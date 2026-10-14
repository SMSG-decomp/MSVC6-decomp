void __fastcall branch_delete(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  if (((t->u20).cond_cells != (c2_cond_cell *)0x0) || (t->op == 0x18b)) {
    branch_delete_cleanup(t);
  }
  node_list_free((c2_node *)(t->u20).cond_cells);
  pcVar1 = t->prev;
  pcVar2 = t->next;
  (t->u20).cond_cells = (c2_cond_cell *)0x0;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  node_free((c2_node *)t);
  return;
}

