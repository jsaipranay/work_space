#include<stdio.h>
#include<GL/glut.h>  // GLUT, include glu.h and gl.h
//#include<GL/gl.h>
//#include<GL/glu.h>
//#include<stdlib.h>
 /* Main function: GLUT runs as a console application starting at main()  */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
/*void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
 
   glFlush();  // Render now
}*/
void display()
{
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glBegin(GL_POLYGON);            // These vertices form a closed polygon      glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glColor3f(1.0f, 0.0f, 0.0f);	
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.7f, 0.4f);
 	glVertex2f(0.6f, 0.6f);
   	glVertex2f(0.4f, 0.6f);
    	glVertex2f(0.3f, 0.4f);
   glEnd();
 
   glFlush();  // Render now


}
 
int main(int argc, char** argv) 
{
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
   glutInitWindowSize(200,200);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}




