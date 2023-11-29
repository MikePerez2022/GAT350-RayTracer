#include "Renderer.h"
#include "Random.h"
#include "Color.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World!";

	Renderer renderer;
	renderer.initialize();
	renderer.CreateWindow("Ray Tracer", 400, 300);

	seedRandom((glm::uint)time(nullptr));
	
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

	}

	renderer.Shutdown();

	return 0;
}