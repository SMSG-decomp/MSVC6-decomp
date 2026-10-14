c1_node * __cdecl
expr_check_pointer_arithmetic_zero_edx_fragment
          (c1_node *left,char opt_J,c1_node *right,c1_type *left_type,c1_node *right_cell,
          c1_node *left_cell,uint op_cell,c1_type *right_type,int op_code,c1_node *node)

{
  char cVar1;
  c1_node *left_00;
  char *pcVar2;
  bool bVar3;
  ushort uVar4;
  c1_node *pcVar5;
  
  uVar4 = right_type->code;
  if ((uVar4 & 0x2000) == 0) {
    if ((opt_J != '\0') && (((byte)uVar4 & 0xf) == 1)) {
      if ((uVar4 & 0xfff) != 0x11) goto code_r0x1042ddaa;
      if ((uVar4 & 0x1000) == 0) {
        pcVar5 = expr_check_binary_operand_types_signed_compare
                           ('\0',left,right,left_type,right_cell,left_cell,op_cell,right_type,
                            op_code,node);
        return pcVar5;
      }
    }
    bVar3 = true;
  }
  else {
code_r0x1042ddaa:
    bVar3 = false;
  }
  if (bVar3) {
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
        pcVar5 = expr_warn_signed_unsigned_compare(right_cell,left_cell,op_cell,op_code,node);
        return pcVar5;
      }
    }
    else {
      diag_warning(3,0x12,op_code);
      left = left_cell;
      right = right_cell;
    }
  }
LAB_1042dc9d:
  pcVar5 = expr_convert_operands_to_common_type(node,left,right);
  if (pcVar5 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  left_00 = pcVar5->left;
  expr_check_operand_conversion_unless_null(op_cell,left_00,pcVar5->right);
  uVar4 = left_00->type->code & 0x8f;
  if ((uVar4 != 0x8a) && (uVar4 != 0x8e)) {
    return pcVar5;
  }
  pcVar5 = expr_expand_member_pointer_compare(pcVar5);
  return pcVar5;
}

