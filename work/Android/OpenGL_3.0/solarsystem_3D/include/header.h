#include<GL/glut.h>
#include<math.h>
#define PI 3.141
#define WINDOW_XPOS 100
#define WINDOW_YPOS 100
#define WIDTH  640
#define HEIGHT 480
static float mercuryRadius = 140;
static float vinusRadius = 220;
static float earthRadius = 350;
static float marsRadius = 480;
static float juRadius = 660;
static float saRadius = 800;
static float urRadius = 950;
static float neRadius = 1100;

static float earth = 360.0 / 90.00 ;
static float mercury = 360.0 / 90.00 ;
static float vinus = 360.0 / 90.00 ;
static float mars = 360.0 / 90.00 ;
static float ju = 360.0 / 90.00 ;
static float sa = 360.0 / 90.00 ;
static float ur = 360.0 / 90.00 ;
static float ne = 360.0 / 90.00 ;

static float earthAngle = 0.0f;
static float mercuryAngle = 0.0f;
static float vinusAngle = 0.0f;
static float marsAngle = 0.0f;
static float juAngle = 0.0f;
static float saAngle = 0.0f;
static float urAngle = 0.0f;
static float neAngle = 0.0f;

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
