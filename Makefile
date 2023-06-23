CC=gcc
ODIR = .
LIBS = -lm

DEPS = sobel_kernel.h check_file.h SOBEL_edgeDetection.h

make: SOBEL_edgeDetection.o check_file.o main.c
	$(CC) -g check_file.o SOBEL_edgeDetection.o main.c -o app $(LIBS)

SOBEL_edgeDetection.o: SOBEL_edgeDetection.c SOBEL_edgeDetection.h sobel_kernel.h
	$(CC) -c SOBEL_edgeDetection.c

check_file.o: check_file.c check_file.h
	$(CC) -c check_file.c

#make: main.c $(DEPS)
#	$(CC) -g main.c sobel_kernel.c check_file.c SOBEL_edgeDetection.c -o main $(LIBS) 

run:
	./app

check:
	cppcheck --addon=misra.json --inline-suppr --suppressions-list=suppressions.txt main.c sobel_kernel.c check_file.c SOBEL_edgeDetection.c

.PHONY:clean

clean:
	rm -f ./app
	rm -f $(ODIR)/*.o lena_output* barbara_output*
