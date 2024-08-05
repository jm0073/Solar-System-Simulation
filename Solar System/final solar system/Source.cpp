#include <GL/glut.h>
#include<iostream>
using namespace std;

const float M_PI = 3.1415926f;
float planetSpeeds[] = { 1.46f, 0.78f, 1.00f, 0.61f, 0.43f, 0.30f, 0.21f, 0.18f }; // comparative angles for planet rotations(J)
float angles[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
float distances[] = { 7.0f, 9.0f, 11.0f, 13.5f, 19.5f, 26.5f, 32.0f, 36.5f }; // Distances of planets from the Sun(A)
float rad[] = { 0.3f, 0.35f, 0.65f, 0.6f, 2.9f, 1.8f, 1.5f ,1.35f }; // radius of each planet(T)

float viewAngleX = 0.0f; // initial view and distance(I)
float viewAngleY = 0.0f;
float viewDistance = 70.0f;

float moonAngle = 0.0f;
float moonDistance = 1.0f; // Distance of moon from Earth(N)

bool showAmbientLight = false;
bool showOrbitLines = false;

void drawSphere(GLfloat radius, GLfloat slices, GLfloat stacks, GLfloat* color) {
	glColor3fv(color);
	glutSolidSphere(radius, slices, stacks);
}

void drawOrbitLines() { //orbit lines
	if (showOrbitLines) {
		glDisable(GL_LIGHTING);
		glColor3f(0.8f, 0.8f, 1.0f); // Set color for orbit lines (white)
		for (int i = 0; i < 8; ++i) {
			glBegin(GL_LINE_LOOP);
			for (int j = 0; j < 360; j += 5) {
				float x = cos(j * M_PI / 180) * distances[i];
				float y = sin(j * M_PI / 180) * distances[i];
				glVertex3f(x, y, 0.0f);
			}
			glEnd();
		}
		glEnable(GL_LIGHTING);
	}
}
void sunlight() { //set sun as light source
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat lightPosition[] = { 0.0, 0.0, 0.0, 1.0 }; // Position at the center of the Sun
	GLfloat lightColor[] = { 1.0, 1.0, 1.0, 1.0 }; // White light for the Sun
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
}

void drawMoon() {
	glPushMatrix();
	glRotatef(angles[2], 0.0f, 0.0f, 1.0f); // Rotate around Earth's orbit
	glTranslatef(distances[2], 0.0f, 0.0f); // Move to Earth's position
	glRotatef(moonAngle, 0.0f, 0.0f, 1.0f); // Rotate moon around Earth
	glTranslatef(moonDistance, 0.0f, 0.0f); // Move moon away from Earth

	// Set material properties for the moon
	GLfloat moonAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat moonDiffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, moonAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, moonDiffuse);

	GLfloat moonColor[] = { 0.9f, 0.9f, 0.9f }; // Light gray
	drawSphere(0.2f, 30, 30, moonColor); // Draw moon
	glPopMatrix();
}

void drawSaturnRings() {
	glPushMatrix();
	glRotatef(angles[5], 0.0f, 0.0f, 1.0f); // Rotate around Z-axis (same as Saturn)
	glTranslatef(distances[5], 0.0f, 0.0f); // Move to Saturn's position
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f); // Rotate to align with Saturn's equator
	// Draw Saturn's rings
	glColor4f(0.8f, 0.6f, 0.5f, 0.5f); // Light brownish color with transparency
	glutSolidTorus(0.3f, 3.0f, 50, 50); // Draw rings with smaller inner radius
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -viewDistance);
	glRotatef(viewAngleY, 1.0f, 0.0f, 0.0f);
	glRotatef(viewAngleX, 0.0f, 1.0f, 0.0f);

	// Draw the Sun
	glPushMatrix();
	GLfloat sunColor[] = { 25.2f, 25.9f, 0.0f }; // Yellow
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sunColor);
	glutSolidSphere(5.0f, 50, 50); // Draw Sun
	glPopMatrix();

	sunlight();
	drawOrbitLines();

	// Set material properties for the planets
	GLfloat planetColors[][3] = {
		{0.8f, 0.8f, 0.8f}, // Mercury 
		{0.9f, 0.8f, 0.5f}, // Venus 
		{0.0f, 0.5f, 1.0f}, // Earth
		{1.0f, 0.5f, 0.0f}, // Mars 
		{0.7f, 0.6f, 0.5f}, // Jupiter 
		{0.5f, 0.1f, 0.8f}, // Saturn 
		{0.5f, 0.7f, 1.0f}, // Uranus 
		{0.0f, 0.0f, 1.0f}  // Neptune 
	};

	// Draw the planets
	for (int i = 0; i < 8; ++i) {
		glPushMatrix();
		glRotatef(angles[i], 0.0f, 0.0f, 1.0f); // Rotate planet around Z-axis
		glTranslatef(distances[i], 0.0f, 0.0f); // Move planet away from the Sun
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, planetColors[i]); // Set planet's material properties
		drawSphere(rad[i], 50, 50, planetColors[i]); // Draw planet
		glPopMatrix();
		angles[i] += 0.05f * planetSpeeds[i]; // Increment angle for planet rotation
		if (angles[i] > 360.0f) {
			angles[i] -= 360.0f;
		}
	}

	// Draw the moon
	drawMoon();
	// Draw the rings of Saturn
	glPushMatrix();
	glRotatef(angles[5], 0.0f, 0.0f, 1.0f); // Rotate around Z-axis (same as Saturn)
	glTranslatef(distances[5], 0.0f, 0.0f); // Move to Saturn's position
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // Rotate to align with Saturn's equator
	// Draw Saturn's rings
	glColor4f(0.8f, 0.6f, 0.5f, 0.5f); // Light brownish color with transparency
	glutSolidTorus(0.3f, 3.0f, 50, 50); // Draw rings with smaller inner radius
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		viewAngleX -= 5.0f;
		break;
	case GLUT_KEY_RIGHT:
		viewAngleX += 5.0f;
		break;
	case GLUT_KEY_UP:
		viewAngleY -= 5.0f;
		break;
	case GLUT_KEY_DOWN:
		viewAngleY += 5.0f;
		break;
	case GLUT_KEY_HOME:
		viewAngleX = 0.0f;
		viewAngleY = 0.0f;
		drawOrbitLines();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'i':
		viewDistance -= 1.0f;
		break;
	case 'o':
		viewDistance += 1.0f;
		break;
	case 'n': // Toggle ambient light
		showAmbientLight = !showAmbientLight;
		if (showAmbientLight == false) {
			GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
		}
		else {
			GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
		}
		break;
	case 'm': // Toggle orbit lines
		showOrbitLines = !showOrbitLines;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void idle() {
	for (int i = 0; i < 8; ++i) {
		angles[i] += 0.05f * planetSpeeds[i]; // Increment angle for planet rotation
		if (angles[i] > 360.0f) {
			angles[i] -= 360.0f;
		}
	}
	// Increment angle for moon rotation
	moonAngle += 0.05f;
	if (moonAngle > 360.0f) {
		moonAngle -= 360.0f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Reset view angles
		viewAngleX = 0.0f;
		viewAngleY = 90.0f;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Solar System");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
