/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 01:00:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/18 01:53:09 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <pthread.h>
# include "../libft/includes/libft.h"

#include <stdio.h>

# define HEIGHT 720 
# define WIDTH  1080
# define ZOOM   100
# define THREADS 21

typedef struct s_rgba
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}               t_rgba;

typedef union  u_color
{
    int         value;
    t_rgba      rgb;
}              t_color;

typedef struct  s_rng
{
    double      real;
    double      imag;
}               t_rng;

typedef struct  s_index
{
    double          x;
    double          y;
}               t_index;

typedef struct s_pixel
{
    t_rng       z;
    t_rng       c;
    double      i;
    t_color     color;
}               t_pixel;

typedef struct  s_fractol
{
    double      x;
    double      y;
    double      c_r;
    double      c_i;
    double      z_r;
    double      z_i;
    double      tmp;
    t_rng       j;
    int         iter;
    t_index     i;
}               t_fractol;

typedef struct  s_display 
{
    void    *win;
    void    *img;
    int     *tab;
    int     bpp;
    int     s_l;
    int     endian;
    int     i;
    t_index size;
}               t_dis;

typedef struct  s_env
{
    t_dis       *d;
    t_index     size;
    void        *mlx_ptr;
    void        *img_ptr;
    void        *win_ptr;
    int         *img;
    int         bpp;
    int         s_l;
    int         endian;
    t_pixel     data[WIDTH][HEIGHT];
    double      zoom;
    double      minx;
    double      miny;
    double      x1;
    double      x2;
    double      y1;
    double      y2;
    long         max_iter;
    int         choix;
    int         rng;
    //int         iter;
    int         style_color;
    int         usr_color;
    int         *color;
    t_rng       julia;
    t_index     offset;
    int         motion;
    int         div;
    int         r;
    int         g;
    int         b;
    int         r2;
    int         g2;
    int         b2;
    t_fractol   *f;
    int         smooth;
    int         linear;
    double         cycle;
    int         help;
    int         switc;
    t_index     opos;
}               t_env;

typedef struct  s_thread
{
    int         n;
    double      start;
    double      end;
    pthread_t   id;
    t_env       *e;
    void        (*fractal)(t_fractol *, t_env *);
}               t_thread;

/**main**/

int         main(int ac, char **av);

/**user infos**/

void        whatfractal(t_env *e, char *name, int ac);
void        whatcolor(t_env *e, char *name, int ac);

/**init prog**/

int         setup(t_env *e);
void        init_fractal(t_env *e);
void        init_param(t_env *e);

/**thread and wheels**/

void        do_fractol(t_env *e);
void        thread_start(t_env *e, void *f(void *));
void        *fractol_pixel_wheel(void *t);
void        fractal_algo(t_env *e, t_fractol *f, void (*fract)(t_fractol *, t_env *));
void		color_pixel_img(int *img, t_index i, t_index size, int color);
void        *ptr_f_choose(t_env *e);
void        *buddhabrot_thread(void *thread);
void        *draw_pixel(void *thread);

/**Algorythme**/

void        mandelbrot(t_fractol *f, t_env *e);
void	    mandelbrot_flower(t_fractol *f, t_env *e);
void        mandel_cube(t_fractol *f, t_env *e);
void        julia(t_fractol *f, t_env *e);
void        julia_cube(t_fractol *f, t_env *e);
void        lauren(t_fractol *f, t_env *e);
void	    phoenix(t_fractol *f, t_env *e);
void        burning_ship(t_fractol *f, t_env *e);
void        tricorn(t_fractol *f, t_env *e);
void        buddhabrot(t_fractol *f, t_env *e);

/**Colors**/

void            get_pal(t_env *e);
int			    get_color(t_env *e, t_pixel p);
t_color         smooth_color(t_env *e, t_pixel p, int *color);
t_color			smooth_color_helper(t_env *e, double index, double mu, int *c);
t_color         linear_color(t_env *e, t_pixel p, int *color);
t_color         linear_color_helper(int c1, int c2, double a);
void            colorset0(t_env *e);
void            colorset1(t_env *e);
void            colorset2(t_env *e);
void            colorset3(t_env *e);
void            colorset4(t_env *e);
void		    colorset5(t_env *e);
int             color_rgb(t_env *e, t_pixel p);
t_color		    color_rgb2(t_env *e, t_pixel p);
int		        fire(t_pixel p, int iter_max);
t_color			color_gradiant(t_env *e, t_pixel p);
int				rgb_to_hsv(int r, int g, int b);
t_color		    zebre_rgb_psyche(t_env *e, t_pixel p);
t_rgba		    fill_rgb(int c);
int			    vasarely(t_pixel p);
int             buddhabrot_color(t_env *e, t_fractol *f);

/**Events**/

void        event(t_env *e);
int         press_event(int key, t_env *e);
int         deal_key(int key, t_env *e);
void        event_color(int key, t_env *e);
void        zoom(t_env *e, int speed);
void        change_julia_set(t_env *e);
void        switch_fractal(t_env *e, int c);
void        switch_pal(t_env *e);
int         motion_mouse(int x, int y, t_env *e);
void        rgb_usr(t_env *e, char c);
void        move(t_env *e, char c, double m);
int			mouse_zoom(int k, int x, int y, t_env *e);
void        reset_default(t_env *e);
void        allow_motion_julia(t_env *e);
void        julias_changes(t_env *e);
void        cycle_usr(int k, t_env *e);

/**display**/

void    display(t_env *e);
void    display_helper(t_env *e, char *c, void *m);
void    display_helper2(t_env *e, char *c, void *m);
void    *backscreen(void *thread);
void    init_second_win(t_env *e);
void    help_event(t_env *e);
void    thread_start_sec_win(t_env *e, void *f(void *));

/**exit**/

int         ft_exit(t_env *e);
void        error();
void		ft_clear_img(t_index winsize, int *img);

#endif