#include"stdafx.h"

extern struct bricks b[45];                                                            
extern float red1,red2,green1,green2,blue1,blue2;                                      
extern struct ball ball;                                                               
extern struct block block;                                                             
                                                                                
extern float red;                                                                  
extern float green;                                                                
extern float blue;

void specialUp(int key,int x,int y) //call back for key release event
{
	switch(key)
	{
		case (GLUT_KEY_LEFT): block.lft=false;
					break;
		case (GLUT_KEY_RIGHT): block.rgt=false;
					break;
	}
}
void specialDown(int key,int x,int y)    //call back for key press event modifying the position
{
	switch(key)
	{
		case (GLUT_KEY_LEFT): block.lft=true;
					break;
		case (GLUT_KEY_RIGHT): block.rgt=true;
				break;
	}
}
void keyboard(unsigned char key,int x,int y)
{
	if(key==27) 		//27 corresponds to the esc key
	{
		ball.velx=0;
		ball.vely=0;	//To stop the ball from moving
		callMenu();    //after escape menu should be called on right mouse click
	}
}
void bg1_menu(int opt) // background color RGB Default menu
{
	switch(opt)
	{
		case RED:	red=1.0;
				green=0.0;
				blue=0.0;
				display();
				break;
		case GREEN:	red=0.0;
				green=1.0;
				blue=0.0;
				display();
			 	break;
		case BLUE:	red=0.0;
				green=0.0;
				blue=1.0;
				display();
			 	break;
		case BLACK:	red=0.0;
				green=0.0;
				blue=0.0;
				display();
			 	break; 
	}
	
}
void bg2_menu(int opt)
{
	switch(opt)
	{
		case GOLD:	ball.red=0.858824;
			  	ball.green=0.858824;
			  	ball.blue=0.439216;
			  	break;
			  	
		case ORCHID:	ball.red=0.858824;
			    	ball.green=0.439216;
			    	ball.blue=0.858824;
			    	break;
	}
}
void bg3_menu(int opt)
{
	switch(opt)
	{
		case C1:
			red1=0.72;
			green1=0.45;
			blue1=0.20;
			red2=0.42;
			green2=0.26;
			blue2=0.15;
			break;
		case C2:
			red1=1;
			green1=0.5;
			blue1=0;
			red2=0.9;
			green2=0.91;
			blue2=0.98;
			break;
		case C3:
			red1=0.858824;
			green1=0.439216;
			blue1=0.858824;
			red2=0.36;
			green2=0.2;
			blue2=0.09;
	}
}
void bg4_menu(int opt)
{
	switch(opt)
	{
		case BLACK1:
			block.red=0.0;
			block.green=0.0;
			block.blue=0.0;
			break;
		case WHITE: 
			block.red=1;
			block.green=1;
			block.blue=1;
			break;
	}
}
void sp_menu(int opt)  //for increasing and decreasing speed of both ball and slider need to be increase
{ 
	switch(opt)
	{
		case INC: 
			ball.velx++;
			ball.vely++;
			break;
		case DEC:
			ball.velx-=0.25;
			ball.vely-=0.25;
			break;
			
	}
}
void main_menu(int opt)
{
	switch(opt)
	{
		case CONTINUE: revert();
			       break;
		case QUIT: exit(0);
	}
}
void callMenu()
{
	int bg,bg1,bg2,bg3,bg4,sp;
	bg1=glutCreateMenu(bg1_menu);                //background color menu
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Default",BLACK);
	
	bg2=glutCreateMenu(bg2_menu);	// ball color menu
	glutAddMenuEntry("gold",GOLD);
	glutAddMenuEntry("Orchid",ORCHID);
	
	bg3=glutCreateMenu(bg3_menu);	//brick combination menu
	glutAddMenuEntry("Combo1",C1);
	glutAddMenuEntry("Combo2",C2);
	glutAddMenuEntry("Combo3",C3);
	
	bg4=glutCreateMenu(bg4_menu);	//block slider color
	glutAddMenuEntry("Black",BLACK1);
	glutAddMenuEntry("White",WHITE);
	
	sp=glutCreateMenu(sp_menu);     //speed menu inc / dec 
	glutAddMenuEntry("Increase",INC);
	glutAddMenuEntry("Decrease",DEC);
	
	bg=glutCreateMenu(main_menu);	// for color submenu
	glutAddSubMenu("Background",bg1); //background color submenu
	glutAddSubMenu("Ball",bg2);	// ball color submenu
	glutAddSubMenu("Brick",bg3);	// brick combination option in submenu
	glutAddSubMenu("Block",bg4);	// block color option in submenu
	
	glutCreateMenu(main_menu); //for continue / quit
	glutAddMenuEntry("Continue",CONTINUE);
	glutAddSubMenu("Color",bg);
	glutAddSubMenu("Speed",sp);
	glutAddMenuEntry("Quit Game",QUIT);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
}
