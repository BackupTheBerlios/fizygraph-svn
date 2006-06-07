double fmnk(double x, double &a, double &b){
	//cout << "jestem tu!";
	return a + (b*x);
}

void wykmnk(double sx, double sy, double *a, double *b){
	int dimx = 400, dimy = 300;
	double x, fx, pp, pl;

	pp = 5/sx;
	pl = -5/sx;
	sx *= (dimx/10);
	sy *= (dimy/10);
	setlinestyle(0,0,1);
	setcolor(RED);

	for(int i = 10; i < (dimx); i++){
		x = (i - (dimx/2))/sx;
		if(x>pl && x<pp){
			fx = fmnk(x,*a,*b);
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
