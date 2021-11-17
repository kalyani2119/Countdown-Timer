# Countdown-Timer
//Embedded C program for countdown timer using 8051 microcontroller and LCD display
#include<reg51.h>
sbit rs=P1^0;
sbit en=P1^1;

void delay(unsigned int count)
{
unsigned int i;
while(count)
{
i=115;
while(i>0);
i--;
count--;
}
}

void lcd_data(unsigned char abc)
{
rs = 1;
p2=abc;
en=1;
delay(50);
en=0;
}

void lcd_cmd(unsigned char abc)
{
rs=0;
p2=abc;
en=1;
delay(50);
en=0;
}


void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x06);
lcd_cmd(0x0E);
lcd_cmd(0x80);
lcd_cmd(0x0c);
}

void lcd_cursor(char row, char coloumn)
{
switch(row)
{
case 1: lcd_cmd(0x80 + column - 1); break;
case 2: lcd_cmd(0xC0 + column - 1); break;
case 3: lcd_cmd(0x94 + column - 1); break;
case 4: lcd_cmd(0xd4 + column - 1); break;
default: break;
}
}

void lcd_clear()
{
lcd_cmd(0x01);
}


void lcd_print(char row, char coloumn, unsigned int value, int digits)
{
unsigned int temp;
unsigned char flag=0;
if(row==0||column==o)
{
lcd_cmd(0x80);
}
else
{
lcd_cursor(row,column);
}
if(digits==1||flag==1)
{
unit=(value%10)+48;
lcd_data(unit);
}
}

void lcd_out(char row, char coloumn, char *str)
{
lcd_cursor(row,column);
while(*str!='\0')
{
lcd_data(*str);
str++;
}
}

void main()
{
int count=0;
lcd_init();
lcd_out(1,1,"Hello");
delay(1000);
lcd_clear();
while(1)
{
lcd_out(1,1,"SECONDS:");
lcd_print(2,1,count,1);
count++;
delay(1000);
}
}
