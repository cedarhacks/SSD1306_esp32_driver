#include <stdio.h>
#include <string.h>
#include "SSD1306_i2c_driver.h"

#define DISP_HOR_RES
#define DISP_VER_RES 240

uint8_t pixels[SSD1306_HEIGHT * SSD1306_WIDTH];

void app_main(void) {
    printf("HEllo world SSD1306\n");

    SSD1306_t display;
    display.i2c_data_pin = 8;  // IO2 ????
    display.i2c_clock_pin = 9; // IO3 ?????
    display.i2c_freq_hz = 1000000;
    display.i2c_address = 0x3C; // ID for 32 pixel height display

    memset(pixels, 0x0, sizeof(pixels));
    SSD1306_init(&display);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    SSD1306_setup_display(&display);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    printf("SETTING UPDISPLAU\n");
    SSD1306_display(&display, pixels);

    int flip = 0;

    while (1) {
        // test(&display);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        flip = !flip;

        // if (flip) {
        //     memset(pixels, 0xff, sizeof(pixels));
        // } else {
        //     memset(pixels, 0x0, sizeof(pixels));
        // }

        uint8_t temp = 0;
        for (int c = 0; c < SSD1306_WIDTH; c++) {
            for (int r = 0; r < SSD1306_HEIGHT; r++) {
                pixels[(128 * r) + c] = temp;

                if (c > 0 && c < 10)
                    pixels[(128 * r) + c] = 0;

                if (c > 118 && c < 128)
                    pixels[(128 * r) + c] = 0;
            }
            temp = temp == 0 ? 255 : 0;
        }

        // pixels[100] = 0xFF;
        // pixels[101] = 0xFF;
        // pixels[102] = 0xFF;

        SSD1306_display(&display, pixels);
    }
}
