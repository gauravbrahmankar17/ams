#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
void drawText(char *message ,GLfloat x, GLfloat y )
{	
	glRasterPos2f(x,y);
	while (*message) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *message);
		message++;
	}
}
void renderFrontScreen() {
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
	drawText(ams , -0.19f, -0.7f); 
	drawText("PRESS F1 TO CLOSE THIS GL WINDOW" , -0.22, -0.9);
	glFlush();  
}
void renderSecondScreen() {
   	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);              
      		glColor3f(0.0f, 1.0f, 1.0f);
      		glVertex2f( 0.0f,   0.9f);    
      		glVertex2f(-0.08f,  0.7f);
      		glVertex2f( 0.08f,  0.7f);
   	glEnd();        
   	glBegin(GL_QUADS);              
      		glColor3f(0.0f, 1.0f, 1.0f);
      		glVertex2f(-0.08f, -0.3f);    
      		glVertex2f( 0.08f, -0.3f);
      		glVertex2f( 0.08f,  0.7f);
      		glVertex2f(-0.08f,  0.7f);
   	glEnd();
	glBegin(GL_TRIANGLES);              
      		glColor3f(0.0f, 1.0f, 1.0f);
      		glVertex2f( 0.0f,   -0.3f);    
      		glVertex2f(-0.1f,  -0.5f);
      		glVertex2f( 0.1f,  -0.5f);
   	glEnd();    
	glBegin(GL_QUADS);              
      		glColor3f(0.0f, 1.0f, 1.0f);
      		glVertex2f(-0.08f , -0.2f);    
      		glVertex2f(-0.08f ,  0.2f);
      		glVertex2f(-0.7f  , -0.5f);
      		glVertex2f(-0.6f  , -0.5f);
   	glEnd();    
	glBegin(GL_QUADS);              
      		glColor3f(0.0f, 1.0f, 1.0f);
      		glVertex2f( 0.08f , -0.2f);    
      		glVertex2f( 0.08f ,  0.2f);
      		glVertex2f( 0.7f  , -0.5f);
      		glVertex2f( 0.6f  , -0.5f);
   	glEnd(); 
	char *ams = "AIRLINE MANAGEMENT SYSTEM";
	glColor3f(1.0f, 0.0f, 0.0f);  
	//drawText(ams , -0.19f, -0.7f); 
	//drawText("PRESS F1 TO CLOSE THIS GL WINDOW" , -0.22, -0.9);
	glFlush();  
}
void pressF1ToExit(int key, int x, int y) {
	
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);             
   	glutInitWindowSize(1920, 1240);   
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("AIRLINE MANAGEMENT SYSTEM : DSA MINI PROJECT : BY GAURAV!!"); 
	glutDisplayFunc(renderFrontScreen); 
	glutSpecialFunc(pressF1ToExit);
	glutMainLoop();           
	return 0;
}
//-------------------------------------------------------------------------=
