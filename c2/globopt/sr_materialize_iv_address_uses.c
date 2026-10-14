void __fastcall sr_materialize_iv_address_uses(c2_symbol *iv)

{
  c2_tuple *anchor;
  c2_operand *new_op;
  
  anchor = symbol_pop_use(iv);
  while (anchor != (c2_tuple *)0x0) {
    if (anchor->op == 0x167) {
      new_op = materialize_memory_address(anchor,anchor->src);
      tuple_replace_src(anchor,anchor->src,new_op);
      anchor->op = 0x15b;
    }
    anchor = symbol_pop_use(iv);
  }
  return;
}

