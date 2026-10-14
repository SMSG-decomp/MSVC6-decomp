void __cdecl init_emit_relocations_to_buffer(c1_symbol *key,c1_node *node)

{
  byte bVar1;
  int iVar2;
  
  init_emit_symbol_data(key,node,&g_il_pending_init);
  if ((g_compile_flags_cc & 0x800) == 0) {
    if ((g_il_pending_init.bytes.start + g_il_pending_init.bytes.size <
         g_il_pending_init.bytes.cur + 2) &&
       (iVar2 = il_buffer_grow(&g_il_pending_init.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_pending_init.open = g_il_pending_init.open & bVar1;
    if (g_il_pending_init.open != 0) {
      *g_il_pending_init.bytes.cur = '\a';
      g_il_pending_init.bytes.cur = g_il_pending_init.bytes.cur + 1;
    }
    return;
  }
  return;
}

