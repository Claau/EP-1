#include <iostream>
#include <string>

#include "Modalidade.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade):
    nome(nome), participantes(participantes), quantidadeDeEquipes(quantidade){

        ordem = new Equipe*[quantidadeDeEquipes];

}

Modalidade::~Modalidade(){
   // delete[] ordem;  /*esvaziar o heap */
}

string Modalidade::getNome(){
    return nome;
}

Equipe** Modalidade::getEquipes(){
    return participantes;
}
int Modalidade::getQuantidadeDeEquipes(){
    return quantidadeDeEquipes;
}

/*armazena o vetor ordem (dos participantes)*/
void Modalidade::setResultado(Equipe** ordem){
    this->ordem = ordem;
    estaOrdenado = true;
}

int Modalidade::getPosicao (Equipe* participante){
 /*indicador de vetor cheio ou vazio (setResultado() definido ou nao)*/
    if(estaOrdenado == false) /*INDICA QUE AINDA NAO FOI DEFINIDO A ORDEM*/
        return -1;

    else{
        for(int i = 0; i < quantidadeDeEquipes ; i++)
            if(ordem[i] == participante) /*confere se existe o participante X no vetor*/
                return i+1;
    }
    return -1;
}

void Modalidade::imprimir(){
    cout << "Modalidade: " << this->nome <<endl;
    cout<< "Participantes:" << endl;
    /*ainda nao foram definidas as posicoes*/
    if (estaOrdenado == false){
        for(int i = 0; i < quantidadeDeEquipes; i++)
            cout<< '\t' << participantes[i]->getNome() <<endl;
    }

    else{
        /*ja foram definidas as posicoes*/
        for(int i = 0; i < quantidadeDeEquipes; i++)
              cout<< '\t' << getPosicao(participantes[i]) << "o " << participantes[i]->getNome() <<endl;}
}
