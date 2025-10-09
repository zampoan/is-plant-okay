#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <Arduino_HS300x.h>

// OLED dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

// Define SPI + control pins
#define MOSI 11
#define MISO 12
#define SCK 13
#define OLED_CS 10
#define OLED_DC 5
#define OLED_RST 6

// HS300x sensor values
float old_temperature = 0;
float old_humidity = 0;

// Display object
Adafruit_SSD1351 display = Adafruit_SSD1351(
  SCREEN_WIDTH, SCREEN_HEIGHT,
  &SPI, OLED_CS, OLED_DC, OLED_RST
);

void oled_setup(){
  display.fillScreen(display.color565(255, 0, 0));
  display.setCursor(10, 10);
  display.setTextColor(display.color565(255, 255, 255));
  display.setTextSize(1);
  display.println("Hello World!");
}


void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Serial ready.");
  Wire.begin();

  if(!HS300x.begin()){
    Serial.println("Failed to initialize HS300x sensor");
    while(1);
  }

  display.begin();

  Serial.println("All initialized...");
}

void loop() {
  
}
