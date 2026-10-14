c2_tuple * __fastcall
build_fill_pattern(uint32_t op,uint16_t type,c2_operand *dst,c2_operand **src,c2_tuple *anchor)

{
  c2_tuple *t;
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  
  pcVar2 = *src;
  t = tuple_new(op,type,dst,pcVar2,tuple_insert_after,anchor);
  pcVar1 = dst->sym;
  if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
    pcVar1->def = t;
  }
  else {
    symbol_mark_overlapping_parts(pcVar1,t);
  }
  if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
    pcVar1 = symbol_new_temp(type);
    if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
      pcVar1->def = t;
    }
    else {
      symbol_mark_overlapping_parts(pcVar1,t);
    }
    pcVar2 = operand_new_reg(0x149,type,pcVar1,pcVar1);
    tuple_append_dst(t,pcVar2);
    retie_register_chain(t->src,pcVar2);
    *src = pcVar2;
  }
  return t;
}

