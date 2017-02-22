#include <GL/glut.h>
#include <stdio.h>

// this file collects all the numbers' functions and they are called as extern functions..
extern void rect_xoy(float a,float b,float c,float d, float z, int normal);
extern void rect_xoz(float a,float b,float c,float d, float y, int normal);
extern void rect_yoz(float a,float b,float c,float d, float x, int normal);
extern void drawRinger( float rmax, float rmin, float amax, float amin, float h );
extern void drawCube( float x1, float x2, float y1, float y2, float z1, float z2);
void drawParallelogram(float x1, float x2, float x3, float x4, float y1, float y2, float h);
void drawNum9();

//==========================1======================================
void drawNum1(){
	glPushMatrix();
	glTranslatef(-3, 6, 0);
  	drawRinger( 5, 3, -10, -90, 2 );
	rect_yoz(-5, -3, 0, 2, 0, -1);
	glPopMatrix();
	drawCube( 0, 2, -6, 6, 0, 2);
}


//==========================2======================================
void drawNum2(){
	glPushMatrix();
	glTranslatef(0, 2.5, 0);
    drawRinger(3.5, 2, 180, -45, 2);
	drawParallelogram(1.42, 3.18, -3.5, -1.45, -1.45, -7.4, 2);
	drawCube(-1.5, 3.5, -7.4, -5.8, 0, 2);
	glPopMatrix();
}

//==========================3======================================
void drawNum3(){
    glPushMatrix();
	glTranslatef(0, 2.5, 0);
	drawRinger(3.5, 2, 178, -90, 1.5);
	rect_xoz(-3.5,-2,0,1.5,0,-1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	drawRinger(3.5, 2, 90, -180, 1.5);
	rect_xoz(-3.5,-2,0,1.5,0,1);
	glPopMatrix();
	drawCube(-1, 0.5, -1, 1, 0, 1.5);
}



//==========================4======================================
void drawNum4(){
	drawCube(1, 3, -5, 5, 0, 2);
	drawCube(-4, 4, -2, 0, 0, 2);
	drawParallelogram(1, 3, -4, -2, 5, 0, 2);
}

//==========================5======================================
void drawNum5(){
    glColor3f(0.5f,0.0f,0.0f);	
	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	drawRinger(4, 2.5, 110, -120, 1.5);
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-2, -3.46, 1.5);
		glVertex3f(-2, -3.46, 0);
		glVertex3f(-1.25, -2.16, 0);
		glVertex3f(-1.25, -2.16, 1.5);
	glEnd();
	glPopMatrix();
	drawCube(-1.75, -0.25, -0.5, 6, 0, 1.5);
	drawCube(-1.75, 3.5, 4.5, 6, 0, 1.5);
}



//==========================6======================================
void drawNum6(){
    glColor3f(0.5f,0.0f,0.0f);	
	glPushMatrix();
;	glRotated( 180,0,0,1.0);
	drawNum9();
	glPopMatrix();
}

//==========================7======================================
void drawNum7(){
	glPushMatrix();
	glTranslatef(21, 0, 0);
	drawRinger(22, 20, 178, 150, 2);
	rect_xoz(-22, -20, 0, 2, -1, -1);
	glPopMatrix();
	drawCube(-3.7, 3.7, 10, 12, 0, 2);
}

//==========================8======================================
void drawNum8(){
	glPushMatrix();
	glTranslatef(0, 2.25, 0);
    drawRinger(3, 1.5, 360, 0, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -2.25, 0);
    drawRinger(3, 1.5, 360, 0, 2);
	glPopMatrix();
}

//==========================9======================================
void drawNum9(){
    glColor3f(0.5f,0.0f,0.0f);	
    glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-4,0,2);
		glVertex3f(-2,0,2);
		glVertex3f(-2,-0.2,2);
		glVertex3f(-4,-0.1,2);

		glNormal3f(0, 0, -1);
		glVertex3f(-2,0,0);
		glVertex3f(-4,0,0);
		glVertex3f(-4,-0.2,0);
		glVertex3f(-2,-0.1,0);
	glEnd();	
	glColor3f(0.0f,0.5f,0.0f);
	rect_yoz(0,-0.1,0,2,-2,1);
	rect_yoz(0,-0.2,0,2,-4,-1);
	glPushMatrix();
	for(int i=0; i<360; i++){
		glColor3f(0.5f,0.0f,0.0f);
		glRotated( -1,0.0,0.0,1.0);
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-4,0,2);
		glVertex3f(-2,0,2);
		glVertex3f(-2,-0.2,2);
		glVertex3f(-4,-0.1,2);

		glNormal3f(0, 0, -1);
		glVertex3f(-2,0,0);
		glVertex3f(-4,0,0);
		glVertex3f(-4,-0.2,0);
		glVertex3f(-2,-0.1,0);
		glEnd();	
		glColor3f(0.0f,0.5f,0.0f);
		rect_yoz(0,-0.1,0,2,-2,1);
		rect_yoz(0,-0.2,0,2,-4,-1);
	}
	glPopMatrix();
	drawParallelogram(1.73, 3.6, -4, -2, -2, -9, 2);
}

//==========================10====================================
void drawNum10(){
	glColor3f(0.5f,0.0f,0.0f);
	glPushMatrix();
	glTranslatef(-4,-2,0);
    drawNum1();	
    glPopMatrix();

	glPushMatrix();
	glTranslatef(3,0,0);
	drawRinger(4, 2, 180, 0, 2);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(3,-4,0);
	drawRinger(4, 2, 0, -180, 2);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	glColor3f(0.5f,0.0f,0.0f);	
	rect_xoy(0, 2, -4, 0, 0,-1);
	rect_xoy(0, 2, -4, 0, 2,1);
	glColor3f(0.0f,0.5f,0.0f);	
	rect_yoz(-4, 0, 0, 2, 0,-1);
	rect_yoz(-4, 0, 0, 2, 2,1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5,0,0);
	glColor3f(0.5f,0.0f,0.0f);	
	rect_xoy(0, 2, -4, 0, 0,-1);
	rect_xoy(0, 2, -4, 0, 2,1);
	glColor3f(0.0f,0.5f,0.0f);	
	rect_yoz(-4, 0, 0, 2, 0,-1);
	rect_yoz(-4, 0, 0, 2, 2,1);
	glPopMatrix();
}

