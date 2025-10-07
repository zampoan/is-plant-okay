#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <Arduino_HS300x.h>
#include <Wire.h>

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

  // if (!Wire.begin()){
  //   Serial.println("Failed to initalize I2C");
  // }

  if(!HS300x.begin()){
    Serial.println("Failed to initialize HS300x sensor");
    while(1);
  }

  // if(display.begin()){
  //   Serial.println("Failed to initialize OLED");
  // }
  display.begin();
  //oled_setup();
  Serial.println("All initialized...");
}

void loop() {
  float temperature = HS300x.readTemperature();
  float humidity = HS300x.readHumidity();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  if (abs(old_temperature - temperature) >= 0.5 || abs(old_humidity - humidity) >= 1 )
  {
  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
   }

}
