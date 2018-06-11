
#include "stdafx.h"
#include <glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, finger = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScalef(2.0, 0.5, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	// uncomment this code for drawing elbow
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScalef(2.0, 0.5, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	// 손가락을 만들어보자
	// 좌표계를 (1,0,0)으로 이동시키고
	glTranslatef(1.0, 0.0, 0.0);
	// 이동한 좌표계를 기준으로 z축 회전
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
	// 현재 변환행렬을 저장해 둔 후
	glTranslatef(0.3, 0.0, 0.0); // x축으로 0.3만큼 이동
								 // 손가락1을 위한 변환
	glPushMatrix();
	glScalef(0.6, 0.1, 0.08); // 손가락을 만들기 위한 좌표계변환 후
	glutWireCube(1.0);         // 큐브를 만든다
	glPopMatrix();              // 손가락 하나를 위한 변환행렬을 원상복괴시키고

								// 손가락2를 위한 변환
	glTranslatef(0.0, 0.0, 0.2);
	glPushMatrix();
	glScalef(0.6, 0.1, 0.08);
	glutWireCube(1.0);
	glPopMatrix();

	// 손가락3을 위한 변환
	glTranslatef(0.0, 0.0, 0.2);
	glPushMatrix();
	glScalef(0.6, 0.1, 0.08);
	glutWireCube(1.0);
	glPopMatrix();

	//
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void processNormalKeys(unsigned char key, int x, int y) {
	//printf("key = %c\n", key);
	switch (key) {
	case 's': /* s key rotates at shoulder */
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e': /* e key rotates at elbow */
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'f': /* f key rotates at finger */
		finger = (finger + 5) % 360;
		glutPostRedisplay();
		break;
	case 'F':
		finger = (finger - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:    // ESC key for Exit
		exit(0);
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Arm control");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();
	return 0;
}
