main:
	MOV		SCON, #01000000B	; USART mode %01 = 8-bit data
	ORL		PCON, #10000000B	; set double baud rate
	MOV		TMOD, #20H			; timer 1 mode 2
	MOV		TH1, #-12			; timer 1 = -12: baud = 2400: double = 4800
	MOV		TL1, #-12			; timer 1 sync
	SETB	TR1					; timer 1 start
	MOV		30H, #'a'			; start string
	MOV		31H, #'b'
	MOV		32H, #'c'
	MOV		33H, #0				; terminate string
	MOV		R0, #30H
loop:
	MOV		A, @R0
	JZ		done				; string terminated
	MOV		C, P				; add parity to char through carry
	MOV		ACC.7, C			; in accu
	MOV		SBUF, A				; send data
	INC		R0
wait:
	JNB		TI, wait			; wait for data sent
	CLR		TI					; clear sent flag
	JMP		loop
done:
	END
