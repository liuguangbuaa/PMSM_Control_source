/*
 * SPICtrl.hpp
 *
 *  Created on: Dec 21, 2019
 *      Author: watashi
 */

#ifndef INC_SPICTRL_HPP_
#define INC_SPICTRL_HPP_

#include "spi.h"
#include "paramsetting.h"
#include <array>
//#include <vector>

enum spiState{
 TRANSFER_WAIT,
 TRANSFER_COMPLETE,
 TRANSFER_ERROR
};

//union IntToCharArray {
//	int mInt;
//	std::array<uint8_t,4> mByte;
//};

class SPICtrl {
private:
	int mArrayPos = 0;

	uint8_t m0fillArr[SPI_DATA_SIZE] = {0};
	uint8_t mTxData[SPI_DATA_SIZE] = {0};
	uint8_t mRxData[SPI_DATA_SIZE] = {0};

	std::array<int,(SPI_DATA_SIZE/4)> mRxInt;

	spiState mspiState;

public:

	SPICtrl();
	virtual ~SPICtrl();
	void SetTransmitData(const uint8_t* pTxData);
	void PushBackTransmitIntData(int pIntData);
	uint8_t* GetReceiveData();

	std::array<int,(SPI_DATA_SIZE/4)> GetRxInt();

	void SPITransmitReceive();

	void spiCplt() { mspiState = TRANSFER_COMPLETE; }
	void spiWait() {mspiState = TRANSFER_WAIT; }
	void spiErr() {mspiState = TRANSFER_ERROR; }

};






#endif /* INC_SPICTRL_HPP_ */