#include<GL/glut.h>
#include<math.h>
#define PI 3.141
#define WINDOW_XPOS 100
#define WINDOW_YPOS 100
#define WIDTH  640
#define HEIGHT 480
static float earthRadius = 400;

static float earth = 360.0 / 90.00 ;

static float earthAngle = 0.0f;

float eyeX = 0.0f;
float eyeY = 700.0f;
float eyeZ = 1700.0f;

float angle = 0.0;

GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { -1.0, 0.0, 0.0, 0.0 };
GLfloat model_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat mat_ambient_red[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient_yellow[] = { 1.0, 1.0, 0.0, 1.0 };

GLfloat mat_color[] = {1.0 , 1.0, 1.0 , 1.0 };



void changeColor(float r, float g, float b , float a );
void changeSize(int w, int h);
void display( void ); /* display function */
void setupMaterials(void);
void init(void);
void keyboard_special(int key , int x ,int y); /*specialkey function*/
void keyboard(int key , int x ,int y); 
void mouse(int button,int state, int x ,int y);
