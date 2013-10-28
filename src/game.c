#include <game.h>

int initialize(SDL_Surface ***surface)
{
    if (!(*surface = malloc(sizeof (SDL_Surface) * SURFACE_COUNT)))
        return 0;
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        printf("SDL_Init : %s\n", SDL_GetError());
        return 0;
    }
 
    *surface[0] = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

    if (!*surface[0])
    {
        printf("SDL_SetVideoMode : %s\n", SDL_GetError());
        return 0; 
    }

    return 1;
}

int load_content(SDL_Surface ***surface)
{
    surface = surface;
    return 1;
}

int unload_content(SDL_Surface ***surface)
{
    for (int i = 0; i < SURFACE_COUNT; ++i)
        SDL_FreeSurface(*surface[i]);
    return 1;
}

short unsigned int quit(short unsigned int code)
{
    SDL_Quit();
    return code;
}

int main(void)
{
    static SDL_Surface       **surface = NULL;
    static enum e_game_state game_state = SPLASH;
    static int               end = 0;
    
    if (!initialize(&surface))
        quit(1);

    if (!load_content(&surface))
        quit(2);

    while (!end)
    {
        update(&game_state, &end);
        draw(game_state, &surface);
    }

    if (!unload_content(&surface))
        quit(3);
    return 0;
}

