# Hydrosmart: Wireless Smart Water Level Indicator

## Overview
Hydrosmart is an advanced water level monitoring system that leverages wireless communication, a touchscreen interface, and real-time data visualization to control and monitor water levels efficiently. The system consists of a transmitter and receiver module that interact seamlessly to automate water level management and motor control.

---

## Components Used
| **Component**                       | **Description**                                                         |
|-------------------------------------|-------------------------------------------------------------------------|
| **Arduino Mega 2560**              | Microcontroller board for both transmitter and receiver.               |
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

---

## System Setup
### Hardware Connections
| **Module**                   | **Connection Details**                                                                 |
|-------------------------------|---------------------------------------------------------------------------------------|
| **nRF24L01 PA LNA**          | Connected via SPI pins to Arduino Mega (MISO, MOSI, SCK, CE, CSN).                    |
| **ULN2003 IC**               | Connected to sensors for water level input.                                           |
| **TFT Touch Screen Shield**  | Mounted directly onto Arduino Mega for display and touch inputs.                      |
| **Relay Module**             | Connected to motor control pins on the Arduino Mega.                                   |

### Power Supply
- **Transmitter:** Powered by the Arduino Mega's onboard power.
- **Receiver:** Powered by the Arduino Mega and TFT display's onboard power.

---

## Installation
1. **Libraries:** Install the required libraries listed above in your Arduino IDE.
2. **Transmitter Code:** Upload the transmitter code to the Arduino Mega connected to the nRF24L01 module and sensors.
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

## Future Enhancements
- Integration of IoT for remote monitoring and control.
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
