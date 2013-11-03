#include <game.h>

SDL_Surface *screen = NULL;
SDL_Surface **surfaces = NULL;

int initialize(void)
{
	int flags = IMG_INIT_PNG;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("SDL_Init : %s\n", SDL_GetError());
		return 0;
	}

	if ((IMG_Init(flags) & flags) != flags)
	{
		printf("IMG_Init : %s\n", IMG_GetError());
		return 0;
	}

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

	if (!screen)
	{
		printf("SDL_SetVideoMode : %s\n", SDL_GetError());
		return 0; 
	}

	return 1;
}

int load_content(void)
{
	surfaces[0] = IMG_Load("assets/img/background.png");
	surfaces[1] = IMG_Load("assets/img/rondoudou.png");
	return 1;
}

int unload_content(void)
{
	for (int i = 0; i < SURFACE_COUNT; i++)
		SDL_FreeSurface(surfaces[i]);

	free(surfaces);

	return 1;
}

short unsigned int quit(short unsigned int code)
{
	SDL_Quit();
	IMG_Quit();
	return code;
}

int main(void)
{
	SDL_Surface       *surface = NULL;
	enum e_game_state game_state = SPLASH;
	int               end = 0;
	SDL_Event	  event;

	if (!(surface = malloc(sizeof (SDL_Surface) * SURFACE_COUNT)))
		return quit(1);

	if (!initialize())
		return quit(1);

	if (!load_content())
		return quit(2);

	while (!end)
	{
		SDL_PollEvent(&event);
		end = event.type == SDL_QUIT ? 1 : 0;
		update(&game_state, &end);
		draw(game_state);
	}

	if (!unload_content())
		return quit(3);
	return 0;
}
