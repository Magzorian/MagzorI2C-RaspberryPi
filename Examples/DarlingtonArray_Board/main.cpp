#include <MagzorI2C/MagzorI2C.h>
#include <wiringPi.h>

//Global Declarations

//MIC board address constants
static const uint8_t DARLINGTON_ARRAY_BOARD_ADDRESS = 0x60;
 
//MIC objects
I2CDevice_DarlingtonArrayBoard darlingtonarray_board1(DARLINGTON_ARRAY_BOARD_ADDRESS);

//device objects
XTransistor t0 = darlingtonarray_board1.get_XTransistor(0);
XTransistor t1 = darlingtonarray_board1.get_XTransistor(1);
XTransistor t2 = darlingtonarray_board1.get_XTransistor(2);
XTransistor t3 = darlingtonarray_board1.get_XTransistor(3);
XTransistor t4 = darlingtonarray_board1.get_XTransistor(4);
XTransistor t5 = darlingtonarray_board1.get_XTransistor(5);
XTransistor t6 = darlingtonarray_board1.get_XTransistor(6);
XTransistor t7 = darlingtonarray_board1.get_XTransistor(7);


static const uint8_t interrupt_pin = 0;
static const uint8_t reset_pin = 4;

using namespace std;

int main(int argc, char** argv) {
    if (wiringPiSetup() < 0) {
        fprintf(stderr, "Setup failed\n");
        exit(1);
    }
    
    MagzorI2C::setup(reset_pin, interrupt_pin);
    MagzorI2C::hardware_reset_i2c_devices();
    
	//Sinks the pin at a 1 second interval
	while(1){
		t0.enable();
		delay(1000);
		t0.disable();
		delay(1000);
	}
    
    return 0;
}
