#pragma once
#include "Ray.h"
#include "Camera.h"
#include "Color.h"
#include "Canvas.h"
#include "Object.h"
#include <memory>

class Scene
{
public:
	Scene() = default;
	Scene(const color3_t& topColor, const color3_t& bottomColor) :
		m_topColor{ topColor },
		m_bottomColor{ bottomColor }
	{}

	void Render(class Canvas& canvas, int numSamples, int depth);
	color3_t Trace(const ray_t& ray, float minDistance, float maxDistance, raycastHit_t& raycastHit, int depth);
	void AddObject(std::unique_ptr<Object> object) { m_objects.push_back(std::move(object)); }

	void SetCamera(std::shared_ptr<Camera> camera) { m_camera = camera; }

	void InitScene01(Scene& scene, const Canvas& canvas);
	void InitScene02(Scene& scene, const Canvas& canvas);

private:
	std::vector<std::unique_ptr<Object>> m_objects;
	std::shared_ptr<Camera> m_camera;	

	color3_t m_topColor{ 1 };
	color3_t m_bottomColor{ 0 };
};