#include <game.h>

void update_splash(SDL_Event event, enum e_game_state *game_state)
{
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_RETURN)
             *game_state = MENU;
}

void update_menu(SDL_Event event, enum e_game_state *game_state, int *end)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_RETURN:
                *game_state = GAME;
            break;
            case SDLK_ESCAPE:
                *end = 1;
            break;
            default:
            break;
        }
    }
}

void update_game(SDL_Event event, enum e_game_state *game_state, int *end)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_RETURN:
                *game_state = PAUSE;
            break;
            case SDLK_ESCAPE:
                *end = 1;
            break;
            default:
            break;
        }
    }
}

void update_pause(SDL_Event event, enum e_game_state *game_state)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_RETURN:
                *game_state = GAME;
            break;
            case SDLK_ESCAPE:
                *game_state = MENU;
            break;
            default:
            break;
        }
    }
}

void update(enum e_game_state *game_state, int *end)
{
    static SDL_Event event;
    SDL_PollEvent(&event);

    switch (*game_state)
    {
        case SPLASH:
            update_splash(event, game_state);
            break;
        case MENU:
            update_menu(event, game_state, end);
            break;
        case GAME:
            update_game(event, game_state, end);
            break;
        case PAUSE:
            update_pause(event, game_state);
            break;
        default:
            break;
    }
}
