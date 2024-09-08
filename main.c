#include <stdio.h>
#include <stdint.h>

// Define the LEDSettings structure 
typedef struct {
    uint8_t state;        // 1 for ON, 0 for OFF
    uint8_t brightness;   // Brightness level (0-255)
    uint32_t color;       // RGB color value encoded as 0xRRGGBB
} LEDSettings;

// Define the LEDGroup structure
typedef struct {
    LEDSettings singleLED;    // Individual LED settings
    uint8_t groupState;       // Collective state for the group of LEDs (1 for all ON, 0 for all OFF)
    uint8_t groupBrightness;  // Collective brightness for the group
} LEDGroup;

// Function to initialize the LEDGroup with default values
void initLEDGroup(LEDGroup *group) {
    if (group == NULL) {
        return;  // Handle null pointer if necessary
    }
    // Initialize individual LED settings to default values
    group->singleLED.state = 0;        // LED OFF
    group->singleLED.brightness = 0;   // Minimum brightness
    group->singleLED.color = 0x000000; // No color (black)

    // Initialize group-level settings
    group->groupState = 0;        // All LEDs OFF
    group->groupBrightness = 0;   // Minimum group brightness
}

// Function to update the LEDGroup and individual LED settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color) {
    if (group == NULL) {
        return;  // Handle null pointer if necessary
    }
    // Update the group settings
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;

    // Update the individual LED settings
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;
}

void displayLEDGroupStatus(const LEDGroup *group) {
    if (group == NULL) {
        printf("Error: Null pointer provided.\n");
        return;  // Handle null pointer if necessary
    }
    // Display group status and brightness
    printf("Group State: %s\n", (group->groupState ? "ON" : "OFF"));
    printf("Group Brightness: %d\n", group->groupBrightness);

    // Display individual LED settings
    printf("Single LED State: %s\n", (group->singleLED.state ? "ON" : "OFF"));
    printf("Single LED Brightness: %d\n", group->singleLED.brightness);
    printf("Single LED Color: RGB(0x%02X, 0x%02X, 0x%02X)\n",
           (group->singleLED.color >> 16) & 0xFF,    // Extract Red component
           (group->singleLED.color >> 8) & 0xFF,     // Extract Green component
           group->singleLED.color & 0xFF);           // Extract Blue component
}

// Main function
int main() {
    // Create and initialize an LEDGroup
    LEDGroup group1;
    initLEDGroup(&group1);

    // Update the LEDGroup settings
    updateLEDGroupSettings(&group1, 1, 150, 1, 255, 0x00FF00);  // Group ON, brightness 150, LED ON, brightness 255, color green

    // Display the LED group status
    displayLEDGroupStatus(&group1);

    return 0;
}
