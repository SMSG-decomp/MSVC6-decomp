void __fastcall retarget_frame_register_operands(c2_function *fn,c2_symbol *reg)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  int iVar4;
  
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->flags & 1) != 0) {
      iVar4 = 0;
      do {
        if (iVar4 == 0) {
          pcVar2 = pcVar1->dst;
        }
        else {
          pcVar2 = pcVar1->src;
        }
        for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage->id == 6)) {
            pcVar3 = reg_find_subreg(reg,(pcVar2->type & 0xfff) << 3,0);
            (pcVar2->u18).reg = pcVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
    }
  }
  return;
}

