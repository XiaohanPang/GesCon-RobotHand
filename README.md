# **Gesture Controlled Robot Hand**

## **Development Environment**
In this project, I used macOS overall, Fusion & Inventor for CAD designs, Visual Studio Code for Python, and Arduino IDE for Arduino coding. 

## **Hardware Design**
My hardware is mainly split into two parts: electronic circuit and CAD.

### **Electronic Circuit**
For the electronic circuit, you need: 
  - DM-S0090D continuous servo motor (x5)
  - Arduino Nano
  - Breadboard (optional) + Jumper Wires (many & different colors)
  - USB cable for Arduino connection
  - Robot hand CAD design (3D printed)
  - Fishing line (or any durable line)

To connect the circuit, you will need jumper wires. Connect them like this:
**Orange (Signal)** → D2 on Arduino Nano
**Red (VCC)** → 3.3V
**Brown/Black (GND)** → GND
This is for one finger. To extend this, do something like:
*(Add your image or diagram here)*

### **CAD Design**
You will find the CAD designs at the bottom as `.stl` files. 

To link the line with the finger:
- You will have an **adapter** in the CAD design so that your line, connected through the finger, will go up or down *depending on which way it spins*. 
- Every finger will have one long line folded to look like two. When threading through the finger, ensure:
  - One line goes up
  - One line goes down

## **Arduino Software Design**
I used Arduino IDE to run the code. In Arduino IDE, you can *only* program with the language **C++**. In this project the Arduino receives data from the Python code about my hand gesture and then sends signals to the board.** Don’t forget** to choose the right **port (your Arduino board)** and **type (in this case, Arduino Nano)**.

## **Python Software Design**
I used Python code to create a webcam that captures my hand gestures which then send signals to Arduino IDE. 

The signals are letters, **C** for "Close hand" and **O** for "Open hand."

These signals were originally for turning right or left, corresponding to the servo motor's direction.

## **Demo Operation**
You can find the demo video on YouTube: [xxx.xxx](#)

## **Known Issues**
- You need to run the Arduino code before the Python code.
- You must close the port window; otherwise, it will say "port is busy."
- The continuous servo motor used here turns infinitely. A more complicated code is required to send commands.
  - It’s better to use standard servo motors for simpler and more accurate functionality.

## **Contributors**
*(Add contributor names or acknowledgements here)*
