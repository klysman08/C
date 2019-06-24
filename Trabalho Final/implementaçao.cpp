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

    string get_Nome()
    {
        return this->nome;
    }

    int get_idade()
    {
        return this->idade;
    }

    int get_cpf()
    {
        return this->cpf;
    }

    void set_Nome(string name)
    {
        this->nome = name;
    }

    void set_idade(int id)
    {
        this->idade = id;
    }

    void set_cpf(int registro)
    {
        this->cpf = registro;
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

public:  
    string nome_ev;
    string endereco;


    Evento()
    {
        this->nome_ev = "Evento generico";
        this->endereco = "Shopping BH";
    }

    void imprime_evento()
    {
        cout << this->nome_ev << endl;
        cout << this->endereco << endl;
    }
};

// Classe Cinema
// Tem como objetivo caracterizar o tipo de cinema para esse evento

class Cinema : public Evento
{

public:

    string tipo;
    string filme;
    int sala;
    string data;
    string horario;


    Cinema() // contrutor padrao
    {
        this->tipo = "3D";
        this->sala = 1;
        this->filme = "Vingadores";
        this->data = "janeiro";
        this->horario = "21h";
    }

    Cinema(string tipo, int sala, string filme, string data, string horario)
    {
        this->tipo = tipo;
        this->sala = sala;
        this->filme = filme;
        this->data = data;
        this->horario = horario;
    }

    void imprime_cinema(const vector<Cinema> &lista)
    {
    	for (int i = 0; i < lista.size(); ++i)
        {
            cout << "Tipo: " << lista[i].tipo << endl;
            cout << "Nome do filme: " << lista[i].filme << endl;
            cout << "Sala: " << lista[i].sala << endl;
            cout << "Data: " << lista[i].data << endl;
            cout << "Horario: " << lista[i].horario << endl;
            cout << "Nome do evento: " << lista[i].nome_ev << endl;

            cout << "\n====================================================\n";
            
        }
	}
};


class BilheteCinema : public Cinema
{
    int valor;
    int codigo;

    public:

    void emite_bilhete_filme(const vector<Cinema> &lista_filmes) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_filmes.size(); ++i)
        {
            cout << "Nome do Evento:" << lista_filmes[i].nome_ev << endl;
            cout << "Endereco:" << lista_filmes[i].endereco << endl;
            cout << "Tipo:" << lista_filmes[i].tipo << endl;
            cout << "Filme:" << lista_filmes[i].filme << endl;
            cout << "Data:" << lista_filmes[i].data << endl;
            cout << "Horario:" << lista_filmes[i].horario << endl;

            cout << "\n====================================================\n";
        }
    }
};

// Classe sistema
// Responsavel por receber todas as informacoes do usario e criar os objetos.


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
        cout << "Informe a sala: ";
        cin >> sala;
        cout << "Informe o nome do filme: ";
        cin >> filme;
        cout << "Informe a data desejada: ";
        cin >> data;
        cout << "Informe o horario: ";
        cin >> horario;

        Cinema *a1 = new Cinema(tipo, sala, filme, data, horario);

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
    BilheteCinema *b1 = new BilheteCinema();

    vector<Cliente> client;
    vector<Cinema> cine;

    while (1)
    {
        cout << "\n====================================================\n";
        cout << "====================================================\n";
        cout << "Informe o que voce deseja. \n\n1 - Cadastrar seus dados\n2 - Escolha o filme \n\n\nMenu de acesso ao banco de dados:\n\n3 - Informacoes de clientes cadastrado\n4 - Informacoes de filmes\n\n\n5 - Sair do Programa\n\n\n6 - Alterar cliente\n ";
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
            b1->emite_bilhete_filme(cine); // Imprime a lista que contem todos as Assinaturas cadastrados
        }
        else if (escolha == 5)
        {
            cout << "Saindo do programa. Obrigado por utilizar o sistema. ";
            break;
        }
         else if (escolha == 6)
        {
        	cout <<	"Escolha um cliente:\n";
        	int i=0;
            for(std::vector<Cliente>::iterator it = client.begin(); it != client.end(); ++it)
            {
                cout <<i+1<<": " << it->get_Nome() << "; \n";
                i++;
            }
        	int vectorindex;
            cin >> vectorindex;
            cout <<	"Altera nome para:\n";
            string novonome;
            cin >>novonome;
            client[vectorindex].set_Nome(novonome);
            cout <<"Nova Lista:\n";
            for(std::vector<Cliente>::iterator it = client.begin(); it != client.end(); ++it)
            {
                cout <<"Nome: " << it->get_Nome() << "; \n";
            }
            break;
        }
        else
        {
            cout << "Escolha invalida. Tente novamente. \n\n";
        }
    }
    return 0;
}
