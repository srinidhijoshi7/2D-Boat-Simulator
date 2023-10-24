#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>
#define PI 3.1416
using namespace std;

GLint i=0;
GLint mode=0,sun_mode=0,boat_mode=0,smoke_mode=0;
GLfloat sun_spin=0, sun_x=0, sun_y=0, moon_spin=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0,moveB=0.0,rx=60.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
float _moveA = 0.0f;
float _moveB = 0.0f;
float _moveC = 0.0f;
float _angle1 = 0.0f;
float speed = 0.02f;
void create_menu(void);
void menu(int);
GLfloat spin = 0.0;
int flag = 0;

void text(char str[]){
 int i;
 for(i=0;i<strlen(str);i++)
 {
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
 }
}

void display(){
     glClearColor(0.3,0.1,0.3,0);
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.35,0.8,-1.0);
     text("JSS ACADEMY OF TECHNICAL EDUCATION");
     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.18,0.7,-1.0);
     text("Dept of Computer Science");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.16,0.4,-1.0);
     text("Mini Project On : ");
     glColor3f(1.0,1.0,0.0);
     glRasterPos3f(-0.27,0.25,-1.0);
     text("TITLE : BOAT SIMULATION");


     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.14,-0.05,-1.0);
     text("Submitted by : ");

     glColor3f(1.0,1.1,0.0);
     glRasterPos3f(-0.67,-0.2,-1.0);
     text("SRINIDHI N JOSHI");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.67,-0.3,-1.0);
     text("USN: 1JS20CS163");

     glColor3f(1.0,1.1,0.0);
     glRasterPos3f(0.35,-0.2,-1.0);
     text("YASHASVI GM");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.35,-0.3,-1.0);
     text("USN: 1JS20CS187");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.25,-0.6,-1.0);
     text("UNDER THE GUIDANCE OF : ");
     glColor3f(1.0,1.1,0.0);
     glRasterPos3f(-0.25,-0.7,-1.0);
     text("Dr Sharana Basavana Gowda");
     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.25,-0.8,-1.0);
     text("Assoc. Prof., Dept of CSE");
     //glRasterPos3f(-0.30,-1.3,-1.0);
     //text("JSS ACADEMY OF TECHNICAL EDUCATION");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.70,-0.9,-1.0);
     text("press -> to continue...");

	glFlush();
}

void display2(){
     glClearColor(0.3,0.1,0.3,0);
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.20,0.8,-1.0);
     text("***  MENU  *** ");

     glColor3f(1.0,1.0,0.1);
     glRasterPos3f(-0.65,0.3,-1.0);
     text("MODE SIMULTATION:");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,0.3,-1.0);
     text("1. Press d/D for DAY MODE (Default)");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,0.2,-1.0);
     text("2. Press n/N for NIGHT MODE");

     glColor3f(1.0,1.0,0.1);
     glRasterPos3f(-0.65,0.0,-1.0);
     text("BOAT SIMULTATION:");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,0.0,-1.0);
     text("1. Press r/R for Normal Speed (Default)");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,-0.1,-1.0);
     text("2. Press + to increase the Speed");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,-0.2,-1.0);
     text("3. Press - to decrease the Speed");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(0.15,-0.3,-1.0);
     text("4. Press s/S to halt the Boat");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.30,-0.5,-1.0);
     text("Press ENTER to start the Simulation.");
     glRasterPos3f(-0.30,-0.6,-1.0);
     text("Press e/E to Exit.");

     glColor3f(1.0,1.0,0.1);
     glRasterPos3f(-0.30,-0.7,-1.0);
     text("(Note: All keys are case insensitive)");

     glColor3f(1.0,1.0,1.0);
     glRasterPos3f(-0.95,-0.9,-1.0);
     text("press <- to go back...");

     glFlush();
}

void circle(GLdouble rad){
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(175, 150);
    glVertex2i(180, 290);
    glVertex2i(184, 290);
    glVertex2i(190, 150);
    glEnd();
}

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}
    ///sky///
void sky() {
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(135,206,250);
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);
    glEnd();
    }

void Sun_Model(){
    glPushMatrix();
    glColor3d(255,255,0);
    glTranslatef(30.0, 7.0, 0);
    glutSolidSphere(1.0, 250, 250);
    glPopMatrix();
}

void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin,0,0,-1.5);
    Sun_Model();
    glPopMatrix();

}
    ///cloud 1///
void clouds(){
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();
    glPopMatrix();

///cloud 2///
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(16.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(16.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(14.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(17.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();
    glPopMatrix();

  ///cloud 3///
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(22.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(22.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(23.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(23.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(24.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(21.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPopMatrix();
    }

void sea(){
  ///sea portion///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(65,105,225);
    glVertex2f(38.0f,-19.0f);
    glVertex2f(38.0f,3.0f);
    glVertex2f(-12.0f,3.0f);
    glVertex2f(-12.0f,-19.0f);
    glEnd();
    }

void left_soil(){
///left soil portion///
//polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(24.0f,0.0f);
    glVertex2f(26.0f,1.0f);
    glVertex2f(23.0f,3.0f);
    glVertex2f(-12.0f,3.0f);
    glVertex2f(-12.0f,0.0f);
    glEnd();

//polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(25.0f,-3.0f);
    glVertex2f(27.0f,-1.5f);
    glVertex2f(24.0f,0.0f);
    glVertex2f(-12.0f,0.0f);
    glVertex2f(-12.0f,-3.0f);
    glEnd();

//polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(26.0f,-4.5f);
    glVertex2f(28.0f,-4.0f);
    glVertex2f(25.0f,-3.0f);
    glVertex2f(-12.0f,-3.0f);
    glVertex2f(-12.0f,-4.5f);
    glEnd();

//polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(22.0f,-9.0f);
    glVertex2f(29.5f,-7.0f);
    glVertex2f(26.0f,-4.5f);
    glVertex2f(-12.0f,-4.5f);
    glVertex2f(-12.0f,-9.5f);
    glEnd();

//polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(22.0f,-11.5f);
    glVertex2f(25.0f,-10.0f);
    glVertex2f(22.0f,-9.0f);
    glVertex2f(-12.0f,-9.0f);
    glVertex2f(-12.0f,-11.5f);
    glEnd();

///left sidewise border partition///
 //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(26.0f,0.5f);
    glVertex2f(26.0f,1.0f);
    glVertex2f(24.0f,0.0f);
    glVertex2f(24.5f,-0.25f);
    glEnd();

 //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(27.0f,-2.0f);
    glVertex2f(27.0f,-1.5f);
    glVertex2f(25.0f,-3.0f);
    glVertex2f(25.5f,-3.15f);
    glEnd();

//polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(28.0f,-4.4f);
    glVertex2f(28.0f,-4.0f);
    glVertex2f(26.0f,-4.5f);
    glVertex2f(26.3f,-4.8f);
    glEnd();

//polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(29.5f,-7.5f);
    glVertex2f(29.5f,-7.0f);
    glVertex2f(22.0f,-9.0f);
    glVertex2f(23.0f,-9.3f);
    glEnd();

//polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(25.0f,-10.5f);
    glVertex2f(25.0f,-10.0f);
    glVertex2f(22.0f,-11.5f);
    glVertex2f(22.0f,-12.0f);
    glEnd();

//polygon 6
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(22.0f,-12.0f);
    glVertex2f(22.0f,-11.5f);
    glVertex2f(-12.0f,-11.5f);
    glVertex2f(-12.0f,-12.0f);
    glEnd();
    }

void house(){
///house on right side///
//polygon1//
    glPushMatrix();
    //glTranslatef(-4.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);

    //glColor3ub(25,25,112);
    glColor3ub(47,79,79);
    glVertex2f(25.3,1.2);
    glVertex2f(21.3,1.2);
    glVertex2f(23,-1);
    glVertex2f(27,-1);
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(47,79,79);
    glVertex2f(21.5,1);
    glVertex2f(21.3,1.2);
    glVertex2f(19.5,-1);
    glVertex2f(20,-1);
    glEnd();

//polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(184,134,11);
    glVertex2f(21.5,1);
    glVertex2f(20,-1);
    glVertex2f(20,-2.5);
    glVertex2f(23,-3);
    glVertex2f(23,-1);
    glEnd();

//polygon4//
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(22,-2);
    glVertex2f(22,-1);
    glVertex2f(21,-1);
    glVertex2f(21,-2);
    glEnd();

//polygon5//
    glBegin(GL_POLYGON);
    glColor3ub(47,79,79);
    glVertex2f(23,-3);
    glVertex2f(20,-2.5);
    glVertex2f(19.7,-2.9);
    glVertex2f(23,-3.5);
    glEnd();

//polygon6//
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
    glVertex2f(26.5,-3);
    glVertex2f(26.5,-1);
    glVertex2f(23,-1);
    glVertex2f(23,-3);
    glEnd();

//polygon7//
    glBegin(GL_POLYGON);
    glColor3ub(47,79,79);
    glVertex2f(23,-3);
    glVertex2f(23,-3.5);
    glVertex2f(27,-3.5);
    glVertex2f(26.5,-3);
    glEnd();

///door:right///
//polygon a//
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(25.5,-3);
    glVertex2f(25.5,-1.2);
    glVertex2f(24,-1.2);
    glVertex2f(24,-3);
    glEnd();

//polygon b//
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(24.7,-3);
    glVertex2f(24.7,-1.4);
    glVertex2f(24,-1.2);
    glVertex2f(24,-3);
    glEnd();

//polygon c//
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(25.5,-3);
    glVertex2f(25.5,-1.2);
    glVertex2f(24.8,-1.4);
    glVertex2f(24.8,-3);
    glEnd();
    glPopMatrix();
}

void hills(){
///hillview///
    glPushMatrix();
    glTranslatef(-3.0f,3.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.0f,0.0f);
    glVertex3f(-9,0,0);
    glVertex3f(9,0,0);
    glVertex3f(0,8,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2f,3.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.0f,0.0f);
    glVertex3f(10,0,0);
    glVertex3f(18,0,0);
    glVertex3f(14,5,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f,3.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.0f,0.0f);
    glVertex3f(10,0,0);
    glVertex3f(28,0,0);
    glVertex3f(19,8,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.2f,3.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.0f,0.0f);
    glVertex3f(10,0,0);
    glVertex3f(16,0,0);
    glVertex3f(13,5,0);
    glEnd();
    glPopMatrix();
    }

void tree(){
///tree left side
    glPushMatrix();
    //glTranslatef(21.0f,0.0f,0.0f);
//polygon 1
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-9.5,1);
    glVertex2f(-9,1.5);
    glVertex2f(-9.5,2.5);
    glVertex2f(-10,2);
    glEnd();

//polygon 2
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-9,1.5);
    glVertex2f(-8.5,1);
    glVertex2f(-8,2);
    glVertex2f(-8,2.5);
    glEnd();

//polygon 3
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-9.5,1);
    glVertex2f(-9.5,-3.5);
    glVertex2f(-9,-4);
    glVertex2f(-8.5,-3.5);
    glVertex2f(-8.5,1);
    glEnd();

//polygon 4
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-8.5,-3);
    glVertex2f(-9.5,-3);
    glVertex2f(-10.5,-3.5);
    glVertex2f(-7.5,-3.5);
    glEnd();

//triangle 1
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(-10,-0.5);
    glVertex2f(-9.5,-1);
    glVertex2f(-9.5,-0.6);
    glEnd();

//triangle 2
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(-9.5,1);
    glVertex2f(-9,1.5);
    glVertex2f(-8.5,1);
    glEnd();
    glPopMatrix();

    ///tree upper side///
    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-10.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-9.5, 3.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-7.5, 1.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-7.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-8.5, 3.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-10.5, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-7.5, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50,205,50);
    glTranslatef(-9.0, 5.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();
    }

void moving_boat1(){

///boat-1 motion left to right
    glPushMatrix();
    glTranslatef(_moveA, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
        glVertex2f(1.0f, -14.0f);
        glVertex2f(1.50f, -13.0f);
        glVertex2f(-2.0f, -13.0f);
        glVertex2f(-3.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.5f);
        glVertex2f(2.0f, -14.0f);
        glVertex2f(-3.0f, -14.0f);
        glVertex2f(-3.0f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(-3.0f, -14.5f);
        glVertex2f(-3.0f, -14.0f);
        glVertex2f(-4.5f, -13.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.5f);
        glVertex2f(3.5f, -13.7f);
        glVertex2f(2.0f, -14.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.0f);
        glVertex2f(1.5f, -13.0f);
        glVertex2f(1.0f, -14.0f);
    glEnd();

    glPopMatrix();
    }

void moving_boat2(){
///boat-2 motion right to left
    glPushMatrix();
    glTranslatef(_moveB, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
        glVertex2f(22.0f, -17.5f);
        glVertex2f(21.0f, -16.5f);
        glVertex2f(17.50f, -16.5f);
        glVertex2f(18.0f, -17.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
        glVertex2f(22.0f, -18.0f);
        glVertex2f(22.0f, -17.5f);
        glVertex2f(17.0f, -17.5f);
        glVertex2f(17.0f, -18.0f);
    glEnd();

   /* glBegin(GL_QUADS);
    glColor3ub(255,99,71);
        glVertex2f(20.5f, -16.5f);
        glVertex2f(21.0f, -14.5f);
        glVertex2f(18.5f, -14.5f);
        glVertex2f(18.0f, -16.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
        glVertex2f(19.8f, -14.5f);
        glVertex2f(19.8f, -14.0f);
        glVertex2f(19.7f, -14.0f);
        glVertex2f(19.7f, -14.5f);
    glEnd(); */

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(17.0f, -18.0f);
        glVertex2f(17.0f, -17.5f);
        glVertex2f(15.5f, -17.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(22.0f, -17.5f);
        glVertex2f(22.0f, -18.0f);
        glVertex2f(23.5f, -17.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(17.0f, -17.5f);
        glVertex2f(18.0f, -17.5f);
        glVertex2f(17.5f, -16.5f);
    glEnd();

    glPopMatrix();
    }

void windmill(){
///windmill structure///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(192,192,192);

    glVertex2f(-5.0f,2.0f);
    glVertex2f(-4.0f,-6.0f);
    glVertex2f(-8.0f,-6.0f);
    glVertex2f(-7.0f,2.0f);
    glVertex2f(-6.5f,3.0f);
    glVertex2f(-5.5f,3.0f);
    glEnd();

     //circle//
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-6.0f,3.0f,0.0f);
    glutSolidSphere(0.5,150,150);
	glRotatef(_angle1, 0.0f, 0.0f,1.0f);

    glBegin(GL_QUADS);// first stand to hold the blade
    glColor3ub(255,255,0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(5.0f,0.0f);
    glVertex2f(5.0f,0.25f);
    glVertex2f(0.0f,0.25f);
    glEnd();

    glBegin(GL_QUADS);// second stand to hold the blade
    glColor3ub(255,255,0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,5.0f);
    glVertex2f(-0.25f,5.0f);
    glVertex2f(-0.25f,0.0f);
    glEnd();

    glBegin(GL_QUADS);// third stand to hold the blade
    glColor3ub(255,255,0);
    glVertex2f(0.0f,-0.25f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-5.0f,0.0f);
    glVertex2f(-5.0f,-0.25f);
    glEnd();

    glBegin(GL_QUADS);// fourth stand to hold the blade
    glColor3ub(255,255,0);
    glVertex2f(0.25f,0.0f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-5.0f);
    glVertex2f(0.25f,-5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// first triangular blade to hold the blade
    glColor3ub(128,0,0);
    glVertex2f(0.25f,0.0f);
    glVertex2f(5.0f,-2.5f);
    glVertex2f(5.0f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// second triangular blade to hold the blade
    glColor3ub(128,0,0);
    glVertex2f(0.0f,0.025f);
    glVertex2f(2.5f,5.0f);
    glVertex2f(0.0f,5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// third triangular blade to hold the blade
    glColor3ub(128,0,0);
    glVertex2f(-0.25f,0.0f);
    glVertex2f(-5.0f,2.5f);
    glVertex2f(-5.0f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// fourth triangular blade to hold the blade
    glColor3ub(128,0,0);
    glVertex2f(0.0f,-0.025f);
    glVertex2f(-2.5f,-5.0f);
    glVertex2f(0.0f,-5.0f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
    }

void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

void moon(){
///moon///
    //1st circle for moon
     glPushMatrix();
     glColor3f(1,1,1);
     glTranslatef(-8.0,10.0, 0);
     glutSolidSphere(1, 250, 250);
     glPopMatrix();

   //2nd circle for moon
     glPushMatrix();
     glColor3f(0,0,0);
     glTranslatef(-7.5,10.25, 0);
     glutSolidSphere(1, 250, 250);
     glPopMatrix();
}

void person(int n, int x, int y, int r) {
	//draw round head
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void straight_lines(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void drawScene() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW);

    sky();
    Sun();
    Moving_Sun_Model();
    clouds();
    sea();
    left_soil();
    hills();
    glPushMatrix();
        glTranslatef(25.0f,5.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(23.0f,2.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(21.0f,0.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.0f,2.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-4.0f,-1.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-8.0f,-4.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-15.0f,-7.0f,0.0f);
        house();
    glPopMatrix();


    glColor3ub(255, 255, 255);//boy colour pink
	person(25, 250, 200, 40);//head
	glLineWidth(10);
	straight_lines(250, 200, 250, 80);//body
	straight_lines(260, 170, 220, 130);//left hand
	straight_lines(220, 130, 230, 120);//left hand down
	straight_lines(250, 160, 280, 130);//right hand
	straight_lines(280, 130, 290, 160);//right hand down
	straight_lines(250, 80, 240, 50);//left foot
	straight_lines(240, 50, 210, 30);//left foot up
	straight_lines(250, 80, 260, 70);//right foot
	straight_lines(260, 70, 250, 30);//right foot


    moving_boat1();
    moving_boat2();
    windmill();

    glPopMatrix();
    glutSwapBuffers();
}

void sun_move(){

    if(sun_mode==1){
        sun_spin = sun_spin + 0.5;
    }
    else if(sun_mode==0){
        sun_spin = sun_spin;
    }

}

void move_right(){
    sun_move();
    spin = spin + 1.0;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;
    }
    if(cx>1000){
            cx= -400;
    }
    if(dx>1000){
            dx= -500;
    }
    glutPostRedisplay();
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void nightsky(){
    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);
    glEnd();
    }

void stars(){
     ///Stars///
    glPushMatrix();
    glPointSize(2.0);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);

    glVertex2f(1,4);
    glVertex2f(2,7.5);
    glVertex2f(4,5);
    glVertex2f(-2,8);
    glVertex2f(30,5);
    glVertex2f(-1,9);
    glVertex2f(35,7);
    glVertex2f(-3,7);
    glVertex2f(-7,5);
    glVertex2f(10,7.5);
    glVertex2f(12,8.5);
    glVertex2f(-11,6);
    glVertex2f(37,7.5);
    glVertex2f(-10,4.5);
    glVertex2f(13,7);
    glVertex2f(14,7.5);
    glVertex2f(18,10);
    glEnd();
    glPopMatrix();
    }

void nightclouds(){
    ///cloud 1///
    glPushMatrix();

    glTranslatef(_moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPopMatrix();

///cloud 2///
    glPushMatrix();

    glTranslatef(_moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(16.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(16.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(14.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(17.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPopMatrix();

  ///cloud 3///
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(22.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(22.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(23.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(23.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(24.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105,105,105);
    glTranslatef(21.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPopMatrix();
    }

void drawScene2() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW);

    nightsky();
    moon();
    stars();
    //Moving_Sun_Model();
    nightclouds();
    sea();
    left_soil();
    hills();
    glPushMatrix();
        glTranslatef(25.0f,5.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(23.0f,2.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(21.0f,0.0f,0.0f);
        tree();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.0f,2.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-4.0f,-1.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-8.0f,-4.0f,0.0f);
        house();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-15.0f,-7.0f,0.0f);
        house();
    glPopMatrix();
    moving_boat1();
    moving_boat2();
    windmill();

    glPopMatrix();
    glutSwapBuffers();
}

void SpecialInput(int key, int x, int y){
    switch(key)
    {
    case GLUT_KEY_UP:
        glutDisplayFunc(drawScene);
        flag = -1;
        break;
    case GLUT_KEY_DOWN:
        glutDisplayFunc(drawScene2);
        flag = -1;
        break;

    case GLUT_KEY_RIGHT:
        if (flag == 0) {
            glutDisplayFunc(display2);
            flag = 1;
            break;
        }
        else
            break;

    case GLUT_KEY_LEFT:
       if (flag == 1) {
            glutDisplayFunc(display);
            flag = 0;
            break;
        }
        else
            break;
    }
glutPostRedisplay();
}

void update1(int value) {
    _moveA += speed;
    if(_moveA > 38)
    {
        _moveA = -38;
    }
//_moveA += 0.11;
    glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 13:
    glutDisplayFunc(drawScene);
    flag = -1;
    break;

case 'E':
case 'e':
    exit(0);

case 'D':
case 'd':
    glutDisplayFunc(drawScene);
    flag = -1;
    break;
case 'N':
case 'n':
    glutDisplayFunc(drawScene2);
    flag = -1;
    break;

case 'S':
case 's'://stops
    speed = 0.0f;
    break;

case 'R':
case 'r'://runs
    speed = 0.02f;
    break;
case '+'://runs
     speed += 0.05f;
    break;
case '-'://runs
     speed -= 0.05f;
    break;

case 'q':
case 'Q':
    sun_mode=1;
    break;
case 'w':
case 'W':
    sun_mode=0;
    break;

glutPostRedisplay();
	}
}

void handleMouse(int button, int state, int x, int y) {
     switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                glutIdleFunc(move_right);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}

void update2(int value) {
    if(_moveB < -36)
    {
        _moveB = +38;
    }
     //Notify GLUT that the display has changed

_moveB -= 0.13;
    glutTimerFunc(20, update2, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}
//function for windlmill
void update3(int value) {
    _angle1-=2.0f;
    if(_angle1 > 360.0)
    {
        _angle1-=360;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(10, update3, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update4(int value) {
    if(_moveC > +36)
    {
        _moveC = -38;
    }
     //Notify GLUT that the display has changed
_moveC += 0.13;
    glutTimerFunc(20, update4, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}

void create_menu(void){
     glutCreateMenu(menu);
     glutAttachMenu(GLUT_LEFT_BUTTON);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
     glutAddMenuEntry("Day", 1);
     glutAddMenuEntry("Night", 2);
     //glutAddMenuEntry("Back", 4);
     glutAddMenuEntry("Stop All Movement", 3);
     glutAddMenuEntry("Exit", 5);
}

void menu(int val){
    switch (val) {
     case 1:
			glutDisplayFunc(drawScene);
			glutPostRedisplay();
			break;
     case 2:
            glutDisplayFunc(drawScene2);
            glutPostRedisplay();
		 break;
	 case 3:
		glutDisplayFunc(move_right);
		glutPostRedisplay();
			break;
	case 4:

            glutDisplayFunc(display2);
            flag = 1;
            break;
		   /* glutDisplayFunc(display2);
		    flag = -1;
			//glutPostRedisplay();
			break;*/
	 case 5: exit(0);
   }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(1500,800);

    glutCreateWindow ("Lake View");

    create_menu();
    glutSpecialFunc(SpecialInput);

    glutTimerFunc(20, update1, 0); //Add a timer
    glutTimerFunc(20, update2, 0); //Add a timer

    glutTimerFunc(10, update3, 0);
    glutTimerFunc(20, update4, 0);

    glutDisplayFunc(display);

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);

    init ();
    glDisable(GL_DEPTH_TEST);
    glutMainLoop();

}
