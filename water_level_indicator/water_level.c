/**
 * Subsystem: Automated Water Level Indicator & Overflow Alarm
 * Controller: Microchip PIC / AVR / Generic Microcontroller
 * Description: Multi-level probe detection using BC547 NPN transistor switching logic.
 */

#include <stdint.h>

#define PROBE_LOW      0x01  // Tank 25%
#define PROBE_MID      0x02  // Tank 50%
#define PROBE_HIGH     0x04  // Tank 75%
#define PROBE_OVERFLOW 0x08  // Tank 100% (Critical)

// Output pin states
uint8_t g_led_indicators = 0x00;
uint8_t g_buzzer_alarm = 0;

void WaterLevel_Process(uint8_t probe_inputs) {
    g_led_indicators = 0;
    g_buzzer_alarm = 0;

    if (probe_inputs & PROBE_LOW) {
        g_led_indicators |= 0x01; // Green LED (Low)
    }
    if (probe_inputs & PROBE_MID) {
        g_led_indicators |= 0x03; // Yellow LEDs (Mid)
    }
    if (probe_inputs & PROBE_HIGH) {
        g_led_indicators |= 0x07; // Orange LEDs (High)
    }
    if (probe_inputs & PROBE_OVERFLOW) {
        g_led_indicators |= 0x0F; // Red LED (Full)
        g_buzzer_alarm = 1;       // Sound audio buzzer
    }
}
