uint32_t __fastcall operand_is_unsafe_for_if_convert(c2_operand *op)

{
  switch(*(undefined1 *)((int)operand_is_unsafe_for_if_convert_jump_table + op->kind + 0xb)) {
  case 0:
    return (op->flags & 0x40) >> 6;
  case 1:
    return 1;
  case 2:
    return 0;
  }
}

