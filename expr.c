//
// Created by 徳備彩人 on 2021/01/24.
//
#include <stdio.h>
#include <libc.h>
#include "data.h"
#include "decl.h"

int arithop(int tok) {
    switch (tok) {
    case TK_PLUS:
        return ND_ADD;
    case TK_MINUS:
        return ND_SUBTRACT;
    case TK_STAR:
        return ND_MULTIPLY;
    case TK_SLASH:
        return ND_DIVIDE;
    default:
        fprintf(stderr, "Unknown token in arithop() on line %d\n", Line);
        exit(1);
    }
}

static struct node *primary(void) {
    struct node *n;

    switch (Token.token) {
    case TK_INT_LITERAL:
        n = make_int(ND_INT_LITERAL, Token.int_value);
        scan(&Token);
        return (n);
    default:
        fprintf(stderr, "syntax error on line %d\n", Line);
        exit(1);
    }
}

struct node *statement(void) {
    struct node *n, *left, *right;
    int node_type;
    left = primary();
    arithop(Token.token);

    if (Token.token == TK_EOF) return left;

    node_type = arithop(Token.token);

    scan(&Token);

    right = statement();

    n = make_node(node_type, left, right, 0);
    return n;
}