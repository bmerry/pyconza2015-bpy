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

#include "petshop_wrap.h"
#include "petshop.h"

extern "C"
{

parrot_handle parrot_new(void)
{
    parrot_handle out;
    out.parrot = static_cast<void *>(new petshop::Parrot);
    return out;
}

void parrot_delete(parrot_handle handle)
{
    delete static_cast<petshop::Parrot *>(handle.parrot);
}

void parrot_voom(parrot_handle handle)
{
    static_cast<petshop::Parrot *>(handle.parrot)->voom();
}

void parrot_set_volts(parrot_handle handle, int volts)
{
    static_cast<petshop::Parrot *>(handle.parrot)->set_volts(volts);
}

int parrot_get_volts(parrot_handle handle)
{
    return static_cast<petshop::Parrot *>(handle.parrot)->get_volts();
}

}
