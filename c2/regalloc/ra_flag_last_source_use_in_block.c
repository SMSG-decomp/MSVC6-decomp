void __fastcall ra_flag_last_source_use_in_block(c2_block *b,c2_live_range *lr)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *t;
  
  pcVar1 = b->head;
  t = b->end;
  if (t == pcVar1) {
    return;
  }
  while (((t->flags & 1) == 0 ||
         (pcVar2 = find_src_reg_operand((c2_symbol *)lr,t), pcVar2 == (c2_operand *)0x0))) {
    t = t->prev;
    if (t == pcVar1) {
      return;
    }
  }
  pcVar2->flags11 = pcVar2->flags11 | 0x10;
  return;
}

