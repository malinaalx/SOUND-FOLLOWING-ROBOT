
# SOUND-FOLLOWING-ROBOT

<details>
  <summary> <h2>  Introduction </h2> </summary>
    
  ##
  The development of robotic technology has opened new horizons in the field of automation and human-machine interaction.
  An innovative example of the application of these technologies is the sound following robot.
  This type of robot has the ability to detect and move in the direction of a sound source, which makes it useful in various applications such as search and rescue, assisting the disabled, and home automation.
  The present project aims to design and build a robot capable of following a sound source using specialized sensors and signal processing algorithms.
  
##
</details>


<details>
  <summary> <h2> General Description </h2> </summary>

  ##
The system involves the integration of directional microphones, an arduino uno for data processing and motors that allow the robot to move.
Its operation is based on capturing sound waves, processing data and generating movement commands.

# Main components:

### Sound Sensors (Microphones): 
The robot is equipped with multiple sound sensors placed around its structure to detect sound from various directions. The microphones capture sound intensities and changes in timing, allowing the robot to identify the source of the sound.

### Control System (Arduino): 
The data collected by the microphones is sent to the Arduino board. It processes the sound data to detect patterns and determine the direction of the sound source. The Arduino then sends commands to control the motors based on this information

### Drive system (motors and wheels): 
The motors and wheels are powered by the Arduino's commands. Once the direction of the sound is determined, the Arduino adjusts the motor speeds and direction to move the robot toward the sound source

### Power Supply: 
The robot is powered by a set of rechargeable batteries, providing the necessary energy to run the electronics, motors, and sensors. The power system ensures the robot can operate continuously.

### Physical Structure:
The robot’s body is designed to house all the components securely, providing stability and mobility. The frame is constructed to support the motors, sensors, and power supply, ensuring smooth movement on various surfaces.


# Mode of operation:

### Sound Detection:
The microphones continuously detect sounds in the environment. They measure differences in sound intensity and the time it takes for the sound to reach each microphone, allowing the robot to "hear" from different directions.

### Data Processing: 
The Arduino processes the data received from the microphones, analyzing the differences in sound signals to determine the direction of the sound source.

### Decision: 
The Arduino compares the sound data to decide the most appropriate direction for the robot to move. It makes real-time decisions based on the varying levels of sound detected from each microphone

### Movement: 
After determining the direction, the robot moves towards the sound source by adjusting the speed and direction of its motors. It continuously re-evaluates its position and makes adjustments as new sounds are detected.

##
</details>


<details>
  <summary> <h2> Hardware Design </h2> </summary>

  ##
  
   ### 1.BOM (BILL OF MATERIALS) : 
|Item name|Role       |Source/Link|Datasheet|
|---------|-----------|-----------|---------|
|Arduino Uno| It processes signals from the sound sensors (microphones), and based on the detected sound intensity, it controls the motors|Kit|[Datasheet](https://store.arduino.cc/uno-rev3)|
|L298N Motor Driver|The motor driver used to control the direction and speed of the DC motors. It takes control signals from the Arduino and drives the motors accordingly|[L298N-motor driver](https://roboromania.ro/produs/l298n/)|[Datasheet](https://www.sparkfun.com/datasheets/Robotics/L298_H_Bridge.pdf)|
|Microphones|Detect surrounding sounds|[Module-MAX4466](https://roboromania.ro/produs/modulul-senzor-sunet-microfon-max4466/)|[Datasheet](https://www.analog.com/en/products/max4466.html)|
|DC Motors|The motors drive the wheels, allowing the robot to move based on the commands from the Arduino|[DC Motor](https://roboromania.ro/produs/motor-5v-reductor-si-roata-robot/)|[Datasheet](https://www.raveo.cz/sites/default/files/dkm/katalogy/motory/DC%20MOTOR%20(15W~120W).pdf)|
|Batteries and Battery Holder|Powers the Arduino, motor driver, motors, and sensors|[AA Battery](https://www.sigmanortec.ro/Suport-Baterii-4AA-cu-Mufa-p148578749)|[Datasheet](https://www.mega-piles.com/im/VARTA-LR6-AA-1-5V-2750mAh-LONGLIFE-X8_722.pdf?srsltid=AfmBOoqPS6lykKANIgqjYkxszVXxVRQaqtvm_0OUlorjIxDFhsr4SlyJ)|
|Resistor|Protect components by limiting the current, used for LED protection.|Kit|[Datasheet](https://eu.mouser.com/c/ds/passive-components/resistors/?resistance=220%20Ohms&srsltid=AfmBOoqYW_AjQohdrFB_rjpYFgMYbT1hn3V4-_5wQEuize5b8UXz_e9j)|
|LED|LED used to indicate when the robot is moving|Kit|[Datasheet](https://www.mouser.com/datasheet/2/737/all-about-leds-932801.pdf?srsltid=AfmBOoo1mQnj_BAGlAsPsRZ1Onf-Gy5X-qO5hG1uBb6l8t24gUo3xy0j)|
|Buzzer| A buzzer is used to provide an audible indication when the robot moves, giving a sound feedback to the user.|Kit|[Datasheet](https://www.farnell.com/datasheets/2171929.pdf)|
|Breadboard|Used for prototyping and connecting components without the need for soldering. It allows for easy setup of the circuit.|Kit|[Datasheet](https://components101.com/sites/default/files/component_datasheet/Breadboard%20Datasheet.pdf)|
|Jumper Wires|Used to connect different components on the breadboard or to the Arduino|Kit|-|

#  Schematic for the circuit.
<a>
  <img src="https://github.com/malinaalx/SOUND-FOLLOWING-ROBOT/blob/main/images/block_diagram.png" width="800"/>
</a>

### Explanation:
### Microphones: 
  The sound sensors send signals to the Arduino UNO.

### Arduino UNO: 
Receives the signal from the microphones and controls other components.
Sends a signal to the L293D Module (motor control).
Sends a signal to the LED (it lights up when the robot moves).
Sends a signal to the Buzzer (emits sound).

### L298N Module: 
Controls the motors (through pins IN1, IN2, IN3, IN4 connected to the Arduino).

### Motors: 
Rotate to move the robot.

### LED: 
Receives a signal from the Arduino and lights up when the motors are running.

### Buzzer: 
Receives a signal from the Arduino and emits a sound when the robot moves.
                            
#  Breadboard diagram for the circuit. 
![schema_fritzing](https://github.com/user-attachments/assets/a1bbf549-da6e-4a85-9231-9df124d3dee0)

# General Circuit Design Overview:

| **Component**        | **Pins Used**              |                                   
|----------------------|----------------------------|
| Microphone           |   -VCC to 5V on Arduino    |
|                       |   -GND to GND on Arduino  | 
|                        |   -Signal output (DO) to a digital pin (AO-for Left Microphone, A1-for Right Microphone)| 
|L298N Motor Driver    | -IN1 and IN2 connected to pins 5 and 6 on Arduino (for Right Motor); |
|                      |   -IN3 and IN4 connected to pins 8 and 9 on Arduino (for Left Motor); | 
|                      |  -VCC and GND to power supply and ground;                             |
| Motors               | connected to OUT1 and OUT2 (Left Motor), OUT3 and OUT4 (Right Motor) ;         |
| LED                  | -Anode connected to pin 13 on Arduino;                  |
|                      |  -Cathode connected to GND via a 220Ω resistor;         | 
|Buzzer                | -One terminal connected to pin 7 on Arduino;           | 
|                      |  -The other terminal connected to GND on Arduino;       |


![WhatsApp Image 2024-12-17 at 21 22 15_cb7b2326](https://github.com/user-attachments/assets/9ba8fc2f-772e-4342-83a0-4c853fc0119d)
![WhatsApp Image 2024-12-17 at 21 22 15_ea829af7](https://github.com/user-attachments/assets/e35ca94b-a507-41a7-bcc4-fe31ce7dddba)
![WhatsApp Image 2024-12-17 at 21 22 15_56a94b0f](https://github.com/user-attachments/assets/2dcb6de9-c45b-40d9-87e0-9d1158a0c26c)


##
</details>

<details>
  <summary> <h2> Software Design </h2> </summary>

  ##
  ### Development enviroment:
  
  I used  the PlatformIO IDE extension within Visual Studio Code.
  
##
</details>

<details>
  <summary> <h2> Results </h2> </summary>

  ##
   TBD
  
##
</details>

<details>
  <summary> <h2> Conclusions </h2> </summary>

  ##
   TBD
  
##
</details>

<details>
  <summary> <h2> Resources </h2> </summary>
  
  ##
  
##
</details>
