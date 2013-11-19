WAV-Trigger-Control
===================

Serial Remote Control and Firmware Update Utility for the WAV Trigger

This application relies on JUCE, the cross-platform C++ library by Julian Storer. The related "Introjucer"
app is used to manage the project and generate project files for 3 build environments: Visual Studio, X-Code
and Linux make. To build this project, you should clone the JUCE library from github into a \JUCE folder off
your root directory. Build the Introjucer app (included in the JUCE repository), run it and open the .jucer
file in this folder.