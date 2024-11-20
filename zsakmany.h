#include <string>
class Zsakmany{
public:
    int szama;
    std::string faja;
    std::string neve;
    virtual void Csokken(){}
    virtual void Masodik_kor(){}
    virtual bool Vadasznak(int vadszam){return false;}
    Zsakmany(int sz, std::string f, std::string n) : szama(sz), faja(f), neve(n){}
    virtual ~Zsakmany(){};
};

class Lemming : public Zsakmany{
public:
    Lemming(int sz, std::string n): Zsakmany(sz,"l",n){}

    bool Vadasznak(int vadszam)override;


    void Csokken()override;
    void Masodik_kor()override;
};

class Nyul : public Zsakmany{

public:
    Nyul(int sz, std::string n): Zsakmany(sz,"n",n){}

    bool Vadasznak(int vadszam)override;

    void Masodik_kor()override;


    void Csokken()override;

};


class Urge : public Zsakmany{
public:
    Urge(int sz, std::string n): Zsakmany(sz,"u",n){}

    bool Vadasznak(int vadszam)override;

    void Masodik_kor()override;

    void Csokken()override;
};
