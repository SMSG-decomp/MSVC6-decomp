void __fastcall set_current_scope(c2_scope_table *scope)

{
  if (scope->parent == &g_global_scope) {
    g_cur_scope = scope;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x6e3);
}

