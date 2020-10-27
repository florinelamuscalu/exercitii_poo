#include <iostream>
#include <cmath>
#include <vector>


class numar_complex {
    double im, re;

    friend class vector;

public:
    explicit numar_complex(double im = 0, double re = 0) : im(im), re(re) {}

    friend std::ostream &operator<<(std::ostream &os, const numar_complex &complex) {
        os << "im: " << complex.im << " re: " << complex.re;
        return os;
    }
    numar_complex &operator+=(numar_complex & nr) { this->im += nr.im; this->re += nr.re; return *this;}
    numar_complex &operator*=(numar_complex & nr) {this->im *= nr.im; this->re *= nr.re; return *this;}
};

class vector {
    int n;
    numar_complex *z;
public:
    vector(int n, numar_complex c) : n(n), z(new numar_complex [n])  // pot sa citesc n la constructor? -> DA
    {
        int i;
        std::cout << "Apel constructor\n";
        for (i = 0; i < n; ++i) {
            z[i].im = c.im;
            z[i].re = c.re;
        }
    }

    ~vector() {
        std::cout << "Apel destructor\n";
        n = 0;
        delete[] z;
    }

    void citire() {
        int i;
        std::cout << '\n';
        std::cout << "Introduceti datele!\n";
        for (i = 0; i < n; ++i) {
            std::cout << "partea  reala si imaginara este egala cu:";
            std::cin >> z[i].re>>z[i].im;
            std::cout << '\n';
        }
    }

    // metoda publica de afisare (sub forma "a", "i*a", "-i*a", "a+i*b", "a-i*b"); --> nu inteleg la ce serfera
    void afisare() const {
        std::cout << "Afisare" << '\n';
        for (int i = 0; i < n; ++i)
            std::cout << z[i] << '\n';
    }

    std::vector<double> modul() {
        std::vector<double> v;
        v = std::vector<double>(n);
        int i;
        for (i = 0; i < n; ++i)
            v[i] = sqrt(pow(z[i].re, 2) + pow(z[i].im, 2));
        return v;
    }

    numar_complex suma() {
        int i;
        numar_complex s;
        for (i = 0; i < n; ++i) {
            s += z[i];
        }
        return s;
    }

    numar_complex produs() {
        int i;
        numar_complex s;
        s = numar_complex (1);
        for (i = 0; i < n; ++i) {
            s *= z[i];
        }
        return s;
    }
};

int main() {
    int n = 3;
    numar_complex c;
    vector nr(n, c);
    nr.citire();
    auto module = nr.modul();
    std::cout<<nr.suma()<<'\n';
    std::cout<<nr.produs()<<'\n';
    for (auto i : module )
        std::cout<<i<<" ";
    std::cout<<'\n';
    nr.afisare();
    vector v2(0,c);
    v2 = nr;

    return 0;
}
