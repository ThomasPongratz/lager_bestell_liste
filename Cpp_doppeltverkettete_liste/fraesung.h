#ifndef FRAESUNG_H
#define FRAESUNG_H

#include "bohrung.h"
#include <math.h>

class Fraesung : public Bohrung {
    public:
        Fraesung(double x, double y, double diam, double l, double a = 0.0)
        : Bohrung{x, y, diam}, length{l}, angle{a} {}
        ~Fraesung();
        double getLength() const { return length; }
        double getAngle() const { return angle; }
        double getEndX() const { return getX() + cos(getAngle()) * getLength(); }
        double getEndY() const { return getY() + sin(getAngle()) * getLength(); }
        void output(std::ostream &os) const override {
            os << "Fraesung mit Start: ";
            Komponente::output(os);
            os << " und Endpunkt: (" << getEndX() << ", " << getEndY() 
            << "), Durchmesser: " << getDiameter();
        }

    private:
        double length;
        double angle;
};

#endif