#! /usr/bin/env python

n = int(raw_input())

lista = []

for i in xrange(n):
	tmp = int(raw_input())
	lista.append(tmp)

lista.sort()
lista.reverse()

for i in lista:
	print i
