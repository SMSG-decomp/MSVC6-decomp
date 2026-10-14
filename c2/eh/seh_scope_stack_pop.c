void seh_scope_stack_pop(void)

{
  if (0 < g_seh_scope_depth) {
    g_seh_scope_depth = g_seh_scope_depth + -1;
    g_seh_scope_stack[g_seh_scope_depth] = (c2_seh_try_scope *)0x0;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\except.c",0x552);
}

