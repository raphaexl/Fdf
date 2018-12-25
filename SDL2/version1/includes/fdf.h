/* ************************************************************************** */
/*                                                                            */
/*i                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:45:04 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/23 18:14:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# define SCR_WIDTH 1800
# define SCR_HEIGHT 1400

# include <SDL2/SDL.h>
# include <sys/stat.h>
# include <math.h>
# include <fcntl.h>
# include <libft.h>

typedef struct		s_point
{
	int			x;
	int			y;
	int			color;
}					t_point;

typedef struct		s_poind
{
	int			x;
	int			y;
}					t_poind;

typedef struct		s_dot
{
	double		z;
	int		color;
}					t_dot;

typedef struct		s_input
{
	int		quit;
	int		mousex;
	int		mousey;
	int		xwheel;
	int		ywheel;
	int		mousexrel;
	int		mouseyrel;
	int		mouse[6];
	int		keys[SDL_NUM_SCANCODES];
}					t_input;

typedef	struct		s_ptr
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
}					t_ptr;

typedef struct		s_map
{
	int			width;
	int			height;
	int			sc;
	t_dot		coords[500][500];
}					t_map;

typedef struct		s_fdf
{
	Uint32			*pixels;
	int				scr_w;
	int				scr_h;
	double			k;
	double			z;
	int				opt;
	double			deta;
	double			angle;
	t_poind			u;
	t_ptr			ptr;
	t_map			map;
}					t_fdf;

void		ft_rotate_x(t_poind *u, double *z, double angle);
void		ft_rotate_y(t_poind *u, double *z, double angle);
void		ft_rotate_z(t_poind *u, double *z, double angle);

double		ft_percent(int start, int end, int current);
int			ft_get_color(t_point c, t_point st, t_point e, t_point delta);
int			ft_get_light(int start, int end, double percentage);

void		ft_put_pixel(Uint32 *pixels, int x, int y, int color);
void		ft_clear_pixels(Uint32 *pixels);

void		ft_read_file(t_map *map, char *argv[]);
void		ft_fill_map(t_map *map, char *line, int y);
int			ft_fdf_init(t_fdf *fdf, char *file[]);

void		ft_isometric(t_poind p, t_point *po, double z, t_fdf *f);

int			ft_init_sdl(t_ptr *ptr, int width, int height, const char *title);
void		ft_update_event(t_input *in);
void		ft_handle_input(t_input *in, t_fdf * f);
void		ft_sdl_draw_line(Uint32 *pixels, t_point p1, t_point p2);
int			ft_render_sdl(t_ptr ptr, Uint32 *pixel);

void		ft_draw(t_fdf *f);
void		ft_quit_sdl(t_ptr *ptr);
void		ft_error(const char *error, const char *str);
void		ft_usage(void);
t_poind		ft_get_point(int x, int y);
void		ft_fdf_quit(t_fdf *f);
#endif
