#include "Equipe.h"

Equipe::Equipe(string nome) :
    nome (nome){
    //ctor
}

Equipe::~Equipe()
{
    //dtor
}

void Equipe::imprimir()
{
    cout <<"Equipe " << this->nome << endl;
}

string Equipe::getNome()
{
    return this->nome;
}
