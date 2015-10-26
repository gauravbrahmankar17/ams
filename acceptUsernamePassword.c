int usrkeyboardindex;
int passkeyboardindex;
char username[64];
char password[64];
void acceptUsername() {
	glutKeyboardFunc(tapUsername);
	drawText(username, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.7f);
}
//--------------------------------------------------=
void tapUsername(unsigned char key, int x, int y) {
	if ('\'== key) {
			write(&fd, username , sizeof(username));
			username1password2=2;
			return;
	}
	if (key=='-') {
		if(usrkeyboardindex!=0) 
			usrkeyboardindex--;
		username[usrkeyboardindex]='\0';
	}else {
		username[usrkeyboardindex] = key;
		usrkeyboardindex++;
	} 
}
//---------------------------------------------------=
void acceptPassword() {
	glutKeyboardFunc(tapPassword);
	drawText(password, GLUT_BITMAP_HELVETICA_18, 0.4f, 0.5f);
}
//--------------------------------------------------=
void tapPassword(unsigned char key, int x, int y) {
	if ('\' == key) {
		write(&fd, password , sizeof(password));
		username1password2 = 5 ;
		return;
	}
	if (key=='-') {
		if(passkeyboardindex!=0) {
			passkeyboardindex--;
			password[passkeyboardindex]='\0';
		}
	}else {
		password[passkeyboardindex] = key;
		passkeyboardindex++;
	} 
}
//---------------------------------------------------=
