//Script to control InMoov Arm using Aoutecen EMG Muscle Sensor V3 from Advancer Technologies
//by Victor Alonso (vicadel@alumni.uv.es)
//Valencia (Spain)
//July 2024
//Part of TFG 3D Prostetic Hand & Forarm - InMoov Project 

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


//Incluye la librería ESP32Servo que permite controlar servomotores con un ESP32
#include <ESP32Servo.h>

//ESP32 esta definido - flexibilidad y concrecion para el micro ESP32             
#ifdef ESP32    

// Definición de pines analógicos y digitales para el ESP32
//ANALOGICOS A0-A7
#define A0 2
#define A1 4
#define A2 35
#define A3 34
#define A4 36
#define A5 39
#define A6 32
#define A7 33

//DIGITALES D2-D13 
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


//myservo1-5 servomotores de los dedos

//int servo_pin = 9;  // for Arduino microcontroller
//int servo_pin = D7;  // for ESP8266 microcontroller
//int servo_pin = D2;  // for ESP32 microcontroller

//Inicializacion de objetos
Servo myservo1, myservo2, myservo3, myservo4, myservo5;

int angle = 0;  //Variable que almacenara el angulo de los servomotores 
 

void setup() 
{ 
  //Asocia cada servomotor a un pin digital del ESP32
  myservo1.attach(D2);    // Asocia el primer servomotor al pin D2 (26)
  myservo2.attach(D3);    // Asocia el segundo servomotor al pin D3 (25)
  myservo3.attach(D4);    // Asocia el tercer servomotor al pin D4 (17)
  myservo4.attach(D5);    // Asocia el cuarto servomotor al pin D5 (16)
  myservo5.attach(D6);    // Asocia el quinto servomotor al pin D6 (27)
} 
  
void loop() 
{ 
   
  // Move from 0 to 180 degrees with a positive angle of 1
  // Mueve los servos de 0 a 180 grados incrementando el angulo en 1 grado cada iteración
  for(angle = 0; angle < 180; angle += 1)
  {                          
    myservo1.write(180-angle);  //Mueve el primer servo a la posicion 180-angle, esto es un ajuste temporal para arreglar el sentido contrario del servo
    myservo2.write(angle);      // Mueve el segundo servo a la posición angle
    myservo3.write(angle);      // Mueve el tercer servo a la posición angle
    myservo4.write(angle);      // Mueve el cuarto servo a la posición angle
    myservo5.write(angle);      // Mueve el quinto servo a la posición angle
    delay(15);                  // Espera 15 milisegundos para suavizar el movimiento del servo                
  } 

  delay(1000);                  // Espera 1 segundo antes de iniciar el siguiente movimiento
  
   // Move from 180 to 0 degrees with a negative angle of 5
   // Mueve los servos de 180 a 0 grados decrementando el ángulo en 5 grados cada iteración
  for(angle = 180; angle>=1; angle-=5)
  {                                
    myservo1.write(180-angle);    // Mueve el primer servo a la posición 180 - angle
    myservo2.write(angle);        // Mueve el segundo servo a la posición angle
    myservo3.write(angle);        // Mueve el tercer servo a la posición angle
    myservo4.write(angle);        // Mueve el cuarto servo a la posición angle
    myservo5.write(angle);        // Mueve el quinto servo a la posición angle
    delay(5);                     // Espera 5 milisegundos para suavizar el movimiento del servo
  } 

    delay(1000);                // Espera 1 segundo antes de repetir el ciclo
}
