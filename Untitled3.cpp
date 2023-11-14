#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

int angle=0;

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity (); 
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//cau 3
//		glRotatef(angle,0,1,0); //quay khi ?n 
	glPushMatrix();
		glRotatef(angle,0,1,0); //quay khi ?n 
		glRotatef(70,1,0,1);

		glutWireSphere(1,9,9);
	glPopMatrix();

	glPushMatrix();
		glRotatef(10,0,0,1); // tr? nghiêng
//		glRotatef(angle,0,1,0); //quay khi ?n 
		glTranslatef(0,-2,0); // cho d?ch xu?ng du?i kh?i c?u 
		glScalef(1.0,3.0,1); // kéo dãn tr?
	glutWireCube(1.0);
	glPopMatrix();

	glFlush ();
}

void mouse(int button,int state,int x,int y){
	
	if(button==GLUT_LEFT_BUTTON){
		angle=(angle+5)%360;
		glutPostRedisplay();
	}
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-2.0, 2.0, -2.0, 2.0, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutMouseFunc(mouse);
//	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

