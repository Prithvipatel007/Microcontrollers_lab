ORG 000
main:
		MOV		DPTR, #180H	; table address
		MOV		R0, #30
		CALL	sub
		JMP		main
		
sub:
		PUSH	PSW
		MOV		A, R0
		MOV		B, #0AH		; step 10
		DIV		AB
		MOVC	A, @A+DPTR	; sin(n) from table
		MOV		R0, A
		POP		PSW
		RET

; ROM from byte 384
ORG 180H
table:
		DB 0,17,34,50,64,77,87,94,98,100

		END