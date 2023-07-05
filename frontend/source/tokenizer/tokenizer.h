#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../tree/tree.h"

#define ASSERT(cond)                                                     \
    if (!(cond))                                                          \
    {                                                                      \
        printf("\nError in %s in line %d in function %s in file %s\n\n",    \
                #cond, __LINE__, __PRETTY_FUNCTION__, __FILE__),             \
        abort();                                                              \
    }


// ========================== DSL ==========================

#define TEXT_LINES text->code_buff.text_lines // pointers to first elements of lines
#define TEXT_BUFF  text->code_buff.text_buff
#define TEXT_LEN   text->code_buff.text_len   // number of symbols in text without 0 in the end
#define WORDS_CNT  text->code_buff.words_cnt
#define LINES_CNT  text->code_buff.lines_cnt
#define POS        text->position
#define TOKEN_BUFF text->token_buff
#define VAR_BUFF   text->var_buff

// =========================================================


//! @brief extern code file
extern FILE* code_file;


//! @brief type of our elements values
typedef double elem_t;


//! @brief maximum length of word
const unsigned MAX_WORD_LEN = 128;


//! @brief structure of variable
typedef struct
{
    char*  name;
    elem_t value;
} var_t;


//! @brief struct of lexical token
typedef struct token
{
    char*      word;
    token_type type;
    elem_t     value;

    token*     parent;
    token*     prev;
    token*     next;

    unsigned   line;
    unsigned   pos;
} token_t;


//! @brief struct of string separation
typedef struct
{
    char**   text_lines;
    char*    text_buff;

    unsigned lines_cnt;
    unsigned words_cnt;
    unsigned text_len;
} code_buff_t;


//! @brief struct of our code
typedef struct
{
    unsigned  position;   // universal var

    token_t** token_buff;
    token_t*  tree_root;
    token_t*  end;

    unsigned  var_cnt;
    var_t**   var_buff;

    code_buff_t code_buff;
} text_t;


//! @brief constructor of text struct
int text_ctor(const char* codefile_name, text_t* text);


//! @brief gets pointers to strings
int get_strings(text_t* text);


//! @brief gets numer of strings in text buffer
int get_num_of_words(text_t* text);


//! @brief gets number of lines in text buffer
int get_num_of_lines(text_t* text);


//! @brief makes tokens out of a line
int get_tokens(text_t* text);


//! @brief skips all blank symbols like spaces tabs and \n
int skip_blanks(text_t* text, unsigned int i);


//! @brief destructor of text struct
int text_dtor(text_t* text);


//! @brief gets tokens from line
int tokenize_line(text_t* text, unsigned int i);


//! @brief gets word from line
int get_word(text_t* text, unsigned int i);