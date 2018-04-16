#include<GL/glut.h>
float counter = 0.0;
void display()
{

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glLoadIdentity(); // First Triangle

 glTranslatef(counter/150 , 0.0 ,-4.0);  //Translate  x axis

 glRotatef(counter, 0.0 , 1.0 , 0.0);

counter = counter + 0.5;
if(counter > 200)
 {
    counter = -220;
 }
 glBegin(GL_TRIANGLES);
      glColor3f(0.0,1.0,0.0);
      glVertex3f(-0.5,-0.5,0.0);		 
 
      glColor3f(1.0,0.0,0.0);
      glVertex3f(0.5,-0.5,0.0);
 
      glColor3f(0.0,0.0,1.0);
      glVertex3f(0,0.5,0.0);
 glEnd();

 glLoadIdentity(); // 2nd Triangle
 glTranslatef(0.0, -0.5 ,-4.0);     // Translation of the Triangle
 glRotatef(5, 0.0 , 1.0 , 0.0);     //Rotation of the Triangle
 
glBegin(GL_TRIANGLES);
      glColor3f(0.0,1.0,0.0);
      glVertex3f(-0.9,-0.1,0.0);
 
      glColor3f(1.0,0.0,0.0);
      glVertex3f(0.1,-0.1,0.0);
      
      glColor3f(0.0,0.0,1.0);
      glVertex3f(-0.5,0.9,0.0);
glEnd();
glutSwapBuffers();
}
 void reshape(int w,int h)
 {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float)w/(float)h, 1.0 , 10.0);
 //angle ,aspect ratio , near cliping plane area ---- far cliping area
  glMatrixMode(GL_MODELVIEW);
 }
 void initOpenGL()
 {
  glClearColor(0.8,0.0,0.0,1.0);
  glEnable( GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
 }
 int main(int argc ,char** argv)
 {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Test");
  initOpenGL();
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
