c1_node * __cdecl expr_check_type_as_expression_4(uint op,c1_node *node)

{
  c1_u16 cVar1;
  c1_node *node_00;
  c1_node *pcVar2;
  
  node_00 = fold_static_const_member(node);
  if (node_00->op == 0x98) {
    diag_error(0x113,node_00->left);
    return (c1_node *)0x0;
  }
  cVar1 = node_00->type->code;
  if (((cVar1 == 0x80c) || (pcVar2 = node_00, cVar1 == 0x80e)) &&
     ((pcVar2 = expr_resolve_function_address((c1_type *)0x0,node_00), pcVar2 == (c1_node *)0x0 ||
      ((pcVar2->kind & 8) != 0)))) {
    expr_report_function_operand((c1_u8)op,node_00);
    return pcVar2;
  }
  return pcVar2;
}

