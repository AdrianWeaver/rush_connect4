/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:42 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 14:57:01 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int    ft_allocate_grid(t_connect4 *setup)
{
    setup->grid = malloc(sizeof(int *) * (setup->lines + 1));
    if (!(setup->grid))
    {
        ft_printf("Mayday!! It seems we have an important issue captain!!\n");
        return (1);
    }
    ft_memset(setup->grid, 0, sizeof(int *) * (setup->lines + 1));

    int i = 0;
    while (i < setup->lines)
    {
        setup->grid[i] = malloc(sizeof(int) * (setup->columns + 1));
        if (!(setup->grid[i]))
        {
            ft_printf("Mayday!! It seems we have an important issue captain, we can't make a column?!\n");
            return (1);
        }
        ft_memset(setup->grid[i], 0, sizeof(int) * (setup->columns + 1));
        i++;
    }

    return (0);
}

void    ft_deallocate_grid(t_connect4 *setup)
{
    int i = 0;
    while (i < setup->lines)
        free(setup->grid[i++]);
    free(setup->grid);
}

void    ft_display_grid(t_connect4 *setup)
{
	ft_printf("%s", CLEAR);
    for (int i = setup->lines - 1; i >= 0; i--)
    {
        ft_putchar('-');
        for (int y = 0; y < (setup->columns * 4); y++)
            ft_putchar('-');
        ft_putchar('\n');
        ft_putchar('|');
        for (int y = 0; y < setup->columns; y++)
        {
            ft_putchar(' ');
            if (setup->grid[i][y] == CELL_EMPTY)
                ft_putchar(CELL_CHAR_EMPTY);
            else if (setup->grid[i][y] == CELL_IA)
                ft_printf("%s%s%s", YELLOW, CELL_CHAR_IA, NOCOLOUR);
            else if (setup->grid[i][y] == CELL_PLAYER)
                ft_printf("%s%s%s", RED, CELL_CHAR_ENNEMY, NOCOLOUR);
            else
                ft_printf("Gone wrong... %i\n", setup->grid[i][y]);
            ft_putchar(' ');
            ft_putchar('|');
        }
        ft_putchar('\n');
    }

    ft_putchar('-');
    for (int y = 0; y < (setup->columns * 4); y++)
        ft_putchar('-');
	ft_putchar('\n');
    for (int y = 0; y < (setup->columns * 4); y++)
	{
		if (y % 2 = 0)
	}
    ft_putchar('\n');
}
