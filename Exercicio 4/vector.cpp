#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;


struct Pessoa { //Essa é a sua classe cliente. Só mudar os parâmetros e o construtor para atender ao cliente lá
 	string nome;
 	int numero;
 
 public:
 	Pessoa (string nome, int numero)
 	{
 		this->nome = nome;
		this->numero = numero;	
	}
};


void imprime(const vector<Pessoa> &lista) 
{
    for (int i = 0; i < lista.size(); ++i)
    {
        cout << lista[i].nome << endl;
        cout << lista[i].numero << endl;
    }
}


int main()
{
    /*vector<Pessoa> lista_tel = {
        {"Joao",123456},
        {"Carlos",234567},
        {"Andre",345678}
    };*/
    Pessoa *luiz = new Pessoa ("Luiz", 21);
    Pessoa *klysman = new Pessoa ("Klysman", 11);
    
    vector<Pessoa> nome;
    
    nome.push_back(*luiz);
    nome.push_back(*klysman);

    imprime(lista_tel);

    return 0;
}
