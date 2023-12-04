#include "Renderer.h"
#include "Random.h"
#include "Color.h"
#include "Canvas.h"
#include "Scene.h"
#include "Material.h"
#include "Sphere.h"
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

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene;
	scene.SetCamera(camera);

	// create material
	auto material = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });

	// create objects -> add to scene
	for (int i = 0; i < 10; i++)
	{
		auto sphere = std::make_unique<Sphere>(glm::vec3{random(-10, 20),random(-10, 20),random(-50,-10)}, random(1, 5), material);
		scene.AddObject(std::move(sphere));
	}
		

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
		scene.Render(canvas);
		canvas.Update();

		renderer.PresentCanvas(canvas);

	}

	renderer.Shutdown();

	return 0;
}