#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>

void engine_run();
int handle_input();
void render(int time);
void precal_sin();
void render_plasma(int time);
void engine_clean_up();
void engine_init();

#endif
