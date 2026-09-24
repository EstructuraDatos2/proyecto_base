#ifndef TIMER_H
#define TIMER_H

void timer_init();
void timer_update();

void timer_reset();
unsigned long timer_get_elapsed_ms();

const char* timer_get_time();

#endif