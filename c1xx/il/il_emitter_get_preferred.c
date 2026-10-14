c1xx_il_emitter * __cdecl il_emitter_get_preferred(void)

{
  c1xx_il_emitter *emitter;
  
  emitter = (c1xx_il_emitter *)g_il_emitter_browse;
  if (g_il_emitter_browse == (c1xx_il_emitter_browse *)0x0) {
    emitter = g_il_emitter_plain;
  }
  return emitter;
}

