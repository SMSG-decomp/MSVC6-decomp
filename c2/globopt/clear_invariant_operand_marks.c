void __fastcall clear_invariant_operand_marks(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->flags & 1) != 0) {
      for (pcVar2 = pcVar1->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        pcVar2->flags11 = pcVar2->flags11 & 0x7f;
      }
      for (pcVar2 = pcVar1->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        pcVar2->flags11 = pcVar2->flags11 & 0x7f;
      }
    }
  }
  return;
}

