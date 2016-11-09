#ifndef __24L01__H__INCLUDED__
#define __24L01__H__INCLUDED__
#include "stm32f10x.h"
#include <stdio.h>
/*NRF24L01˵��

*/
//NRF24L01�Ĵ�����������
#define NRF_READ_REG 	0x00 //�����üĴ���,��5λΪ�Ĵ�����ַ
#define NRF_WRITE_REG 	0x20 //д���üĴ���,��5λΪ�Ĵ�����ַ
#define RD_RX_PLOAD 0x61 //��RX��Ч����,1~32�ֽ�
#define WR_TX_PLOAD 0xA0 //дTX��Ч����,1~32�ֽ�
#define FLUSH_TX 	0xE1 //���TX FIFO�Ĵ���.����ģʽ����
#define FLUSH_RX 	0xE2 //���RX FIFO�Ĵ���.����ģʽ����
#define REUSE_TX_PL 0xE3 //����ʹ����һ������,CEΪ��,���ݰ������Ϸ���.
#define NOP 		0xFF //�ղ���,����������״̬�Ĵ���
//********************************************************************************************************************// 
//SPI(NRF24L01)�Ĵ�����ַ
#define CONFIG 		0x00 //���üĴ�����ַ;bit0:1����ģʽ,0����ģʽ;bit1:��ѡ��;bit2:CRCģʽ;bit3:CRCʹ��;
						 //bit4:�ж�MAX_RT(�ﵽ����ط������ж�)ʹ��;bit5:�ж�TX_DSʹ��;bit6:�ж�RX_DRʹ��
#define EN_AA 		0x01 //ʹ���Զ�Ӧ���� bit0~5,��Ӧͨ��0~5
#define EN_RXADDR 	0x02 //���յ�ַ����,bit0~5,��Ӧͨ��0~5
#define SETUP_AW 	0x03 //���õ�ַ����(��������ͨ��):bit1,0:00,3�ֽ�;01,4�ֽ�;02,5�ֽ�;
#define SETUP_RETR 	0x04 //�����Զ��ط�;bit3:0,�Զ��ط�������;bit7:4,�Զ��ط���ʱ 250*x+86us
#define RF_CH 		0x05 //RFͨ��,bit6:0,����ͨ��Ƶ��;
#define RF_SETUP 	0x06 //RF�Ĵ���;bit3:��������(0:1Mbps,1:2Mbps);bit2:1,���书��;bit0:�������Ŵ�������
#define STATUS 		0x07 //״̬�Ĵ���;bit0:TX FIFO����־;bit3:1,��������ͨ����(���:6);bit4,�ﵽ�����ط�
						 //bit5:���ݷ�������ж�;bit6:���������ж�;
#define OBSERVE_TX 	0x08 //���ͼ��Ĵ���,bit7:4,���ݰ���ʧ������;bit3:0,�ط�������
#define CD 			0x09 //�ز����Ĵ���,bit0,�ز����;
#define RX_ADDR_P0 	0x0A //����ͨ��0���յ�ַ,��󳤶�5���ֽ�,���ֽ���ǰ
#define RX_ADDR_P1 	0x0B //����ͨ��1���յ�ַ,��󳤶�5���ֽ�,���ֽ���ǰ
#define RX_ADDR_P2 	0x0C //����ͨ��2���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P3 	0x0D //����ͨ��3���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P4 	0x0E //����ͨ��4���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P5 	0x0F //����ͨ��5���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define TX_ADDR 	0x10 //���͵�ַ(���ֽ���ǰ),ShockBurstTMģʽ��,RX_ADDR_P0��˵�ַ���
#define RX_PW_P0 	0x11 //��������ͨ��0��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P1 	0x12 //��������ͨ��1��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P2 	0x13 //��������ͨ��2��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P3 	0x14 //��������ͨ��3��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P4 	0x15 //��������ͨ��4��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P5 	0x16 //��������ͨ��5��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define FIFO_STATUS 0x17 //FIFO״̬�Ĵ���;bit0,RX FIFO�Ĵ����ձ�־;bit1,RX FIFO����־;bit2,3,����
						 //bit4,TX FIFO�ձ�־;bit5,TX FIFO����־;bit6,1,ѭ��������һ���ݰ�.0,��ѭ��;
#define MAX_TX 		0x10 //�ﵽ����ʹ����ж�
#define TX_OK 		0x20 //TX��������ж�
#define RX_OK 		0x40 //���յ������ж�
//�������ͨ��
#define Ch0	0x00
#define Ch1	0x02
#define Ch2	0x04
#define Ch3	0x06
#define Ch4	0x08
#define Ch5	0x0a

#define ADR_WIDTH    5 
#define TX_PLOAD_WIDTH  32 //���ݻ�������С
#define RX_PLOAD_WIDTH  32 //���ݻ�������С
//SPI�ӿڶ���
//CE�շ�����--PD12
//CSNƬѡ--PB12
//IRQ--PA3
/*#define CE_H  GPIOC->BSRR=GPIO_Pin_5   //PD5��1
#define CE_L  GPIOC->BRR=GPIO_Pin_5   	//PD5��0
#define CSN_H GPIOC->BSRR=GPIO_Pin_6	//PB6��1
#define CSN_L GPIOC->BRR=GPIO_Pin_6	//PB6��0*/

typedef struct _NRF24L01_T NRF24L01_T;
struct _NRF24L01_T{
	GPIO_TypeDef* CE_GPIO;
	uint16_t CE_GPIO_Pin;
	GPIO_TypeDef* IRQ_GPIO;
	uint16_t IRQ_GPIO_Pin;
	GPIO_TypeDef* CSN_GPIO;
	uint16_t CSN_GPIO_Pin;
	SPI_TypeDef* SPI;
	
	void(*CE_Set)(NRF24L01_T* nrf);
	void(*CE_Reset)(NRF24L01_T* nrf);
	void(*CSN_Set)(NRF24L01_T* nrf);
	void(*CSN_Reset)(NRF24L01_T* nrf);
	u8(*IRQ_Get)(NRF24L01_T* nrf);
	
	void (*RF_Write_Reg)(NRF24L01_T* nrf,u8 reg, u8 value);
	u8 (*RF_Write_Buf)(NRF24L01_T* nrf,u8 reg, u8 *pBuf,u8 bytes);
	u8 (*RF_Read_Reg)(NRF24L01_T* nrf,u8 reg);
	u8 (*RF_Read_Buf)(NRF24L01_T* nrf,u8 reg, u8 *pBuf, u8 bytes);
	u8 (*nRF24L01_TxPacket)(NRF24L01_T* nrf,u8 *tx_buf);
	u8 (*nRF24L01_RxPacket)(NRF24L01_T* nrf,u8 *rx_buf);
	void (*Set_TX_Mode)(NRF24L01_T* nrf);
	void (*Set_RX_Mode)(NRF24L01_T* nrf);
};

//void RF_SPI_Init(void);
//void Receive(void);
void NRF24L01_Init(NRF24L01_T* nrf);
//void RX_Mode(u8 channel);
//u8 SPIx_ReadWriteByte(u8 data);
//void  RF_Write_Reg(u8 reg, u8 value);
//u8 RF_Read_Reg(u8 reg);
// u8 RF_Read_Buf(u8 reg, u8 *pBuf, u8 bytes);
// u8 RF_Write_Buf(u8 reg, u8 *pBuf,u8 bytes);
// u8 nRF24L01_RxPacket(u8 *rx_buf);
// u8 nRF24L01_TxPacket(u8 *tx_buf);
extern NRF24L01_T* nrf1;
#endif