void ccs2fcs(double *x, double *y, double z, double d){
	*x /= (z/d)+1;
	*y /= (z/d)+1;
}