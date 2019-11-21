.SUFFIX:.cpp .o

CC=g++
SRCS=main2.cpp\
	 	Huffman.cpp\
			File.cpp

OBJS=$(SRCS:.cpp=.o)
EXEC=xuzip

start:$(OBJS)
	@$(CC) -o $(EXEC) $(SRCS) -g
	@echo "----------OK"
.cpp.o:
	@$(CC) -o $@ -c $< -g
clean:
	@rm -rf $(OBJS) $(EXEC)
