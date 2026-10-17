# Arduino Circular Queue Implementation

## Project Overview

This project was developed as part of the **EE4047 Embedded Software** module at the University of Limerick.

The program demonstrates the use of circular queues in C using the Arduino environment. It performs several queue operations, including inserting, removing, swapping, and reversing elements, as well as calculating the number of days between two dates.

## Technologies Used

- C / Arduino
- Arduino IDE
- Arduino Serial Monitor
- Wokwi Simulator

## Features

- **Enqueue and Dequeue:** Insert and remove elements from circular queues.
- **Front and Rear Retrieval:** Access the first and last elements without removing them.
- **Queue Swapping:** Exchange elements between two queues.
- **Queue Reversal:** Create a third queue containing elements in reverse order.
- **Empty Queue Detection:** Check whether a queue contains any elements.
- **Date Calculation:** Calculate the number of days between two dates.
- **Serial Monitor Output:** Display queue operations and results.

## My Contributions

The basic circular queue implementation was provided as starter code for the assignment.

I extended the program by completing the required tasks, including:

- Implementing the `peekRear()` function.
- Creating and manipulating three queues.
- Swapping queue contents using temporary storage.
- Reversing queue elements.
- Displaying the front and rear elements.
- Checking whether a queue is empty.
- Implementing date calculations.

## Running the Project

1. Download or clone this repository.
2. Open `Arduino-Circular-Queue.ino` using Arduino IDE.
3. Select a compatible Arduino board.
4. Compile and upload the program, or test it using a compatible simulator.
5. Open the Serial Monitor at **9600 baud** to view the output.

## What I Learned

This assignment helped me practise C programming, working with arrays, manipulating circular queues, and understanding how data structures operate in embedded software.

It also gave me experience testing programs and examining their output using the Arduino Serial Monitor.

## Acknowledgements

The original circular queue implementation was provided as starter code for the EE4047 Embedded Software module at the University of Limerick. The additional functionality was implemented as part of the assignment requirements.