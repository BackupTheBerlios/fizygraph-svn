void wcs2ccs(double *x, double *y, double *z, double kX, double kY, double kZ, double tx, double ty, double tz){
	double ax1 = cos(kY)*cos(kZ);
	double ax2 = (-1)*cos(kX)*sin(kZ) + sin(kX)*sin(kY)*cos(kZ);
	double ax3 = sin(kX)*sin(kZ) + cos(kX)*sin(kY)*cos(kZ);
	double ax4 = tx*ax1 + ty*ax2 + tz*ax3;
	double ay1 = cos(kY)*sin(kZ);
	double ay2 = cos(kX)*cos(kZ) + sin(kX)*sin(kY)*sin(kZ);
	double ay3 = (-1)*sin(kX)*cos(kZ) + cos(kX)*sin(kY)*sin(kZ);
	double ay4 = tx*ay1 + ty*ay2 + tz*ay3;
	double az1 = (-1)*sin(kY);
	double az2 = sin(kX)*cos(kY);
	double az3 = cos(kX)*cos(kY);
	double az4 = tx*ay1 + ty*ay2 + tz*ay3;

	double nx = ax1**x + ax2**y + ax3**z + ax4;
	double ny = ay1**x + ay2**y + ay3**z + ay4;
	double nz = az1**x + az2**y + az3**z + az4;

	*x = nx;
	*y = ny;
   *z = nz;
}