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
    byte rom_code[8]; // create an array containing 8 elements of type byte for the rom code
    byte scratchpad[9];

    ow.reset(); // 1st step: Initialization

    // 2nd step: ROM command (since we only have one slave, we use Read Room 33). This reads the ROM information.
    ow.write(0x33);
    for (int i=0; i<8; i++){
        rom_code[i] = ow.read();
    }

    // 3rd step: DS18B20 Function Command. Start sequence to convert temperature.
    ow.reset();
    ow.write(0xCC); //skip the ROM
    ow.write(0x44); //convert temperatures

    // Start sequence to read data from the scratchpad - HEX Code 0xBE
    ow.reset();
    ow.write(0xCC);
    ow.write(0xBE);

    for (int i=0; i<9; i++){
        scratchpad[i] = ow.read();
    }
   
}