ORG 000
	JMP		main
	
ORG 01BH
	MOV		A, P1
	CPL		A
	MOV		P1, A
	RETI

ORG	100H
main:
	MOV		TMOD, #02H
	MOV		TH0, #5
	MOV		IE, #82H
	SETB	TR0
	
	MOV		P1, 0FFH
loop:
	JMP		loop
	
	END