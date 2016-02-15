#include <MagzorI2C/MagzorI2C.h>
#include <wiringPi.h>

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
    
	printf("Hello world from Magzor!\n");
    
    return 0;
}
