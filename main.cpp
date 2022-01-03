#include <iostream>
#include <fstream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main()
{
	system("color 2");
	
	void draw();
	void read();
	
	int choose;
	cin>>choose;
	
	switch(choose)
	{	
		case 1 : draw(); break;
		case 2 : read(); break; 
	}
}

//----------functions----------//


/*
	Help:

	1.if you want to draw whit blue color -> press and hold '1'
	2.if you want to draw whit green color -> press and hold '2'
	3.if you want to draw whit red color -> press and hold '3'
	4.if you want to draw whit cyan color -> press and hold '4'
	5.if you want to draw whit magenta color -> press and hold '5'						& move youre mouse.
	6.if you want to draw whit brown color -> press and hold '6'
	7.if you want to draw whit yellow color -> press and hold '7'
	8.if you want to draw whit white color -> press and hold '8'
	9.if you want to draw whit dakgray color -> press and hold '9'
	10.if you want to clear youre draw -> press 'c'
*/


void draw()
{
	initwindow(1000 , 800 , "Code Khol");
	fstream  file_x,file_y,file_color;
	file_x.open("x.txt" , ios :: out);
	file_y.open("y.txt" , ios :: out);
	file_color.open("color.txt" , ios :: out);
	
	if(file_x.is_open() , file_y.is_open() , file_color.is_open())
	{
		while(getch() != 'e')
		{
			switch(getch())
			{
				case '1' : setcolor(1); file_color<<5<<endl; cout<<"color: blue"<<endl; break;
				case '2' : setcolor(2); file_color<<3<<endl; cout<<"color: green"<<endl; break;
				case '3' : setcolor(3); file_color<<3<<endl; cout<<"color: cyan"<<endl; break;
				case '4' : setcolor(4); file_color<<2<<endl; cout<<"color: red"<<endl; break;
				case '5' : setcolor(5); file_color<<5<<endl; cout<<"color: MAGENTA"<<endl; break;
				case '6' : setcolor(6); file_color<<6<<endl; cout<<"color: brown"<<endl; break;
				case '7' : setcolor(14); file_color<<14<<endl; cout<<"color: yellow"<<endl; break;
				case '8' : setcolor(15); file_color<<15<<endl; cout<<"color: white"<<endl; break;
				case '9' : setcolor(8); file_color<<8<<endl; cout<<"color: darkgray"<<endl; break;
			}
			
			if(getch() == 'c')
			{
				cleardevice();
				system("cls");
				file_x.close();
				file_y.close();
				file_x.open("x.txt" , ios :: out);
				file_y.open("y.txt" , ios :: out);	
			}
			
			else
			{
				circle(mousex() , mousey() , 2);
				delay(1);
			//	cout<<mousex()<<" - "<<mousey()<<endl;
				file_x<<mousex()<<endl;
				file_y<<mousey()<<endl;
			}
		}
	}
}

void read()
{
	initwindow(1000 , 800 , "Code Khol");
	fstream file_x , file_y,file_color;
	file_x.open("x.txt" , ios :: in);
	file_y.open("y.txt" , ios :: in);
	file_color.open("color.txt" , ios :: in);
	
	int x,y,color;
	getch();
	
	if(file_x.is_open() , file_y.is_open() , file_color.is_open())
	{
		while(file_x>>x && file_y>>y && file_color>>color)
		{
			cout<<x<<" - "<<y<<endl;
			
			delay(25);
			
			setcolor(color);
			circle(x , y , 2);
			
		}
		delay(4000);
		closegraph();
	}
}