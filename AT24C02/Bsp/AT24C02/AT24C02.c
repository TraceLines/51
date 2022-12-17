#include "reg52.h"

#include "I2C.h"

#define AT24C02_ADDRESS 0XA0

/**
 * @brief 向从机写数据，字节写，整个过程由AT24C02的写时序决定的
 * @param WordAddress 被写的地址
 * @param ByteData    被写的数据
 *
 */
void AT24C02_WriteByte(unsigned char WordAddress, ByteData)
{
    // unsigned char ReceiveACK;
    // -----------通信的流程 begin
    // I2C发送起始条件
    I2C_Start();
    // I2C发送从机地址
    I2C_SendByte(AT24C02_ADDRESS);
    // 读取从机应答
    I2C_ReceiveACK();
    // 要写的地址
    I2C_SendByte(WordAddress);
    I2C_ReceiveACK();
    // 发送数据
    I2C_SendByte(ByteData);
    // 读取接收者的应答
    I2C_ReceiveACK();
    // 停止通信
    I2C_Stop();
    // -----------通信的流程 end
}

/**
 * @brief 从slave中读取数据，字节读，整个过程由AT24C02的读时序决定的
 * @param WordAddress 要读的地址
 * @return ByteData 读到的数据
 */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
    unsigned char ByteData;
    // -----------通信的流程 begin
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveACK();
    // 要读的地址，这里先将要读的地址发送过去，可能与AT24C02有关，可以翻阅手册来确定
    I2C_SendByte(WordAddress);
    // 等接收者的应答
    I2C_ReceiveACK();
    // 开始接收数据，重新发起一个起始位，并切换数据的方向。
    I2C_Start();
    // 改变数据的方向，主机变为接收者（其实不在这里切换数据方向，在上一句中是否可行呢？）
    I2C_SendByte(AT24C02_ADDRESS | 0x01);
    I2C_ReceiveACK();
    ByteData = I2C_ReceiveByte();
    // 接收完一位，作为主机，接收者，又准备结束通信的情况下，发送一个NACK，让从机释放SCL和SDA，以便作为主机的MCU结束通信
    I2C_SendACK(1);
    I2C_Stop();
    // -----------通信的流程 end

    return ByteData;
}