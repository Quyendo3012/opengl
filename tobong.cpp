#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//static int day= 0; //cau5

//bai2
float angle = 0.0;
////	//bai 2 mau vang am 1 
//	GLfloat light_diffuse1[] = { 0.8, 0.8, 0.0, 1.0 };
//	GLfloat light_ambient1[] = { 0.2, 0.2, 0.0, 1.0 };
//////	//am mau magenta tao tu red + blue
//	GLfloat light_diffuse2[] = { 0.8, 0.0, 0.8, 1.0 };
//	GLfloat light_ambient2[] = { 0.2, 0.0, 0.2, 1.0 };

//bai 3 mau xanh la cay 010  
	GLfloat light_diffuse_green[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat light_ambient_green[] = { 0.0, 0.2, 0.0, 1.0 };
	//cam tao tu red 100 + vang110 
	GLfloat light_diffuse_orange[] = { 1.5, 0.5, 0.0, 1.0 };
	GLfloat light_ambient_orange[] = { 0.6, 0.2, 0.0, 1.0 };


//bai5
//slider mau do 100
//	GLfloat light_diffuse_slider[] = {3.0, 0.0, 0.0, 1.0};
//	GLfloat light_ambient_slider[] = {0.2, 0.0, 0.0, 1.0};
//ball xanh la cay 010
//	GLfloat light_diffuse_ball[] = {0.0, 1.0, 0.0, 1.0};
//	GLfloat light_ambient_ball[] = {0.0, 0.2, 0.0, 1.0};
void init(void)
{
	//c5
//	glClearColor(1.0,1.0,1.0,1.0);
//	glShadeModel (GL_FLAT);
//
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat light_position[] = { 3.0, 5.0, 5.0, 0.0 };

//	//c2c1
	//bai 1 cau mau xanh da troi 
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//	GLfloat light_diffuse[] = { 0.3, 0.3, 1.0, 1.0 };
//	GLfloat light_ambient[] = { 0.2, 0.2, 1.0, 1.0 };
//	glClearColor (0.0, 0.0, 0.0, 0.0);
//	glShadeModel (GL_SMOOTH);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glEnable(GL_LIGHTING); //kich hoat chieu sang toan cuc 
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
	
//bai2 +3
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glEnable(GL_LIGHTING); //kich hoat chieu sang toan cuc 
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	//cau1
//	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidSphere (1.0, 20, 16); //cau 1
//	glFlush();

//bai2
//	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//left am 1
//	glTranslatef(-0.8,0.0,0.0);
//	glPushMatrix();
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
//		glRotatef(angle, 1 , 0 ,0);
//		glutSolidTeapot (0.4);
//	glPopMatrix();
////right am 2
//	glPushMatrix();
//		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
//		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
//		glTranslatef(1.5 ,0.0,0.0);
//		glutSolidTeapot (0.4);
//	glPopMatrix();
//	glutSwapBuffers();	
//	glLoadIdentity();
//	glFlush ();

//bai3
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//left cau xanh
	glPushMatrix();

		glTranslatef(0.5,0.0,0.0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_green);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_green);
//		glRotatef(angle, 1 , 0 ,0);
		glutSolidSphere (0.2, 16,20);
	glPopMatrix();
	
//right cau cam
	glPushMatrix();
		glTranslatef(0.4,0,0);
		glRotatef(angle, 0 , 1 ,0);
		glTranslatef(-0.4,0,0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_orange);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_orange);
//		glTranslatef(0.5,0.0,0.0);
		glutSolidSphere (0.2, 16, 20);
	glPopMatrix();
	glutSwapBuffers();	
	glLoadIdentity();
	glFlush ();


	
	//cau5
	//	glClear (GL_COLOR_BUFFER_BIT); //c5

//	glPushMatrix();
//		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, light_diffuse_slider);
//	    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, light_ambient_slider);
//		glColor3f(1.0,0.0,0.0);
//		glRotatef(45,0,0,1);
//		glScalef(15,0.6,5);
//		glutSolidCube(1.0);
//	glPopMatrix();
//	
//	glPushMatrix();
//	    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, light_diffuse_ball);
//	    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, light_ambient_ball);
//		glTranslatef(5,7,0);
//		glColor3f(0.0,1.0,0.0);
//		glTranslatef( (GLfloat) day/40 , (GLfloat) day/40 , 0);
//		glRotatef (((GLfloat) day)*(-1), 0, 0, 1);
//		glutSolidSphere(1, 20, 15);
//	glPopMatrix();
//	glutSwapBuffers();	
	//glLoadIdentity();
//	glFlush ();
}
void spin(){
		angle = (angle + 0.2);
		glutPostRedisplay();
	}
void keyboard(unsigned char key, int x, int y) 
{
//	cau2
	if (key == 'a')
	{
		glutIdleFunc(spin);
	}	

//cau5
//	switch (key) {
//	case '.':
//		day = (day + 1)/1.1;
//		glutPostRedisplay();
//		break;
//	
//	case ',':
//		day = (day - 1)*1.1;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
}
void reshape (int w, int h)
{
//	cau1 + 2
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
	1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
	glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
	1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0,
	10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//cau 3 
//	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
//	glMatrixMode (GL_PROJECTION);
//	glLoadIdentity ();
//	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt (0, 0, 20, 0.0, 0.0, 0.0, 0, 1, 0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//c2c1
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	
	//c5
//	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
//	glutInitWindowSize (800, 800);
//	glutInitWindowPosition (0, 0);
	
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
