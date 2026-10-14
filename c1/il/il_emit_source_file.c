void __cdecl il_emit_source_file(char *file_name)

{
  if ((g_c9il_mode == '\0') && (file_name != g_il_last_source_file_ni)) {
    (*g_pdb_gi->name_map->vtbl->getName)
              (g_pdb_gi->name_map,(NI)file_name,(char **)&g_source_file_ni);
    il_emit_symbol(0x16,(c1_symbol *)0x0);
    g_il_last_source_file_ni = file_name;
  }
  return;
}

