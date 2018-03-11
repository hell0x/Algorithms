//f(x) = a0 + a1x + ... + a n-1 x n-1 + a n x n
double f(int n, double a[], double x){
	int i;
	double p = a[0];
	for(i=1; i<=n; i++)
		P += (a[i] * pow(x, i));
	return p;
}