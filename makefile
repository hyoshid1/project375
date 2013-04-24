all:
	g++ -Wall -Wextra -g -o submission driver.cpp Node.cpp List.cpp sort.cpp

test1:
	./submission input.txt output.txt

test2:
	./submission 10d_largeInput.txt 10d_largeOutput.txt

test3:
	./submission 20d_largInput.txt 20d_largeOutput.txt

test4:
	./submission 100d_largeInput.txt 100d_largeInput.txt

clean:
	rm submission *utput*
	rm -rf *.dSYM
