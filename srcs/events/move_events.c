/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:09 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:09:11 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_move_wall(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == '1')
			return (0);
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == '1')
			return (0);
	}
	return (1);
}

int	check_move_exit(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == 'E')
			return (0);
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == 'E')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == 'E')
			return (0);
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == 'E')
			return (0);
	}
	return (1);
}

void	check_move_collect(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == 'C')
			root->counters.count_collect--;
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == 'C')
			root->counters.count_collect--;
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == 'C')
			root->counters.count_collect--;
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == 'C')
			root->counters.count_collect--;
	}
}

void	check_move_sprite(t_root *root, int direction)
{
	if (check_move_wall(root, direction))
	{
		if (check_move_exit(root, direction))
		{
			root->counters.count_move++;
			ft_printf("Moves %d\n", root->counters.count_move);
			check_move_collect(root, direction);
			move_sprite(root, &root->hero, '0', direction);
		}
	}
}
