#include "lem_in.h"
//(create tmp variable to store and end, check input when passed);
int					duplicate(t_in *stack, char *s)
{
	//t_lst *temp;

	while (stack)
	{
		/* temp = stack->right;
		while (temp)
		{
			if (stack->data == temp->data)
				return (1);
			temp = temp->right;
		} */
        if (!ft_strcmp(stack->data, s))
            return (1);
		stack = stack->next;
	}
	return (0);
}