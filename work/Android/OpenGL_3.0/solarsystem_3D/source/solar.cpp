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
    //	gluPerspective(45, ratio, 1 , 10000);
    gluPerspective(60, ratio, 1 , 20000);

    glMatrixMode(GL_MODELVIEW);
}

void display( void ) /* display function */
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /*clear default window*/

    glLoadIdentity();

    gluLookAt(0.0f, eyeY, eyeZ,
            0.0f, 0.0f, 0.0f,
            0.0f, 1.0f , 0.0f);

    /*--------------------Paths for mercury -------------*/
    glPushMatrix();
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,0.0);	
    //	changeColor(1.0, 1.0, 1.0 , 1.0);
    for(double i = 0; i < 2 * PI ; i += PI/mercuryRadius)
        glVertex3f( cos(i) * mercuryRadius , 1.0 ,sin(i) * mercuryRadius);
    glEnd();

    /*--------------------Paths for vinus -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/vinusRadius)
        glVertex3f( cos(i) * vinusRadius , 1.0 ,sin(i) * vinusRadius);
    glEnd();

    /*--------------------Paths for earth -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/earthRadius)
        glVertex3f( cos(i) * earthRadius , 1.0 ,sin(i) * earthRadius);
    glEnd();
    /*--------------------Paths for mars -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/marsRadius)
        glVertex3f( cos(i) * marsRadius , 1.0 ,sin(i) * marsRadius);
    glEnd();

    /*--------------------Paths for Ju -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/juRadius)
        glVertex3f( cos(i) * juRadius , 1.0 ,sin(i) * juRadius);
    glEnd();
    /*--------------------Paths for sa -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/saRadius)
        glVertex3f( cos(i) * saRadius , 1.0 ,sin(i) * saRadius);
    glEnd();


    /*--------------------Paths for ur -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/urRadius)
        glVertex3f( cos(i) * urRadius , 1.0 ,sin(i) * urRadius);
    glEnd();

    /*--------------------Paths for ne -------------*/
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);	
    for(double i = 0; i < 2 * PI ; i += PI/neRadius)
        glVertex3f( cos(i) * neRadius , 1.0 ,sin(i) * neRadius);
    glEnd();
    glPopMatrix();


    /*---------------------------------------*/
    /*-----------------Sun------------------*/

    glPushMatrix();
    //	changeColor(1.0, 0.0, 0.0 , 0.0);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *sun;
    sun = gluNewQuadric();
    gluSphere(sun , 85,100,100);

    glPopMatrix();

    /**** mercury ****/
    glPushMatrix();

    glRotatef(mercuryAngle, 0.0, 1.0 ,0.0);
    glTranslatef(mercuryRadius , 0.0 ,0.0);

    // changeColor(0.123, 0.13342, 0.123 , 1.0);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Mercury;
    Mercury = gluNewQuadric();
    gluSphere(Mercury , 20,100,100);

    glPopMatrix();

    /*** Venus *****/

    glPushMatrix();

    glRotatef(vinusAngle,0.0,1.0,0.0);
    glTranslatef(vinusRadius,0.0,0.0);

    // changeColor(0.5,1.0,1.0,1.0);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Vinus;
    Vinus = gluNewQuadric();
    gluSphere(Vinus,30,100,100);

    glPopMatrix();

    /*---------------------------------------*/
    /*-----------------Earth-----------------*/
    glPushMatrix();

    glRotatef(earthAngle, 0.0, 1.0, 0.0);
    glTranslatef(earthRadius , 0.0 ,0.0);

    //changeColor(0.137255, 0.9, 0.6 , 0.8);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Earth;
    Earth = gluNewQuadric();
    gluSphere(Earth, 45, 100,100);

    /*---------------------------------------*/
    /*------------------Moon-----------------*/

    glRotatef(5*earthAngle , 0.0, 1.0 ,0.0);
    glTranslatef(70, 0.0 ,0.0);

    //changeColor(0.3098040, 0.184314, 0.184314 , 1.0);
    glColor3f(1.0,1.0,1.0);

    GLUquadric *Moon;
    Moon = gluNewQuadric();
    gluSphere(Moon, 15, 100,100);

    glPopMatrix();	

    /*---------------------------------------*/
    /*-----------------Mars-----------------*/
    glPushMatrix();

    glRotatef(marsAngle, 0.0, 1.0, 0.0);
    glTranslatef(marsRadius , 0.0 ,0.0);

    // changeColor(0.337255, 0.9, 0.6 , 0.8);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Mars;
    Mars = gluNewQuadric();
    gluSphere(Mars, 40, 100,100);

    glPopMatrix();	
    /*-----------------ju-----------------*/
    glPushMatrix();
    glRotatef(juAngle, 0.0, 1.0, 0.0);
    glTranslatef(juRadius , 0.0 ,0.0);
    //changeColor(1.355, 0.9, 0.6 , 0.8);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Ju;
    Ju = gluNewQuadric();
    gluSphere(Ju, 67, 100,100);
    glPopMatrix();	
    /*-----------------sa-----------------*/
    glPushMatrix();

    glRotatef(saAngle, 0.0, 1.0, 0.0);
    glTranslatef(saRadius , 0.0 ,0.0);

    //changeColor(0.955, 0.434, 0.9 , 0.8);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Sa;
    Sa = gluNewQuadric();
    gluSphere(Sa, 62, 100,100);
    
       {
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/80)
       glVertex3f( cos(i) * 80 , 1.0 ,sin(i) * 80);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/81)
       glVertex3f( cos(i) * 81 , 1.0 ,sin(i) * 81);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/82)
       glVertex3f( cos(i) * 82 , 1.0 ,sin(i) * 82);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/83)
       glVertex3f( cos(i) * 83 , 1.0 ,sin(i) * 83);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/84)
       glVertex3f( cos(i) * 84 , 1.0 ,sin(i) * 84);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/85)
       glVertex3f( cos(i) * 85 , 1.0 ,sin(i) * 85);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/87)
       glVertex3f( cos(i) * 87 , 1.0 ,sin(i) * 87);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/88)
       glVertex3f( cos(i) * 88 , 1.0 ,sin(i) * 88);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/90)
       glVertex3f( cos(i) * 90 , 1.0 ,sin(i) * 90);
       glEnd();
       glBegin(GL_POINTS);
       changeColor(1.0, 1.0, 1.0 , 1.0);
       for(double i = 0; i < 2 * PI ; i += PI/91)
       glVertex3f( cos(i) * 91 , 1.0 ,sin(i) * 91);
       glEnd();
       }
       
    glPopMatrix();	


    /*-----------------ur-----------------*/
    glPushMatrix();
    glRotatef(urAngle, 0.0, 1.0, 0.0);
    glTranslatef(urRadius , 0.0 ,0.0);
    glColor3f(1.0,1.0,1.0);
    //changeColor(1.355, 1.9, 0.6 , 0.8);
    GLUquadric *Ur;
    Ur = gluNewQuadric();
    gluSphere(Ur, 64, 100,100);
    glPopMatrix();	

    /*-----------------ne-----------------*/
    glPushMatrix();
    glRotatef(neAngle, 0.0, 1.0, 0.0);
    glTranslatef(neRadius , 0.0 ,0.0);
    //changeColor(0.355, 1.9, 1.2 , 0.8);
    glColor3f(1.0,1.0,1.0);
    GLUquadric *Ne;
    Ne = gluNewQuadric();
    gluSphere(Ne, 67, 100,100);
    glPopMatrix();	


    /******* continues rotation *******/

    mercuryAngle = mercuryAngle + mercury/10;
    vinusAngle = vinusAngle + vinus/20;
    earthAngle = earthAngle + earth/30;
    marsAngle = marsAngle + mars/40;
    juAngle = juAngle + ju/50;
    saAngle = saAngle + sa/60;
    urAngle = urAngle + ur/70;
    neAngle = neAngle + ne/80;




    glutSwapBuffers();

}
void setupMaterials(void)
{
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
   // glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
   // glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
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
            eyeY -= 20.0f ;
            eyeZ -= 20.0f ;
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
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
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

