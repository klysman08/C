#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

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

    void imprime_cliente(const vector<Cliente> &lista) // FunÃ§Ã£o que imprime os atributos dos objetos instanciados via <vector>
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
    
    void set_nome_ev(string name_ev)
    {
        this->nome_ev = name_ev;
    }
    
};


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
};



class BilheteCinema : public Cinema
{
	public:
    int valor_cine = 20;
    int codigo_cine = 45245;


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
            //cout << "Valor:" << lista_filmes[i].valor_cine << endl;
            //cout << "Codigo:" << lista_filmes[i].codigo_cine << endl;            

            cout << "\n====================================================\n";
        }
    }
};



class Show : public Evento
{

public:

    int setor;
    string atracao;
    string data;
    string horario;


    Show() // contrutor padrao
    {
        this->setor = 2;
        this->atracao = "Rock";
        this->data = "Nirvana";
        this->horario = "21h";
    }

    Show(int setor, string atracao, string data, string horario)
    {
        this->setor = setor;
        this->atracao = atracao;
        this->data = data;
        this->horario = horario;
    }

};



class BilheteShow : public Show
{
	public:
		
    int valor_sw = 20;
    int codigo_sw = 248742;

    

    void emite_bilhete_show(const vector<Show> &lista_show) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_show.size(); ++i)
        {
            cout << "Nome do Evento:" << lista_show[i].nome_ev << endl;
            cout << "Endereco:" << lista_show[i].endereco << endl;
            cout << "Setor:" << lista_show[i].setor << endl;
            cout << "Atracao:" << lista_show[i].atracao << endl;
            cout << "Data:" << lista_show[i].data << endl;
            cout << "Horario:" << lista_show[i].horario << endl;
            
            //cout << "Valor:" << lista_show[i].valor_sw << endl;
            //cout << "Codigo:" << lista_show[i].codigo_sw << endl;

            cout << "\n====================================================\n";
        }
    }
};




class Teatro : public Evento
{

public:

    string tipo;
    string nome;
    int sala;
    string data;
    string horario;


    Teatro() // contrutor padrao
    {
        this->tipo = "Musical";
        this->nome = "Bela e a Fera";
        this->sala = 1;
        this->data = "janeiro";
        this->horario = "21h";
    }

    Teatro(string tipo, string nome, int sala, string data, string horario)
    {
        this->tipo = tipo;
        this->nome = nome;
        this->sala = sala;
        this->data = data;
        this->horario = horario;
    }

};



class BilheteTeatro : public Teatro
{
    int valor_te;
    int codigo_te;

    public:

        void emite_bilhete_show(const vector<Teatro> &lista_teatro) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_teatro.size(); ++i)
        {
            cout << "Nome do Evento:" << lista_teatro[i].nome_ev << endl;
            cout << "Endereco:" << lista_teatro[i].endereco << endl;
            cout << "Tipo:" << lista_teatro[i].tipo << endl;
            cout << "Nome:" << lista_teatro[i].nome << endl;
            cout << "Sala:" << lista_teatro[i].sala << endl;
            cout << "Data:" << lista_teatro[i].data << endl;
            cout << "Horario:" << lista_teatro[i].horario << endl;
            
            //cout << "Valor:" << lista_show[i].valor_te << endl;
            //cout << "Codigo:" << lista_show[i].codigo_te << endl;

            cout << "\n====================================================\n";
        }
    }
};




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

        cout << "Informe os dados do Filme que deseja\n\n\n";
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

    Show inscreverShow()
    {
        int setor;
        string atracao;
        string data;
        string horario;


        cout << "Informe os dados do Show que deseja\n\n\n";
        cout << "Qual o setor?";
        cin >> setor;
        cout << "Informe a atracao: (rock, pop, kpop, ax�, sertanejo, country)";
        cin >> atracao;
        cout << "Informe a data: ";
        cin >> data;
        cout << "Informe o horario: ";
		cin >> horario;
        Show *b1 = new Show(setor, atracao, data, horario);

        cout << "\nOk! Seus dados foram armazenados. \n\n";
        return *b1;
    }
    
    
	Teatro inscreverTeatro()
    {
        string tipo;
        string nome;
        int sala;
        string data;
        string horario;


        cout << "Informe os dados do Teatro que deseja\n\n\n";
        cout << "Qual o tipo? (musical, opera, filarmonica) ";
        cin >> tipo;
        cout << "Informe o nome da peca desejada: ";
        cin >> nome;
        cout << "Informe a sala da peca: ";
        cin >> sala;
        cout << "Informe a data: ";
        cin >> data;
        cout << "Informe o horario: ";
        cin >> horario;

        Teatro *t1 = new Teatro(tipo, nome, sala, data, horario);

        cout << "\nOk! Seus dados foram armazenados. \n\n";
        return *t1;
    }


};



int main()
{    
	Sistema *s1 = new Sistema();
	Evento *e1 = new Evento();
    Cliente *c1 = new Cliente();
    Cinema *a1 = new Cinema();
    Show *b1 = new Show();
    Teatro *t1 = new Teatro();

    vector<Cliente> client;
    vector<Cinema> cine;
    vector<Show> show;
    vector<Teatro> teatro;
    
	int escolha;
	int escolhe_evento;
	int escolhe_pagamento;

    while (1)
    {
        cout << "Pressione o botao 1 se voce deseja iniciar o processo de compras.\n";
        cin >> escolha;

        if (escolha == 1)
        {
            cout << "\n====================================================\n";

            *c1 = s1->inscreverCliente();
            client.push_back(*c1);

            cout << "Informe agora qual o tipo de evento que voce deseja: ";
            cout << "\n1 - Cinema\n2 - Show\n3 - Teatro\n9 - Sair do processo de compras\n";
            cin >> escolhe_evento;
            //e1->set_nome_ev(string escolhe_evento);
            
            if (escolhe_evento == 1)
            {
            	e1->set_nome_ev("Cinema");
                *a1 = s1->inscreverFilme(); // Chama a funcao na classe sistema para instanciar os objetos
           		cine.push_back(*a1);        // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            if (escolhe_evento == 2)
            {
            	e1->set_nome_ev("Show");
                *b1 = s1->inscreverShow(); // Chama a funcao na classe sistema para instanciar os objetos
           		show.push_back(*b1);        // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            if (escolhe_evento == 3)
            {
                e1->set_nome_ev("Teatro");
                *t1 = s1->inscreverTeatro(); // Chama a funcao na classe sistema para instanciar os objetos
           		teatro.push_back(*t1);        // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            if (escolhe_evento == 4)
            {
                
            }
            
            cout << "\nDados salvos. Escolha o metodo de pagamento:\n1 - Dinheiro\n2 - Cartao de credito\n3 - Cartao de debito";
            cin >> escolhe_pagamento;
            
			if (escolhe_pagamento == 1)
            {
            	//paga_dinheiro();
			}
            
            if (escolhe_pagamento == 2)
            {
            	//paga_credito();
			}
			
			if (escolhe_pagamento == 3)
            {
            	//paga_debito();
			}
			
			cout << "\nPagamento realizado. Imprimindo bilhetes.";
			//imprime_pagamento();
		}
        
		else if (escolha == 9)
        {
            cout << "Comando para finalizar o programa iniciado. Finalizando...";
            return 0;
        }
        
		else
        {
			cout << "Escolha invalida. Tente novamente. \n";
        }       
    }
}
