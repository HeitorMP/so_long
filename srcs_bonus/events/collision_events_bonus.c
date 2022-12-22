/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:08:55 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:08:58 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_collision_exit(t_root *root)
{
	if (collision(&root->hero, &root->exit))
	{
		root->flags.is_game_over = 1;
		root->flags.is_game_over_fail = 0;
	}
}

void	check_collision_patrol(t_root *root)
{
	if (collision(&root->hero, &root->patrol))
	{
		root->flags.is_game_over = 1;
		root->flags.is_game_over_fail = 1;
	}
}

void	check_collision_events(t_root *root)
{
	check_collision_exit(root);
	check_collision_patrol(root);
}
