int __cdecl asm_slot_size_matches(c1_asm_operand_slot *slot,char size_class)

{
  if ((slot->size_given & 1) != 0) {
    return (uint)(size_class == slot->size_class);
  }
  return 1;
}

