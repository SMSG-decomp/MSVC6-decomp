c1xx_il_emitter * __cdecl il_emitter_get_default(void)

{
  if (g_il_emitter_plain == (c1xx_il_emitter *)0x0) {
    g_il_emitter_plain = __2_YAPAXI_Z(4);
    if (g_il_emitter_plain != (c1xx_il_emitter *)0x0) {
      g_il_emitter_plain->vtbl = (c1xx_il_emitter_vtbl *)&PTR_vtable_nop_104bc4e8;
      return g_il_emitter_plain;
    }
    g_il_emitter_plain = (c1xx_il_emitter *)0x0;
  }
  return g_il_emitter_plain;
}

