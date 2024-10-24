# Car Locking System Project

This project simulates a car locking system using an Arduino (or ESP8266), RF modules, buttons, and an OLED display. Users can lock, unlock, and reset the car's locking system through remote control with visual feedback provided on an OLED screen.

## Features

- **Lock and Unlock**: Lock and unlock the car using RF signals.
- **Status Display**: Show the lock/unlock status on an OLED screen.
- **Visual Feedback**: LED indicators provide feedback on actions taken.
- **Reset Functionality**: Reset the system to its initial state.

## Components Required

1. **Microcontroller**: Arduino Uno or ESP8266
2. **RF Modules**: RF transmitter and receiver
3. **OLED Display**: 128x64 SSD1306 OLED display
4. **Push Buttons**: For lock, unlock, and reset functions
5. **LED**: For visual feedback (optional)
6. **Jumper Wires**: For connections
7. **Breadboard**: For prototyping (optional)

## Wiring Instructions

Connect the components as follows:

- **Lock Button**: Connect to GPIO12 (D6)
- **Unlock Button**: Connect to GPIO5 (D1)
- **Reset Button**: Connect to GPIO14 (D5)
- **RF Receiver**: 
  - DATA pin to GPIO12 (D6)
  - VCC to 3.3V
  - GND to GND
- **RF Transmitter**: 
  - DATA pin to GPIO13 (D7)
  - VCC to 3.3V
  - GND to GND
- **OLED Display**:
  - SDA to GPIO4 (D2)
  - SCL to GPIO5 (D1)

## Software Requirements

1. **Arduino IDE**: Download and install the latest version from the [Arduino website](https://www.arduino.cc/en/software).
2. **Libraries**: Install the following libraries in your Arduino IDE:
   - **RCSwitch**: For RF communication. [RCSwitch GitHub](https://github.com/sui77/rc-switch)
   - **Adafruit SSD1306**: For OLED display control. [Adafruit SSD1306 GitHub](https://github.com/adafruit/Adafruit_SSD1306)
   - **Adafruit GFX**: Required by the SSD1306 library. [Adafruit GFX GitHub](https://github.com/adafruit/Adafruit-GFX-Library)

### Installing Libraries

1. Open the Arduino IDE.
2. Go to **Sketch** > **Include Library** > **Manage Libraries**.
3. In the Library Manager, search for each library and click **Install**.

## Code Upload Instructions

1. Open the Arduino IDE.
2. Copy the code provided in this repository into a new sketch.
3. Connect your Arduino board to your computer via USB.
4. Select the appropriate board type and port in the Arduino IDE:
   - Go to **Tools** > **Board** and select your board.
   - Go to **Tools** > **Port** and select the port your board is connected to.
5. Click on the **Upload** button to upload the code to your Arduino.

## How to Use the Car Locking System

1. **Power On**: Connect your Arduino to a power source. The system will initialize, and the OLED display will show instructions.
2. **Using Buttons**:
   - **Lock Button**: Press the lock button to lock the car. The OLED display will show "Car Locked."
   - **Unlock Button**: Press the unlock button to unlock the car. The OLED display will show "Car Unlocked."
   - **Reset Button**: Press the reset button to reset the system. The OLED display will show "System Reset."
3. **Monitor Status**: The OLED display will guide you through the available options and current status. When no button is pressed, it will display:

Press your choice:
1.Lock
2.Unlock
3.Reset

## Troubleshooting

- **Buttons Not Responding**: Check the wiring and ensure the buttons are correctly connected and functioning.
- **Display Issues**: Verify that the OLED display is wired correctly and powered. Check the I2C address if necessary.
- **RF Communication Failures**: Ensure the transmitter and receiver are properly connected and within range. 

## Contributing

Contributions are welcome! If you would like to contribute to this project, please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- **Arduino**: For providing a platform for building hardware projects.
- **Adafruit**: For their libraries and components.

## Author

- **usal winodith**- [winodith](https://github.com/winodith)
