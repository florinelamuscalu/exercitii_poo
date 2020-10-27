#include <iostream>
#include <vector>

// Am auzit de tema cu clasa masina lalaborator si am zis sa incerc si eu
// Deci sunt 2 clase: masina si categorie
// Retin numele masinii (nu stiu in realitatea asa ceva deci o sa fie din imaginatia mea), tipul de motor
// (puternic slab),tipul de dimensiune (mic, mare) nr de km (cred ca cai putere s-ar spune)
// O sa fac un constructor implicit, un constructor cu argumente si un constructor de copiere + o afisare
// O functie in care daca varsta == 16 -> tipul == mic
// Asta ne-a pus sa facem si la seminar si sa mai repet

class masina
{
    std::string nume, tip_mot, tip_dim;
    int km;
    friend  class categorie;
public:
    masina(); // constructir implicit
    masina(std::string nume, std::string tip_mot,std::string tip_dim, int km); // constructor cu argumente
    masina ( masina &ma); // constructor de copiere
    virtual ~masina();
};

class categorie
{
    int varsta{};
    std::vector<masina> masini;
public:
    categorie()= default;
    void citire();
    void afisare();
    void cat();
};

masina::masina() {
    nume = " ";
    tip_mot = " ";
    tip_dim =" ";
    km= 0;
}

masina::masina(std::string nume, std::string tip_mot,std::string tip_dim, int km) : nume(std::move(nume)), tip_mot(std::move(tip_mot)),tip_dim(std::move(tip_dim)), km(km) {}

masina::masina(masina &ma) {
    nume = ma.nume;
    tip_mot = ma.tip_mot;
    tip_dim=ma.tip_dim;
    km = ma.km;
}

masina::~masina() = default;

void categorie::citire() {
    int n,m;
    std::cout<<"introduceti nr de masini si nr de varste"<<'\n';
    std::cin>>n>>m;
    std::cout<<"introduceti vasrta";
    for(int i= 0; i < m; ++i)
        std::cin>>varsta;
    masina ms;
    for (int i = 0; i < n; ++i) {
        std::cin >> ms.nume >> ms.tip_mot>>ms.tip_dim>>ms.km;
        masini.push_back(ms);
    }
}

void categorie::afisare() {
    std::cout<<varsta<<'\n';
    for (auto &masina : masini) {
        std::cout << masina.nume << " " << masina.tip_mot << " "<<masina.tip_dim <<" "<< masina.km << '\n';
    }
}
void categorie::cat() {
    for (auto &masina : masini)
    {
        if(varsta == 16) {
            masina.tip_dim = "mic";
            masina.tip_mot = "slab";
        }
        else
        if(varsta == 18) {
            masina.tip_dim = "mare";
            masina.tip_mot = "puternic";
        }
    }
}
int main() {
    categorie cat;
    masina ms("Strumf", "Puternic", "Mare", 0);
    masina ms1("Jerry","Slab","Mic",5);
    //masina ms2(); constructorul imlicit nu are sen aici, dar l-am facut ca sa pot sa ma obisnuiesc :))
    masina ms3(ms);
    cat.citire();
    cat.cat();
    cat.afisare();

    return 0;
}
