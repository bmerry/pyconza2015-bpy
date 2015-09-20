#!/usr/bin/env python
import cffi_petshop

p = cffi_petshop.Parrot()
print(p)
p.voom()
p.volts = 1000000000000000
print(p.volts)
p.voom()
p.volts = 'hello'
