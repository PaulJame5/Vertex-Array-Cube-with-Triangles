#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

// We have 36 verts with 3 points
float temporaryVerts[36 * 3];

// Vertices for one Triangle
float vertices[] = { 
	-1.0f,-1.0f,-3, // t1
	-1.0f,-1.0f, -5.0f,
	-1.0f, 1.0f, -5.0f, // t1
	1.0f, 1.0f,-3, // t2
	-1.0f,-1.0f,-3,
	-1.0f, 1.0f,-3, // t2
	1.0f,-1.0f, -5.0f,//t3s
	-1.0f,-1.0f,-3,
	1.0f,-1.0f,-3,//t3e
	1.0f, 1.0f,-3,//t4s
	1.0f,-1.0f,-3,
	-1.0f,-1.0f,-3,//t4
	-1.0f,-1.0f,-3,//t5
	-1.0f, 1.0f, -5.0f,
	-1.0f, 1.0f,-3,//t5
	1.0f,-1.0f, -5.0f,//t6
	-1.0f,-1.0f, -5.0f,
	-1.0f,-1.0f,-3,//t6
	-1.0f, 1.0f, -5.0f,//t7
	-1.0f,-1.0f, -5.0f,
	1.0f,-1.0f, -5.0f,//t7
	1.0f, 1.0f, -5.0f,//t8
	1.0f,-1.0f,-3,
	1.0f, 1.0f,-3,//t8
	1.0f,-1.0f,-3,//t9
	1.0f, 1.0f, -5.0f,
	1.0f,-1.0f, -5.0f,//t9
	1.0f, 1.0f, -5.0f,//t10
	1.0f, 1.0f,-3,
	-1.0f, 1.0f,-3,//t10
	1.0f, 1.0f, -5.0f,//t11
	-1.0f, 1.0f,-3,
	-1.0f, 1.0f, -5.0f,//t11
	1.0f, 1.0f, -5.0f,//t12
	-1.0f, 1.0f, -5.0f,
	1.0f,-1.0f, -5.0f//t12
};

// Colors for those vertices
float colors[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f };

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();


	// Rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!pressedRotation)
		{

			pressedRotation = true;

			// loop through 36 times
			for (int i = 0; i < 36; i++)
			{
				// offsets for choosing index
				int x = i * 3;
				int y = i * 3 + 1;
				int z = i * 3 + 2;
				// temporary vector for performing calculations
				MyVector3 tVect = MyVector3{vertices[ x],vertices[y],vertices[z] };

				// rotate along the z axis by 20 degrees
				tVect = MyMatrix3::rotationZ(20) * tVect;

				vertices[x] = tVect.x;
				vertices[y] = tVect.y;
				vertices[z] = tVect.z;
			}



				
		} // end !pressed
		

	}
	else
	{
		pressedRotation = false;
	}

	//scale
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!pressedScale)
		{

			pressedScale = true;

			// loop through 36 times
			for (int i = 0; i < 36; i++)
			{
				// offsets for choosing index
				int x = i * 3;
				int y = i * 3 + 1;
				int z = i * 3 + 2;
				// temporary vector for performing calculations
				MyVector3 tVect = MyVector3{ vertices[x],vertices[y],vertices[z] };

				// scale cube by 20% less
				tVect = MyMatrix3::scale(.8) * tVect;

				vertices[x] = tVect.x;
				vertices[y] = tVect.y;
				vertices[z] = tVect.z;
			}




		} // end !pressed


	}
	else
	{
		pressedScale = false;
	}



	// Move cube
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		if (!pressedTransformation)
		{

			pressedTransformation = true;

			// loop through 36 times
			for (int i = 0; i < 36; i++)
			{
				// offsets for choosing index
				int x = i * 3;
				int y = i * 3 + 1;
				int z = i * 3 + 2;
				// temporary vector for performing calculations
				MyVector3 tVect = MyVector3{ vertices[x],vertices[y],vertices[z] };
				// temp vector for moving along y axis
				MyVector3 displacementAmount = MyVector3{ 0,0.002,0 };

				tVect = MyMatrix3::translation(displacementAmount) * tVect;

				vertices[x] = tVect.x;
				vertices[y] = tVect.y;
				vertices[z] = tVect.z;
			}




		} // end !pressed


	}
	else
	{
		pressedTransformation = false;
	}

}

void Game::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 36);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

