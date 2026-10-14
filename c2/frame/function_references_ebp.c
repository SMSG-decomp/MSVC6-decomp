int __fastcall function_references_ebp(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_function *pcVar2;
  uint32_t uVar3;
  int iVar4;
  
  g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 & 0xef;
  do {
    if (t == (c2_tuple *)0x0) {
      return 0;
    }
    if ((t->flags & 1) != 0) {
      for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if (pcVar1->op == 0x14a) {
          return 1;
        }
        if (pcVar1->op == 0x14e) {
          return 1;
        }
        if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->storage->id == 6)) {
          return 1;
        }
        if ((pcVar1->kind == '\n') && (uVar3 = bitset_test((c2_bitset *)pcVar1->sym,6), uVar3 != 0))
        {
          return 1;
        }
      }
      for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if (pcVar1->op == 0x14a) {
          return 1;
        }
        if (pcVar1->op == 0x14e) {
          return 1;
        }
        if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->storage->id == 6)) {
          return 1;
        }
        if ((pcVar1->kind == '\n') && (uVar3 = bitset_test((c2_bitset *)pcVar1->sym,6), uVar3 != 0))
        {
          return 1;
        }
      }
      if (((t->kind == '\x15') &&
          (iVar4 = function_references_ebp((t->u20).default_label), iVar4 != 0)) ||
         ((t->op == 0x1a0 &&
          ((pcVar2 = ((t->u20).eh_construct)->object->funclet, pcVar2 != (c2_function *)0x0 &&
           (iVar4 = function_references_ebp(pcVar2->cfg->first->head), iVar4 != 0)))))) {
        return 1;
      }
    }
    t = t->next;
  } while( true );
}

