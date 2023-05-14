#include <iostream>
#include <vector>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    // Constructor
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Obtener las coordenadas X e Y
    double getX() 
    {
        return x;
    }

    double getY() 
    {
        return y;
    }
};

int main()
{
    // Crear un polígono usando un vector de puntos
    vector<Point> polygon;

    // Agregar puntos al polígono
    polygon.push_back(Point(1.0, 1.0));
    polygon.push_back(Point(3.0, 2.0));
    polygon.push_back(Point(2.5, 4.0));
    polygon.push_back(Point(1.5, 3.5));

    // Mostrar las coordenadas de los puntos del polígono
    for (Point &point : polygon)
    {
        cout << "Coordenada x: " << point.getX() << ", Coordenada y: " << point.getY() << endl;
    }

    return 0;
}
