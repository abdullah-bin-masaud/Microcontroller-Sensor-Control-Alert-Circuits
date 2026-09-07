/**
 * Subsystem: Automatic Street Light Controller with Hysteresis Filtering
 * Description: LDR ambient light sensing. Hysteresis prevents rapid flicker during dusk/dawn.
 */

#include <stdint.h>

#define THRESHOLD_DUSK 350  // Turn ON when ambient drops below this ADC value
#define THRESHOLD_DAWN 500  // Turn OFF when ambient rises above this (Hysteresis window)

static uint8_t s_light_state = 0; // 0 = OFF, 1 = ON

uint8_t StreetLight_Update(uint16_t ldr_adc_value) {
    if (s_light_state == 0) {
        if (ldr_adc_value < THRESHOLD_DUSK) {
            s_light_state = 1; // Turn ON relay/lights
        }
    } else {
        if (ldr_adc_value > THRESHOLD_DAWN) {
            s_light_state = 0; // Turn OFF relay/lights
        }
    }
    return s_light_state;
}
