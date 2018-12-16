/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:54:55 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/16 13:47:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	f;
	t_input	in;
	int		status;

	status = EXIT_FAILURE;
	if (argc != 2)
	{
		ft_error("./fdf filename", "");
		goto Quit;
	}
	if (ft_fdf_init(&f, argv))
		goto Quit;
	ft_memset(&in, SDL_FALSE, sizeof(t_input));
	ft_usage();
	while (!in.quit)
	{
		ft_update_event(&in);
		ft_handle_input(&in, &f);
		ft_draw(&f);
	}
	status = EXIT_SUCCESS;
Quit:
	ft_fdf_quit(&f);
	return (status);
}
