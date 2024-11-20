#include "ragadozo.h"

void Ragadozo::Tamad(bool nincs_eleg){
    if(nincs_eleg){
        this->szama = this->szama/4;
    }
}

void Bagoly::Szaporodik(){
    this->szama = this->szama+(this->szama/4);
}


void Roka::Szaporodik(){
    this->szama = this->szama+3*(this->szama/4);
}


void Farkas::Szaporodik(){
    this->szama = this->szama+2*(this->szama/4);
}
