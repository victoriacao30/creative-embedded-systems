# Sonder

> **sonder** *(n.)* — the realization that each passerby has a life as vivid and complex as your own.

A generative art installation on the ESP32 TTGO T-Display that visualizes a flickering cityscape — each window a different story.

🎥 [Demo Video](https://www.youtube.com/shorts/ogUNu3cPZ-Q) · 🌐 [Project Page](https://victoriaxcao.com/esp)

![Sonder installation](assets/installation.jpg)

---

## What It Does

The display cycles between two states:

1. **Cityscape** (~5 seconds) — three buildings with independently flickering windows in warm colors (yellow, blue, pink, green), generated fresh each cycle
2. **Text** (~3 seconds) — *"every window tells a different story"* fades in on a dark background

The pattern never repeats exactly. No two runs are the same.

---

## Hardware

| Component | Details |
|-----------|---------|
| Microcontroller | ESP32 TTGO T-Display |
| Display | Built-in 1.14" TFT (135×240px) |
| Power | LiPo battery |

---

## Software & Dependencies

- [VSCode](https://code.visualstudio.com/) + [PlatformIO](https://platformio.org/) extension
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) library
- Arduino framework for ESP32

---

## Installation & Usage

### 1. Clone the repo

```bash
git clone https://github.com/YOUR_USERNAME/sonder.git
cd sonder
```

### 2. Configure TFT_eSPI for the TTGO T-Display

In your `TFT_eSPI` library folder, open `User_Setup_Select.h` and make sure the TTGO T-Display setup is selected:

```cpp
#include <User_Setups/Setup25_TTGO_T_Display.h>
```

> ⚠️ This step is critical — wrong pin settings will give you a blank or garbled screen with no error message.

### 3. Configure platformio.ini

```ini
[env:ttgo-t1]
platform = espressif32
board = ttgo-t1
framework = arduino
lib_deps = bodmer/TFT_eSPI
```

### 4. Flash the device

Connect your ESP32 via USB, then in VSCode hit **Upload** (PlatformIO sidebar) or run:

```bash
pio run --target upload
```

### 5. Power and deploy

Disconnect USB, connect your LiPo battery, and the sketch will start automatically on boot.

---

## Tips for Reproducibility

- **Avoid `fillScreen()` every frame.** Redrawing only changed windows (rather than the whole screen) dramatically reduces flicker.
- **Cap your frame rate.** A tight loop with no `delay()` drains the battery fast — add a small delay to keep the installation running for a full class period.
- **Randomness on ESP32.** `random()` on the ESP32 benefits from seeding with `randomSeed(analogRead(0))` at startup for better variation between runs.

---

## File Structure

```
sonder/
├── src/
│   └── main.cpp        # Main sketch
├── platformio.ini      # PlatformIO config
├── assets/
│   └── installation.jpg
├── README.md
└── BLOG.md
```
