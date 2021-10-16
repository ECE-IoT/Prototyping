# PH- Sensor Atlas Scientific EZO-pH

## Atlas Scientific EZO-pH
- 3.3 to 5V power and I/O
- Range: 0.001-14
- Accuracy: +/- 0,002
- Body size : 13.97mm x 20.16mm
- Communication Interface: I2C, UART
> More information can be found [here](https://www.amazon.com/dp/B00641R1PQ/)
> or [here] (https://learn.adafruit.com/reef-pi-guide-7-ph-monitoring/overview)
> or [here] (https://www.exp-tech.de/module/chemie/6134/ezo-ph-circuit)

- requieres a probe for testing!

## Libraries

- Ezo I2C libary
- Ezo UART libary



## Implementation
### arduino 
//This code was written to be easy to understand.
//Modify this code as you see fit.
//This code will output data to the Arduino serial monitor.
//Type commands into the Arduino serial monitor to control the pH circuit.
//This code was written in the Arduino 1.8.9 IDE
//An Arduino UNO was used to test this code.
//This code was last tested 6/2019


#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#define rx 2                                          //define what pin rx is going to be
#define tx 3                                          //define what pin tx is going to be

SoftwareSerial myserial(rx, tx);                      //define how the soft serial port is going to work


String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_complete = false;               //have we received all the data from the Atlas Scientific product
float pH;                                             //used to hold a floating point number that is the pH



void setup() {                                        //set up the hardware
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  myserial.begin(9600);                               //set baud rate for the software serial port to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product
}


void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC
}


void loop() {                                         //here we go...

  if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    myserial.print('\r');                             //add a <CR> to the end of the string
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;                           //add the char to the var called sensorstring
    if (inchar == '\r') {                             //if the incoming character is a <CR>
      sensor_string_complete = true;                  //set the flag
    }
  }


  if (sensor_string_complete == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
    /*                                                //uncomment this section to see how to convert the pH reading from a string to a float 
    if (isdigit(sensorstring[0])) {                   //if the first character in the string is a digit
      pH = sensorstring.toFloat();                    //convert the string to a floating point number so it can be evaluated by the Arduino
      if (pH >= 7.0) {                                //if the pH is greater than or equal to 7.0
        Serial.println("high");                       //print "high" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
      }
      if (pH <= 6.999) {                              //if the pH is less than or equal to 6.999
        Serial.println("low");                        //print "low" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
      }
    }
    */
    sensorstring = "";                                //clear the string
    sensor_string_complete = false;                   //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
}

### I2C
//This code will work on an Arduino Uno and Mega
//This code was written to be easy to understand.
//Modify this code as you see fit.
//This code will output data to the Arduino serial monitor.
//Type commands into the Arduino serial monitor to control the Ph circuit.
//This code was written in the Arduino 1.8.9 IDE
//This code was last tested 7/2019


#include <Wire.h>                //enable I2C.
#define address 99               //default I2C ID number for EZO pH Circuit.



char computerdata[20];           //we make a 20 byte character array to hold incoming data from a pc/mac/other.
byte received_from_computer = 0; //we need to know how many characters have been received.
byte serial_event = 0;           //a flag to signal when data has been received from the pc/mac/other.
byte code = 0;                   //used to hold the I2C response code.
char ph_data[20];                //we make a 20 byte character array to hold incoming data from the pH circuit.
byte in_char = 0;                //used as a 1 byte buffer to store inbound bytes from the pH Circuit.
byte i = 0;                      //counter used for ph_data array.
int time_ = 815;                 //used to change the delay needed depending on the command sent to the EZO Class pH Circuit.
float ph_float;                  //float var used to hold the float value of the pH.


void setup()                     //hardware initialization.
{
  Serial.begin(9600);           //enable serial port.
  Wire.begin();                 //enable I2C port.
}


void serialEvent() {                                                              //this interrupt will trigger when the data coming from the serial monitor(pc/mac/other) is received.
  received_from_computer = Serial.readBytesUntil(13, computerdata, 20);           //we read the data sent from the serial monitor(pc/mac/other) until we see a <CR>. We also count how many characters have been received.
  computerdata[received_from_computer] = 0;                                       //stop the buffer from transmitting leftovers or garbage.
  serial_event = true;                                                            //set the serial event flag.
}


void loop() {                                                                     //the main loop.
  if (serial_event == true) {                                                     //if a command was sent to the EZO device.
    for (i = 0; i <= received_from_computer; i++) {                               //set all char to lower case, this is just so this exact sample code can recognize the "sleep" command.
      computerdata[i] = tolower(computerdata[i]);                                 //"Sleep" ≠ "sleep"
    }
    i=0;                                                                          //reset i, we will need it later 
    if (computerdata[0] == 'c' || computerdata[0] == 'r')time_ = 815;             //if a command has been sent to calibrate or take a reading we wait 815ms so that the circuit has time to take the reading.
    else time_ = 250;                                                             //if any other command has been sent we wait only 250ms.
    

    Wire.beginTransmission(address);                                              //call the circuit by its ID number.
    Wire.write(computerdata);                                                     //transmit the command that was sent through the serial port.
    Wire.endTransmission();                                                       //end the I2C data transmission.


    if (strcmp(computerdata, "sleep") != 0) {  	                                  //if the command that has been sent is NOT the sleep command, wait the correct amount of time and request data.
                                                                                  //if it is the sleep command, we do nothing. Issuing a sleep command and then requesting data will wake the circuit.

      delay(time_);								                                                //wait the correct amount of time for the circuit to complete its instruction.

      Wire.requestFrom(address, 20, 1); 		                                      //call the circuit and request 20 bytes (this may be more than we need)
      code = Wire.read();               		                                      //the first byte is the response code, we read this separately.

      switch (code) {							          //switch case based on what the response code is.
        case 1:                         		//decimal 1.
          Serial.println("Success");    		//means the command was successful.
          break;                        		//exits the switch case.

        case 2:                         		//decimal 2.
          Serial.println("Failed");     		//means the command has failed.
          break;                        		//exits the switch case.

        case 254:                       		//decimal 254.
          Serial.println("Pending");    		//means the command has not yet been finished calculating.
          break;                        		//exits the switch case.

        case 255:                       		//decimal 255.
          Serial.println("No Data");    		//means there is no further data to send.
          break;                        		//exits the switch case.
      }





      while (Wire.available()) {         		//are there bytes to receive.
        in_char = Wire.read();           		//receive a byte.
        ph_data[i] = in_char;					      //load this byte into our array.
        i += 1;                          		//incur the counter for the array element.
        if (in_char == 0) {              		//if we see that we have been sent a null command.
          i = 0;                         		//reset the counter i to 0.
          break;                         		//exit the while loop.
        }
      }

      Serial.println(ph_data);          		//print the data.
    }
    serial_event = false;                   //reset the serial event flag.
  }
  //Uncomment this section if you want to take the pH value and convert it into floating point number.
  //ph_float=atof(ph_data);
}