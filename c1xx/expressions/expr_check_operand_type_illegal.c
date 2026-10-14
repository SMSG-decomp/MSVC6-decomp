char __cdecl expr_check_operand_type_illegal(c1_u8 op,c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code & 0x8f;
  if ((uVar1 != 0x8a) && (uVar1 != 0x8e)) {
    return '\0';
  }
  diag_error(0xab,op,type);
  return '\x01';
}

