void __cdecl il_emitters_discard(void)

{
  char **ppcVar1;
  c1xx_il_emitter_browse *pcVar2;
  
  if (g_il_emitter_browse != (c1xx_il_emitter_browse *)0x0) {
    (*g_il_emitter_browse->vtbl->discard)(g_il_emitter_browse);
    pcVar2 = g_il_emitter_browse;
    if (g_il_emitter_browse != (c1xx_il_emitter_browse *)0x0) {
      ppcVar1 = &g_il_emitter_browse->sbr_name;
      g_il_emitter_browse->vtbl =
           (c1xx_il_emitter_browse_vtbl *)&PTR_il_emitter_browse_finish_104c4db4;
      free(*ppcVar1);
      __3_YAXPAX_Z(pcVar2);
    }
    g_il_emitter_browse = (c1xx_il_emitter_browse *)0x0;
  }
  if (g_il_emitter_plain != (c1xx_il_emitter *)0x0) {
    __3_YAXPAX_Z(g_il_emitter_plain);
    g_il_emitter_plain = (c1xx_il_emitter *)0x0;
  }
  return;
}

