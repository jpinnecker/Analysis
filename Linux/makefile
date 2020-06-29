Analysis: Bison Flex
	g++ *.cpp -o Analysis

Bison: grammar.y
	bison --defines="grammar.tab.h" --output="grammar.tab.cpp" grammar.y

Flex: tokens.l
	flex --outfile="tokens.flex.cpp" tokens.l

clean:
	rm Analysis grammar.tab.* tokens.flex.cpp
