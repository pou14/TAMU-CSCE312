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
    int int_var;

    struct timeval this_instant;
    double time_stamp;

    FILE *my_file_pointer;
    if ( (my_file_pointer = fopen("lab1_prob1_out.txt", "w")) == NULL)
    {
        printf("Error opening the file, so exiting\n");
        exit(1);
    }

    gettimeofday(&this_instant, 0);
    time_stamp = this_instant.tv_sec;

    //Code segment for file I/O
    fprintf(my_file_pointer, "This program was executed at time : %ld or %f\n", this_instant.tv_sec, time_stamp);

    fprintf(my_file_pointer, "The sizes of different data type for this machine and compiler are -\n");

    fprintf(my_file_pointer, "int data type is %lu bytes or %lu bits long\n",sizeof(int_var), sizeof(int_var)*8);
    fprintf(my_file_pointer, "unsigned int data type is %lu bytes or %lu bits long\n",sizeof(unsigned int), sizeof(unsigned int)*8);
    fprintf(my_file_pointer, "double data type is %lu bytes or %lu bits long\n",sizeof(double), sizeof(double)*8);
    fprintf(my_file_pointer, "long data type is %lu bytes or %lu bits long\n",sizeof(long), sizeof(long)*8);
    fprintf(my_file_pointer, "long long data type is %lu bytes or %lu bits long\n",sizeof(long long), sizeof(long long)*8);
    fprintf(my_file_pointer, "char data type is %lu bytes or %lu bits long\n",sizeof(char), sizeof(char)*8);
    fprintf(my_file_pointer, "float data type is %lu bytes or %lu bits long\n",sizeof(float), sizeof(float)*8);
    fprintf(my_file_pointer, "struct timeval data type is %lu bytes or %lu bits long\n",sizeof(struct timeval), sizeof(struct timeval)*8);
    fprintf(my_file_pointer, "short data type is %lu bytes or %lu bits long\n",sizeof(short), sizeof(short)*8);
    fprintf(my_file_pointer, "FILE* data type is %lu bytes or %lu bits long\n",sizeof(FILE*), sizeof(FILE*)*8);

    

    //Code segment for console I/O, this can be used instead of the file I/O
    printf("This program was executed at time : %ld or %f\n", this_instant.tv_sec, time_stamp);

    printf("The sizes of different data type for this machine and compiler are -\n");
    printf("int data type is %lu bytes or %lu bits long\n",sizeof(int_var), sizeof(int_var)*8);
    printf("unsigned int data type is %lu bytes or %lu bits long\n",sizeof(unsigned int), sizeof(unsigned int)*8);
    printf("double data type is %lu bytes or %lu bits long\n",sizeof(double), sizeof(double)*8);
    printf("long data type is %lu bytes or %lu bits long\n",sizeof(long), sizeof(long)*8);
    printf("long long data type is %lu bytes or %lu bits long\n",sizeof(long long), sizeof(long long)*8);
    printf("char data type is %lu bytes or %lu bits long\n",sizeof(char), sizeof(char)*8);
    printf("float data type is %lu bytes or %lu bits long\n",sizeof(float), sizeof(float)*8);
    printf("struct timeval data type is %lu bytes or %lu bits long\n",sizeof(struct timeval), sizeof(struct timeval)*8);
    printf("short data type is %lu bytes or %lu bits long\n",sizeof(short), sizeof(short)*8);
    printf("FILE* data type is %lu bytes or %lu bits long\n",sizeof(FILE*), sizeof(FILE*)*8);

    fclose(my_file_pointer); //To close the output file, mandatory to actually get an output !
    return 0;
}
