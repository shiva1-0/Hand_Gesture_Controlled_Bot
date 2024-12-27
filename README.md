# Hand_Gesture_Controlled_Bot

A Hand Gesture Controlled Robot uses advanced motion-sensing technology to interpret hand gestures and translate them into movement commands for the robot. By utilizing sensors like accelerometers, this system provides an intuitive and contactless way to control a robot's movement.

## Overview
This project focuses on creating a robot that responds to hand gestures detected by an accelerometer. The gesture data is processed and sent wirelessly to the robot using nRF24 modules. The robot's microcontroller decodes the received signals and moves accordingly, enabling seamless interaction without physical controllers.

## Key Features
- Gesture-Based Control: Uses hand movements to direct the robot.
- Wireless Communication: Transfers data between the gesture controller and the robot.
- Compact Design: Powered by Arduino Nano and lightweight components.
- Scalable: Can be adapted for various robotic applications.

## Hardware Requirements
- Arduino Nano
- nRF24 Wireless Module
- ADXL345 Accelerometer
- Motor Driver Module
- DC Motors
- Power Supply

## Software Requirements
- Arduino IDE

## Working Principle
- **Gesture Recognition**: The accelerometer detects changes in hand orientation and motion along the X, Y, and Z axes.
These readings represent specific gestures, such as moving forward, backward, or turning.
- **Data Transmission**:The transmitter unit sends the processed gesture data wirelessly to the robot using the nRF24 module.
- **Signal Interpretation**:The robot’s microcontroller interprets the received data and converts it into movement commands.
- **Bot Movement**:The robot executes actions like moving forward, backward, left, or right based on the commands.

## Connections
![Screenshot 2024-12-27 123212](https://github.com/user-attachments/assets/32f8f794-6059-4455-b81f-9208d83bb1ae)
![Screenshot 2024-12-27 121708](https://github.com/user-attachments/assets/79640989-64bb-41ad-81e6-c7b04dd55263)
![Screenshot 2024-12-27 121733](https://github.com/user-attachments/assets/e0170c1a-7e43-4c7f-88e4-f9d84c700bd3)

