# SSD1306 Drivers

## Description

A small .c/.h file combo that initializes the display and lets you render a pixel buffer onto it. Lots of the fluff and display features is taken out, merge requests and modifications are welcome if you want to expand it!

## How to use

After you compile in the SSD1306_i2c_driver.h/.c files into your esp-idf project, you can do the following:

**Define a pixel buffer and create an SSD1306_t display object**
```
uint8_t pixels[SSD1306_HEIGHT * SSD1306_WIDTH];
SSD1306_t display;
```

**Initialize the display object**
```
display.i2c_data_pin = 15; // pin number for data
display.i2c_clock_pin = 16; // pin number for clock
display.i2c_freq_hz = 1000000;
display.i2c_address = 0x3C; // ID for 32 pixel height display
SSD1306_init(&display);
```

**Startup the display**
```
SSD1306_setup_display(&display);
```

**Render pixels onto the display**
```
SSD1306_display(&display, pixels);
```

## Using LVGL

The main file in this project shows an example of integrating LVGL with this driver, you can use it as reference to do the same. The `color_on(...)` function might need to be tuned for your purposes

