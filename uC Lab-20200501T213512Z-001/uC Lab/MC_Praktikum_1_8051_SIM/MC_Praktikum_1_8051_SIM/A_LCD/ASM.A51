NAME    ASM

?PR?LCD_init?ASM   SEGMENT CODE
PUBLIC  LCD_init
                RSEG   ?PR?LCD_init?ASM
                USING  0

CLK	EQU	P1.2			; #define LCD CLK
RS	EQU	P1.3			; #define LCD RS

LCD_init:

	CLR RS				; clear RS - indicates instructions being sent to LCD
	
	CLR P1.7			; high nibble set - %0010
	CLR P1.6
	SETB P1.5
	CLR P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	CALL LCD_wait		; wait for BF to clear
	
	SETB CLK			; negative edge CLK - 4-bit operation
	CLR CLK
	
	SETB P1.7			; low nibble also set - %1010
	CLR P1.6
	SETB P1.5
	CLR P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	CALL LCD_wait		; wait for BF to clear
	
						; LCD entry mode set - increment with no shift
	CLR P1.7			; high nibble set - %0000
	CLR P1.6
	CLR P1.5
	CLR P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	
	CLR P1.7			; low nibble also set - %0110
	SETB P1.6
	SETB P1.5
	CLR P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	CALL LCD_wait		; wait for BF to clear
	
						; LCD display on/off control
	CLR P1.7			; high nibble set - %0000
	CLR P1.6
	CLR P1.5
	CLR P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	
	SETB P1.7			; low nibble also set - %1111
	SETB P1.6
	SETB P1.5
	SETB P1.4
	
	SETB CLK			; negative edge CLK
	CLR CLK
	CALL LCD_wait		; wait for BF to clear
	RET

?PR?_LCD_send?ASM   SEGMENT CODE
PUBLIC  _LCD_send
                RSEG   ?PR?_LCD_send?ASM
                USING  0
				
CH	EQU	R7				; #define sent character

_LCD_send:

	SETB RS				; set RS - indicates data being sent to LCD
	MOV A, CH			; sent character
	
	MOV C, ACC.7		; high nibble set
	MOV P1.7, C
	MOV C, ACC.6
	MOV P1.6, C
	MOV C, ACC.5
	MOV P1.5, C
	MOV C, ACC.4
	MOV P1.4, C
	
	SETB CLK			; negative edge CLK
	CLR CLK
	
	MOV C, ACC.3		; low nibble also set
	MOV P1.7, C
	MOV C, ACC.2
	MOV P1.6, C
	MOV C, ACC.1
	MOV P1.5, C
	MOV C, ACC.0
	MOV P1.4, C
	
	SETB CLK			; negative edge CLK
	CLR CLK
	CALL LCD_wait		; wait for BF to clear
	RET

?PR?LCD_wait?ASM   SEGMENT CODE
PUBLIC  LCD_wait
                RSEG   ?PR?LCD_wait?ASM
                USING  0
				
CNT	EQU	R0				; #define counter

LCD_wait:
	MOV CNT, #50
loop:
	DJNZ CNT, loop
	RET
	
    END
