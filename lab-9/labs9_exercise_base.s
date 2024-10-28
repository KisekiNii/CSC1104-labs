    //@ labs9_exercise.s; Function using two-operand instruction for X0 = (X2 – X3) * (X4 + X5) 

    //@ data sector is for initialized variables and constants
    .data

    //@ text sector is for the actual code;
    .text
    .global  main                         //@ start the assembly code;

     main: 
     		SUB     sp, sp, #16  // Store the return address, i.e., link reg. (lr), and
    		STR     X30, [sp]	// Save the return lr to stack.

                MOV     X2, #9          //@ initial value in register X2;
                MOV     X3, #7          //@ initial value in register X3;
                MOV     X4, #6          //@ initial value in register X4;
                MOV     X5, #4          //@ initial value in register X5;
                
                MOV     X6, X2          //@ X6 = X2;
                SUB     X6, X6, X3      //@ X6 = X6 - X3 = X2 - X3
                MOV     X1, X4          //@ X1 = X4
                ADD     X1, X1, X5      //@ X1 = X1 + X5 = X4 + X5
                MUL     X0, X6, X1      //@ X0 = X6 * X1;    

    		LDR     X30, [sp]       // Access the stack
    		ADD     sp, sp, #16     // get back the lr (link reg.) value, return;
    		RET                     //@ end program; return to previous instruction; LR: Link Reg.
    


