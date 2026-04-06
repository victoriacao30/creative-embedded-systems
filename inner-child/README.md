# Inner Child

## The Idea

We spend so much of our lives performing. The way we talk at a dinner party, the way we introduce ourselves to strangers, the carefully constructed surface we present to the world — none of it is the whole story. Somewhere underneath all of that is the person we were before we learned to edit ourselves. This project is about that gap.

*Inner Child* is an interactive sculpture made of two figures: a large wire adult on the outside, and a small 3D-printed baby figure nestled inside it. The wire form is open, skeletal, exposed — and yet somehow still guarded. The baby inside is solid, complete, hidden. When you touch the outside of the adult figure, you hear static and noise — the sound of disconnection, of surface-level communication that doesn't quite reach anything real. When you touch the baby inside, you hear a heartbeat. Clear. Steady. Alive. And at the place where the two figures meet, there is a piano tone — the moment of contact between the outer self and the inner one.

---

## Artistic Vision

My broader portfolio theme is about seeing things from a different perspective — the idea that nothing is quite what it appears on the surface. *Inner Child* takes that literally. The adult wire sculpture looks like the whole story, but it isn't. You have to reach past it, through it, to find what's actually there.

I was inspired by large wire sculptures — figures made of open metalwork with glowing forms inside. That image of a transparent outer shell with something luminous at the center felt exactly right for what I was trying to say. Everyone is walking around as a wire frame. The light is on the inside.

The sound design was central to the artistic vision:
- **Outer adult (static)** — static is what you get when you can't quite tune into someone
- **Inner child (heartbeat)** — the most honest sound a body makes, the one you can't fake
- **Meeting point (piano)** — piano feels like memory, like something half-remembered from childhood

The two modes add another layer. In **Mode 1** the piece is purely sonic. In **Mode 2** it becomes visual too, with particles that bloom on screen when the baby is touched. The viewer has to discover the mode switch themselves by touching multiple points at once — a little secret hidden in the interface, just like the child is hidden in the sculpture.

---

## Technical Process

### Hardware
- ESP32 TTGO T-Display
- Aluminum wire (adult sculpture)
- 3D printed baby figure (cupid sculpture from Printables, wings removed after printing)
- Copper tape (5 touch points)
- Breadboard + jumper wires

### Touch Sensor Mapping
| Pin | GPIO | Location | Sound |
|-----|------|----------|-------|
| T3 | 15 | Outer adult | Static |
| T5 | 12 | Outer adult | Static |
| T2 | 2 | Meeting point | Piano |
| T9 | 32 | Baby figure | Heartbeat |
| T8 | 33 | Baby figure | Heartbeat |

### Software
- **ESP32:** C++ via PlatformIO — reads capacitive touch sensors, sends data over serial at 20Hz
- **Laptop:** Python with pygame — receives serial data, plays sounds, renders visuals

---

## Installation & Usage

### Requirements
- VS Code + PlatformIO
- Python 3.11
- conda environment with: `pyserial`, `pygame`, `numpy`

### Setup
1. Clone this repo
2. Open `inner-child/` in VS Code with PlatformIO
3. Upload `main.cpp` to your ESP32 TTGO T-Display
4. Install Python dependencies:
```bash
conda create -n inner_child python=3.11
conda activate inner_child
pip install pyserial pygame numpy
```
5. Update `SERIAL_PORT` in `inner_child.py` to match your device
6. Run:
```bash
python inner_child.py
```

### Sound Files
Download and place in your home directory (`~/`):
- `static.wav` — [freesound.org/sounds/552160](https://freesound.org/people/quantumriver/sounds/552160/)
- `heartbeat.wav` — [freesound.org/sounds/369017](https://freesound.org/people/patobottos/sounds/369017/)
- `piano.wav` — [freesound.org/sounds/818822](https://freesound.org/people/josefpres/sounds/818822/)

---

## Technical Challenges

**Copper tape** — the tape is very thin and wrinkles easily. Getting a reliable solder connection required patience and multiple attempts.

**Serial port detection** — the ESP32 wouldn't show up on `/dev/cu.*` — had to use `/dev/tty.*` instead. Port name also changes on every reconnect.

**Touch threshold calibration** — the default threshold of 40 was completely wrong. Raw sensor values sat at 120-130 at rest and dropped to 13-27 on touch. Final threshold: 15.

**False triggering** — bare wires act as antennas and pick up ambient electrical noise. Solution: keep wires short and properly attached to copper tape on the sculpture.

**Wire sculpture stability** — aluminum wire holds form well but the figure needed internal structure to stay upright consistently.

---

## What I Would Do Differently

- Cleaner enclosure for the ESP32 and breadboard
- Gradual sound transitions (fade between static and heartbeat rather than hard cut)
- LED lighting inside the wire adult to make the baby figure glow from within

---

## Reflections

This project taught me that the hardest part of interactive art isn't the code or the hardware — it's the translation between a feeling and a physical object. I knew what I wanted someone to feel when they touched this piece. Getting the materials, the sensors, the sounds, and the code to all work together to produce that feeling was a much longer road than I anticipated. But when it works — when someone reaches through the wire and the heartbeat plays — it works.
