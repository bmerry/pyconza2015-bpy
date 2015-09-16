#include <iostream>
#include "petshop.h"

using namespace std;

namespace petshop
{

void Parrot::voom()
{
    if (volts >= 4000000)
        cout << "It wouldn't voom if you put 4 million volts through it!\n";
    else
        cout << "If you hadn't nailed it to the perch, it'd be pushing up the daisies!\n";
}

void Parrot::set_volts(int volts)
{
    this->volts = volts;
}

int Parrot::get_volts() const
{
    return volts;
}

}
