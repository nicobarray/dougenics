#include <game.h>

static SDL_Surface **surfaces = NULL;
static s_list *bodies = NULL;

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

	surfaces[0] = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

	if (!surfaces[0])
	{
		printf("SDL_SetVideoMode : %s\n", SDL_GetError());
		return 0; 
	}

    // Initialize bodies here 

	return 1;
}

int load_content(void)
{
	surfaces[BKG] = IMG_Load("assets/img/background.png");
	surfaces[RDD] = IMG_Load("assets/img/rondoudou.png");
    surfaces[GRD] = IMG_Load("assets/img/ground.png");
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
	enum e_game_state game_state = GAME;
	int               end = 0;
	SDL_Event	  event;

	if (!(surfaces = malloc(sizeof (SDL_Surface*) * SURFACE_COUNT)))
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
		draw(surfaces, bodies, game_state);
	}

	if (!unload_content())
		return quit(3);
	return 0;
}
