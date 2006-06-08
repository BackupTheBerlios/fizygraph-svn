/*
			FIZYG
			autor:		Jerzy Pabich
			wersja:		0.5.5
			data utw.:	16.03.2006
			data mod.:	03.06.2006

######################################################################*/

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <string.h>
#include <dos.h>
#include <fstream.h>

char fun[200] = {"A"};

//----------> PUNKT:

class punkt{
	public:
		punkt(int newx = 0, int newy = 0):x(newx),y(newy){}
		void setXY(int nx, int ny){x=nx; y=ny;}

		~punkt(){}

	protected:
		int x, y;
};

//----------

#include "osie.cpp"
#include "fun.cpp"
#include "wykres.cpp"
#include "pochodna.cpp"
#include "calka.cpp"
#include "calunia.cpp"
#include "wsk.cpp"
#include "punkty.cpp"
#include "tstu.cpp"
#include "mnk.cpp"
#include "wykmnk.cpp"
#include "osiehist.cpp"
#include "hist.cpp"
#include "fun2z.cpp"
#include "wcs2ccs.cpp"
#include "ccs2fcs.cpp"
#include "rysuj3d.cpp"

//----------> MAIN:

int main(){
int dimx = 400, dimy = 300;
double reX1, reY1;
double nsx, nsy;
int m, n, k, xiy = 0;
char xname[50];
char yname[50];
double *pX;
double *pY;
double a = 0, b = 0;
double Sy, Sa, Sb, deltaA, deltaB;
double var, sbk, hk, hsx, hsy;
double lx, px, ly, py, x, y, z, kX, kY, kZ, tx, ty, tz, d;
double staryx, staryy, staryz;
int t;
//double zcp;

directvideo = 0;

int X = 0, Y = 0;
int X1 = 0, Y1 = 0;

osie o1(X,Y);
wsk wsk1(X1,Y1);
osiehist o2(X,Y);

int GD, GM;
//detectgraph(&GD, &GM);
GD = DETECT;
GM = 2;
initgraph(&GD, &GM, "bgi");
setbkcolor(BLACK);

rectangle(220,90,420,390);
setcolor(BLUE);
line(221,391,420,391);
line(222,392,421,392);
line(223,393,422,393);
line(421,91,421,390);
line(422,92,422,391);
line(423,93,423,392);
setcolor(WHITE);
setlinestyle(1,0,1);
line(220,145,420,145);
line(220,335,420,335);

gotoxy(30,8);
cout << "FIZYG menu:";
gotoxy(30,11);
cout << "Nacisnij klawisz (n):";
gotoxy(30,13);
cout << "(1) wykres funkcji";
gotoxy(30,14);
cout << "(2) metoda najm. kwad.";
gotoxy(30,15);
cout << "(3) histogram";
gotoxy(30,16);
cout << "(4) wykres 3D";
gotoxy(30,18);
cout << "Powodzenia!";
gotoxy(30,23);
cout << "(Esc) koniec";

double sx, sy, pl, pp, h, cl, cp, ro;
sx = 1;
sy = 1;
pl = 1;
pp = 1;
h = 0.01;
cl = 1;
cp = 1;
ro = 3;

char co;
co = getch();
if(co == 27){
	closegraph();
	return 0;
}
cleardevice();
grafika:
switch(co){

	case '1':
//---------->  1:
gotoxy(1,1);

if(fun[0] == 'A'){
cout << "f(x) = ";
cin >> fun;
/*cout << "Sx = ";
cin >> sx;
cout << "Sy = ";
cin >> sy;
cout << "poczatek przedzialu = ";
cin >> pl;
cout << "koniec przedzialu = ";
cin >> pp;
cout << "dolna granica calkowania = ";
cin >> cl;
cout << "gorna granica calkowania = ";
cin >> cp;*/
sx = 1;
sy = 1;
pl = -5;
pp = 5;
cl = 0;
cp = 0;
//fun[0] = '1';
}

cleardevice();

o1.show();
calka(sx,sy,cl,cp,Y,ro);
pochodna(sx,sy,pl,pp,h);
wykres(sx,sy,pl,pp);
wsk1.show();

gotoxy(67,3);
cout << "- f(x)";
gotoxy(67,4);
cout << "- df(x)/dx";
gotoxy(69,5);
cout << char(218);
gotoxy(67,6);
cout << "- " << char(217) << "f(x)dx";

setcolor(YELLOW);
line(440,40,510,40);
setcolor(RED);
line(440,55,510,55);
setcolor(GREEN);
for(m = 440; m <= 510; m += ro){
	for(n = 70; n <= 100; n += ro){
		line(m,n,m+1,n+1);
		//cout << m << "; " << n << endl;
	}
}

gotoxy(56,11);
cout << "(1) Sx = " << sx;
gotoxy(56,12);
cout << "(2) Sy = " << sy;
gotoxy(56,13);
cout << "(3) Pl = " << pl;
gotoxy(56,14);
cout << "(4) Pp = " << pp;
gotoxy(56,15);
cout << "(5) Cd = " << cl;
gotoxy(56,16);
cout << "(6) Cg = " << cp;
gotoxy(56,17);
cout << "(7) kursor";

gotoxy(4,21);
cout << cp;
gotoxy(4,22);
cout << "  " << char(218);
gotoxy(4,23);
cout << "  " << char(217) << "f(x)dx = " << calunia(cl,cp,0.0001);
gotoxy(4,24);
cout << cl;
gotoxy(28,21);
cout << "polozenie kursora:";
gotoxy(28,22);
nsx = sx*(dimx/10);
nsy = sy*(dimy/10);
reX1 = (X1 - (dimx/2))/nsx;
reY1 = -((Y1-(dimy/2))/nsy);
cout << "K = (" << reX1 << ";" << reY1 << ")";

	break;

	case '2':
//----------> 2:
cleardevice();
gotoxy(1,1);

if(xiy == 0){
	cout << "n = ";
	cin >> n;
	cout << "plik z iksami: ";
	//cin.getline(xname,49);
	cin >> xname;
	cout << "plik z igrekami: ";
	//cin.getline(yname,49);
	cin >> yname;

//	cout << "Sx = ";
//	cin >> sx;
//	cout << "Sy = ";
//	cin >> sy;
	sx = 1;
   sy = 1;

	pX = new double [n];
	pY = new double [n];

	ifstream plikX(xname);
	for(int i = 0; i < n; i++){
		plikX >> pX[i];
	}
	plikX.close();

	ifstream plikY(yname);
	for(i = 0; i < n; i++){
		plikY >> pY[i];
	}
	plikY.close();

	xiy = 1;
}

cleardevice();
o1.show();
mnk(&a,&b,pX,pY,n,&Sy,&Sa,&Sb,&deltaA,&deltaB);
wykmnk(sx,sy,&a,&b);
punkty(sx,sy,pX,pY,n);
gotoxy(4,21);
cout << "a       = " << a << endl;
cout << "   b       = " << b << endl;
cout << "   Sy      = " << Sy << endl;
cout << "   Sa      = " << Sa << endl;
cout << "   Sb      = " << Sb << endl;
cout << "   delta a = " << deltaA << endl;
cout << "   delta b = " << deltaB << endl;

setlinestyle(0,0,1);
setcolor(YELLOW);
line(472,52,477,57);
line(477,52,472,57);
gotoxy(67,4);
cout << "- punkt";
setcolor(RED);
line(440,70,510,70);
gotoxy(67,5);
cout << "- prosta";
gotoxy(67,6);
cout << "  y = a + bx";

gotoxy(56,11);
cout << "(1) Sx = " << sx;
gotoxy(56,12);
cout << "(2) Sy = " << sy;
gotoxy(56,13);
cout << "(7) kursor";
gotoxy(28,21);
cout << "polozenie kursora:";
gotoxy(28,22);
nsx = sx*(dimx/10);
nsy = sy*(dimy/10);
reX1 = (X1 - (dimx/2))/nsx;
reY1 = -((Y1-(dimy/2))/nsy);
cout << "K = (" << reX1 << ";" << reY1 << ")";

wsk1.show();

	break;

	case '3':
//----------> 3:
cleardevice();
gotoxy(1,1);

if(xiy == 0){
	cout << "n = ";
	cin >> n;
	cout << "plik z liczbami: ";
	//cin.getline(xname,49);
	cin >> xname;
//	cout << "liczba klas = ";
//	cin >> k;
	k = int(sqrt(n));

	pX = new double [n];

	ifstream plikX(xname);
	for(int i = 0; i < n; i++){
		plikX >> pX[i];
	}
	plikX.close();

	xiy = 1;
}

cleardevice();
o2.show();

setfillstyle(4,4);
bar3d(465,20,485,90,0,1);
gotoxy(67,4);
cout << "- slupek";
gotoxy(67,5);
cout << "  klasy";

gotoxy(56,11);
cout << "(8) liczba klas = " << k;

hist(pX,n,k,&var,&hk,&hsx,&hsy);
sbk = sqrt(var);
gotoxy(4,21);
cout << "sredni blad kwad. = " << sbk << endl;
gotoxy(4,22);
cout << "wariancja         = " << var << endl;
gotoxy(4,23);
cout << "szerokosc klasy   = " << hk << endl;
gotoxy(4,24);
cout << "Sx                = " << hsx << endl;
gotoxy(4,25);
cout << "Sy                = " << hsy << endl;

	break;

	case '4':
//----------> 4:
cleardevice();
gotoxy(1,1);

if(fun[0] == 'A'){
cout << "f(x,y) = ";
cin >> fun;
//cout << "poczatek przedzialu x = ";
//cin >> lx;
cout << "koniec przedzialu x = ";
cin >> px;
//cout << "poczatek przedzialu y = ";
//cin >> ly;
cout << "koniec przedzialu y = ";
cin >> py;

//strcpy(fun, "*[/[S(+[x][y])][+[x][y]]][5]");
//strcpy(fun, "/[+[y][x]][x]");
//strcpy(fun, "-[x][y]");
lx = 0;
//px = 30;
ly = 0;
//py = 30;


kX = -1.57;
kY = -1.57;
kZ = 0;
tx = 0;
ty = 3;
tz = 5;
d = 30;
//fun[0] = '1';
}

gotoxy(1,1);
cleardevice();

setlinestyle(0,0,1);

for(x = 0; x <= px; x += 0.01){
	staryx = x;
	y = 0;
	z = 0;
	wcs2ccs(&x,&y,&z,kX,kY,kZ,tx,ty,tz);
	ccs2fcs(&x,&y,z,d);
	rysuj3d(x,y,2);
	x = staryx;
}

for(y = 0; y <= py; y += 0.01){
	staryy = y;
	x = 0;
	z = 0;
	wcs2ccs(&x,&y,&z,kX,kY,kZ,tx,ty,tz);
	ccs2fcs(&x,&y,z,d);
	rysuj3d(x,y,3);
	y = staryy;
}

for(z = 0; z <= 10; z += 0.01){
	staryz = z;
	x = 0;
	y = 0;
	wcs2ccs(&x,&y,&z,kX,kY,kZ,tx,ty,tz);
	ccs2fcs(&x,&y,z,d);
	rysuj3d(x,y,4);
	z = staryz;
}

for(x = lx; x <= px; x += 0.1){
	for(y = ly; y <= py; y+= 0.1){
		staryx = x;
		staryy = y;
		z = f2z(x, y, 0, 200);
//		zcp = z;
		wcs2ccs(&x,&y,&z,kX,kY,kZ,tx,ty,tz);
		ccs2fcs(&x,&y,z,d);
//		if(zcp == int(zcp)){
//			rysuj3d(x,y,1);
//		}
//		else{
			rysuj3d(x,y,0);
//		}
		x = staryx;
		y = staryy;
	}
}

gotoxy(67,3);
cout << "- os X";
gotoxy(67,4);
cout << "- os Y";
gotoxy(67,5);
cout << "- os Z";

setcolor(RED);
line(440,40,510,40);
setcolor(GREEN);
line(440,55,510,55);
setcolor(BLUE);
line(440,70,510,70);

gotoxy(56,11);
cout << "(z) kat X = " << kX;
gotoxy(56,12);
cout << "(x) kat Y = " << kY;
gotoxy(56,13);
cout << "(c) kat Z = " << kZ;
gotoxy(56,14);
cout << "(a) wsp. tx = " << tx;
gotoxy(56,15);
cout << "(s) wsp. ty = " << ty;
gotoxy(56,16);
cout << "(d) wsp. tz = " << tz;
gotoxy(56,17);
cout << "(q) wsp. d = " << d;
gotoxy(4,21);
cout << "naciskaj spacje, zeby generowac wykres...";
gotoxy(4,23);
cout << "(w) koniec przedzialu x = " << px;
gotoxy(4,24);
cout << "(e) koniec przedzialu y = " << py;


	break;

	default:
	cleardevice();
	gotoxy(1,1);
	cout << "Nie wiem, co to znaczy...\nDo widzenia!";
	unsigned time = 3000;
	delay(time);
	closegraph();
	return 0;
}

setlinestyle(0,0,1);
setcolor(WHITE);
rectangle(10,310,410,470);
rectangle(420,10,630,300);
rectangle(420,310,630,470);
setcolor(BLUE);
line(11,471,410,471);
line(12,472,411,472);
line(13,473,412,473);
line(411,311,411,470);
line(412,312,412,471);
line(413,313,413,472);

line(421,301,630,301);
line(422,302,631,302);
line(423,303,632,303);
line(631,11,631,300);
line(632,12,632,301);
line(633,13,633,302);

line(421,471,630,471);
line(422,472,631,472);
line(423,473,632,473);
line(631,311,631,470);
line(632,312,632,471);
line(633,313,633,472);

gotoxy(56,9);
cout << "(n), zeby zmienic:";
gotoxy(56,18);
cout << "(Esc) koniec";

gotoxy(56,22);
cout << "FIZYG";
gotoxy(56,23);
cout << "wersja:     0.5.5";
gotoxy(56,24);
cout << "data mod.:  03.06.2006";
gotoxy(56,25);
cout << "autor:    Jerzy Pabich";

char ch;
while(1){
	ch = getch();
	if(ch == 27){
		break;
	}
	cleardevice();
	gotoxy(1,1);
	switch(ch){

		case '1':
		cout << "Sx = ";
		cin >> sx;
		break;

		case '2':
		cout << "Sy = ";
		cin >> sy;
		break;

		case '3':
		cout << "poczatek przedzialu = ";
		cin >> pl;
		break;

		case '4':
		cout << "koniec przedzialu = ";
		cin >> pp;
		break;

		case '5':
		cout << "dolna granica calkowania = ";
		cin >> cl;
		break;

		case '6':
		cout << "gorna granica calkowania = ";
		cin >> cp;
		break;

		case '7':
		wsk1.show();
		o1.show();

setcolor(WHITE);
rectangle(420,10,630,300);
setcolor(BLUE);
line(421,301,630,301);
line(422,302,631,302);
line(423,303,632,303);
line(631,11,631,300);
line(632,12,632,301);
line(633,13,633,302);
gotoxy(56,3);
cout << "menu kursora:";
setlinestyle(1,0,1);
setcolor(WHITE);
line(420,60,630,60);

gotoxy(56,6);
cout << "sterowanie:";

gotoxy(56,8);
cout << "(w) do gory";
gotoxy(56,9);
cout << "(s) do dolu";
gotoxy(56,10);
cout << "(a) w lewo";
gotoxy(56,11);
cout << "(d) w prawo";

gotoxy(56,12);
cout << "(i) szybko do gory";
gotoxy(56,13);
cout << "(k) szybko do dolu";
gotoxy(56,14);
cout << "(j) szybko w lewo";
gotoxy(56,15);
cout << "(l) szybko w prawo";

gotoxy(56,17);
cout << "(7) powrot";

char kur;
	while(1){
		kur = getch();
		if(kur == '7'){
			goto kursor;
		}
		wsk1.hide();
		switch(kur) {

			case 'w':
			if(Y1 > 0)
			wsk1.setXY(X1,Y1-=1);
			break;

			case 's':
			if(Y1 < dimy)
			wsk1.setXY(X1,Y1+=1);
			break;

			case 'a':
			if(X1 > 0)
			wsk1.setXY(X1-=1,Y1);
			break;

			case 'd':
			if(X1 < dimx)
			wsk1.setXY(X1+=1,Y1);
			break;

			case 'i':
			if(Y1 > 0){
				wsk1.setXY(X1,Y1-=10);
			}
			else{
				wsk1.setXY(X1,0);
			}
			break;

			case 'k':
			if(Y1 < dimy){
				wsk1.setXY(X1,Y1+=10);
			}
			else{
				wsk1.setXY(X1,dimy);
			}
			break;

			case 'j':
			if(X1 > 0){
				wsk1.setXY(X1-=10,Y1);
			}
			else{
				wsk1.setXY(0,Y1);
			}
			break;

			case 'l':
			if(X1 < dimx){
				wsk1.setXY(X1+=10,Y1);
			}
			else{
				wsk1.setXY(dimx,Y1);
			}
			break;
			}
		wsk1.show();
		o1.show();
	}
		kursor:
		break;

		case '8':
		cout << "liczba klas = ";
		cin >> k;
		break;

		case 'z':
		cout << "kat X = ";
		cin >> kX;
		break;

		case 'x':
		cout << "kat Y = ";
		cin >> kY;
		break;

		case 'c':
		cout << "kat Z = ";
		cin >> kZ;
		break;

		case 'a':
		cout << "wsp. tx = ";
		cin >> tx;
		break;

		case 's':
		cout << "wsp. ty = ";
		cin >> ty;
		break;

		case 'd':
		cout << "wsp. tz = ";
		cin >> tz;
		break;

		case 'q':
		cout << "wsp. d = ";
		cin >> d;
		break;

		case 'w':
		cout << "koniec przedzialu x = ";
		cin >> px;
		break;

		case 'e':
		cout << "koniec przedzialu y = ";
		cin >> py;
		break;

	}
	goto grafika;
}


koniec:

closegraph();
return 0;
}
