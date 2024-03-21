/*Arduino temperature logger
Using DS18B20 sensor
*/
#include <OneWire.h>

#define DS18B20_Pin 8
OneWire ow(DS18B20_Pin);

void setup(){
    Serial.begin(9600);
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
   
   // Extract information from retrieved data
   // Get serial number from ROM code data
   // The data is already in the Arduino, available to be used
    if (rom_code[0] != 0x28) {
        Serial.print("# Sensor is not a DS18B20 sensor!");
    }
    String registration_number;
    for (int i=1; i<7; i++){
        registration_number += String(rom_code[i], HEX);
    }
    Serial.println(registration_number); 

    // Read temperature information from scratchpad variable
    // The OR operator concatenate both "bit" blocks and then we allocate it to an integer so it already converts into real value (16bits integer)
    int16_t tempRead = (scratchpad[1] << 8) |  scratchpad[0] ; // shifting 8 bits because its the beginning of the number

    float tempCelsius = (float)tempRead / 16.0; /* divide by 2^4 for 4 digits, i.e. 12-bit resolution of the sensor 
    and the first 8 digits are decimal values*/
    Serial.println(tempCelsius, 4);

    delay(1500);
}