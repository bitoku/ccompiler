//
// Created by 徳備彩人 on 2021/01/24.
//

#ifndef CCOMPILER_DEFS_H
#define CCOMPILER_DEFS_H

enum {
    TK_PLUS,
    TK_MINUS,
    TK_STAR,
    TK_SLASH,
    TK_INT_LITERAL,
    TK_EOF,
};

struct token {
    int token;
    int int_value;
};

enum {
    ND_ADD,
    ND_SUBTRACT,
    ND_MULTIPLY,
    ND_DIVIDE,
    ND_INT_LITERAL,
};

struct node {
    int op;
    struct node *left;
    struct node *right;
    int int_value;
};

#endif //CCOMPILER_DEFS_H
