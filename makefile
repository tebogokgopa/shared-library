CC= g++
CFLAGS=-Wall -shared -fPIC -o

library: 
	$(CC) $(CFLAGS) radarcalculations.so radarcalculations.h radarcalculations.cc

clean:
	rm -f *.so 

