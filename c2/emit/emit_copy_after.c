c2_tuple * __fastcall
emit_copy_after(uint16_t type,c2_operand *dst,c2_operand *src,c2_tuple *anchor)

{
  c2_symbol *sym;
  c2_tuple *t;
  
  t = tuple_new(1,type,dst,src,tuple_insert_after,anchor);
  sym = dst->sym;
  if (sym->storage->part_next == (c2_symbol *)0x0) {
    sym->def = t;
    return t;
  }
  symbol_mark_overlapping_parts(sym,t);
  return t;
}

