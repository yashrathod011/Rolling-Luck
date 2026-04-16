# Rolling Luck

**Rolling Luck** is a high-speed, interactive dice-rolling race game built using **C++** and the **OpenGL Utility Toolkit (GLUT)**. The project combines classic tabletop mechanics with real-time 3D graphics rendering, featuring a competitive racing environment where movement is governed by the luck of the draw.

## 🚀 Overview
In this simulation, players navigate a racing track where progression is determined by a digital dice simulator. The game utilizes a fixed-function OpenGL pipeline to render the environment, the racing elements, and the interactive dice. It serves as a practical implementation of computer graphics concepts, including window resizing logic, keyboard-controlled event handling, and random value generation.

## 🛠️ Technologies Used
* **Language:** C++
* **Graphics Library:** OpenGL (Legacy)
* **Utility Toolkit:** FreeGLUT / GLUT
* **Development Tools:** MinGW/GCC (Compiler), Git

## 🎮 Features
* **Interactive Dice:** A keyboard-triggered random value generator that simulates the physical toss of a die.
* **Real-time Rendering:** Uses OpenGL to draw the racing grid and game pieces.
* **Dynamic Gameplay:** A race-to-the-finish mechanic where players must rely on "Rolling Luck" to reach the goal.

## 🔧 Installation & Setup
To run this project locally, ensure you have a C++ compiler and the GLUT/FreeGLUT libraries configured.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/yashrathod011/Rolling-Luck.git](https://github.com/yashrathod011/Rolling-Luck.git)
    cd Rolling-Luck
    ```
2.  **Compile the code:**
    *(Example using MinGW)*
    ```bash
    g++ main.cpp -o RollingLuck -lfreeglut -lglu32 -lopengl32
    ```
3.  **Run the executable:**
    ```bash
    ./RollingLuck
    ```

## ⌨️ Controls
* **[Enter(Return)]:** Roll the dice 


---
*Developed as a study of Computer Graphics and Application Lifecycle Management.*
