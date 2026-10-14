void __cdecl init_finish_array(int sym)

{
  byte bVar1;
  byte *pbVar2;
  
  init_emit_data((c1_symbol *)sym);
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    pbVar2 = *(byte **)(sym + 0x14);
    bVar1 = *pbVar2;
    while ((char)bVar1 < '\0') {
      pbVar2 = *(byte **)(pbVar2 + 4);
      bVar1 = *pbVar2;
    }
    g_init_offset = g_init_offset + (char)(&g_type_rank_table)[*pbVar2 & 0xf];
  }
  return;
}

