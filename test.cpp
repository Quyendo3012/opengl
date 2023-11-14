#include <GL/gl.h>

#include <GL/glut.h>

void display(void){

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);

glBegin(GL_POLYGON);

glVertex3f (0.25, 0.25, 0.0);

glVertex3f (0.75, 0.25, 0.0);

glVertex3f (0.75, 0.75, 0.0);

glVertex3f (0.25, 0.75, 0.0);

glEnd();

glFlush ();

}

#

void init (void){

glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);}

int main(int argc, char** argv){

glutInit(&argc, argv);// Kh?i t?o Glut v� x? l� m?i d�ng l?nh d?i s?,
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng m� h�nh RGBA

glutInitWindowSize (250, 250);// k�ch c? c?a s?

glutInitWindowPosition (100, 100);// ch? ra v? tr� m�n h�nh g�c tr�n b�n tr�i

glutCreateWindow ("hello"); // T?o ti�u d? c?a s? �hello�

init ();

glutDisplayFunc(display);

glutMainLoop();

return 0;

}

#
