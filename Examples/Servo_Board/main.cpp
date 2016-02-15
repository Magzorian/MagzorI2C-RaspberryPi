#include <MagzorI2C/MagzorI2C.h>
#include <wiringPi.h>

//Global Declarations
 
//MIC board address constants
static const uint8_t SERVO_BOARD_1_ADDRESS = 0x20;
 
//MIC objects
I2CDevice_ServoBoard servo_board1(SERVO_BOARD_1_ADDRESS);
 
//device objects
 
// connector 0 on Magzor MIC: 8x Servo board #1
XServo servo1 = servo_board1.get_XServo(0);
// connector 1 on Magzor MIC: 8x Servo board #1
XServo servo2 = servo_board1.get_XServo(1);
// connector 2 on Magzor MIC: 8x Servo board #1
XServo servo3 = servo_board1.get_XServo(2);
// connector 3 on Magzor MIC: 8x Servo board #1
XServo servo4 = servo_board1.get_XServo(3);
// connector 4 on Magzor MIC: 8x Servo board #1
XServo servo5 = servo_board1.get_XServo(4);
// connector 5 on Magzor MIC: 8x Servo board #1
XServo servo6 = servo_board1.get_XServo(5);
// connector 6 on Magzor MIC: 8x Servo board #1
XServo servo7 = servo_board1.get_XServo(6);
// connector 7 on Magzor MIC: 8x Servo board #1
XServo servo8 = servo_board1.get_XServo(7);

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
    
	//Sets the servo angle from 0 to 180 with a 25 millisecond delay between angle increments
	//Then sets the servo angle from 180 to 1 with a 25 millisecond delay between angle increments
	//Repeats itself
	while(true){
		for(uint8_t i = 0; i <= 180; ++i){
			servo1.write(i);
			delay(25);
		}
		for(uint8_t i = 180; i > 0; --i){
			servo1.write(i);
			delay(25);
		}
	}
    
    return 0;
}
