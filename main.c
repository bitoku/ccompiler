#include <stdio.h>
#include <libc.h>
#include <errno.h>

#define extern_
#include "data.h"
#undef extern_
#include "decl.h"

char *token_list[] = {"+", "-", "*", "/", "int_literal"};

static void init() {
    Line = 1;
    Putback = '\n';
}

int main(int argc, char *argv[]) {
    struct node *n;

    init();
    if ((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan(&Token);
    n = statement();
    printf("%d\n", interpret_ast(n));
    return 0;
}