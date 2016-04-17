CMOCK=$(shell readlink -f ..)
CWD=$(shell pwd)
CFLAGS=
LDFLAGS=-rdynamic -Wl,--no-as-needed -ldl

INCFLAGS = -isystem ../include -I../include/
SRCS=$(shell ls *.cc)
OBJS=$(SRCS:.cc=.o)

all: libfoo.so cmock_test

foo.o: foo.c
	$(CC) -c -fPIC $^ -o $@

libfoo.so: foo.o
	$(CC) -shared -Wl,-soname,$(CWD)/$@ -o $@ $^

%.o: %.cc
	$(CXX) $(INCFLAGS) -c $(CFLAGS) $^ -o $@

cmock_test: $(OBJS)
	$(CXX) $(INCFLAGS) $^ $(LDFLAGS) -pthread -L$(CWD) -lfoo ../gmock_main.a -o $@

clean:
	rm -f $(OBJS) cmock_test foo.o libfoo.so
