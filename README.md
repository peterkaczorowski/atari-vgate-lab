# Video Gate Lab for PIC18F57Q43 Curiosity Nano

This repository contains test‑bench code for creating a **“video gate”**—a video signal switcher—similar to the one demonstrated in the UGV project by MyTek. It’s written specifically for the PIC18F57Q43 Curiosity Nano development board and is intended as an experimental **lab tool**, not a commercially ready solution.
The final version of the "video gate" will be used in the SAVO MAX boards for Atari 8-bit.

## 📺 Live Demo

Watch a short demo showcasing the video‑gate functionality here:

https://www.youtube.com/shorts/dBwXZMA6RJU


## Features

- Switches between video sources under microcontroller control
- Designed for the PIC18F57Q43 (Curiosity Nano) platform
- Ideal for experimentation, testing, and educational use

## Getting Started

1. Clone this repo
2. Open the MPLAB® project file for the PIC18F57Q43
3. Build and program the firmware onto the Curiosity Nano board
4. Connect GND, CSYNC signal to RB1 as input and VIDEO_GATE output from RF2 pin as switching signal to your test board.

## Usage

- Compile the source code as firmware to toggle video paths
- Monitor output on a connected display or capture system
- Modify and extend the demo code for custom video‑switching applications

## License & Warranty

⚠️ This code is provided **as-is**, for **lab use only**. **No warranties or guarantees**—use at your own risk.

---

Happy experimenting!

