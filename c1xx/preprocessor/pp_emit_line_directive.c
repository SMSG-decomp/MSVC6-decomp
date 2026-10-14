void __cdecl pp_emit_line_directive(void)

{
  char cVar1;
  c1_line_map_row *pcVar2;
  byte *pbVar3;
  uint uVar4;
  byte local_200 [512];
  
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar2 = &g_line_map_cached_row;
  }
  else {
    pcVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  format_snprintf((char *)local_200,"#line %d ",0x10,
                  (pcVar2->line - pcVar2->position) + 1 + g_token_position);
  uVar4 = 0xffffffff;
  pbVar3 = local_200;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (cVar1 != '\0');
  fwrite(local_200,~uVar4 - 1,1,g_pp_output_stream);
  pbVar3 = (byte *)pp_position_file_name(&g_token_position);
  pbVar3 = pp_quote_file_name(local_200,pbVar3);
  fwrite(local_200,(int)pbVar3 - (int)local_200,1,g_pp_output_stream);
  return;
}

