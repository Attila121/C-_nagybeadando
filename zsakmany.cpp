#include "zsakmany.h"

bool Lemming::Vadasznak(int vadszam){
    if(this->szama - (vadszam * 4) > 0){
        this->szama = this->szama-(vadszam * 4);
    }
    return (this->szama-(vadszam * 4) <= 0);
}
void Lemming::Csokken(){
    if(this->szama >= 200){
        this->szama = 30;
    }
}

void Lemming::Masodik_kor(){
    this->szama = this->szama + this->szama;
}

bool Nyul::Vadasznak(int vadszam){
    if(this->szama-(vadszam * 2) > 0){
        this->szama = this->szama-(vadszam * 2);
    }
    return (this->szama-(vadszam * 2) <= 0);
}
void Nyul::Csokken(){
    if(this->szama >= 100){
        this->szama = 20;
    }
}

void Nyul::Masodik_kor(){
    this->szama = int(this->szama + 0.5*this->szama);
}



bool Urge::Vadasznak(int vadszam){
    if(this->szama-(vadszam * 2) > 0){
        this->szama = this->szama-(vadszam * 2);
    }
    return (this->szama-(vadszam * 2) <= 0);
}
void Urge::Csokken(){
    if(this->szama >= 200){
        this->szama = 40;
    }
}

void Urge::Masodik_kor(){
    this->szama = this->szama + this->szama;
}


