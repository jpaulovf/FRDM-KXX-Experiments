/********************************************************************
 * intflash.c - Internal flash R/W routines
 *
 * author: jpaulovf@gmail.com
 * date: 24 May 2019
 *
 ********************************************************************/

/********************************************************************
 * Includes
 ********************************************************************/
#include "intflash.h"
#include <stdint.h>
#include "IFlash.h"

/********************************************************************
 * Functions
 ********************************************************************/

/*==================================================================*
 * 	Erases the NVM block
 *==================================================================*/
void flashErase(){

	// Erasing entire sector belonging to the NVM inital address
	IFlash_EraseSector(NVM_START_ADDR);

}

/*==================================================================*
 * 	Writes data to internal flash
 *==================================================================*/
uint8_t flashWrite(uint16_t addr, uint16_t size, uint8_t *data){

	uint8_t status;
	uint32_t real_addr;

	// Verifying address
	if ( addr > NVM_SIZE ){
		return NVM_ERR_ADDR;
	}

	// Verifying size
	if ( (addr + size) > NVM_SIZE ){
		return NVM_ERR_SIZE;
	}

	// Calculating real address
	real_addr = NVM_START_ADDR + ((uint32_t) addr);

	// Writing
	status = IFlash_SetBlockFlash( (IFlash_TDataAddress) data,
								   (IFlash_TAddress) real_addr,
								   (word) size);

	// Error during write operation
	if (status != ERR_OK){
		return NVM_ERR_W;
	}

	// No error
	return NVM_OK;

}

/*==================================================================*
 * 	Reads data from internal flash
 *==================================================================*/
uint8_t flashRead(uint16_t addr, uint16_t size, uint8_t *data){

	uint8_t status;
	uint32_t real_addr;

	// Verifying address
	if ( addr > NVM_SIZE ){
		return NVM_ERR_ADDR;
	}

	// Verifying size
	if ( (addr + size) > NVM_SIZE ){
		return NVM_ERR_SIZE;
	}

	// Calculating real address
	real_addr = NVM_START_ADDR + ((uint32_t) addr);

	// Reading
	status = IFlash_GetBlockFlash( (IFlash_TAddress) real_addr,
								   (IFlash_TDataAddress) data,
								   (word) size);

	// Error during read operation
	if (status != ERR_OK){
		return NVM_ERR_R;
	}

	// No error
	return NVM_OK;

}
