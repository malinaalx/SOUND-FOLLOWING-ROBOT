#include<Arduino.h>


// declare constant variables for motor control pins
const int leftMotorForwardPin = 5;
const int leftMotorBackwardPin = 6;
const int rightMotorForwardPin = 8;
const int rightMotorBackwardPin = 9;


const int buzzerPin = 7;      // Buzzer on pin 7
const int ledPin = 13;        // LED on pin 13

// constant variables for microphone pins
const int mic1pin = A0;
const int mic2pin = A1;

// other variables
const int sample_window = 3000; // amount of time to sample sound in milliseconds
int mic1;      // microphone 1 value from analogRead (0-1023)
int mic2;      // microphone 2 value from analogRead (0-1023)
int mic1_max;  // maximum value recorded by mic1 during sample window
int mic1_min;  // minimum value recorded by mic1 during sample window
int mic2_max;  // maximum value recorded by mic2 during sample window
int mic2_min;  // minimum value recorded by mic2 during sample window
int amp1;      // largest amplitude of mic1 during sample window (max-min)
int amp2;      // largest amplitude of mic2 during sample window (max-min)
int difference;  // difference between the mic amplitudes
unsigned long start_time;  // time in milliseconds at start of sample window (since program started)

const int lowAmplitudeThreshold = 100; 

void setup() {
  // set motor control pins as outputs
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorBackwardPin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorBackwardPin, OUTPUT);
  //pinMode(leftMotorSpeedPin, OUTPUT);
  //pinMode(rightMotorSpeedPin, OUTPUT);

   // Configure LED and buzzer as OUTPUT
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);


  Serial.begin(115200);  // initialize serial communication for debugging
}

// Motor control functions
void driveForward() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void driveBackward() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
}

void turnRight() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
}

void turnLeft() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void stopDriving() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void loop() {
  // Stop driving to avoid motor noise interference
  stopDriving();
  delay(500);

  // Reset max and min values
  mic1_min = 1023;
  mic1_max = 0;
  mic2_min = 1023;
  mic2_max = 0;

  // Sample the microphones for sample_window milliseconds
  start_time = millis();
  while (millis() - start_time < sample_window) {
    mic1 = analogRead(mic1pin);
    mic2 = analogRead(mic2pin);

    mic1_min = min(mic1, mic1_min);
    mic1_max = max(mic1, mic1_max);
    mic2_min = min(mic2, mic2_min);
    mic2_max = max(mic2, mic2_max);
  }

  // Calculate amplitudes
  amp1 = mic1_max - mic1_min;
  amp2 = mic2_max - mic2_min;
  difference = amp1 - amp2;

  // Print data to the serial monitor
  Serial.print("Mic 1 amplitude: ");
  Serial.print(amp1);
  Serial.print(" | Mic 2 amplitude: ");
  Serial.print(amp2);
  Serial.print(" | Difference = ");
  Serial.println(difference);

 // Check if sound levels are low
  const int soundThreshold = 50; 
  if (amp1 < soundThreshold && amp2 < soundThreshold) {
    Serial.println("No significant sound detected. Staying still.");
    stopDriving();
    digitalWrite(buzzerPin, LOW); //  buzzer is off
    digitalWrite(ledPin, LOW);    // LED is off
    return; // Exit loop early
  }
else 
{  // Turn on the LED and buzzer when sound is detected
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(200); // Flash the LED and buzzer briefly
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

if (amp1 < lowAmplitudeThreshold && amp2 < lowAmplitudeThreshold) {
    // when sound is weak->robot will drive forward
    Serial.println("Sound is weak - Driving forward");
    driveForward();
    delay(200);
  }

else 
 {
  if (difference > soundThreshold) { // Sound is stronger on mic1
  Serial.println("Turning left...");
    turnLeft();
    delay(500);  // Adjust duration for sharper turns if needed
   
  } else if (difference < -soundThreshold) { // Sound is stronger on mic2
  Serial.println("Turning right...");
    turnRight();
    delay(500);
  
   } else { // Sound is roughly equal
    driveForward();
    delay(500);
  }
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
    }
 } //delay(100); // Pause for stability
}