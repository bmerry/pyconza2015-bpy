#ifndef PETSHOP_H
#define PETSHOP_H

namespace petshop
{

class Parrot
{
private:
    int volts;
public:
    void voom();
    void set_volts(int volts);
    int get_volts() const;
};

}

#endif
