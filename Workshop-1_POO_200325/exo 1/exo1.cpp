#include <iostream>
#include <cmath>

// Classe Circle
class Circle {
public:
    // Attributs publics (pour rester compatible avec main, qui accède directement aux membres)
    double x;
    double y;
    double r;
    
    // Constructeur
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    // Méthode pour modifier la position du centre
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    }
    
    // Méthode pour calculer le périmètre
    double perimeter() const {
        return 2 * M_PI * r;
    }
    
    // TODO: Ajout d'une méthode pour calculer l'aire du cercle
    double area() const {
        return M_PI * r * r;
    }
};

// Classe Rectangle
class Rectangle {
public:
    // Attributs publics
    double x;
    double y;
    double w;
    double h;
    
    // Constructeur
    Rectangle(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {}

    // Méthode pour modifier la position du coin supérieur gauche
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    }
    
    // Méthode pour calculer le périmètre
    double perimeter() const {
        return 2 * (w + h);
    }
    
    // TODO: Ajout d'une méthode pour calculer l'aire du rectangle
    double area() const {
        return w * h;
    }
};

int main() {
    // Utilisation de la classe Circle
    Circle c(0, 0, 1);
    std::cout << "Périmètre du cercle : " << c.perimeter() << std::endl;
    c.set_pos(1, 1);
    std::cout << "Coordonnées du centre : (" << c.x << ", " << c.y << ")" << std::endl;
    std::cout << "Aire du cercle : " << c.area() << std::endl;

    // Utilisation de la classe Rectangle
    Rectangle r(0, 0, 1, 2);
    std::cout << "Périmètre du rectangle : " << r.perimeter() << std::endl;
    r.set_pos(-1, -1);
    std::cout << "Coordonnées du coin supérieur gauche : (" << r.x << ", " << r.y << ")" << std::endl;
    std::cout << "Aire du rectangle : " << r.area() << std::endl;
    
    return 0;
}
