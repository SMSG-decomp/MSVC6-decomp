c1_node * __cdecl expr_check_based_operator(c1_node *right,c1_node *left)

{
  char cVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_type local_10;
  
  if ((right == (c1_node *)0x0) || (left == (c1_node *)0x0)) {
    return (c1_node *)0x0;
  }
  pcVar4 = left->type;
  if (((-1 < (char)pcVar4->code) || (pcVar4 == (c1_type *)0x0)) ||
     (((pcVar4->flags & 0x18) != 8 && ((left->kind & 0x80) == 0)))) {
    diag_error(0xd7);
    return left;
  }
  pcVar4 = right->type;
  if ((char)pcVar4->code < '\0') {
    if ((*(byte *)(-(uint)((pcVar4->code & 0x80) != 0) & (uint)pcVar4) & 0x8f) != 0x82) {
LAB_10481c8c:
      diag_error_C2296_or_C2297('^',1,pcVar4);
      return left;
    }
    if ((*(byte *)((-(uint)((pcVar4->code & 0x80) != 0) & (uint)pcVar4) + 2) & 8) != 0) {
      diag_error_C2296_or_C2297('^',1,pcVar4);
      return left;
    }
  }
  else {
    cVar1 = (char)pcVar4->code;
    pcVar2 = pcVar4;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    if ((~pcVar2->code & 0x400) != 0) goto LAB_10481c8c;
  }
  pcVar3 = tree_new_node('^',left,right,(c1_type *)0x0);
  if ((left->kind & 0x80) != 0) {
    pcVar3->kind = pcVar3->kind | 0x80;
  }
  local_10.debug_index = 0;
  pcVar4 = left->type->base;
  local_10.code = 0x82;
  local_10.flags = decl_apply_default_calling_convention(0x82,0);
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = pcVar4;
  pcVar4 = type_intern(&local_10);
  pcVar3->type = pcVar4;
  return pcVar3;
}

