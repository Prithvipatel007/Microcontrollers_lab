$include (REG51.inc)

XBR2 EQU 0E3H

ORG 0000H
	JMP		main

; timer0 irq handler
ORG 000BH
	CPL		P1.4		; toggle LED

	MOV		TH0, #80H	; timer 0 reload
	MOV		TL0, #00H

	RETI

main:
	MOV		XBR2, #01000000B	; port power

	; timer 0
	ORL		TMOD, #00000001B	; timer 0 mode 1
	MOV		TH0, #80H			; timer 0 load
	MOV		TL0, #00H

	; 8051 standard irq configuration
	MOV		IE, #10000010B		; enable timer 0 IRQ and enable global

	SETB	TR0					; timer 0 start
loop:
	JMP		loop

	END
