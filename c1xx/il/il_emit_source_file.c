void __cdecl il_emit_source_file(int ni)

{
  if ((g_c9il_mode == '\0') && (ni != g_il_last_source_file_ni)) {
    (*g_pdb_gi->namemap->vtbl->get_name)(ni,&g_source_file_ni);
    il_emit_symbol(0x16,(c1_symbol *)0x0);
    g_il_last_source_file_ni = ni;
  }
  return;
}

