void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);// Use the Projection Matrix
	glLoadIdentity();// Reset Matrix
	glViewport(0, 0, w, h);// Set the viewport to be the entire window
	glMatrixMode(GL_MODELVIEW);// Get Back to the Modelview
}
