#include <windows.h>
#include <stdio.h>

#include "timer.h"

static DWORD startTime;

void timer_init() {
    // El sistema crecerá y aqui se manejaran los ticks y una mejor gestion de FPS 
    startTime = GetTickCount();
}

void timer_reset() {
    startTime = GetTickCount();
}

const char* timer_get_time() {
    static char timeText[32];
    unsigned long elapsed = timer_get_elapsed_ms();

    int totalSeconds = elapsed / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    snprintf(timeText, sizeof(timeText), "TIEMPO: %02d:%02d", minutes, seconds);

    return timeText;
}

unsigned long timer_get_elapsed_ms() {
  return GetTickCount() - startTime;
}

void timer_update() {
    // Por ahora la configuración base son ~10 FPS
    Sleep(100);
}