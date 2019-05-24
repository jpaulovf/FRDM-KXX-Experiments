/***********************************************
 * run.c - Runs the main routine
 *
 * author: jpaulovf@gmail.com
 * date: 24 May 2019
 *
 ***********************************************/

/***********************************************
 * Includes
 ***********************************************/
#include "run.h"
#include "intflash.h"
#include "dbgterm.h"
#include "Term1.h"
#include <stdint.h>
#include <string.h>

/***********************************************
 * Functions
 ***********************************************/

/* ------------------------------------------- *
 * 	run - runs the main routine
 * ------------------------------------------- */
void run(){

	char key = 0;
	char mystring[STRING_MAXLEN+1];
	uint8_t status;
	int datasize;

	while (key != 'q'){

		// Clearing string
		memset(mystring, 0, STRING_MAXLEN+1);

		termPrintln("\n*** Internal Flash test ***\n", clMagenta, clBlack);
		termPrintln("Select an option:", clWhite, clBlack);

		termPrint(" (", clWhite, clBlack);
		termPrint(" W", clMagenta, clBlack);
		termPrintln(" )rite data", clWhite, clBlack);

		termPrint(" (", clWhite, clBlack);
		termPrint(" R", clMagenta, clBlack);
		termPrintln(" )ead data", clWhite, clBlack);

		termPrint(" (", clWhite, clBlack);
		termPrint(" Q", clMagenta, clBlack);
		termPrintln(" )uit\n", clWhite, clBlack);

		termRead(&key, 1);

		switch (key){

			// Write operation
			case 'w':

				termPrintln("Enter string: ", clWhite, clBlack);
				termRead(mystring, STRING_MAXLEN);
				termPrint("You entered: ", clWhite, clBlack);
				termPrintln(mystring, clCyan, clBlack);
				termPrint("Writing on internal flash... ", clWhite, clBlack);
				status = flashWrite(0, (uint16_t) strlen(mystring), (uint8_t *) mystring);
				if (status != NVM_OK){
					termPrintln("ERROR", clRed, clBlack);
				}
				termPrintln("OK", clGreen, clBlack);

			break;

			// Read operation
			case 'r':
				termPrintln("Enter number of bytes to read: ", clWhite, clBlack);
				termReadNumber(&datasize);
				termPrint("You entered: ", clWhite, clBlack);
				termPrintlnNumber(datasize, clCyan, clBlack);
				termPrint("Reading from internal flash... ", clWhite, clBlack);
				status = flashRead(0, (uint16_t) datasize, (uint8_t *) mystring);
				if (status != NVM_OK){
					termPrintln("ERROR", clRed, clBlack);
				}
				termPrintln("OK\n", clGreen, clBlack);
				termPrint("Data = ", clWhite, clBlack);
				termPrintln(mystring, clCyan, clBlack);

			break;

			default:
			break;

		}

	}


}
