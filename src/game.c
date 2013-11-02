#include <game.h>

static SDL_Surface *screen = NULL;
static s_list	   *surfaces = NULL;

int initialize(s_list **surfaces)
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

int load_content(s_list **surfaces)
{
	surface = surface;
    return 1;
}

int unload_content(s_list **surfaces)
{
        while
	SDL_FreeSurface(surfaces[i]);

    free(*surface);
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

	if (!(surface = malloc(sizeof (SDL_Surface) * SURFACE_COUNT)))
		return quit(1);

	if (!initialize(&surface))
		return quit(1);

	if (!load_content(&surface))
		return quit(2);

	while (!end)
	{
		update(&game_state, &end);
		draw(game_state, &surface);
	}

	if (!unload_content(&surface))
		return quit(3);
	return 0;
}

