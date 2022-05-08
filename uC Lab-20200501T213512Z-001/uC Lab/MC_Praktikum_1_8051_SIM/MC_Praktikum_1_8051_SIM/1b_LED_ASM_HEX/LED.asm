main:
	SETB	P1.0		; LED off (high)
	SETB	P2.0		; switch off (high)
	
loop:
	JNB		P2.0, led	; check switch (low) and jump
	SETB	P1.0		; if not : LED off (high)
	JMP		loop
led:
	CLR		P1.0		; LED on (low)
	CALL	delay		; switch de-bounce
	JMP		loop
	
delay:
	MOV		R0, #100
loop1:
	DJNZ	R0, loop1	; loop until 0
	RET
	
	END