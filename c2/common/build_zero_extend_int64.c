c2_tuple * __fastcall
build_zero_extend_int64(c2_operand *dst,c2_tuple *anchor,uint32_t lo,int link_def)

{
  uint16_t type;
  c2_symbol *sym;
  c2_const_operand *src;
  c2_tuple *t;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  type = dst->type;
  src = operand_new_intconst(type,lo,(int)lo >> 0x1f);
  t = tuple_new(1,type,dst,src,insert_fn,anchor);
  if (link_def != 0) {
    sym = dst->sym;
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = t;
    }
    else {
      symbol_mark_overlapping_parts(sym,t);
    }
    if (lo == 0) {
      t->op = 0x11a;
    }
  }
  return t;
}

