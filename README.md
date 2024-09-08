# LED Control System

This C program simulates an advanced LED control system. It includes functionalities to manage both individual LED settings and collective settings for a group of LEDs.

## Structures

- **`LEDSettings`**: Represents settings for a single LED.
  - `state`: ON/OFF state (1 for ON, 0 for OFF).
  - `brightness`: Brightness level (0-255).
  - `color`: RGB color value (0xRRGGBB).

- **`LEDGroup`**: Represents a group of LEDs.
  - `singleLED`: Settings for an individual LED.
  - `groupState`: Collective state of the group (1 for all ON, 0 for all OFF).
  - `groupBrightness`: Collective brightness level (0-255).

## Functions

- **`void initLEDGroup(LEDGroup *group)`**
  - Initializes the `LEDGroup` with default values.
  - Sets all LEDs to OFF, minimum brightness, and no color.
  - Sets group state and brightness to default values.

- **`void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color)`**
  - Updates both group and individual LED settings.
  - Modifies group state, brightness, and individual LED state, brightness, and color.

- **`void displayLEDGroupStatus(const LEDGroup *group)`**
  - Displays the current status of the `LEDGroup`.
  - Prints group state, group brightness, and individual LED settings (state, brightness, color).

## Example Usage

```c
int main() {
    LEDGroup group1;

    // Initialize the LEDGroup
    initLEDGroup(&group1);

    // Update the LEDGroup settings
    updateLEDGroupSettings(&group1, 1, 150, 1, 255, 0x00FF00);  // Group ON, brightness 150, LED ON, brightness 255, color green

    // Display the LED group status
    displayLEDGroupStatus(&group1);

    return 0;
}
