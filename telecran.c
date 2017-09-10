/*	if ((w->key.down[6]) & (1 << 5)) //esc
		exit(0);
	if ((w->key.down[1]) & (1 << 3)) //b
		pc = 0x0000FF;//blue
	if ((w->key.down[1]) & (1 << 7)) //r
		pc = 0xFF0000;//red
	if ((w->key.down[14]) & (1 << 5)) //del
		pc = 0x000000; //black
	if ((w->key.down[15]) & (1 << 3) && (w->img.px[LARG * y + --x] = pc) == pc) //left 123
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 4) && (w->img.px[LARG * y + ++x] = pc) == pc) // right 124
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 5) && (w->img.px[LARG * ++y + x] = pc) == pc) // down
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 6) && (w->img.px[LARG * --y + x] = pc) == pc) // up
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
*/
