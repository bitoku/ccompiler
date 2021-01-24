//
// Created by 徳備彩人 on 2021/01/24.
//

#ifndef CCOMPILER_DATA_H
#define CCOMPILER_DATA_H
#ifndef extern_
#define extern_ extern
#endif
#include "defs.h"

extern_ int Line;
extern_ int Putback;
extern_ FILE *Infile;
extern_ struct token Token;

#endif //CCOMPILER_DATA_H
