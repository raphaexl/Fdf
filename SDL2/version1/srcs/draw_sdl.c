/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:10:04 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 22:21:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

static void		ft_sdl_draw_octant1(Uint32 *pixels, t_point start, t_point p2)
{
	t_point		dp;
	t_poind		pincr;
	t_point		p1;
	int			error;
	int			i;

	i = -1;
	p1.x = start.x;
	p1.y = start.y;
	p1.color = start.color;
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.x / 2;
	while (++i <= dp.x)
	{
		p1.x += pincr.x;
		error += dp.y;
		if (error > dp.x)
		{
			error -= dp.x;
			p1.y += pincr.y;
		}
		ft_put_pixel(pixels,  p1.x, p1.y, ft_get_color(p1, start, p2, dp));
	}
}

static void		ft_sdl_draw_octant2(Uint32 *pixels, t_point start, t_point p2)
{
	t_point		dp;
	t_poind		pincr;
	t_point		p1;
	int			error;
	int			i;

	i = -1;
	p1.x = start.x;
	p1.y = start.y;
	p1.color = start.color;
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.y / 2;
	while (++i <= dp.y)
	{
		p1.y += pincr.y;
		error += dp.x;
		if (error > dp.y)
		{
			error -= dp.y;
			p1.x += pincr.x;
		}
		ft_put_pixel(pixels,  p1.x, p1.y, ft_get_color(p1, start, p2, dp));
	}
}

void			ft_sdl_draw_line(Uint32 *pixels, t_point p1, t_point p2)
{
	ft_put_pixel(pixels,  p1.x, p1.y, ft_get_color(p1, p1, p1, p1));
	ft_put_pixel(pixels,  p2.x, p2.y, ft_get_color(p2, p1, p2, p2));
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		ft_sdl_draw_octant1(pixels, p1, p2);
	else
		ft_sdl_draw_octant2(pixels, p1, p2);
}

void	ft_clear_pixels(Uint32 *pixels)
{
	int		i;

	i = -1;
	while (++i < SCR_WIDTH * SCR_HEIGHT)
		pixels[i] = 0x000000;
}

int		ft_render_sdl(t_ptr ptr, Uint32 *pixels)
{
	if (SDL_RenderClear(ptr.renderer))
	{
		ft_error("Error SDL_RenderClear() ", SDL_GetError());
		return (-1);
	}
	if (SDL_UpdateTexture(ptr.texture, NULL, pixels, SCR_WIDTH * sizeof(Uint32)))
	{
		ft_error("error SDL_UpdateTexture", SDL_GetError());
		return (-1);
	}
	if (SDL_RenderCopy(ptr.renderer, ptr.texture, NULL, NULL))
	{
		ft_error("Error SDL_RenderCopy :", SDL_GetError());
		return (-1);
	}
	SDL_RenderPresent(ptr.renderer);
	SDL_Delay(100);
	ft_clear_pixels(pixels);
	return (0);
}

