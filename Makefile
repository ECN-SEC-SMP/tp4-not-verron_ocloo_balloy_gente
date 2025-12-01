SRCDIR := src
INCDIR := include
BUILDDIR := build
ASSETSDIR := assets

all: $(BUILDDIR)/main.out

# Build the final executable
$(BUILDDIR)/main.out: $(BUILDDIR)/main.o $(BUILDDIR)/Point2D.o 
	g++ -o $@ $^

# Build main.o
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Point2D.cpp $(INCDIR)/Point2D.hpp  | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Build Point2D.o
$(BUILDDIR)/Point2D.o: $(SRCDIR)/Point2D.cpp $(INCDIR)/Point2D.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Point2D.cpp -o $(BUILDDIR)/Point2D.o

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) && rm -rfv $(ASSETSDIR)/lexique*