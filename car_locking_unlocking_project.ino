#include <RCSwitch.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define pins for buttons
const int lockButtonPin = 12; // GPIO12 (D6)
const int unlockButtonPin = 5; // GPIO5 (D1)
const int resetButtonPin = 14; // GPIO14 (D5)

// Define pins for OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Create an RCSwitch object
RCSwitch mySwitch = RCSwitch();

// States
enum State { LOCKED, UNLOCKED, RESET };
State currentState = LOCKED;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Initialize the buttons
    pinMode(lockButtonPin, INPUT_PULLUP);
    pinMode(unlockButtonPin, INPUT_PULLUP);
    pinMode(resetButtonPin, INPUT_PULLUP);
    
    // Initialize RF transmitter and receiver
    mySwitch.enableTransmit(13); // GPIO13 (D7)
    mySwitch.enableReceive(0);    // Receiver on interrupt 0 (GPIO2/D4)
    
    // Initialize OLED display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // I2C address 0x3C
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Car Locking System");
    display.display();
    delay(2000);
    display.clearDisplay();
    showStatus();
}

void loop() {
    // Check button states
    if (digitalRead(lockButtonPin) == LOW) {
        lockCar();
        delay(300); // Debounce delay
    }
    if (digitalRead(unlockButtonPin) == LOW) {
        unlockCar();
        delay(300); // Debounce delay
    }
    if (digitalRead(resetButtonPin) == LOW) {
        resetSystem();
        delay(300); // Debounce delay
    }
    
    // Handle received signals
    if (mySwitch.available()) {
        int value = mySwitch.getReceivedValue();
        
        // Handle RF received value
        if (value == 123456) { // Replace with your actual lock signal
            lockCar();
        } else if (value == 654321) { // Replace with your actual unlock signal
            unlockCar();
        }
        
        mySwitch.resetAvailable();
    }
}

void lockCar() {
    currentState = LOCKED;
    mySwitch.send(123456, 24); // Send lock signal
    showStatus();
}

void unlockCar() {
    currentState = UNLOCKED;
    mySwitch.send(654321, 24); // Send unlock signal
    showStatus();
}

void resetSystem() {
    currentState = RESET;
    showStatus();
}

void showStatus() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Current Status:");
    
    switch (currentState) {
        case LOCKED:
            display.println("Car Locked");
            break;
        case UNLOCKED:
            display.println("Car Unlocked");
            break;
        case RESET:
            display.println("System Reset");
            break;
    }
    
    display.display();
}
