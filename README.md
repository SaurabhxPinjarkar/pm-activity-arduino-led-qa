# Arduino LED Blinking - Project Management Activity 2

AI-assisted educational QA exercise for Saurabh Pinjarkar.
Target board: Arduino Uno R3. Use the built-in LED; no external wiring is required.

## Behavior and upload

Open `led_blink/led_blink.ino` in Arduino IDE, select Arduino Uno and the connected port, then Verify and Upload. The built-in LED starts LOW and toggles every 1000 ms (approximately one second ON and one second OFF; full cycle about two seconds, 0.5 Hz). Use a data-capable USB cable. No external LED or resistor is needed for the built-in LED.

The revised sketch uses `LED_BUILTIN`, explicit output initialization and non-blocking `millis()` timing. Unsigned subtraction tolerates the 32-bit timer wrap as long as the loop is serviced normally. This is not a hard real-time scheduler; long loop stalls can extend an interval.

## QA evidence

The first commit is an intentionally incomplete teaching baseline. Four GitHub issues track its review findings. Later revisions address these findings. GitHub Actions compiles the final sketch for Arduino Uno; that is not a hardware execution test. See `docs/QA.md` and `docs/PLAN.md`.

AI assistance was used to prepare code, analyze issues and document resolutions. Comments posted by the repository owner with AI assistance are not independent peer review. Physical tests and peer review remain pending.

## References

- Arduino Blink Without Delay: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
- Arduino CLI: https://arduino.github.io/arduino-cli/latest/
