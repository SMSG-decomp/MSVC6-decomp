void __fastcall factor_replace_with_combined(c2_node *n,c2_tuple *t,int op,int inner)

{
  c2_operand *new_op;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *old;
  c2_operand *t_00;
  
  factor_combine_or_identity(t,n,op);
  pcVar1 = (c2_operand *)n;
  t_00 = (c2_operand *)0x0;
  if (n->op == inner) {
    pcVar1 = *(c2_operand **)&n[1].kind;
    t_00 = (c2_operand *)n;
  }
  old = pcVar1;
  if (pcVar1->op == op) {
    if ((op == 0x171) || (op == 0x177)) {
      pcVar2 = ((pcVar1->u18).children)->next;
    }
    else {
      pcVar2 = (pcVar1->u18).children;
    }
    old = pcVar2;
    t_00 = pcVar1;
    if (pcVar2->op == inner) {
      old = (pcVar2->u18).children;
      t_00 = pcVar2;
    }
  }
  if (t_00 != (c2_operand *)0x0) {
    tuple_replace_src((c2_tuple *)t_00,old,new_op);
    simplify_node_algebraic((c2_tuple *)n,(c2_tuple *)0x0);
    return;
  }
  node_free((c2_node *)old);
  simplify_node_algebraic((c2_tuple *)new_op,(c2_tuple *)0x0);
  return;
}

