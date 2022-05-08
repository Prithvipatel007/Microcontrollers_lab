ORG 000H
	JMP		main
ORG 003H						; ADC IRQ on INT0
	JMP		ext0
ORG 00BH						; ADC sampling rate by T0
	JMP		timer0
ORG 030H
main:
	CLR		P0.7				; enable DAC write
	MOV		TCON, #00000001B	; external interrupt 0 edge mode
	MOV		IE, #10000011B
	MOV		TMOD, #2
	MOV		TH0, #-20
	SETB	TR0
loop:
	JMP loop
timer0:							; send sampling pulse to ADC
	CLR		P3.6				; enable ADC write
	NOP
	SETB	P3.6				; disable ADC write
	RETI
ext0:							; ADC has aquired
	CLR		P3.7				; enable ADC read
	MOV		P1, P2				; read data from ADC and write into DAC
	SETB	P3.7				; disable ADC read
	RETI