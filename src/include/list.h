#ifndef LIST_H_
# define LIST_H_

# include "game.h"

s_list *remove_at_list(int id, s_list *list);
s_list *get_list(int id, s_list *list);
s_list *add_list(s_list *list, s_body *body);

#endif /* !LIST_H_ */
