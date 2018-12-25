/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:10:43 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 21:53:50 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


void		ft_handle_input(t_input *in, t_fdf *f)
{
	if ((in->keys[SDL_SCANCODE_F1]) && (f->opt = 1))
		f->deta = -0.05;
	if ((in->keys[SDL_SCANCODE_F2]) && (f->opt = 1))
		f->deta = 0.05;
	if ((in->keys[SDL_SCANCODE_F3]) && (f->opt = 2))
		f->deta = -0.05;
	if ((in->keys[SDL_SCANCODE_F4]) && (f->opt = 2))
		f->deta = 0.05;
   	if((in->keys[SDL_SCANCODE_F5]) && !(f->opt = 0))
		f->deta = -0.05;
	if ((in->keys[SDL_SCANCODE_F6]) && !(f->opt = 0))
		f->deta = 0.05;
	if ((in->keys[SDL_SCANCODE_SPACE]))
		f->opt = 10;
	if ((in->mouse[SDL_BUTTON_LEFT]))
		f->k += 0.05;
	if (in->mouse[SDL_BUTTON_RIGHT])
		f->k -= 0.05;
	if ((in->keys[SDL_SCANCODE_LEFT]))
		f->u.x = (f->u.x > 0) ? f->u.x - 2 : 0;
	if ((in->keys[SDL_SCANCODE_RIGHT]))
		f->u.x = (f->u.x < f->scr_w) ? f->u.x + 2 : f->scr_w;
	if ((in->keys[SDL_SCANCODE_UP]))
		f->u.y = (f->u.y > 0) ? f->u.y - 2 : 0;
	if ((in->keys[SDL_SCANCODE_DOWN]))
		f->u.y = (f->u.y < f->scr_h) ? f->u.y + 2 : f->scr_h;
   	if((in->keys[SDL_SCANCODE_KP_PLUS]))
		f->z = (f->z < 25) ? f->z + 0.05 : 25.0;
	if ((in->keys[SDL_SCANCODE_KP_MINUS]))
		f->z = (f->z > 0) ? f->z - 0.05 : 1.0;
	f->angle += f->deta;
}

void		ft_draw(t_fdf *f)
{
	int		i;
	int		j;
	t_point	p;
	t_point q;

	i = -1;
	while ((++i < f->map.height - 1) && (j = -1))
	{
		while (++j < f->map.width - 1)
		{
			ft_isometric(ft_get_point(f->k * j, f->k * i), &p, f->z * f->map.coords[i][j].z, f);
			if (j < f->map.width - 1)
			{
				ft_isometric(ft_get_point(f->k * (j + 1), f->k * i), &q, f->z * f->map.coords[i][j + 1].z, f);
				ft_sdl_draw_line(f->pixels, p, q);
			}
			if (i < f->map.height - 1)
			{
				ft_isometric(ft_get_point(f->k * j, f->k * (i + 1)), &q, f->z * f->map.coords[i + 1][j].z, f);
				ft_sdl_draw_line(f->pixels, p, q);
			}
		}
	}
	ft_render_sdl(f->ptr, f->pixels);
}
