#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ObjetoGeometrico{
    private:
        double d1;
        double d2;

    public: 
        ObjetoGeometrico(double D1, double D2) : d1(D1), d2(D2){};
        ObjetoGeometrico() = default;

        virtual double calcArea(){return d1 * d2;}
        virtual double calcPerimetro(){return d1 + d2;}

        virtual void mostraDados(){
            cout << "D1: " << d1 << endl << "D2: " << d2 << endl << endl;
        }
};

class Circulo : public ObjetoGeometrico{
    private: 
        double raio;
        double centro;

    public:
        Circulo(double r, double c) : raio(r), centro(c){};

        double calcArea() override{
            double pi = 3.14159;
            return pi * (raio * raio);
        }

        double calcPerimetro() override{
            double pi = 3.14159;
            return 2 * (pi * raio);
        }

        void mostraDados() override{
            cout << "Raio: " << raio << endl << "Centro: " << centro << endl << endl;
        }
};

class Retangulo : public ObjetoGeometrico{
    private:
        double base;
        double altura;

    public:
        Retangulo(double b, double h) : base(b), altura(h){};

        double calcArea() override{
            return base * altura;
        }

        double calcPerimetro() override{
            return 2*(base + altura);
        }

        void mostraDados() override{
            cout << "Base: " << base << endl << "Altura: " << altura << endl << endl;
        }
};

class Triangulo : public ObjetoGeometrico{
    private:
        double lado1;
        double lado2;
        double lado3;

    public:
        Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3){};

        double calcPerimetro() override{
            return lado1 + lado2 + lado3;
        }

        double calcArea() override{
            double s = calcPerimetro()/2;
            return sqrt(s*(s - lado1) * (s - lado2) * (s - lado3));
        }

        void mostraDados() override{
            cout << "Lado 1: " << lado1 << endl << "Lado 2: " << lado2 << endl << "Lado 3: " << endl << endl;
        }
};

int main(){
    Circulo c(5, 0);
    Retangulo r(16, 7);
    Triangulo t(5, 5, 5);

    //Polimorfismo
    ObjetoGeometrico *obj;
    
    //Utilizando um único objeto como referência
    obj = &c;
    cout << c.calcPerimetro() << endl;

    obj = &r;
    cout << r.calcPerimetro() << endl;

    obj = &t;
    cout << t.calcPerimetro() << endl;
}