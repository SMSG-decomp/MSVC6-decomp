void __cdecl init_nested_brace_begin(void)

{
  int iVar1;
  
  if (-1 < g_init_brace_depth) {
    iVar1 = sym_has_scalar_type(g_init_level->cursor);
    if (iVar1 == 0) {
      iVar1 = init_check_undefined_type((c1_node *)0x0);
      if (iVar1 == 0) {
        if (g_init_too_many_reported != 0) {
          return;
        }
        g_init_too_many_reported = 1;
        diag_error(0x4e);
        return;
      }
    }
    else {
      init_push_brace_level(g_init_level->cursor);
    }
    g_init_level->flags = '\x01';
    iVar1 = sym_has_scalar_type(g_init_level->cursor);
    if (iVar1 != 0) {
      g_init_level->flags = g_init_level->flags | 4;
    }
  }
  return;
}

