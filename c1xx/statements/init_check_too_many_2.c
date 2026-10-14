void init_check_too_many_2(void)

{
  int iVar1;
  uint uVar2;
  
  init_construct_remaining_elements();
  if (-1 < g_init_brace_depth) {
    iVar1 = sym_has_scalar_type(g_init_level->sym);
    if (iVar1 == 0) {
      uVar2 = init_descend_to_member(0);
      if (uVar2 == 0) {
        if (g_init_too_many_reported != 0) {
          return;
        }
        g_init_too_many_reported = 1;
        diag_error(0x4e);
        return;
      }
    }
    else {
      init_push_brace_level(g_init_level->sym);
    }
    g_init_level->flags = '\x01';
    iVar1 = sym_has_scalar_type(g_init_level->sym);
    if (iVar1 != 0) {
      g_init_level->flags = g_init_level->flags | 4;
    }
  }
  return;
}

