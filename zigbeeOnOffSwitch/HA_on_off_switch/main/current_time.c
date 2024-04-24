// first make sure network connected

#include <stdio.h>
#include <time.h>
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_sntp.h"

// Initialize Wi-Fi and connect to the network (not shown here)

void obtain_time(void)
{
    // Set your timezone offset and daylight offset
    int gmtOffset_sec = 3600; // Example: GMT+1
    int daylightOffset_sec = 0; // Example: No daylight saving time

    // Set your preferred NTP server (e.g., pool.ntp.org)
    const char* ntpServer = "pool.ntp.org";

    // Initialize NTP client
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void app_main(void)
{
    obtain_time();
    // Now you can use standard C functions to get the current datetime
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // Print the current date and time
    char strftime_buf[64];
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    ESP_LOGI("NTP Example", "Current date and time: %s", strftime_buf);
}
