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

int angle=0,angle2=0;
float toado=0,Xp=0,Yp=0,Sscale=1;

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity (); /* clear the matrix */
	/* viewing transformation */
	gluLookAt (0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//cau 1 a
//	glRotatef(angle,1,0,0);
//	glutWireTeapot(1);
//	cau 1 b
//	glTranslatef(-2.5,0,0);
//	glTranslatef(toado,0,0);
//	glutWireTeapot(0.5);

//	cau 2 a
//	glRotatef(angle,0,0,1);
//	register int i;
//	GLfloat step=3.14/5;//2*3.14/10
//	GLfloat r,anglesao;
//	glBegin(GL_LINE_LOOP);
//	for(i=0;i<10;i++){
//		r=i%2==0?0.5:1;
//		anglesao=step*i;
//		glVertex3f(r*cos(anglesao),r*sin(anglesao),0);
//	}
//	glEnd();
//cau 2 b
//	GLfloat step=3.14/5;
//	register int i;
//	GLfloat r,anglesao;
//	r=1;
//	Xp=r*cos(9*step);
//	Yp=r*sin(9*step);
//	glTranslatef(Xp,Yp,0);
//	glRotatef(angle,0,0,1);
//	glTranslatef(-Xp,-Yp,0);		
//	glBegin(GL_POLYGON);
//	for(i=0;i<10;i++){
//		r=i%2==0?0.5:1.0;
//		anglesao=i*step;
//		glVertex3f(r*cos(anglesao),r*sin(anglesao),0);
//	}
//	glEnd();

//cau 2 c
//	GLfloat step=3.14/5;
//	register int i;
//	GLfloat r,anglesao;
//	r=1;
//	Xp=r*cos(9*step);
//	Yp=r*sin(9*step);
//	glTranslatef(Xp,Yp,0);
//	glScalef(Sscale,Sscale,1);
//	glTranslatef(-Xp,-Yp,0);		
//	glBegin(GL_POLYGON);
//	for(i=0;i<10;i++){
//		r=i%2==0?0.5:1.0;
//		anglesao=i*step;
//		glVertex3f(r*cos(anglesao),r*sin(anglesao),0);
//	}
//	glEnd();
	//cau 2d
//	glRotatef(angle,0,0,1);
//	register int i;
//	GLfloat step=3.14/5;//2*3.14/10
//	GLfloat r,anglesao;
//	glBegin(GL_LINE_LOOP);
//	for(i=0;i<10;i++){
//		r=i%2==0?0.5:1;
//		anglesao=step*i;
//		glVertex3f(r*cos(anglesao),r*sin(anglesao),0);
//	}
//	glEnd();
//hinh tron
//	step=3.14/180;
//	glBegin(GL_LINE_LOOP);
//	for(i=0;i<360;i++){
//		r=1;
//		anglesao=i*step;
//		glVertex3f(r*cos(anglesao),r*sin(anglesao),0);
//	}
//	glEnd();

	//cau 3
//	glPushMatrix();
//		glRotatef(70,1,0,1);
//		glRotatef(angle,0,0,1);
//		glutWireSphere(1,9,9);
//	glPopMatrix();
//	glPushMatrix();
//		glRotatef(10,0,0,1);
//		glTranslatef(0,-2,0);
//		glScalef(1.0,2.0,1);
//		glutWireCube(1.0);
//	glPopMatrix();
	//cau 4
	glPushMatrix();
		glRotatef(70,1,0,1);
		glTranslatef(4,0,0);
		glRotatef(angle,0,0,1);
		glutWireSphere(1,9,9);
	glPopMatrix();
	
	glPushMatrix();
		glRotatef(70,1,0,1);
		glTranslatef(2,0,0);
//		glRotatef(angle,0,1,0);
		glTranslatef(-2,0,0);
		glRotatef(angle2,1,0,0);
		glutWireSphere(1,9,9);
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush ();
}

void mouse(int button,int state,int x,int y){
	
	if(button==GLUT_LEFT_BUTTON){
		//cau 1 a
		angle=(angle+5)%360;
//		angle2=(angle2+2)%360;
//		if(toado<4.4){
//			toado+=0.1;			
//		}

		glutPostRedisplay();
	}
}

void scale(){
	if(Sscale>0.5){
		Sscale-=0.0001;
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key,int x,int y){
	if(key=='a'){
		angle=(angle+5)%360;
		glutPostRedisplay();
	}
	if(key=='b'){
		glutIdleFunc(scale);
	}
}


void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
//	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
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
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
