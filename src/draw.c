#include <game.h>

void draw_splash(SDL_Surface **surfaces)
{
    // Fill the screen in RED
	SDL_FillRect(surfaces[0], NULL, 0xFF0000);
}

void draw_menu(SDL_Surface **surfaces)
{
    // Fill the screen in YELLOW
	SDL_FillRect(surfaces[0], NULL, 0xFFFF00);
}

void draw_game(SDL_Surface **surfaces, s_list *bodies)
{
	s_list *tmp_bodies = bodies;
	SDL_Surface *to_draw = NULL;
    SDL_Rect position = { 0, 0, 0, 0};

	SDL_BlitSurface(surfaces[BKG], NULL, surfaces[SCREEN], &position);
	
	tmp_bodies = bodies;
	while (tmp_bodies)
	{
		switch (tmp_bodies->body->type)
		{
			case RONDOUDOU:
				to_draw = surfaces[RDD];
				break;
			default:
				break;
		}

		
        position.x = tmp_bodies->body->position.x;
		position.y = tmp_bodies->body->position.y;

		SDL_BlitSurface(to_draw, NULL, surfaces[SCREEN], &position);
		tmp_bodies = tmp_bodies->next;
	}
}

void draw_pause(SDL_Surface **surfaces)
{
    //Fill the screen of GREEN-BLUE
	SDL_FillRect(surfaces[0], NULL, 0x00FFFF);
}

void draw(SDL_Surface **surfaces, s_list *bodies, enum e_game_state game_state)
{
	SDL_FillRect(surfaces[SCREEN], NULL, 0x000000);
	switch (game_state)
	{
		case SPLASH:
			draw_splash(surfaces);
			break;
		case MENU:
			draw_menu(surfaces);
			break;
		case GAME:
			draw_game(surfaces, bodies);
			break;
		case PAUSE:
			draw_pause(surfaces);
			break;
		default:
			break;
	}
	SDL_Flip(surfaces[0]);
}
