void __cdecl tu_end_flush(void)

{
  c1xx_emitter_suspend *pcVar1;
  int iVar2;
  
  tu_emit_vcall_thunks();
  tu_emit_pending_table_15d0();
  tu_emit_pending_vtables();
  if (g_rtti != '\0') {
    rtti_emit_pending_descriptors();
  }
  pcVar1 = g_emitter_suspend;
  if (g_emitter_suspend->depth == 0) {
    g_emitter_suspend->saved = g_il_emitter;
    g_il_emitter = il_emitter_get_default();
    pcVar1->enabled = '\0';
  }
  pcVar1->depth = pcVar1->depth + 1;
  vector_for_each(PTR_104d1b4c,tu_emit_guid_object);
  pcVar1 = g_emitter_suspend;
  PTR_104d1b4c = (c1_vector *)0x0;
  iVar2 = g_emitter_suspend->depth + -1;
  g_emitter_suspend->depth = iVar2;
  if (iVar2 == 0) {
    g_il_emitter = pcVar1->saved;
    pcVar1->enabled = '\x01';
  }
  return;
}

