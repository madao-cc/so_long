# so_long

> **Objective:** Develop a simple 2D game using C and the MiniLibX library, where a player navigates through a map, collects items, and reaches an exit point.

## Table of Contents

- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Game Mechanics](#game-mechanics)
- [Controls](#controls)
- [Implementation Details](#implementation-details)
- [Learning Outcomes](#learning-outcomes)
- [Acknowledgments](#acknowledgments)

## Project Overview

**so_long** is a project that challenges you to create a small 2D game where a player navigates through a map, collects items (like coins or fuel), and reaches an exit point. citeturn0search2

## Key Features

- **Map Parsing:** Reads and validates a map file to set up the game environment.
- **Graphics Rendering:** Utilizes the MiniLibX library to render images and sprites.
- **Event Handling:** Responds to user input via keyboard for character movement.
- **Game Logic:** Implements movement, collision detection, item collection, and exit conditions.

## Project Structure

The repository is organized as follows:

- `src/`: Contains the main source files for the game.
- `include/`: Header files with function prototypes and macros.
- `assets/`: Images and sprites in XPM format used in the game.
- `maps/`: Map files with the `.ber` extension defining game levels.
- `Makefile`: Automates the compilation process.

## Installation

To set up and run the game:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/madao-cc/so_long.git
   ```

2. **Navigate to the Project Directory:**
   ```bash
   cd so_long
   ```

3. **Compile the Project:**
   ```bash
   make
   ```
   This will generate the executable `so_long`.

## Usage

To start the game, run the executable with a map file as an argument:

```bash
./so_long maps/level1.ber
```

Replace `maps/level1.ber` with the path to your desired map file.

## Game Mechanics

- **Objective:** Navigate the player character through the map to collect all collectibles and reach the exit.
- **Map Elements:**
  - `1`: Wall
  - `0`: Empty space
  - `P`: Player start position
  - `C`: Collectible item
  - `E`: Exit

## Controls

- **W:** Move Up
- **A:** Move Left
- **S:** Move Down
- **D:** Move Right
- **ESC:** Exit the game

## Implementation Details

- **Map Parsing:** The game reads the map file to set up the game environment, ensuring the map is rectangular and properly formatted.
- **Graphics Rendering:** Utilizes the MiniLibX library to display images and sprites corresponding to the map elements.
- **Event Handling:** Listens for keyboard inputs to move the player character and updates the game state accordingly.
- **Game Logic:** Checks for collisions with walls, tracks collected items, and determines when the exit condition is met.

## Learning Outcomes

Through this project, the following concepts are reinforced:

- **Graphics Programming:** Understanding the basics of rendering graphics using the MiniLibX library.
- **Event-Driven Programming:** Handling user inputs and updating the game state in response.
- **File I/O:** Reading and parsing map files to set up the game environment.
- **Game Development Fundamentals:** Implementing core game mechanics such as movement, collision detection, and win conditions.

## Acknowledgments

This project is part of the curriculum at 42 School, designed to introduce students to basic game development and graphics programming in C.
