c1_node * __cdecl
fold_binary_constant_expression_fragment
          (uint code,int is_unsigned,int hi,uint lo,c1_node *result,char long_operand,
          c1_type *result_type,int size)

{
  ushort uVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_type *pcVar4;
  int iVar5;
  short sVar6;
  
  uVar1 = (ushort)code & 0x8f;
  if ((uVar1 == 0x86) || (uVar1 == 0x82)) {
    result->left = (void *)lo;
    result->right = (void *)hi;
    return result;
  }
  if (result_type != (c1_type *)0x0) {
    size = type_size_scalar(result_type);
  }
  sVar6 = (short)is_unsigned;
  if (size == 8) {
    pcVar4 = g_type_uint64;
    g_constant_value_high = hi;
    if (sVar6 == 0) {
      pcVar4 = g_type_int64;
    }
  }
  else {
    if (sVar6 == 0) {
      iVar5 = (int)lo >> 0x1f;
    }
    else {
      iVar5 = 0;
    }
    if (result_type == (c1_type *)0x0) {
      if (long_operand == '\0') {
LAB_1060d2f4:
        pcVar4 = g_type_unsigned_int;
        if (sVar6 == 0) {
          pcVar4 = g_type_int;
        }
        g_constant_value = lo;
        g_constant_value_high = iVar5;
        pcVar2 = tree_new_constant(pcVar4,&g_constant_value,g_expr_arena_index);
        return pcVar2;
      }
    }
    else {
      iVar3 = type_size_scalar(result_type);
      if ((iVar3 != 4) || ((result_type->code & 0x1f) == 0x14)) goto LAB_1060d2f4;
    }
    pcVar4 = g_type_unsigned_long;
    g_constant_value_high = iVar5;
    if (sVar6 == 0) {
      pcVar4 = g_type_long;
    }
  }
  g_constant_value = lo;
  pcVar2 = tree_new_constant(pcVar4,&g_constant_value,g_expr_arena_index);
  return pcVar2;
}

