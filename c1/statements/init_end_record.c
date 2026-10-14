void __cdecl init_end_record(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  
  if (PTR_1066b8f0 != (c1_node *)0x0) {
    label_emit_definition(PTR_1066b8f0);
    PTR_1066b8f0 = (c1_node *)0x0;
  }
  PTR_1065df70 = (c1_symbol *)0x0;
  if ((g_compile_flags_cc & 0x4000) != 0) {
    (*g_il_emitter->vtbl->end_block)();
    g_compile_flags_cc = g_compile_flags_cc & 0xffffbfff;
  }
  if (((g_compile_flags_c4 & 0x100000) != 0) && ((g_compile_flags_c4 & 0x40000) == 0)) {
    return;
  }
  if ((g_compile_flags_cc & 0x800) == 0) {
    if ((g_il_in.bytes.pbStart + g_il_in.bytes.cbAlloc < g_il_in.bytes.pbEnd + 2) &&
       (iVar2 = il_buffer_grow(&g_il_in.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_in.open = g_il_in.open & bVar1;
    if (g_il_in.open != 0) {
      *g_il_in.bytes.pbEnd = '\a';
      g_il_in.bytes.pbEnd = g_il_in.bytes.pbEnd + 1;
    }
    return;
  }
  return;
}

