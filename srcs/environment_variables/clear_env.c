
#include "env.h"

void	clear_env(void)
{
	t_env	*envp;
	t_env	*temp;

	envp = *get_t_env();
	while (envp)
	{
		temp = envp;
		envp = envp->next;
		del(temp);
	}
	free_split(env()[0]);
}