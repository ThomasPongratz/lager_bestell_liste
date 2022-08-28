#ifndef BOHRUNG_H
#define BOHRUNG_H

#include "komponente.h"

class Bohrung : public Komponente {
    public:
    Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0)
        : Komponente{x_, y_}, diameter{diam} {}
    ~Bohrung();
    double getDiameter() const { return diameter; }
    void output(std::ostream &os) const override {
        os << "Bohrung: ";
        Komponente::output(os);
        os << ", Durchmesser: " << getDiameter();
    }
    
    private:
    double diameter;
};

#endif