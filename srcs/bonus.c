#include "../dream_princesses.h"

void	counter_bonus(t_vars *vars)
{
	const char		*str = ft_itoa(vars->counter);

	if (!str)
		__exit__(NULL, vars, FAILURE);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xFF0000, (char *)str);
	free((char *)str);
}
