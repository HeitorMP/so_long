/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:49:12 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/19 19:49:13 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_over_sucess(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, 32, 16711680, \
		"Congratulations!");
	return (0);
}
