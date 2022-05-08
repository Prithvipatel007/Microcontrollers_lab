#include <reg51.h>

extern void LCD_init(void);
extern void LCD_send(unsigned char);

char str[] = "Hello world ...";

void main(void)
{
	char ch, idx = 0;
	
	LCD_init();
	
	while ((ch = str[idx++]) != 0)
	{
		LCD_send(ch);
	}
	
	while (1);
}
