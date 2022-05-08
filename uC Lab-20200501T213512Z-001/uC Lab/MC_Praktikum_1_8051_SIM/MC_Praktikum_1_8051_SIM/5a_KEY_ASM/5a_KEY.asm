main:
	MOV		R0, #-1
	ORL		P0, #01111111B
row3:
	CLR		P0.3
	JNB		P0.6, key1
	JNB		P0.5, key2
	JNB		P0.4, key3
	JMP		main
key1:
	MOV		R0, #1
	RET
key2:
	MOV		R0, #2
	RET
key3:
	MOV		R0, #3
	RET

	END