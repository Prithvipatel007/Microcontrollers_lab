$include (REG51.inc)

XBR2 EQU 0E3H

main:
	ORL		XBR2, #01000000B	; port power
loop:
	CPL		P1.4				; toggle LED

	CALL	delay
	CALL	delay
	CALL	delay
	CALL	delay

	JMP		loop

delay:
	MOV		R1, #0FFH
delay_high:
	MOV		R0, #0FFH
delay_low:
	DJNZ	R0, delay_low
	DJNZ	R1, delay_high
	RET

	END
