void __cdecl il_emitters_create(char *browse_file)

{
  c1xx_il_emitter_browse *pcVar1;
  char *pcVar2;
  
  if (browse_file == (char *)0x0) {
    g_il_emitter_plain = __2_YAPAXI_Z(4);
    if (g_il_emitter_plain != (c1xx_il_emitter *)0x0) {
      g_il_emitter_plain->vtbl = (c1xx_il_emitter_vtbl *)&PTR_vtable_nop_104bc4e8;
      return;
    }
    g_il_emitter_plain = (c1xx_il_emitter *)0x0;
    return;
  }
  g_emitter_region_mode = 3;
  pcVar1 = __2_YAPAXI_Z(0xc);
  if (pcVar1 != (c1xx_il_emitter_browse *)0x0) {
    pcVar1->vtbl = (c1xx_il_emitter_browse_vtbl *)&PTR_il_emitter_browse_finish_104c4db4;
    pcVar2 = _strdup(browse_file);
    pcVar1->sbr_name = pcVar2;
    g_il_emitter_browse = pcVar1;
    return;
  }
  g_il_emitter_browse = (c1xx_il_emitter_browse *)0x0;
  return;
}

