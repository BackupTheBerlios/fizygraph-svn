void calka(double sx, double sy, double cl, double cp, int y, int ro){
	int dimx = 400, dimy = 300;
	double x, fx, wcl = cl, wcp = cp;

	if(cp > 5/sx){
		wcp = 5/sx;
	}
	if(cp < -5/sx){
		wcp = -5/sx;
	}
	if(cl < -5/sx){
		wcl = -5/sx;
	}
	if(cl > 5/sx){
		wcl = 5/sx;
	}

	sx *= (dimx/10);
	sy *= (dimy/10);
	setlinestyle(1,0,1);
	setcolor(GREEN);

	x = wcl;
	fx = f(x,0,200);
	x = x*sx + (dimx/2);
	double gl = x;
	fx = (((dimy/2)/sy) - fx)*sy;
	if((fx < dimy) && (fx > 10)){
		line(x,y+(dimy/2),x,fx);
	}

	x = wcp;
	fx = f(x,0,200);
	x = x*sx + (dimx/2);
	double gp = x;
	fx = (((dimy/2)/sy) - fx)*sy;
	if((fx < dimy) && (fx > 10)){
		line(x,y+(dimy/2),x,fx);
	}

	setlinestyle(0,0,1);

	for(int i = gl; i < gp; i += ro){
		x = (i - (dimx/2))/sx;
		double g = f(x,0,200);
		x = x*sx + (dimx/2);
		if(g < 0){
			g = (((dimy/2)/sy) - g)*sy;
			fx = dimy/2;
			while(fx < g){
				if((fx < dimy) && (fx > 10)){
					line(x,fx,x+1,fx+1);
				}
				fx += ro;
			}
		}
		else{
			g = (((dimy/2)/sy) - g)*sy;
			fx = dimy/2;
			while(fx > g){
				if((fx < dimy) && (fx > 10)){
					line(x,fx,x+1,fx+1);
				}
				fx -= ro;
			}
		}
	}
	//cout << x << ";" << fx;

	setlinestyle(0,0,1);
}
