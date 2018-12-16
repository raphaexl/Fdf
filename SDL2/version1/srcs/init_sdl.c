/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:19:34 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/16 13:48:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


int		ft_init_sdl(t_ptr *ptr, int width, int height, const char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		ft_error(" Initialisation :", SDL_GetError());
		return (-1);
	}
	if (!(ptr->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN)))
	{
		ft_error("Window Creation :", SDL_GetError());
		return (-1);
	}
		if (!(ptr->renderer = SDL_CreateRenderer(ptr->window, -1, SDL_RENDERER_PRESENTVSYNC\
			| SDL_RENDERER_ACCELERATED)))
	{
		ft_error("Renderer Creation :", SDL_GetError());
		return (-1);
	}
	if (!(ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height)))
	{
		ft_error("SDL_CreateTexture :", SDL_GetError());
		return (-1);
	}
	return (0);
}


void	ft_quit_sdl(t_ptr *ptr)
{
	if (ptr->texture)
		SDL_DestroyTexture(ptr->texture), ptr->texture = NULL;
	if (ptr->window)
		SDL_DestroyWindow(ptr->window), ptr->window = NULL;
	if (ptr->renderer)
		SDL_DestroyRenderer(ptr->renderer), ptr->renderer = NULL;
	SDL_Quit();
}
