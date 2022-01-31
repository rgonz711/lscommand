#Raul Gonzalez
#RedID 824258754


myls: myls.o
	gcc myls.o -o myls

myls.o: myls.c
	gcc -c myls.c

clean:
	rm *.o myls

