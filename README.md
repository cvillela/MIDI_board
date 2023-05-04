# MIDI Board Project

![MIDI Board](https://i.ibb.co/yQ3sjyq/midi-board.jpg)


This repository contains the C++ code for an Arduino implementation of a MIDI board. The MIDI board is designed for music production and live looping and can be used as MIDI inputs for any digital audio workstation. The board consists of an Arduino board, a button grid, two sliders, three knobs and a LCD screen.

In addition to the basic MIDI input functionality, the MIDI board also includes an intelligent scale module. The button grid representing piano notes can be set to represent Greek Modes, octaves and root notes that can be changed via controls and the LCD screen for a more intuitive Music Creation process.

## Getting Started

To get started, you will need an Arduino board and the necessary components to build the MIDI board.

Setup the MIDI board I/O as follows:

![MIDI Schematics](https://i.ibb.co/vJwyzVv/midi-schematics.jpg)

Once you have the required components, you can upload the code to your Arduino board using the Arduino IDE. The code is located in the `midi_board.ino` file. You will need to install the necessary libraries before uploading the code.

Third party software is also required for the correct MIDI input management to the system:
 - loopMIDI is a software used for creating virtual MIDI ports on a Windows operating system. It allows you to create and manage virtual MIDI ports that can be used to connect MIDI software and hardware within your computer. By using loopMIDI, you can create a virtual MIDI port that acts as a bridge between two or more MIDI applications, allowing them to communicate and share MIDI data without requiring any physical MIDI cables. 
 - Hairless MIDI is a software tool that allows you to transmit and receive MIDI messages between your computer and MIDI devices. It is often used in conjunction with an Arduino board or other microcontroller, allowing you to create custom MIDI devices that can be controlled by your computer or used to control your computer. Hairless MIDI works by creating a virtual serial port that communicates with the MIDI input and output ports on your computer. You can then use Hairless MIDI to send and receive MIDI messages to and from your MIDI devices. 

Both softwares must be installed and set: the signal coming from the USB must be read as a MIDI input by the loopMIDI software, and later passed as a MIDI input to hairless MIDI, which can be used to transmit the MIDI signal to a Digital Audio Workstation such as Ableton Live.

## Usage

To use the MIDI board, connect it to your computer using a USB cable. Set the MIDI port using loopMIDI and HairlessMIDI. The board will appear as a MIDI device in your digital audio workstation. You can then use the button grid, sliders, and knobs to control various parameters in your music production software.

![loop_midi_hairless](https://i.ibb.co/fQdTFTq/loop-bridge.jpg)

To change the Scale (Greek mode), octave and root note of the button grid, use the controls and the LCD screen. The current mode will be displayed on the LCD screen.

## Contributing

Contributions to this project are welcome. To contribute, fork the repository and create a pull request with your changes.

## Acknowledgments

This project was inspired by the need for a compact and cheap and versatile MIDI controller for music production and live looping. Special thanks to the Arduino community for providing the necessary resources and libraries to make this project possible.The project was designed in collaboration with Ângelo Barbosa as a project for the Embedded Systems Laboratory course at the University of Campinas.

## Demo Video

[MIDI Demo](https://drive.google.com/file/d/1DgK937WFLZGRN2ylbOXcIjHM-X9WzkjP/view?resourcekey)
