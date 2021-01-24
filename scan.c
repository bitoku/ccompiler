//
// Created by 徳備彩人 on 2021/01/24.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <libc.h>
#include "data.h"

static int next(void) {
    int c;

    if (Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if ('\n' == c) Line++;
    return c;
}

static void putback(int c) {
    Putback = c;
}

static int skip(void) {
    int c;

    c = next();
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
        c = next();
    }
    return c;
}

static int chrpos(char *s, int c) {
    char *p;

    p = strchr(s, c);
    return p ? p - s : -1; // NOLINT(cppcoreguidelines-narrowing-conversions)
}

static int scan_int(int c) {
    int k, val = 0;

    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    putback(c);
    return val;
}

int scan(struct token *t) {
    int c;

    c = skip();

    switch (c) {
    case EOF:
        t->token = TK_EOF;
        break;
    case '+':
        t->token = TK_PLUS;
        break;
    case '-':
        t->token = TK_MINUS;
        break;
    case '*':
        t->token = TK_STAR;
        break;
    case '/':
        t->token = TK_SLASH;
        break;
    default:
        if (isdigit(c)) {
            t->int_value = scan_int(c);
            t->token = TK_INT_LITERAL;
            break;
        }

        printf("Unrecognised character %c on Line %d\n", c, Line);
        exit(1);
    }
}

