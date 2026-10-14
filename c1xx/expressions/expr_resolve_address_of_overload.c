c1_node * __cdecl expr_resolve_address_of_overload(c1_node *node)

{
  byte *pbVar1;
  c1_node *pcVar2;
  byte bVar3;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  bVar3 = node->kind;
  pcVar2 = node;
  if ((bVar3 & 8) == 0) {
    while ((bVar3 & 7) == 7) {
      switch(pcVar2->op) {
      case 0xb5:
      case 0xb6:
      case 0xb7:
      case 0xc5:
        pcVar2 = pcVar2->left;
      }
      bVar3 = pcVar2->kind;
    }
    if (((pcVar2->kind & 7) == 0) && (pcVar2->op == 0x98)) {
      pcVar2 = expr_strip_value_conversions_check_name(8,node,pcVar2);
      return pcVar2;
    }
    if ((pcVar2->op == '\x06') && (pbVar1 = pcVar2->left, (*pbVar1 & 0x1f) == 0x12)) {
      bVar3 = **(byte **)(**(int **)(pbVar1 + 0x14) + 8) & 0x1f;
      if ((bVar3 == 0x11) || (bVar3 == 8)) {
        pcVar2 = (c1_node *)expr_build_unary(0x31,node);
        return pcVar2;
      }
      diag_error(0x255,pbVar1);
      pcVar2->kind = pcVar2->kind | 8;
      node->kind = node->kind | 8;
    }
  }
  return node;
}

