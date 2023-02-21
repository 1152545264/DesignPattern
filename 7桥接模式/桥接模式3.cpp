#include <bits/stdc++.h>
using namespace std;

// 摘自《C++20设计模式》对应章节的代码
struct Render // 渲染基类
{
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRender : Render // 向量渲染
{
    virtual void render_circle(float x, float y, float radius) override
    {
        cout << "Rastering circle of radius " << radius << endl;
    }
};

struct RasterRender : Render // 光栅渲染
{
    virtual void render_circle(float x, float y, float radius) override
    {
        cout << "Drawing a vector circle of radius " << radius << endl;
    }
};

struct Shape
{
protected:
    Render &render;
    Shape(Render &render) : render(render) {}

public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape
{
    float x, y, radius;
    Circle(Render &render, float x, float y, float radius) : Shape(render), x{x}, y{y}, radius{radius}
    {
    }

    virtual void draw() override
    {
        render.render_circle(x, y, radius);
    }

    virtual void resize(float factor) override
    {
        radius *= factor;
        cout << "Success resize the radius to " << radius << endl;
    }
};

int main()
{
    RasterRender rr;
    Circle cr{rr, 5, 5, 5};
    cr.draw();
    cr.resize(10);
    cr.draw();
    return 0;
}