#include <MagzorI2C/MagzorI2C.h>
#include <wiringPi.h>

//Global Declarations
 
//MIC board address constants
static const uint8_t MOTOR_BOARD_1_ADDRESS = 0x30;
 
//MIC objects
I2CDevice_MotorBoard motor_board1(MOTOR_BOARD_1_ADDRESS);
 
//device objects
 
// connector 0 on Magzor MIC: 2x DC Motor board #1
XMotor motor1 = motor_board1.get_XMotor(0);
// connector 1 on Magzor MIC: 2x DC Motor board #1
XMotor motor2 = motor_board1.get_XMotor(1);

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
    
	//Increases the speed of the motor from 0 to 254
	//Decreases the speed of the motor from 255 to 1
	//Flips the motor direction and repeats
	while(true){	
		for(uint8_t i = 0; i < 255; ++i){
			motor1.set_speed(i);
			delay(10);
		}
		for(uint8_t i = 255; i > 0; --i){
			motor1.set_speed(i);
			delay(10);
		}		
		motor1.set_direction(XMotor::FLIP);		
	}
    
    return 0;
}
