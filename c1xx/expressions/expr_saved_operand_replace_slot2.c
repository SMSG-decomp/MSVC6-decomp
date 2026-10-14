void __thiscall expr_saved_operand_replace_slot2(c1_saved_operand *rec,c1_node *node)

{
  expr_saved_operand_slot2((int *)rec);
  node->link = rec->slot2->link;
  rec->slot2->link->left = node;
  rec->slot2 = node;
  return;
}

