#include "Game.h"

Game game;

void draw()
{
	
}

void update(int a)
{

}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Game");
	gluOrtho2D(-VIEWPORT_STD_WIDTH / 2, VIEWPORT_STD_WIDTH / 2, -VIEWPORT_STD_HEIGHT / 2, VIEWPORT_STD_HEIGHT / 2);
	glutDisplayFunc(draw);
	glutTimerFunc(0, update, 0);
	glutMainLoop();

	return 0;
}