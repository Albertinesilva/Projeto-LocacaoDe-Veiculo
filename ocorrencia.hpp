#ifndef OCORRENCIA_HPP
#define OCORRENCIA_HPP

#include "dataHora.hpp"
#include<iostream>
#include "verificacoesOcorrencia.hpp"

using namespace std;

typedef struct{
    string descricao;
    DataHora horario;
    string numeroApolice;
    bool ativa = false;



}Ocorrencia;

#endif
