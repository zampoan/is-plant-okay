# Is-Plant-Okay 🌱?
## Concept
A solar-powered sensor node that uses a low-power camera and a tiny on-board ML model to detect early signs of plant disease. It will be mounted on a stake and its purpose is to continuously watch the same plant or section of crop bed. 
It will periodically take a picture every 30 mins.

Output: An image showing what areas of the plant is diseased. What the disease is. What plant it is. Confidene score of the plant. This information will be sent to a dashboard via LoRaWAN.

Dataset to be trained on: https://www.kaggle.com/datasets/vipoooool/new-plant-diseases-dataset

ML model: https://www.nature.com/articles/s41598-025-06452-5

## Hardware
- 🧠 MCU: Arduino Nano 33 BLE Sense Rev2 
- 🔋 Lipo: 3.7 2000mAh
- ☀️ Solar power cells: 0.5W Solar Panel 55x70
- 📷 Camera: Himax CMOS imaging camera (HM01B0)
- 🌡️ Temperature sensor: Arduino Nano 33 BLE Sense Rev2 (onboard HS3003)
- 🌡️ Humidity sensor: Arduino Nano 33 BLE Sense Rev2 (onboard HS3003)
- 🌡️ Soil moisture sensor: 
- 🖵 Screen:

## Software
- KiCad 9.0: Schematic diagram drawing & PCB design
- Fusion 360: Case design

## Inspiration
https://core-electronics.com.au/solar-lipo-charger-3-7v.html?gad_source=1&gad_campaignid=17417005429&gbraid=0AAAAADlEpP5hdt5SrEQd7QDKWpbK3QQSB&gclid=EAIaIQobChMI1JaFiPXgjwMVgyN7Bx0SeB8vEAQYASABEgJKWPD_BwE