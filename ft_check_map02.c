/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:50:02 by magonzal          #+#    #+#             */
/*   Updated: 2023/06/01 14:34:50 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	aux(char	**matrix, int i, int j)
{
	while (matrix[++i])
	{
		j = -1;
		if (ft_strlen(matrix[i]) > 3)
		{
			ft_free_matrix(matrix);
			return (0);
		}
		while (matrix[i][++j])
		{
			if (ft_isdigit(matrix[i][j]) == 0)
			{
				ft_free_matrix(matrix);
				return (0);
			}
		}
	}
	if (i != 3)
	{
		ft_free_matrix(matrix);
		return (0);
	}
	return (1);
}

void	ft_check_map_floor(t_all all, int i, int j)
{
	if (i == 0 || j == 0 || j == (int)(ft_strlen(all.mapest->map[i]) - 1)
	|| !all.mapest->map[i + 1])
		ft_error("map open");
	if (!all.mapest->map[i + 1][j] || !all.mapest->map[i - 1][j]
	|| !all.mapest->map[i][j + 1] || !all.mapest->map[i][j - 1])
		ft_error("map open");
	if (all.mapest->map[i + 1][j] == ' ' || all.mapest->map[i - 1][j] == ' '
	|| all.mapest->map[i][j + 1] == ' ' || all.mapest->map[i][j - 1] == ' ')
		ft_error("map open");
}

void	ft_check_map02(t_all all)
{
	int	j;
	int	player;
	int	i;

	i = -1;
	player = 0;
	while (all.mapest->map[++i])
	{
		j = -1;
		while (all.mapest->map[i][++j])
		{
			if (ft_strchr(PLAYER, all.mapest->map[i][j]))
				player++;
			if (!ft_strchr(SYMBOLS, all.mapest->map[i][j]))
				ft_error("bad symbols");
			else if (ft_strchr(FLOOR, all.mapest->map[i][j]))
				ft_check_map_floor(all, i, j);
		}
	}
	if (player != 1)
		ft_error("bad player");
}
