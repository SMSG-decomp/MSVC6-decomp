c2_node * __fastcall simplify_tree_bottom_up(c2_tuple *t,c2_tuple *user,int factoring)

{
  c2_operand *pcVar1;
  c2_operand *t_00;
  c2_tuple *pcVar2;
  
  do {
    pcVar1 = t->src;
    do {
      t_00 = pcVar1;
      if (t_00 == (c2_operand *)0x0) {
        pcVar2 = simplify_node_algebraic(t,user);
        pcVar2 = (c2_tuple *)fold_constant_operands(pcVar2,user);
        if ((factoring != 0) || (pcVar2->op == 0x17d)) {
          pcVar2 = factor_common_terms(pcVar2,user);
          refresh_node_cost_shallow(pcVar2);
        }
        return (c2_node *)pcVar2;
      }
      pcVar1 = t_00->next;
    } while (((((1 << (t_00->kind & 0x1f) & 0xffeU) != 0) ||
              (pcVar2 = (c2_tuple *)simplify_tree_bottom_up((c2_tuple *)t_00,t,factoring),
              factoring == 0)) || (pcVar2->op != 0x15f)) ||
            (pcVar2 = (c2_tuple *)narrow_conversion_into_operator(t,pcVar2,user),
            pcVar2 == (c2_tuple *)0x0));
  } while (pcVar2 == t);
  simplify_tree_bottom_up(t,pcVar2,factoring);
  return (c2_node *)pcVar2;
}

