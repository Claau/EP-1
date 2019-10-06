#include "Equipe.h"
#include "Competicao.h"
#include "Modalidade.h"
#include "Tabela.h"

#include <iostream>

using namespace std;

int main()
{
    string NomeCompeticao;

     /*criacao das equipes*/
    int QntEquipes;
        cout << "Informe o nome da competicao: ";
        cin >> NomeCompeticao;
        cout << endl << "Informe a quantidade de equipes: ";
        cin >> QntEquipes;
        cout << endl;
    Equipe **p = new Equipe*[QntEquipes];
    string Nomes;
    for(int i = 0; i < QntEquipes; i++)
    {
        cout << "Informe o nome da equipe " << i + 1 << ": ";
        cin >> Nomes;
        p[i] = new Equipe(Nomes);
    }


    int QntModalidades;
    cout << endl << "Informe a quantidade de modalidades: ";
    cin >> QntModalidades;
    string *ModalidadeNomes = new string[QntModalidades];
    Modalidade **m = new Modalidade*[QntModalidades];
    int ordem;
    Competicao *c = new Competicao(NomeCompeticao, p, QntEquipes, QntModalidades);

    for(int i = 0; i < QntModalidades; i++)
    {
        /* criacao do vetor que armazena a ordem das equipes em cada modalidade */
        Equipe **o = new Equipe*[QntEquipes];
        cout << "Informe o nome da modalidade " << i+1 << ": ";
        cin >> ModalidadeNomes[i];
        for(int j = 0; j < QntEquipes; j++)
        {
            cout << "Informe a equipe " << j+1 << "a colocada: ";
            cin >> ordem;
            o[j] = p[ordem - 1];
        }
        /* criacao de cada modalidade, e adicao das modalidades na competicao */
        m[i] = new Modalidade(ModalidadeNomes[i], p, QntEquipes);
        m[i]->setResultado(o);
        c->adicionar(m[i]);
    }
    c->imprimir();


    delete[] ModalidadeNomes;
    return 0;
}


