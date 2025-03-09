// NAMA : ELIZA TALENT SIRAIT
// NIM : 24060123140147

#include <GLUT/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846;

// Fungsi untuk menggambar lingkaran
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * PI / 180.0f;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Fungsi display untuk menampilkan lingkaran
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.5f);
    glutSwapBuffers();
}

// Inisialisasi OpenGL
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Koordinat tampilan
}

// Fungsi utama lingkaran
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
