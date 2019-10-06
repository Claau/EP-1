#include "Tabela.h"


Tabela::Tabela(Equipe** participantes, int quantidade):
    participantes(participantes),quantidade(quantidade){
        pontuacao = new int[quantidade];

        /*Zera o vetor posicao*/
        for (int i = 0; i < quantidade; i++)
            pontuacao[i] = 0;
}

Tabela::~Tabela(){
    delete[] pontuacao;
}

void Tabela::pontuar(Equipe* participante, int pontos){
    for(int i = 0; i < quantidade; i++){
        if(participante ==  participantes[i] )
            pontuacao[i] = pontuacao[i] + pontos;
    }
}

int Tabela::getPontos(Equipe* participante){
    for(int i = 0; i < quantidade; i++)
       if(participante == participantes[i])
            return pontuacao[i];
}

int Tabela::getPosicao(Equipe* participante){
    int posicao = 1;
    for(int i = 0; i < quantidade; i++)/* adiciona posicoes conforme o vetor eh percorrido: caso haja um participante com pontuacao maior que a do analisado, incrementa-se posicao */
        if(pontuacao[i] > getPontos(participante))
            posicao++;

return posicao;
}

void Tabela::imprimir(){
     for(int i = 0; i < quantidade; i++)
        cout<< participantes[i]->getNome() << " - " << getPontos(participantes[i]) << " pontos (" <<  getPosicao(participantes[i]) << "o)"<<endl;
}
