# Smart AI Lantern

A hardware-based smart lighting project that combines voice control, motion sensing, ambient light detection, and adaptive brightness control to create a more convenient and energy-efficient home lighting system.

## Overview

Smart AI Lantern was developed as a Final Year Project for the BS Information Technology program at Rawalpindi Women University. The project focuses on improving traditional smart lighting systems by making them easier to use, more responsive, and more energy-aware.

The lantern can respond to user commands, detect human presence, adjust brightness according to the surrounding light, and control RGB lighting output. The main goal is to provide a user-friendly smart home lighting solution that improves comfort while reducing unnecessary energy use.

## Problem Statement

Many smart lighting systems are difficult to use, expensive, or poorly integrated with user needs. Some systems require manual control, while others do not adapt well to the environment or user presence.

This project addresses these issues by building a smart lantern that can:

- Detect motion through a PIR sensor
- Sense ambient light through an LDR sensor
- Adjust brightness automatically
- Provide RGB color control
- Support simple and convenient user interaction
- Reduce energy waste when no user is present

## Key Features

- **Voice-based control** for easier interaction with the lamp
- **PIR motion detection** to identify user presence
- **LDR-based light sensing** to detect surrounding brightness
- **Adaptive brightness control** for energy-efficient lighting
- **RGB lighting support** for different color modes
- **Relay-based switching** for controlling lighting hardware
- **Arduino-based embedded control** for sensor processing and actuator control

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller for processing sensor input and controlling output |
| PIR Motion Sensor HC-SR501 | Detects human movement or presence |
| LDR Sensor | Measures ambient light intensity |
| RGB Bulb / RGB LEDs | Provides colored lighting output |
| Relay Module | Controls switching of higher-power lighting components |
| Resistors and jumper wires | Circuit support and connections |
| Power supply | Provides required voltage to the system |

## Software and Tools

- Arduino IDE
- Embedded C / Arduino programming
- Sensor-based decision logic
- RGB LED control using PWM
- Motion detection algorithm
- Light intensity control algorithm

## System Workflow

```text
PIR Motion Sensor
        |
        v
Arduino Microcontroller ----> Relay / RGB Light Output
        ^
        |
LDR Light Sensor
```

The system reads input from the PIR motion sensor and LDR sensor. If motion is detected, the lantern turns on and adjusts brightness based on the surrounding light. RGB control allows the lamp to display different colors based on user settings or programmed behavior.

## Basic Algorithm

1. Initialize the Arduino pins for PIR sensor, LDR sensor, relay, and RGB LEDs.
2. Read motion data from the PIR sensor.
3. Read ambient light level from the LDR sensor.
4. If motion is detected, turn on the light.
5. Adjust brightness according to the detected light level.
6. If no motion is detected, turn off or reduce brightness to save energy.
7. Repeat the process continuously.

## Example Arduino Logic

```cpp
const int pirPin = 2;
const int relayPin = 7;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(relayPin, HIGH);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
```

## Testing

The project was tested in different situations to check:

- PIR motion detection accuracy
- LDR response to different light levels
- RGB light output
- Relay switching behavior
- System response time
- Integrated hardware and software performance

The testing showed that the lantern could detect motion, control lighting output, and support automatic lighting behavior using sensor input.

## Benefits

- Improves user comfort through automatic lighting control
- Saves energy by reducing unnecessary light usage
- Supports smart home automation concepts
- Helps users with limited mobility through easier interaction
- Encourages practical use of AI and IoT in daily life

## Limitations

- Voice recognition and AI features are basic and can be improved
- Sensor accuracy may vary based on environment and placement
- The prototype is designed for small-scale demonstration
- More advanced mobile or web-based control can be added in future
- Real-time energy consumption measurement was limited

## Future Improvements

- Add mobile app control
- Improve voice recognition accuracy
- Add Wi-Fi or Bluetooth connectivity
- Add real-time energy monitoring
- Use machine learning for smarter brightness adaptation
- Improve enclosure and hardware design for real-world use
- Add cloud-based logging and remote control

## Project Context

This project was developed as a Final Year Project under the Department of Information Technology, Faculty of Sciences, Rawalpindi Women University.

**Project Title:** Smart AI Lantern  
**Student:** Aena Azhar  
**Supervisor:** Sidra Khudadad  
**Degree:** BS Information Technology  
**Session:** 2020-2024

## Conclusion

Smart AI Lantern demonstrates how embedded systems, sensors, and intelligent control logic can be combined to build a useful smart home device. The project shows the practical application of AI, IoT, and automation concepts in everyday lighting systems, with a focus on comfort, accessibility, and energy efficiency.
