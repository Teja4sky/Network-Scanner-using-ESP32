# ESP32 Network Scanner with Up and Down Buttons
This project is a simple network scanner built using the ESP32. It allows you to scan available Wi-Fi networks and display the results. The up and down buttons enable navigation through the scanned network list.

# Features
Scans available Wi-Fi networks.
Displays the list of networks on an attached screen (e.g., OLED).
Navigation through the list using up and down buttons.
Displays basic information about each network, such as SSID and signal strength.
# Hardware Requirements
ESP32 Development Board
OLED or similar screen (0.96-inch or larger recommended)
2 Push Buttons (Up and Down for navigation)
Jumper wires for connections
# Wiring Diagram
Connect the Up Button to a digital pin (e.g., GPIO 12).
Connect the Down Button to another digital pin (e.g., GPIO 14).
Connect the OLED Screen (e.g., SSD1306) using I2C (SDA to GPIO 21, SCL to GPIO 22).
Ensure the ESP32 board is powered correctly.
# Software Requirements
Arduino IDE or PlatformIO
ESP32 board support in the Arduino IDE
Libraries: Wire.h, Adafruit_GFX.h, Adafruit_SSD1306.h (or other libraries depending on your display)
Setup Instructions
# Install Libraries:
Open the Arduino IDE.
Go to Sketch > Include Library > Manage Libraries.
Install the following libraries:
Adafruit GFX
Adafruit SSD1306
WiFi (for Wi-Fi scanning)


-> Connect your ESP32 board to the computer.
  Select the correct board and port under Tools > Board.
  Upload the code to the ESP32.
  
 # Test the Setup:

Once uploaded, the ESP32 will scan available networks and display them on the OLED screen.
Use the up and down buttons to scroll through the available networks.
# Usage
Power up the ESP32 and open the Serial Monitor to see debug information.
Press the Up or Down buttons to scroll through the scanned networks.
The SSID and signal strength of each network will be shown on the OLED display.
# Troubleshooting
OLED not displaying anything: Make sure the wiring is correct and the appropriate library is installed.
Wi-Fi scan issues: Ensure the ESP32 is not connected to any Wi-Fi network during scanning
