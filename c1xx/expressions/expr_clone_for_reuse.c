void __thiscall expr_clone_for_reuse(c1_saved_operand *rec,c1_node *value)

{
  c1_node *pcVar1;
  
  expr_saved_operand_slot2((int *)rec);
  rec->slot2->link->left = (void *)0x0;
  pcVar1 = tree_copy_to_arena(rec->root,g_expr_arena_index);
  rec->slot2->link->left = rec->slot2;
  *(c1_node **)(*(int *)(*(int *)((int)pcVar1->right + 0x14) + 0x14) + 0x10) = value;
  return;
}

