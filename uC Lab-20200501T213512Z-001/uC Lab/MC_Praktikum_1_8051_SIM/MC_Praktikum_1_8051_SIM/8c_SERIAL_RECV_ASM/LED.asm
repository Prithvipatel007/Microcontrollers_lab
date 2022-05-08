main:
	MOV		SCON, #01010000B	; USART mode %01 = 8-bit data + enable receiver
	ORL		PCON, #10000000B	; set double baud rate
	MOV		TMOD, #20H			; timer 1 mode 2
	MOV		TH1, #-12			; timer 1 = -12: baud = 2400: double = 4800
	MOV		TL1, #-12			; timer 1 sync
	SETB	TR1					; timer 1 start
	MOV		R0, #30H			; empty string start
loop:
	JNB		RI, loop			; wait for data received
	CLR		RI					; clear received flag
	MOV		A, SBUF				; fetch received byte
	CJNE	A, #8DH, skip		; receiver termination is 8DH
	JMP		done
skip:
	CLR		ACC.7				; clear parity bit
	MOV		@R0, A				; put into empty string
	INC		R0
	JMP		loop
done:
	END
