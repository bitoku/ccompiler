//
// Created by 徳備彩人 on 2021/01/24.
//

#ifndef CCOMPILER_DECL_H
#define CCOMPILER_DECL_H

#include "data.h"

int scan(struct token *t);
struct node *make_node(
    int op,
    struct node *left,
    struct node *right,
    int int_value
);
struct node *make_int(int op, int int_value);
struct node *make_unary(int op, struct node *left, int int_value);
struct node *statement(void);
int interpret_ast(struct node *n);

#endif //CCOMPILER_DECL_H
