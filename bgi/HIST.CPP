int maxh(long kl[], int n){
	int maxh = kl[0];
	for(int i = 0; i < n; i++){
		if(maxh < kl[i]){
			maxh = kl[i];
		}
	}
	return maxh;
}

double maxX(double k[], int n){
	double max = k[0];
	for(int i = 0; i < n; i++){
		if(max < k[i]){
			max = k[i];
		}
	}
	return max;
}

double minX(double k[], int n){
	double min = k[0];
	for(int i = 0; i < n; i++){
		if(min > k[i]){
			min = k[i];
		}
	}
	return min;
}

double srednia(double X[], int n){
	double srednia = 0;
	for(int i = 0; i < n; i++){
		srednia += X[i];
	}
	return srednia/n;
}

void hist(double X[], int n, int k, double *var, double *h, double *sx, double *sy){
	double max, min;
	max = maxX(X,n);
	min = minX(X,n);
	long *pK;
	pK = new long [k+2];
	int l;
	double dimx = 400, dimy = 280;

	//cout << min << endl;
	//cout << max << endl;

	for(int i = 0; i < k+2; i++){
		pK[i] = 0;
	}

	*h = (max - min)/k;
	*sx = (dimx-20)/k;

	for(i = 0; i < n; i++){
		l = int((X[i] - min)/(*h))+1;
		if(l < 0) l = 0;
		if(l > k+1) l = k+1;
		pK[l]++;
	}
	*sy = dimy/maxh(pK,k+1);

	for(i = 1; i < k+1; i++){
		setfillstyle(4,i%15+1);
		bar3d(*sx*(i-1)+10,dimy - pK[i]**sy+20,*sx*(i)+10,dimy+20,0,1);

		//cout << pK[i] << endl;
	}

	double Sxxs2 = 0, xs;
	xs = srednia(X,n);
	for(i = 0; i < n; i++){
		Sxxs2 += (X[i] - xs)*(X[i] - xs);
	}
	*var = Sxxs2/(n-1);
}