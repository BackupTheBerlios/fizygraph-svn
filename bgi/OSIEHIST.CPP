class osiehist : public punkt{
	public:
		osiehist(int nx, int ny);
		~osiehist(){}

		virtual void draw();
		void show();
		void hide();
};

//----------

osiehist::osiehist(int nx, int ny):punkt(nx, ny){
};

void osiehist::draw(){
	int dimx = 400, dimy = 300;

	setlinestyle(1,0,1);
	setcolor(BLUE);

	for(int i = (dimx/10)+10; i < dimx; i+=(dimx/10)){
		line(x+i, y+10, x+i, y+dimy);
	}

	for(i = (dimy/10); i < dimy; i+=(dimy/10)){
		line(x+10, y+i, x+dimx, y+i);
	}

	setlinestyle(0,0,1);
	setcolor(WHITE);


	line(x+10, y+10, x+10, y+dimy);
	line(x+10, y+dimy, x+dimx, y+dimy);

	line(x+10, y+10, x+7, y+15);
	line(x+10, y+10, x+13, y+15);
	line(x+dimx-5, y+dimy+3, x+dimx, y+dimy);
	line(x+dimx-5, y+dimy-3, x+dimx, y+dimy);
}

void osiehist::show(){
	setcolor(WHITE);
	draw();
}

void osiehist::hide(){
	setcolor(BLACK);
	draw();
	setcolor(WHITE);
}
