c1_node * __cdecl expr_build_sizeof(c1_node *operand)

{
  c1_type *type;
  byte bVar1;
  c1_node *pcVar2;
  
  if ((operand->kind & 7) == 4) {
    type = *(c1_type **)((int)operand->left + 0x14);
    bVar1 = (byte)type->code;
    if ((bVar1 & 0x8f) == 0x83) {
      pcVar2 = expr_sizeof_type(type);
      return pcVar2;
    }
    if ((bVar1 & 0x83) != 0x81) goto LAB_10419cc1;
  }
  else if ((g_token_class[operand->op] == '=') && (*(char *)operand->left == '5')) {
    diag_error(0x46);
    return (c1_node *)0x0;
  }
  if (operand->type->code == 0x4086) {
    diag_error(0x46);
    return (c1_node *)0x0;
  }
LAB_10419cc1:
  pcVar2 = expr_sizeof_type(operand->type);
  return pcVar2;
}

