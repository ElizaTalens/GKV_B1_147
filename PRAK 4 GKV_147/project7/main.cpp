//
//  main.cpp
//  project7
//
//  Created by Eliza Talent Sirait on 23/03/25.
//

#include <math.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angleX = 0.0f, angleY = 0.0f;
float x = 0.0f, y = 1.75f, z = 15.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float ratio;
int w, h;

void Reshape(int w1, int h1)
{
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe()
{
    lx = sin(angleX);
    ly = sin(angleY);
    lz = -cos(angleX);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(float i)
{
    x += i * lx * 0.5;
    z += i * lz * 0.5;
    orientMe();
}

void strafeMeFlat(float i)
{
    x += i * lz * 0.5;
    z -= i * lx * 0.5;
    orientMe();
}

void moveMeUp(float i)
{
    y += i * 0.5;
    orientMe();
}

void Grid()
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (float i = -50; i < 50; i += 1.5)
    {
        glVertex3f(i, 0, -50);
        glVertex3f(i, 0, 50);
        glVertex3f(-50, 0, i);
        glVertex3f(50, 0, i);
    }
    glEnd();
}

void Mobil()
{
    glPushMatrix();
    glScalef(1.6, 1.6, 1.6);
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 3);

    // Badan mobil
    glPushMatrix();
    glTranslatef(-0.9, 0.8, 0);
    glScalef(4, 2, 4);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 0.8, 0);
    glScalef(6, 2, 4);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.40, 1.4, 0);
    glScalef(7.5, 6, 8);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(0.25);
    glPopMatrix();
    
    // Lampu depan
    glPushMatrix();
    glTranslatef(-1.87, 1.0, 0.7);
    glScalef(0.2, 0.31, 0.9);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.87, 1.0, -0.7);
    glScalef(0.2, 0.31, 0.9);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();

    // Lampu belakang
    glPushMatrix();
    glTranslatef(2.5, 1.0, 0.7);
    glScalef(0.2, 0.31, 0.9);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5, 1.0, -0.7);
    glScalef(0.2, 0.31, 0.9);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix();

    // Kaca depan
    glPushMatrix();
    glTranslatef(-0.5, 1.33, -0.001);
    glScalef(9, 11, 19);
    glRotatef(228, 0, 0, 250);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidCube(0.1);
    glPopMatrix();

    // Roda depan kiri
    glTranslatef(0, 0.3, 0.5);
    glPushMatrix();

    // Depan kiri
    glPushMatrix();
    glTranslatef(-1.0, 0.1, 0.5);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidTorus(0.16, 0.26, 20, 20);
    glPopMatrix();

    // velg depan kiri
    glPushMatrix();
    glTranslatef(-1.0, 0.1, 0.6);
    glScalef(0.8, 0.8, 0.1);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Belakang kiri
    glPushMatrix();
    glTranslatef(1.8, 0.1, 0.5);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidTorus(0.16, 0.26, 20, 20);
    glPopMatrix();

    // velg belakang kiri
    glPushMatrix();
    glTranslatef(1.8, 0.1, 0.6);
    glScalef(0.8, 0.8, 0.1);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // Roda depan kanan
    glTranslatef(0, 0.0, -1.0);
    glPushMatrix();
    glTranslatef(-1.0, 0.1, -0.5);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidTorus(0.16, 0.26, 20, 20);
    glPopMatrix();

    // velg depan kanan
    glPushMatrix();
    glTranslatef(-1.0, 0.1, -0.6);
    glScalef(0.8, 0.8, 0.1);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Roda Belakang kanan
    glPushMatrix();
    glTranslatef(1.8, 0.1, -0.5);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidTorus(0.16, 0.26, 20, 20);
    glPopMatrix();

    // velg belakang kanan
    glPushMatrix();
    glTranslatef(1.8, 0.1, -0.6);
    glScalef(0.8, 0.8, 0.1);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Grid();
    Mobil();
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w': moveMeFlat(1); break;
    case 's': moveMeFlat(-1); break;
    case 'a': strafeMeFlat(1); break;
    case 'd': strafeMeFlat(-1); break;
    case 'q': moveMeUp(1); break;
    case 'e': moveMeUp(-1); break;
    case 'j': angleX -= 0.05f; orientMe(); break;
    case 'l': angleX += 0.05f; orientMe(); break;
    case 'i': angleY += 0.05f; orientMe(); break;
    case 'k': angleY -= 0.05f; orientMe(); break;
    case 27: exit(0); break; // ESC
    }
    glutPostRedisplay();
}

void lighting()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat light_pos[] = { 0.0f, 20.0f, 10.0f, 1.0f };
    GLfloat ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - MacBook Fix");
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(keyboard);
    lighting();
    init();
    glutMainLoop();
    return 0;
}
