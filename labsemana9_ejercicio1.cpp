#include <iostream>

using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // obtener el ancho
    double getWidth() 
    {
        return width;
    }

    // obtener la altura
    double getHeight() 
    {
        return height;
    }

    // Establecer el ancho
    void setWidth(double w)
    {
        width = w;
    }

    // Establecer la altura
    void setHeight(double h)
    {
        height = h;
    }

    // Calcular el área
    double calculateArea() 
    {
        return width * height;
    }
};

int main()
{
    // Crear un objeto Rectangle
    Rectangle rect(5.0, 3.0);

    // Obtener y mostrar el ancho y la altura
    cout << "Ancho: " << rect.getWidth() << endl;
    cout << "Altura: " << rect.getHeight() << endl;

    // Cambiar el ancho y la altura
    rect.setWidth(7.0);
    rect.setHeight(4.0);

    // Calcular y mostrar el área
    double area = rect.calculateArea();
    cout << "Area: " << area << endl;

    return 0;
}
