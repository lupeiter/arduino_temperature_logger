/*Arduino temperature logger
Using DS18B20 sensor
*/
#include OneWire.h

#define DS18B20_Pin 8
OneWire ow(DS18B20_Pin);

void setup(){

}

void loop(){
    /* We always need to follow this 1, 2 and 3 sequence */
    byte rom_code(8); // create an array containing 8 elements of type byte for the rom code
  
    ow.reset(); // 1st step: Initialization

    // 2nd step: ROM command (since we only have one slave, we use Read Room 33). This reads the ROM information.
    ow.write(0x33);

    for (int i=0; i<8; i++){
        rom_code[i] = ow.read();
    }

    // 3rd step: DS18B20 Function Command. Start sequence to convert temperature.


}