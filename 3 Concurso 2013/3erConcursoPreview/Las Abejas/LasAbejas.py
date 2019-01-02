#! /usr/bin/env python	
# -*- coding: utf-8 -*-
from math import sqrt
PI=3.14159265359

def solve():
	ox,oy=raw_input().split(' ')
	ox=float(ox)
	oy=float(oy)
	n,k=raw_input().split(' ')
	n=int(n)
	k=int(k)
	distancia=[0 for i in xrange(n)]
	for i in xrange(n):
		x,y=raw_input().split(' ')
		x=float(x)
		y=float(y)
		xi = x - ox
		yi = y - oy
		distancia[i] = sqrt(xi*xi+yi*yi)
	distancia.sort()
	print "%.2f" % (distancia[k-1]*distancia[k-1]*PI, )
	garbage = raw_input()

#MAIN
casos = raw_input()
casos = int(casos)
for i in xrange(casos):
	solve()


