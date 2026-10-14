c1_node * __cdecl class_check_operator_global_form(uint op,c1_node *node2)

{
  c1_node *left;
  c1_u8 cVar1;
  c1_u8 cVar2;
  int iVar3;
  c1_node *pcVar4;
  
  if (node2 == (c1_node *)0x0) {
    diag_error(0x329,g_token_spelling[op & 0xff]);
    return (c1_node *)0x0;
  }
  pcVar4 = node2->left;
  left = node2->link->left;
  iVar3 = expr_count_call_arguments(node2);
  cVar1 = (c1_u8)op;
  if (iVar3 == 1) {
    cVar1 = operator_unary_form(cVar1);
    if (cVar1 == '\x01') {
      diag_error(0x33b,op & 0xff);
      return (c1_node *)0x0;
    }
    pcVar4 = expr_build_builtin_unary(op,left);
    return pcVar4;
  }
  if (iVar3 != 2) {
    if (iVar3 < 1) {
      diag_error(0x329,op & 0xff);
      return (c1_node *)0x0;
    }
    diag_error(0x326,op & 0xff);
    return (c1_node *)0x0;
  }
  cVar2 = operator_binary_form(cVar1);
  if (cVar2 == '\x01') {
    diag_error(0x33c,op & 0xff);
    return (c1_node *)0x0;
  }
  pcVar4 = expr_build_builtin_binary(cVar1,left,pcVar4);
  return pcVar4;
}

