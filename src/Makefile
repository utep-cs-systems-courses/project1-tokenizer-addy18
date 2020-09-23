#FIles for program
OBJS= tokenizer.o history.o uimain.o

#-g to debug -03 to optimize code for performance
CFLAGS= -g -03

#first target built in make
all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)
clean:
	rm -f *.o tokenize
run: tokenize
	./tokenize
