c1_node * __cdecl fold_float_constant(c1_node *node,float_const *a,float_const *b)

{
  ushort uVar1;
  int iVar2;
  c1_node *pcVar3;
  ushort uVar4;
  float_const result;
  
  switch(node->op) {
  case '2':
    iVar2 = float_const_compare_mask(6,(float10 *)a,(float10 *)&g_float_zero);
    if ((iVar2 == 0) ||
       (iVar2 = float_const_compare_mask(6,(float10 *)b,(float10 *)&g_float_zero), iVar2 == 0)) {
      g_constant_value = (void *)0x0;
    }
    else {
      g_constant_value = (void *)0x1;
    }
    g_constant_value_high = 0;
    pcVar3 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
    return pcVar3;
  default:
    return node;
  case '9':
    iVar2 = float_const_compare_mask(6,(float10 *)b,(float10 *)&g_float_zero);
    if (iVar2 == 0) {
      node->kind = '@';
      return node;
    }
    iVar2 = fold_float_store_result_3(a,b,&result);
    goto LAB_10632d73;
  case ';':
    uVar1 = 1;
    break;
  case '>':
    uVar1 = 2;
    break;
  case '?':
    uVar1 = 3;
    break;
  case 'D':
    uVar1 = 4;
    break;
  case 'E':
    uVar1 = 5;
    break;
  case 'F':
    iVar2 = float_fold_subtract_constants(a,b,&result);
    goto joined_r0x10632cc5;
  case 'J':
    iVar2 = float_fold_multiply_constants(a,b,&result);
LAB_10632d73:
    if (iVar2 != 0) {
LAB_10632cc7:
      diag_warning(2,0x38);
    }
LAB_10632cf0:
    if (g_opt_Op != '\0') {
      fold_float_round_to_width(&result,stack0xfffffffa & 0xffff);
    }
    g_constant_value = record3_new_from((int *)&result,g_expr_arena_index);
    uVar1 = node->type->code;
    uVar4 = uVar1 & 0xfff;
    if (uVar4 == 0x27) {
      pcVar3 = tree_new_constant(g_type_double,(c1_u32 *)&g_constant_value,g_expr_arena_index);
      return pcVar3;
    }
    if (uVar4 == 0x26) {
      pcVar3 = tree_new_constant(g_type_float,(c1_u32 *)&g_constant_value,g_expr_arena_index);
      return pcVar3;
    }
    if (((byte)uVar1 & 0x28) == 0x28) {
      pcVar3 = tree_new_constant(g_type_long_double,(c1_u32 *)&g_constant_value,g_expr_arena_index);
      return pcVar3;
    }
    return (c1_node *)0x0;
  case 'L':
    uVar1 = 6;
    break;
  case 'O':
    iVar2 = float_const_compare_mask(6,(float10 *)a,(float10 *)&g_float_zero);
    if (iVar2 == 0) {
      iVar2 = float_const_compare_mask(6,(float10 *)b,(float10 *)&g_float_zero);
      g_constant_value = (void *)0x0;
      if (iVar2 == 0) goto LAB_10632c80;
    }
    g_constant_value = (void *)0x1;
LAB_10632c80:
    g_constant_value_high = 0;
    pcVar3 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
    return pcVar3;
  case 'Q':
    iVar2 = float_fold_add_constants(a,b,&result);
joined_r0x10632cc5:
    if (iVar2 == 0) goto LAB_10632cf0;
    goto LAB_10632cc7;
  }
  g_constant_value = (void *)float_const_compare_mask(uVar1,(float10 *)a,(float10 *)b);
  g_constant_value_high = (int)g_constant_value >> 0x1f;
  pcVar3 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
  return pcVar3;
}

