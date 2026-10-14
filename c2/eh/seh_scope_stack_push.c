void __fastcall seh_scope_stack_push(c2_seh_try_scope *scope)

{
  if (g_seh_scope_depth < 0x14) {
    g_seh_scope_stack[g_seh_scope_depth] = scope;
    g_seh_scope_depth = g_seh_scope_depth + 1;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\except.c",0x54c);
}

