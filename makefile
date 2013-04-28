# Mention default target.
all:

# Implicit rule to compile C++ files.  Modify to your taste.
%.o: %.cpp
	g++ -c -O2 -Wall -Wextra -pedantic $<

# Components of the library.
library-objects = \
	BigUnsigned.o \
	BigInteger.o \
	BigIntegerAlgorithms.o \
	BigUnsignedInABase.o \
	BigIntegerUtils.o \

library-headers = \
	NumberlikeArray.hh \
	BigUnsigned.hh \
	BigInteger.hh \
	BigIntegerAlgorithms.hh \
	BigUnsignedInABase.hh \
	BigIntegerLibrary.hh \

# To ``make the library'', make all its objects using the implicit rule.
library: $(library-objects)

# Conservatively assume that all the objects depend on all the headers.
$(library-objects): $(library-headers)

# The rules below build a program that uses the library.  They are preset to
# build ``sample'' from ``sample.cc''.  You can change the name(s) of the
# source file(s) and program file to build your own program, or you can write
# your own Makefile.

# Components of the program.
program = submission
program-objects = \
	Node.o \
	List.o \
	sort.o \
	driver.o \
	cSort.o \


# Conservatively assume all the program source files depend on all the library
# headers.  You can change this if it is not the case.
$(program-objects) : $(library-headers)

# How to link the program.  The implicit rule covers individual objects.
$(program) : $(program-objects) $(library-objects)
	g++ $^ -o $@

# Delete all generated files we know about.
clean :
	rm -f $(library-objects) $(testsuite-cleanfiles) $(program-objects) $(program)
	rm -rf *.dSYM
	rm *utput*

# I removed the *.tag dependency tracking system because it had few advantages
# over manually entering all the dependencies.  If there were a portable,
# reliable dependency tracking system, I'd use it, but I know of no such;
# cons and depcomp are almost good enough.

# Come back and define default target.
all : library $(program)

test:
	./submission input2.txt output2.txt

test1:
	./submission input.txt output.txt

test2:
	./submission 10d_largeInput.txt 10d_largeOutput.txt

test3:
	./submission 20d_largeInput.txt 20d_largeOutput.txt

test4:
	./submission 100d_largeInput.txt 100d_largeOutput.txt
