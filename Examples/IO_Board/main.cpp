#include <MagzorI2C/MagzorI2C.h>
#include <wiringPi.h>

//Global Declarations
 
//MIC board address constants
static const uint8_t GPIO_BOARD_1_ADDRESS = 0x10;
 
//MIC objects
I2CDevice_IOBoard io_board1(GPIO_BOARD_1_ADDRESS);
 
//device objects
 
// connector 0 on Magzor MIC: 10x GPIO board #1
XPin digital_pin1 = io_board1.get_XPin(0);
// connector 1 on Magzor MIC: 10x GPIO board #1
XPin digital_pin2 = io_board1.get_XPin(1);
// connector 2 on Magzor MIC: 10x GPIO board #1
XPin digital_pin3 = io_board1.get_XPin(2);
// connector 3 on Magzor MIC: 10x GPIO board #1
XPin digital_pin4 = io_board1.get_XPin(3);
// connector 4 on Magzor MIC: 10x GPIO board #1
XPin digital_pin5 = io_board1.get_XPin(4);
// connector 5 on Magzor MIC: 10x GPIO board #1
XPin digital_pin6 = io_board1.get_XPin(5);
// connector 6 on Magzor MIC: 10x GPIO board #1
XPin digital_pin7 = io_board1.get_XPin(6);
// connector 7 on Magzor MIC: 10x GPIO board #1
XPin digital_pin8 = io_board1.get_XPin(7);
// connector 8 on Magzor MIC: 10x GPIO board #1
XPin digital_pin9 = io_board1.get_XPin(8);
// connector 9 on Magzor MIC: 10x GPIO board #1
XPin digital_pin10 = io_board1.get_XPin(9);

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
	
	//register MIC boards for interrupts
	MagzorI2C::register_i2c_device(io_board1);
    
	
	//Blinks the pin at a 1 second interval
	while(1){
		digital_pin1.digitalWrite(true);
		delay(1000);
		digital_pin1.digitalWrite(false);
		delay(1000);
	}
    
    return 0;
}
