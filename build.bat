@echo off

gcc engine/*.c games/*.c games/dungeon/scenes/*.c games/dungeon/*.c -o game.exe

game.exe