uint32_t __fastcall discard_expression_tree(c2_node *t)

{
  c2_node *pcVar1;
  c2_node *pcVar2;
  c2_tuple *pcVar3;
  uint uVar4;
  uint32_t uVar5;
  int iVar6;
  c2_tuple *t_00;
  
  uVar4 = 1 << (t->kind & 0x1f);
  if ((uVar4 & 0xffe) == 0) {
    iVar6 = node_has_side_effects(t);
    if (iVar6 != 0) {
      t->rank_or_prev = 0;
      t_00 = (c2_tuple *)tuple_delete_if_dead(t,0);
      while (t_00 != (c2_tuple *)0x0) {
        pcVar3 = t_00->prev;
        t_00->flags12 = '\x01';
        cost_sort_and_emit_tree(t_00);
        t_00 = pcVar3;
      }
      return 0;
    }
    for (pcVar2 = *(c2_node **)&t[1].kind; pcVar2 != (c2_node *)0x0; pcVar2 = pcVar2->next) {
      discard_expression_tree(pcVar2);
    }
  }
  else {
    if (((((uVar4 & 0x60) != 0) &&
         ((pcVar2 = *(c2_node **)&t[2].kind, pcVar2 == (c2_node *)0x0 ||
          (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (*(int *)(pcVar2[1].op + 0x14) != 0)))))) &&
        ((pcVar1 = (c2_node *)t[2].rank_or_prev, pcVar1 == (c2_node *)0x0 ||
         (((1 << (pcVar1->kind & 0x1f) & 6U) != 0 && (*(int *)(pcVar1[1].op + 0x14) != 0)))))) &&
       (pcVar2 != pcVar1)) {
      t = pcVar2;
    }
    if ((((1 << (t->kind & 0x1f) & 6U) != 0) &&
        (pcVar2 = *(c2_node **)(t[1].op + 0x14), pcVar2 != (c2_node *)0x0)) &&
       (uVar5 = discard_expression_tree(pcVar2), uVar5 != 0)) {
      node_free(pcVar2);
      return 1;
    }
  }
  return 1;
}

