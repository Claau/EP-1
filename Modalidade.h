
#include <iostream>
#include <string>
#include "Equipe.h"

#ifndef MODALIDADE_H
#define MODALIDADE_H

using namespace std;

class Modalidade{

    private:
        string nome;
        Equipe** ordem;  /*armazena a colocacao das equipes*/
        Equipe** participantes;
        int quantidadeDeEquipes;


    public:

        Modalidade(string nome, Equipe** participantes, int quantidade);
        ~Modalidade();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();
        void setResultado(Equipe** ordem);
        int getPosicao (Equipe* participante);
        void imprimir();

    };



#endif
