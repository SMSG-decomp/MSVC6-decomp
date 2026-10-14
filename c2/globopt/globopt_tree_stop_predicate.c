int __fastcall globopt_tree_stop_predicate(c2_tuple *t,int *clean)

{
  c2_operand *pcVar1;
  int iVar2;
  
  iVar2 = node_has_side_effects((c2_node *)t);
  if (iVar2 == 0) {
    pcVar1 = t->src;
    while( true ) {
      if (pcVar1 == (c2_operand *)0x0) {
        *clean = 1;
        return 0;
      }
      if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->cls == '\x03')) &&
         (pcVar1->sym->def == (c2_tuple *)0x0)) break;
      pcVar1 = pcVar1->next;
    }
  }
  *clean = 0;
  return 1;
}

