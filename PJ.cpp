#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

int MousePositionX = 0;
int MousePositionY = 0;
int randomedShape = 0;

void keyboard(unsigned char key, int x, int y) {
	printf("%d\n", key);
	switch (key) {
	case 'a': printf("a pressed.!!!"); break;
	}
	glutPostRedisplay();
}

void obstacle1() {
	glBegin(GL_POLYGON);
	glColor3ub(50, 50, 50);
	glVertex2f(1, 1);
	glVertex2f(1.2, 1);
	glVertex2f(1.2, 0);
	glVertex2f(1, 0);
}

void player() {

	//หัว
	glBegin(GL_POLYGON);
	glColor3ub(255, 253, 208);
	glVertex2f(0, 0);
	glVertex2f(0.1, 0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0, 0.1);
	glEnd();

	//คอ
	glBegin(GL_POLYGON);
	glColor3ub(255, 253, 208);
	glVertex2f(0.03, 0);
	glVertex2f(0.03, -0.03);
	glVertex2f(0.07, -0.03);
	glVertex2f(0.07, 0);
	glEnd();

	//ตัว
	glBegin(GL_POLYGON);
	glColor3ub(200, 100, 60);
	glVertex2f(-0.025, -0.03);
	glVertex2f(-0.025, -0.25);
	glVertex2f(0.12, -0.25);
	glVertex2f(0.12, -0.03);
	glEnd();

	//ขา
	glBegin(GL_POLYGON);
	glColor3ub(60, 100, 60);
	glVertex2f(-0.015, -0.25);
	glVertex2f(-0.015, -0.45);
	glVertex2f(0.11, -0.45);
	glVertex2f(0.11, -0.25);
	glEnd();

	//ปืน
	glBegin(GL_POLYGON);
	glColor3ub(211, 211, 211);
	glVertex2f(0, -0.16);
	glVertex2f(0, -0.19);
	glVertex2f(0.25, -0.19);
	glVertex2f(0.25, -0.16);
	glEnd();

	//แขน
	glPushMatrix();
	glTranslatef(-0.08, -0.08, 0);
	glRotatef(50, 0, 0, 1);
	glBegin(GL_POLYGON);
	glColor3ub(255, 253, 208);
	glVertex2f(0.03, -0.1);
	glVertex2f(0.03, -0.2);
	glVertex2f(0.07, -0.2);
	glVertex2f(0.07, -0.1);
	glEnd();
	glPopMatrix();

}

void field() {

	glBegin(GL_POLYGON);
	glColor3ub(100, 100, 100);
	glVertex2f(-1, -0.6);
	glVertex2f(1, -0.6);
	glVertex2f(1, -1);
	glVertex2f(-1, -1);
	glEnd();

}

void draw() {
	field();

	glPushMatrix();
	glTranslatef(-0.8, -0.25, 0);
	player();
	glPopMatrix();
	
	glFlush();
}
void randomObstacle() {

	srand(time(NULL));
	randomedShape = rand()% 10;
	//printf("%d\n", randomedShape);

}

void mousepassive(int x, int y) {
	MousePositionX = x;
	MousePositionY = y;
	//printf("x = %d, y = %d\n", x, y);
}

void createObstacles() {
	randomObstacle();
	draw();
}

void moveObstacles() {
	glPushMatrix();
	obstacle1();
	glPopMatrix();
}

void startGame() {
	glClear(GL_COLOR_BUFFER_BIT);
	createObstacles();
	glutIdleFunc(moveObstacles);
}

void main(int argc, char **argv) {
	glutInitWindowSize(500, 500);
	glutCreateWindow("PJ");
	glutDisplayFunc(startGame);
	glutPassiveMotionFunc(mousepassive);
	glutMainLoop();
}
