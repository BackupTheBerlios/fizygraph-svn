void punkty(double sx, double sy, double X[], double Y[], int n){
	int dimx = 400, dimy = 300;
	double x, y, pl, pp;

	pp = 5/sx;
	pl = -5/sx;
	sx *= (dimx/10);
	sy *= (dimy/10);
	setlinestyle(0,0,1);
	setcolor(YELLOW);

	for(int i = 0; i < n; i++){
		if(X[i]>pl && X[i]<pp){
			x = X[i]*sx + (dimx/2);
			y = (((dimy/2)/sy) - Y[i])*sy;
			if((y < dimy) && (y > 10)){
				line(x-2,y-2,x+2,y+2);
				line(x-2,y+2,x+2,y-2);
			}
		}
	}
	//cout << x << ";" << fx;

	setlinestyle(0,0,1);
}
