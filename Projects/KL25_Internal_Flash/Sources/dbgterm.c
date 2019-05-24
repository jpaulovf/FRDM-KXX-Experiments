/********************************************************************
 * dbgterm.c - Serial communication for user interface
 *
 * author: jpaulovf@gmail.com
 * date: 24 May 2019
 *
 ********************************************************************/

/********************************************************************
 * Includes
 ********************************************************************/

#include "dbgterm.h"
#include "Term1.h"
#include <stdlib.h>

/********************************************************************
 * Functions
 ********************************************************************/

/*==================================================================*
 * termClear - Clear the screen                                     *
 *==================================================================*/
void termClear(){

	Term1_Cls();
	Term1_MoveTo(0,0);
}

/*==================================================================*
 * termPrint - Print a colored string                               *
 *==================================================================*/
void termPrint(char *string, uint8_t font_color, uint8_t bg_color){

	// Configuring colors
	Term1_SetColor(font_color, bg_color);
	// Sending string
	Term1_SendStr(string);
	// Resetting colors
	Term1_SetColor(clWhite, clBlack);

}

/*==================================================================*
 * termPrintln - Print a colored string followed by a CRLF          *
 *==================================================================*/
void termPrintln(char *string, uint8_t font_color, uint8_t bg_color){

	termPrint(string, font_color, bg_color);
	Term1_CRLF();

}

/*==================================================================*
 * termPrintNumber - Print a colored integer                        *
 *==================================================================*/
void termPrintNumber(int number, uint8_t font_color, uint8_t bg_color){

	// Configuring colors
	Term1_SetColor(font_color, bg_color);
	// Sending string
	Term1_SendNum(number);
	// Resetting colors
	Term1_SetColor(clWhite, clBlack);

}

/*==================================================================*
 * termPrintlnNumber - Print a colored integer followed by a CRLF   *
 *==================================================================*/
void termPrintlnNumber(int number, uint8_t font_color, uint8_t bg_color){

	termPrintNumber(number, font_color, bg_color);
	Term1_CRLF();

}

/*==================================================================*
 * termPrintFloat - Print a colored float                           *
 *==================================================================*/
void termPrintFloat(float flnumber, uint8_t font_color, uint8_t bg_color){

	// Configuring colors
	Term1_SetColor(font_color, bg_color);
	// Sending string
	Term1_SendFloatNum(flnumber);
	// Resetting colors
	Term1_SetColor(clWhite, clBlack);

}

/*==================================================================*
 * termPrintFloat - Print a colored float followed by a CRLF        *
 *==================================================================*/
void termPrintlnFloat(float flnumber, uint8_t font_color, uint8_t bg_color){

	termPrintFloat(flnumber, font_color, bg_color);
	Term1_CRLF();

}

/*==================================================================*
 * termRead - Reads a string from terminal                          *
 *==================================================================*/
void termRead(char *string, uint32_t size){

	char c = 0;
	int counter = 0;
	int i;

	// Clearing string
	for (i=0; i<size; i++){
		string[i] = 0;
	}

	// Continuously read characters from terminal until 'Return' is pressed
	//  or the number of characters read exceed the maximum
	while ( (counter < size) && (c != 0x0D) ){
		if (Term1_KeyPressed()){
			Term1_ReadChar(&c);
			string[counter] = c;
			counter++;
		}
	}

}

/*==================================================================*
 * termRead - Reads an integer from terminal                        *
 *==================================================================*/
void termReadNumber(int *number){

	int size = 10; // 32 bits: 10 digits
	char str[size];
	char *cptr;

	// Reading string from terminal
	termRead(str, size);

	// Converting to int
	*number = (int) strtol(str, &cptr, 10);

}

/*==================================================================*
 * termRead - Reads a float from terminal                           *
 *==================================================================*/
void termReadFloat(float *flnumber){

	int size = 10; // 32 bits: 10 digits
	char str[size];
	char *cptr;

	// Reading string from terminal
	termRead(str, size);

	// Converting to float
	*flnumber = (float) strtof(str, &cptr);

}
