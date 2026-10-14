c2_tuple * __fastcall hoist_common_negation(c2_tuple *t,c2_tuple *parent,uint32_t op)

{
  c2_operand *t_00;
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  t_00 = t->src;
  pcVar1 = t_00;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      while (t_00 != (c2_operand *)0x0) {
        pcVar1 = t_00->next;
        tuple_forward_src_and_free((c2_tuple *)t_00,t);
        t_00 = pcVar1;
      }
      pcVar2 = negate_operand((c2_node *)t,parent);
      g_simplify_changed = 1;
      pcVar2 = simplify_node_algebraic(pcVar2,parent);
      return pcVar2;
    }
    if (pcVar1->op != op) break;
    pcVar1 = pcVar1->next;
  }
  return t;
}

