#include "Renderer.h"
#include "Random.h"
#include "Color.h"
#include "Canvas.h"
#include "Scene.h"
#include "Material.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "Mesh.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World!";

	const int width = 400;
	const int height = 300;
	const int samples = 20;
	const int depth = 8;

	Renderer renderer;
	renderer.initialize();
	renderer.CreateWindow("Ray Tracer", width, height);
	Canvas canvas(width, height, renderer);

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	//std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 2, 10 }, glm::vec3{ 0, 1, 0 }, glm::vec3{ 0, 1, 0 }, 20.0f, aspectRatio);
	//std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 1, 20 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 25.0f, aspectRatio);

	Scene scene(glm::vec3{ 0.0f }, glm::vec3{ 0.5f, 0.7f, 1.0f });
	//scene.SetCamera(camera);

	scene.InitScene01(scene, canvas);

	// create material
	//for (int x = -10; x < 10; x++)
	//{
	//	for (int z = -10; z < 10; z++)
	//	{
	//
	//		std::shared_ptr<Material> material;
	//
	//		// create random material
	//		float r = random01();
	//		if (r < 0.3f)		material = std::make_shared<Lambertian>(glm::rgbColor(glm::vec3{ random(0, 360), 1.0f, 1.0f }));
	//		else if (r < 0.6f)	material = std::make_shared<Metal>(color3_t{ random(0.5f, 1.0f) }, random(0, 0.5f));
	//		else if (r < 0.9f)	material = std::make_shared<Dielectric>(color3_t{ 1.0f }, random(1.1f, 2));
	//		else				material = std::make_shared<Emissive>(glm::rgbColor(glm::vec3{ random(0, 360), 1.0f, 1.0f }), 5.0f);
	//
	//		// set random sphere radius
	//		float radius = random(0.2f, 0.3f);
	//		// create sphere using random radius and material
	//		auto sphere = std::make_unique<Sphere>(glm::vec3{ x + random(-0.5f, 0.5f), radius, z + random(-0.5f, 0.5f)}, radius, material);
	//		// add sphere to the scene
	//		scene.AddObject(std::move(sphere));
	//	}
	//}

	/*auto mesh = std::make_unique<Mesh>(std::make_shared<Emissive>(color3_t{ 1, 1, 1 }, 5.0f));
	mesh->Load("Models/cube.obj", glm::vec3{ 0, 1.7f, 6.5f }, glm::vec3{ 5, 0, 0 }, glm::vec3{ 0.4f, 0.4f, 0.4f });
	scene.AddObject(std::move(mesh));

	mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 1, 1, 1 }));
	mesh->Load("Models/quad.obj", glm::vec3{ 0, 1.4f, 5 }, glm::vec3{ 85, 0, 0 }, glm::vec3{6,5,1});
	scene.AddObject(std::move(mesh));

	mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 1, 1, 1 }));
	mesh->Load("Models/quad.obj", glm::vec3{ 0, 0.5f, 4 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 5, 2.1f, 1 });
	scene.AddObject(std::move(mesh));*/

	//mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 1, 1, 1 }));
	//mesh->Load("Models/quad.obj", glm::vec3{ 0, 0.5f, 12 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 5, 2.1f, 1 });
	//scene.AddObject(std::move(mesh));

	//mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 1, 0, 0 }));
	//mesh->Load("Models/quad.obj", glm::vec3{ -1.0f, 0.5f, 5 }, glm::vec3{ 0, 90, 0 }, glm::vec3{ 7, 3.1f, 1 });
	//scene.AddObject(std::move(mesh));

	/*mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 0, 1, 0 }));
	mesh->Load("Models/quad.obj", glm::vec3{ 1.0f, 0.5f, 5 }, glm::vec3{ 0, -90, 0 }, glm::vec3{ 7, 3.1f, 1 });
	scene.AddObject(std::move(mesh));*/

	/*mesh = std::make_unique<Mesh>(std::make_shared<Lambertian>(color3_t{ 1, 1, 1 }));
	mesh->Load("Models/quad.obj", glm::vec3{ 0, -0.4f, 5 }, glm::vec3{ -85, 0, 0 }, glm::vec3{ 6,5,1 });
	scene.AddObject(std::move(mesh));*/

	/*auto material = std::make_shared<Lambertian>(color3_t{ 1 });
	auto plane = std::make_unique<Plane>(glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, material);
	scene.AddObject(std::move(plane));*/

	seedRandom((glm::uint)time(nullptr));

	// render scene 
	canvas.Clear({ 0, 0, 0, 1 });
	scene.Render(canvas, samples, depth);
	canvas.Update();
	
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
		renderer.PresentCanvas(canvas);
	}

	renderer.Shutdown();

	return 0;
}