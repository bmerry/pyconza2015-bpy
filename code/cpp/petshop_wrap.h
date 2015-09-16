#ifndef PETSHOP_WRAP_H
#define PETSHOP_WRAP_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    void *parrot;
} parrot_handle;

parrot_handle parrot_new(void);
void parrot_delete(parrot_handle);
void parrot_voom(parrot_handle);
void parrot_set_volts(parrot_handle, int volts);
int parrot_get_volts(parrot_handle);

#ifdef __cplusplus
}
#endif

#endif
