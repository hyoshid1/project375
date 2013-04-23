all:
	g++ -Wall -Wextra -o submission driver.cpp

test1:
	./submission input.txt output.txt

test2:
	./submission 10d_largeInput.txt 10d_largeOutput.txt

clean:
	rm submission output.txt 10d_largeOutput.txt
