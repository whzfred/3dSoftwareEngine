#include <SDL3/SDL.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define PI 3.14159265358979323846f

void engine();
int handle_input();
void render(int time);
void put_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void precal_sin();
void renderPlasma(int time);

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

static int sin_table[360];

int main(int argc, char* argv[])
{
    precal_sin();
	SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "3D software Engine",
        1024,
        768,
        SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(window, NULL);
	
	
	engine();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


void engine()
{
	int running = 1;
	int time = 0;
	
	while (running) 
	{
		running = !handle_input();
		render(time);
		time++;
	}
	return;
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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
	
	renderPlasma(time);
	
    SDL_RenderPresent(renderer);
}

void put_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderPoint(renderer, x, y);
}

void precal_sin()
{
	for (int i = 0; i < 360; i++)
    {
        
	    sin_table[i] = (int)(sin(i * (PI / 180.0)) * 256.0);
    }
} 

void renderPlasma(int time)
{
	for (int x = 0; x < 1024; x++)
    {
        for (int y = 0; y < 768; y++)
        {
			int v = (sin_table[x % 360] + sin_table[y % 360] + sin_table[(x + y + time) % 360]);
			v = v + 768; 
            int c = (v * 255) >> 11;
            put_pixel(x, y, c, 255-c, c/2, 255);
        }
    }
}