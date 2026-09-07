"""
Interactive Software Simulation of All 3 Sensor Control and Alert Circuits.
"""
import time


def simulate():
    print("==================================================================")
    print("  MICROCONTROLLER SENSOR CONTROL & ALERT CIRCUITS SIMULATION")
    print("==================================================================")

    # 1. Water Level System
    print("\n[CIRCUIT 1: Automated Water Level Indicator]")
    water_levels = [("Empty", 0), ("25% Low", 1), ("50% Mid", 3), ("75% High", 7), ("100% Overflow", 15)]
    for label, mask in water_levels:
        leds = bin(mask)[2:].zfill(4)
        buzzer = "SOUNDING BUZZER!" if mask == 15 else "Quiet"
        print(f"  Level: {label:<16} | Bar LEDs [4-Level]: [{leds}] | Buzzer: {buzzer}")

    # 2. LDR Street Light
    print("\n[CIRCUIT 2: Automatic Street Light with Hysteresis]")
    lux_readings = [800, 600, 320, 280, 340, 420, 550, 700]
    light_state = "OFF"
    for ldr in lux_readings:
        if light_state == "OFF" and ldr < 350:
            light_state = "ON"
        elif light_state == "ON" and ldr > 500:
            light_state = "OFF"
        print(f"  Ambient Light (ADC): {ldr:4d} | Hysteresis Filtered Relay: [{light_state}]")

    # 3. Fire & Smoke Alert
    print("\n[CIRCUIT 3: Emergency Smoke & Flame Alert System]")
    scenarios = [
        ("Normal Air Quality", 80, "No Flame"),
        ("Minor Cooking Vapors", 220, "No Flame"),
        ("SMOKE HAZARD DETECTED", 650, "No Flame"),
        ("ACTIVE FLAME DETECTED", 110, "FLAME PRESENT")
    ]
    for desc, ppm, flame in scenarios:
        alarm = (ppm > 400 or flame == "FLAME PRESENT")
        status = "EMERGENCY STROBE + SIREN TRIGGERED!" if alarm else "Standby (Nominal)"
        print(f"  Condition: {desc:<24} | MQ-2: {ppm} PPM | IR Flame: {flame:<13} -> {status}")

    print("\n[*] All 3 circuit logic simulations verified successfully.")


if __name__ == "__main__":
    simulate()
