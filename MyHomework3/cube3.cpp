#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

extern void drawEavedPlane1();
extern void drawEavedPlane2();
extern void drawEavedPlane3();
extern void rect_xoy(float a,float b,float c,float d, float z, int normal);
extern void rect_xoz(float a,float b,float c,float d, float y, int normal);
extern void rect_yoz(float a,float b,float c,float d, float x, int normal);
extern void drawCube( float x1, float x2, float y1, float y2, float z1, float z2);
extern void drawRinger( float rmax, float rmin, float amax, float amin, float h );
extern void drawParallelogram(float x1, float x2, float x3, float x4, float y1, float y2, float h);

//====================E=========================================
void drawE(){
	drawCube(-4,4,-1,1,8,10);
	drawCube(-4,4,4,6,8,10);
	drawCube(-4,4,-6,-4,8,10);
	drawCube(-4,-2,-6,6,8,10);
}

//======================F=================================
void drawF(){
	drawCube(-4,2,-1,1,8,10);
	drawCube(-4,4,4,6,8,10);
	drawCube(-4,-2,-6,6,8,10);
}

//========================G=============================
void drawG(){
    glPushMatrix();
	glTranslatef(0,0,8);
	glScalef(1,1.3,1);
	drawRinger(5,3,330,30,2);
	glColor3f(0, 0.5, 0);
	glBegin(GL_QUADS);
    glVertex3f(4.33,2.5,0);
	glVertex3f(3.46,2,0);
	glVertex3f(3.46,2,2);
	glVertex3f(4.33,2.5,2);

	glVertex3f(4.33,-2.5,0);
	glVertex3f(3.66,-1.7,0);
	glVertex3f(3.66,-1.7,2);
	glVertex3f(4.33,-2.5,2);
    glEnd();
	
	drawCube(0, 5, -2.5, -0.5, 0, 2);
	drawCube(4, 5, -5, -0.5, 0, 2);
	glPopMatrix();
}

//=======================H=============================================
void drawH(){   
	drawCube(-4,-2,-6,6,8,10);
	drawCube(2,4,-6,6,8,10);
	drawCube(-2,2,-1,1,8,10);
}

//===========Draw Cube3=========================================================
void drawCube3(){
	drawEavedPlane1();
	drawE();

	glPushMatrix();
	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawF();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane1();
	glPushMatrix();
	drawG();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawH();
	glPopMatrix();
	glPopMatrix();

	//top & bottom
	glPushMatrix();
	glRotated(90, 10, 0, 0);
	drawEavedPlane3();
	drawE();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 10, 0, 0);
	drawEavedPlane3();
	drawF();
	glPopMatrix();
}


