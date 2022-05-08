ORG 000
main:
	CLR		P0.7			; MUX CS -> SEG off
	MOV		P1, #0FFH		; SEG clear
	CLR		P3.3			; MUX A0 = 0 -> SEG #1 select
	CLR		P3.4			; MUX A1 = 0
	SETB	P0.7			; MUX CS -> SEG on
	MOV		DPTR, #180H		; SEG table
loop1:
	MOV		R0, #0			; SEG = 0
loop2:
	MOV		A, R0
	MOVC	A, @A+DPTR		; SEG number from table
	MOV		P1, A			; SEG show number
	CALL	delay
	INC		R0				; SEG + 1
	CJNE	R0, #3, loop2	; MAX ?
	JMP		loop1
	
delay:
	MOV		R3, #250		; long delay : 250*250
d_loop1:
	MOV		R4, #250
d_loop2:
	DJNZ	R4, d_loop2		; loop while <> 0
	DJNZ	R3, d_loop1		; loop while <> 0
	RET

; ROM from byte 384
ORG 180H
table:
	DB		11000000B	; 0
	DB		11111001B	; 1
	DB		10100100B	; 2

	END