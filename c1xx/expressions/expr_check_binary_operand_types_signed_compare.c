c1_node * __cdecl
expr_check_binary_operand_types_signed_compare
          (char left_signed,c1_node *left,c1_node *right,c1_type *left_type,c1_node *right_cell,
          c1_node *left_cell,uint op_cell,c1_type *right_type,int op_code,c1_node *node)

{
  char cVar1;
  c1_node *left_00;
  char *pcVar2;
  ushort uVar3;
  c1_node *pcVar4;
  
  if (left_signed != '\0') {
    if ((left->op == 'd') && (left_type == g_type_int)) {
      pcVar2 = *(char **)((int)left->left + 4);
      cVar1 = *pcVar2;
      while (cVar1 < '\0') {
        pcVar2 = *(char **)(pcVar2 + 4);
        cVar1 = *pcVar2;
      }
      if ((pcVar2[1] & 0x20U) != 0) goto LAB_1042dc9d;
    }
    if ((right->op == 'd') && (right_type == g_type_int)) {
      pcVar2 = *(char **)((int)right->left + 4);
      cVar1 = *pcVar2;
      while (cVar1 < '\0') {
        pcVar2 = *(char **)(pcVar2 + 4);
        cVar1 = *pcVar2;
      }
      if ((pcVar2[1] & 0x20U) == 0) {
        pcVar4 = expr_warn_signed_unsigned_compare(right_cell,left_cell,op_cell,op_code,node);
        return pcVar4;
      }
    }
    else {
      diag_warning(3,0x12,op_code);
      left = left_cell;
      right = right_cell;
    }
  }
LAB_1042dc9d:
  pcVar4 = expr_convert_operands_to_common_type(node,left,right);
  if (pcVar4 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  left_00 = pcVar4->left;
  expr_check_operand_conversion_unless_null(op_cell,left_00,pcVar4->right);
  uVar3 = left_00->type->code & 0x8f;
  if ((uVar3 != 0x8a) && (uVar3 != 0x8e)) {
    return pcVar4;
  }
  pcVar4 = expr_expand_member_pointer_compare(pcVar4);
  return pcVar4;
}

