2.
#include <GL/glut.h>
#include <math.h>

GLfloat hexagonSize = 0.5; // Initial size of the hexagon

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the hexagon
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); // White
    for (int i = 0; i < 6; ++i) {
        float angle = 2.0 * 3.14159265358979323846 * i / 6;
        float x = hexagonSize * cos(angle);
        float y = hexagonSize * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void winReshapeFcn(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width <= height) {
        glOrtho(-1.0, 1.0, -1.0 * (GLfloat)height / (GLfloat)width,
            1.0 * (GLfloat)height / (GLfloat)width, -1.0, 1.0);
    }
    else {
        glOrtho(-1.0 * (GLfloat)width / (GLfloat)height,
            1.0 * (GLfloat)width / (GLfloat)height, -1.0, 1.0, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hexagon Window Reshape");
    glutDisplayFunc(display);
    glutReshapeFunc(winReshapeFcn); 
    glutMainLoop();
    return 0;
}
