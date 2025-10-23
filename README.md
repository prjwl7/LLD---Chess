# ♟️ C++ Console Chess Game

A command-line implementation of the classic game of Chess using Object-Oriented Programming (OOP) principles in C++. This project focuses on class inheritance (`Piece` $\rightarrow$ `Rook`, `Pawn`, etc.), polymorphism, and board manipulation.

## ✨ Features

* **OOP Structure:** Clear separation of concerns with classes for `System`, `Board`, `Player`, `Move`, `Cell`, and all `Piece` types.
* **Polymorphism:** Uses a virtual base class (`Piece`) to handle unique movement logic for all derived pieces.
* **Console Interface:** Displays the board using standard ASCII characters (e.g., `r`, `N`, `P`, `.`).
* **Basic Game Flow:** Supports player turns, move input (e.g., A2A4), and move execution.

## 🛠️ Build and Run

### Prerequisites

* A C++ Compiler (e.g., **GCC/G++**, Clang, MSVC).
* A build system or IDE (e.g., VS Code, Visual Studio, CMake).

### Compiling with G++ (Linux/macOS/MinGW)

Assuming all your `.cpp` files are in the main directory, use the following command to compile all source files into a single executable.

```bash
g++ -std=c++17 -o chess_game main.cpp System.cpp Board.cpp Player.cpp Move.cpp Cell.cpp Piece.cpp
```

### Running the Game

```bash
./chess_game
```

## Project Structure
```
Chess/
├── main.cpp          # Main game loop and system initialization
├── System.h/.cpp     # Manages game state, players, and turn flow
├── Board.h/.cpp      # Manages the 8x8 grid and pieces
├── Player.h/.cpp     # Handles player information and input logic
├── Move.h/.cpp       # Defines a move (start and end Cell coordinates)
├── Cell.h/.cpp       # Represents a single square on the board
├── Piece.h/.cpp      # Abstract base class for all pieces
├── Types.h           # Global enums (ColorType, PieceType, GameStatus)
└── Pieces/
    ├── Rook.h/.cpp   # Derived Rook class
    ├── Pawn.h/.cpp   # Derived Pawn class
    └── ...           # All other piece definitions (King, Queen, etc.)
```
