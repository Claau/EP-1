#include <iostream>
#include <string>

#include "Modalidade.h"
#include "Equipe.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade):
    nome(nome), participantes(participantes), quantidadeDeEquipes(quantidade){

        ordem = new Equipe*[quantidadeDeEquipes];
        for(int i=0; i<quantidadeDeEquipes; i++)
            ordem[i] = NULL;  /*indicador de vetor cheio ou vazio (setResultado() definido ou nao)*/
}

Modalidade::~Modalidade(){
    delete[] ordem;  /*esvaziar o heap*/
}

string Modalidade::getNome(){
    return this->nome;
}

Equipe** Modalidade::getEquipes(){
    return this-> participantes;
}
int Modalidade::getQuantidadeDeEquipes(){
    return this-> quantidadeDeEquipes;
}

/*armazena o vetor ordem (dos participantes)*/
void Modalidade::setResultado(Equipe** ordem){
    this->ordem = ordem;
}

int Modalidade::getPosicao (Equipe* participante){
    if( ordem[0] == NULL) return -1; /*INDICA QUE AINDA NAO FOI DEFINIDO A ORDEM*/
    else{
        for(int i = 0; i< quantidadeDeEquipes ; i++)
            if(ordem[i] == participante) /*confere se existe o participante X no vetor*/
                return i+1;
    }
    return -1;
}

void Modalidade::imprimir(){
    cout << "Modalidade: " << this->nome <<endl;
    cout<< "Participantes:" << endl;

    /*ainda nao foram definidas as posicoes*/
    if (this-> ordem[0] == NULL){
        for(int i = 0; i < quantidadeDeEquipes; i++)
            cout<< '\t' << participantes[i]->getNome() <<endl;
    }

    else{
        /*ja foram definidas as posicoes*/
        for(int i = 0; i<quantidadeDeEquipes; i++)
              cout<< '\t' << getPosicao(participantes[i]) << "o " << participantes[i]->getNome() <<endl;}
}
