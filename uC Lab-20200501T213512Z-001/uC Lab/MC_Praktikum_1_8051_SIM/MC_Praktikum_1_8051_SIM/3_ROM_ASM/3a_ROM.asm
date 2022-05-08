ORG 000
main:
		MOV		DPTR, #180H	; table address
		MOV		A, #0FFH
		MOV		P2, A		; P2 input
loop:
		MOV		A, P2		; read n
		CPL		A
		MOVC	A, @A+DPTR	; n*n from table
		CPL		A
		MOV		P1, A		; output n*n
		JMP		loop

; ROM from byte 384
ORG 180H
table:
		DB		0,1,4,9,16,25,36,49,64,81

		END