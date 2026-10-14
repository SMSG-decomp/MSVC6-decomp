int __fastcall tree_any_def_matches(c2_tuple *t,c2_accept_fn *accept,c2_tuple **found)

{
  c2_operand *pcVar1;
  c2_tuple *t_00;
  c2_operand *pcVar2;
  int iVar3;
  
  iVar3 = (*accept)(t,(int *)found);
  if (iVar3 == 0) {
    pcVar1 = t->src;
    do {
      pcVar2 = pcVar1;
      if (pcVar2 == (c2_operand *)0x0) {
        return 0;
      }
      pcVar1 = pcVar2->next;
    } while ((((1 << (pcVar2->kind & 0x1f) & 6U) == 0) ||
             (t_00 = pcVar2->sym->def, t_00 == (c2_tuple *)0x0)) ||
            (iVar3 = tree_any_def_matches(t_00,accept,found), iVar3 == 0));
  }
  return 1;
}

