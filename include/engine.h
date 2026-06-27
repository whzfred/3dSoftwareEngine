#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include "object.h"

void engine_run();
int handle_input();
void render(int time);
void render_plasma(int time);
void render_cube();
void render_object(Object* obj);
void engine_clean_up();
void engine_init();
#endif
