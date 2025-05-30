/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:35:13 by mlouron           #+#    #+#             */
/*   Updated: 2025/05/30 18:21:16 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <string.h>

char **map(void)
{
	static char *base_map[] = {
		"11111111",
		"10C00000",
		"10011000",
		"10000C0E",
		"10000000",
		"1001001C",
		"10010P00",
		"11111111",
		NULL
	};
	int height = 0;
	while (base_map[height])
		height++;
	char **copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return NULL;
	for (int i = 0; i < height; i++)
	{
		copy[i] = strdup(base_map[i]);
		if (!copy[i])
		{
			for (int j = 0; j < i; j++)
				free(copy[j]);
			free(copy);
			return NULL;
		}
	}
	copy[height] = NULL;
	return (copy);
}
