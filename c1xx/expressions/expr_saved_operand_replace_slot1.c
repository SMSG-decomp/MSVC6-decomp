void __thiscall expr_saved_operand_replace_slot1(void *rec,c1_node *node)

{
  expr_saved_operand_slot1(rec);
  node->link = *(c1_node **)(*(int *)((int)rec + 4) + 8);
  *(c1_node **)(*(int *)(*(int *)((int)rec + 4) + 8) + 0x10) = node;
  *(c1_node **)((int)rec + 4) = node;
  return;
}

