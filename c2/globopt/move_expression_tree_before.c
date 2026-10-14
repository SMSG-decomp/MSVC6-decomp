void __fastcall move_expression_tree_before(c2_tuple *t,c2_tuple *t2)

{
  c2_operand *pcVar1;
  c2_tuple *t2_00;
  
  tuple_unlink(t2);
  tuple_insert_before(t,t2);
  for (pcVar1 = t2->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
       (t2_00 = pcVar1->sym->def, t2_00 != (c2_tuple *)0x0)) {
      move_expression_tree_before(t2,t2_00);
    }
  }
  return;
}

