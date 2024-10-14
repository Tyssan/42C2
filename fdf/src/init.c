/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:29 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/14 06:22:12 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*ft_fdfstruct_maker(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->matrix = NULL;
	fdf->map_x = 0;
	fdf->map_y = 0;
	fdf->flt_x = 0;
	fdf->flt_y = 0;
	return (fdf);
}

t_image	*ft_imagestruct_maker(void)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->img_ptr = NULL;
	img->img_data_ptr = NULL;
	img->img_bpp = 0;
	img->img_line_length = 0;
	img->img_endian = 0;
	return (img);
}

void	ft_mlx_destroyer(t_data *data, int code)
{
	if (code == 1)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	else if (code == 2)
	{
		free(data->img);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	}
	else if (code == 3)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
		free(data->img);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

bool	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win_ptr = NULL;
	data->img = NULL;

	data->mlx_ptr = mlx_init();//initialisation MLX et assigner le pointeur
	if (!data->mlx_ptr)
		return (0);

	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_NAME);//initialisation de la fenetre MLX
	if (!data->mlx_win_ptr)
		return (ft_mlx_destroyer(data, 0), 0);

	data->img = ft_imagestruct_maker();//malloc des data de la future image
	if (!data->img)
		return (ft_mlx_destroyer(data, 1), 0);

	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);//initialisation de l'image a afficher
	if (!data->img->img_ptr)
		return (ft_mlx_destroyer(data, 2), 0);

	data->img->img_data_ptr = mlx_get_data_addr(
			data->img->img_ptr, &data->img->img_bpp, \
			&data->img->img_line_length, &data->img->img_endian);//donne l'adresse des variables MLX
	if (!data->img->img_data_ptr)
		return (ft_mlx_destroyer(data, 3), 0);

	return (1);
}

bool	ft_init_main(char *file, t_data *data)
{
	data->fdf = ft_fdfstruct_maker();
	if (data->fdf == NULL)
		return (0);
	if (!ft_map_parsing(file, data))//parsing de la map dans les int, matrices, ...
		return (0);//si ft_map_parsing renvoie 0, je renvoie 0 ici aussi, ce qui renvoie un 0 au main !!;
	if (!ft_mlx_init(data))//initialisation MLX
		return (0);
	return (1);
}
