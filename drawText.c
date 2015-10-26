void drawText(char *message , void* font ,GLfloat x, GLfloat y )
{	
	glRasterPos2f(x,y);
	while (*message) {
		glutBitmapCharacter(font, *message);
		message++;
	}
}
