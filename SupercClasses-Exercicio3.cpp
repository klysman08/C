/**Nome: Klysman Rezende Alves Vieira
   Matricula: 2017108779 **/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;


class Point {
    float x;
    float y;

public:

    //Construtores da classe Point

    void setCoordenadas (float x, float y){
        this->x = x;
        this->y = y;
    }

    //Metodos da classe Point

    float getx(){
        return x;
    }

    float gety(){
        return y;
    }

    //toString()
};

class Triangulo: public Point {

    //Atributos lados do triangulo

    int ladoA;
    int ladoB;
    int ladoC;

    public:

    //Construtores da classe Triangulo

    Triangulo(int a, int b, int c) {
        this->ladoA = a;
        this->ladoB = b;
        this->ladoC = c;
    }

    //Metodos da classe Triangulo

    int calcula_perimetro(){
        return ladoA + ladoB + ladoC;
    }

    int calcula_area(){
        float p = (ladoA + ladoB + ladoC)/2;
        return (sqrt((p*(p-ladoA)*(p-ladoB)*(p-ladoC)))); //fórmula para calcular a área
    }

    void tipo_triangulo(){
        if (ladoA == ladoB && ladoA == ladoC)
            cout << " O triangulo e equilatero. ";
        else if ((ladoA == ladoB && ladoA != ladoC) || (ladoA == ladoC && ladoA != ladoB) || (ladoB == ladoC && ladoB != ladoA))
            cout << " O triangulo e isosceles. ";
        else
            cout << " O triangulo e escaleno. ";
    }
};


class Circle: public Point {

    //variáveis de instancia privadas, isto é, não acessíveis de fora desta classe.

    double radius;
    string color;
    double comprimento;


    public:

    //Primeiro construtor o qual atribui valores iniciais a ambos: radius, color e comprimento.

    Circle( ) {
        this->radius = 1.0;
        this->color = "red";
    }

    //Segundo construtor que inicia radius com o parâmetro recebido, e matem color com o valor padrão definido.

    Circle(double r) {
        this->radius = r;
        this->color = "red";
    }

    //Terceiro construtor que inicia radius e color recebidos.

    Circle(double r, string c) {
        this->radius = r;
        this->color = c;
    }

    //Quarto construtor que inicia radius padrão e recebe e color do int main.

    Circle(string c) {
        this->radius = 1.0;
        this->color = c;
    }

    //Metodo de acesso para obter o valor armazenado em radius

    double getRadius() {
        return radius;
    }

    //Metodo de acesso para computar a área de um circulo.

    double getArea() {
        return radius*radius*M_PI; //M_PI está definida no arquivo <math.h>
    }

    //Metodo de acesso para saber a cor.

    string getColor() {
        return color;
    }

    //Metodo para alterar o valor do radius

    void setRadius(double radius) {
        this->radius = radius;
    }

    //Metodo para alterar o valor de color

    void setColor(string color) {
        this->color = color;
    }

    //Metodo de acesso para saber o calculo do comprimento

    double getComprimento() {
        return radius*2*M_PI;
    }

    string toString() {
        char buffer[50];
        int n = sprintf(buffer,"Circulo: raio = %d  cor = %s", radius, color.c_str());
        return string(buffer);
    }
};


int main( ) {


    // Declara c1 como variável habilitada a armazenar uma referencia para objeto da classe Circle.

    Circle *c1;

    // Atribui a c1 .a referencia retornada pelo construtor padrão Circle ()

    c1 = new Circle();

     // Para invocar os metodos classe Circle para operar sobre a instância c1, usa-se o operador ponto (“.”).
     // Em outras palavras: usa-se o ponto para enviar uma mensagem ao objeto c1 para que ele execute um de seus métodos.

    cout << "O circulo tem o raio de " << c1->getRadius() << ", area de " << c1->getArea() << " e comprimento de " << c1->getComprimento();


     // Declara e aloca uma segunda instancia da classe Circle chamada c2 com o valor do radius igual a 2.0 e color com valor padrão.

    Circle * c2 = new Circle(2.0);

    //c2->setRadius(5.0);
    //c2->setColor("green");

    //Para invocar os metodos a operar sobre a instância c2, usa-se o operador ponto (“.”)


    cout << "\nO circulo tem raio de " << c2->getRadius() << ", area de " << c2->getArea() << " e comprimento de " << c2->getComprimento();


    Circle * c3 = new Circle(2.0, "verde");
    cout << "\nO circulo tem raio de " << c3->getRadius() << ", area de " << c3->getArea() << " e cor " << c3->getColor() << " e comprimento de " << c3->getComprimento();

    c3->setColor("Cinza");
    cout << "\nApos modificar os valores : O circulo tem raio de " << c3->getRadius() << ", area de " << c3->getArea() << ", cor " << c3->getColor() << " e comprimento de " << c3->getComprimento();

    //cout << "\n\n\n" << c3->toString() << "\n\n\n";

    c3->setCoordenadas(5.0, 3.0);

    cout << "\nCoordenada x e: " << c3->getx() << "\nCoordenada y e: " << c3->gety();


    //DESAFIO 3 (TRIANGULO, POINT)

    int x, y, z; // recebendo os lados do triangulo do usuario
    cout << "\ninsira os lados do triangulo\n ";
    cin >> x >> y >> z;
    if ( (x + y < z) || (x + z < y) || (y + z < x)){
            cout << "Não pode formar um triangulo";
        }
    else{
        Triangulo *T1 = new Triangulo(x, y, z);
        cout << "/nPerimetro do triangulo: " << T1->calcula_perimetro();
        cout << "/nArea do triangulo: /n" << T1->calcula_area();
        T1->tipo_triangulo();
    }
 }
