c1xx_decl_specifiers * decl_specifiers_current(void)

{
  c1xx_decl_specifiers *pcVar1;
  
  if ((g_paren_level_flags[g_paren_depth] & 1) != 0) {
    return g_paren_level_declspecs + g_paren_depth;
  }
  pcVar1 = decl_specifiers_default((void *)0x0);
  return pcVar1;
}

