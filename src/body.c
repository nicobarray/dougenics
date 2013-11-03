#include "body.h"

s_list *new_body(s_list *bodies, enum type type, SDL_Rect position)
{
	s_body *new_body = malloc(sizeof (s_body));
	new_body->position = position;
	new_body->type = type;
	bodies = add_list(bodies, new_body);

	return bodies;
}
