c1_node * __cdecl pm_build_simple_data_member_access(c1_node *operand)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  c1_type *type;
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  pcVar2 = *(c1_type **)(*(int *)((int)operand->left + 4) + 4);
  type = *(c1_type **)(*(int *)((int)operand->right + 4) + 4);
  if ((pcVar2->code & 0x8f) == 0x83) {
    pcVar2 = type_skip_arrays(pcVar2->base);
  }
  uVar1 = pcVar2->flags & 0x3e0;
  if ((type->flags & uVar1) != uVar1) {
    type_code = type->code;
    type_flags = type->flags;
    local_10.base = type->base;
    local_10.flags = type_flags | uVar1;
    local_10.code = type_code;
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    type = type_intern(&local_10);
  }
  operand->op = 'Q';
  operand->type = type;
  pcVar3 = tree_new_unary('=',type,operand);
  return pcVar3;
}

