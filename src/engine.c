#include <SDL3/SDL.h>

void engine();
int handle_input();


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "3D software Engine",
        800,
        600,
        SDL_WINDOW_RESIZABLE
    );

	engine();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


void engine()
{
	int running = 1;
	
	while (running) 
	{
		running = !handle_input();
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

