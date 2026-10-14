void __cdecl pch_auto_start_recording(void)

{
  c1_vector *pcVar1;
  int iVar2;
  c1_u8 *text;
  short sVar3;
  
  if (g_pch_creating == 0) {
    g_pch_directive_mode = 1;
    if (g_pch_file != (FILE *)0x0) {
      _g_io_result = fclose((FILE *)g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
      }
    }
    if (g_pch_records_buffer != (int *)0x0) {
      mem_free(g_pch_records_buffer);
      g_pch_record_cursor = (int *)0x0;
      g_pch_records_buffer = (int *)0x0;
    }
    g_pch_creating = 1;
    block_list_open_or_rewind((c1_byte_block_list **)&g_pch_record_list);
    iVar2 = (*g_idb->vtbl->idb_begin_unit)(g_idb,&g_ilstore_status);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\pch.c",0x275);
    }
    if (g_c9il_mode == '\0') {
      ilstore_open_for_gi();
    }
    g_il_emitter = il_emitter_get_preferred();
    (*g_il_emitter->vtbl->open)(g_il_emitter);
    il_emitter_begin_region_at_top_level(g_il_emitter,'\x01');
    if (((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) && (g_opt_Zi != '\0')) {
      debug_begin('\0');
    }
    pcVar1 = g_define_list;
    for (sVar3 = 0; (pcVar1 != (c1_vector *)0x0 && ((int)sVar3 < (int)(uint)pcVar1->count));
        sVar3 = sVar3 + 1) {
      pch_record_macro_definition((byte *)"",pcVar1->data[sVar3],0);
    }
    text = cwd_string();
    pch_record_entry(7,0,(char *)text);
    pcVar1 = g_include_path_list;
    for (sVar3 = 0; (pcVar1 != (c1_vector *)0x0 && ((int)sVar3 < (int)(uint)pcVar1->count));
        sVar3 = sVar3 + 1) {
      pch_record_entry(7,0,pcVar1->data[sVar3]);
    }
    g_eh_declarations_injected = 0;
  }
  return;
}

