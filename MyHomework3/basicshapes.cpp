#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

//These 4 drawEavedPlane functions are used to draw planes in different colors. 
void drawEavedPlane1(){//This is the single plane with eaves.
	glBegin(GL_QUADS);		// Draw The plane Using quads   
    glColor3f(0.5f,0.0f,0.0f);
	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);		
	
	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(8, 8, 10);
	glVertex3f(10, 10, 10);

	glNormal3f(0, 0, 1);
	glVertex3f(10, 10, 10);	
    glVertex3f(8, 8, 10);
    glVertex3f(8, -8, 10);
	glVertex3f(10, -10, 10);	
	
	glNormal3f(0, 0, 1);
	glVertex3f(10, -10, 10);
    glVertex3f(8, -8, 10);
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);

	// Draw The eaves Using quads
	glColor3f(0.0f,0.3f,0.3f);	
    glNormal3f(1, 0, 0);
	glVertex3f(-8,8,10);	
    glVertex3f(-8,8,8);		
    glVertex3f(-8,-8,8);
	glVertex3f(-8,-8,10);

	glNormal3f(-1, 0, 0);
	glVertex3f(8,8,10);	
    glVertex3f(8,8,8);		
    glVertex3f(8,-8,8);
	glVertex3f(8,-8,10);
	
	glColor3f(0.3f,0.3f,0.0f);	
	glNormal3f(0, -1, 0);
	glVertex3f(-8, 8, 10);	
    glVertex3f(-8, 8, 8);  
    glVertex3f(8, 8, 8); 
	glVertex3f(8, 8, 10); 

	glNormal3f(0, 1, 0);
	glVertex3f(-8, -8, 10);	
    glVertex3f(-8, -8, 8);  
    glVertex3f(8, -8, 8); 
	glVertex3f(8, -8, 10); 	
	glEnd();

	glEnable(GL_TEXTURE_2D); 
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(8, 8, 8);	
    glTexCoord2f(0, 1);glVertex3f(-8, 8, 8);	
    glTexCoord2f(0, 0);glVertex3f(-8, -8, 8);
	glTexCoord2f(1, 0);glVertex3f(8, -8, 8);
	glEnd();
	glDisable(GL_TEXTURE_2D); 
}

void drawEavedPlane2(){
	glBegin(GL_QUADS);		// Draw The plane Using quads   
    glColor3f(0.0f,0.0f,0.5f);
	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);		

	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(8, 8, 10);
	glVertex3f(10, 10, 10);

	glNormal3f(0, 0, 1);
	glVertex3f(10, 10, 10);	
    glVertex3f(8, 8, 10);
    glVertex3f(8, -8, 10);
	glVertex3f(10, -10, 10);	

	glNormal3f(0, 0, 1);
	glVertex3f(10, -10, 10);
    glVertex3f(8, -8, 10);
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);

	glColor3f(0.0f,0.3f,0.3f);
	glNormal3f(1, 0, 0);
    glVertex3f(-8,8,10);	
    glVertex3f(-8,8,8);		
    glVertex3f(-8,-8,8);
	glVertex3f(-8,-8,10);

	glNormal3f(-1, 0, 0);
	glVertex3f(8,8,10);	
    glVertex3f(8,8,8);		
    glVertex3f(8,-8,8);
	glVertex3f(8,-8,10);
	
	glColor3f(0.3f,0.3f,0.0f);
	glNormal3f(0, -1, 0);
	glVertex3f(-8, 8, 10);	
    glVertex3f(-8, 8, 8);  
    glVertex3f(8, 8, 8); 
	glVertex3f(8, 8, 10); 

	glNormal3f(0, 1, 0);
	glVertex3f(-8, -8, 10);	
    glVertex3f(-8, -8, 8);  
    glVertex3f(8, -8, 8); 
	glVertex3f(8, -8, 10); 	
	glEnd();
	
	glEnable(GL_TEXTURE_2D); 
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(8, 8, 8);	
    glTexCoord2f(0, 1);glVertex3f(-8, 8, 8);	
    glTexCoord2f(0, 0);glVertex3f(-8, -8, 8);
	glTexCoord2f(1, 0);glVertex3f(8, -8, 8);
	glEnd();
	glDisable(GL_TEXTURE_2D); 
}

void drawEavedPlane3(){
	glBegin(GL_QUADS);		// Draw The plane Using quads
    glColor3f(0.0f,0.5f,0.0f);	
	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);		

	glNormal3f(0, 0, 1);
    glVertex3f(-10, 10, 10);
    glVertex3f(-8, 8, 10);	
    glVertex3f(8, 8, 10);
	glVertex3f(10, 10, 10);

	glNormal3f(0, 0, 1);
	glVertex3f(10, 10, 10);	
    glVertex3f(8, 8, 10);
    glVertex3f(8, -8, 10);
	glVertex3f(10, -10, 10);	

	glNormal3f(0, 0, 1);
	glVertex3f(10, -10, 10);
    glVertex3f(8, -8, 10);
    glVertex3f(-8, -8, 10);
	glVertex3f(-10, -10, 10);

	glColor3f(0.0f,0.3f,0.3f);
	glNormal3f(1, 0, 0);
    glVertex3f(-8,8,10);	
    glVertex3f(-8,8,8);		
    glVertex3f(-8,-8,8);
	glVertex3f(-8,-8,10);

	glNormal3f(-1, 0, 0);
	glVertex3f(8,8,10);	
    glVertex3f(8,8,8);		
    glVertex3f(8,-8,8);
	glVertex3f(8,-8,10);
	
	glNormal3f(0, -1, 0);
	glColor3f(0.3f,0.3f,0.0f);	
	glVertex3f(-8, 8, 10);	
    glVertex3f(-8, 8, 8);  
    glVertex3f(8, 8, 8); 
	glVertex3f(8, 8, 10); 

	glNormal3f(0, 1, 0);
	glVertex3f(-8, -8, 10);	
    glVertex3f(-8, -8, 8);  
    glVertex3f(8, -8, 8); 
	glVertex3f(8, -8, 10); 	
	glEnd();
	
	glEnable(GL_TEXTURE_2D); 
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(8, 8, 8);	
    glTexCoord2f(0, 1);glVertex3f(-8, 8, 8);	
    glTexCoord2f(0, 0);glVertex3f(-8, -8, 8);
	glTexCoord2f(1, 0);glVertex3f(8, -8, 8);
	glEnd();
	glDisable(GL_TEXTURE_2D); 
}

//draw the rectangle parallel to the xoy plane, a,b,c,d are the minimum and maximun 
//of x-axis and y-axis, and z is the location of z-axis. 
void rect_xoy(float a,float b,float c,float d, float z, int normal){
    if(normal == 1){
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(a,c,z);
		glVertex3f(b,c,z);
		glVertex3f(b,d,z);
		glVertex3f(a,d,z);
		glEnd();
	}
	if(normal == -1){
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(a,c,z);
		glVertex3f(b,c,z);
		glVertex3f(b,d,z);
		glVertex3f(a,d,z);
		glEnd();
	}
}

//draw the rectangle parallel to the xoz plane, a,b,c,d are the minimum and maximun 
//of x-axis and z-axis, and y is the location of y-axis. 
void rect_xoz(float a,float b,float c,float d, float y, int normal){
    if(normal == 1){
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(a,y,d);
		glVertex3f(b,y,d);
		glVertex3f(b,y,c);
		glVertex3f(a,y,c);
	glEnd();
	}
	if(normal == -1){
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(a,y,d);
		glVertex3f(b,y,d);
		glVertex3f(b,y,c);
		glVertex3f(a,y,c);
	glEnd();
	}
}

//draw the rectangle parallel to the yoz plane, a,b,c,d are the minimum and maximun 
//of y-axis and z-axis, and z is the location of y-axis. 
void rect_yoz(float a,float b,float c,float d, float x, int normal){
    if(normal == 1){ 
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(x,a,c);
		glVertex3f(x,b,c);
		glVertex3f(x,b,d);
		glVertex3f(x,a,d);
		glEnd();
	}
	if(normal == -1){ 
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(x,a,c);
		glVertex3f(x,b,c);
		glVertex3f(x,b,d);
		glVertex3f(x,a,d);
		glEnd();
	}
}


//draw a circular with radium r and height h
void drawCircular( float r, float h ){
    glColor3f(0.5f,0.0f,0.0f);	//Dark Green
	glPushMatrix();
	for(int i=0; i<360; i++){
		glColor3f(0.5f,0.0f,0.0f);
		glBegin(GL_TRIANGLES);
		glNormal3f(0, 0, -1);
		glVertex3f(0, 0, 0);
		glVertex3f(r, 0, 0);
		glVertex3f(r, r/50, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0, 0, h);
		glVertex3f(r, 0, h);
		glVertex3f(r, r/50, h);
		glEnd();
		glColor3f(0.0f,0.0f,0.5f);
		rect_yoz(0 ,r/50, 0, h, r, 1);
		glRotated( 1,0.0,0.0,1.0);
	}
	glPopMatrix();
}


//draw a cube which is parallel to the coordinate planes
void drawCube( float x1, float x2, float y1, float y2, float z1, float z2){
	glColor3f(0.5f, 0, 0);
	rect_xoy(x1,x2,y1,y2,z1, -1);
	rect_xoy(x1,x2,y1,y2,z2, 1);
	glColor3f(0.0, 0, 0.5f);
	rect_xoz(x1,x2,z1,z2,y1, -1);
	rect_xoz(x1,x2,z1,z2,y2, 1);
	glColor3f(0, 0.5f, 0);
	rect_yoz(y1,y2,z1,z2,x1, -1);
	rect_yoz(y1,y2,z1,z2,x2, 1);
}

//draw a cube which is parallel to the coordinate planes
void drawBlackCube( float x1, float x2, float y1, float y2, float z1, float z2){
	glColor3f(0.0, 0.0, 0.0);
	rect_xoy(x1,x2,y1,y2,z1, -1);
	rect_xoy(x1,x2,y1,y2,z2, 1);
	rect_xoz(x1,x2,z1,z2,y1, -1);
	rect_xoz(x1,x2,z1,z2,y2, 1);
	rect_yoz(y1,y2,z1,z2,x1, -1);
	rect_yoz(y1,y2,z1,z2,x2, 1);
}

//rmax and rmin are radium. amax and amin are angle degrees. h is the width of the ring. 
void drawRinger( float rmax, float rmin, float amax, float amin, float h ){
	glPushMatrix();
	glRotated( amin, 0.0, 0.0, 1.0 );  
	for( int i = 0 ; i < ( amax - amin ); i ++ ){
		glColor3f(0.5f, 0, 0);
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(rmax,0,0);
		glVertex3f(rmin,0,0);
		glVertex3f(rmin,(rmin/10.0),0);
		glVertex3f(rmax,(rmax/10.0),0);

		glNormal3f(0, 0, 1);
		glVertex3f(rmax,0,h);
		glVertex3f(rmin,0,h);
		glVertex3f(rmin,(rmin/10.0),h);
		glVertex3f(rmax,(rmax/10.0),h);
		glEnd();
		glColor3f(0, 0.5f, 0);
		rect_yoz(0,(rmax/10.0),0,h,rmax, 1);
		rect_yoz(0,(rmin/10.0),0,h,rmin, -1);
		glRotated( 1,0.0,0.0,1.0);
	}
	glPopMatrix();
}
//set color to black
void drawBlackRinger( float rmax, float rmin, float amax, float amin, float h ){
	glPushMatrix();
	glRotated( amin, 0.0, 0.0, 1.0 );  
	for( int i = 0 ; i < ( amax - amin ); i ++ ){
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(rmax,0,0);
		glVertex3f(rmin,0,0);
		glVertex3f(rmin,(rmin/10.0),0);
		glVertex3f(rmax,(rmax/10.0),0);

		glNormal3f(0, 0, 1);
		glVertex3f(rmax,0,h);
		glVertex3f(rmin,0,h);
		glVertex3f(rmin,(rmin/10.0),h);
		glVertex3f(rmax,(rmax/10.0),h);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		rect_yoz(0,(rmax/10.0),0,h,rmax, 1);
		rect_yoz(0,(rmin/10.0),0,h,rmin, -1);
		glRotated( 1,0.0,0.0,1.0);
	}
	glPopMatrix();
}

void drawParallelogram(float x1, float x2, float x3, float x4, float y1, float y2, float h){
	glColor3f(0,0,0.5f);
	rect_xoz(x1, x2, 0, h, y1, 1);
	rect_xoz(x3, x4, 0, h, y2, -1);
	glBegin(GL_QUADS);
		glColor3f(0.0f,0.25f,0.0f);
		glNormal3f(y2-y1, x1-x3, 0);
		glVertex3f(x1, y1, 0);
		glVertex3f(x1, y1, h);
		glVertex3f(x3, y2, h);
		glVertex3f(x3, y2, 0);

		glNormal3f(y1-y2, x4-x2, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x2, y1, h);
		glVertex3f(x4, y2, h);
		glVertex3f(x4, y2, 0);
		
		glColor3f(0.5f,0.0f,0.0f);
		glNormal3f(0, 0, -1);
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x4, y2, 0);
		glVertex3f(x3, y2, 0);
		
		glNormal3f(0, 0, 1);
		glVertex3f(x1, y1, h);
		glVertex3f(x2, y1, h);
		glVertex3f(x4, y2, h);
		glVertex3f(x3, y2, h);
	glEnd();
}
//set color to black
void drawBlackParallelogram(float x1, float x2, float x3, float x4, float y1, float y2, float h){
	glColor3f(0,0,0);
	rect_xoz(x1, x2, 0, h, y1, 1);
	rect_xoz(x3, x4, 0, h, y2, -1);
	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glNormal3f(y2-y1, x1-x3, 0);
		glVertex3f(x1, y1, 0);
		glVertex3f(x1, y1, h);
		glVertex3f(x3, y2, h);
		glVertex3f(x3, y2, 0);

		glNormal3f(y1-y2, x4-x2, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x2, y1, h);
		glVertex3f(x4, y2, h);
		glVertex3f(x4, y2, 0);
		
		glColor3f(0,0,0);
		glNormal3f(0, 0, -1);
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x4, y2, 0);
		glVertex3f(x3, y2, 0);
		
		glNormal3f(0, 0, 1);
		glVertex3f(x1, y1, h);
		glVertex3f(x2, y1, h);
		glVertex3f(x4, y2, h);
		glVertex3f(x3, y2, h);
	glEnd();
}

//rmax and rmin are radium. amax and amin are angle degrees
void drawSingleRing( float rmax, float rmin, float amax, float amin){
	glPushMatrix();
	glRotated( amin, 0.0, 0.0, 1.0 );  
	for( int i = 0 ; i < ( amax - amin ); i ++ ){
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(rmax,0,0);
		glVertex3f(rmin,0,0);
		glVertex3f(rmin,(rmin/10.0),0);
		glVertex3f(rmax,(rmax/10.0),0);
		glEnd();
		glRotated( 1,0.0,0.0,1.0);
	}
	glPopMatrix();
}

void drawParallel(float x1, float x2, float x3, float x4, float y1, float y2){
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x4, y2, 0);
		glVertex3f(x3, y2, 0);
	glEnd();
}
