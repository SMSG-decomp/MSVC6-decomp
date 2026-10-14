int __cdecl func_wants_inline(c1_symbol *fn)

{
  int iVar1;
  
  iVar1 = 1;
  if ((((fn->flags21 & 1) == 0) && (((byte)g_compile_flags_c4 & 0x20) == 0)) &&
     ((g_inline_level != 2 || (g_function_auto_inline == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}

