OBJS = tokenizer.o history.o ui.o

CFLAGS = -g -03

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)
clean:
	rm -f *.o tokenize
run: tokenize
	./tokenize
