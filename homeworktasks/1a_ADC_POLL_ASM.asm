ADC_WR EQU P3.6
ADC_INTR EQU P3.2
ADC_RD EQU P3.7
DAC_WR EQU P0.7

main:
	CLR ADC_WR		; enables ADC write
	SETB ADC_WR		; disables ADC write

loop:
	JB ADC_INTR, loop	; ADC_INTR pin used for polling
	CLR ADC_RD			; enables ADC read	
	MOV P1, P2			; stores data for the write process
	SETB ADC_RD			; disables ADC read
	CLR DAC_WR			; enables DAC write and write the values
	JMP main