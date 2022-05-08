$include (REG51.inc)

XBR2 EQU 0E3H

IT01CF EQU 0E4H

WDTCN EQU 97H

ORG 0000H
	JMP		main

; BUT on INT1=P0.2
ORG 0013H
	CPL		P1.4	; toggle LED
	RETI

main:
	MOV		XBR2, #01000000B	; port power
	MOV		WDTCN, #0DEH		; disable watchdog passcode
	MOV		WDTCN, #0ADH
	; EFM8 specific irq configuration
	MOV		IT01CF, #00100000B	; IRQ assign 6:4 INT1=P0.2 2:0 INT0 not assigned
	; 8051 standard irq configuration
	MOV		TCON, #00000100B	; enable INT1 edge
	MOV		IE, #10000100B		; enable INT1 IRQ and enable global
loop:
	JMP		loop

	END
