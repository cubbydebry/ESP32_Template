#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_13

void flash_sos(void *pvParameter);

void app_main(void){
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    TaskHandle_t flash;
    xTaskCreate(flash_sos, "flash_sos", configMINIMAL_STACK_SIZE, NULL, 5, &flash);
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(100));
        printf("I'm Alive!\n");
    }
}

void flash_sos(void *pvParameter){
    const uint8_t dot = 200;
    const uint16_t dash = 600;

    while(1){
        // S
        for(int i = 0; i < 3; i++){
            gpio_set_level(LED_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(dot));
            gpio_set_level(LED_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(dot));
        }
        vTaskDelay(pdMS_TO_TICKS(500));

        // O
        for(int i = 0; i < 3; i++){
            gpio_set_level(LED_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(dash));
            gpio_set_level(LED_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(dot));
        }
        vTaskDelay(pdMS_TO_TICKS(500));

        // S
        for(int i = 0; i < 3; i++){
            gpio_set_level(LED_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(dot));
            gpio_set_level(LED_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(dot));
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}