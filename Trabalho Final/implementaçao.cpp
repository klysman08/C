/**
Nome: Klysman Rezende Alves Vieira
Matricula: 2017108779
Trabalho Final - Sistema de compra de ingressos para eventos  **/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

// Classe Cliente
// Armazena os dados inseridos pelo usuario na interce e serve para imprimir o bilhete e validar pagamento

class Cliente
{
    string nome;
    int idade;
    int cpf; /**De acordo com o slide precisa ter*/

public:
    Cliente()
    {
        this->nome = "Klysman";
        this->idade = 24;
        this->cpf = 123456789;
    }

    Cliente(string nome, int idade, int cpf)
    {
        this->nome = nome;
        this->idade = idade;
        this->cpf = cpf;
    }

    void imprime_cliente(const vector<Cliente> &lista) // Função que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista.size(); ++i)
        {
            cout << "Nome do Cliente: " << lista[i].nome << endl;
            cout << "Idade: " << lista[i].idade << endl;
            cout << "CPF: " << lista[i].cpf << endl;

            cout << "\n====================================================\n";
        }
    }
};

// Classe Evento
// Contém os atributos comuns dos eventos que serão tratados no sistema de compra.

class Evento
{
    string nome;
    string endereco;

public:
    Evento()
    {
        this->nome = "Evento generico";
        this->endereco = "Shopping BH";
    }

    void imprime_evento()
    {
        cout << this->nome << endl;
        cout << this->endereco << endl;
    }
};

// Classe Cinema
// Tem como objetivo caracterizar o tipo de cinema para esse evento

class Cinema
{
    string tipo;
    string filme;
    string data;
    string horario;

public:
    Cinema() // contrutor padrao
    {
        this->tipo = "3D";
        this->filme = "Vingadores";
        this->data = "janeiro";
        this->horario = "21h";
    }

    Cinema(string tipo, string filme, string data, string horario)
    {
        this->tipo = tipo;
        this->filme = filme;
        this->data = data;
        this->horario = horario;
    }

    void imprime_filmes(const vector<Cinema> &lista_filmes) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_filmes.size(); ++i)
        {
            cout << "Tipo:" << lista_filmes[i].tipo << endl;
            cout << "Filme:" << lista_filmes[i].filme << endl;
            cout << "Data:" << lista_filmes[i].data << endl;
            cout << "Horario:" << lista_filmes[i].horario << endl;

            cout << "\n====================================================\n";
        }
    }
};

// Classe sistema
// Responsavel por receber todas as informacoes do usario e criar os objetos das classes publicacoes, clientes e assinaturas.

/**Aqui precisa ter uma classe Sistema de acordo com o slide (slide 21 da aula - Diagrama de classes).
   Ela nao possui atributos nem construtores, somente metodos. */

class Sistema : public Cliente, public Cinema
{

public:
    Cliente inscreverCliente()
    {
        string nome;
        int idade;
        int cpf;

        cout << "Informe os dados para cadastro no sistema \n";
        cout << "Seu nome: ";
        cin >> nome;
        cout << "Sua idade: ";
        cin >> idade;
        cout << "Seu cpf: ";
        cin >> cpf;

        Cliente *c1 = new Cliente(nome, idade, cpf);

        cout << "\nOk! Seus dados foram armazenados. \n\n";
        return *c1;
    }

    Cinema inscreverFilme()
    {
        string tipo;
        string filme;
        string data;
        string horario;

        cout << "Informe os dados do filme deseja\n";
        cout << "Legendado, legendado 3D, dublado, dublado 3D: ";
        cin >> tipo;
        cout << "Informe o nome do filme: ";
        cin >> filme;
        cout << "Informe a data desejada: ";
        cin >> data;
        cout << "Informe o horario: ";
        cin >> horario;

        Cinema *a1 = new Cinema(tipo, filme, data, horario);

        cout << "\nOk! Seus dados foram armazenados. \n\n";
        return *a1;
    }
};

// Programa principal para o usuario interagir
// Chama as devidas funcoes para setar os valores informados pelo usario.

int main(int argc, char **argv)
{
    int escolha = 0;
    Sistema *s1 = new Sistema();
    Cliente *c1 = new Cliente();
    Evento *e1 = new Evento();
    Cinema *a1 = new Cinema();

    vector<Cliente> client;
    vector<Cinema> cine;

    while (1)
    {
        cout << "\n====================================================\n";
        cout << "====================================================\n";
        cout << "Informe o que voce deseja. \n\n1 - Cadastrar seus dados\n2 - Escolha o filme \n\n\nMenu de acesso ao banco de dados:\n\n3 - Informacoes de clientes cadastrado\n4 - Informacoes de filmes\n\n\n5 - Sair do Programa\n\n";
        cout << "Escolha: ";
        cin >> escolha;

        if (escolha == 1)
        {
            *c1 = s1->inscreverCliente(); // Chama a funcao na classe sistema para instanciar os objetos
            client.push_back(*c1);        // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
        }
        else if (escolha == 2)
        {
            *a1 = s1->inscreverFilme(); // Chama a funcao na classe sistema para instanciar os objetos
            cine.push_back(*a1);        // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
        }
        else if (escolha == 3)
        {
            c1->imprime_cliente(client); // Imprime a lista que contem todos os Usuarios cadastrados
        }
        else if (escolha == 4)
        {
            a1->imprime_filmes(cine); // Imprime a lista que contem todos as Assinaturas cadastrados
        }
        else if (escolha == 5)
        {
            cout << "Saindo do programa. Obrigado por utilizar o sistema. ";
            break;
        }
        else
        {
            cout << "Escolha invalida. Tente novamente. \n\n";
        }
    }
    return 0;
}
