#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <ostream>

class Komponente {
    public:
        Komponente(double xPos = 0.0, double yPos = 0.0) : x{xPos}, y{yPos} {}
        virtual ~Komponente();
        double getX() const { return x; }
        double getY() const { return y; }
        virtual void output(std::ostream& os) const {
            os << "(" << getX() << ", " << getY() << ")";
        }

    private:
        double x;
        double y;
};

inline std::ostream& operator<<(std::ostream &os, const Komponente &k) {
    k.output(os);
    return os;
}

#endif