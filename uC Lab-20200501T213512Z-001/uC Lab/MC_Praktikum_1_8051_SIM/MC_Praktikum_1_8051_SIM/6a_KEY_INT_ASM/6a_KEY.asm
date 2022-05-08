ORG 000
	JMP		main

; INT1
ORG 013H
	JNB		P0.6, key1
	JNB		P0.5, key2
	JNB		P0.4, key3
key1:
	CPL		P1.0			; LED on P1.0
	RETI
key2:
	CPL		P1.1			; LED on P1.1
	RETI
key3:
	CPL		P1.2			; LED on P1.2
	RETI

ORG 180H
main:
	MOV		TCON, #00000100B	; enable INT1 edge
	MOV		IE, #10000100B		; enable INT1 IRQ and enable global
	
	ORL		P0, #01111111B		; all key lines high
	CLR		P0.3				; row3 line low
loop:
	JMP		loop				; wait for IRQ
	
	END