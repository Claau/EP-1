#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <iostream>
#include "Modalidade.h"
#include "Tabela.h"

using namespace std;

class Competicao
{
    private:
    string nome;
    Equipe** equipes;
    int quantidade; //quant de equiṕes
    int maximoDeModalidades;
    Modalidade** modalidades;


    public:
    Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
        ~Competicao();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    bool adicionar(Modalidade* m);
    Modalidade** getModalidades();
    int getQuantidadeDeModalidades();
    Tabela* getTabela();
    void imprimir();
};

#endif // COMPETICAO_H
