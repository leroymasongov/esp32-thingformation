// need to set password

#define LM_PASSWORD "2167c91035"


#include <stdio.h>
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

// Wi-Fi event handler
static esp_err_t wifi_event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id) {
        case WIFI_EVENT_STA_START:
            ESP_LOGI("Wi-Fi", "Station started %s"," ");
            esp_wifi_connect();
            break;
        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI("Wi-Fi", "Connected to AP");
            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGI("Wi-Fi", "Disconnected from AP");
            esp_wifi_connect();
            break;
        default:
            break;
    }
    return ESP_OK;
}

void app_main(void)
{
    // Initialize Wi-Fi
    tcpip_adapter_init();
    esp_event_loop_create_default();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);

    // Set Wi-Fi configuration
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "masons2020",
            .password = LM_PASSWORD,
        },
    };
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);

    // Register Wi-Fi event handler
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL);

    // Start Wi-Fi
    esp_wifi_start();
}
