void __fastcall shrink_wrap_collect_regs(c2_tuple *t,c2_block *b)

{
  c2_operand *pcVar1;
  int iVar2;
  
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->kind == '\x01') {
      b->de = (c2_bitset *)((uint)b->de | 1 << ((byte)((pcVar1->u18).reg)->storage->id & 0x1f));
    }
    else if (pcVar1->kind == '\n') {
      iVar2 = bitset_iter_next((c2_bitset *)pcVar1->sym);
      while (iVar2 != -1) {
        b->de = (c2_bitset *)((uint)b->de | 1 << ((byte)iVar2 & 0x1f));
        iVar2 = bitset_iter_next((c2_bitset *)0x0);
      }
    }
  }
  for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->kind == '\x01') {
      b->de = (c2_bitset *)((uint)b->de | 1 << ((byte)((pcVar1->u18).reg)->storage->id & 0x1f));
    }
    else if (pcVar1->kind == '\n') {
      iVar2 = bitset_iter_next((c2_bitset *)pcVar1->sym);
      while (iVar2 != -1) {
        b->de = (c2_bitset *)((uint)b->de | 1 << ((byte)iVar2 & 0x1f));
        iVar2 = bitset_iter_next((c2_bitset *)0x0);
      }
    }
  }
  return;
}

