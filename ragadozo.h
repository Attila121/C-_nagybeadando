#include <string>
class Ragadozo{
public:
    int szama;
    std::string faja;
    std::string neve;
    Ragadozo(int sz, std::string f, std::string n) : szama(sz), faja(f), neve(n), kezdo(sz){}
    virtual void Szaporodik(){}
    void Tamad(bool nincs_eleg);
    int getKezdo(){return this->kezdo;}
    virtual ~Ragadozo(){}
protected:
    int kezdo;
};

class Bagoly : public Ragadozo{
public:
    Bagoly(int sz, std::string n) : Ragadozo(sz,"h",n){}


    void Szaporodik()override;

};

class Roka : public Ragadozo{
public:
    Roka(int sz, std::string n) : Ragadozo(sz,"s",n){}

    void Szaporodik()override;


};

class Farkas : public Ragadozo{
public:

    Farkas(int sz, std::string n) : Ragadozo(sz,"f",n){}


    void Szaporodik()override;


};
