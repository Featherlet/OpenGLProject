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

//=====================M============================================
void drawM(){
	glPushMatrix();
	glTranslatef(0,0,8);
	drawParallelogram(2,3,4,5,5,-5,2);
	drawParallelogram(-3,-2,-5,-4,5,-5,2);
	drawParallelogram(2,3,-1,1,5,-5,2);
	drawParallelogram(-3,-2,-1,1,5,-5,2);
	glPopMatrix();
}

//=========================P====================================================
void drawP(){
    glPushMatrix();
	glTranslatef(-1,3,8);
	drawRinger(3,2,90,-90,2);
	glPopMatrix();
	drawCube(-2,-1,-6,6,8,10);
}

//=========================O===================================================
void drawO(){
    glPushMatrix();
	glTranslatef(0,0,8);
	glScalef(1,1.5,1);
	drawRinger(4,2,360,0,2);
	glPopMatrix();
}

//==============================N==========================================
void drawN(){
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawParallelogram(2, 4, -4, -2, 5, -5, 2);
	drawCube(2, 4, -5, 5, 0, 2);
	drawCube(-4,-2, -5, 5, 0, 2);
	glPopMatrix();
}



//===========Draw Cube4=========================================================
void drawCube4(){
	drawEavedPlane1();
	glPushMatrix();
	glScalef(1.5,1,1);
	drawM();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	glScalef(1.5,1,1);
	drawP();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane1();
	glPushMatrix();
	drawO();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawN();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 10, 0, 0);
	drawEavedPlane3();
	drawO();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 10, 0, 0);
	drawEavedPlane3();
	drawN();
	glPopMatrix();
}


