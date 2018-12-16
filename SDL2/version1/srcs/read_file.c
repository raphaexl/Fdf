/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:22:47 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/16 14:04:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	ft_fill_map(t_map *map, char *line, int y)
{
	char	**tab;
	int		x;
	int		i;

	i = -1;
	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
	{
		map->coords[y][x].z = (double)ft_atoi(tab[i]);
		map->coords[y][x++].color = 0xFF00FF;
	}
	if (!map->width && x)
		map->width = x;
	if (map->width && x != map->width)
	{
		ft_error("Error ", "Bad map");
		exit(EXIT_FAILURE);
	}
}

void	ft_read_file(t_map *map, char *argv[])
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	y = 0;
	if (ft_get_next_line(fd, &line) == 1 && line)
	{
		ft_fill_map(map, line, y++);
	while (ft_get_next_line(fd, &line))
		ft_fill_map(map, line, y++);
	map->height = y;
	if (!map->width || !map->height)
	{
		ft_error("Error ", "Bad map");
		exit(EXIT_FAILURE);
	}
	map->sc = 25;
	}
	else
	{
		ft_error("Error ", "Bad map");
		exit(EXIT_FAILURE);
	}
}

int		ft_fdf_init(t_fdf *fdf, char *file[])
{
	t_poind		scr;

	ft_read_file(&fdf->map, file);
	scr.x = (fdf->map.width * 25) + 100;
	scr.y = (fdf->map.height * 25) + 200;
	fdf->scr_h = scr.y > SCR_HEIGHT ? SCR_HEIGHT : scr.y;
	fdf->scr_w = scr.x > SCR_WIDTH || scr.y == SCR_HEIGHT ? SCR_WIDTH : scr.x;
	fdf->k = (scr.y == SCR_HEIGHT || scr.x == SCR_WIDTH) ? 2.0 : 10.0;
	fdf->z = (scr.y == SCR_HEIGHT || scr.x == SCR_WIDTH) ? 2.0 : 10.0;
	fdf->opt = 5;
	fdf->deta = 0.05;
	fdf->angle = 0.0;
	fdf->u.x = fdf->scr_w / 2;
	fdf->u.y = fdf->scr_h / 2 - (fdf->map.height / 2) * fdf->k;
	if (!(fdf->pixels = (Uint32 *)malloc((SCR_WIDTH * SCR_HEIGHT) * sizeof(Uint32))))
	{
		ft_error("Error D'allocation dynamique", "quit");
		return (-1);
	}
	ft_memset(fdf->pixels, 0, sizeof(Uint32) * (SCR_WIDTH * SCR_HEIGHT));
	ft_init_sdl(&fdf->ptr, fdf->scr_w, fdf->scr_h, "fdf");
	return (0);
}

void		ft_fdf_quit(t_fdf *fdf)
{
	ft_quit_sdl(&fdf->ptr);
	return ;
}
