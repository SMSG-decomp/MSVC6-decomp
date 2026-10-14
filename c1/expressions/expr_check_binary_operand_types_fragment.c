c1_node * __cdecl expr_check_binary_operand_types_fragment(c1_node *right,c1_type *type)

{
  c1_type *type_00;
  ushort uVar1;
  c1_u8 in_stack_00000010;
  
  diag_error_C2296_or_C2297(in_stack_00000010,1,type);
  type_00 = right->type;
  if (((((type_00->code & 0x130) == 0) && (uVar1 = type_00->code & 0x8f, uVar1 != 0x83)) &&
      (uVar1 != 0x82)) && (uVar1 != 0x86)) {
    diag_error_C2296_or_C2297(in_stack_00000010,2,type_00);
  }
  return (c1_node *)0x0;
}

