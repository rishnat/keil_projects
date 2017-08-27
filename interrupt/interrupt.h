#ifndef _INTERRUPT_H
#define _INTERRUPT_H



void PortFInit(void);
_Bool isprivileged(void);
void settoprivileged(void);
void settounprivileged(void);


#endif

