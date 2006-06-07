void rysuj3d(double x, double y, int t){
	int dimx = 300, dimy = 300;
	double sx = dimx/10;
	double sy = dimy/10;

	x *= sx;
	y *= sy;

	x = x + 50;
	y = - y + dimy;

	if(x > 50 && x < (dimx + 50) && y > 0 && y < dimy){
		if(t == 1){
			setcolor(YELLOW);
			//line(x+1,y+1,x+1,y+1);
		}
		else if(t == 2){
			setcolor(RED);
		}
		else if(t == 3){
			setcolor(GREEN);
		}
		else if(t == 4){
			setcolor(BLUE);
		}
		else{
			setcolor(YELLOW);
		}
		line(x,y,x,y);
	}
}