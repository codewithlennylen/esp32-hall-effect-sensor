# esp32-hall-effect-sensor

### Description

A Hall effect sensor is a transducer that varies its output voltage in response to a magnetic field. These sensors are used for proximity switching, positioning, speed detection, and current sensing applications. In its simplest form, the sensor operates as an analog transducer, directly returning a voltage. With a known magnetic field, its distance from the Hall plate can be determined. Using groups of sensors, the relative position of the magnet can be deduced.

**Internal ESP32 Hall Effect Sensor:**
The ESP32 features a built-in Hall effect sensor located behind the metal lid of the SoC. It works by detecting the voltage changes caused by the magnetic field on the internal sensing element.
- **Functionality:** In the Arduino framework, the sensor is read using the `hallRead()` function.
- **Output:** It returns an integer value. The value increases or decreases depending on the polarity and strength of the magnetic field brought near the chip.
- **Sensitivity:** While convenient, the internal sensor is relatively low-sensitivity and can be affected by the chip's own internal magnetic noise and temperature.

This project demonstrates using both this internal sensor and an external A3144 Hall effect sensor (a digital switch) to detect the presence of a magnet.

### A3144 Pinout

<img width="738" height="600" alt="image" src="https://github.com/user-attachments/assets/1b81f669-2846-4984-aa5a-bfb732a721da" />


### References

- [A3144 Pinout](https://www.circuits-diy.com/a3144-magnetic-hall-effect-sensor/)
- [ESP32 pins that support PULLUP](https://forum.arduino.cc/t/esp32-pins-that-support-pullup/1173356)
- [ESP32 Devkit Pins](https://europe1.discourse-cdn.com/arduino/original/4X/4/c/f/4cf2243ab5d5d7122f66f4e795172780b9d921a1.jpeg)
- [ESP32 Basics: Hall Effect Sensor](https://lastminuteengineers.com/esp32-hall-effect-sensor-tutorial/)
