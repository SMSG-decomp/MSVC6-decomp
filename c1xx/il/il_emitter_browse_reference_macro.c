void __thiscall il_emitter_browse_reference_macro(c1xx_il_emitter_browse *this,int *macro)

{
  if (((g_compile_flags_cc & 0x8000) == 0) && ((*(uint *)(*macro + 8) & 0x200000) == 0)) {
    browse_add_record(0x12,macro);
  }
  return;
}

