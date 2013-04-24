all:
	g++ -Wall -Wextra -g -o submission driver.cpp Node.cpp List.cpp

test1:
	./submission input.txt output.txt

test2:
	./submission 10d_largeInput.txt 10d_largeOutput.txt

clean:
	rm submission output.txt 10d_largeOutput.txt
