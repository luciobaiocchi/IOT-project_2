# Smart Waste Management System

This project is an Arduino-based smart waste management system. It monitors various parameters such as waste level, temperature, and user presence, while also managing an automatic gate and communication with a graphical user interface (GUI).

## Main Components

### Implemented Tasks

- **AllarmTask**: Measures the system temperature and triggers an alarm if it exceeds a predefined threshold.
- **WasteLevelTask**: Measures the waste level and notifies the `GateTask` to close the gate if the container is full.
- **LedTask**: Manages the turning on and off of LEDs based on the system state (alarm, normal operation).
- **ProxTask**: Detects user presence in front of the sensor and manages a timer to put Arduino into sleep mode.
- **GateTask**: Controls the opening and closing of the gate based on the system state and alarm conditions.
- **SerialCommTask**: Handles serial communication with the GUI, sending data and receiving commands.

### Project Structure

- **ContainerProp**: A shared object among tasks that contains all system state information (e.g., active alarm, container full).
- **LCDManager**: A wrapper for the LCD display that prevents flickering by storing the currently displayed message.
- **Gate**: A separate class to manage the servo motor controlling the gate.
- **TickCounter**: A class that simulates a timer, useful for managing delays and timing.

## Features

- **Temperature Monitoring**: Uses an LM35 sensor to measure temperature and triggers an alarm if it exceeds a threshold.
- **Waste Level Management**: Measures the waste level and automatically closes the gate if the container is full.
- **GUI Communication**: Sends data to the GUI and receives commands to restore the system or empty the container.
- **Sleep Mode**: If no presence is detected for a certain period, the system enters sleep mode to save energy.

## Pin Configuration

- **LM35**: Connected to pin A1 for temperature measurement.
- **LEDs**: 
  - L1 connected to pin 3.
  - L2 connected to pin 4.
- **Proximity Sensor**: Connected to a digital pin to detect user presence.
- **Servo Motor**: Connected to a PWM pin to control the gate.

## System Requirements

- **Arduino**: The system is developed to run on an Arduino board.
- **Libraries**: 
  - `MSTimer2` for scheduler management.
  - `Servo` for motor control.
  - `LiquidCrystal` for LCD display management.

## Installation

1. Clone the repository or download the source code.
2. Open the project in the Arduino IDE.
3. Connect the Arduino board to your computer.
4. Upload the code to the board.

## Usage

- Power on the system and wait for the sensors to calibrate.
- The system will start monitoring temperature, waste level, and user presence.
- Use the GUI to monitor the system status and send commands.

## Authors

- Lucio Baiocchi
- Luca Camillini

## License

This project is released under the MIT License. See the `LICENSE` file for more details.

## Link to video demo https://youtu.be/G0cvC06uNy4
