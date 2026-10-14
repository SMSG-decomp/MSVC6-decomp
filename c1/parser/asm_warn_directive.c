void __cdecl asm_warn_directive(short directive,uint value)

{
  if (directive == 0x1bf) {
    if (g_asm_after_period != 0) {
      diag_warning(3,0x194);
    }
    if ((((int)value < 2) || (0x10 < (int)value)) || ((value & value - 1) != 0)) {
      diag_error(0x19d,g_last_name);
    }
    else {
      g_asm_align_size = (ushort)value;
    }
  }
  else {
    if (directive != 0x1c0) {
      g_asm_after_period = 0;
      return;
    }
    if (g_asm_after_period != 0) {
      diag_warning(3,0x194);
    }
    if (g_asm_operand_index != 0) {
      diag_warning(1,0x196);
    }
    g_asm_align_size = 2;
  }
  il_emit_pragma_or_segment_record(0x18);
  g_asm_after_period = 0;
  return;
}

