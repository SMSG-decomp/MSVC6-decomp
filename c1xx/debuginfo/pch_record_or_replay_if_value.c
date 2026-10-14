int __cdecl pch_record_or_replay_if_value(int value)

{
  int *piVar1;
  
  if (g_include_depth != 0) {
    pp_include_pop_file();
  }
  if (g_pch_directive_mode == 1) {
    init_write_reloc_record(9,value,0);
    return value;
  }
  if (g_pch_directive_mode == 2) {
    piVar1 = g_pch_record_cursor + 2;
    g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
    return *piVar1;
  }
  return value;
}

