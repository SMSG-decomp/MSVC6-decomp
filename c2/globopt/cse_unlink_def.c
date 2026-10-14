void __fastcall cse_unlink_def(c2_tuple *t)

{
  c2_operand *op;
  c2_symbol *sym;
  c2_operand *local_4;
  
  op = t->dst;
  local_4 = (c2_operand *)t;
  find_next_use_of_dst(t,&local_4);
  if (op->kind != '\x02') {
    operand_make_sym(op);
  }
  if (local_4->kind != '\x02') {
    operand_make_sym(local_4);
  }
  sym = op->sym;
  if (sym->storage->part_next == (c2_symbol *)0x0) {
    sym->def = (c2_tuple *)0x0;
    return;
  }
  symbol_mark_overlapping_parts(sym,(c2_tuple *)0x0);
  return;
}

