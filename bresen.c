void LineBresenham(int x1, int y1, int x2, int y2, int color)
{
	int dy = y2 - y1;
	int dx = x2 - x1;
	int stepx, stepy;

	if (dy < 0)
	{
		dy = -dy;
		stepy = -1;
	}
	else
		stepy = 1;
	if (dx < 0)
	{
		dx = -dx;
		stepx = -1;
	}
	else
		stepx = 1;
	dy <<= 1;        // dy is now 2*dy
	dx <<= 1;        // dx is now 2*dx
//	drawpixel(x1,y1, color);
	if (dx > dy)
	{
		int fraction = dy - (dx >> 1);  // same as 2*dy - dx
		while (x1 != x2) 
		{
			if (fraction >= 0) 
			{
				y1 += stepy;
				fraction -= dx;          // same as fraction -= 2*dx
			}
			x1 += stepx;
			fraction += dy;              // same as fraction -= 2*dy
			drawpixel(x1, y1, color);
		}
	}
	else
	{
		int fraction = dx - (dy >> 1);
		while (y1 != y2)
		{
			if (fraction >= 0)
			{
				x1 += stepx;
				fraction -= dy;
			}
			y1 += stepy;
			fraction += dx;
			drawpixel(x1, y1, color);
		}
	}
}
