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
