c1_u8 __cdecl asm_operand_mode(int *operand)

{
  byte bVar1;
  c1_symbol *pcVar2;
  
  bVar1 = g_asm_kind_mode[*(byte *)(operand + 2) & 0x1f];
  switch(bVar1) {
  case 1:
    if ((*(byte *)((int)operand + 10) & 0xc0) == 0xc0) {
      return '\x14';
    }
    break;
  case 3:
    if (*operand == 0) {
      operand._0_1_ = 0x10;
      bVar1 = (byte)operand;
    }
    break;
  case 4:
    if (*(char *)((int)operand + 0xb) != '?') {
      return '\x06';
    }
    break;
  case 5:
    if (*(char *)((int)operand + 0xb) != '?') {
      return '\a';
    }
    break;
  case 8:
    pcVar2 = (c1_symbol *)*operand;
    operand._0_1_ = bVar1;
    if ((pcVar2 == g_builtin_label_1) &&
       ((((g_asm_operand_form == 0x10 || (g_asm_operand_form == 0xf)) ||
         (g_asm_operand_form == 0x1b)) || (g_asm_operand_form == 0xe)))) {
      operand._0_1_ = 0xc;
    }
    bVar1 = (byte)operand;
    if ((pcVar2 == g_builtin_label_10) && ((g_asm_operand_form == 6 || (g_asm_operand_form == 0xd)))
       ) {
      return '\v';
    }
  }
  operand._0_1_ = bVar1;
  return (byte)operand;
}

