#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#define ONE 1
#define TWO 2
//front screen globals
	GLfloat personloggingin ;


void drawText(char *message , void* font ,GLfloat x, GLfloat y )
{	
	glRasterPos2f(x,y);
	while (*message) {
		glutBitmapCharacter(font, *message);
		message++;
	}
}
void frontScreenKeyInput(unsigned char key, int x, int y) {
	switch(key) {
		case 103:
			personloggingin=1;
		case 102:
			personloggingin=2;
	}
}
void frontScreenSpecialInput(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_F12 :
			exit(0);	 
		break;
		case GLUT_KEY_F1:
			personloggingin=1;
		case GLUT_KEY_F2:
			personloggingin=2;
	}
}
void renderScreens() {
	//RENDERING OF THE FScreen
   	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);              
      		glColor3f(1.0f, 1.0f, 1.0f);
      		glVertex2f( 0.0f,   0.9f);    
      		glVertex2f(-0.08f,  0.7f);
      		glVertex2f( 0.08f,  0.7f);
   	glEnd();        
   	glBegin(GL_QUADS);              
      		glColor3f(1.0f, 1.0f, 1.0f);
      		glVertex2f(-0.08f, -0.3f);    
      		glVertex2f( 0.08f, -0.3f);
      		glVertex2f( 0.08f,  0.7f);
      		glVertex2f(-0.08f,  0.7f);
   	glEnd();
	glBegin(GL_TRIANGLES);              
      		glColor3f(1.0f, 1.0f, 1.0f);
      		glVertex2f( 0.0f,   -0.3f);    
      		glVertex2f(-0.1f,  -0.5f);
      		glVertex2f( 0.1f,  -0.5f);
   	glEnd();    
	glBegin(GL_QUADS);              
      		glColor3f(1.0f, 1.0f, 1.0f);
      		glVertex2f(-0.08f , -0.2f);    
      		glVertex2f(-0.08f ,  0.2f);
      		glVertex2f(-0.7f  , -0.5f);
      		glVertex2f(-0.6f  , -0.5f);
   	glEnd();    
	glBegin(GL_QUADS);              
      		glColor3f(1.0f, 1.0f, 1.0f);
      		glVertex2f( 0.08f , -0.2f);    
      		glVertex2f( 0.08f ,  0.2f);
      		glVertex2f( 0.7f  , -0.5f);
      		glVertex2f( 0.6f  , -0.5f);
   	glEnd(); 
	char *ams = "AIRLINE MANAGEMENT SYSTEM";
	glColor3f(1.0f, 0.0f, 0.0f);  
	drawText(ams , GLUT_BITMAP_TIMES_ROMAN_24,-0.19f, -0.7f); 
	drawText("PRESS F12 TO CLOSE THIS GL WINDOW" ,GLUT_BITMAP_TIMES_ROMAN_24, -0.22, -0.9);
	drawText("F1: LOGIN AS A CUSTOMER." ,GLUT_BITMAP_HELVETICA_18, -0.9f , 0.2f);
	drawText("F2: LOGIN AS AN ADMINISTRATOR.", GLUT_BITMAP_HELVETICA_18, 0.5f, 0.2f );
	glutSpecialFunc(frontScreenSpecialInput);
	glutKeyboardFunc(frontScreenKeyInput);
	//RENDERING OF THE SECscreen
	if(personloggingin == 1) {
		 glPushMatrix();
    			glColor3d(1.0, 0.0, 0.0);
   			glutWireSphere(0.5, 50, 50);
    		 glPopMatrix();
	}
	glFlush();  
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); 
   	glutInitWindowSize(1920, 1240);   
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("AIRLINE MANAGEMENT SYSTEM : DSA MINI PROJECT : BY GAURAV!!"); 
	glutDisplayFunc(renderScreens); 
	glutMainLoop();           
	return 0;
}
//-------------------------------------------------------------------------=
