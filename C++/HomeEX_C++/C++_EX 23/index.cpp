#include <iostream>
#include <ostream>

#define CIRCLE_AREA(R) R / 2 * R / 2 * 3.14
#define SQUARE_AREA(a) a *a

class Shape
{
    std::string shapeName;
    float shapeArea;

public:
    void printArea(float area, std::string name)
    {
        this->shapeArea = area;
        this->shapeName = name;
        std::cout << "Area of a " << name << " is: " << area << std::endl;
    }

    bool operator==(const Shape &obj)
    {
        bool status{false};

        if (shapeArea == obj.shapeArea)
        {
            status = true;
        }

        return status;
    }
};

class Point
{
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x{_x}, y{_y} {};

    friend std::ostream &operator<<(std::ostream &out, const Point &point)
    {
        out << "(" << point.x << ", " << point.y << ")" << std::endl;
        return out;
    }
};

class Circle : public Shape
{
    std::string name{"Circle"};
    float area;

public:
    float calculateArea(float r)
    {
        Point point{0, 0};

        area = CIRCLE_AREA(r);
        printArea(area, name);
        return area;
    }
};

class Square : public Shape
{
    std::string name{"Square"};
    float area;

public:
    float calculateArea(float a)
    {
        Point point{static_cast<int>(a/2), static_cast<int>(a/2)};

        area = SQUARE_AREA(a);
        printArea(area, name);
        return area;
    }
};

int main(void)
{
    Circle squareOne;
    squareOne.calculateArea(5);

    Square squareTwo;
    squareTwo.calculateArea(6);

    if (squareOne == squareTwo)
    {
        std::cout << "They are equal" << std::endl;
    }
    else
    {
        std::cout << "They are not equal" << std::endl;
    }

    return 0;
}