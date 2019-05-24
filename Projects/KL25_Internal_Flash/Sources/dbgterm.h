/********************************************************************
 * dbgterm.h - Serial communication for user interface
 *
 * author: jpaulovf@gmail.com
 * date: 24 May 2019
 *
 ********************************************************************/

#ifndef SOURCES_DBGTERM_H_
#define SOURCES_DBGTERM_H_

/********************************************************************
 * Includes
 ********************************************************************/

#include <stdint.h>

/********************************************************************
 * Defines
 ********************************************************************/

#define STRING_MAXLEN	100		// String maximum size

/********************************************************************
 * Prototypes
 ********************************************************************/

/*	Clear the screen
 * 	param
 * 		void
 * 	return
 * 		void
 */
void termClear();

/*
 *	Print a colored string to the serial terminal
 * 	param[in] string
 * 		String to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrint(char *string, uint8_t font_color, uint8_t bg_color);

/*
 *	Print a colored string to the serial terminal followed by a CRLF
 * 	param[in] string
 * 		String to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrintln(char *string, uint8_t font_color, uint8_t bg_color);

/*
 *	Print a colored integer to the serial terminal
 * 	param[in] number
 * 		Number to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrintNumber(int number, uint8_t font_color, uint8_t bg_color);

/*
 *	Print a colored integer to the serial terminal followed by a CRLF
 * 	param[in] number
 * 		Number to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrintlnNumber(int number, uint8_t font_color, uint8_t bg_color);

/*
 *	Print a colored float to the serial terminal
 * 	param[in] flnumber
 * 		Float number to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrintFloat(float flnumber, uint8_t font_color, uint8_t bg_color);

/*
 *	Print a colored float to the serial terminal followed by a CRLF
 * 	param[in] flnumber
 * 		Float number to be printed
 * 	param[in] font_color
 * 		Color of the string
 * 	param[in] bg_color
 * 		Background color
 * 	return
 * 		void
 */
void termPrintlnFloat(float flnumber, uint8_t font_color, uint8_t bg_color);

/*
 * 	Reads a string from the terminal
 * 	param[out] string
 * 		String read from terminal
 * 	return
 * 		void
 */
void termRead(char *string, uint32_t size);

/*
 * 	Reads an integer from the terminal
 * 	param[out] number
 * 		Number read from terminal
 * 	return
 * 		void
 */
void termReadNumber(int *number);

/*
 * Reads a float from the terminal
 * param[out] flnumber
 * 		Number read from terminal
 * return
 * 		void
 */
void termReadFloat(float *flnumber);


#endif /* SOURCES_DBGTERM_H_ */

