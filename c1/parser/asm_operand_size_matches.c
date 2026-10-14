int __cdecl asm_operand_size_matches(c1_asm_operand *operand,char size_class)

{
  if ((operand->flags & 1) != 0) {
    return (uint)(size_class == operand->size_class);
  }
  return 1;
}

