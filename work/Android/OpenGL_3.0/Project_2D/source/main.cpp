#include"stdafx.h"

struct bricks b[45];
float red1,red2,green1,green2,blue1,blue2;
struct ball ball;
struct block block;

float red=0.0;                                                             
float green=0.0;                                                                
float blue=0.0; 

void initialize()	//To set the initial co-ordinates of the objects on the screen
{
	for(int n = 0, x = 4 ,y = 400-25/*390*/; n < 45 ; n++ , x += 66 )//total 45 bricks  600/9-in each row nine bricks,window width 600/9=66. 400-10=390 or each level of 25 units at y axis
	{
	   if(x>560)//after each row completion x again set to 4,y decrement to 25.  x,y postion
	   {
	     x=4;
	     y-=25;
	   }
	   b[n].x=x;              // for each brick , information will be stored in structure like position and width and height.
	   b[n].y=y;
	   b[n].w=60;//Brick width
	   b[n].h=20;//Brick height
	   b[n].alive=true; //initial flag true
	}
	
	block.myx=300;// slide initial position
	block.myy=0;//slide initial position
	block.width=80;//slide width
	block.height=20;//slider height
	block.lft=false;//initial stable pos
	block.rgt=false;//
	
	ball.ballx=300;//ball position
	ball.bally=20;// above the slider //200 /modf 
	ball.ballwh=30;//ball width
	ball.velx=0.85;//velocity of ball x axis 
	ball.vely=0.85;//velocity of ball y axis
	
	red1=1.0;//bricks colour0.96
 	green1=1.0;//0.8;
 	blue1=0.69;
 	red2=0.6;
 	green2=0.8;
	blue2=0.196078;
	
	ball.red=1.0;//ball colour0.65
	ball.green=0.0;//0.49;
	ball.blue=0.0;//0.24;
	
	block.red=0.0;//0.137255;//slider colour
	block.green=0.0;//0.556863;
	block.blue=1.0;//0.419608;

}
bool check_collision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh) //Function for checking collision a-> ball b-> bricks[DO MODIICATION]
{
  if ( Ay+Ah < By ) return false; //if A is more to the lft than B
  else if ( Ay > By+Bh ) return false; //if A is more to rgt than B
  else if ( Ax+Aw < Bx ) return false; //if A is higher than B
  else if ( Ax > Bx+Bw ) return false; //if A is lower than B
 
  return true; //There is a collision because none of above returned false
}
void drawBitmapText(char *string,float x,float y,float z)  //function to show message
{  
	char *c;
	glRasterPos2f(x, y);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}

}
void reshape()		//Modify the co-ordinates according to the key-presses and collisions etc...
{
	if(block.myx<0) //slider < 0
	  block.myx=0;
	if(block.myx+block.width>600) 
	  block.myx=520;
	if(block.lft==true)
	  block.myx=block.myx-0.10; // init val = 0.05
	if(block.rgt==true)
	  block.myx=block.myx+0.10;
	  
	
	  
	ball.ballx+=0.05*ball.velx; // move ball to some cordinated 
	ball.bally+=0.05*ball.vely; // moving towards right top corner
	
	for(int n=0;n<45;n++) // for 45 bricks we'll check for collision
	{
	   if(b[n].alive==true)
	   {
	   	if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,b[n].x,b[n].y,b[n].w,b[n].h)==true)
	   	{
	   	  ball.vely=-ball.vely;
	   	  b[n].alive=false;
	   	  ball.down=true;
	   	  ball.up=false;
		  bricks_count--;
  			if(bricks_count ==0) // Successful completion of Game
			{
	/*		glClear(GL_COLOR_BUFFER_BIT); 
			glLoadIdentity();

			drawBitmapText("CONGRATULATIONS !!!! Successfully completed the game!!",200,200,0) ;
			glutSwapBuffers(); 	*/		
			exit(0);
			}
	   	  break;
	   	}
	   }
	}
	if(ball.ballx<0)
	{
		ball.velx=-ball.velx;
		ball.right=true;
		ball.left=false;
	}
	if(ball.ballx+ball.ballwh>600)
	{
		ball.right=false;
		ball.left=true;
		ball.velx=-ball.velx;
	}
	if(ball.bally+ball.ballwh>400)
		ball.vely=-ball.vely;
	
	else if(ball.bally<0)
		{	
			/*glClear(GL_COLOR_BUFFER_BIT); 
			glLoadIdentity();
				glColor3f(0.0,1.0,0.0);
			drawBitmapText("Game Over !!!",300,100,0) ;
			glutSwapBuffers(); 			
			*/
			//while(1);	//exit condition
		exit(0);
		}	
	if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,block.myx,block.myy,block.width,block.height)==true) //colision of ball with block
	{
			ball.vely = -ball.vely;
			ball.up = true;
			ball.down = false;
	}
	draw();
}
void myinit()
{
	glViewport(0,0,600,400);//x,y,w,h  viewing port modification (full screen mode)
	glLoadIdentity();//default to identitiy matrix like clering
	glShadeModel(GL_SMOOTH);//flat and smooth colour
	glMatrixMode(GL_PROJECTION);//GL projection:for screen orientation changes
				    //GL modelview:for camera changes
				    //GL texture:by default
	gluOrtho2D(0,600,0,400);//2D projection
}


void draw()		//Render the objects on the screen using the latest updated co-ordinates 
{	
	for(int i=0;i<45;i++) //45 bricks
	{
		if(b[i].alive==true)
		{
		   if(i%2==0) glColor3f(red1,green1,blue1);
		   else glColor3f(red2,green2,blue2);
		   glBegin(GL_POLYGON);                                  //each brick made up of 4 vertexes -> 1- (x,y) 2-> (x+w,y) 3-> (x+w ,y+h) 4-> (x, y+h)
			   glVertex2f(b[i].x,b[i].y);
			   glVertex2f(b[i].x+b[i].w,b[i].y);
			   glVertex2f(b[i].x+b[i].w,b[i].y+b[i].h);
			   glVertex2f(b[i].x,b[i].y+b[i].h);
		   glEnd();
		}
	}
	
	glColor3f(block.red,block.green,block.blue);//color and slider position with coordinates
	glBegin(GL_POLYGON);
		glVertex2f(block.myx,block.myy);
		glVertex2f(block.myx+block.width,block.myy);
		glVertex2f(block.myx+block.width,block.myy+block.height);
		glVertex2f(block.myx,block.myy+block.height);
	glEnd();
	
	glColor3f(ball.red,ball.green,ball.blue);//colour and ball position with coordinates
	glBegin(GL_POLYGON);
		glVertex2f(ball.ballx,ball.bally);
		glVertex2f(ball.ballx+ball.ballwh,ball.bally);
		glVertex2f(ball.ballx+ball.ballwh,ball.bally+ball.ballwh);
		glVertex2f(ball.ballx,ball.bally+ball.ballwh);
	glEnd();
	glutPostRedisplay();//glutPostRedisplay marks the current window as needing to be redisplayed. 
	glutSwapBuffers(); //glutSwapBuffers swaps the buffers of the current window if double buffered. 
//Performs a buffer swap on the layer in use for the current window. Specifically, glutSwapBuffers promotes the contents of the back buffer of the layer in use of the current window to become the contents of the front buffer. 
// If the layer in use is not double buffered, glutSwapBuffers has no effect. 
	
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //clear buffers to preset values GL_COLOR_BUFFER_BIT Indicates the buffers currently enabled for color writing.
	glClearColor(red,green,blue,1); //specify clear values for the color buffers
	glDisable(GL_DEPTH_TEST); //GL_DEPTH_TEST -the depth buffer is not updated if the depth test is disabled. 
	draw(); 
	glFlush(); //glFlush — force execution of GL commands in finite time
	reshape(); //
}
void processmenu(int opt)
{
	switch(opt)
	{
		case CONTINUE:
			revert();
			break;
		case INC:
			ball.velx++;
			ball.vely++;
			break;
		
		case QUIT: exit(0);
	}
	
}
void revert()
{
	ball.velx=0.85;
	ball.vely=0.85;
	if(ball.up==true)
	{
		if(ball.right==true)
		{
			ball.velx=ball.velx;
			ball.vely=ball.vely;
		}
		else if(ball.left==true)
		{
			ball.velx=-ball.velx;
			ball.vely=ball.vely;
		}
	}
	else if(ball.down=true)
	{
		if(ball.right=true)
		{
			ball.velx=ball.velx;
			ball.vely=-ball.vely;
		}
		else if(ball.left==true)
		{
			ball.velx=-ball.velx;
			ball.vely=-ball.vely;
		}
	}
}
int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitWindowSize(600,400);//600,400
	glutInitWindowPosition(100,100);
	glutCreateWindow("DEX-BALL BREAKER");
	initialize();
	myinit();
	draw();
	glutDisplayFunc(display); //callback function called when need to be redraw
        glutSpecialFunc(specialDown); // glutSpecialFunc sets the special keyboard down(press) callback for the current window. 
    	glutSpecialUpFunc(specialUp);//sets the special keyboard up (key release) callback for the current window.
    	glutKeyboardFunc(keyboard); // glutKeyboardFunc sets the keyboard callback for the current window
	glutIdleFunc(reshape); //glutIdleFunc sets the global idle callback. 
	glutMainLoop(); //glutMainLoop enters the GLUT event processing loop. This routine should be called at most once in a GLUT program. Once called, this routine will never return. It will call as necessary any callbacks that have been registered. 
	return 0;
}

