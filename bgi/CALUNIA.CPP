double calunia(double a, double b, double E){
	double p = a, I = 0;
	do{
	if(p < 0){
		I += (fabs(a) - fabs(p))*f(p,0,200);
	}
	if(p > 0){
   	I += (p-a)*f(p,0,200);
	}
   a = p;
	p += E;
	}while(p <= b);
	return I;
}