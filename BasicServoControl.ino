// Script to control Servos
// by Victor Alonso (vicadel@alumni.uv.es)
// Valencia (Spain)
// July 2024
// Part of TFG 3D Prosthetic Hand & Forearm - InMoov Project 

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

// Instantiate our servo
Servo servo;   // Creates a Servo object named 'servo'

// Define the pin to which the servo is connected
int pinServo = 2;

void setup() {
  // Initialize the servo position and specify the pin to which it is connected
  servo.attach(pinServo, 500, 2500);
}

// Initialize the servo position variable in degrees
int pos = 0;

void loop() {
  // Loop to position the servo from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // Move the servo to the 'pos' position in degrees
    servo.write(pos);
    // Wait 15 milliseconds before the next iteration
    delay(15);
  }

  // Loop to position the servo from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    // Move the servo to the 'pos' position in degrees
    servo.write(pos);
    // Wait 15 milliseconds before the next iteration
    delay(15);
  }
}
