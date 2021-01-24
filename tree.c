//
// Created by 徳備彩人 on 2021/01/24.
//

#include <libc.h>
#include "data.h"

struct node *make_node(
    int op,
    struct node *left,
    struct node *right,
    int int_value
) {
   struct node *n;

   n = (struct node *) malloc(sizeof(struct node));
   if (n == NULL) {
       fprintf(stderr, "Unable to malloc in make_int_node()\n");
       exit(1);
   }
   n->op = op;
   n->left = left;
   n->right = right;
   n->int_value = int_value;
   return n;
}

struct node *make_int(int op, int int_value) {
    return make_node(op, NULL, NULL, int_value);
}

struct node *make_unary(int op, struct node *left, int int_value) {
    return make_node(op, left, NULL, int_value);
}