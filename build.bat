@echo off

gcc engine/*.c games/*.c games/lightsOut/scenes/*.c games/lightsOut/*.c -o game.exe

game.exe