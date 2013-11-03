#include <game.h>

void draw_splash()
{
	SDL_FillRect(surfaces[0], NULL, 0xFF0000);
}

void draw_menu()
{
	SDL_FillRect(surfaces[0], NULL, 0xFFFF00);
}

void draw_game(s_list *bodies)
{
	SDL_FIllRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	s_list *tmp_bodies = bodies;
	SDL_Rect position = { 0, 0, 0, 0 };
	SDL_Surface *to_draw = NULL;

	while (tmp_bodies->body->type != BACKGROUND)
		tmp_bodies = tmp_bodies->next;
	SDL_BlitSurface(surface[0], NULL, screen, position);
	
	tmp_bodies = bodies;
	while (tmp_bodies != NULL)
	{
		switch (tmp_bodies->body->type)
		{
			case RONDOUDOU:
				to_draw = surfaces[1];
				break;
			default:
				break;
		}
		position.x = tmp_bodies->body->position.x;
		position.y = tmp_bodies->body->position.y;

		SDL_BlitSurface(to_draw, NULL, screen, position);
		tmp_bodies = tmp_bodies->next;
	}
}

void draw_pause()
{
	SDL_FillRect(surfaces[0], NULL, 0x00FFFF);
}

void draw(enum e_game_state game_state)
{
	SDL_FillRect(surfaces[0], NULL, 0x000000);
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
	SDL_Flip(surfaces[0]);
}
