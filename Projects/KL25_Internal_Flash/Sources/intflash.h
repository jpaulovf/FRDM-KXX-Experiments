/********************************************************************
 * intflash.h - Internal flash R/W routines
 *
 * author: jpaulovf@gmail.com
 * date: 24 May 2019
 *
 ********************************************************************/

#ifndef SOURCES_INTFLASH_H_
#define SOURCES_INTFLASH_H_

/********************************************************************
 * Includes
 ********************************************************************/
#include <stdint.h>

/********************************************************************
 * Defines
 ********************************************************************/

#define NVM_START_ADDR	0x1FC00U	// Non-volatile memory initial address
#define NVM_SIZE		0x0400U		// Non-volatile memory size

// Error codes
#define NVM_OK			0			// No error
#define NVM_ERR_SIZE	1			// Bad size error
#define NVM_ERR_ADDR	2			// Bad address error
#define NVM_ERR_W		3			// Write error
#define NVM_ERR_R		4			// Read error

/********************************************************************
 * prototypes
 ********************************************************************/

/*
 * 	Erases the NVM block
 * 	param
 * 		void
 * 	return
 * 		void
 */
void flashErase();

/*
 * 	Writes data to internal flash
 * 	param[in] addr
 * 		Address
 * 	param[in] size
 * 		Size of data in bytes
 * 	param[in] data
 * 		Pointer to data array
 * 	return
 * 		Error code
 */
uint8_t flashWrite(uint16_t addr, uint16_t size, uint8_t *data);

/*
 * 	Reads data from internal flash
 * 	param[in] addr
 * 		Address
 * 	param[in] size
 * 		Size of data in bytes
 * 	param[out] data
 * 		Pointer to data array
 * 	return
 * 		Error code
 */
uint8_t flashRead(uint16_t addr, uint16_t size, uint8_t *data);


#endif /* SOURCES_INTFLASH_H_ */
