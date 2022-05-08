NAME    ASM

?PR?keypad?ASM   SEGMENT CODE
PUBLIC  keypad
                RSEG   ?PR?keypad?ASM
                USING  0

keypad:
	MOV R7, #-1
	ORL P0, #01111111B
row3:
	CLR P0.3
	JNB P0.6, key1
	JNB P0.5, key2
	JNB P0.4, key3
	ORL P0, #01111111B
row2:
	CLR P0.2
	JNB P0.6, key4
	JNB P0.5, key5
	JNB P0.4, key6
	ORL P0, #01111111B
row1:
	CLR P0.1
	JNB P0.6, key7
	JNB P0.5, key8
	JNB P0.4, key9
	ORL P0, #01111111B
row0:
	CLR P0.0
	JNB P0.6, keystar
	JNB P0.5, key0
	JNB P0.4, keydash
	
	RET
	
key1:
	MOV R7, #1
	RET
key2:
	MOV R7, #2
	RET
key3:
	MOV R7, #3
	RET
key4:
	MOV R7, #4
	RET
key5:
	MOV R7, #5
	RET
key6:
	MOV R7, #6
	RET
key7:
	MOV R7, #7
	RET
key8:
	MOV R7, #8
	RET
key9:
	MOV R7, #9
	RET
keystar:
	MOV R7, #0	; no keystar
	RET
key0:
	MOV R7, #0
	RET
keydash:
	MOV R7, #0	; keydash
	RET

	END