/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:07:43 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/16 13:49:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	ft_put_pixel(Uint32 *pixels, int x, int y, int color)
{
	if (y >= 0 && y < SCR_HEIGHT && x >= 0 && x < SCR_WIDTH)
		pixels[y * SCR_WIDTH + x] = color;
	else ;
}

void	ft_isometric(t_poind q, t_point *p, double z, t_fdf *f)
{

	if (z <= 10)
		p->color = 0xFFFFFF;
	else if (z > 10 && z <= 50)
		p->color =  0x00FF00;
	else
		p->color = 0xFFFF00;
	if (f->opt == 0)
		ft_rotate_x(&q, &z, f->angle);
	if (f->opt == 1)
		ft_rotate_y(&q, &z, f->angle);
	if (f->opt == 2)
		ft_rotate_z(&q, &z, f->angle);
	p->x = (q.x - q.y) * cos(0.523599) + f->u.x;
	p->y = -z + (q.x + q.y) * sin(0.523599) + f->u.y;
}

void		ft_usage(void)
{
	ft_putendl("42 Fdf v1.0");
	ft_putendl("F1 --- F6 >>> Pour La Rotation");
	ft_putendl("SPACE pour Arreter La Rotation");
	ft_putendl("Les Touches directionnelles Pour La Translation");
	ft_putendl("Plus Moin du Keypad Pour La Hauteur");
	ft_putendl("Mouse Button Left or Right for the Zoom");
	ft_putendl("Fdf Version 1.0");
	ft_putendl("\n\n\t ./fdf test_maps/42.fdf");
}

t_poind		ft_get_point(int x, int y)
{
	t_poind p;
	
	p.x =  x < SCR_WIDTH ? x : SCR_WIDTH - 1;
	p.y =  y < SCR_HEIGHT ? y : SCR_HEIGHT - 1;
	return (p);
}

void	ft_error(const char *error, const char *str)
{
	ft_putstr(error);
	ft_putchar(' ');
	ft_putendl(str);
}
