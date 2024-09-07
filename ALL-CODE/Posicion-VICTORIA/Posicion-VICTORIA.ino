//Script to control InMoov Arm using Aoutecen EMG Muscle Sensor V3 from Advancer Technologies
//by Victor Alonso (vicadel@alumni.uv.es)
//Valencia (Spain)
//July 2024
//Part of TFG 3D Prosthetic Hand & Forearm - InMoov Project 

//For information about Aoutecen EMG Muscle Sensor V3 board, manual and other resources, please visit:
//https://www.tme.eu/Document/8732078ad54d82f6b49c5284341026b5/POLOLU-2726.pdf


/* * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */


// Includes the ESP32Servo library which allows control of servomotors with an ESP32
#include <ESP32Servo.h>

// Check if ESP32 is defined - provides flexibility and specificity for the ESP32 microcontroller
#ifdef ESP32    

// Define analog and digital pins for the ESP32
// ANALOG PINS A0-A7
#define A0 2
#define A1 4
#define A2 35
#define A3 34
#define A4 36
#define A5 39
#define A6 32
#define A7 33

// DIGITAL PINS D2-D13 
#define D2 26
#define D3 25
#define D4 17
#define D5 16
#define D6 27
#define D7 14
#define D8 12
#define D9 13
#define D10 5
#define D11 23
#define D12 19
#define D13 18
#endif

// Define servo objects for fingers
// myservo1-5 are for the fingers
// myservo6 is for the wrist, commented out because for the first exercise
// we only want finger movement, not wrist movement

// int servo_pin = 9;  // for Arduino microcontroller
// int servo_pin = D7;  // for ESP8266 microcontroller
// int servo_pin = D2;  // for ESP32 microcontroller

// Initialization of servo objects
Servo myservo1, myservo2, myservo3, myservo4, myservo5, myservo6;

int angle = 0;  // Variable to store the angle of the servomotors 

//POSICION DE MANO VICTORIA/VICTORY : myservo1,myservo2,myservo5 ESCONDIDOS y myservo3 y myservo4 movimiento para posicion VICTORIA/VICTORY

void setup() 
{ 
  // Attach each servomotor to a digital pin on the ESP32
  myservo1.attach(D2);    // Attach the first servomotor to pin D2 (26)                   //MENIQUE
  myservo2.attach(D3);    // Attach the second servomotor to pin D3 (25)                  //ANULAR
  myservo3.attach(D4);    // Attach the third servomotor to pin D4 (17)                   //CORAZON
  myservo4.attach(D5);    // Attach the fourth servomotor to pin D5 (16)                  //INDICE
  myservo5.attach(D6);    // Attach the fifth servomotor to pin D6 (27)                   //PULGAR
  //myservo6.attach(D7);  // Attach the sixth servomotor to pin D7 (14)
} 

void loop() 
{ 
  // Move from 0 to 180 degrees with a positive angle of 1
  for(angle = 0; angle < 180; angle += 1)
  {                          
    //myservo1.write(angle);  // Move the first servo to the position 180 - angle, a temporary adjustment to fix the servo's reverse direction
    //myservo2.write(angle);        // Move the second servo to the position angle
    myservo3.write(angle);        // Move the third servo to the position angle
    myservo4.write(angle);        // Move the fourth servo to the position angle
    //myservo5.write(angle);        // Move the fifth servo to the position angle
    //myservo6.write(angle);     // Move the sixth servo to the position angle (IN TESTING)
    delay(15);                    // Wait 15 milliseconds to smooth the servo's movement                
  } 

  delay(1000);                    // Wait 1 second before starting the next movement
  
  // Move from 180 to 0 degrees with a negative angle of 5
  for(angle = 180; angle >= 1; angle -= 5)
  {                                
    myservo1.write(angle);  // Move the first servo to the position 180 - angle
    myservo2.write(angle);        // Move the second servo to the position angle
    myservo3.write(angle);        // Move the third servo to the position angle
    myservo4.write(angle);        // Move the fourth servo to the position angle
    myservo5.write(angle);        // Move the fifth servo to the position angle
    //myservo6.write(180 - angle);  // Move the sixth servo to the position 180 - angle (IN TESTING)
    delay(5);                     // Wait 5 milliseconds to smooth the servo's movement
  } 

  delay(1000);                    // Wait 1 second before repeating the cycle
}