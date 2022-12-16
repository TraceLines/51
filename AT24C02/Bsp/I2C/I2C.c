/*
 * @Author       :
 * @Date         : 2022-12-16 10:47:12
 * @LastEditors  : miduoduo
 * @LastEditTime : 2022-12-16 13:38:45
 * @FilePath     : \AT24C02\Bsp\I2C\I2C.C
 * @desc         : 注意，这个程序是使用51单片机去读取AT24C02，也就是说使用I2C协议去读取EEPROM，作为读方，即51单片机是作为主机来设定的。所以在一些软件中
 *                 会去操作SCL时钟线，因为MCU是主机，可以操作SCL线。
 * 另外一件事情是，在I2C通信中有两种通信速率模式，100kbps和400kbps，但在软件模拟中，并不能完全遵循此。而在此例程中，SCL的高低电平变化，完全由软件来控制。
 * 如I2C_SendByte中SDA数据的变化是在SCL为低时，变化完成之后，接着产生一个上升沿，将数据传送出去。
 * 因为软件模拟I2C，需要考虑时序中的时间问题，以满足I2C的要求，或者说接收方中可以正确读取的时序要求，就需要对SCL的保持状态进行延时，但51单片机的速度太低，完全满足通信时序，所以在此程序中，并没有对SCL的时间进行处理
 * 不管是接收还是发送，作为主机的MCU，即本机都要产生通信时钟
 */
#include "reg52.h"

sbit I2C_SCL = p2 ^ 1;
sbit I2C_SDA = p2 ^ 0;
void I2C_Start(void)
{
    // 产生起始信号的条件：SDA和SCL从高电平变为低电平，并且是SDA先拉低，随后再SCL再被拉低，则产生起始信号
    // 为防止SDA或SCL的电平不为高，或为正确产生一个起始信号，将两条线都拉高。
    I2C_SDA = 1;
    I2C_SCL = 1;
    // 先接低SDA，再拉低SCL，产生起始信号
    I2C_SDA = 0;
    I2C_SCL = 0;
}

// STOP信号跟在数据帧的结束，
void I2C_Stop(void)
{
    // I2C产起停止信号的条件：SCL从低拉到高电平，接着SDA也变为高电平。注意的是，SCL先拉高，再将SDA拉高
    // 为防止SDA或SCL电平不为低，或为正确产生一个结束信号，将两条线都拉低
    I2C_SDA = 0;
    // I2C_SCL = 0;
    // 先拉高SCL，再拉高SDA，产生结束
    I2C_SCL = 1;
    I2C_SDA = 1;
}

void I2C_SendByte(unsigned char Byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        // 数据变化时，SCL为低，满足I2C的协议
        I2C_SDA = Byte & (0x80 >> i);
        // 产生I2C的SCL，以传输数据
        I2C_SCL = 1; // 在高电平期间，接收方会读取SDA上的数据
        I2C_SCL = 0; // 恢复为低电平，为下一次数据传输做准备
    }
}

/**
 * @brief 接收一个字节：SCL低电平期间，从机将数据位依次放入到SDA线上（高位在前），然后拉高SCL，主机将在SCL高电平期间读取数据位
 * 所以SCL高电平期间SDA不允许有数据变量，依次循环上述过程8次，即可接收一个字节。（主机在接收之前，需要释放SDA，交由从机来控制SDA。）
 *
 * @return unsigned char
 */
unsigned char I2C_ReceiveByte(void)
{
    unsigned char i, Byte = 0x00;
    I2C_SDA = 1; // 作为主机也好或者从机也罢，进入接收模式时，都要释放总线
    // 开始接收数据
    for (i = 0; i < 8; i++)
    {
        I2C_SCL = 1; // 将SCL拉高，以读取SDA。协议规定，要在SCL高电平期间去读取SDA的数据
        if (I2C_SDA)
        {
            Byte = |= (0x80 >> i);
        }
        I2C_SCL = 0; // 将SCL拉低，表示1bit数据读完，发送方则在此期间改变数据
    }

    return Byte;
}

/**
 * @brief 产生应答的函数——此作为主机接收模式，向从机发送应答。作为主机，要产生SCL通信时钟
 * 如何产生应答？在ACK时钟脉冲期间，SDA=1则不应答。SDA=0，则表示应答。应答由接收方发出。根据协议，接收方为了接收答应，会在发送完一个字节后，将SDA拉高。
 * 所以在ACK时间周期内，将SDA=0，则即为应答，否则为不答应。不应答时，发送方会认为发送错误，会进入发送错误处理程序。
 * @param AckBit
 */
void I2C_SendACK(unsigned char AckBit)
{
    I2C_SDA = AckBit; // 设置SDA的状态，或为1或为0
    // 处理SCL线，但这里有一个疑问，若作为从机接收方，是不可以处理SCL的。这里对SCL的处理，则默认为自己是主机，是主机接收模式。
    // 作为主机，即使是接收方，也要处理SCL线
    I2C_SCL = 1; // 拉高SCL,将SDA的状态发送出去
    I2C_SCL = 0; // 再拉低SCL，表示响应完成，为下一次的通信或bit传输做准备。
}

/**
 * @brief MCU是主机，场景应该是发送完数据后，等从机发送应答。要做的事情是处理SCL线，并在SCL为高时读取SDA，判断SDA的电平，
 *
 * @return unsigned char
 */
unsigned char I2C_ReceiveACK(void)
{
    unsigned char AckBit;
    I2C_SDA = 1; // I2C协议规定，接收应答时，要释放SDA，由应答者来操控SDA，主机产生SCL，在高电平期间去读SDA，若读到的为1则为未应答，可能出现错误。若读到为0，则接收方应答了
    // 产生一个额外的时钟脉冲，以触发接收方处理SDA
    // I2C_SCL = 0;//不加此句也可以，因为每个通信帧的最后，都将SCL拉低了
    I2C_SCL = 1;      // 拉高SCL，并在SCL为高电平期间去读取SDA，以确定接收者是否响应了。
    AckBit = I2C_SDA; // 读SDA，并将数据传输出去
    I2C_SCL = 0;      // 再拉低SCL，为下一次的通信或bit传输做准备。
    return AckBit;
}