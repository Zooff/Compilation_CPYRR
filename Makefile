CMD_BISON = bison
CMD_FLEX = flex

FIC_BISON = grammaire_CPYRR
FIC_FLEX = lex_CPYRR

CC = gcc
CFLAGS = -Wall
LDFLAGS = -ly -lfl


compilateur: $(FIC_BISON).tab.c lex.yy.c
	$(CC) -o compilateur $(FIC_BISON).tab.c lex.yy.c lexhashcode.c $(LDFLAGS)


grammaire_CPYRR.tab.c : $(FIC_BISON).y
	$(CMD_BISON) -d -v $(FIC_BISON).y

lex.yy.c: $(FIC_FLEX).l
	flex $(FIC_FLEX).l

clean:
	 rm -r $(FIC_BISON).tab.c $(FIC_BISON).tab.h $(FIC_BISON).output lex.yy.c compilateur
