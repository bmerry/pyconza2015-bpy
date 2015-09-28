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
