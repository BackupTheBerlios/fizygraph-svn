void pochodna(double sx, double sy, double pl, double pp, double h){
	int dimx = 400, dimy = 300;
	double x, fx;

	sx *= (dimx/10);
	sy *= (dimy/10);
	setlinestyle(0,0,1);
	setcolor(RED);

	for(int i = 10; i < (dimx); i++){
		x = (i - (dimx/2))/sx;
		if(x>pl && x<pp){
			fx = (f(x+h,0,200)-f(x,0,200))/h;
			x = x*sx + (dimx/2);
			fx = (((dimy/2)/sy) - fx)*sy;
			if((fx < dimy) && (fx > 10)){
				line(x,fx,x,fx);
			}
		}
	}
	//cout << x << ";" << fx;

	setlinestyle(0,0,1);
}
