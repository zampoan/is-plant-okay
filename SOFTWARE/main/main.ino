#include <SPI.h>

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

void setup() {
    Serial.begin(9600);
    SPI.begin();

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
    pinMODE(CAM_HREF, OUTPUT); // href output
    pinMode(CAM_PCLK, OUTPUT); // pixel clock output
    pinMode(CAM_XCLK, OUTPUT); // system clock output

    // Button Pins
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // LoRa Module Pins
    pinMode(LORA_CS, OUTPUT);
    pinMode(LORA_RST, OUTPUT);

    // TFT Screen Pins
    pinMode(TFT_CS, OUTPUT);

    // RTC Pins
    pinMode(RTC_CS, OUTPUT);
}

void loop(){
    if (digitalRead(BUTTON_PIN) == LOW){
        Serial.println("Button Pressed");
    }
}
