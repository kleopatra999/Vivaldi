#include "function_definition.h"

#include "gc.h"
#include "value/function.h"

using namespace vv;

ast::function_definition::function_definition(symbol name,
                                              std::unique_ptr<expression>&&body,
                                              const std::vector<symbol>& args)
  : m_name {name},
    m_body {move(body)},
    m_args {args}
{ }

std::vector<vm::command> ast::function_definition::generate() const
{
  const auto argc = static_cast<int>(m_args.size());
  std::vector<vm::command> definition;
  for (auto i = argc; i--;) {
    definition.emplace_back(vm::instruction::arg, i);
    definition.emplace_back(vm::instruction::let, m_args[i]);
  }

  auto body = m_body->generate();
  copy(begin(body), end(body), back_inserter(definition));
  definition.emplace_back(vm::instruction::ret);

  std::vector<vm::command> vec;
  vec.emplace_back( vm::instruction::push_fn,
                    vm::function_t{argc, move(definition)} );

  if (m_name != symbol{})
    vec.emplace_back(vm::instruction::let, m_name);

  return vec;
}
