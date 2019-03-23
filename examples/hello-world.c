/* This file was generated by TS2C */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <esp_system.h>
#include <esp_spi_flash.h>
#include <freertos/task.h>
#include <freertos/FreeRTOS.h>

typedef short int16_t;
static esp_chip_info_t * chip_info;
static int16_t i;
int main(void) {
    printf("Hello world!\n");
    chip_info = malloc(sizeof(*chip_info));
    assert(chip_info != NULL);
    esp_chip_info(chip_info);
    printf("This is ESP32 chip with");
    printf(" %d", chip_info->cores);
    printf(" CPU cores, WiFi");
    printf(" %s", chip_info->features & CHIP_FEATURE_BT ? "/BT" : "");
    printf(" %s", chip_info->features & CHIP_FEATURE_BLE ? "/BLE" : "");
    printf(" , silicon revision");
    printf(" %d", chip_info->revision);
    printf(" %d", spi_flash_get_chip_size() / (1024 * 1024));
    printf(" Mb");
    printf(" %s", chip_info->features & CHIP_FEATURE_EMB_FLASH ? "embedded" : "external");
    printf(" flash\n");
    i = 10;
    for (;i >= 0;i--)
    {
        printf("Restarting in");
        printf(" %d", i);
        printf(" seconds...\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    esp_restart();
    free(chip_info);

    return 0;
}