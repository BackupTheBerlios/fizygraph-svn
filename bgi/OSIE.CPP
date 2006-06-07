class osie : public punkt{
	public:
		osie(int nx, int ny);
		~osie(){}

		virtual void draw();
		void show();
		void hide();
};

//----------

osie::osie(int nx, int ny):punkt(nx, ny){
};

void osie::draw(){
	int dimx = 400, dimy = 300;

	setlinestyle(1,0,1);
	setcolor(BLUE);

	for(int i = (dimx/10); i < dimx; i+=(dimx/10)){
		line(x+i, y+10, x+i, y+dimy);
	}

	for(i = (dimy/10); i < dimy; i+=(dimy/10)){
		line(x+10, y+i, x+dimx, y+i);
	}

	setlinestyle(0,0,1);
	setcolor(WHITE);


	line(x+(dimx/2), y+10, x+(dimx/2), y+dimy);
	line(x+10, y+(dimy/2), x+dimx, y+(dimy/2));
	line(x+(dimx/2), y+10, x+(dimx/2)-3, y+15);
	line(x+(dimx/2), y+10, x+(dimx/2)+3, y+15);
	line(x+dimx-5, y+(dimy/2)+3, x+dimx, y+(dimy/2));
	line(x+dimx-5, y+(dimy/2)-3, x+dimx, y+(dimy/2));
}

void osie::show(){
	setcolor(WHITE);
	draw();
}

void osie::hide(){
	setcolor(BLACK);
	draw();
	setcolor(WHITE);
}
