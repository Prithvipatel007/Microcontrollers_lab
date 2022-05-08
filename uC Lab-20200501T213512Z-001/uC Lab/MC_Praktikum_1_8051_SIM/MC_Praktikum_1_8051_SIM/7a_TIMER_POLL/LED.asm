main:
	MOV		TMOD, #20H
	MOV		TH1, #5
	CLR		TF1
	SETB	TR1
loop:
    MOV		P1, #0
    CALL	T1Wait
    MOV		P1, #0FFH
    CALL	T1Wait
	JMP		loop
	
T1Wait:
	JNB		TF1, T1Wait
	CLR		TF1
	RET
	
	END