CC = g++
CFLAGS = -std=c++20 -I./src
ODIR = obj
TDIR = test
OBJS = test.o

OBSTEST = $(patsubst %, $(ODIR)/%, $(OBJS))

test: $(OBSTEST)
	$(CC) $(CFLAGS) -o target/$@ $(OBSTEST)

$(ODIR)/%.o: $(TDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(ODIR)/*.o target/test