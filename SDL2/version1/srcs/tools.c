/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:12:03 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/16 13:48:14 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		ft_get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = ft_percent(start.x, end.x, current.x);
	else
		percentage = ft_percent(start.y, end.y, current.y);
	red = ft_get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = ft_get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = ft_get_light((start.color & 0xFF), end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | (blue));
}

void	ft_rotate_x(t_poind *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double		prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->x = prev_x * cos(angle) - prev_y * sin(angle);
	u->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	ft_rotate_y(t_poind *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double		prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->y = prev_y * cos(angle) - prev_z * sin(angle);
	*z = prev_y * sin(angle) + prev_z * cos(angle);
}

void	ft_rotate_z(t_poind *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->x = prev_x * cos(angle) + prev_z * sin(angle);
	*z = -prev_x * sin(angle) + prev_z * cos(angle);
}
