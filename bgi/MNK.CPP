void mnk(double *a, double *b, double X[], double Y[], int n,double *By,double *Ba, double *Bb, double *deltaA, double *deltaB){
	double Sxy = 0, Sx = 0, Sy = 0, Sx2 = 0;

	for(int i = 0; i < n; i++){
		Sxy += X[i]*Y[i];
	}
	for(i = 0; i < n; i++){
		Sx += X[i];
	}
	for(i = 0; i < n; i++){
		Sy += Y[i];
	}
	for(i = 0; i < n; i++){
		Sx2 += X[i]*X[i];
	}

	*b = (n*Sxy - Sx*Sy)/(n*Sx2 - (Sx*Sx));
	*a = (Sy - (*b*Sx))/(n);

	double SyY2 = 0;
	int k = n - 2;

	for(i = 0; i < n; i++){
		SyY2 += (Y[i] - (*a + *b*X[i]))*(Y[i] - (*a + *b*X[i]));
	}

	*By = sqrt(SyY2/k);
	*Ba = *By * sqrt((Sx2)/(n*Sx2 - (Sx*Sx)));
	*Bb = *By * sqrt((n)/(n*Sx2 - (Sx*Sx)));

   *deltaA = tstudent(k)*(*Ba);
	*deltaB = tstudent(k)*(*Bb);
}
