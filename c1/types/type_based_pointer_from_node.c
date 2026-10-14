c1_node * __cdecl type_based_pointer_from_node(c1_type *type,c1_node *left)

{
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_type local_10;
  
  if ((left->kind & 0x80) != 0) {
    local_10.debug_index = 0;
    pcVar2 = type->base;
    local_10.code = 0x82;
    local_10.flags = decl_apply_default_calling_convention(0x82,0);
    local_10.extra.sym = (c1_symbol *)0x0;
    local_10.base = pcVar2;
    pcVar2 = type_intern(&local_10);
    left->type = pcVar2;
    return left;
  }
  iVar3 = type_based_on_pointer_variable(type);
  if ((iVar3 != 0) &&
     (((uVar1 = left->type->code & 0x8f, uVar1 == 0x83 || (uVar1 == 0x82)) || (uVar1 == 0x86)))) {
    pcVar4 = type_based_base(type);
    pcVar4 = tree_new_node('_',left,pcVar4,type);
    return pcVar4;
  }
  pcVar2 = left->type;
  if (((char)pcVar2->code < '\0') &&
     ((*(byte *)(((uint)pcVar2 & -(uint)((pcVar2->code & 0x80) != 0)) + 2) & 8) != 0)) {
    left->type = type;
  }
  else {
    left = tree_new_cast(type,left);
  }
  if ((type->flags & 0x18) == 8) {
    left = expr_based_pointer_fixup(left);
  }
  return left;
}

