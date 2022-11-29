#include "mbed.h"
 
// Initialise D2 as an OPEN DRAIN output
// It can be used in the same way as a normal DigitalOut
DigitalInOut trig(D2, PIN_OUTPUT, OpenDrain, 0);
 
// Initialise D3 as an input
DigitalIn echo(D3);
 
int main()
{
    while(true) {
        // Send 10us trigger pulse
        trig = true;
        wait_us(10);
        trig = false;
        
        while(!echo); // Wait for echo pulse to start
        while(echo);  // Wait for echo pulse to end
        printf("Echo received\n");
        thread_sleep_for(500);
    }
}
