# Microcontroller Sensor Control & Alert Circuits

A suite of three practical embedded hardware automation circuits designed, simulated in Proteus, and coded in Embedded C:

1. **Water Level Indicator:** Multi-stage transistor switching logic (BC547) driving a 4-tier LED display and automated overflow buzzer alert.
2. **Automatic Street Light Controller:** LDR sensor-based illumination control featuring hysteresis filtering to prevent dusk/dawn relay chatter.
3. **Fire & Smoke Emergency Alert:** Dual-stage safety circuit interfacing an MQ-2 combustible gas sensor and IR flame phototransistor with rapid strobe and siren signaling.

## Project Structure
- `water_level_indicator/`: C firmware & Proteus design guide for water tank sensing.
- `automatic_street_light/`: C firmware & hysteresis logic for lighting control.
- `fire_smoke_alert/`: Emergency alert interrupt logic.
- `simulation/simulate_circuits.py`: Python-based interactive simulation of all three systems.

## Quickstart
```bash
python simulation/simulate_circuits.py
```
