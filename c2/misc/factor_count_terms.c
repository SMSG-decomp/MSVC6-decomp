void __fastcall factor_count_terms(c2_tuple *t,uint32_t op,uint32_t inner)

{
  c2_operand *pcVar1;
  c2_operand *t_00;
  
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    t_00 = pcVar1;
    if (pcVar1->op == inner) {
      t_00 = (pcVar1->u18).children;
    }
    if (t_00->op == op) {
      factor_count_terms((c2_tuple *)t_00,0x145,inner);
    }
    else {
      factor_count_subtree((c2_node *)t_00);
    }
  }
  return;
}

