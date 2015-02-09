#ifndef VV_BUILTINS_H
#define VV_BUILTINS_H

#include "value.h"
#include "vm/call_stack.h"

namespace vv {

namespace builtin {

namespace sym {

extern vv::symbol self;
extern vv::symbol call;

}

namespace function {

extern value::builtin_function print;
extern value::builtin_function puts;
extern value::builtin_function gets;
extern value::builtin_function quit;
extern value::builtin_function make_array;
extern value::builtin_function type;

}

namespace type {

extern value::type string;
extern value::type integer;
extern value::type floating_point;
extern value::type boolean;
extern value::type array;
extern value::type dictionary;
extern value::type symbol;
extern value::type iterator;
extern value::type range;
extern value::type nil;
extern value::type function;
extern value::type custom_type;
extern value::type custom_object;

}

void make_base_env(vm::call_stack& base);

}

}

#endif
