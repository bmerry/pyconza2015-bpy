#!/usr/bin/env python
import capi_petshop

p = capi_petshop.Parrot()
print(p)
p.voom()
p.volts = 1000000000000000
print(p.volts)
p.voom()
p.volts = 'hello'
