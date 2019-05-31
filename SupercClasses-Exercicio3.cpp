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
        return (sqrt((p*((p-ladoA)*(p-ladoB)*(p-ladoC))))); //f�rmula para calcular a �rea
        
        
    }
    
    float angulo1(){
    	return acos((ladoA*ladoA) - ((ladoB*ladoB) + (ladoC*ladoC)))/(-2*ladoB*ladoC);
	}
	float angulo2(){
		return acos((ladoB*ladoB) - ((ladoA*ladoA) + (ladoC*ladoC)))/(-2*ladoA*ladoC);
	}
	float angulo3(){
		return acos((ladoC*ladoC) - ((ladoB*ladoB) + (ladoA*ladoA)))/(-2*ladoB*ladoA);
	}

    string tipo_triangulo(){
    	char n[20];
        if (ladoA == ladoB && ladoA == ladoC){
        	int a = sprintf(n, "Equilatero");
            cout << " O triangulo e equilatero. ";
    	}
        else if ((ladoA == ladoB && ladoA != ladoC) || (ladoA == ladoC && ladoA != ladoB) || (ladoB == ladoC && ladoB != ladoA)){
            int a = sprintf(n, "Isosceles");
			cout << " O triangulo e isosceles. ";
		}
        else{
        	int a = sprintf(n, "Escaleno");
            cout << " O triangulo e escaleno. ";
    	}
        return string(n);
    }
    
    string toString() {
		char buffer[500]; 
		
		//N�o est� sendo poss�vel fazer a chamada das fun��es publicas dentro do Sprintf abaixo.
		//Colocando a formula direto na chamada funciona mas quando chama a fun��o printa Zero.
	    
		int n = sprintf(buffer,"Lados do Triangulo: A = %d || B = %d || C = %d || Area = %6.2f ||  Ang1 = %6.2f || Ang2 = %6.2f || Ang3 = %6.2f", this->ladoA, this->ladoB, this->ladoC, (sqrt((((ladoA + ladoB + ladoC)/2)*((((ladoA + ladoB + ladoC)/2)-ladoA)*(((ladoA + ladoB + ladoC)/2)-ladoB)*(((ladoA + ladoB + ladoC)/2)-ladoC))))), angulo1(), angulo2(), angulo3());
		return string(buffer);
	}
    
};


class Circle: public Point {

    //vari�veis de instancia privadas, isto �, n�o acess�veis de fora desta classe.
		
		
    double radius;
    string color;
    double comprimento;


    public:

    //Primeiro construtor o qual atribui valores iniciais a ambos: radius, color e comprimento.

    Circle( ) {
        this->radius = 1.0;
        this->color = "red";
    }

    //Segundo construtor que inicia radius com o par�metro recebido, e matem color com o valor padr�o definido.

    Circle(double r) {
        this->radius = r;
        this->color = "red";
    }

    //Terceiro construtor que inicia radius e color recebidos.

    Circle(double r, string c) {
        this->radius = r;
        this->color = c;
    }

    //Quarto construtor que inicia radius padr�o e recebe e color do int main.

    Circle(string c) {
        this->radius = 1.0;
        this->color = c;
    }
    

    //Metodo de acesso para obter o valor armazenado em radius

    double getRadius() {
        return radius;
    }

    //Metodo de acesso para computar a �rea de um circulo.

    double getArea() {
        return radius*radius*M_PI; //M_PI est� definida no arquivo <math.h>
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
	
	//Metodo de ToString para imprimir resultados dos metodos acima.
    string toString() {
    	char buffer[50];
        int n = sprintf(buffer,"Circulo: raio = %6.2f || Cor = %s || Area = %6.2f ", this->radius, this->color.c_str(), getArea());
        return string(buffer);
    }
};


int main( ) {

    
    // Circle *c1;   		// Declara c1 como vari�vel habilitada a armazenar uma referencia para objeto da classe Circle.
    // c1 = new Circle();   // Atribui a c1 .a referencia retornada pelo construtor padr�o Circle ()

   	// Ou dessa forma para instaciar um novo objeto tipo Circle ->
    Circle *c1 = new Circle();

    // Para invocar os metodos classe Circle para operar sobre a inst�ncia c1, usa-se o operador ponto (�.�).
    // Em outras palavras: usa-se o ponto para enviar uma mensagem ao objeto c1 para que ele execute um de seus m�todos.
	
	
	cout << "\n\n\nInstanciando os objetos c1 c2 c3 \n\n";
    cout << "O circulo tem o raio de " << c1->getRadius() << ", area de " << c1->getArea() << " e comprimento de " << c1->getComprimento();


     //Declara e aloca uma segunda instancia da classe Circle chamada c2 com o valor do radius igual a 2.0 e color com valor padr�o.

    Circle * c2 = new Circle(2.0);

    //c2->setRadius(5.0);
    //c2->setColor("green");

    //Para invocar os metodos a operar sobre a inst�ncia c2, usa-se o operador ponto (�.�)
	cout << "\nO circulo tem raio de " << c2->getRadius() << ", area de " << c2->getArea() << " e comprimento de " << c2->getComprimento();

	//Criando um novo Circle passando atributo de raio e cor
    Circle * c3 = new Circle(4.0, "verde");
    cout << "\nO circulo tem raio de " << c3->getRadius() << ", area de " << c3->getArea() << " e cor " << c3->getColor() << " e comprimento de " << c3->getComprimento();
	
	//Alterando o valor da cor em C3
    c3->setColor("Cinza");
    
    
    cout << "\n\n\nApos modificar os valores com a fun��o c3->setColor: \nO circulo tem raio de  " << c3->getRadius() << ", area de " << c3->getArea() << ", cor " << c3->getColor() << " e comprimento de " << c3->getComprimento();
    
    //Chamada para o metodo ToString de Circle
	cout << "\n\n\n====================================== \n";
    cout << "AQUI ESTA O TOSTRING:  " << c3->toString() << "\n";
    cout << "====================================== \n";


	
	//Alterando o valor das coordenadas em C3
    c3->setCoordenadas(5.0, 3.0);
    
	//Imprimindo as coordenadas x y de C3
    cout << "\n Coordenada x e: " << c3->getx() << "\n Coordenada y e: " << c3->gety();
	

    //Desafio 3 - Recebendo do usuario os lados do triangulo e validando se � lados de tringulo
    int x, y, z; 
    cout << "insira os lados do triangulo \n ";
    cin >> x >> y >> z ;
    if ( (x + y < z) || (x + z < y) || (y + z < x)){
            cout << "N�o pode formar um triangulo";
        }
    else{
        Triangulo *T1 = new Triangulo(x, y, z);
        cout << "\n Perimetro do triangulo: " << T1->calcula_perimetro();
        cout << "\n Area do triangulo: " << T1->calcula_area() << "\n";
        T1->tipo_triangulo();
        cout << T1->toString();
    }
 }
 
 
