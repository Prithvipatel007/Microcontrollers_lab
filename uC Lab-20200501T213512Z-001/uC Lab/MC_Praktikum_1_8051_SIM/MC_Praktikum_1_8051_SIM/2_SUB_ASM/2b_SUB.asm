main:
	MOV		R0, #30H
	MOV		@R0, #6H
	MOV		R0, #31H
	MOV		@R0, #4H
	MOV		R0, #32H
	MOV		@R0, #1H
parameter:
	MOV		R0, #30H
	MOV		R1, #3H
	MOV		SP, #6FH
	CALL	sub
	MOV		40H, A
	MOV		41H, B
	JMP		main
	
sub:
	PUSH	0
	PUSH	1
function:
	MOV		B, R1
	CLR		A
loop:
	ADD		A, @R0
	INC		R0
	DJNZ	R1, loop
	DIV		AB
	POP		1
	POP		0
	RET

	END