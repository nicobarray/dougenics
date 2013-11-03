#ifndef STRUCTURES_H_
# define STRUCTURES_H_

enum type
{
	RONDOUDOU,
	BACKGROUND
};

typedef struct body
{
	SDL_Rect *position;
	enum type *type;
} s_body;



typedef struct list
{
	int id;
	struct list *next;
	s_body *body;
} s_list;

#endif /* !STRUCTURES_H_ */
