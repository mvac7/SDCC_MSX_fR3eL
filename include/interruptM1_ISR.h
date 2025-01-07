/* =============================================================================
Z80 interrupt Mode 1 MSX SDCC Library (fR3eL Project)
Library with basic functions to control the Interrupt Service Routine (ISR) for 
Z80 Mode 1 interrupts on MSX system.
https://github.com/mvac7/SDCC_MSX_fR3eL
============================================================================= */

#ifndef  __INTERRUPT_M1_ISR_H__
#define  __INTERRUPT_M1_ISR_H__


#ifndef _Z80interruptDefs_
#define _Z80interruptDefs_

#define  DisableI         __asm di __endasm
#define  EnableI          __asm ei __endasm

#define  HALT             __asm halt __endasm

#endif




/* =============================================================================
 Save_ISR

 Function : Save Old ISR vector
 Input    : -
 Output   : -
============================================================================= */
void Save_ISR(void);



/* =============================================================================
 Install_ISR

 Function : Set ISR vector  
 Input    : Function address
 Output   : -
============================================================================= */
void Install_ISR(void (*isr)(void));



/* =============================================================================
 Restore_ISR

 Function : Restore old ISR vector 
 Input    : -
 Output   : -
============================================================================= */
void Restore_ISR(void);



/* =============================================================================
 Disable_ISR

 Function : Disable ISR
            Install an ISR with the minimum code so as not to block the Z80.
 Input    : -
 Output   : -
============================================================================= */
void Disable_ISR(void);



/* =============================================================================
## Basic ISR for M1 interrupt of Z80

* Saves all Z80 registers on the stack.
* Calls the two hooks of the system: TIMI (VBLANK) and KEYI

Note: 
  You can optimize it, commenting on those records that you know you don't use 
  (such as alternate records) or removing the KEYI hook. 
============================================================================= */
void ISR_Basic(void);




#endif
