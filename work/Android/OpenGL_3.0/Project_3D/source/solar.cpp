#include "../include/header.h"


void changeColor(float r, float g, float b , float a )
{
	mat_color[0] = r;
	mat_color[1] = g;
	mat_color[2] = b;
	mat_color[3] = a;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,mat_color);
}

void changeSize(int w, int h)
{
	if(h == 0) h = 1;
	float ratio = 1.0 * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0 , 0 ,w ,h);
	//gluPerspective(45, ratio, 1 , 10000);
	gluPerspective(45, ratio, 1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void display( void ) /* display function */
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /*clear default window*/

	glLoadIdentity();

	gluLookAt(0.0f, eyeY, eyeZ,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f , 0.0f);

	/*--------------------Paths -------------*/
	glBegin(GL_POINTS);
	
	changeColor(1.0, 1.0, 1.0 , 1.0);
	for(double i = 0; i < 2 * PI ; i += PI/earthRadius)
		glVertex3f( cos(i) * earthRadius , 1.0 ,sin(i) * earthRadius);

	glEnd();
	/*---------------------------------------*/
	/*-----------------Sun------------------*/

	glPushMatrix();
	
	glRotatef(angle, 0.0f, 1.0f ,0.0f);

	changeColor(1.0, 0.0, 0.0 , 1.0);
	GLUquadric *sun;
	sun = gluNewQuadric();
	gluSphere(sun , 200,200,200);

	glPopMatrix();

	/*---------------------------------------*/
	/*-----------------Earth-----------------*/
	glPushMatrix();

	glRotatef(earthAngle, 0.0, 1.0, 0.0);
	glTranslatef(earthRadius , 0.0 ,0.0);

	changeColor(0.137255, 0.9, 0.6 , 0.8);
	GLUquadric *Earth;
	Earth = gluNewQuadric();
	gluSphere(Earth, 35, 100,100);

	/*---------------------------------------*/
	/*------------------Moon-----------------*/
	
	glRotatef(5*earthAngle , 0.0, 1.0 ,0.0);
	glTranslatef(70, 0.0 ,0.0);
	
	changeColor(0.3098040, 0.184314, 0.184314 , 1.0);
	
	GLUquadric *Moon;
	Moon = gluNewQuadric();
	gluSphere(Moon, 15, 100,100);

	glPopMatrix();	
	
	/*---------------------------------------*/

	earthAngle = earthAngle + earth/10;

	glutSwapBuffers();
}
void setupMaterials(void)
{
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //Background Color of the Window
	setupMaterials();   /**/
	glEnable(GL_LIGHTING); /*Enabling Lighting Effect*/
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);

}
void keyboard_special(int key , int x ,int y) /*specialkey function*/
{
	switch(key)
	{
		case GLUT_KEY_UP:
					eyeY -= 10.0f ;
					eyeZ -= 10.0f ;
					break;
		case GLUT_KEY_DOWN:
					eyeY += 10.0f ;
					eyeZ += 10.0f ;
	}

}
void keyboard(unsigned char key, int x , int y) 
{	
	switch(key)
	{
		case 27:exit(0);/*exit condition with key value*/
				break;
	}
}
void mouse(int button ,int state,int x, int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
				if(state == GLUT_DOWN) 
				{
					glutIdleFunc(display);
				}
				break;
		case GLUT_RIGHT_BUTTON:
				if(state == GLUT_DOWN)
				{
					glutIdleFunc(NULL);
				}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc , argv); /* init GLUT and create window */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowPosition(WINDOW_XPOS,WINDOW_YPOS);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Solar System");

	glutFullScreen();  

	init();  /*one time initialization */

	glutDisplayFunc(display); /*glut callback function*/
	glutIdleFunc(display);

	glutReshapeFunc(changeSize);
	
	glutSpecialFunc(keyboard_special); /*special keyboard function(arrow key function key)*/
	glutKeyboardFunc(keyboard); /*register callback for normal key*/

	glutMouseFunc(mouse);
	glutMainLoop(); /*glut infinite event */

	return 0;
}

