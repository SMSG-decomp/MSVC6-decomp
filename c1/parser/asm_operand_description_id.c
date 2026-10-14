int __cdecl asm_operand_description_id(void)

{
  if (g_asm_operands_begun != 0) {
    return g_asm_operand_index + 0x140;
  }
  return 0x143;
}

