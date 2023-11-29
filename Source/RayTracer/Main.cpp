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
	Canvas canvas(400, 300, renderer);

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

		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({random(1, 400), random(1, 400)}, {random01(), random01(), random01(), 1});
		canvas.Update();

		renderer.PresentCanvas(canvas);

	}

	renderer.Shutdown();

	return 0;
}