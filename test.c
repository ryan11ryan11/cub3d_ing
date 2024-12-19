#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

int main(void)
{
    void *mlx, *win, *img;
    unsigned int *data;
    int img_width, img_height;
    int bpp, size_l, endian;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "mlx_title");
    img = mlx_xpm_file_to_image(mlx, "./textures/mark.xpm", &img_width, &img_height);
    data = (unsigned int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);
	printf("width:%d height:%d\n", img_width, img_height);
	printf("hoho:%d\n",data[0]);
    for(int i = 0; i < img_height; i++)
        for (int j = 0; j < img_width; j++)
            if (i % 20 == 0)
                data[size_l / 4 * i + j] = 0xCC00FF00;
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}
