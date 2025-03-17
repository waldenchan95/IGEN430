#include <WiFi.h>
#include <esp_now.h>

//    DC MOTOR DRIVER MAC ADDRESS: 1C:69:20:CD:49:34
uint8_t dc_motor_addr[] = {0x1C, 0x69, 0x20, 0xCD, 0x49, 0x34};

//    STEPPER MOTOR DRIVER MAC ADDRESS: 88:13:BF:69:FB:00
uint8_t stepper_motor_addr[] = {0x88, 0x13, 0xBF, 0x69, 0xFB, 0x00};

typedef struct CommandMessage {
  char command[32]; // char array for the command to send 
} CommandMessage; 

void onSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("Delivery Status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}



void setup() {
  // Start Serial communication
  Serial.begin(115200);
  
  // Initialize Wi-Fi (even if you're not using it for actual networking)
  WiFi.mode(WIFI_STA);  // Set Wi-Fi mode to Station mode (client)
  delay(1000);  // Add a short delay to ensure Wi-Fi is initialized
  
  // Get and print the MAC address
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Nothing to do in loop
}
