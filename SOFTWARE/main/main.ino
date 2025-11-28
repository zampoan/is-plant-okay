/*
    Before starting, install following libraries:
        - adafruit_gfx
        - adafruit_st7735
        - arduino_hs300x
        - arduino_bmi270_bmm150
        - arduino_LPS22HB

*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Arduino_HS300x.h>


// Pinouts
#define CAM_D0 D0
#define CAM_D1 D1
#define CAM_D2 D2
#define CAM_D3 D3
#define CAM_D4 D4
#define CAM_D5 D5
#define CAM_D6 D6
#define CAM_D7 D7
#define CAM_VSYNC D8
#define CAM_XCLK D9 
#define CAM_HREF D10
#define BUTTON_PIN A0
#define LORA_CS A1
#define LORA_RST A2
#define TFT_CS A3
#define CAM_SIOD A4
#define CAM_SIOC A5
#define RTC_CS A6
#define CAM_PCLK A7
#define UNUSED_PIN -1

#define DEBUG
#ifdef DEBUG
    #define DEBUG_PRINT(x) Serial.print(x)
    #define DEBUG_PRINTLN(x) Serial.println(x) 
#else
    #define DEBUG_PRINT(x) Serial.print(x)
    #define DEBUG_PRINTLN(x) Serial.println(x)
#endif

// tft screen
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, UNUSED_PIN, UNUSED_PIN);

// temperature and humidity sensor
float old_temp = 0;
float old_hum = 0;

void showTemperatureHumidity(void){
    float temperature = HS300x.readTemperature();
    float humidity = HS300x.readHumidity();

    if (abs(old_temp - temperature) >= 0.5 || abs(old_hum - humidity) >= 1){
        DEBUG_PRINT("Temperature: ");
        DEBUG_PRINTLN(temperature);

        DEBUG_PRINT("Humidity: ");
        DEBUG_PRINTLN(humidity);
        DEBUG_PRINTLN(" %");

        delay(500);
    }
}

void setup() {
    Serial.begin(11600);
    SPI.begin();
    if (!HS300x.begin()){
        DEBUG_PRINTLN("Failed to init HS300x!");
    } 

    // Camera Pins
    pinMode(CAM_SIOD, INPUT); // Serial ubterface data I/o
    pinMode(CAM_SIOC, INPUT); // Serial clock
    pinMode(CAM_D0, OUTPUT); 
    pinMode(CAM_D1, OUTPUT);
    pinMode(CAM_D2, OUTPUT);
    pinMode(CAM_D3, OUTPUT);
    pinMode(CAM_D4, OUTPUT);
    pinMode(CAM_D5, OUTPUT);
    pinMode(CAM_D6, OUTPUT);
    pinMode(CAM_D7, OUTPUT);
    pinMode(CAM_VSYNC, OUTPUT); // vertical sync output
    pinMode(CAM_HREF, OUTPUT); // href output
    pinMode(CAM_PCLK, OUTPUT); // pixel clock output
    pinMode(CAM_XCLK, OUTPUT); // system clock output

    // Button Pins
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // LoRa Module Pins
    pinMode(LORA_CS, OUTPUT);
    pinMode(LORA_RST, OUTPUT);

    // TFT Screen Pins
    pinMode(TFT_CS, OUTPUT);
    tft.initR(INITR_MINI160x80);

    // RTC Pins
    pinMode(RTC_CS, OUTPUT);
}

void loop(){
    showTemperatureHumidity();

    if (digitalRead(BUTTON_PIN) == LOW){
        Serial.println("Button Pressed");
    }
}
