#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
void init(void) // khoi tao
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT); // mo hinh chieu sang
}
int angle = 0;
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity (); // ma tran don vi
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glScalef (1.0, 2.0, 1.0); /* modeling transformation 
	glTranslatef(7, 0, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-7, 0, 0);
	//glutWireTeapot (1.0);
	GLfloat step = 3.14/5.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_LINE_LOOP);
	for(i = 0; i<10; i++)
	{
		r = (i % 2 == 0 ? 7:3); //v0(7,0)
		angle = i* step;
		glVertex3f(r * cos(angle), r*sin(angle), 0.0);
	}
	glEnd();
	glutSwapBuffers(); // doi cho khung hinh
	glFlush ();
}

void spin()
{
	angle += 1;
	glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
	if(btn == GLUT_LEFT)
	{
//		glutIdleFunc(spin);
		angle = (angle + 2)%360;
		glutPostRedisplay(); // ve lai anh
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
		angle = (angle + 2)%360;
		glutPostRedisplay(); // ve lai anh
	}
}

void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
//glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); //phep chieu phoi canh
glOrtho(40.0, -40.0, 40.0, -40.0, -1.0, 1.0); // phép chieu song song
glMatrixMode (GL_MODELVIEW);
}
int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow(argv[0]);
init ();
glutMouseFunc(mouse); //nhan chuot
glutKeyboardFunc(keyboard); // nhan ban phim
glutDisplayFunc(display);
glutReshapeFunc(reshape); //do co dan cua so
glutMainLoop();
return 0;
}
