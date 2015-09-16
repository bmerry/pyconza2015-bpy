#include "petshop.h"

int main()
{
    petshop::Parrot p;
    p.set_volts(10);
    p.voom();
    p.set_volts(10000000);
    p.voom();
    return 0;
}
