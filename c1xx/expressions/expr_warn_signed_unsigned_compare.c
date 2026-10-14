c1_node * __cdecl
expr_warn_signed_unsigned_compare
          (c1_node *right_cell,c1_node *left_cell,uint op_cell,int op_code,c1_node *node)

{
  c1_node *left;
  ushort uVar1;
  c1_node *pcVar2;
  
  diag_warning(3,0x12,op_code);
  pcVar2 = expr_convert_operands_to_common_type(node,left_cell,right_cell);
  if (pcVar2 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  left = pcVar2->left;
  expr_check_operand_conversion_unless_null(op_cell,left,pcVar2->right);
  uVar1 = left->type->code & 0x8f;
  if ((uVar1 != 0x8a) && (uVar1 != 0x8e)) {
    return pcVar2;
  }
  pcVar2 = expr_expand_member_pointer_compare(pcVar2);
  return pcVar2;
}

