// CSCE312: Lab-1 Problem-3 framework

/* ***   README   **** */

/*
   This example program sounds the bell when driver is on seat
   AND haven't closed the doors. Use the general framework and the function
   shells, replace the code inside the control_action() function with your
   own code to do problems 3.

Note: This code is designed to run in an infinite loop to mimic a real control system.
If you prefer to read the inputs from a file, modify the code appropriately to terminate the
loop when all the inputs have been processed.

Turning in this file without your code will result in zero points being awarded for this problem.

run this file as : gcc -std=c99 filename.c -o executableName

*/


#include <stdio.h> //This is useful to do i/o to test the code

unsigned int driver_seat_belt_fastened;
unsigned int engine_running;
unsigned int doors_closed;
unsigned int door_lock_lever;
unsigned int driver_on_seat;
unsigned int key_in_car;
unsigned int brake_pedal;
unsigned int car_moving;

unsigned int bell = 0;
unsigned int door_lock_actu = 0;
unsigned int brake_actu = 0;

void read_inputs_from_ip_if(){
	
	// 1. Provide your input code here
	// This function should read the current state of the available sensors (8 in total)
    
    printf("Driver Seat Belt Fastened?\t");
    scanf("%u", &driver_seat_belt_fastened);
    
    printf("Enginer Running?\t");
    scanf("%u", &engine_running);
    
    printf("Doors Closed?\t");
    scanf("%u", &doors_closed);
    
    printf("Door Lock Leaver activated?\t");
    scanf("%u", &door_lock_lever);

    printf("Driver on the Seat?\t");
    scanf("%u", &driver_on_seat);

    printf("Key in Car?\t");
    scanf("%u", &key_in_car);

    printf("Break Pedal activated?\t");
    scanf("%u", &brake_pedal);

    printf("Car Moving?\t");
    scanf("%u", &car_moving);

	// Hint : You can use scanf to obtain inputs for the sensors

}

void write_output_to_op_if(){

    // 2. Provide your output code here
    // This function should display/print the state of the 3 actuators (BELL/DLA/BA)
    printf("\n(BELL/DLA/BA):\t (%u/%u/%u)\n", bell, door_lock_actu, brake_actu);
}


// The code segment which implements the decision logic
void control_action(){

    /*
       The code given here sounds the bell when driver starts the engine and
       hasn't closed the doors. (Requirement-2)
      
       3. Provide your own code to do problems 3, which satisfies 5 requirements 
    */

    if(!driver_seat_belt_fastened && engine_running){
        bell = 1;
    }else if(engine_running && !doors_closed){
        bell = 1;
    }else{
        bell = 0;
    }

    if(!driver_on_seat && key_in_car && door_lock_lever){
        door_lock_actu = 0;
    }else if(driver_on_seat && door_lock_lever){
        door_lock_actu = 1;
    }else{
        door_lock_actu = 0;
    }

    if(car_moving && brake_pedal){
        brake_actu = 1;
    }else{
        brake_actu = 0;
    }


}


/* ---     You do not need to modify codes shown below  ---- */

int main(int argc, char *argv[])
{

    // code segment 1 starts here
    /*
        The main control loop which keeps the system alive and responsive for ever,
        until the system is powered off
    */

    // for (; ; ) {
    //     bell = 0;
    //     door_lock_actu = 0;
    //     brake_actu = 0;

    //     read_inputs_from_ip_if();
    //     control_action();
    //     write_output_to_op_if();
    // }

    // code segment 1 ends here
 
    
    // code segment 2 starts here
    /*
        Below is 8 different test cases provided you for testing purposes.
        Please uncomment this code segment 2 and comment out the code segment 1
        and run the file using command shown below
        gcc -std=c99 -o test lab1_prob3.c
        4. Please provide the screenshot of the output obtained from running this code segment 2 
        and your code written from 1-3 to the lab report 
    */

    int test[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0}, 
                        {1, 1, 0, 0, 0, 1, 0, 1}, 
                        {1, 0, 1, 0, 1, 1, 1, 1}, 
                        {0, 1, 0, 1, 0, 1, 0, 0}, 
                        {0, 1, 1, 1, 1, 1, 1, 0}, 
                        {1, 1, 0, 1, 0, 1, 0, 1}, 
                        {1, 1, 1, 1, 1, 1, 1, 1}, 
                        {0, 1, 0, 0, 0, 1, 1, 0} };

    for (int i = 0; i < 8; i++) {
        bell = 0;
        door_lock_actu = 0;
        brake_actu = 0;

    	driver_seat_belt_fastened = test[i][0];
        engine_running = test[i][1]; 
        doors_closed = test[i][2];
        door_lock_lever = test[i][3];
        driver_on_seat = test[i][4];
        key_in_car = test[i][5];
        brake_pedal = test[i][6];
        car_moving = test[i][7];
        
        control_action();
        printf("\nTest %d: ", i);
        printf(" %d %d %d %d %d %d %d %d ", driver_seat_belt_fastened, engine_running, doors_closed,
                                             door_lock_lever, driver_on_seat, key_in_car, 
                                             brake_pedal, car_moving);
        write_output_to_op_if();
    }

    // code segment 2 ends here

    return 0;
}
