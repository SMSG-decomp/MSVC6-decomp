c1_node * __cdecl fold_float_constant(c1_node *node,void *a,void *b)

{
  ushort uVar1;
  c1_node *pcVar2;
  int iVar3;
  ushort uVar4;
  undefined1 local_10 [16];
  
  switch(node->op) {
  case '2':
    iVar3 = float_const_compare_mask(6,a,&g_float_zero);
    if ((iVar3 == 0) || (iVar3 = float_const_compare_mask(6,b,&g_float_zero), iVar3 == 0)) {
      g_constant_value = (void *)0x0;
    }
    else {
      g_constant_value = (void *)0x1;
    }
    g_constant_value_high = 0;
    pcVar2 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
    return pcVar2;
  default:
    return node;
  case '9':
    iVar3 = float_const_compare_mask(6,b,&g_float_zero);
    if (iVar3 == 0) {
      node->kind = '@';
      return node;
    }
    iVar3 = fold_float_store_result_3(a,b,local_10);
    goto joined_r0x1046a685;
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
    iVar3 = float_fold_subtract_constants(a,b,(c1xx_float_const *)local_10);
    if (iVar3 == 0) goto LAB_104518e6;
    goto LAB_1046a68b;
  case 'J':
    iVar3 = float_fold_multiply_constants(a,b,(float10 *)local_10);
    goto joined_r0x1046a685;
  case 'L':
    uVar1 = 6;
    break;
  case 'O':
    iVar3 = float_const_compare_mask(6,a,&g_float_zero);
    if (iVar3 == 0) {
      iVar3 = float_const_compare_mask(6,b,&g_float_zero);
      g_constant_value = (void *)0x0;
      if (iVar3 == 0) goto LAB_1046a640;
    }
    g_constant_value = (void *)0x1;
LAB_1046a640:
    g_constant_value_high = 0;
    pcVar2 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
    return pcVar2;
  case 'Q':
    iVar3 = float_fold_add_constants(a,b,(float10 *)local_10);
joined_r0x1046a685:
    if (iVar3 != 0) {
LAB_1046a68b:
      diag_warning(2,0x38);
    }
LAB_104518e6:
    if (g_opt_Op != '\0') {
      fold_float_round_to_width((int)local_10,local_10._10_4_ & 0xffff);
    }
    g_constant_value = record3_new_from((int *)local_10,g_expr_arena_index);
    uVar1 = node->type->code;
    uVar4 = uVar1 & 0xfff;
    if (uVar4 == 0x27) {
      pcVar2 = tree_new_constant(g_type_double,&g_constant_value,g_expr_arena_index);
      return pcVar2;
    }
    if (uVar4 == 0x26) {
      pcVar2 = tree_new_constant(g_type_float,&g_constant_value,g_expr_arena_index);
      return pcVar2;
    }
    if (((byte)uVar1 & 0x28) == 0x28) {
      pcVar2 = tree_new_constant(g_type_long_double,&g_constant_value,g_expr_arena_index);
      return pcVar2;
    }
    return (c1_node *)0x0;
  }
  g_constant_value = (void *)float_const_compare_mask(uVar1,a,b);
  g_constant_value_high = (int)g_constant_value >> 0x1f;
  pcVar2 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
  return pcVar2;
}

