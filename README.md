# Hydrosmart: Wireless Smart Water Level Indicator

## Overview
Hydrosmart is an advanced water level monitoring system that leverages wireless communication, a touchscreen interface, and real-time data visualization to control and monitor water levels efficiently. The system consists of a transmitter and receiver module that interact seamlessly to automate water level management and motor control. Additionally, the system includes an ESP32 for WiFi connectivity, allowing remote control via a mobile app.

---

## Components Used
| **Component**                       | **Description**                                                         |
|-------------------------------------|-------------------------------------------------------------------------|
| **Arduino Nano**                   | Microcontroller board for the transmitter.                              |
| **Arduino Mega 2560**              | Microcontroller board for the receiver.                                |
| **ESP32**                          | WiFi-enabled microcontroller for remote control via mobile app.        |
| **nRF24L01 PA LNA Module**         | Long-range RF communication module for wireless data transfer.          |
| **2.4” TFT Touch Screen Shield**   | Touch-enabled LCD display for user interface and visualization.         |
| **ULN2003 IC**                     | Used for sensing water levels through analog inputs.                    |
| **Relay Module**                   | Controls the motor based on the received water level data.              |

---

## Libraries Used
### Transmitter
| **Library**    | **Purpose**                                     |
|----------------|-------------------------------------------------|
| `SPI.h`        | Enables SPI communication for RF module.       |
| `RF24.h`       | Handles RF communication with nRF24L01 module. |
| `nRF24L01.h`   | Driver for nRF24L01 wireless module.           |

### Receiver
| **Library**          | **Purpose**                                                |
|----------------------|------------------------------------------------------------|
| `Adafruit_GFX.h`     | Provides graphics functions for TFT displays.              |
| `Adafruit_TFTLCD.h`  | Hardware-specific library for the TFT LCD.                 |
| `TouchScreen.h`      | Handles touchscreen input from the display.                |
| `SPI.h`              | Enables SPI communication for RF module.                  |
| `RF24.h`             | Handles RF communication with nRF24L01 module.            |
| `nRF24L01.h`         | Driver for nRF24L01 wireless module.                       |

### ESP32
| **Library**    | **Purpose**                                     |
|----------------|-------------------------------------------------|
| `WiFi.h`       | Enables WiFi functionality for ESP32.          |

---

## Key Features

### Transmitter
- **RF Communication:** Utilizes nRF24L01 for wireless data transmission to the receiver.
- **Water Level Sensing:** Employs ULN2003 IC to read water levels from sensors connected to analog pins.
- **Dry Run Detection:** Identifies and transmits a dry-run condition to prevent motor damage.
- **Compact Design:** Ensures low power consumption and efficient data transmission.

### Receiver
- **Graphical User Interface:** Features an interactive TFT touch screen with dynamic level display.
- **Menu Navigation:** Multiple operational modes, such as Manual, Automatic, and Level Mode.
- **Motor Control:** Automatically controls the motor based on water levels and mode settings.
- **Real-Time Feedback:** Provides graphical updates and alerts for motor status and dry-run conditions.
- **Color-Coded UI:** Uses a custom color scheme for enhanced visualization, configured using [RGB Color Picker](https://rgbcolorpicker.com/565).
- **Bitmap Integration:** Displays icons generated from images converted using [Image2CPP](https://javl.github.io/image2cpp/).

### ESP32
- **WiFi Connectivity:** Connects to the mobile app via WiFi to control the system remotely.
- **Mobile Control:** Allows for motor control (ON/OFF) through a simple web interface served by the ESP32.
- **Sensor Data Monitoring:** Can send sensor data and motor status to the mobile app.

---

## System Setup
### Hardware Connections
| **Module**                   | **Connection Details**                                                                 |
|-------------------------------|---------------------------------------------------------------------------------------|
| **nRF24L01 PA LNA**          | Connected via SPI pins to Arduino Nano (MISO, MOSI, SCK, CE, CSN).                    |
| **ULN2003 IC**               | Connected to sensors for water level input.                                           |
| **TFT Touch Screen Shield**  | Mounted directly onto Arduino Mega for display and touch inputs.                      |
| **Relay Module**             | Connected to motor control pins on the Arduino Mega.                                   |
| **ESP32**                    | Connected via WiFi to communicate with the mobile app and control the system.         |

### Power Supply
- **Transmitter:** Powered by the Arduino Nano's onboard power.
- **Receiver:** Powered by the Arduino Mega and TFT display's onboard power.
- **ESP32:** Powered by a separate 5V supply or through USB.

---

## Installation
1. **Libraries:** Install the required libraries listed above in your Arduino IDE.
2. **Transmitter Code:** Upload the transmitter code to the Arduino Nano connected to the nRF24L01 module and sensors.
3. **Receiver Code:** Upload the receiver code to the Arduino Mega with the TFT display and nRF24L01 module.
4. **Power On:** Ensure all connections are secure and power both modules.
5. **Calibrate Touch Screen:** (Optional) Perform calibration for precise touch functionality.

---

## Project Features
- **Interactive Display:** Easy-to-use touch interface with menu-driven navigation.
- **Wireless Monitoring:** Reliable long-range communication using nRF24L01 PA LNA modules.
- **Automated Control:** Intelligent motor activation based on water levels and modes.
- **Error Detection:** Alerts for dry-run and other anomalies to ensure system reliability.
- **Customizable UI:** Vibrant and responsive UI with intuitive graphical feedback.

---

## Troubleshooting

### Common Issues and Solutions

- **No Communication Between Transmitter and Receiver:**
  - Ensure the nRF24L01 modules are correctly connected to both the Arduino Nano (transmitter) and Arduino Mega (receiver).
  - Verify the power supply to the nRF24L01 modules. If the modules are not receiving sufficient power, they may not function properly.
  - Check the wiring of the SPI pins (MISO, MOSI, SCK, CE, CSN) for any loose connections or incorrect pin assignments.
  - Ensure the correct addresses are used for communication in the code (both transmitter and receiver should match).

- **Water Level Data Not Displaying Correctly:**
  - Check the ULN2003 IC connections to ensure the water level sensors are providing accurate input to the Arduino Nano.
  - Verify the sensor calibration and check for any dirt or obstructions affecting the sensor's operation.

- **Touchscreen Not Responding:**
  - Recalibrate the touchscreen using the `TouchScreen.h` library if the touch input is inaccurate or unresponsive.
  - Ensure the touchscreen wiring is correct, especially the connections for the `X` and `Y` pins.

- **Motor Not Turning On/Off Correctly:**
  - Verify the relay module is connected to the correct pins on the Arduino Mega.
  - Ensure the motor control logic in the receiver code is correctly processing the water level data and triggering the relay.

---

## Future Enhancements
- Addition of voice command functionality.
- Improved power efficiency for longer operational lifespan.

---

## Acknowledgments
- **Color Configuration Tool:** [RGB Color Picker](https://rgbcolorpicker.com/565)
- **Bitmap Conversion Tool:** [Image2CPP](https://javl.github.io/image2cpp/)
- **Libraries Used:** Special thanks to the authors of the libraries used, including `SPI.h`, `RF24.h`, `nRF24L01.h`, `Adafruit_GFX.h`, `Adafruit_TFTLCD.h`, and `TouchScreen.h`, for providing such useful resources.

---

## Contributors
- **Amith Mathew Titus**
- **Mohamed Afran**

---

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## References
- Arduino: [https://www.arduino.cc](https://www.arduino.cc)
- nRF24L01 Module Documentation: [https://www.nordicsemi.com/Products/Low-power-short-range-wireless/nRF24L01](https://www.nordicsemi.com/Products/Low-power-short-range-wireless/nRF24L01)
- Adafruit Libraries: [https://github.com/adafruit/Adafruit_GFX](https://github.com/adafruit/Adafruit_GFX), [https://github.com/adafruit/TFTLCD-Library](https://github.com/adafruit/TFTLCD-Library)
- ULN2003 IC Datasheet: [https://www.tescaglobal.com/product-detail/ULN2003A](https://www.tescaglobal.com/product-detail/ULN2003A)


---

**Project Status**: Completed ✅
