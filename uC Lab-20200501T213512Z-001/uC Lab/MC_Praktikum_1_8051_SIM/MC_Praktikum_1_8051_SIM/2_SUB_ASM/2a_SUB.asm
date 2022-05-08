main:
	MOV		R0, #30H
	MOV		@R0, #6H
	MOV		R0, #31H
	MOV		@R0, #4H
	MOV		R0, #32H
	MOV		@R0, #1H
	
function:
	MOV		A, 30H
	ADD		A, 31H
	ADD		A, 32H
	MOV		B, #3H
	DIV		AB
	MOV		40H, A
	MOV		41H, B
	
	END