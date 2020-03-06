/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:33:39 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/06 18:01:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdio.h"
#include "inttypes.h"

int t(void)
{
    printf("ok\n");
    return (0);
}

typedef	struct	s_rgba
{
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t a;
}				t_rgba;

typedef union	u_color
{
	uint32_t	c;
	t_rgba		rgba;
}				t_color;


// gcc -L.   main.c -lmlx
int main(void)
{

    void    *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "432432");

    t_color color;

    color.c = 0;
    color.rgba.r = 255;

    int i = 0;
    int j = 0;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
        {
        	mlx_pixel_put(mlx_ptr, win_ptr, j, i, color.c); 
            j++;
        }
        i++;
    }
    


	mlx_loop_hook (mlx_ptr, t, NULL);

     mlx_loop (mlx_ptr);
     return (0);
}