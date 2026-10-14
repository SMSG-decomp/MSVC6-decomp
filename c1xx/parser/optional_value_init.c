c1_param_clause * __thiscall
optional_value_init(c1_param_clause *clause,c1_u32 tag,c1_sym_list *params,char pop_scope)

{
  clause->kind = tag;
  if ((params == (c1_sym_list *)0x0) && (pop_scope == '\0')) {
    clause->params = (c1_sym_list *)0x0;
    clause->pop_scope = '\0';
    return clause;
  }
  clause->params = params;
  clause->pop_scope = '\x01';
  return clause;
}

