plot.png: Calor.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: Calor.cpp
	g++ Calor.cpp
