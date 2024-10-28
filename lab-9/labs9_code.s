//@ labs9_code.s

//@ This is Data section
.data
.balign 8       //@ Ensure variable is 8-byte aligned (64-bit)
variable1:  .word	0x5      //@ Initial value of variable1 

.balign 8       //@ Ensure variable is 8-byte aligned (64-bit)
variable2:  .word	0x6        //@ Initial value of variable2


//@ This is Code section 
.text
.global main    //@ entry of the program

main:
    SUB     sp, sp, #16  	// Store the return address, i.e., link reg. (lr), and
    STR     X30, [sp]		// Save the return lr to stack.

    MOV     X3, #10             //@ X3 ← 10; assign the value to X3
    LDR     X1, =variable1      //@ X1 ← &variable1. Load address into X1
    STR     X3, [X1]            //@ *X1 ← X3. store X3 value into var address in X1

    MOV     X4, #15             //@ X4 ← 15; assign the value to X3   
    LDR     X2, =variable2      //@ X2 ← &variable2. Load address into X2
    STR     X4, [X2]            //@ *X2 ← X4. store X4 value into var address in X2

    LDR     X1, =variable1      //@ X1 ← &variable1. Load address into X1
    LDR     X1, [X1]            //@ X1 ← *X1. Load the value at address in X1
    LDR     X2, =variable2      //@ X2 ← &variable2. Load address into X2
    LDR     X2, [X2]            //@ X2 ← *X2. Load the value at address in X2
    ADD     X0, X1, X2          //@ X0 ← X1 + X2

    LDR     X30, [sp]      	// Access the stack
    ADD     sp, sp, #16   	// get back the lr (link reg.) value, return;
    RET                     	//@ end program; return to previous instruction; LR: Link Reg.


