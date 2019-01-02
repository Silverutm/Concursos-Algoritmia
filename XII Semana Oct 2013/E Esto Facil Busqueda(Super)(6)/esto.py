#! /usr/bin/env python

T = int(raw_input())

for it in xrange(T):
	N = int(raw_input())

	arr = [int(j) for j in raw_input().split()]

	M = int(raw_input())

	d = {}

	for i in arr:
		if i not in d:
			d[i] = 1
		else:
			d[i] += 1

	salir = False
	for i in arr:
		if M - i in d:
			salir = True
			print "SI"
			break

	if salir:
		continue

	print "NO"
