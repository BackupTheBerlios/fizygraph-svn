class wsk : public punkt{
	public:
		wsk(int newx, int newy);
		~wsk(){}

		virtual void draw();
		void show();
		void hide();
};

//----------

wsk::wsk(int newx, int newy) : punkt(newx, newy){
}

void wsk::draw(){

	//setcolor(6);
	setlinestyle(0,0,3);
	line(x+2,y+2,x+9,y+9);
	setlinestyle(0,0,1);
	line(x,y,x,y+7);
	line(x+1,y,x+1,y+6);
	line(x+2,y,x+2,y+5);
	line(x+3,y,x+3,y+4);
	line(x+4,y,x+4,y+3);
	line(x+5,y,x+5,y+2);
	line(x+6,y,x+6,y+1);
	line(x+7,y,x+7,y);



}

void wsk::show(){
	setcolor(6);
	draw();
}

void wsk::hide(){
	setcolor(BLACK);
	draw();
	setcolor(WHITE);
}
