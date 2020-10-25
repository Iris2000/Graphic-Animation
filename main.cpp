#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
#include <iostream>
#define PI 3.14

using namespace std;

void drawCircle(double rad);
void sun();
void moon();
void move_cloud();
void move_mountain();
void move_hill();
void cloud_model_one();
void cloud_model_two();
void cloud_model_three();
void cloud_one(string cloudColor);
void cloud_two(string cloudColor);
void cloud_three(string cloudColor);
void cloud_four(string cloudColor);
void mountain_model_large(string snowColor);
void mountain_model_small(string snowColor);
void mountain_large_one(string snowColor);
void mountain_large_two(string snowColor);
void mountain_large_three(string snowColor);
void mountain_small_one(string snowColor);
void mountain_small_two(string snowColor);
void mountain_small_three(string snowColor);
void mountain_small_four(string snowColor);
void mountain_small_five(string snowColor);
void hill_model_one();
void hill_model_two();
void hill_one(string hillColor);
void hill_two(string hillColor);
void hill_three(string hillColor);
void hill_four(string hillColor);
void hill_five(string hillColor);
void dayToNight();
void afternoon();
void nightToDay();

float ax=0, bx=0, cx=0, dx=0;
float sx=0, sy=0, mx=0, my=0;
float m1x=0, m2x=0, m3x=0, m4x=0, m5x=0, m6x=0, m7x=0, m8x=0;
float h1x=0, h2x=0, h3x=0, h4x=0, h5x=0;
int scWidth = 800, scHeight = 1000;
string cloudColor;

void dayToNight() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //draw sky
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(0, 250);
    glVertex2d(1000, 250);
    glColor3f(0.0f, 0.7f, 0.9f);
    glVertex2d(1000, 1000);
    glVertex2d(0, 1000);
    glEnd();

    sun();

    //evening sky
    if (sy <= -200) {
        glBegin(GL_QUADS);
        glColor3ub(253,198,125);
        glVertex2d(0, 250);
        glVertex2d(1000, 250);
        glColor3ub(44,56,126);
        glVertex2d(1000, 1000);
        glVertex2d(0, 1000);
        glEnd();
    }

    sun();

    move_mountain();
    move_hill();
    mountain_small_three("day");
    hill_three("day");
    mountain_large_one("day");
    mountain_small_one("day");
    hill_two("day");
    mountain_large_two("day");
    mountain_small_five("day");
    hill_five("day");
    hill_one("day");
    mountain_small_two("day");
    hill_four("day");
    mountain_small_four("day");
    mountain_large_three("day");

    //drawLand
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex2d(0, 0);
    glVertex2d(1000, 0);
    glColor3f(0.8f, 0.9f, 0.0f);
    glVertex2d(1000, 250);
    glVertex2d(0, 250);
    glEnd();

    move_cloud();
    cloud_one("day");
    cloud_two("day");
    cloud_three("day");
    cloud_four("day");

    glFlush();

    if (sy <= -420) {
        mx = 0;
        my = 0;
        glutDisplayFunc(nightToDay);
    }
}

void nightToDay() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //draw sky
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2d(0, 250);
    glVertex2d(1000, 250);
    glColor3f(0.0f,0.0f,0.3f);
    glVertex2d(1000, 1000);
    glVertex2d(0, 1000);
    glEnd();

    moon();

    //evening sky
    if (my <= -200) {
        glBegin(GL_QUADS);
        glColor3ub(253,198,125);
        glVertex2d(0, 250);
        glVertex2d(1000, 250);
        glColor3ub(44,56,126);
        glVertex2d(1000, 1000);
        glVertex2d(0, 1000);
        glEnd();
    }

    moon();

    move_mountain();
    move_hill();
    mountain_small_three("night");
    hill_three("night");
    mountain_large_one("night");
    mountain_small_one("night");
    hill_two("night");
    mountain_large_two("night");
    mountain_small_five("night");
    hill_five("night");
    hill_one("night");
    mountain_small_two("night");
    hill_four("night");
    mountain_small_four("night");
    mountain_large_three("night");

    //drawLand
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2d(0, 0);
    glVertex2d(1000, 0);
    glColor3f(0.4f, 0.5f, 0.0f);
    glVertex2d(1000, 250);
    glVertex2d(0, 250);
    glEnd();

    move_cloud();
    cloud_one("night");
    cloud_two("night");
    cloud_three("night");
    cloud_four("night");

    glFlush();

    if (my <= -420) {
        sx = 0;
        sy = 0;
        glutDisplayFunc(dayToNight);
    }
}

void drawCircle(double rad)
{
    int points = 24;
    double delTheta = (2.0 * PI) / (GLdouble)points;
    double theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for(int i = 0; i <= 24; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

///***MODEL***///
void hill_model_one(){
	glBegin(GL_POLYGON);
	glVertex2i(125, 50);
	glVertex2i(170, 95);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(280, 110);
	glVertex2i(290, 108);
	glVertex2i(300, 105);
	glVertex2i(310, 100);
	glVertex2i(320, 95);
	glVertex2i(365, 50);
	glEnd();
}

void hill_model_two() {
    // Left_Part
    glPushMatrix();
    glTranslatef(430,95,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(430,90,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,85,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(385,75,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(370,60,0);
    drawCircle(40);
    glPopMatrix();

    //Right_Part
    glPushMatrix();
    glTranslatef(445,80,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    drawCircle(40);
    glPopMatrix();
}

void mountain_model_large(string snowColor) {
    //body
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.4f, 0.3f);
	glVertex2d(70, 250);
	glVertex2d(220, 460);
	glVertex2d(350, 250);
	glEnd();

	if (snowColor == "day") {
        glColor3f(1.0f, 1.0f, 1.0f);
	}
	else {
        glColor3f(0.6f, 0.6f, 0.6f);
	}
	//snow
	glBegin(GL_POLYGON);
	glVertex2d(220, 460);
	glVertex2d(260, 400);
	glVertex2d(250, 380);
	glVertex2d(220, 400);
	glVertex2d(190, 380);
	glVertex2d(170, 390);
	glEnd();
}

void mountain_model_small(string snowColor) {
    //body
	glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.2f, 0.1f);
	glVertex2d(280, 250);
	glVertex2d(365, 360);
	glVertex2d(450, 250);
	glEnd();

    if (snowColor == "day") {
        glColor3f(1.0f, 1.0f, 1.0f);
	}
	else {
        glColor3f(0.6f, 0.6f, 0.6f);
	}

    //snow
	glBegin(GL_POLYGON);
    glVertex2d(340, 330);
	glVertex2d(365, 360);
	glVertex2d(390, 330);
	glVertex2d(385, 310);
	glVertex2d(365, 340);
	glVertex2d(350, 310);
	glEnd();
}

void cloud_model_one(){
    //Left_Part
    glPushMatrix();
    glTranslatef(325,230,0);
    drawCircle(20);
    glPopMatrix();

    //Top
    glPushMatrix();
    glTranslatef(350,250,0);
    drawCircle(25);
    glPopMatrix();

    //Right_Part
    glPushMatrix();
    glTranslatef(374,237,0);
    drawCircle(20);
    glPopMatrix();

    //Bottom_Part
    glPushMatrix();
    glTranslatef(350,227,0);
    drawCircle(20);
    glPopMatrix();
}

void cloud_model_two() {
    //Left_Part
    glPushMatrix();
    glTranslatef(290,200,0);
    drawCircle(25);
    glPopMatrix();

    //Top_Left
    glPushMatrix();
    glTranslatef(310,220,0);
    drawCircle(25);
    glPopMatrix();

    //Top
    glPushMatrix();
    glTranslatef(330,240,0);
    drawCircle(24);
    glPopMatrix();

    //Top_Right
    glPushMatrix();
    glTranslatef(350,220,0);
    drawCircle(25);
    glPopMatrix();

    //Right_Part
    glPushMatrix();
    glTranslatef(370,200,0);
    drawCircle(25);
    glPopMatrix();

    //Bottom_Right
    glPushMatrix();
    glTranslatef(360,180,0);
    drawCircle(20);
    glPopMatrix();

    //Bottom_Left
    glPushMatrix();
    glTranslatef(300,180,0);
    drawCircle(20);
    glPopMatrix();

    //Bottom
    glPushMatrix();
    glTranslatef(330,180,0);
    drawCircle(25);
    glPopMatrix();
}

void cloud_model_three() {
    //Top_Left
    glPushMatrix();
    glTranslatef(310,220,0);
    drawCircle(25);
    glPopMatrix();

    //Top
    glPushMatrix();
    glTranslatef(340, 240, 0);
    drawCircle(25);
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(370,215,0);
    drawCircle(26);
    glPopMatrix();

    //middle_Fill
    glPushMatrix();
    glTranslatef(350,215,0);
    drawCircle(26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,210,0);
    drawCircle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,209,0);
    drawCircle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,209,0);
    drawCircle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,209,0);
    drawCircle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,209,0);
    drawCircle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290,209,0);
    drawCircle(20);
    glPopMatrix();
}

///***OBJECT***///
void sun() {
    glColor3f(9.0f, 0.8f, 0.0f);
    glPushMatrix();
    glTranslatef(sx+1000,sy+1000,0);
    drawCircle(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+690,sy+445,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(300, 600);
    glVertex2d(310, 620);
    glVertex2d(320, 600);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+655,sy+445,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(300, 600);
    glVertex2d(307, 580);
    glVertex2d(320, 593);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+635,sy+400,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(300, 600);
    glVertex2d(320, 610);
    glVertex2d(320, 590);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+730,sy+445,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(298, 593);
    glVertex2d(318, 600);
    glVertex2d(308, 580);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+745,sy+400,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(320, 600);
    glVertex2d(300, 610);
    glVertex2d(300, 590);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+655,sy+360,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(298, 595);
    glVertex2d(305, 615);
    glVertex2d(318, 602);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+690,sy+355,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(300, 600);
    glVertex2d(310, 580);
    glVertex2d(320, 600);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+730,sy+360,0);
    glBegin(GL_TRIANGLES);
    glColor3f(9.0f, 0.8f, 0.0f);
    glVertex2d(298, 602);
    glVertex2d(308, 615);
    glVertex2d(318, 595);
    glEnd();
    glPopMatrix();

    //eyes
    glPushMatrix();
    glTranslatef(sx+283,sy+305,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+315,sy+305,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    //blush
    glPushMatrix();
    glTranslatef(sx+275,sy+295,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.5f, 0.5f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sx+323,sy+295,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.5f, 0.5f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    //mouth
    glPushMatrix();
    glTranslatef(sx+290,sy+200,0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 790);
    glVertex2d(710, 785);
    glVertex2d(710, 785);
    glVertex2d(720, 790);
    glEnd();
    glPopMatrix();
}

void moon() {
    glColor3ub(255,244,197);
    glPushMatrix();
    glTranslatef(mx+1000,my+1000,0);
    drawCircle(40);
    glPopMatrix();

    //eyes
    glPushMatrix();
    glTranslatef(mx+275,my+205,0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 790);
    glVertex2d(705, 785);
    glVertex2d(705, 785);
    glVertex2d(710, 790);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(mx+315,my+205,0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 790);
    glVertex2d(705, 785);
    glVertex2d(705, 785);
    glVertex2d(710, 790);
    glEnd();
    glPopMatrix();

    //blush
    glPushMatrix();
    glTranslatef(mx+270,my+285,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.5f, 0.5f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(mx+330,my+285,0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.5f, 0.5f);
    glVertex2d(700, 700);
    glEnd();
    glPopMatrix();

    //mouth
    glPushMatrix();
    glTranslatef(mx+295,my+190,0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 790);
    glVertex2d(705, 792);
    glVertex2d(705, 792);
    glVertex2d(710, 790);
    glEnd();
    glPopMatrix();
}

void mountain_large_one(string snowColor) {
    glPushMatrix();
    glTranslatef(m1x+0, 0, 0);
    mountain_model_large(snowColor);
    glPopMatrix();
}

void mountain_large_two(string snowColor) {
    glPushMatrix();
    glTranslatef(m5x+590, 0, 0);
    mountain_model_large(snowColor);
    glPopMatrix();
}

void mountain_large_three(string snowColor) {
    glPushMatrix();
    glTranslatef(m7x+970, -50, 0);
    mountain_model_large(snowColor);
    glPopMatrix();
}

void mountain_small_one(string snowColor) {
    glPushMatrix();
    glTranslatef(m4x+320, 55, 0);
    mountain_model_small(snowColor);
    glPopMatrix();
}

void mountain_small_two(string snowColor) {
    glPushMatrix();
    glTranslatef(m2x+-50, 0, 0);
    mountain_model_small(snowColor);
    glPopMatrix();
}

void mountain_small_three(string snowColor) {
    glPushMatrix();
    glTranslatef(m3x+170, -10, 0);
    mountain_model_small(snowColor);
    glPopMatrix();
}

void mountain_small_four(string snowColor) {
    glPushMatrix();
    glTranslatef(m6x+670, -20, 0);
    mountain_model_small(snowColor);
    glPopMatrix();
}

void mountain_small_five(string snowColor) {
    glPushMatrix();
    glTranslatef(m8x+-280, -40, 0);
    mountain_model_small(snowColor);
    glPopMatrix();
}

void hill_one(string hillColor) {
    if (hillColor == "day") {
        glColor3f(0.2f, 0.8f, 0.2f);
    }
    else {
        glColor3f(0.2f, 0.6f, 0.2f);
    }
    glPushMatrix();
    glTranslatef(h1x+0, 200, 0);
    hill_model_one();
    glPopMatrix();
}

void hill_two(string hillColor) {
    if (hillColor == "day") {
        glColor3f(0.2f, 0.8f, 0.2f);
    }
    else {
        glColor3f(0.2f, 0.6f, 0.2f);
    }
    glPushMatrix();
    glTranslatef(h3x+410, 200, 0);
    hill_model_one();
    glPopMatrix();
}

void hill_three(string hillColor) {
    if (hillColor == "day") {
        glColor3f(0.2f, 0.8f, 0.2f);
    }
    else {
        glColor3f(0.2f, 0.6f, 0.2f);
    }
    glPushMatrix();
    glTranslatef(h2x+0, 190, 0);
    hill_model_two();
    glPopMatrix();
}

void hill_four(string hillColor) {
    if (hillColor == "day") {
        glColor3f(0.2f, 0.8f, 0.2f);
    }
    else {
        glColor3f(0.2f, 0.6f, 0.2f);
    }
    glPushMatrix();
    glTranslatef(h4x+480, 190, 0);
    hill_model_two();
    glPopMatrix();
}

void hill_five(string hillColor) {
    if (hillColor == "day") {
        glColor3f(0.2f, 0.8f, 0.2f);
    }
    else {
        glColor3f(0.2f, 0.6f, 0.2f);
    }
    glPushMatrix();
    glTranslatef(h5x+-460, 170, 0);
    hill_model_two();
    glPopMatrix();
}

void cloud_one(string cloudColor){
    if (cloudColor == "day"){
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else {
        glColor3f(0.6f, 0.6f, 0.6f);
    }
    glPushMatrix();
    glTranslatef(ax+-100,700,0);
    cloud_model_two();
    glPopMatrix();
}

void cloud_two(string cloudColor) {
    if (cloudColor == "day"){
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else {
        glColor3f(0.6f, 0.6f, 0.6f);
    }
    glPushMatrix();
    glTranslatef(bx+200,500,0);
    cloud_model_three();
    glPopMatrix();
}

void cloud_three(string cloudColor) {
    if (cloudColor == "day"){
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else {
        glColor3f(0.6f, 0.6f, 0.6f);
    }
    glPushMatrix();
    glTranslatef(cx+550,600,0);
    cloud_model_two();
    glPopMatrix();
}

void cloud_four(string cloudColor) {
    if (cloudColor == "day"){
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else {
        glColor3f(0.6f, 0.6f, 0.6f);
    }
    glPushMatrix();
    glTranslatef(dx+-200,400,0);
    cloud_model_one();
    glPopMatrix();
}

///***MOVEMENT***///
void move_cloud() {
    ax = ax + 0.04;
    bx = bx + 0.06;
    cx = cx + 0.05;
    dx = dx + 0.06;

    if (ax > 900) {
        ax = ax - 1200;
    }
    if (bx > 600) {
        bx = bx - 1200;
    }
    if (cx > 200) {
        cx = cx - 1200;
    }
    if (dx > 900) {
        dx = dx - 1200;
    }
    glutPostRedisplay();
}

void move_mountain() {
    m1x = m1x - 0.3;
    m2x = m2x - 0.3;
    m3x = m3x - 0.3;
    m4x = m4x - 0.3;
    m5x = m5x - 0.3;
    m6x = m6x - 0.3;
    m7x = m7x - 0.3;
    m8x = m8x - 0.3;

    if (m1x < -400) {
        m1x = m1x + 1400;
    }
    if (m2x < -400) {
        m2x = m2x + 1400;
    }
    if (m3x < -600) {
        m3x = m3x + 1400;
    }
    if (m4x < -800) {
        m4x = m4x + 1400;
    }
    if (m5x < -1000) {
        m5x = m5x + 1400;
    }
    if (m6x < -1200) {
        m6x = m6x + 1400;
    }
    if (m7x < -1400) {
        m7x = m7x + 1400;
    }
    if (m8x < -100) {
        m8x = m8x + 1400;
    }
    glutPostRedisplay();
}

void move_hill() {
    h1x = h1x - 0.3;
    h2x = h2x - 0.3;
    h3x = h3x - 0.3;
    h4x = h4x - 0.3;
    h5x = h5x - 0.3;

    if (h1x < -400) {
        h1x = h1x + 1400;
    }
    if (h2x < -600) {
        h2x = h2x + 1400;
    }
    if (h3x < -800) {
        h3x = h3x + 1400;
    }
    if (h4x < -1000) {
        h4x = h4x + 1400;
    }
    if (h5x < -100) {
        h5x = h5x + 1400;
    }
    glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y) {
    //night
    if(key == 'n') {
        if (sy > -420) {
            sx = sx - 5;
            sy = sy - 2;
        }
    }
    //day
    if(key == 'd') {
        if (my > -420) {
            mx = mx - 5;
            my = my - 2;
        }
    }
    //rain
    if(key == 'r') {

    }
    //snow
    if(key == 's') {

    }
    // stop/resume
    if (key == '0') {

    }
}

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,999.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(scWidth, scHeight);
    glutCreateWindow("StickMan");
    glutDisplayFunc(dayToNight);
    glutKeyboardFunc(myKeyboard);
    init();
    glutMainLoop();
    return 0;
}
