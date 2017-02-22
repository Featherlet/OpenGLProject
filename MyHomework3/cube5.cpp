#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

extern void drawEavedPlane1();
extern void drawEavedPlane2();
extern void drawEavedPlane3();
extern void rect_xoy(float a,float b,float c,float d, float z, int normal);
extern void rect_xoz(float a,float b,float c,float d, float y, int normal);
extern void rect_yoz(float a,float b,float c,float d, float x, int normal);
extern void drawCircular( float r, float h );
extern void drawCube( float x1, float x2, float y1, float y2, float z1, float z2);
extern void drawRinger( float rmax, float rmin, float amax, float amin, float h );
extern void drawParallelogram(float x1, float x2, float x3, float x4, float y1, float y2, float h);

//============================Y================================
void drawY(){
	glPushMatrix();
	glTranslatef(0,0,8);
	drawParallelogram(3, 5, -1, 1, 5, 0, 2);
	drawParallelogram(-5, -3, -1, 1, 5, 0, 2);
	drawCube(-1,1,-5,0,0,2);
	glPopMatrix();
}

//===========================Z=============================================
void drawZ(){
	glPushMatrix();
	glTranslatef(0,0,8);
	drawParallelogram(3, 5, -5, -3, 5, -5, 2);
	glPopMatrix();
	drawCube(-3, 5, -5, -3, 8, 10);
	drawCube(-5, 3, 3, 5, 8, 10);
}

//================Polygon=================================================
void drawpolygon(){
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f,0.5f,0.0f);
	glNormal3f(0, 0, -1);
	glVertex3f(-6, 1, 8);
	glVertex3f(0, 6, 8);
	glVertex3f(0, 0, 8);

	glVertex3f(0, 6, 8);
	glVertex3f(6, 1, 8);
	glVertex3f(0, 0, 8);

	glVertex3f(6, 1, 8);
	glVertex3f(3, -6, 8);
	glVertex3f(0, 0, 8);

	glVertex3f(3, -6, 8);
	glVertex3f(-3, -6, 8);
	glVertex3f(0, 0, 8);
	
	glVertex3f(-6, 1, 8);
	glVertex3f(-3, -6, 8);
	glVertex3f(0, 0, 8);

	glNormal3f(0, 0, 1);
	glVertex3f(-6, 1, 10);
	glVertex3f(0, 6, 10);
	glVertex3f(0, 0, 10);

	glVertex3f(0, 6, 10);
	glVertex3f(6, 1, 10);
	glVertex3f(0, 0, 10);

	glVertex3f(6, 1, 10);
	glVertex3f(3, -6, 10);
	glVertex3f(0, 0, 10);

	glVertex3f(3, -6, 10);
	glVertex3f(-3, -6, 10);
	glVertex3f(0, 0, 10);

	glVertex3f(-6, 1, 10);
	glVertex3f(-3, -6, 10);
	glVertex3f(0, 0, 10);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5f,0.0f,0.0f);
	glNormal3f(-5, 6, 0);
	glVertex3f(-6, 1, 10);
	glVertex3f(-6, 1, 8);
	glVertex3f(0, 6, 8);
	glVertex3f(0, 6, 10);

	glNormal3f(5, 6, 0);
	glVertex3f(0, 6, 10);
	glVertex3f(0, 6, 8);
	glVertex3f(6, 1, 8);
	glVertex3f(6, 1, 10);
	
	glNormal3f(7, -3, 0);
	glVertex3f(6, 1, 10);
	glVertex3f(6, 1, 8);
	glVertex3f(3, -6, 8);
	glVertex3f(3, -6, 10);

	glNormal3f(0, -1, 0);
	glVertex3f(3, -6, 10);
	glVertex3f(3, -6, 8);
	glVertex3f(-3, -6, 8);
	glVertex3f(-3, -6, 10);

	glNormal3f(-7, -3, 0);
	glVertex3f(-6, 1, 10);
	glVertex3f(-6, 1, 8);
	glVertex3f(-3, -6, 8);
	glVertex3f(-3, -6, 10);
	glEnd();	
}

//===========Draw Cube4=========================================================
void drawCube5(){
	drawEavedPlane1();
	glPushMatrix();
	drawY();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawZ();
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane1();
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawCircular(6, 2);
	glPopMatrix();

	glRotated(90, 0, 10, 0);
	drawEavedPlane2();
	glPushMatrix();
	drawpolygon();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 10, 0, 0);
	drawEavedPlane3();
	drawY();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 10, 0, 0);
	drawEavedPlane3();
	glPushMatrix();
	glTranslatef(0, 0, 8);
	drawCircular(6, 2);
	glPopMatrix();
	glPopMatrix();
}


