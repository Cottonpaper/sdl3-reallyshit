#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <math.h>
#include <stdio.h>

int
main( void )
{
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Vertex vert[3];
	bool keep_running = true;

	SDL_SetAppMetadata("shit app", "v1", "com.poop");
	if( SDL_InitSubSystem(SDL_INIT_VIDEO) == 0 )
	{
		printf("VIDEO SUBSYSTEM INIT FAILED: %s\n", SDL_GetError());
		SDL_ClearError();
		return -1;
	}

	window = SDL_CreateWindow("shit app", 1920, 1080, SDL_WINDOW_FULLSCREEN);
	render = SDL_CreateRenderer(window, NULL);

	vert[0].position.x = 1000;
	vert[0].position.y = 200;
	vert[0].color.r = 1.0;
	vert[0].color.g = 0.0;
	vert[0].color.b = 0.0;
	vert[0].color.a = 1.0;

	vert[1].position.x = 1600;
	vert[1].position.y = 600;
	vert[1].color.r = 1.0;
	vert[1].color.g = 0.0;
	vert[1].color.b = 0.0;
	vert[1].color.a = 1.0;

	vert[2].position.x = 1200;
	vert[2].position.y = 1000;
	vert[2].color.r = 1.0;
	vert[2].color.g = 0.0;
	vert[2].color.b = 0.0;
	vert[2].color.a = 1.0;
	
	float angle = M_PI / 4;
	float cx = (1000 + 1600 + 1200) / 3.0f;
	float cy = (200 + 600 + 1000) / 3.0f;

	while(keep_running)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_EVENT_QUIT) keep_running = false;
		}

		SDL_SetRenderDrawColor(render, 36, 36, 36, 255);
		SDL_RenderClear(render);

		SDL_RenderGeometry(render, NULL, vert, 3, NULL, 0);

		for(int i = 0; i < 3; i++)
		{
			float x = vert[i].position.x;
			float y = vert[i].position.y;

			vert[i].position.x = cx + (x - cx) * cos(angle) - (y - cy) * sin(angle);
			vert[i].position.y = cy + (x - cx) * sin(angle) + (y - cy) * cos(angle);
		}

		SDL_RenderPresent(render);

		SDL_Delay(500);
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
