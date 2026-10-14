c1_node * __cdecl expr_strip_value_conversions_check_name(byte mark,c1_node *node,c1_node *operand)

{
  c1_node *pcVar1;
  byte bVar2;
  short n;
  byte *pbVar3;
  
  if ((operand->type->code & 0x800) == 0) {
    pbVar3 = operand->left;
    n = 0x113;
  }
  else {
    if (operand->op != '\x06') {
      return node;
    }
    pbVar3 = operand->left;
    if ((*pbVar3 & 0x1f) != 0x12) {
      return node;
    }
    bVar2 = **(byte **)(**(int **)(pbVar3 + 0x14) + 8) & 0x1f;
    if ((bVar2 == 0x11) || (bVar2 == mark)) {
      pcVar1 = (c1_node *)expr_build_unary(0x31,node);
      return pcVar1;
    }
    n = 0x255;
  }
  diag_error(n,pbVar3);
  operand->kind = operand->kind | mark;
  node->kind = node->kind | mark;
  return node;
}

