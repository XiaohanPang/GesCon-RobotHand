Gesture Controlled Robot Hand

Development environment
In this project I used macOS overall,  Fusion & Inventor for CAD designs and Visual Studio Code for Python, and Arduino IDE for Arduino coding. 

Hardware design
My hardware is mainly splitted into two parts, electronic circuit and CAD. 
For the electronic circuit you need: 
DM-S0090D continuous servo motor * 5
Arduino Nano
Breadboard (optional) + Jumper Wires (many & different colors)
USB cable for Arduino connection. 
Robot hand CAD design (3D printed)
Fishing line (or any durable line)
Then, to connect it, you will need jumper wires. Connect like this:
Orange (Signal) → D2 on Arduino Nano
Red (VCC) → 3.3V 
Brown/Black (GND) → GND 
This is for one finger, to extend this do something like:
(image)

And for CAD designs you will find it at the bottom as .stl files. 
To link the line with the finger, do this: 
You will have an adopter in the Cad design so that your line connected through the finger will go up or down depending which way it spins. Every finger will have one long line which will be folded so it looks like two. And when you go through the finger itself, remember to have one line up and one line down. 

Arduino Software design
I used Arduino IDE to run the code. In Arduino IDE you can only program with the language C++. In this project I will use it to receive data from the Python code about my hand gesture and send a signal to the Arduino board. Don’t forget to choose the right port(your arduino board) and type(in this case, Arduino Nano). 
Python Software design
I used a Python code to create a webcam so that it could capture my hand gesture and then send a signal to Arduino IDE. The signal is like letters, C for Close hand and O for Open hand. These was originally turning right or left which is related to the direction of the servo motor. 

Demo operation
You will find the video on YouTube: xxx.xxx

Known issues
You will have to run the Arduino code before the Python code. Then you will have to close the window with the port otherwise it will say the port is busy. 
This type of continuous servo motor we are using will turn infinitely so if we’ll have to use a more complicated code to send commands. 
It is better to use standard servo motors, then code will be simpler and the function will be correct.

Contributors
