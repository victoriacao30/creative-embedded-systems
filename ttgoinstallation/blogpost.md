# Sonder — ESP32 Generative Art Installation
 
> **sonder** *(n.)* — the realization that each passerby has a life as vivid and complex as your own.
 
🎥 [Watch the demo](https://www.youtube.com/shorts/ogUNu3cPZ-Q) · 🌐 [Full project page](https://victoriaxcao.com/esp)
 
---
 
## The Concept
 
For this generative art installation, I wanted to make something that felt true to the space — a busy hallway on the fifth floor of Milstein, full of people passing each other without a second thought.
 
I kept coming back to the word *sonder*. That quiet, slightly overwhelming feeling of realizing every stranger around you carries a whole interior world. A whole life. And what better metaphor for that than a city at night, lit up window by window?
 
**Sonder** displays a generative cityscape of three buildings, each dotted with windows that flicker on and off independently — different colors, different rhythms, different stories. After a few seconds, the skyline fades and a single line of text appears: *"every window tells a different story."* Then the city comes back, and it starts again.
 
The piece loops endlessly, never repeating exactly the same pattern twice.
 
---
 
## Artistic Vision
 
I wanted the ESP32's small screen to feel like looking at something from far away — like peering up at apartment buildings at night and catching glimpses of light behind curtains. The tiny display actually *helped* that feeling. It made the city feel distant and intimate at the same time.
 
The decision to separate the cityscape and the text into two distinct moments was deliberate. My first instinct was to show both at once, but it felt cluttered — the message got lost in the visual noise. Splitting them gave each element room to breathe: the buildings let you *feel* something, and the text gives it a name.
 
For the colors, I wrote a `randomWindowColor()` function that cycles through warm tones — yellow, blue, pink, and green — to suggest the variety of lives inside. No two windows are the same, and no two moments are the same.
 
**The installation itself became its own accidental act of sonder.** Hanging alongside my classmates' devices in the hallway — each one a tiny screen with its own world inside — the collection of blinking lights and scrolling text was, collectively, its own kind of city.
 
---
 
## Process
 
### 1. Learning Generative Art
 
Before starting, we explored what makes code truly *generative* — not just a looping animation, but a system driven by randomness and time that never repeats exactly. Key techniques included:
 
- **Modulus (`%`)** for wrap-around and timing effects
- **`sin()` / `cos()`** for smooth oscillation
- A creative iteration strategy: tune parameters → replace with code → refactor → make structural changes
The biggest lesson: imprecision is part of the process. Keep trying things and see what happens.
 
### 2. Getting Comfortable with the ESP32
 
I started with a simple white-light flash to get familiar with the setup — configuring `platformio.ini`, installing USB drivers, and getting the `TFT_eSPI` library running in VSCode with PlatformIO.
 
Seeing the screen light up from my own code for the first time was genuinely exciting. My friend Mima and I got a little carried away and ended up building a mini Doodle Jump clone on it for fun — more on that soon 👀
 
### 3. Building Sonder
 
The trickiest part was making the windows feel alive and *independent*. I needed each window across three buildings to blink at different times, in different colors, without syncing up or falling into a predictable pattern.
 
The solution was a **frame counter + modulus** approach: each window checks a global frame count and uses a unique offset and modulus value to decide when to toggle. Combined with random initial states, no two windows ever blink in unison.
 
Key technical decisions:
 
- **`randomWindowColor()`** — returns one of four warm tones per window per cycle
- **Two-phase sequencing** — cityscape runs for ~5 seconds, fades to text for ~3 seconds, then cycles back
- **Independent per-window state** — each window holds its own color and on/off value, updated through the frame counter
### 4. The Installation
 
The final piece hung in a small paper envelope in the Milstein hallway alongside every other ESP32 in the class. All the little screens blinking and scrolling at once — different visuals, different meanings, different creative visions coexisting in one corridor.
 
Walking around to see everyone's work was its own moment of sonder. That's the piece.
 
---
 
## Reflection
 
This was my first time making art for an installation, and I wasn't sure what to expect. Working on something so small and technical — debugging timing offsets, tuning colors, iterating on sequencing — and then seeing it hanging in a public hallway among my classmates' works was so exciting!!
