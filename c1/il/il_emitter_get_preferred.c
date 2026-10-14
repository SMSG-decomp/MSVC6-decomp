c1_il_emitter * il_emitter_get_preferred(void)

{
  c1_il_emitter *emitter;
  
  emitter = (c1_il_emitter *)g_il_emitter_browse;
  if (g_il_emitter_browse == (c1_il_emitter_browse *)0x0) {
    emitter = g_il_emitter_plain;
  }
  return emitter;
}

