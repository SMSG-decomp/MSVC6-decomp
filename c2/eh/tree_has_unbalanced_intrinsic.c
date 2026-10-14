int __fastcall tree_has_unbalanced_intrinsic(c2_tuple *t,int depth)

{
  c2_operand *pcVar1;
  c2_tuple *t_00;
  int iVar2;
  
  if (t->kind == '\x12') {
    if ((t->u20).intrinsic.id == 0xdf) {
      depth = depth + 1;
    }
    if ((t->u20).intrinsic.id == 0xde) {
      if (depth == 0) {
        return 1;
      }
      depth = depth + -1;
    }
  }
  pcVar1 = t->src;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
        (t_00 = pcVar1->sym->def, t_00 != (c2_tuple *)0x0)) &&
       (iVar2 = tree_has_unbalanced_intrinsic(t_00,depth), iVar2 != 0)) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

