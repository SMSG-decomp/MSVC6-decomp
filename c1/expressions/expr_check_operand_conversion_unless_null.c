void __cdecl expr_check_operand_conversion_unless_null(c1_u8 op,c1_node *left,c1_node *right)

{
  ushort uVar1;
  
  if (((left != (c1_node *)0x0) && (right != (c1_node *)0x0)) &&
     (((left->kind & 0x80) == 0 ||
      (((uVar1 = right->type->code & 0x8f, uVar1 != 0x83 && (uVar1 != 0x82)) && (uVar1 != 0x86))))))
  {
    conv_check_conversion_to_type(op,left->type,right);
  }
  return;
}

