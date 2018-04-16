#include<iostream>
#include<math.h>
#include<GL/glut.h>
#define PI 3.141
GLfloat ballRadius = 0.2f; //Radius of the bouncing Ball
int refreshmills = 30;

GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;

GLfloat ballXMax,ballXMin,ballYMax,ballYMin;

GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;

GLdouble clipAreaXleft ,clipAreaXright,clipAreaYBottom,clipAreaYtop;

GLfloat xspeedsave ,yspeedsave;
bool fullScreenMode = true;

bool paused = false;

int windowPosX = 50;
int windowPosY = 50;
int windowWidth = 640;
int windowHeight = 480;

void initGL()
{

	glClearColor(0.0,0.0,0.0,1.0); ///Set Back ground Color

}

void Timer (int value)
{

	glutPostRedisplay();
	glutTimerFunc(refreshmills,Timer,0); //Subsequent Timer call at Millisecond
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear the color buffer
	glMatrixMode(GL_MODELVIEW); //Operate Model view Matrix
	glLoadIdentity(); //Reset model view matrix

	glTranslatef(ballX,ballY,0.0); //Translate to xPos and Ypos

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0,1.0,0.0);  //Green 

	glVertex2f(0.0,0.0);	//Centre of the circle

	int numSegments = 100;

	GLfloat angle;

	for(int i = 0  ; i<= numSegments ; i++) { //last vertex is same as first vertex
		angle = i * 2.0f * PI/numSegments; //360 for all segments
		glVertex2f(cos(angle)*ballRadius ,sin(angle)*ballRadius );
	}

	glEnd();

	glutSwapBuffers(); //Swap front end and Back End

	ballX += xSpeed;
		ballY += ySpeed;

	//Check if the ball exceed the edge
	if(ballX > ballXMax)
	{
		ballX = ballXMax;
		xSpeed = -xSpeed;
	}
	else if (ballX < ballXMin)
	{
		ballX = ballXMin;
		xSpeed = -xSpeed;
	}
		if(ballY > ballYMax)
		{
		ballY = ballYMax;
		ySpeed = -ySpeed;
		}
		else if (ballY < ballYMin)
		{
		ballY = ballYMin;
		ySpeed = -ySpeed;
		}
}

void reshape(GLsizei width,GLsizei height)
{
	if (height == 0) 
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width >= height)
	{
		clipAreaXleft = -1.0 * aspect;
		clipAreaXright = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYtop = 1.0;
	}
	else
	{
		clipAreaXleft = -1.0 ;
		clipAreaXright = 1.0 ;
		clipAreaYBottom = -1.0 /aspect;
		clipAreaYtop = 1.0/aspect;

	}

	glutOrtho2D(clipAreaXleft,clipAreaXright,clipAreaYBottom,clipAreaYtop);


	//	ballXMin = cilpAreaXleft + ballRadius;
	//	ballXMax = cilpAreaXright + ballRadius;
	//	ballYMin = cilpAreaYBottom + ballRadius;
	//	ballYMax = clipAreaYtop + ballRadius;

	ballXMin = clipAreaXleft + ballRadius;
	ballXMax = clipAreaXright - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYtop - ballRadius;

}
void specialKeys(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_F2:    // F1: Toggle between full-screen and windowed mode
			fullScreenMode = !fullScreenMode;         // Toggle state
			if (fullScreenMode) {                     // Full-screen mode
				windowPosX   = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
				windowPosY   = glutGet(GLUT_WINDOW_Y);
				windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
				windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
				glutFullScreen();                      // Switch into full screen
			} else {                                         // Windowed mode
				glutReshapeWindow(640,480); // Switch into windowed mode
				glutPositionWindow(50,50);   // Position top-left corner
			}
			break;
		case GLUT_KEY_RIGHT:
							xSpeed *= 1.05f;
							break;
		case GLUT_KEY_LEFT:
							xSpeed *= 0.95f;
							break;
		case GLUT_KEY_UP:
							ySpeed *= 1.05f;
							break;
		case GLUT_KEY_DOWN:
							ySpeed *= 0.95f;
							break;
		case GLUT_KEY_PAGE_UP:
							ballRadius *= 1.05f;				
							ballXMin = clipAreaXleft + ballRadius;
							ballXMax = clipAreaXright - ballRadius;
							ballYMin = clipAreaYBottom + ballRadius;
							ballYMax = clipAreaYtop - ballRadius;
							break;
		case GLUT_KEY_PAGE_DOWN:
							ballRadius *= 0.95f;				
							ballXMin = clipAreaXleft + ballRadius;
							ballXMax = clipAreaXright - ballRadius;
							ballYMin = clipAreaYBottom + ballRadius;
							ballYMax = clipAreaYtop - ballRadius;
	}
}

void keyboard(unsigned char key,int x, int y)
{
	switch(key){
		case 27: exit(0);
				 break;
	}
}
void mouse(int button ,int state,int x,int y){
	if( (button == GLUT_LEFT_BUTTON || GLUT_RIGHT_BUTTON)  && state == GLUT_DOWN)
	{
		paused = ! paused;
		if(paused)
		{
			xspeedsave = xSpeed ;
			yspeedsave = ySpeed;
			xSpeed = 0 ;
			ySpeed = 0;
		}
		else
		{
			xSpeed = xspeedsave ;
			ySpeed = yspeedsave ;
		}
	}
}

int main(int argc,char**argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50,50);
	glutCreateWindow("BouncingBall");

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);
	glutTimerFunc(0,Timer,0);

	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	glutFullScreen();

	glutMouseFunc(mouse);

	initGL();
	glutMainLoop();

	return 0;
}
