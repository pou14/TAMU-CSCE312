//File named "lab5_prob6.c"
#include <stdio.h>
int very_fast_function(int i){

	int result;
	
	__asm__(
		"movl %[input_i], %%eax;"      	//i stored in in eax
        "leal (%%rax,%%rax,2), %%ecx;" 	//return value stored in eax, return = i * 3
        "leal (%%rcx,%%rcx,4), %%ecx;" 	//return value = i * 3 * 5
        "addl $15, %%ecx;"             	//return = return + 15
        "cmpl $300, %%ecx;"            	//comparing return - 300
        "jle else;"              		//jump to else if temp <= 300
        "movl $0, %%eax;"              	//return = 0
        "jmp end;"                     	//jump to end
        "else:;"                 		//else block
        "addl $1, %%eax;"               //i++
        "end:;"                        	//end block
        : "=r" (result)                	//output: result in eax
        : [input_i] "r" (i)            	//input: i
        : "%ecx"                        	//return
	);

	return result;
}

int main(int argc, char *argv[])
{
	int i;
	i = 12;
	printf("The function value of i is %d\n", very_fast_function(i) );
	return 0;
}
