#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "zsakmany.h"
#include "ragadozo.h"

class Beolvasas{
public:
    int zsakmany, ragadozo;
    std::string nev;
    std::string fajta;
    int hany;
};

enum Status{ abnorm, norm };


bool read(std::ifstream &in, Beolvasas &beolvasas, Status &st, int ind)
{
    std::string line;
    if(getline(in,line))
    {
        st = norm;
        std::stringstream in(line);

        if(ind == 0){
            in >> beolvasas.zsakmany >> beolvasas.ragadozo;
            std::cout << beolvasas.zsakmany << " " << beolvasas.ragadozo << std::endl;
        }else{
            in >> beolvasas.nev >> beolvasas.fajta >> beolvasas.hany;
            std::cout << beolvasas.nev << " "<< beolvasas.fajta << " " << beolvasas.hany << std::endl;
        }

    }
    else st = abnorm;

    return st == norm;
}

void destroy_all(std::vector<Zsakmany*> zsakmany, std::vector<Ragadozo*> ragadozo){
    for(unsigned int i = 0; i <  zsakmany.size();i++){delete zsakmany[i];}
    for(unsigned int i = 0; i <  ragadozo.size();i++){delete ragadozo[i];}
}

int run(std::string fajlnev){
    srand (time(NULL));
    Beolvasas beolvasas;
    Status st = norm;
    std::ifstream x(fajlnev);
    if(x.fail()){ std::cout << "Rossz fajl nev!" ; return 1;}
    std::string line;
    int ind = 0;
    std::vector<Zsakmany*> zsakmany;
    std::vector<Ragadozo*> ragadozo;
    while(st == norm) {
        read(x,beolvasas,st,ind);
        ind++;
        if(beolvasas.fajta == "l"){
            Lemming* beolvasott = new Lemming(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "n"){
            Nyul* beolvasott = new Nyul(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "u"){
            Urge* beolvasott = new Urge(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "h"){
            Bagoly* beolvasott = new Bagoly(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }

        if(beolvasas.fajta == "s"){
            Roka* beolvasott = new Roka(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }

        if(beolvasas.fajta == "f"){
            Farkas* beolvasott = new Farkas(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }
    }

    std::cout << std::endl;
    if(zsakmany.size() == 0 && ragadozo.size() == 0){
        std::cout << "Nincsen zsakmany allat, se ragadozo!" << std::endl; return 1;
    }
    else if(zsakmany.size() == 0){
        std::cout << "Nincsen zsakmany allat!" << std::endl; return 1;
    }
    else if(ragadozo.size() == 0){
        std::cout << "Nincsen ragadozo allat!" << std::endl; return 1;
    }

    bool mind_nagyobb_4 = true;

    bool dupla = true;
    int random;
    int index = 1;
    int kisebb = 0;
    int osszesitett = 0;
    int kezdo = 0;
    for(int i = 0; i < beolvasas.ragadozo;i++){kezdo += ragadozo.at(i)->getKezdo();}
    while(mind_nagyobb_4 == true && dupla == true){
        for(int i = 0; i < beolvasas.ragadozo;i++){
            random = rand() % beolvasas.zsakmany + 1;
            ragadozo.at(i)->Tamad(zsakmany.at(random-1)->Vadasznak(ragadozo.at(i)->szama));
        }
        if(index % 2 == 0){
            for(int i = 0; i < beolvasas.zsakmany;i++){
                zsakmany.at(i)->Masodik_kor();
            }
        }

        if(index % 8 == 0){
            for(int i = 0; i < beolvasas.ragadozo;i++){
                ragadozo.at(i)->Szaporodik();
            }
        }
        for(int i = 0; i < beolvasas.zsakmany;i++){
                std::cout << zsakmany.at(i)->neve << " " << zsakmany.at(i)->faja << " " << zsakmany.at(i)->szama << std::endl;
                zsakmany.at(i)->Csokken();
        }
        for(int i = 0; i < beolvasas.ragadozo;i++){
                std::cout << ragadozo.at(i)->neve << " " << ragadozo.at(i)->faja << " " << ragadozo.at(i)->szama << std::endl;
        }
        for(int i = 0; i < beolvasas.ragadozo;i++){
            if(ragadozo.at(i)->szama < 4){
                kisebb++;
            }
            osszesitett += ragadozo.at(i)->szama;
        }
        if(osszesitett >= 2*kezdo){
            dupla = false;

        }

        if(kisebb == beolvasas.ragadozo){
            mind_nagyobb_4 = false;
        }
        index++;
        kisebb = 0;
        osszesitett = 0;

        std::cout << std::endl << std::endl << std::endl;
    }
    destroy_all(zsakmany, ragadozo);

}
//Ezzel lehet a manualis es a unit teszt mod kozott valtogatni
//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main(){
    std::string fajlnev;
    std::cout << "Kerem adja meg a fajl nevet!"  << std::endl;
    std::cin >> fajlnev;
    run(fajlnev);


    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("1") {
    run("test1.txt");
}
TEST_CASE("2"){
    run("test2.txt");
}
TEST_CASE("3") {
    run("test3.txt");
}
TEST_CASE("4") {
    run("test4.txt");
}
TEST_CASE("5") {
    run("test5.txt");
}
TEST_CASE("6") {
    Beolvasas beolvasas;
    Status st = norm;
    std::ifstream x("test6.txt");
    std::string line;
    int ind = 0;
    std::vector<Zsakmany*> zsakmany;
    std::vector<Ragadozo*> ragadozo;
    while(st == norm) {
        read(x,beolvasas,st,ind);
        ind++;
        if(beolvasas.fajta == "l"){
            Lemming* beolvasott = new Lemming(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "n"){
            Nyul* beolvasott = new Nyul(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "u"){
            Urge* beolvasott = new Urge(beolvasas.hany, beolvasas.nev);
            zsakmany.push_back(beolvasott);
        }

        if(beolvasas.fajta == "h"){
            Bagoly* beolvasott = new Bagoly(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }

        if(beolvasas.fajta == "s"){
            Roka* beolvasott = new Roka(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }

        if(beolvasas.fajta == "f"){
            Farkas* beolvasott = new Farkas(beolvasas.hany, beolvasas.nev);
            ragadozo.push_back(beolvasott);
        }
    }
    CHECK(zsakmany.at(0)->szama == 86);
    CHECK(zsakmany.at(0)->faja == "l");
    CHECK(zsakmany.at(0)->neve == "kicsik");
    CHECK(ragadozo.at(0)->szama == 8);
    CHECK(ragadozo.at(0)->faja == "s");
    CHECK(ragadozo.at(0)->neve == "picik");
    CHECK(zsakmany.at(1)->szama == 26);
    CHECK(zsakmany.at(1)->faja == "n");
    CHECK(zsakmany.at(1)->neve == "szaporak");
    CHECK(zsakmany.at(2)->szama == 12);
    CHECK(zsakmany.at(2)->faja == "u");
    CHECK(zsakmany.at(2)->neve == "szorgosak");
    CHECK(ragadozo.at(1)->szama == 12);
    CHECK(ragadozo.at(1)->faja == "f");
    CHECK(ragadozo.at(1)->neve == "ehesek");
    CHECK(ragadozo.at(2)->szama == 6);
    CHECK(ragadozo.at(2)->faja == "h");
    CHECK(ragadozo.at(2)->neve == "tollasak");
    destroy_all(zsakmany, ragadozo);

}
//A tovabbi folyamatokat nem lehet tesztelni a randomizaltsag miatt.

#endif // NORMAL_MODE
