#include <iostream>
#include <math.h>

using namespace std;

class Circle {
 // vari�veis de instancia privadas, isto �, n�o acess�veis de fora desta classe.
 double radius;
 string color;

 double getcomprimento() {
 return radius*2*M_PI;

public:
// primeiro construtor o qual atribui valores iniciais a ambos: radius e color .


 Circle( ) {
 radius = 1.0;
 color = "red";

 }

 // Segundo construtor que inicia radius com o par�metro recebido, e matem color com
 // o valor padr�o definido.

 Circle(double r) {
 radius = r;
 color = "red";
 }

 Circle(double r, string c) {
 radius = r;
 color = c;
 }

 // Metodo de acesso para obter o valor armazenado em radius

 double getRadius() {
 return radius;

 }
 // Metodo de acesso para computar a �rea de um circulo.

 double getArea() {
 return radius*radius*M_PI; //M_PI est� definida no arquivo <math.h>

}

string getColor() {
 return color;

}

void setRadius(double r) {
    this->radius = r
};

void setColor(String c) {
    this->color = c
 }


int main( ) {


 // Declara c1 como vari�vel habilitada a armazenar uma referencia para objeto da classe Circle.
    Circle *c1;
 // atribui a c1 .a referencia retornada pelo construtor padr�o Circle ()


    c1 = new Circle();


 // Para invocar os metodos classe Circle para operar sobre a inst�ncia c1,
 // usa-se o operador ponto (�.�).
 // Em outras palavras: usa-se o ponto para enviar uma mensagem ao objeto c1 para que
 // ele execute um de seus m�todos.


    cout << "O circulo tem o raio de " << c1->getRadius() << " e area de " << c1->getArea();


 // Declara e aloca uma segunda instancia da classe Circle chamada c2
 // com o valor do radius igual a 2.0 e color com valor padr�o.


    Circle * c2 = new Circle(2.0);


 // Para invocar os metodos a operar sobre a inst�ncia c2, usa-se o operador ponto (�.�)


    cout <<"O circulo tem raio de " << c2->getRadius() << " e area de " << c2->getArea();

 }

 //#Item 4 = privado nao dara certo
 //#Consigo alterar o valor do atributo do objeto
 //#7 - criar um metodo privado antes do public para o objeto comprimento
 //#Criar um metodo para converter tudo em string ToString
