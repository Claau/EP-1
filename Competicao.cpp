#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades):
    nome(nome), equipes(equipes), quantidade(quantidade), maximoDeModalidades(maximoDeModalidades){
        modalidades = new Modalidade*[maximoDeModalidades];

        //NULL - forma de controlar se o vetor esta vazio ou cheio
        for (int i = 0; i < maximoDeModalidades; i++)
            modalidades[i] = NULL;
}

Competicao::~Competicao(){
    for(int i = 0; i < maximoDeModalidades; i++)
        delete modalidades[i];
    delete[] modalidades;

}
string Competicao::getNome(){
    return this->nome;
}

Equipe** Competicao::getEquipes(){
    return this-> equipes;
}

int Competicao::getQuantidadeDeEquipes(){
    return this-> quantidade;
}

bool Competicao::adicionar(Modalidade* m){

    for (int i = 0; i < maximoDeModalidades; i++) {
            if(modalidades[i] == NULL) {
                modalidades[i] = m;
                return true;
            }
        }
    return false; //o vetor se encontra cheio
}

//modalidades[i]==NULL respresenta um espaço vazio
int Competicao::getQuantidadeDeModalidades(){
    int i = 0;
    for (i = 0; i < maximoDeModalidades && modalidades[i] != NULL; i++){}
    return i;
}

Modalidade** Competicao::getModalidades(){
   return this-> modalidades;
}

Tabela* Competicao::getTabela(){
Tabela  *tabela = new Tabela(equipes, quantidade);

    /*Atribuicao dos pontos a cada posicao de participante*/
    for(int j = 0; j < getQuantidadeDeModalidades() ; j++){
        if(modalidades[j]->getPosicao(equipes[0]) != -1){
            for(int i = 0; i < quantidade; i++){

               //1o LUGAR
                if(modalidades[j]->getPosicao(equipes[i]) == 1)
                    tabela->pontuar(equipes[i], 13);


                //2o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 2)
                    tabela->pontuar(equipes[i], 10);


                //3o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 3)
                    tabela->pontuar(equipes[i], 8);

                //4o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 4)
                    tabela->pontuar(equipes[i], 7);

                //5o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 5)
                    tabela->pontuar(equipes[i], 5);

                //6o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 6)
                    tabela->pontuar(equipes[i], 4);

                //7o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 7)
                    tabela->pontuar(equipes[i], 3);

                //8o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 8)
                    tabela->pontuar(equipes[i], 2);

                //9o LUGAR
                if(modalidades[j]->getPosicao ( equipes[i] ) == 9)
                    tabela->pontuar(equipes[i], 1);
                }
            }
    }
    return tabela;

}

void Competicao::imprimir(){
    cout<< nome<< endl;
    getTabela()->imprimir();
}



