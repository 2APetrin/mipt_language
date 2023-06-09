#pragma once

#include "../tree/tree.h"
#include "../tokenizer/tokenizer.h"


token_t* get_general(text_t* text);

token_t* get_def_function(text_t* text);

token_t* get_start(text_t* text);

token_t* get_comp(text_t* text);

token_t* get_operator(text_t* text);

token_t* get_print(text_t* text);

token_t* get_If(text_t* text);

token_t* get_expr(text_t* text);

token_t* get_T(text_t* text);

token_t* get_P(text_t* text);

token_t* get_elem(text_t* text);
