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
The system involves the integration of directional microphones, a microcontroller for data processing and motors that allow the robot to move.
Its operation is based on capturing sound waves, processing data and generating movement commands.

# Main components:

### Sound Sensors (Microphones): 
The robot is equipped with several strategically placed microphones to detect sound from different directions. Differences in sound intensity and time of arrival between microphones allow the source to be located.

### Processing unit (microcontroller): 

The data captured by the microphones is sent to the microcontroller, which analyzes the differences and determines the direction of the sound source using algorithms for localization and background noise filtering.

### Drive system (motors and wheels): 

After calculating the direction, the microcontroller sends commands to the motors, adjusting the speed and direction to point the robot towards the sound source.

### Power: 

The robot is powered by a rechargeable battery, ensuring continuous operation of the electronics and motors.

### Body and structure: 

The physical design of the robot includes a robust platform that houses all components and enables stable movement on different types of terrain.


# Mode of operation:

### Detection:

Microphones pick up surrounding sounds and measure differences in intensity and timing.

### Processing: 

The data is analyzed to determine the precise direction of the sound source.

### Decision: 

The microcontroller compares the received information and decides the optimal direction of travel.

### Movement: 

The robot moves in the direction of the sound source and continuously adjusts its trajectory as it detects new sounds.

##
</details>


<details>
  <summary> <h2> Hardware Design </h2> </summary>

  ##
  
   ### 1. List of components: 
|Item name| Picture|Description|
|---------|--------|-----------|
|Battery pack|![4xAA-battery-holder-picture](https://github.com/user-attachments/assets/30297ea7-6351-4d28-ad69-7d370d34a528) |This is the power supply for your robot. Battery packs come in all shapes and sizes. The one in this project holds 4 AA batteries.|
|Breadboard|![breadboard-picture](https://github.com/user-attachments/assets/db718aed-d2c8-4224-a35a-be6ce7b3111b)|A breadboard allows you to quickly and easily connect wires and electronic components in order to build a circuit. The connections are not permanent, so you can easily move things around if you make a mistake.|
|Switch|![spdt-switch-new](https://github.com/user-attachments/assets/5c182494-4efd-4488-915c-dff82771da9a)|You use switches every day to turn lights and appliances on and off. This is a tiny switch that fits on a breadboard, to let you turn your robot on and off.|
|Jumper wire|![jumper-wires](https://github.com/user-attachments/assets/499a5e40-635e-4991-b5c2-82ebd709cc24)|Jumper wires are short wires used to make electrical connections on a breadboard. They come with many colors of plastic insulation, which makes it easy to color-code and organize complicated circuits.|
|DC Motor|![DC-motor-picture](https://github.com/user-attachments/assets/444cc959-be85-4a92-bc9b-3f380f9bce9e)|Electrical current causes a motor to spin. Two motors drive the robot's wheels. This type of motor runs on direct current (DC) from a battery (as opposed to alternating current [AC] from a wall outlet).|
|MOSFET|![MOSFET-picture](https://github.com/user-attachments/assets/9407b928-2af2-46fc-aa5b-300aac90c4fb)|A MOSFET is a special type of transistor, which acts like a control valve to let electrical current flow. As an analogy, think of how a valve can control the flow of water through a garden hose. In this circuit, the MOSFETs control the flow of current through the motors.|
|Diode|![diode-picture](https://github.com/user-attachments/assets/5a18096b-90cf-4a2c-a84f-869f93813ac5)|A diode is like a one-way valve for electricity. It only lets current flow in one direction. In this circuit, diodes are used to protect the MOSFETs from voltage spikes that can be caused by abruptly stopping the motors.|
|Male-female jumper wire|![M-F-jumper-wires](https://github.com/user-attachments/assets/e3fa5ca9-0f19-40f8-a1b0-d3d1bdf29166)|This is a special type of jumper wire that comes with a female connector on one end and a male connector on the other end.|

#  Breadboard diagram for the circuit. 
![sound-tracking-robot-breadboard-diagram](https://github.com/user-attachments/assets/7803d519-aa83-4715-9cf2-e90fa84492b4)

#  Schematic for the circuit.
![sound-tracking-robot-circuit-diagram](https://github.com/user-attachments/assets/2ca5329b-7363-4ac1-a745-67125943f7f2)

##
</details>

<details>
  <summary> <h2> Software Design </h2> </summary>

  ##
  ### Development enviroment:
  
  I will use the PlatformIO IDE extension within Visual Studio Code.
  
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
