#include <iostream>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    // Constructor
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Obtener las coordenadas x e y
    double getX() 
    {
        return x;
    }

    double getY() 
    {
        return y;
    }

    // Establecer las coordenadas x e y
    void setX(double xCoord)
    {
        x = xCoord;
    }

    void setY(double yCoord)
    {
        y = yCoord;
    }
};

int main()
{
    // Crear un objeto Point utilizando el constructor
    Point p1(3.5, 2.0);

    // Obtener y mostrar las coordenadas x e y
    cout << "Coordenada x: " << p1.getX() << endl;
    cout << "Coordenada y: " << p1.getY() << endl;

    // Establecer nuevas coordenadas utilizando los métodos
    p1.setX(1.0);
    p1.setY(4.5);

    // Obtener y mostrar las nuevas coordenadas
    cout << "Nueva coordenada x: " << p1.getX() << endl;
    cout << "Nueva coordenada y: " << p1.getY() << endl;

    return 0;
}
