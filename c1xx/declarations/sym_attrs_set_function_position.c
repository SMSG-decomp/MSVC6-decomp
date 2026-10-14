void __thiscall sym_attrs_set_function_position(c1_symbol_attrs *attrs,int earlier_entity)

{
  if (earlier_entity == 0) {
    attrs->earlier_entity = 0;
    attrs->flags = attrs->flags & 0xfe;
    return;
  }
  attrs->earlier_entity = earlier_entity;
  attrs->flags = attrs->flags | 1;
  return;
}

