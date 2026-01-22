idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "./include"
    REQUIRES freertos
    PRIV_REQUIRES esp_driver_gpio
)