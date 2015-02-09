#include "function.h"

#include "builtins.h"
#include "gc.h"
#include "lang_utils.h"

using namespace vv;

value::function::function(const std::vector<vm::command>& new_body,
                          std::shared_ptr<vm::call_stack> new_enclosure)
  : base      {&builtin::type::function},
    body      {new_body},
    enclosure {new_enclosure}
{ }

std::string value::function::value() const { return "<function>"; }
