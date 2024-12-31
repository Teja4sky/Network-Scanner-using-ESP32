#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <WiFi.h>

// OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED SPI Pins
#define OLED_MOSI 23
#define OLED_CLK 18
#define OLED_DC 17
#define OLED_CS 5
#define OLED_RESET 16

// Button Pins
#define BUTTON_UP 25
#define BUTTON_DOWN 26

// Create OLED object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

int networkIndex = 0;  // Index of the current network being displayed
int networkCount = 0;  // Total number of networks found

void setup() {
  Serial.begin(115200);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_RESET)) {
    Serial.println("OLED initialization failed!");
    while (true);
  }
  display.clearDisplay();
  display.display();
  Serial.println("OLED Initialized!");

  // Configure button pins
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);

  // Initialize Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); // Ensure no active connection
  delay(100);

  // Scan for Wi-Fi networks
  scanWiFi();
}

void loop() {
  // Check for button presses
  if (digitalRead(BUTTON_UP) == LOW) {
    scrollUp();
    delay(300); // Debounce delay
  }

  if (digitalRead(BUTTON_DOWN) == LOW) {
    scrollDown();
    delay(300); // Debounce delay
  }
}

// Function to scan Wi-Fi networks
void scanWiFi() {
  displayMessage("Scanning...");
  Serial.println("Scanning for networks...");
  networkCount = WiFi.scanNetworks();
  Serial.println("Scan complete.");

  if (networkCount == 0) {
    displayMessage("No networks found.");
  } else {
    Serial.printf("%d networks found.\n", networkCount);
    displayNetwork();
  }
}

// Function to scroll up
void scrollUp() {
  if (networkCount > 0) {
    networkIndex = (networkIndex + 1) % networkCount; // Wrap around
    displayNetwork();
  }
}

// Function to scroll down
void scrollDown() {
  if (networkCount > 0) {
    networkIndex = (networkIndex - 1 + networkCount) % networkCount; // Handle wrap-around
    displayNetwork();
  }
}

// Function to display the current network
void displayNetwork() {
  String networkInfo = String(networkIndex + 1) + ": " +
                       WiFi.SSID(networkIndex) + " (" +
                       WiFi.RSSI(networkIndex) + " dBm) " +
                       ((WiFi.encryptionType(networkIndex) == WIFI_AUTH_OPEN) ? "Open" : "Encrypted");

  Serial.println(networkInfo);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(networkInfo);
  display.display();
}

// Function to display a message on the OLED
void displayMessage(String message) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(message);
  display.display();
}
