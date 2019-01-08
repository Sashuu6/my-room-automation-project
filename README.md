# my-room-automation-project
## Introduction
This repository contains the code and instructions to implement home automation using raspberry pi zero W and a 2-channel relay. I selected to channel relay to automate tubelight and bulb.

## Hardware Requirements

1. Raspberry Pi zero W
2. n - Relay (I used 2 - channel relay)
3. Some wires

## Software Requirements

1. Particle.io account
2. IFTTT app

## Steps

1. Goto particle.io.
2. Goto console.
3. Click on webIDE present on the left side of the page.
4. Paste the code present in /code/main_program.ino to the WebIDE.
5. Save and compile the code and check for errors.
6. Install particle.io in your raspberry pi zero w.
7. Flash the code to the pi from WebIDE.
8. Connect the D0 of the pi to the respective relays.
9. Setup IFTTT to trigger the commands.

The instructions are for expert users, I will be writing a detailed blog on how to implement this project step by step.

## To-Do

1. Built case
2. Add TRIAC support for controlling fan