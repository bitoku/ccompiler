//
// Created by 徳備彩人 on 2021/01/24.
//

#include <stdio.h>
#include <libc.h>
#include "data.h"

int interpret_ast(struct node *n) {
    int left, right;

    if (n->left) left = interpret_ast(n->left);
    if (n->right) right = interpret_ast(n->right);

    switch (n->op) {
    case ND_ADD:
        return left + right;
    case ND_SUBTRACT:
        return left - right;
    case ND_MULTIPLY:
        return left * right;
    case ND_DIVIDE:
        return left / right;
    case ND_INT_LITERAL:
        return n->int_value;
    default:
        fprintf(stderr, "Unknown AST operator %d\n", n->op);
        exit(1);
    }
}