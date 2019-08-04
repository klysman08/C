/**
Nome: Klysman Rezende Alves Vieira
Matricula: 2017108779
Trabalho final  **/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <ctime>   //para o sorteio e regar o código de validacao
#include <cstdlib> //para o sorteio e regar o código de validacao

using namespace std;

class Cliente
{
    string nome;
    int idade;
    long int cpf; /**De acordo com o slide precisa ter*/

public:
    Cliente()
    {
        this->nome = "Klysman";
        this->idade = 24;
        this->cpf = 123456789;
    }

    Cliente(string nome, int idade, long int cpf)
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

    void set_nome_ev(string nome_ev)
    {
        this->nome_ev = nome_ev;
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
    float valor_cine = 20;

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

    float getvalor()
    {
        return this->valor_cine;
    }

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
            cout << "Valor:" << this->valor_cine << endl
                 << ",00 R$";
            //cout << "Codigo:" << this->codigo_cine << endl;

            cout << "\n====================================================\n";
        }
    }
};

class BilheteCinema : public Cinema
{
public:
    int codigo_cine = (rand() % 10000000000) + 1; // Gera o codigo de validacao

    void emite_bilhete_filme(const vector<Cinema> &lista_filmes) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_filmes.size(); ++i)
        {
            cout << "Nome do Evento:................................" << lista_filmes[i].nome_ev << endl;
            cout << "Endereco:......................................" << lista_filmes[i].endereco << endl;
            cout << "Tipo:.........................................." << lista_filmes[i].tipo << endl;
            cout << "Filme:........................................." << lista_filmes[i].filme << endl;
            cout << "Data:.........................................." << lista_filmes[i].data << endl;
            cout << "Horario:......................................." << lista_filmes[i].horario << endl;
            cout << "Valor:........................................." << this->valor_cine << ",00 R$" << endl;
            cout << "Codigo de validacao:..........................." << this->codigo_cine << endl;

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
    float valor_sw = 20;

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
    float getvalor()
    {
        return this->valor_sw;
    }
};

class BilheteShow : public Show
{
public:
    int codigo_sw = (rand() % 100000000000) + 1; // Gera o codigo de validacao

    void emite_bilhete_show(const vector<Show> &lista_show) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_show.size(); ++i)
        {
            cout << "Nome do Evento:........................................." << lista_show[i].nome_ev << endl;
            cout << "Endereco:..............................................." << lista_show[i].endereco << endl;
            cout << "Setor:.................................................." << lista_show[i].setor << endl;
            cout << "Atracao:................................................" << lista_show[i].atracao << endl;
            cout << "Data:..................................................." << lista_show[i].data << endl;
            cout << "Horario:................................................" << lista_show[i].horario << endl;
            cout << "Valor:.................................................." << this->valor_sw << ",00 R$" << endl;
            cout << "Codigo de validacao:...................................." << this->codigo_sw << endl;

            cout << "\n====================================================\n";
        }
    }
};

class Teatro : public Evento
{

public:
    float valor_te = 15;
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
    float getvalor()
    {
        return this->valor_te;
    }
};

class BilheteTeatro : public Teatro
{
    int codigo_te = (rand() % 10000000000) + 1; // Gera o codigo de validacao

public:
    void emite_bilhete_teatro(const vector<Teatro> &lista_teatro) // Funcao que imprime os atributos dos objetos instanciados via <vector>
    {
        for (int i = 0; i < lista_teatro.size(); ++i)
        {

            cout << "Nome do Evento:..........................................." << lista_teatro[i].nome_ev << endl;
            cout << "Endereco:................................................." << lista_teatro[i].endereco << endl;
            cout << "Tipo:....................................................." << lista_teatro[i].tipo << endl;
            cout << "Nome:....................................................." << lista_teatro[i].nome << endl;
            cout << "Sala:....................................................." << lista_teatro[i].sala << endl;
            cout << "Data:....................................................." << lista_teatro[i].data << endl;
            cout << "Horario:.................................................." << lista_teatro[i].horario << endl;
            cout << "Valor:...................................................." << this->valor_te << ",00 R$" << endl;
            cout << "Codigo de validacao:......................................" << this->codigo_te << endl;

            cout << "\n====================================================\n";
        }
    }
};

class Sistema : public Cliente
{
public:
    Cliente inscreverCliente()
    {
        string nome;
        int idade;
        int cpf;

        cout << "Informe os dados para cadastro no sistema. (somente o primeiro nome) \n";
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
        int sala;
        string filme;
        string data;
        string horario;

        cout << "Informe os dados do Filme que deseja\n\n";
        cout << "Legendado, Legendado 3D, Dublado, Dublado 3D: ";
        cout << "\n1 - Legendado\n2 - Legendado 3D\n3 - Dublado\n4 - Dublado 3D\n";
        cin >> tipo;
        cout << "Informe a sala (1,2 ou 3): ";
        cin >> sala;
        cout << "Informe o nome do filme (somente o primeiro nome): ";
        cin >> filme;
        cout << "Informe a data desejada (exemplo 20/07/2019): ";
        cin >> data;
        cout << "Informe o horario (exemplo 20h): ";
        cin >> horario;

        if (tipo == "1")
        {
            tipo = "Legendado";
        }
        if (tipo == "2")
        {
            tipo = "Legendado 3D";
        }
        if (tipo == "3")
        {
            tipo = "Dublado";
        }
        if (tipo == "4")
        {
            tipo = "Dublado 3D";
        }

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

        cout << "Informe os dados do Show que deseja\n\n";
        cout << "Qual o setor? (1,2 ou 3): ";
        cin >> setor;
        cout << "Informe a atracao (rock, pop, kpop, axe, sertanejo, country): ";
        cin >> atracao;
        cout << "Informe a data (exemplo 20/07/2019): ";
        cin >> data;
        cout << "Informe o horario (exemplo 20h): ";
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

        cout << "Informe os dados do Teatro que deseja\n\n";
        cout << "Qual o tipo de obra voce gostaria?";
        cout << "\n1 - Musical\n2 - Opera\n3 - Filarminica\n";
        cin >> tipo;
        cout << "Informe o nome da peca desejada:";
        cin >> nome;
        cout << "Informe o numero da sala (1,2 ou 3): ";
        cin >> sala;
        cout << "Informe a data (exemplo 20/07/2019): ";
        cin >> data;
        cout << "Informe o horario (exemplo 20h): ";
        cin >> horario;

        if (tipo == "1")
        {
            tipo = "Musical";
        }
        if (tipo == "2")
        {
            tipo = "Opera";
        }
        if (tipo == "3")
        {
            tipo = "Filarmonica";
        }

        Teatro *t1 = new Teatro(tipo, nome, sala, data, horario);

        cout << "\nOk! Seus dados foram armazenados. \n\n";
        return *t1;
    }
};

void emissao_bilhete()
{
    int escolha_emissao; //Escolhe emitir ou não o bilhete ao final do processo. 1-Emite;2-Não emite.
    cout << "Deseja emitir o bilhete?\n1-Sim\n2-Nao\n";
    cin >> escolha_emissao;
    if (escolha_emissao == 1)
    {
        cout << "Bilhete emitido com sucesso. Finalizando processo...\nProcesso finalizado\n\n\n";
        cout << "=============================================\n";
        cout << "=============================================\n";
        cout << "=============================================\n";
    }
    else
    {
        cout << "Processo finalizado sem a emissao do bilhete.\n\n\n";
        cout << "=============================================\n";
        cout << "=============================================\n";
        cout << "=============================================\n";
    }
}

int main()
{
    srand(time(0)); // funcao necessaria para gerar valores aleatorios - Codigo de validaçcao
    // Classe sistema responsável por gerênciar, atravez de metodos, as outras classes do sistima.
    Sistema *s1 = new Sistema();

    // Classes para instanciar os objetos do tipo Cliente e super class Evento.
    Evento *e1 = new Evento();
    Cliente *c1 = new Cliente();

    Cinema *a1 = new Cinema();
    BilheteCinema *aa1 = new BilheteCinema();
    Show *b1 = new Show();
    BilheteShow *bb1 = new BilheteShow();
    Teatro *t1 = new Teatro();
    BilheteTeatro *tt1 = new BilheteTeatro();

    // Listas para armazenar de maneira sequencial as informações do usario no processo de compra do ingresso.

    vector<Cliente> client;
    vector<Cinema> cine;
    vector<Show> show;
    vector<Teatro> teatro;

    // Variaveis responsasveis para genrenciar a interface do usario.
    int escolha;               //Usada para inicializar ou finalizar a máquina:1-Inicializa;9-Finaliza.
    int escolhe_evento;        //Escolhe o evento ao qual o bilhete corresponde:1-Cinema;2-Show;3-Teatro.
    int escolhe_pagamento;     //Escolhe o metodo de pagamento: 1-Dinheiro;2-Crédito;3-Débito;4-Bilhete de cortesia.
    float valor_cine;          //Usada para comparação entre o valor pago e o valor do bilhete para confirmar o pagamento e gerar o troco.
    float valor_show;          //Usada para comparação entre o valor pago e o valor do bilhete para confirmar o pagamento e gerar o troco.
    float valor_teatro;        //Usada para comparação entre o valor pago e o valor do bilhete para confirmar o pagamento e gerar o troco.
    long int num_cartao;       //Usada para os cartões de crédito e débito.
    string bandeira;           //Usada para os cartões de crédito e débito.
    long int confirma_cpf;     //Usada para o bilhete de cortesia.
    long int bilhete_cortesia; //Usada para armazenar o numero do bilhete de cortesia

    while (1) //Programa roda indefinidamente, até que o valor de escolha seja alterado para 9.
    {
        cout << "Bem vindo ao sistema para compra de ingressos.\n\nTemos a venda ingressos para Cinema, Shows e Teatro.\nPressione o botao 1 se voce deseja iniciar o processo de compras.\n";
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
                *a1 = s1->inscreverFilme(); // Chama a funcao na classe sistema para instanciar os objetos
                a1->nome_ev = ("Cinema");
                cine.push_back(*a1); // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            if (escolhe_evento == 2)
            {
                *b1 = s1->inscreverShow(); // Chama a funcao na classe sistema para instanciar os objetos
                b1->nome_ev = ("Show");
                show.push_back(*b1); // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            if (escolhe_evento == 3)
            {
                *t1 = s1->inscreverTeatro(); // Chama a funcao na classe sistema para instanciar os objetos
                t1->nome_ev = ("Teatro");
                teatro.push_back(*t1); // Armazena o objeto criado na linha de cima em uma lista do tipo vector.
            }

            // Sessão do programa para o pagamento;

            /* Se o pagamento for em dinheiro ele deve informar o valor dado em pagamento e a máquina calcula o troco, se houver.

             */

            cout << "\nDados salvos. Escolha o metodo de pagamento:\n1 - Dinheiro\n2 - Cartao de credito\n3 - Cartao de debito\n4 - Bilhete de cortesia\n";
            cin >> escolhe_pagamento;

            if (escolhe_pagamento == 1)
            {
                if (escolhe_evento == 1)
                {
                    cout << "O valor para o cinema eh: " << a1->getvalor() << ",00 R$";
                    cout << "\nDigite o valor a ser pago: ";
                    cin >> valor_cine;

                    while (valor_cine < a1->getvalor())
                    {
                        cout << "Valor insuficiente. Insira novamente: ";
                        cin >> valor_cine;
                    }

                    if (valor_cine >= a1->getvalor())
                    {
                        cout << "Pagamento realizado com sucesso!";
                        cout << "\nSeu troco eh: " << valor_cine - a1->getvalor();
                    }

                    cout << "\n\n\nConfirme suas informacoes antes de emitir o bilhete.\n\n";
                    aa1->emite_bilhete_filme(cine);
                    emissao_bilhete();
                }

                if (escolhe_evento == 2)
                {
                    cout << "O valor para o show eh: " << b1->getvalor() << ",00 R$";
                    cout << "\nDigite o valor a ser pago: ";
                    cin >> valor_show;

                    while (valor_show < b1->getvalor())
                    {
                        cout << "Valor insuficiente. Insira novamente: ";
                        cin >> valor_show;
                    }

                    if (valor_show >= b1->getvalor())
                    {
                        cout << "Pagamento realizado com sucesso!";
                        cout << "\nSeu troco eh: " << valor_show - b1->getvalor();
                    }

                    cout << "\n\n\nConfirme suas informacoes antes de emitir o bilhete.\n\n";
                    bb1->emite_bilhete_show(show);
                    emissao_bilhete();
                }

                if (escolhe_evento == 3)
                {
                    cout << "O valor para o cinema eh: " << t1->getvalor() << ",00 R$";
                    cout << "\nDigite o valor a ser pago: ";
                    cin >> valor_teatro;

                    while (valor_teatro < t1->getvalor())
                    {
                        cout << "Valor insuficiente. Insira novamente: ";
                        cin >> valor_teatro;
                    }

                    if (valor_teatro >= t1->getvalor())
                    {
                        cout << "Pagamento realizado com sucesso!";
                        cout << "\nSeu troco eh: " << valor_teatro - t1->getvalor();
                    }

                    cout << "\n\n\nConfirme suas informacoes antes de emitir o bilhete.\n\n";
                    tt1->emite_bilhete_teatro(teatro);
                    emissao_bilhete();
                }
            }

            /* // Funcao par alterar dados do usuario

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

            */

            /* Se for cartão de crédito, o usuário deve fornecer o número do cartão e a bandeira Visa, Mastercard, etc.
             * A máquina deve verificar a validade dos dados e informar se o pagamento foi aceito, ou não.
             * O procedimento de verificação deverá usar um sorteio para recusar alguns pagamentos, simulando uma situação real.*/
            else if (escolhe_pagamento == 2)
            {
                if (escolhe_evento == 1)
                    cout << "O valor do bilhete para o cinema eh: " << a1->getvalor() << ",00 R$";
                else if (escolhe_evento == 2)
                    cout << "O valor do bilhete para o show eh: " << b1->getvalor() << ",00 R$";
                else if (escolhe_evento == 3)
                    cout << "O valor do bilhete para o teatro eh: " << t1->getvalor() << ",00 R$";

                cout << "\nInsira o numero do cartao: ";
                cin >> num_cartao;
                cout << "Insira a bandeira (Visa, Mastercard, Elo, Cielo, etc...: ";
                cin >> bandeira;
                //if (sizeof(num_cartao) == 8 && num_cartao%1000000 == 33)
                if ((rand() % 15) + 1 > 2) // Processo para gerar um numero aleatorio entre 1 e 15. Caso seja maior que 2
                                           // (cerca de 90% das vezes), o processo é concluido
                {
                    cout << "\n\n\nCartao validado com sucesso. Pagamento realizado. \nConfirme suas informacoes antes de emitir o bilhete.\n\n";

                    if (escolhe_evento == 1)
                    {
                        aa1->emite_bilhete_filme(cine);
                        emissao_bilhete();
                    }
                    else if (escolhe_evento == 2)
                    {
                        bb1->emite_bilhete_show(show);
                        emissao_bilhete();
                    }
                    else if (escolhe_evento == 3)
                    {
                        tt1->emite_bilhete_teatro(teatro);
                        emissao_bilhete();
                    }
                }
                else
                {
                    cout << "Cartao invalido. Finalizando o processo...\nProcesso finalizado\n\n";
                }
                //paga_credito();
            }

            else if (escolhe_pagamento == 3)
            {
                if (escolhe_evento == 1)
                    cout << "O valor do bilhete para o cinema eh: " << a1->getvalor() << ",00 R$";
                else if (escolhe_evento == 2)
                    cout << "O valor do bilhete para o show eh: " << b1->getvalor() << ",00 R$";
                else if (escolhe_evento == 3)
                    cout << "O valor do bilhete para o teatro eh: " << t1->getvalor() << ",00 R$";

                cout << "\nInsira o numero do cartao: ";
                cin >> num_cartao;
                cout << "Insira a bandeira (Visa, Mastercard, Elo, Cielo, etc...: ";
                cin >> bandeira;

                if ((rand() % 5) + 1 > 1) // Processo para gerar um numero aleatorio entre 1 e 15. Caso seja maior que 2
                                          // (cerca de 90% das vezes), o processo é concluido
                {
                    cout << "Saldo suficiente na conta. Pagamento realizado. \nConfirme suas informacoes antes de emitir o bilhete.\n\n";

                    if (escolhe_evento == 1)
                    {
                        aa1->emite_bilhete_filme(cine);
                        emissao_bilhete();
                    }
                    else if (escolhe_evento == 2)
                    {
                        bb1->emite_bilhete_show(show);
                        emissao_bilhete();
                    }
                    else if (escolhe_evento == 3)
                    {
                        tt1->emite_bilhete_teatro(teatro);
                        emissao_bilhete();
                    }
                }

                else
                {
                    cout << "Saldo insuficiente na conta. Finalizando o processo...\nProcesso finalizado\n\n";
                }
                //paga_debito();
            }

            /* Pode ser ainda que o usuário tenha direito a bilhetes de cortesia. Neste caso, após optar por esta modalidade,
             * ele deverá fornecer o seu CPF, e um procedimento de verificação poderá atender até dois pedidos a cada quinze solicitações. */
            else if (escolhe_pagamento == 4) //Bilhete de cortesia
            {
                cout << "Seu CPF eh: " << c1->get_cpf() << "?\n1 - Sim\n2 - Nao\n";
                cin >> confirma_cpf;
                if (confirma_cpf == 1)
                {
                    cout << "Insira o numero do bilhete de cortesia: \n";
                    cin >> bilhete_cortesia;

                    if ((rand() % 15) + 1 > 2)
                    {
                        cout << "Bilhete de cortesia valido. \nConfirme suas informacoes antes de emitir o bilhete.\n\n";
                        if (escolhe_evento == 1)
                        {
                            aa1->emite_bilhete_filme(cine);
                            emissao_bilhete();
                        }
                        else if (escolhe_evento == 2)
                        {
                            bb1->emite_bilhete_show(show);
                            emissao_bilhete();
                        }
                        else if (escolhe_evento == 3)
                        {
                            tt1->emite_bilhete_teatro(teatro);
                            emissao_bilhete();
                        }
                    }
                    else
                    {
                        cout << "Bilhete de cortesia invalido. Finalizando o processo...\nProcesso finalizado\n\n";
                    }
                }
                else
                {
                    cout << "CPF inserido invalido. Finalizando o processo...\nProcesso finalizado\n\n";
                }
            }
            /* Sessão para o usuario validar as informações que irão constar no bilhete e silicitar a impressão do mesmo. */

            //imprime_pagamento();
        }

        else if (escolha == 9)
        {
            cout << "Comando para finalizar o programa iniciado. Finalizando...\nObrigado!";
            return 0;
        }

        else
        {
            cout << "Escolha invalida. Tente novamente. \n";
        }
    }
}
