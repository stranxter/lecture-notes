#include <iostream>

struct Point
{
    double x;
    double y;
};

Point western(Point p1, Point p2)
{
    if (p1.x < p2.x)
    {
        return p1;
    }
    return p2;
}

void print(Point p)
{
    std::cout << "{" << p.x << "," << p.y << "}";
}

struct Vector3D
{
    double coords[3];
};

Vector3D sumVectors(Vector3D v1,Vector3D v2)
{
    Vector3D result = {{v1.coords[0]+v2.coords[0], 
                        v1.coords[1] + v2.coords[1], 
                        v1.coords[2]+v2.coords[2]}};
    
    return result;
}



int main()
{

    Vector3D v1 = {{0,0,0}};
    Vector3D v2 = {{1,1,1}};

    v1 = v2;

    Point points[] = {{0,0},{1,1},{-1,1},{1,-1}};

    Point westmost = points[0];
    for (int i = 1; i < 4; ++i)
    {
        westmost = western(westmost,points[i]);
    }

    print(westmost);

}