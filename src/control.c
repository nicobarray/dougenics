#include "control.h"

static SDL_Rect pos_mouse = { 0, 0, 10, 10 };

// Need functions : collision and move_to

void select(s_list *bodies, SDL_Event event)
{
	pos_mouse.x = event.button.x;
	pos_mouse.y = event.button.y;

	s_list *tmp_bodies = bodies;
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		while (tmp_bodies)
		{
			if (tmp_bodies->body->type == RONDOUDOU && 
			collision(pos_mouse, tmp_bodies->body->position &&
			event.button.button == SDL_BUTTON_LEFT))
				tmp_bodies->body->select = 1;
			else
				tmp->body->select = 0;
			tmp_bodies = tmp_bodies->next;
		}
	}
}

void control(s_list *bodies, SDL_Event event)
{
	select(bodies, event);

	s_list *tmp_bodies = bodies;
	while (tmp_bodies)
	{
		if (tmp_bodies->body->select &&
				event.type == SDL_MOUSEBUTTONDOWN &&
				event.button.button == SDL_BUTTON_RIGHT)
			move_to(tmp_bodies->body-position, pos_mouse);
		tmp_bodies = tmp_bodies->next;
	}
}

int collision(SDL_Rect *pos1, SDL_Rect *pos2)
{
	float distance = sqrt(pow(pos1->off_pos.x - pos2->off_pos.x, 2 +
			      pow(pos1->off_pos.y - pos2->off_pos.y, 2)));

	if (distance < radius1 + radius2)
		return 1;
	else
		return 0;
}
