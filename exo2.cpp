#include <iostream>

using namespace std;


/*
You can write your class Fraction here
*/

class Fraction {
    private:
    int numerateur;
    int denominateur;
    
public:
    // Constructeur par défaut (initialise la fraction à 0/1)
    Fraction() : numerateur(1), denominateur(1) {}
    
    // Constructeur avec paramètres
    Fraction(int num, int den) : numerateur(num), denominateur(den) {
        if (denominateur == 0)
            throw std::invalid_argument("Denominateur ne peut être zéro");
    }
    
    // Getters
    int getNumerateur() const { return numerateur; }
    int getDenominateur() const { return denominateur; }
    
    // Setters
    void setNumerateur(int num) { numerateur = num; }
    void setDenominateur(int den) { 
        if (den == 0)
            throw std::invalid_argument("Denominateur ne peut être zéro");
        denominateur = den; 
    }
    
    // Addition de deux fractions : this + other
    Fraction add(const Fraction& other) const {
        int num = numerateur * other.denominateur + denominateur * other.numerateur;
        int den = denominateur * other.denominateur;
        return Fraction(num, den);
    }
    
    // Soustraction de deux fractions : this - other
    Fraction minus(const Fraction& other) const {
        int num = numerateur * other.denominateur - denominateur * other.numerateur;
        int den = denominateur * other.denominateur;
        return Fraction(num, den);
    }
    
    // Multiplication de deux fractions
    Fraction multiply(const Fraction& other) const {
        int num = numerateur * other.numerateur;
        int den = denominateur * other.denominateur;
        return Fraction(num, den);
    }
    
    // Division de deux fractions : this / other
    Fraction divide(const Fraction& other) const {
        if (other.numerateur == 0)
            throw std::invalid_argument("Division par zéro");
        int num = numerateur * other.denominateur;
        int den = denominateur * other.numerateur;
        if (den == 0)
            throw std::invalid_argument("Division par zéro dans le résultat");
        return Fraction(num, den);
    }
};

int main()
{
    /* Test constructors */
    Fraction f0;
    if (f0.getNumerateur() == 1 && f0.getDenominateur() == 1) {
        cout << "[OK] Default constructor works" << endl;
    }
    else {
        cout << "[FAILURE] Default constructor doesn't work" << endl;
    }

    Fraction f1(1, 2);
    if (f1.getNumerateur() == 1 && f1.getDenominateur() == 2) {
        cout << "[OK] Constructor with parameters works" << endl;
    }
    else {
        cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
    }

    Fraction f2(3, 4);

    /* Test add */    
    Fraction f3 = f1.add(f2);
    
    if (f3.getNumerateur() == 10 && f3.getDenominateur() == 8) {
        cout << "[OK] Add method works" << endl;
    }
    else {
        cout << "[FAILURE] Add method doesn't work" << endl;
    }

    /* Test minus */
    f3 = f1.minus(f2);
    if (f3.getNumerateur() == -2 && f3.getDenominateur() == 8) {
        cout << "[OK] Minus method works" << endl;
    }
    else {
        cout << "[FAILURE] Minus method doesn't work" << endl;
    }

    /* Test multiply */
    f3 = f1.multiply(f2);
    if (f3.getNumerateur() == 3 && f3.getDenominateur() == 8) {
        cout << "[OK] Multiply method works" << endl;
    }
    else {
        cout << "[FAILURE] Multiply method doesn't work" << endl;
    }

    /* Test divide */
    f3 = f1.divide(f2);
    if (f3.getNumerateur() == 4 && f3.getDenominateur() == 6) {
        cout << "[OK] Divide method works" << endl;
    }
    else {
        cout << "[FAILURE] Divide method doesn't work" << endl;
    }
    return 0;
}