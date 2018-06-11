
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

	// �հ����� ������
	// ��ǥ�踦 (1,0,0)���� �̵���Ű��
	glTranslatef(1.0, 0.0, 0.0);
	// �̵��� ��ǥ�踦 �������� z�� ȸ��
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
	// ���� ��ȯ����� ������ �� ��
	glTranslatef(0.3, 0.0, 0.0); // x������ 0.3��ŭ �̵�
								 // �հ���1�� ���� ��ȯ
	glPushMatrix();
	glScalef(0.6, 0.1, 0.08); // �հ����� ����� ���� ��ǥ�躯ȯ ��
	glutWireCube(1.0);         // ť�긦 �����
	glPopMatrix();              // �հ��� �ϳ��� ���� ��ȯ����� ���󺹱���Ű��

								// �հ���2�� ���� ��ȯ
	glTranslatef(0.0, 0.0, 0.2);
	glPushMatrix();
	glScalef(0.6, 0.1, 0.08);
	glutWireCube(1.0);
	glPopMatrix();

	// �հ���3�� ���� ��ȯ
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
