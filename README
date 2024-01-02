**WhiTeCaT App Project Readme**

### Part 1: My App

**WhiTeCaT App Overview**

WhiTeCaT is a mobile application designed for controlling an ESP32-based motor controller wirelessly over Bluetooth or Wifi. Here we provide instructions on how to use the app, specifically focusing on the "Joystick" feature within the tab bar.

**Operation Modes:**
- The app supports two different operation modes: "vmode" and "srmode."
  - **vmode:** This command is sent when you long click in voice icon then send string 
  - **srmode:** Esp32 send data to App when you click on plug icon.
  - When both of 2 mode are not available, bluetooth control by joystick will be worked.

**Joystick BLuetooth Feature**

The "Joystick" feature with bluetooth is one of the features of the app. It allows users to control the ESP32 motor controller using a virtual joystick on the app. Here are the steps to use this feature:
1. **Enable Bluetooth Connection:**
   - Ensure Bluetooth on your mobile device is enabled.
   - Navigate to the "Joystick" tab in the app.

2. **Establish Bluetooth Connection:**
   - Press the Bluetooth icon/button on the app to initiate the Bluetooth connection to the ESP32 device.

3. **Control the Motors:**
   - Use the virtual joystick to control the motors.
   - The joystick sends data in the format ``angle:signal`` to the ESP32 device:
     - **angle:** Represents the angle of the joystick, controlling the direction of movement.
     - **signal:** Represents a signal or action triggered by a button press.

### Part 2: Code Operation Overview

**Bluetooth Connection and Processing:**
- The ESP32 device waits for incoming Bluetooth data from the app.
- Data received is processed in the `bluProcessor` function.

**Motor Control:**
- Motor control functions include `stop`, `forward`, `backward`, `turnLeft`, and `turnRight`.
- Motors are controlled based on the angle and signal received from the app.

**Example Usage:**
- The app sends data in the format "angle:signal" based on joystick movements.
- The ESP32 code interprets the data and performs corresponding motor control actions.

**Getting Started:**
1. Upload the ESP32-NVD code to your ESP32 board using the Arduino IDE.
2. Open the WhiTeCaT app, navigate to the "Joystick" tab, and establish a Bluetooth connection.
3. Use the virtual joystick to control the motors wirelessly.

Feel free to modify the code and app to meet your specific requirements. Enjoy exploring the capabilities of your Bluetooth-controlled motor setup with WhiTeCaT!
