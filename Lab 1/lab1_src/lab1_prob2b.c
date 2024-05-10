/*
   Instructions -

   To run this program - first compile to create an executable,
   then run the executable code.

   Type the following in the Linux console/shell to compile and make an executable using the gcc complier -

   gcc lab1_prob1.c -o lab1_prob1

   To run the executable named "lab1_prob1", type the following -

   ./lab1_prob1
*/


#include <stdio.h>    // For input/output
#include <stdlib.h>   // For exit()
#include <sys/time.h> // For gettimeofday() function

int main()
{
    struct employee1{
        int id;
        char name[50];
    };
    struct employee2{
        int id;
        char name[52];
    };

   
    printf("struct employee1 data type is %lu bytes or %lu bits long\n",sizeof(struct employee1), sizeof(struct employee1)*8);
    printf("struct employee2 data type is %lu bytes or %lu bits long\n",sizeof(struct employee2), sizeof(struct employee2)*8);

    return 0;
}
