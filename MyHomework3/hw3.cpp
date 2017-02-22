#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Global Variables
float angle_x=0;
float angle_y=0;
double rotate_x=0;
double rotate_y=20;
double rotate_z=50;
int rotateAngle1=0;
int rotateAngle2=0;
float NumMove=0;
float mouseX, mouseY;
bool mouseLeftDown;
float sm[16] = { 1, 0, 0, 0,
				  0, 0, -1, 0,
				  0, 0, 1, 0,
				  0, -14.8, -14.8, 1 };
//I put those shapes outsides the main file and call them as exern function, so the main file can be more brief.
extern void drawCube1();
extern void drawCube2();
extern void drawCube3();
extern void drawCube4();
extern void drawCube5();
extern void drawNum1();
extern void drawNum2();
extern void drawNum3();
extern void drawNum4();
extern void drawNum5();
extern void drawNum6();
extern void drawNum7();
extern void drawNum8();
extern void drawNum9();
extern void drawNum10();

//The black objets for shadows
extern void drawBlackCube( float x1, float x2, float y1, float y2, float z1, float z2);
extern void drawBlack1();
extern void drawBlack2();
extern void drawBlack3();
extern void drawBlack4();
extern void drawBlack5();
extern void drawBlack6();
extern void drawBlack7();
extern void drawBlack8();
extern void drawBlack9();
extern void drawBlack10();

//Used to upload the texture file which is *.bmp
void loadBMP_custom(const char * imagepath){
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	// Open the file
	FILE * file = fopen(imagepath,"rb");
	if (!file){
		printf("Image could not be openedn"); 
		return;
	}
	if ( fread(header, 1, 54, file)!=54 ){ 
		// If not 54 bytes read : problem
		printf("Not a correct BMP filen");
		return;
	}
	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP filen");
		return;
	}
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);	
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header [0x16]);
	// Some BMP files are misformatted, guess missing information
	// 3 : one byte for each Red, Green and Blue component
	if (imageSize==0)    
		imageSize=width*height*3; 
	// The BMP header is done that way
	if (dataPos==0)      
		dataPos=54; 
	// Create a buffer
	data = new unsigned char [imageSize];
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	//Everything is in memory now, the file can be closed
	fclose(file);
	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Give the image to OpenGL 
	//subtituted GL_BGR to GL_BGRA_EXT
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	if(data)
		delete data;
}


//It set the background with two large white rectangles.
void drawbackground(){
	glColor3f(1, 1, 1);	
    glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(400,200,-60);
	glVertex3f(-400,200,-60);
	glVertex3f(-400,-15,-60);
	glVertex3f(400,-15,-60);
	glNormal3f(0, 1, 0);
	glVertex3f(400,-15,-60);
	glVertex3f(-400,-15,-60);
	glVertex3f(-400,-15,200);
	glVertex3f(400,-15,200);

	glEnd();
}


static void initLight()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}


// This display function is called in each program loop.
void display(){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//clear the buffer of color and depth.
    glMatrixMode( GL_MODELVIEW );//set the camera.
    glLoadIdentity();
	//gluLookAt( rotate_x, rotate_y, rotate_z, 0, 0, 0,0, 1, 0);
	gluLookAt( 0, 20, 60, 0, 0, 0,0, 1, 0);
	glRotatef(angle_x, 0, 1, 0);
	glRotatef(angle_y, 1, 0, 0);
	//set light position
	GLfloat position[] = { 0, 40, 40, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);	
	//set background
	drawbackground();

	//=========draw shadows=========================================
	glPushMatrix();
	glMultMatrixf(sm);//sm is the shadow matrix
	//cube1
	glPushMatrix();
	glTranslatef(-40, 0, 0);
	glRotatef(rotateAngle1, 0, 1, 0);
	drawBlackCube(-10, 10, -10, 10, -10, 10);
	glPopMatrix();
	//cube2
	glPushMatrix();
	glTranslatef(-20, 0, -20);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawBlackCube(-10, 10, -10, 10, -10, 10);
	glPopMatrix();
	//cube3
	glPushMatrix();
	glTranslatef(0, 0, -40);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawBlackCube(-10, 10, -10, 10, -10, 10);
	glPopMatrix();
	//cube4
	glPushMatrix();
	glTranslatef(20, 0, -20);
	glRotatef(rotateAngle1, 0, 1, 0);
	drawBlackCube(-10, 10, -10, 10, -10, 10);
	glPopMatrix();
	//cube5
	glPushMatrix();
	glTranslatef(40, 0, 0);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawBlackCube(-10, 10, -10, 10, -10, 10);
	glPopMatrix();

	//draw nummbers
	glPushMatrix();
	glTranslatef(-40+NumMove, 0, -20+NumMove);
	drawBlack1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90+NumMove, 0, -70+NumMove);
	drawBlack3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-140+NumMove, 0, -120+NumMove);
	drawBlack5();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-190+NumMove, -5, -170+NumMove);
	drawBlack7();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-240+NumMove, 2, -220+NumMove);
	drawBlack9();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(65-NumMove, 0, -45+NumMove);
	drawBlack2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(115-NumMove, 0, -95+NumMove);
	drawBlack4();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(165-NumMove, -2, -145+NumMove);
	drawBlack6();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(215-NumMove, 0, -195+NumMove);
	drawBlack8();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(275-NumMove, 0, -245+NumMove);
	drawBlack10();
	glPopMatrix();

	glPopMatrix();

	//==========draw normal objects=========================
	//put each cube and numbers.
	glPushMatrix();
	glTranslatef(-40, 0, 0);
	glRotatef(rotateAngle1, 0, 1, 0);
	drawCube1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, -20);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawCube2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -40);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawCube3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20, 0, -20);
	glRotatef(rotateAngle1, 0, 1, 0);
	drawCube4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40, 0, 0);
	glRotatef(rotateAngle2, 0, 1, 0);
	drawCube5();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40+NumMove, 0, -20+NumMove);
	drawNum1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90+NumMove, 0, -70+NumMove);
	drawNum3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-140+NumMove, 0, -120+NumMove);
	drawNum5();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-190+NumMove, -5, -170+NumMove);
	drawNum7();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-240+NumMove, 2, -220+NumMove);
	drawNum9();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(65-NumMove, 0, -45+NumMove);
	drawNum2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(115-NumMove, 0, -95+NumMove);
	drawNum4();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(165-NumMove, -2, -145+NumMove);
	drawNum6();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(215-NumMove, 0, -195+NumMove);
	drawNum8();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(275-NumMove, 0, -245+NumMove);
	drawNum10();
	glPopMatrix();

	//show the graphic immedately.
	glutSwapBuffers();
}


//This function will be called if we change the window's shape and isn't used here.
void reshape(int ww,int hh){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	glViewport(0,0,ww,hh);
    gluPerspective( 80, (float)ww/(float)hh, 0.1, 1000 );
}


void animate(){
	rotateAngle1-=4;
	rotateAngle2+=4;
	NumMove+=1;
    glutPostRedisplay();
}

//get the current state of mouse.
void mouseCB(int button, int state, int x, int y){
    mouseX = x;
    mouseY = y;
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            mouseLeftDown = true;
        }else if(state == GLUT_UP)
            mouseLeftDown = false;
			}
}
//use the mouse motion to change the value of angle_x and angle_y so we can see the shapes in different angles.
void mouseMotionCB(int x, int y){
    if(mouseLeftDown){
        angle_x += (x - mouseX)/5.0;
        angle_y += (y - mouseY)/5.0;
        mouseX = x;
        mouseY = y;
    }
    glutPostRedisplay();
}


//This function is used to change the value of angle_x and angle_y so we can see the shapes in different angles.
void specialKeys( int key, int x, int y ) {
	if (key == GLUT_KEY_RIGHT){ //key== 'a';
		angle_x -= 5;						
	}else if (key == GLUT_KEY_LEFT){
		angle_x += 5;						
	}else if (key == GLUT_KEY_UP){
		angle_y += 5;						
	}else if (key == GLUT_KEY_DOWN){
		angle_y -= 5;						
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize( 800, 600 );
	glutCreateWindow("Homework3");
	glFrontFace(GL_CW);
	glEnable(GL_DEPTH_TEST);
	initLight();
	glShadeModel(GL_SMOOTH);
	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
	glViewport(0,0,w, h);
	gluPerspective( 80, (float)w/(float)h, 0.1, 1000 );
	loadBMP_custom("woodtex3.bmp");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouseCB);
	glutMotionFunc(mouseMotionCB);
	glutIdleFunc(animate);
	glutMainLoop();//to garantee the program loop.
	return 0;
}
