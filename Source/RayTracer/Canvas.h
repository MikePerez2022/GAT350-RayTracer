#pragma once

class Canvas
{
public:
    Canvas(int width, int height, const class Renderer& renderer);
    ~Canvas();

    void Update();

    //void Clear(const color4_t& color);
    //void DrawPoint(<const reference to glm integer vector 2> point, const color4_t& color);

    //<return const reference of m_size> GetSize() const { return m_size; }

    //<allow Renderer to access Canvas private data>

private:
    //<SDL Texture pointer(forward declaration)> m_texture<default to nullptr>;
    //<vector of rgba_t> m_buffer;

    //<glm integer vector2> m_size<default to 0>;
};