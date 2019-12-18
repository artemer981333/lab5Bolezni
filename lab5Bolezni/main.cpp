#include "Game.h"
#include "Controller.h"
#include "glut.h"

#define LATENCY 10

Game game;
Controller controller = Controller(&game);

void draw()
{
	controller.draw();
}

void update(int a)
{
	controller.update();
	controller.draw();
	glutTimerFunc(LATENCY, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	controller.inputKey(key, true);
}

void keyboardUp(unsigned char key, int x, int y)
{
	controller.inputKey(key, false);
}

void mouse(int button, int state, int x, int y)
{
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;

	int newX = x - WINDOW_WIDTH / 2;
	int newY = WINDOW_HEIGHT / 2 - y;

	controller.inputMouse(newX, newY);
}

int main()
{
	game.init("config.txt");
	game.startGame();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Game");

	gluOrtho2D(-VIEWPORT_STD_WIDTH / 2, VIEWPORT_STD_WIDTH / 2, -VIEWPORT_STD_HEIGHT / 2, VIEWPORT_STD_HEIGHT / 2);

	glutDisplayFunc(draw);
	glutTimerFunc(LATENCY, update, 0);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouse);


	glutMainLoop();

	game.endGame();
	return 0;
}