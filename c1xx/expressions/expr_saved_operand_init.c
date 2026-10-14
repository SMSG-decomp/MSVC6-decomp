void __thiscall expr_saved_operand_init(c1_saved_operand *rec,c1_node *expr)

{
  rec->root = expr;
  rec->slot1 = (c1_node *)0x0;
  rec->slot2 = (c1_node *)0x0;
  rec->replacement = (c1_node *)0x0;
  return;
}

