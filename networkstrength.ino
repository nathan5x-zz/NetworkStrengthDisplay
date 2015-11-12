#include "application.h"
#include "neopixel/neopixel.h"

SYSTEM_MODE(AUTOMATIC);

#define DL_PIXEL_PIN D1
#define UL_PIXEL_PIN D2
#define PIXEL_COUNT 9
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel uploadStrip = Adafruit_NeoPixel(PIXEL_COUNT, UL_PIXEL_PIN, PIXEL_TYPE);
Adafruit_NeoPixel downloadStrip = Adafruit_NeoPixel(PIXEL_COUNT, DL_PIXEL_PIN, PIXEL_TYPE);

uint32_t redColor = uploadStrip.Color(255, 0, 0);
uint32_t greenColor = uploadStrip.Color(0, 255, 0);
uint32_t blueColor = uploadStrip.Color(0, 0, 255);
uint32_t mediumColor = uploadStrip.Color(255, 219, 0);

uint32_t ulCurrentColor;
uint32_t dlCurrentColor;

uint8_t ulLedTimeDelay = 30;
uint8_t dlLedTimeDelay = 150;

int j = 0;
int i = 0;
int k = 0;
int l = 0;
int dlNumPixels;
int ulNumPixels;

int dlPixelResetter = 0;
int ulPixelResetter = 8;

void setup()
{
  uploadStrip.begin();
  uploadStrip.setBrightness(25);
  uploadStrip.show();

  downloadStrip.begin();
  downloadStrip.setBrightness(25);
  downloadStrip.show();

  dlNumPixels = downloadStrip.numPixels();
  ulNumPixels = uploadStrip.numPixels();

   ulCurrentColor = blueColor;
   dlCurrentColor = greenColor;

  Spark.function("upload", ulSpeedController);
  Spark.function("download", dlSpeedController);
}

int ulSpeedController(String cSpeed){
    Serial.println("ulSpeedController -->");
    Serial.println(cSpeed);

    if(cSpeed == "HIGH") {
        ulCurrentColor = blueColor;
        ulLedTimeDelay = 50;
        uploadStrip.setBrightness(250);
    } else if (cSpeed == "LOW") {
        ulLedTimeDelay = 150;
        ulCurrentColor = redColor;
        uploadStrip.setBrightness(5);
    } else {
        ulCurrentColor = mediumColor;
        ulLedTimeDelay = 100;
        uploadStrip.setBrightness(50);
    }
    delay(ulLedTimeDelay);
    uploadSpeedController();
    return ulLedTimeDelay;
}

int dlSpeedController(String cSpeed){
    Serial.println("dlSpeedController -->");
    Serial.println(cSpeed);

    if(cSpeed == "HIGH") {
        dlCurrentColor = greenColor;
        dlLedTimeDelay = 50;
        downloadStrip.setBrightness(250);
    } else if (cSpeed == "LOW") {
        dlLedTimeDelay = 150;
        dlCurrentColor = redColor;
        downloadStrip.setBrightness(5);
    } else {
        dlCurrentColor = mediumColor;
        dlLedTimeDelay = 100;
        downloadStrip.setBrightness(50);
    }
    downloadStrip.show();
    delay(dlLedTimeDelay);
    downloadSpeedController();
    return dlLedTimeDelay;
}

void loop()
{
    uploadSpeedController();
    downloadSpeedController();
}

void downloadSpeedController() {
     j = dlPixelResetter;
     i = 0;

    for(i=0; i<dlNumPixels;i++) {
        if(i==j || i==j+1 || i==j+2) {
            //downloadStrip.setPixelColor(i,downloadStrip.Color(0,255,0));
            downloadStrip.setPixelColor(i,dlCurrentColor);
            downloadStrip.show();
        } else {
            downloadStrip.setPixelColor(i, 0);
            downloadStrip.show();
        }
        delay(dlLedTimeDelay);
    }

    dlPixelResetter+=3;

    if(dlPixelResetter==9) {
        dlPixelResetter = 0;
    }
}

void uploadSpeedController() {
     k = ulPixelResetter;
     l = 0;

    for(l=ulNumPixels-1; l>=0;l--) {
        if(l==k || l==k-1 || l==k-2) {
            //uploadStrip.setPixelColor(l,uploadStrip.Color(0,0,255));
            uploadStrip.setPixelColor(l,ulCurrentColor);
            uploadStrip.show();
            Serial.println(l);
        } else {
            uploadStrip.setPixelColor(l, 0);
            uploadStrip.show();
        }
        delay(ulLedTimeDelay);
    }

    if(ulPixelResetter == 2) {
        ulPixelResetter-=2;
    } else {
        ulPixelResetter-=3;
    }

    if(ulPixelResetter==0) {
        ulPixelResetter = 8;
    }
}
