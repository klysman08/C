/**Nome: Klysman Rezende Alves Vieira
   Matricula: 2017108779
   Exercicio 3 - Classes e Superclasses **/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Editora
{
    string nome_ed;
    string endereco_ed;
    int quantPublicacoes_ed;

public:
    Editora()
    {
        this->nome_ed = "DCC";
        this->endereco_ed = "UFMG";
        this->quantPublicacoes_ed = 5;
    }

    string getnome()
    {
        return nome_ed;
    }

    string getendereco()
    {
        return endereco_ed;
    }

    int getquantPublicacoes()
    {
        return quantPublicacoes_ed;
    }
};

class Publicacoes : public Editora
{
    string pub1 = "Tecnologia";
    string pub2 = "Ciencias";
    string pub3 = "Biologia";
    string pub4 = "Natureza";
    string pub5 = "Bioengenharia";



public:

    string getpub1()
    {
        return pub1;
    }

    string getpub2()
    {
        return pub2;
    }

    string getpub3()
    {
        return pub3;
    }

    string getpub4()
    {
        return pub4;
    }

    string getpub5()
    {
        return pub5;
    }
};

class Cliente : public Publicacoes
{
	string nome;
	int idade;
	string endereco;

	int quantAssinaturas;
	int codigoCliente;

	public:

		Cliente (string nome, int idade, string endereco, int quantAssinaturas)
		{
			this->nome = nome;
			this->idade = idade;
			this->endereco = endereco;
			this->quantAssinaturas = quantAssinaturas;
		}


	void setCodigo () // função para gerar codído ao cliente
	{
		int num;
		num = 100+rand() % 499 + rand() % 400;
		this->codigoCliente = num;

	}

	string getnome()
	{
		return nome;
	}

	int getidade()
	{
		return idade;
	}

	string getendereco()
	{
		return endereco;
	}

	int getquantidadeassinaturas()
	{
		return quantAssinaturas;
	}

	int getcodigo()
	{
	 	return codigoCliente;
	}


};


int main(int argc, char** argv)
{
	int i; // será usada no for para quantidade de assinaturas que o cliente desejou;
	string publicacao; // para armaznenar o nome da assinatura;
	int edicoes; //numero de semanas que a publicação será enviada
	int assinaturas; //quantidade da mesma publicação a ser recebida
	string nome;
	int idade;
	string endereco;
	int quantPublicacoes;

	cout << "Informe os dados para cadastro no sistema \n";
	cout << "Seu nome: ";
	cin >> nome;
	cout << "Sua idade: ";
	cin >> idade;
	cout << "Seu endereco: ";
	cin >> endereco;
	cout << "Quantidade de publicacoes desejadas: ";
	cin >> quantPublicacoes;
	while(quantPublicacoes > 5 || quantPublicacoes < 1)
	{
		cout << "Valor invalido. Insira novamente: ";
		cin >> quantPublicacoes;
	}

	cout << "\nOk! Seus dados foram armazenados. Nossa editora possui as seguintes publicacoes: \n\n1 - Tecnologia\n2 - Ciencias\n3 - Biologia\n4 - Natureza\n5 - Bioengenharia\n\nA partir de agora voce deve inserir o numero correspondente a publicacao desejada, o numero de edicoes e o numero de assinaturas.\n";

	for (i = 0; i < quantPublicacoes; i++)
    {
        cout << "Insira o numero da publicacao " << i+1 << " desejada: ";
        cin >>  publicacao;
        while (publicacao < 1 || publicacao > 5)
        {
            cout << "O valor inserido nao e valido. Insira novamente: ";
            cin >>  publicacao;
        }
        cout << "Insira a quantidade de edicoes semanais desejada: ";
        cin >> edicoes;
        cout << "Insira a quantidade de assinaturas desejada para essa publicacao: ";
        cin >> assinaturas;
    }

	Cliente *c1 = new Cliente(nome, idade, endereco, quantPublicacoes);
	c1->setCodigo();

	//cout<< c1->getnome() << c1->getidade() << c1->getendereco() << c1->getquantidadeassinaturas() << c1->getcodigo();






	return 0;
}
