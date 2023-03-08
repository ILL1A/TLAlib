CC = g++
CFLAGS = -std=c++20 -I./include
ODIR = obj
SDIR = src/math
TDIR = test
OBJS = vector.o matrix.o test.o

OBSTEST = $(patsubst %, $(ODIR)/%, $(OBJS))

test: $(OBSTEST)
	$(CC) $(CFLAGS) -o target/$@ $(OBSTEST)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR)/%.o: $(TDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(ODIR)/*.o target/test