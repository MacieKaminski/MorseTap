#include "uart.h"
#include "string.h"

void convert(char[]);

void convert(char[]);

void convert(char letter[])
{
	if(!strcmp(letter,"21000"))
	{
		UART_Print("A");
	}
	else if(!strcmp(letter,"12220"))
	{
		UART_Print("B");
	}
	else if(!strcmp(letter,"12120"))
	{
		UART_Print("C");
	}
	else if(!strcmp(letter,"12200"))
	{
		UART_Print("D");
	}
	else if(!strcmp(letter,"20000"))
	{
		UART_Print("E");
	}
	else if(!strcmp(letter,"22120"))
	{
		UART_Print("F");
	}
	else if(!strcmp(letter,"11200"))
	{
		UART_Print("G");
	}
	else if(!strcmp(letter,"22220"))
	{
		UART_Print("H");
	}
	else if(!strcmp(letter,"22000"))
	{
		UART_Print("I");
	}
	else if(!strcmp(letter,"21110"))
	{
		UART_Print("J");
	}
	else if(!strcmp(letter,"12100"))
	{
		UART_Print("K");
	}
	else if(!strcmp(letter,"21220"))
	{
		UART_Print("L");
	}
	else if(!strcmp(letter,"11000"))
	{
		UART_Print("M");
	}
	else if(!strcmp(letter,"12000"))
	{
		UART_Print("N");
	}
	else if(!strcmp(letter,"11100"))
	{
		UART_Print("O");
	}
	else if(!strcmp(letter,"21120"))
	{
		UART_Print("P");
	}
	else if(!strcmp(letter,"11210"))
	{
		UART_Print("Q");
	}
	else if(!strcmp(letter,"21200"))
	{
		UART_Print("R");
	}
		else if(!strcmp(letter,"22200"))
	{
		UART_Print("S");
	}
	else if(!strcmp(letter,"10000"))
	{
		UART_Print("T");
	}
	else if(!strcmp(letter,"22100"))
	{
		UART_Print("U");
	}
	else if(!strcmp(letter,"22210"))
	{
		UART_Print("V");
	}
	else if(!strcmp(letter,"21100"))
	{
		UART_Print("W");
	}
	else if(!strcmp(letter,"12210"))
	{
		UART_Print("X");
	}
	else if(!strcmp(letter,"12110"))
	{
		UART_Print("Y");
	}
	else if(!strcmp(letter,"11220"))
	{
		UART_Print("Z");
	}
	else if(!strcmp(letter,"21111"))
	{
		UART_Print("1");
	}
	else if(!strcmp(letter,"22111"))
	{
		UART_Print("2");
	}
	else if(!strcmp(letter,"22211"))
	{
		UART_Print("3");
	}
	else if(!strcmp(letter,"22221"))
	{
		UART_Print("4");
	}
	else if(!strcmp(letter,"22222"))
	{
		UART_Print("5");
	}
	else if(!strcmp(letter,"12222"))
	{
		UART_Print("6");
	}
	else if(!strcmp(letter,"11222"))
	{
		UART_Println("7");
	}
	else if(!strcmp(letter,"11122"))
	{
		UART_Print("8");
	}
	else if(!strcmp(letter,"1112"))
	{
		UART_Print("9");
	}
	else if(!strcmp(letter,"11111"))
	{
		UART_Print("0");
	}
	else
	{
		UART_Print("");
	}
}
