// NAMA : ELIZA TALENT SIRAIT
// NIM : 24060123140147

#include <GLUT/glut.h>
#include <cmath>

// konstanta untuk lingkaran
const double PI = 3.142857143;

// Variabel posisi dan rotasi mobil
float xPos = 0.0, yPos = -1.5; // Posisi awal mobil
float angle = 0.0; // Sudut rotasi mobil

// Fungsi untuk menggambar lingkaran
void drawCircle(float cx, float cy, float r, int segments, float red, float green, float blue) {
    float angle;
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        angle = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

// Fungsi untuk menggambar pohon dengan batang lebih tinggi dan daun lebih besar
void drawTree(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // Batang pohon
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.1, -0.8);
    glVertex2f(0.1, 0.0);
    glVertex2f(-0.1, 0.0);
    glEnd();

    drawCircle(0.0, 0.5, 0.5, 30, 0.0, 0.8, 0.0);

    glPopMatrix();
}

void tampil()
{
    // Perintah menghapus layar
    glClear(GL_COLOR_BUFFER_BIT);

    // Fungsi untuk jalan abu-abu
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, -1.5);
    glVertex2f(5.0, -1.5);
    glVertex2f(5.0, -3.0);
    glVertex2f(-5.0, -3.0);
    glEnd();
    glPopMatrix();

    // Fungsi untuk garis jalan putih
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    for (float i = -4.5; i < 4.5; i += 1.5) {
        glBegin(GL_POLYGON);
        glVertex2f(i, -2.2);
        glVertex2f(i + 0.8, -2.2);
        glVertex2f(i + 0.8, -2.0);
        glVertex2f(i, -2.0);
        glEnd();
    }
    glPopMatrix();

    drawTree(-3.0, -1.0);
    drawTree(-1.5, -1.0);
    drawTree(0.0, -1.0);
    drawTree(1.5, -1.0);
    drawTree(3.0, -1.0);

    // Fungsi untuk mobil
    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(1.2, 1.2, 1.0);

    // Fungsi untuk badan mobil
    glColor3f(1.0, 0.4, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, -0.5);
    glVertex2f(1.5, -0.5);
    glVertex2f(1.5, 0.2);
    glVertex2f(-1.5, 0.2);
    glEnd();

    // Fungsi untuk atap mobil
    glColor3f(1.0, 0.4, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.2);
    glVertex2f(1.0, 0.2);
    glVertex2f(0.7, 0.8);
    glVertex2f(-0.7, 0.8);
    glEnd();

    // Fungsi untuk jendela kiri
    glColor3f(0.8, 0.6, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, 0.25);
    glVertex2f(-0.1, 0.25);
    glVertex2f(-0.1, 0.7);
    glVertex2f(-0.7, 0.7);
    glEnd();

    // Fungsi untuk jendela kanan
    glColor3f(0.8, 0.6, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.25);
    glVertex2f(0.8, 0.25);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.1, 0.7);
    glEnd();

    // **Ban Depan**
    glPushMatrix();
    glTranslatef(1.0, -0.7, 0.0);
    drawCircle(0.0, 0.0, 0.35, 50, 0.0, 0.0, 0.0);
    glPopMatrix();

    // Fungsi untuk ban depan
    glPushMatrix();
    glTranslatef(-1.0, -0.7, 0.0);
    drawCircle(0.0, 0.0, 0.35, 50, 0.0, 0.0, 0.0);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

// Fungsi untuk input keyboard atau kursor
void specialKeys(int key, int x, int y)
{
    float moveSpeed = 0.2;
    float rotateSpeed = 5.0;

    switch (key)
    {
    case GLUT_KEY_UP: // Maju
        xPos += moveSpeed * cos(angle * PI / 180);
        yPos += moveSpeed * sin(angle * PI / 180);
        break;
    case GLUT_KEY_DOWN: // Mundur
        xPos -= moveSpeed * cos(angle * PI / 180);
        yPos -= moveSpeed * sin(angle * PI / 180);
        break;
    case GLUT_KEY_LEFT: // Rotasi ke kiri
        angle += rotateSpeed;
        break;
    case GLUT_KEY_RIGHT: // Rotasi ke kanan
        angle -= rotateSpeed;
        break;
    case 27: // Escape key untuk keluar
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil");

    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    glutDisplayFunc(tampil);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}
