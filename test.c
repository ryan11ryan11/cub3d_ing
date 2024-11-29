#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

// KEYBOARD ESC 리눅스 키 매핑
#define K_ESC 65307

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

// EVENT KEY 리눅스 이벤트 상수
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

typedef struct s_info {
	double playerPositionX;
	double playerPositionY;
	double directionVectorX;
	double directionVectorY;
	double planeX;
	double planeY;
	void *mlx;
	void *win;
	void *img;
	int *buffer;
	int bpp;
	int size_line;
	int endian;
	double moveSpeed;
	double rotSpeed;
} t_info;

int worldMap[mapWidth][mapHeight] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void verLine(t_info *info, int x, int y1, int y2, int color) {
	for (int y = y1; y <= y2; y++) {
		info->buffer[y * screenWidth + x] = color;
	}
}

int main_loop(t_info *info) {
	// 버퍼 초기화
	printf("#1\n");
	memset(info->buffer, 0, screenWidth * screenHeight * sizeof(int));

	for (int x = 0; x < screenWidth; x++) {
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = info->directionVectorX + info->planeX * cameraX;
		double rayDirY = info->directionVectorY + info->planeY * cameraX;

		int mapX = (int)info->playerPositionX;
		int mapY = (int)info->playerPositionY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double sideDistX, sideDistY;

		int stepX, stepY, hit = 0, side;

		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (info->playerPositionX - mapX) * deltaDistX;
		} else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->playerPositionX) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (info->playerPositionY - mapY) * deltaDistY;
		} else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->playerPositionY) * deltaDistY;
		}

		while (!hit) {
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		double perpWallDist = (side == 0)
							  ? (mapX - info->playerPositionX + (1 - stepX) / 2) / rayDirX
							  : (mapY - info->playerPositionY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0) drawStart = 0;
		if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

		int color;
		switch (worldMap[mapX][mapY]) {
			case 1: color = 0xFF0000; break;
			case 2: color = 0x00FF00; break;
			case 3: color = 0x0000FF; break;
			case 4: color = 0xFFFF00; break;
			default: color = 0xFFFFFF; break;
		}
		if (side == 1) color /= 2;

		verLine(info, x, drawStart, drawEnd, color);
	}

	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (0);
}

int key_press(int key, t_info *info) {
	if (key == KEY_W) {
		if (!worldMap[(int)(info->playerPositionX + info->directionVectorX * info->moveSpeed)][(int)info->playerPositionY])
			info->playerPositionX += info->directionVectorX * info->moveSpeed;
		if (!worldMap[(int)info->playerPositionX][(int)(info->playerPositionY + info->directionVectorY * info->moveSpeed)])
			info->playerPositionY += info->directionVectorY * info->moveSpeed;
	}
	if (key == KEY_S) {
		if (!worldMap[(int)(info->playerPositionX - info->directionVectorX * info->moveSpeed)][(int)info->playerPositionY])
			info->playerPositionX -= info->directionVectorX * info->moveSpeed;
		if (!worldMap[(int)info->playerPositionX][(int)(info->playerPositionY - info->directionVectorY * info->moveSpeed)])
			info->playerPositionY -= info->directionVectorY * info->moveSpeed;
	}
	if (key == KEY_A) {
		double oldDirX = info->directionVectorX;
		info->directionVectorX = info->directionVectorX * cos(info->rotSpeed) - info->directionVectorY * sin(info->rotSpeed);
		info->directionVectorY = oldDirX * sin(info->rotSpeed) + info->directionVectorY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == KEY_D) {
		double oldDirX = info->directionVectorX;
		info->directionVectorX = info->directionVectorX * cos(-info->rotSpeed) - info->directionVectorY * sin(-info->rotSpeed);
		info->directionVectorY = oldDirX * sin(-info->rotSpeed) + info->directionVectorY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	if (key == K_ESC) exit(0);
	return (0);
}

int	main()
{
	t_info	info;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "Raycaster");
	info.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
	info.buffer = (int *)mlx_get_data_addr(info.img, &info.bpp, &info.size_line, &info.endian);

	info.playerPositionX = 12;
	info.playerPositionY = 5;
	info.directionVectorX = -1;
	info.directionVectorY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
