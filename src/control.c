#include "control.h"

void select(s_list *bodies, SDL_Event event)
{
	static SDL_Rect pos_mouse = { 0, 0, 10, 10 };
	pos_mouse.x = event.button.x;
	pos_mouse.y = event.button.y;

	s_list *tmp_bodies = bodies;
	while (tmp_bodies)
	{
		if ()
		tmp_bodies = tmp_bodies->next;
	}
}

void control(s_list *bodies, SDL_Event event)
{
	select();
}
