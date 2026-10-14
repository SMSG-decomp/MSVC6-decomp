void __fastcall pass_mark_register_candidates(c2_function *fn)

{
  uint16_t type;
  c2_tuple *pcVar1;
  c2_operand *opnd;
  c2_symbol *pcVar2;
  int iVar3;
  int iVar4;
  
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->flags & 1) != 0) {
      iVar4 = 0;
      do {
        if (iVar4 == 0) {
          opnd = pcVar1->dst;
        }
        else {
          opnd = pcVar1->src;
        }
        for (; opnd != (c2_operand *)0x0; opnd = opnd->next) {
          if ((opnd->kind == '\x02') && ((opnd->flags & 0x40) == 0)) {
            pcVar2 = opnd->sym;
            if ((((pcVar2->storage->fe != (c2_fe_symbol *)0x0) ||
                 ((pcVar2->cls == '\x03' && (pcVar2->def == (c2_tuple *)0x0)))) &&
                ((pcVar2->storage->flags5 & 0x40) == 0)) && (pcVar2->cls != '\n')) {
              type = opnd->type;
              iVar3 = type_is_register_candidate(type);
              if ((iVar3 != 0) &&
                 (((pcVar1->kind != '\x0e' || (opnd != pcVar1->src)) && ((type & 0xf000) != 0x4000))
                 )) {
                mark_operand_register_candidate(opnd);
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
    }
  }
  return;
}

