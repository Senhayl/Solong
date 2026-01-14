# 🎮 Solong

**so_long** is a graphical project of the 42 curriculum.  
The goal is to create a small 2D game using the **MiniLibX**, where the player must collect all items and reach the exit.

---

## 🧠 Project Objectives

- Learn the basics of graphical programming
- Handle events (keyboard input, window close)
- Parse and validate a map
- Manage textures and sprites
- Apply structured programming in C

---

## 🕹️ Game Rules

- The player can move using **W A S D**
- The player must collect **all collectibles** (`C`)
- Once all collectibles are gathered, the **exit** (`E`) becomes accessible
- The game ends when the player reaches the exit
- The player **cannot pass through walls** (`1`)
- Each movement is counted and displayed in the terminal

---

## 🗺️ Map Format

The map must be provided as a `.ber` file and follow these rules:

- Must be **rectangular**
- Must be **surrounded by walls**
- Must contain **exactly one player (`P`)**
- Must contain **at least one collectible (`C`)**
- Must contain **exactly one exit (`E`)**
- Must contain only valid characters:  
  `0` (empty), `1` (wall), `P` (player), `C` (collectible), `E` (exit)
- Player must have a way out

Example:

111111
1P0C01
100001
1C0E01
111111

---

## 🛠️ Controls

| Key | Action |
|----|-------|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| ESC | Quit the game |
| Window close | Quit the game |

---

## 🧪 Compilation & Usage

### 🔹 Compile the game
```bash
make

🔹 Run the game

./so_long maps/map.ber

📦 Files Structure

    src/ – source files

    includes/ – header files

    textures/ – sprites and textures

    maps/ – map files

    libft/ – Libft library

    mlx/ – MiniLibX

📏 Norm & Constraints

    Written in C

    Fully compliant with 42 Norm

    Uses MiniLibX

    No memory leaks

    Clean exit on window close or ESC

👤 Author

    mlouron, 42 Student

⚠️ Disclaimer

This project is part of the 42 School curriculum.
If you are a 42 student, do not copy this code — use it only as a reference.
