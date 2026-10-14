c2_operand * __fastcall bind_value_to_new_temp(c2_tuple *t,c2_symbol *s,int add_dst)

{
  c2_symbol *sym;
  c2_operand *op;
  c2_operand *op_00;
  
  op = find_src_symbol_ref(t,s);
  op_00 = operand_new_temp(op->type);
  if (add_dst != 0) {
    tuple_append_dst(t,op_00);
    sym = op_00->sym;
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = t;
      retie_register_chain(op,op_00);
      return op_00;
    }
    symbol_mark_overlapping_parts(sym,t);
  }
  retie_register_chain(op,op_00);
  return op_00;
}

