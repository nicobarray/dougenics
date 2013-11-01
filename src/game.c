#include <game.h>

int initialize(SDL_Surface ***surface)
{
    int flags = IMG_INIT_PNG;

    for (int i = 0; i < SURFACE_COUNT; ++i)
    {
        surface[i] = malloc(sizeof (SDL_Surface));
    }
 
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

    *surface[0] = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);
    *surface[1] = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
    
    if (!*surface[0])
    {
        printf("SDL_SetVideoMode : %s\n", SDL_GetError());
        return 0; 
    }

    return 1;
}

static SDL_Surface *load_img(char *asset)
{
    SDL_Surface *img = NULL;
    
    if (!(img = IMG_Load(asset)))
    {
        printf("load_content : %s\n", IMG_GetError());
        exit(quit(1));
    }
    return img;
}

int load_content(SDL_Surface ***surface)
{
    SDL_Surface *img = load_img("assets/img/background.png");
    *surface[1] = img;
    return 1;
}

int unload_content(SDL_Surface ***surface)
{
    for (int i = 0; i < SURFACE_COUNT; ++i)
        SDL_FreeSurface(*surface[i]);

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
    SDL_Surface       **surface = NULL;
    enum e_game_state game_state = SPLASH;
    int               end = 0;

    printf("++ array\n");
    if (!(surface = malloc(sizeof (SDL_Surface) * SURFACE_COUNT)))
        return quit(1);
    printf("-- array\n");
    printf("++ init\n");
    if (!initialize(&surface))
        return quit(1);

    printf("-- init\n");
    printf("++ load\n");
    if (!load_content(&surface))
        return quit(2);

    printf("-- load\n");
    printf("++ loop\n");
    while (!end)
    {
        printf("++ update\n");
        update(&game_state, &end);
        printf("-- update\n");
        printf("++ draw\n");
        draw(game_state, &surface);
        printf("-- draw\n");
    }
    printf("-- loop\n");
    printf("++ unload\n");

    if (!unload_content(&surface))
        return quit(3);
    printf("-- unload\n");
    return 0;
}

