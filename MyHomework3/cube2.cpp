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

//====================A=========================================
void drawA(){
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawParallelogram(-1, 1, 4, 5, 5, -5, 2);
	drawParallelogram(-1, 1, -5, -4, 5, -5, 2);
	drawCube(-2, 2, 1, -1, 0, 2);
	glPopMatrix();
}

//===================B================================
void drawB(){
    glPushMatrix();
	glTranslatef(0,2.5,8);
	drawRinger(3.5,1.5,90,-90,2);
	glTranslatef(0,-5,0);
	drawRinger(3.5,1.5,90,-90,2);
	glPopMatrix();
	
	glPushMatrix();
	drawCube(-3,0,-1,1,8,10);
	drawCube(-3,0,4,6,8,10);
	drawCube(-3,0,-6,-4,8,10);
	drawCube(-5,-3,-6,6,8,10);
	glPopMatrix();
}

//====================C===================================
void drawC(){
    glPushMatrix();
	glTranslatef(0,2,8);
	drawRinger(4,2,180,0,2);
	glTranslatef(0,-4,0);
	drawRinger(4,2,-2,-182,2);
	glPopMatrix();

	drawCube(-4,-2,-2,2,8,10);
	rect_xoz(2,4,8,10,2, -1);
	rect_xoz(2,4,8,10,-2, 1);
}

//====================D================================================
void drawD(){
    glPushMatrix();
	glTranslatef(-2,0,8);
	drawRinger(6,4,90,-90,2);
	drawCube(-2,0,-6,6,0,2);
	glPopMatrix();
	
}

//===========Draw Cube2=========================================================
void drawCube2(){
	drawEavedPlane1();
	drawA();

	glPushMatrix();
	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawB();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane1();
	glPushMatrix();
	drawC();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawD();
	glPopMatrix();
	glPopMatrix();

	//top & bottom
	glPushMatrix();
	glRotated(90, 10, 0, 0);
	drawEavedPlane3();
	drawA();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 10, 0, 0);
	drawEavedPlane3();
	drawD();
	glPopMatrix();
}


