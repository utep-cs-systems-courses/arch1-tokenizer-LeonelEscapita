OBJS = uimain.o tokenizer.o
CFLAGS = -g -O3

all: token

token: $(OBJS)
	cc -o token $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean:
	rm -f *.o token

run:token
	./token
