/* Copyright 2015 SKA South Africa
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
