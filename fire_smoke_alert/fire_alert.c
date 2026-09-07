/**
 * Subsystem: Fire and Gas/Smoke Emergency Alert System
 * Description: Dual threshold evaluation for MQ-2 gas sensor and IR flame phototransistor.
 */

#include <stdint.h>

#define GAS_PPM_DANGER_THRESHOLD 400
#define FLAME_DETECTED_LOGIC_LOW 0

typedef struct {
    uint8_t emergency_active;
    uint8_t strobe_led;
    uint8_t audio_siren;
} AlarmStatus;

AlarmStatus FireAlert_Check(uint16_t mq2_adc_ppm, uint8_t flame_pin_state) {
    AlarmStatus status = {0, 0, 0};

    if (mq2_adc_ppm > GAS_PPM_DANGER_THRESHOLD || flame_pin_state == FLAME_DETECTED_LOGIC_LOW) {
        status.emergency_active = 1;
        status.strobe_led = 1;
        status.audio_siren = 1;
    }
    return status;
}
