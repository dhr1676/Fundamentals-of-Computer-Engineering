# HWK2

## Question 4 (3 pt.)
Create a new class Square as a child of class Rectangle. Modify the main() function to instantiate one more shape object of type Square, add it to array shapes, and print its area within the for loop.
The call to instantiate a Square object should take only one float value as an argument, specifying the length of a side of the square. Show the code for files Square.cc, Square.h, and main.cc.

Create a ZIP file with the complete source code for this question, and upload it in a file named q4.zip. Include all source files in the Shapes project, even those that were not modified, and omit any object or
executable files.

## Question 5 (open-ended, +2 pt.)
Extend class Shape with a virtual function void Shape::Draw(void) that draws the shape on the screen. This function can be optionally overridden by any child class of Shape. For example, a rectangle of width 8 and height 4 would draw the following figure:
Shape 'rect1'
Width = 8
Height = 4

\* * * * * * * * 

\*             * 

\*             * 

\* * * * * * * * 

## Compile and run
1. Compile: make all

2. Run: ./main
