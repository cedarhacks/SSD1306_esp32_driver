#include <stdio.h>
#include <string.h>
#include "SSD1306_i2c_driver.h"

void app_main(void) {
    printf("HEllo world SSD1306\n");

    SSD1306_t display;
    display.i2c_data_pin = 8;  // IO2 ????
    display.i2c_clock_pin = 9; // IO3 ?????
    display.i2c_freq_hz = 1000000;
    display.i2c_address = 0x3C; // ID for 32 pixel height display

    uint8_t buffer[128 * ((32 + 7) / 8)];
    memset(buffer, 0xff, sizeof(buffer));

    SSD1306_init(&display);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    SSD1306_setup_display(&display);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    printf("SETTING UPDISPLAU\n");
    SSD1306_display(&display, buffer);

    int flip = 0;

    while (1) {
        // test(&display);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        flip = !flip;

        if (flip) {
            memset(buffer, 0xff, sizeof(buffer));
        } else {
            memset(buffer, 0x0, sizeof(buffer));
        }

        SSD1306_display(&display, buffer);  
    }
}
