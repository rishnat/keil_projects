	AREA	ACCESS_OP, CODE, READONLY
	EXPORT  settoprivileged
	EXPORT  settounprivileged	
	
settoprivileged PROC
	MRS R0,CONTROL
	
	AND R0, R0, #0xFE	;Clear 0th bit of control register
	MSR CONTROL, R0
	
	BX LR
	
	ENDFUNC
	
settounprivileged PROC
	MRS R0,CONTROL
	
	ORR R0, R0, #0x01	;Set 0th bit of control register
	MSR CONTROL, R0
	
	BX LR
	ENDFUNC
	
	
	END