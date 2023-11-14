#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>4


void midpoint(int x1,int y1,int x2,int y2, int doday = 10){
	int x,y,dx,dy,d;
	x=x1;y=y1;dx=x2-x1;dy=y2-y1;
	d=2*dy-dx;
	int j = 0;
	while(x<=x2)
	{
			if ((j /10) %2 ==0) {
				for (int i = 0 - (doday/2); i<doday/2; i++) {
					glVertex2i(x,y+i);
				}
			}
		
		
		if(d>=0){
			y++;
			d=d+2*dy-2*dx;
		}else{
			d=d+2*dy;
		}
		x++;
		j++;
	}
}

void display(void){

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POINTS);	//ve da giac gom cac dinh trong begin va end
midpoint(0,0,70,50);
	glEnd();

//glBegin(GL_POLYGON);
//
//	glVertex3f (0.25, 0.25, 0.0);
//	
//	glVertex3f (0.75, 0.25, 0.0);
//	
//	glVertex3f (0.75, 0.75, 0.0);
//	
//	glVertex3f (0.25, 0.75, 0.0);

//Ngu giac 
// Thuc hanh 2 _ Bai 1
    
// Ngu giac
    
//        glBegin(GL_LINE_LOOP);
//        glVertex3f(0.25, 0.25, 0.0);
//        glVertex3f(0.55, 0.25, 0.0);
//        glVertex3f(0.65, 0.55, 0.0);
//        glVertex3f(0.40, 0.75, 0.0);
//        glVertex3f(0.15, 0.55, 0.0);
    
// Luc giac
    
//        glBegin(GL_LINE_LOOP);
//        glVertex3f(0.20, 0.25, 0.0);
//        glVertex3f(0.60, 0.25, 0.0);
//        glVertex3f(0.775, 0.55, 0.0);
//        glVertex3f(0.60, 0.85, 0.0);
//        glVertex3f(0.20, 0.85, 0.0);
//        glVertex3f(0.0, 0.55, 0.0);

//Ngoi sao 
//	GLfloat step = 3.14 / 5.0;
//	register int i;
//	GLfloat angle, r;
//	glBegin(GL_LINE_LOOP);
//	for (i = 0; i < 10; ++i) {
//	r = (i % 2 == 0 ? 5 : 15);
//	angle = i * step;
//	glVertex3f(r * cos(angle), r * sin(angle),0.0);
//	}

//hinh tron 

//	GLfloat step = 3.14 /60.0;
//	register int i;
//	GLfloat angle, r;
//	glBegin(GL_LINE_LOOP);
//	for (i = 0; i < 360; ++i) {
//		r = (i % 2 == 0 ? 5 : 15);
//		angle = i * step;
//		glVertex3f(r * cos(angle), r * sin(angle),0.0);
//	}
//	
//	for (i = 0; i < 360; ++i) {
//		r = 15;
//		angle = i * step;
//		glVertex3f(r * cos(angle), r * sin(angle),0.0);
//	}
	

//bai 4
//GLfloat step = 3.14 / 60.0;
//	register int i;
//	GLfloat angle, r;
//	glBegin(GL_LINE_LOOP);
//	for (i = 0; i < 360; ++i) {
//		r = (i % 2 == 0 ? 5 : 15);
//		angle = i * step;
//		glVertex3f(r * cos(angle), r * sin(angle),0.0);
//	}
//	glEnd();
//	
//	glBegin(GL_LINE);
//	glVertex3f(5*cos(180), 5 * sin(180) -20.0, 0.0);
//	glEnd();
//
//		glBegin(GL_LINE_LOOP);
//
//		for (i = 0; i < 360; ++i) {
//		r = (i % 2 == 0 ? 5 : 15);
//		angle = i * step;
//		glVertex3f(r * cos(angle), r * sin(angle) -20.0,0.0);
//	}
//	
//




glEnd();

glFlush (); 

}

#

void init (void){

glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

glOrtho(-150.0, 150.0, -150.0, 150.0, -1.0, 1.0);}

int main(int argc, char** argv){

glutInit(&argc, argv);// Kh?i t?o Glut và x? lí m?i dòng l?nh d?i s?,
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng mô hình RGBA

glutInitWindowSize (250, 250);// kích c? c?a s?

glutInitWindowPosition (100, 100);// ch? ra v? trí màn hình góc trên bên trái

glutCreateWindow ("hello"); // T?o tiêu d? c?a s? “hello”

init ();

glutDisplayFunc(display);

glutMainLoop();

return 0;

}
