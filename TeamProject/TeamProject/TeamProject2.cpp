#include "stdafx.h"
#include<glut.h>
//#include<GLAUX.H>
#include<stdio.h>
#include <stdlib.h> 
#include<math.h>
#include <time.h> 

void rotate(void);
void ProcessMenu(int value);

static GLfloat xP = 80.00f;
static GLfloat yP = 0.0f;
GLUquadricObj* obj, *sun, *mer, *ven, *earth,*moon, *mars, *jup, *sat, *ura, *nep;
//AUX_RGBImageRec * pTextureImage[11];

static GLfloat nRange = 50.f;

static GLfloat MerR = 50.0f;//행성들(수,금,지,화,목,토,천,해,명) 의 범위내에서 중심을 향한 각도.
static GLfloat VenR = 280.0f;
static GLfloat EarR = 80.0f;
static GLfloat MarR = 240.0f;
static GLfloat JupR = 300.0f;
static GLfloat SatR = 140.0f;
static GLfloat UraR = 70.0f;
static GLfloat NepR = 180.0f;
static GLfloat PluR = 20.0f;

static GLfloat planetRoy = 0.0f;

static GLfloat planetRoz = 0.0f;

static GLfloat planetSpiny = 0.0f;
static GLfloat planetSpinz = 0.0f;
static GLfloat planety = 0.0f;
static int index = 1;

GLfloat ambientLight[] = { 0.3f , 0.3f, 0.3f, 1.0f };

GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };

GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static int iPlanet = 3;


////////////////////////////////////////////////////////////////행성들 구성
void SunRotation(void)
{

	glPushMatrix();

	glColor3ub(230, 50, 0);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}



void MercuryRotation(void) {

	glPushMatrix();

	glColor3ub(50.0, 50.0, 50.0);

	glutWireSphere(30.0, 25, 25),

		glPopMatrix();
}


void VenusRotation(void) {

	glPushMatrix();

	glColor3b(255, 110, 0);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();

}


void EarthRotation(void) {


	glPushMatrix();
	glColor3ub(60, 90, 250);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}



void MarsRotation(void) {

	glPushMatrix();
	glColor3ub(230, 50, 30);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}

void JupiterRotation(void) {

	glPushMatrix();

	glColor3ub(90, 110, 100);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}


void SaturnRotation(void) {

	glPushMatrix();
	glColor3ub(130, 80, 30);
	glutWireSphere(30.0, 25, 25);
	glPushMatrix();

	//obj = gluNewQuadric();
	//glBindTexture(GL_TEXTURE_2D, MyTextureOBject[7]);
	//gluDisk(saturn_ring, 0.0f, 0.17, 26, 13);

	glPopMatrix();
}

void UranusRotation(void) {

	glPushMatrix();

	glColor3ub(80, 150, 240);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}

void NeptuneRotation(void) {

	glPushMatrix();

	glColor3ub(60, 110, 200);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();

}


void PlutoRotation(void) {

	glPushMatrix();

	glColor3ub(130, 220, 250);

	glutWireSphere(30.0, 25, 25);

	glPopMatrix();
}

void ProcessMenu(int value) {

	glutPostRedisplay();
}


void makeMercury(void) {

	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0, 0, -7);
	glutSolidSphere(0.6f, 25, 25);
	glPopMatrix();
}


void makeVenus(void) {

	glPushMatrix();
	glColor3ub(180, 60, 20);
	glTranslatef(0, 0, -10);
	glutSolidSphere(1.8f, 25, 25);
	glPopMatrix();
}


void makeEarth(void) {

	glPushMatrix();
	glColor3ub(60, 90, 250);
	glTranslatef(0, 0, -14.2);
	glutSolidSphere(1.9f, 25, 25);
	glPopMatrix();
}



void makeMars(void) {

	glPushMatrix();
	glColor3ub(115, 25, 15);
	glTranslatef(0, 0, -17.8);
	glutSolidSphere(1.0f, 25, 25);
	glPopMatrix();
}



void makeJupiter(void) {

	glPushMatrix();
	glColor3ub(100, 100, 100);
	glTranslatef(0, 0, -23.0);
	glutSolidSphere(3.8f, 25, 25);
	glPopMatrix();
}


void makeSaturn(void) {

	glPushMatrix();
	glColor3ub(130, 80, 30);
	glTranslatef(0, 0, -31.0);
	glutWireTorus(3.0f, 3.0f, 2, 100);
	glutSolidSphere(3.4f, 25, 25);
	glPopMatrix();
}



void makeUranus(void) {

	glPushMatrix();
	glColor3ub(80, 200, 200);
	glTranslatef(0, 0, -38.0);
	glutSolidSphere(2.5f, 25, 25);
	glPopMatrix();
}



void makeNeptune(void) {

	glPushMatrix();
	glColor3ub(80, 150, 240);
	glTranslatef(0, 0, -44.0);
	glutSolidSphere(2.4f, 25, 25);
	glPopMatrix();
}

void makePluto(void) {

	glPushMatrix();
	glColor3ub(220, 220, 220);
	glTranslatef(0, 0, -48.0);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();
}



void planetRotate(void)
{
	planetRoy += planetSpiny;
	glutPostRedisplay();
}


void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (1 <= iPlanet && iPlanet <= 3)
	{
		glPushMatrix();
		glRotatef(xP, 1.0f, 0.0f, 0.0f);

		glRotatef(yP, 0.0f, 1.0f, 0.0f);

		glColor3ub(255, 5, 5);
		glutWireTorus(3.0f, 3.0f, 2, 100);
		glutSolidSphere(6.0f, 25, 25);

		int i = 0;


		int xpoint = 50;
		int zpoint = 50;
		
		glPushMatrix();
		glRotatef(MerR, 0.0f, 1.0f, 0.0f);
		makeMercury();
		glPopMatrix();

		glPushMatrix();
		glRotatef(VenR, 0.0f, 1.0f, 0.0f);
		makeVenus();
		glPopMatrix();


		glPushMatrix();
		glRotatef(EarR, 0.0f, 1.0f, 0.0f);
		makeEarth();
		glPopMatrix();

		glPushMatrix();
		glRotatef(MarR, 0.0f, 1.0f, 0.0f);
		makeMars();
		glPopMatrix();


		glPushMatrix();
		glRotatef(JupR, 0.0f, 1.0f, 0.0f);
		makeJupiter();
		glPopMatrix();


		glPushMatrix();
		glRotatef(SatR, 0.0f, 1.0f, 0.0f);
		makeSaturn();
		glPopMatrix();


		glPushMatrix();
		glRotatef(UraR, 0.0f, 1.0f, 0.0f);
		makeUranus();
		glPopMatrix();

		glPushMatrix();
		glRotatef(NepR, 0.0f, 1.0f, 0.0f);
		makeNeptune();
		glPopMatrix();


		glPushMatrix();
		glRotatef(PluR, 0.0f, 1.0f, 0.0f);
		makePluto();
		glPopMatrix();

		glutIdleFunc(rotate);
		glPopMatrix();
	}
	glutSwapBuffers();
}
/*
int LoadTextures() {
	sun = gluNewQuadric();
	mer= gluNewQuadric();
	ven= gluNewQuadric();
	earth= gluNewQuadric();
	mars= gluNewQuadric();
	jup= gluNewQuadric();
	sat= gluNewQuadric();
	ura= gluNewQuadric();
	nep= gluNewQuadric();
	
	int Status = false;

	gluQuadricTexture(sun, GL_TRUE);
	gluQuadricTexture(mer, GL_TRUE);
	gluQuadricTexture(ven, GL_TRUE);
	gluQuadricTexture(earth, GL_TRUE);
	gluQuadricTexture(mars, GL_TRUE);
	gluQuadricTexture(jup, GL_TRUE);
	gluQuadricTexture(sat, GL_TRUE);
	gluQuadricTexture(ura, GL_TRUE);
	gluQuadricTexture(nep, GL_TRUE);

	memset(pTextureImage, 0, sizeof(void*) * 1);
}
*/

void rotate(void)
{
	MerR += (4.09f / index);
	VenR += (1.602f / index);
	EarR += (1.0f / index);
	MarR += (0.72f / index);
	JupR += (float)(0.5 / index);
	SatR += (0.38f / index);
	UraR += (0.2f / index);
	NepR += (0.1f / index);
	PluR += (0.05f / index);
	if (MerR > 360) MerR -= 360;
	else if (VenR > 360) VenR -= 360;
	else if (EarR > 360) EarR -= 360;
	else if (MarR > 360) MarR -= 360;
	else if (JupR > 360) JupR -= 360;
	else if (SatR > 360) SatR = -360;
	else if (UraR > 360) UraR = -360;
	else if (NepR > 360) NepR = -360;
	else if (PluR > 360) PluR = -360;
	glutPostRedisplay();
}

void setupRC() {/////////////////
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
}


void keyboard_handler(unsigned char key, int x, int y)
{
	if (key == 'w')//X축 중심 5도씩 감소,증가 
		xP -= 5.0f;
	if (key == 'W')
		xP += 5.0f;
	if (key == 's')//Y축을 중심 각도가 5도씩 감소, 증가 
		yP -= 5.0f;
	if (key == 'S')
		yP += 5.0f;
	if (key == 'l') {//행성들의 속도 감소, 증가
		index++;
	}
	if (key == 'L') {
		index--;
	}
	if (index > 3) {//예외 처리문.
		index = 0;
	}
	if (index <1) {//예외 처리문.
		index = 3;
	}
	if (key>356.0f)//예외 처리문.
		xP = 0.0f;
	if (key<-1.0f)//예외 처리문.
		xP = 355.0f;
	if (key>356.0f)//예외 처리문.
		yP = 0.0f;
	if (key<-1.0f)//예외 처리문.
		yP = 355.0f;
	glutPostRedisplay();

}

void ChangeSize(int w, int h)
{
	GLfloat lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

int main(int argc, char*argv[]) {
	int SolidMenu;
	int WireMenu;
	int MainMenu;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("TEAM PROJECT");
	glutKeyboardFunc(keyboard_handler);
	WireMenu = glutCreateMenu(ProcessMenu);
	SolidMenu = glutCreateMenu(ProcessMenu);
	MainMenu = glutCreateMenu(ProcessMenu);
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);


	setupRC();

	glutMainLoop();
	return 0;
}


////L 누르면 돌아가는 속도가 하락.  , W,w 누르면 