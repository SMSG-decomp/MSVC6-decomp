void __fastcall assign_temp_homes_in_reference_order(c2_function *fn)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  
  for (pcVar2 = fn->cfg->first->head; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->flags & 1) != 0) {
      for (pcVar3 = pcVar2->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->op == 0x14a) || (pcVar3->op == 0x14e)) {
          pcVar3->rank = 0;
        }
        if ((((1 << (pcVar3->kind & 0x1f) & 0xcU) != 0) &&
            (pcVar4 = pcVar3->sym->storage, pcVar4->cls == '\x03')) &&
           (bVar1 = pcVar4->flags5, (bVar1 & 0x20) == 0)) {
          if ((((fn->flags & 0x600000) == 0) || ((pcVar4->type & 0xf000) != 0x4000)) ||
             (pcVar4->type != 0x4008)) {
            iVar5 = 0;
          }
          else {
            iVar5 = 8;
          }
          iVar5 = frame_alloc_local(pcVar4->size,iVar5);
          (pcVar4->u28).frame_home = iVar5;
          pcVar4->flags5 = bVar1 | 0x20;
        }
      }
      for (pcVar3 = pcVar2->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->op == 0x14a) || (pcVar3->op == 0x14e)) {
          pcVar3->rank = 0;
        }
        if ((((1 << (pcVar3->kind & 0x1f) & 0xcU) != 0) &&
            (pcVar4 = pcVar3->sym->storage, pcVar4->cls == '\x03')) &&
           (bVar1 = pcVar4->flags5, (bVar1 & 0x20) == 0)) {
          if ((((fn->flags & 0x600000) == 0) || ((pcVar4->type & 0xf000) != 0x4000)) ||
             (pcVar4->type != 0x4008)) {
            iVar5 = 0;
          }
          else {
            iVar5 = 8;
          }
          iVar5 = frame_alloc_local(pcVar4->size,iVar5);
          (pcVar4->u28).frame_home = iVar5;
          pcVar4->flags5 = bVar1 | 0x20;
        }
      }
    }
  }
  return;
}

