c2_tuple * __fastcall simplify_tuple_tree(c2_tuple *t)

{
  c2_operand *pcVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_block *pcVar5;
  
  pcVar1 = t->src;
  if (pcVar1 == (c2_operand *)0x0) {
    return t;
  }
  uVar2 = t->op;
  if (uVar2 == 0x16c) {
    if (pcVar1->kind == 6) {
      if ((1 << (pcVar1->base->kind & 0x1f) & 6U) == 0) {
        return t;
      }
      pcVar4 = pcVar1->base->sym->def;
      pcVar3 = t;
      if (pcVar4 == (c2_tuple *)0x0) {
        return t;
      }
    }
    else if (((1 << (pcVar1->kind & 0x1f) & 6U) == 0) ||
            (pcVar4 = pcVar1->sym->def, pcVar3 = t, pcVar4 == (c2_tuple *)0x0)) {
      return t;
    }
  }
  else if (uVar2 == 0x185) {
    pcVar4 = pcVar1->next->sym->def;
    pcVar3 = t;
  }
  else {
    if (uVar2 == 0x1ab) {
      if ((t->u20).cond_cells == (c2_cond_cell *)0x0) {
        return t;
      }
      for (pcVar4 = (c2_tuple *)list_last((c2_link *)(t->u20).cond_cells);
          (pcVar4 != (c2_tuple *)0x0 && (pcVar4->op != 0x1ac)); pcVar4 = pcVar4->prev) {
      }
      simplify_tuple_tree(pcVar4);
      return t;
    }
    g_simplify_context_tuple = (c2_tuple *)0x0;
    pcVar4 = t;
    pcVar3 = g_simplify_context_tuple;
  }
  g_simplify_context_tuple = pcVar3;
  g_simplify_insert_before = pcVar4->next;
  pcVar4 = prepare_and_simplify_tree(pcVar4);
  pcVar4 = compute_tree_cost_and_sort(pcVar4);
  pcVar4 = (c2_tuple *)emit_tree_as_tuples(pcVar4);
  pcVar5 = (c2_block *)pcVar4;
  if ((1 << (pcVar4->kind & 0x1f) & 0xffeU) != 0) {
    pcVar5 = ((pcVar4->u14).block)->rpo_next;
    node_free((c2_node *)pcVar4);
  }
  return (c2_tuple *)pcVar5;
}

