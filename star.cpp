#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
static GLfloat spin = 0.0;
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRotatef(spin, 1.0, 0.0, 0.0);
//gluLookAt (1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
glutWireTeapot(10.0);
//glColor3f(1.0, 1.0, 1.0);
//glRectf(-25.0, -25.0, 25.0, 25.0);
glPopMatrix();
glutSwapBuffers();
}
void spinDisplay(void)
{
spin = spin + 0.2;
if (spin > 360.0)
spin = spin - 360.0;
glutPostRedisplay();
}
void reshape(int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-30.0, 30.0, -30.0, 30.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
//void keyboard (unsigned char key, int x, int y)
//{
//switch (key) {
//case ‘s’: /* s key rotates */
//spin = spin + 2;
//if (spin > 360.0)
//spin = spin - 360.0;
//glutPostRedisplay();
//break;}

//void mouse(int button, int state, int x, int y)
//{
//switch (button) {
//case GLUT_LEFT_BUTTON:
//if (state == GLUT_DOWN)
//glutIdleFunc(spinDisplay);
//break;
//case GLUT_MIDDLE_BUTTON:
//if (state == GLUT_DOWN)
//glutIdleFunc(NULL);
//break;
//default:
//break;
//}}
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
	{
	if (state == GLUT_DOWN)
	spin = spin + 2;
	if (spin > 360.0)
	spin = spin - 360.0;
	
	glutPostRedisplay();
	break;
	}
}}
/* Request double buffer display mode.
Register mouse input callback functions */
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (250, 250);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutMainLoop();
return 0;}
