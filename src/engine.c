#include <SDL3/SDL.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "engine.h"
#include "fastmath.h"
#include "render.h"
#include "config.h"
#include "object.h"
#include "projection.h"
#include "camera.h"
#include "rasterizer.h"

#define PI 3.14159265358979323846f

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;

static int fps = 0;

Vertex cube_vertices[] =
{
    {-1.0f, -1.0f, -1.0f},
    { 1.0f, -1.0f, -1.0f},
    { 1.0f,  1.0f, -1.0f},
    {-1.0f,  1.0f, -1.0f},
    {-1.0f, -1.0f, 1.0f},
    { 1.0f, -1.0f, 1.0f},
    { 1.0f,  1.0f, 1.0f},
    {-1.0f,  1.0f, 1.0f}
};

Face cube_faces[] =
{
    {0,1,2},
    {0,2,3},
    {5,4,7},
    {5,7,6},
    {4,0,3},
    {4,3,7},
    {1,5,6},
    {1,6,2},
    {3,2,6},
    {3,6,7},
    {4,5,1},
    {4,1,0}
};

Object cube =
{
    cube_vertices,
    8,
    cube_faces,
    12
};


int main(int argc, char* argv[])
{
    fastmath_precalc_sin();
	engine_init();
	engine_run();
	engine_clean_up();
	printf("FPS: %d\n", fps);
    return 0;
}

void engine_init()
{
	SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "3D software Engine",
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(window, NULL);
	
	texture = SDL_CreateTexture
	(
        renderer,
        SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH,
        HEIGHT
    );	
}
void engine_clean_up()
{
	printf("engine_clean_up\n");
	SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void engine_run()
{
	int running = 1;
	int time = 0;
	int frames = 0;
	Uint64 last_time = SDL_GetTicks();
	
	while (running) 
	{
		running = !handle_input();
		render(time);
		time++;
		frames++;
		
	    Uint64 now = SDL_GetTicks();
	
		if (now - last_time >= 1000)
		{
			fps = frames;
			frames = 0;
			last_time = now;
		}
	}
}

int handle_input()
{
	SDL_Event event;
	int should_exit = 0;
	while (SDL_PollEvent(&event)) 
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			should_exit = 1;
		}

		if (event.type == SDL_EVENT_KEY_DOWN) 
		{
			if (event.key.key == SDLK_SPACE)	
			{
				should_exit = 1;
			}
		}
	}
	return should_exit;
}

void render(int time)
{
	//render_plasma(time);
	render_cube();

    SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(Uint32));

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void render_plasma(int time)
{
	for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
			int v = (fastmath_sin(x % 360) + fastmath_sin(y % 360) + fastmath_sin((x + y + time) % 360));
			v = v + 768; 
            int c = (v * 255) >> 11;
            render_put_pixel(x, y, c, 255-c, c/2, 255);
        }
    }
}

void render_cube()
{
	render_object(&cube);
}




