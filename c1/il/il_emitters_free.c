void il_emitters_free(void)

{
  c1_il_emitter_browse *pcVar1;
  c1_il_emitter_browse *pcVar2;
  
  pcVar2 = g_il_emitter_browse;
  if (g_il_emitter_browse != (c1_il_emitter_browse *)0x0) {
    pcVar1 = g_il_emitter_browse + 1;
    g_il_emitter_browse->vtbl = (c1_il_emitter_browse_vtbl *)&PTR_il_emitter_browse_finish_106539c0;
    free(pcVar1->vtbl);
    __3_YAXPAX_Z(pcVar2);
    g_il_emitter_browse = (c1_il_emitter_browse *)0x0;
  }
  if (g_il_emitter_plain != (c1_il_emitter *)0x0) {
    __3_YAXPAX_Z(g_il_emitter_plain);
    g_il_emitter_plain = (c1_il_emitter *)0x0;
  }
  return;
}

