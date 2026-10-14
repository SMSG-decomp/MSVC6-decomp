c2_tuple * __fastcall emit_x87_unary_tuple(c2_tuple *t,uint32_t op)

{
  c2_operand *dst;
  c2_symbol *sym;
  c2_tuple *t_00;
  
  dst = t->dst;
  t_00 = tuple_new(op,t->type,dst,t->src,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  if (((dst->kind == '\x01') && (sym = dst->sym, sym->cls == '\x03')) &&
     (sym->def != (c2_tuple *)0x0)) {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = t_00;
      tuple_replace(t,(c2_node *)t_00);
      return t_00;
    }
    symbol_mark_overlapping_parts(sym,t_00);
  }
  tuple_replace(t,(c2_node *)t_00);
  return t_00;
}

