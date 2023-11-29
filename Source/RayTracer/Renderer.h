#pragma once
#include "SDL.h"
#include "Canvas.h"
#include <string>

class Renderer
{
public:
	Renderer() = default;

	bool initialize();
	void Shutdown();
	bool CreateWindow(const std::string& title, int width, int height);
	void PresentCanvas(const Canvas& canvas);

private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
};