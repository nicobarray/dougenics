#ifndef GAME_H_
# define GAME_H_

// includes

# include <stdlib.h>
# include <stdio.h>

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# include "structures.h"

// defines
# define WIDTH  800
# define FORMAT 16 / 9
# define HEIGHT 600
# define FPS    60

# define SURFACE_COUNT 2

// types declaration

enum e_game_state
{
    SPLASH = 0,
    MENU,
    GAME,
    PAUSE
};

// methods declarations

int initialize(SDL_Surface **surface);
int load_content(SDL_Surface **surface);
int unload_content(SDL_Surface **surface);

void update(enum e_game_state *game_state, int *end);
void draw(enum e_game_state game_state, SDL_Surface **surface);

void update_splash(SDL_Event event, enum e_game_state *game_state);
void draw_splash(SDL_Surface **surface);

void update_menu(SDL_Event event, enum e_game_state *game_state, int *end);
void draw_menu(SDL_Surface **surface);

void update_game(SDL_Event event, enum e_game_state *game_state, int *end);
void draw_game(SDL_Surface **surface);

void update_pause(SDL_Event, enum e_game_state *game_state);
void draw_pause(SDL_Surface **surface);

short unsigned int quit(short unsigned int code);

#endif /* !GAME_H_ */
