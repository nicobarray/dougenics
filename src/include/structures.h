#ifndef STRUCTURES_H_
# define STRUCTURES_H_

typedef struct rondoudou
{
	SDL_Rect *position;
} s_rondoudou;

typedef struct list
{
	struct list *next;
	void *body;
} s_list;
#endif /* !STRUCTURES_H_ */
