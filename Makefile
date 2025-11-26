
tp9ex: tp9ex.o ti.o image.o matrice.o
	 gcc tp9ex.o ti.o image.o matrice.o -lm -o tp9ex

tp9ex.o: tp9ex.c ti.h image.h matrice.h
	 gcc -c tp9ex.c

image.o: image.c image.h matrice.h
	 gcc -c image.c

matrice.o: matrice.c matrice.h
	 gcc -c matrice.c

clean:
	 rm -f *.o tp9ex