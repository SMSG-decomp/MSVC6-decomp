int __fastcall x87_stack_depth_at(c2_tuple *t)

{
  c2_edge *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_symbol **ppcVar4;
  int iVar5;
  
  if ((t->op != 0x163) && (t->op != 0x164)) {
    return (uint)t->flags12 - (uint)t->flags13;
  }
  pcVar2 = t->prev;
  iVar5 = 0;
LAB_10778485:
  do {
    if ((pcVar2->kind == '\x19') && ((pcVar2->u14).arg != (void *)0x0)) break;
    if (((pcVar2->flags & 1) != 0) &&
       (((pcVar2->type & 0xf000) == 0x4000 || (pcVar2->kind == '\x0e')))) {
      if (pcVar2->op == 0x163) {
        if (((pcVar2->dst->u18).range)->colour != (c2_register_descriptor *)0x0) {
          pcVar2 = pcVar2->prev;
          iVar5 = iVar5 + 1;
          goto LAB_10778485;
        }
      }
      else if (pcVar2->op != 0x164) break;
    }
    pcVar2 = pcVar2->prev;
  } while( true );
  if ((pcVar2->flags & 1) != 0) {
    return (uint)pcVar2->flags12 + iVar5;
  }
  pcVar1 = ((pcVar2->u14).block)->preds;
  if (pcVar1 == (c2_edge *)0x0) {
    return iVar5;
  }
  iVar3 = 0;
  ppcVar4 = ((pcVar1->from->u58).x87_stack)->slot;
  do {
    if (*ppcVar4 == (c2_symbol *)0x0) break;
    iVar3 = iVar3 + 1;
    ppcVar4 = ppcVar4 + 1;
  } while (iVar3 < 8);
  return iVar3 + iVar5;
}

