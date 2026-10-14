int __fastcall ra_block_has_upward_exposed_use(c2_block *b,c2_live_range *lr)

{
  c2_tuple *pcVar1;
  c2_tuple *t;
  c2_operand *pcVar2;
  
  pcVar1 = b->end;
  t = b->head;
  do {
    if (t == pcVar1) {
      return 0;
    }
    if ((t->flags & 1) != 0) {
      pcVar2 = find_src_reg_operand((c2_symbol *)lr,t);
      if (pcVar2 != (c2_operand *)0x0) {
        return 1;
      }
      pcVar2 = find_dst_reg_operand((c2_symbol *)lr,t);
      if (pcVar2 != (c2_operand *)0x0) {
        return 0;
      }
    }
    t = t->next;
  } while( true );
}

