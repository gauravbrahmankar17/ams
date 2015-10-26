#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
//front screen globalss
	int customer1admin2;
	int switchofffrontscreen=0;
//second screen globalss
	int switchoffsecondscreen=0;
	int login1signup2;	
//login screen globals
	int switchoffloginscreen = 0;
	int enterusername=1;
	int usrkeyboardindex;
	int passkeyboardindex;
	char username[64];
	char password[64];
	int username1password2;
//---------------------------------=
void frontScreenSpecialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_F1 :
			switchofffrontscreen=1;
			customer1admin2 =1;
			break;
		case GLUT_KEY_F2 :
			switchofffrontscreen=1;
			customer1admin2 = 2; break;
		case GLUT_KEY_F12 :
			exit(0); break;
	}
}
//---------------------------------=
void secondScreenSpecialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_F1 :
			switchoffsecondscreen = 1;
			login1signup2= 1;
			break;
		case GLUT_KEY_F2 :
			switchoffsecondscreen = 1;
			login1signup2= 2; 
			break;
		case GLUT_KEY_F12 :
			exit(0); break;
	}
}
//----------------------------------------------------------------------------
void loginScreenSpecialFunc(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_F5 :
			switchoffloginscreen = 1;
			break;
		case GLUT_KEY_F12 :
			exit(0); break;
	}
}
//-----------------------------------------------------------------------------
void displayText( int x, int y, char *st) {
	int len,i;
	len=strlen( st ); 
	glRasterPos2f( x, y); 	
	for( i=0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); 
	}
}
//---------------------------------------------------------------------------
void preparePassword(unsigned char key, int x, int y) {
	if (key=='-') {
		if(passkeyboardindex!=0)
			passkeyboardindex--;
		password[passkeyboardindex]='\0';
	}else {
		password[passkeyboardindex] = key;
		passkeyboardindex++;
	} 
}
//----------------------------------------------------------------------------
void prepareUsername(unsigned char key, int x, int y) {
	if (key=='-') {
		if(usrkeyboardindex!=0)
			usrkeyboardindex--;
		username[usrkeyboardindex]='\0';
	}else {
		username[usrkeyboardindex] = key;
		usrkeyboardindex++;
	} 
}
//-----------------------------------------------------------------------------
void drawText(char *message , void* font ,GLfloat x, GLfloat y )
{	
	glRasterPos2f(x,y);
	while (*message) {
		glutBitmapCharacter(font, *message);
		message++;
	}
}
//-----------------------------------------------------------------------------
void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
}
//-----------------------------------------------------------------------------
void usernamePassword(int key, int x, int y) {
	if (key==GLUT_KEY_F1) {
		username1password2=1;
	} 
	if(key==GLUT_KEY_F2) {
		username1password2=2;
	}
}
//-----------------------------------------------------------------------------
void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);// Use the Projection Matrix
	glLoadIdentity();// Reset Matrix
	glViewport(0, 0, w, h);// Set the viewport to be the entire window
	glMatrixMode(GL_MODELVIEW);// Get Back to the Modelview
}
//-----------------------------------------------------------------------------
void renderScene(void) {
	glutKeyboardFunc(processNormalKeys);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear Color and Second Depth Buffers
	glLoadIdentity();// Reset transformations
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	drawText("PRESS ESC TO EXIT.",GLUT_BITMAP_TIMES_ROMAN_24, -0.75,0.92);
	//Front Screen Rendering
		glBegin(GL_LINES);              
      			glColor3f(1.0f, 0.0f, 0.0f);
      			glVertex2f( -0.8f , -0.8f);    
      			glVertex2f( -0.8f ,  0.97f);
      			glVertex2f( 0.8f  , 0.97f);
			glVertex2f( -0.8f ,  0.97f);
      			glVertex2f( 0.8f  , -0.8f);
      			glVertex2f( 0.8f  , 0.97f);
			glVertex2f( -0.8f ,  -0.8f);
      			glVertex2f( 0.8f  , -0.8f);
   		glEnd(); 	
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
		if(switchofffrontscreen==0){
			char *ams = "AIRLINE MANAGEMENT SYSTEM";
			glColor3f(1.0f, 0.0f, 0.0f);  
			drawText(ams , GLUT_BITMAP_TIMES_ROMAN_24,-0.19f, -0.7f); 
			drawText("PRESS F12 TO CLOSE THIS GL WINDOW" ,GLUT_BITMAP_TIMES_ROMAN_24, -0.22, -0.9);
			drawText("F1: LOGIN AS A CUSTOMER." ,GLUT_BITMAP_HELVETICA_18, -0.7f , 0.2f);
			drawText("F2: LOGIN AS AN ADMINISTRATOR.", GLUT_BITMAP_HELVETICA_18, 0.3f, 0.2f );
			glutSpecialFunc(frontScreenSpecialKeys);
		}
//Second Screen Rendering
	if (customer1admin2==1) {
		if(switchoffsecondscreen == 0) {
			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			char *ams = "AIRLINE MANAGEMENT SYSTEM";
			glColor3f(1.0f, 0.0f, 0.0f);  
			drawText(ams , GLUT_BITMAP_TIMES_ROMAN_24,-0.19f, -0.7f);
			drawText("F1: LOGIN" ,GLUT_BITMAP_HELVETICA_18, -0.7f , 0.4f);
			drawText("F2: SIGNUP", GLUT_BITMAP_HELVETICA_18, 0.5f, 0.4f);
			glutSpecialFunc(secondScreenSpecialKeys);
		}
//LOGIN SCREEN rendering
	if(login1signup2==1) {
		if(switchoffloginscreen == 0) {
			glBegin(GL_LINES);              
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2f( 0.7f , 0.4f);    
				glVertex2f( 0.7f ,  0.8f);
				glVertex2f( 0.2f  , 0.8f);
				glVertex2f( 0.7f ,  0.8f);
				glVertex2f( 0.2f  , 0.4f);
				glVertex2f( 0.7f  , 0.4f);
				glVertex2f( 0.2f ,  0.8f);
				glVertex2f( 0.2f  , 0.4f);
			glEnd();
			drawText("LOGIN HERE:", GLUT_BITMAP_HELVETICA_18, 0.2f, 0.85f); 
			drawText("1.USERNAME : " , GLUT_BITMAP_HELVETICA_18, 0.22f, 0.7f);
			drawText("2.PASSWORD : " , GLUT_BITMAP_HELVETICA_18, 0.22f, 0.5f);
			glutSpecialFunc(usernamePassword);
			if(username1password2==1) {
				glutKeyboardFunc(processNormalKeys);
				glutKeyboardFunc(prepareUsername);
				drawText(username, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.7f);
			}
			if(username1password2==2) {
				//search username in the file
				glutKeyboardFunc(processNormalKeys);
				glutKeyboardFunc(preparePassword);
				drawText(password, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.5f);
			}
			drawText(username, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.7f);
			drawText(password, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.5f);
			//glutSpecialFunc(loginScreenSpecialFunc);
		} 	
	}else {  // signup
	}	
		
	}else { //admin
	}
	glutSwapBuffers();
}
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1920,1240);
	glutCreateWindow("AIRLINE MANAGEMENT SYSTEM : DSA MINI PROJECT");
	
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	// enter GLUT event processing cycle
	glutMainLoop();
	return 0;
}
//-----------------------------------------------------------------------------
