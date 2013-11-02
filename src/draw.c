#include <game.h>

void draw_splash(SDL_Surface **surface)
{
    SDL_FillRect(surface[0], NULL, 0xFF0000);
}

void draw_menu(SDL_Surface **surface)
{
    SDL_FillRect(surface[0], NULL, 0xFFFF00);
}

void draw_game(SDL_Surface **surface)
{
    SDL_FillRect(surface[0], NULL, 0xFF00FF);
}

void draw_pause(SDL_Surface **surface)
{
    SDL_FillRect(surface[0], NULL, 0x00FFFF);
}

void draw(enum e_game_state game_state, SDL_Surface **surface)
{
    SDL_FillRect(surface[0], NULL, 0x000000);
    switch (game_state)
    {
        case SPLASH:
            draw_splash(surface);
            break;
        case MENU:
            draw_menu(surface);
            break;
        case GAME:
            draw_game(surface);
            break;
        case PAUSE:
            draw_pause(surface);
            break;
        default:
            break;
    }
    SDL_Flip(surface[0]);
}

