OBJS = uimain.o tokenizer.o history.o
CFLAGS = -g -O3

all: token

token: $(OBJS)
	cc -o token $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o token

run:token
	./token
