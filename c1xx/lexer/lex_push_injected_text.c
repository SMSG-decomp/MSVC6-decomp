void __cdecl lex_push_injected_text(int arg)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  byte *pbVar4;
  uint hash;
  byte local_200 [512];
  
  g_compile_flags_c4 = g_compile_flags_c4 | 0x200;
  pbVar4 = local_200;
  hash = 0;
  free_list_mark_block_end(g_injected_text_list);
  bVar1 = *g_opt_il_prefix;
  local_200[0] = bVar1;
  pbVar2 = (byte *)g_opt_il_prefix;
  while (bVar1 != 0) {
    pbVar2 = pbVar2 + 1;
    bVar1 = *pbVar2;
    hash = (hash >> 4) + hash * 4 + (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
    *pbVar4 = bVar1;
  }
  pcVar3 = "if";
  *pbVar4 = 0x69;
  do {
    pcVar3 = pcVar3 + 1;
    bVar1 = *pcVar3;
    hash = (hash >> 4) + hash * 4 + (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
    *pbVar4 = bVar1;
  } while (bVar1 != 0);
  file_open_or_fatal((char *)local_200,hash,2,arg,0);
  g_string_literal_cur = &g_string_literal_buffer;
  return;
}

