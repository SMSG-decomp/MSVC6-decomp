void __cdecl class_check_member_pointer_representation(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  byte bVar2;
  
  if (((sym->kind & 0x1f) == 4) && ((g_compile_flags_c8 & 0x700000) != 0)) {
    bVar2 = ((sym->detail).cls)->pm_model;
    if ((bVar2 & 8) == 0) {
      ((sym->detail).cls)->pm_model = ((byte)(g_compile_flags_c8 >> 0x14) ^ bVar2) & 7 ^ bVar2;
      pcVar1 = &((sym->detail).cls)->pm_model;
      *pcVar1 = *pcVar1 | 8;
    }
    else if ((g_compile_flags_c8 >> 0x14 & 7) != (bVar2 & 7)) {
      diag_error(0x11e,sym,g_member_pointer_model_names[bVar2 & 7]);
      g_compile_flags_c8 = g_compile_flags_c8 & 0xff8fffff;
      return;
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0xff8fffff;
  }
  return;
}

