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

//===========X=========================================================
void drawX(){
    glPushMatrix();
	glTranslatef(0, 0, 8);
	drawParallelogram(3, 5, -5, -3, 5, -5, 2);
	drawParallelogram(-5, -3, 3, 5, 5, -5, 2);
	glPopMatrix();
}

//===========U=========================================================
void drawU(){     
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawRinger( 6, 4, 0, -180, 2);
	drawCube(4,6,0,6,0,2);
	drawCube(-6,-4,0,6,0,2);
	glColor3f(0.0f,0.0f,0.5f);
	rect_xoz(-6, -4, 0, 2, 6, 1);
	rect_xoz(4, 6, 0, 2, 6, 1);
	glPopMatrix();
}


//===========V=========================================================
void drawV(){
    glPushMatrix();
	glTranslatef(0, 0, 8);
	drawParallelogram(3, 5, -1, 1, 5, -5, 2);
	drawParallelogram(-5, -3, -1, 1, 5, -5, 2);
	glPopMatrix();
}

//==================W=========================================================
void drawW(){
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawParallelogram(3.3, 5, 1.75, 2.5, 5, -5, 2);
	drawParallelogram(-5, -3.5, -2.5, -1.75, 5, -5, 2);
	drawParallelogram(-0.75, 0.75, 1.75, 2.5, 1, -5, 2);
	drawParallelogram(-0.75, 0.75, -2.5, -1.75, 1, -5, 2);
	glPopMatrix();
}


//===========Draw Cube1=========================================================
void drawCube1(){
	drawEavedPlane1();
	drawX();

	glPushMatrix();
	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawU();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane1();
	glPushMatrix();
	drawV();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawW();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 10, 0, 0);
	drawEavedPlane3();
	drawX();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 10, 0, 0);
	drawEavedPlane3();
	drawX();
	glPopMatrix();
}


