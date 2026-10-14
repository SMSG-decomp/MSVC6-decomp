void __cdecl pragma_include_alias(void)

{
  char cVar1;
  c1_u8 *cell;
  int iVar2;
  uchar *puVar3;
  char *delim;
  byte *pbVar4;
  char *delim_2;
  char *delim_3;
  c1_u8 *pcVar5;
  char *delim_4;
  char *pcVar6;
  c1_u8 *pcVar7;
  uint uVar8;
  
  iVar2 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x24);
  if (iVar2 == 0) {
    diag_fatal(0x49,".\\p0pragma.c",0xbec);
  }
  puVar3 = pragma_warn_expected_token('v');
  if (puVar3 != (uchar *)0x0) {
    if (g_opt_E_preprocess != 0) {
      fwrite("(",1,1,g_pp_output_stream);
    }
    cell = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + 0x10;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    pcVar7 = cell + 0xc;
    delim = pp_include_parse_filename('\0',(char *)pcVar7);
    *(char **)(cell + 4) = delim;
    if (delim == (char *)0x0) {
      diag_warning(1,0x264);
      pbVar4 = token_next((c1_token_reader *)&g_token_position);
      pragma_skip_to_dash(pbVar4);
      return;
    }
    if (g_opt_E_preprocess != 0) {
      delim_2 = "<";
      if (*pcVar7 == '\0') {
        delim_2 = "\"";
      }
      fwrite(delim_2,1,1,g_pp_output_stream);
      uVar8 = 0xffffffff;
      pcVar6 = *(char **)(cell + 4);
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      fwrite(*(char **)(cell + 4),~uVar8 - 1,1,g_pp_output_stream);
      delim_3 = ">";
      if (*pcVar7 == '\0') {
        delim_3 = "\"";
      }
      fwrite(delim_3,1,1,g_pp_output_stream);
    }
    puVar3 = pragma_warn_expected_token('7');
    if (puVar3 != (uchar *)0x0) {
      if (g_opt_E_preprocess != 0) {
        fwrite(",",1,1,g_pp_output_stream);
      }
      pcVar5 = str_dup_arena(*(char **)(cell + 4),0);
      pcVar7 = cell + 0xd;
      *(c1_u8 **)(cell + 4) = pcVar5;
      delim_4 = pp_include_parse_filename('\0',(char *)pcVar7);
      *(char **)(cell + 8) = delim_4;
      if (delim_4 == (char *)0x0) {
        diag_warning(1,0x264);
        pbVar4 = token_next((c1_token_reader *)&g_token_position);
        pragma_skip_to_dash(pbVar4);
        return;
      }
      if (g_opt_E_preprocess != 0) {
        pcVar6 = "<";
        if (*pcVar7 == '\0') {
          pcVar6 = "\"";
        }
        fwrite(pcVar6,1,1,g_pp_output_stream);
        uVar8 = 0xffffffff;
        pcVar6 = *(char **)(cell + 8);
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        fwrite(*(char **)(cell + 8),~uVar8 - 1,1,g_pp_output_stream);
        pcVar6 = ">";
        if (*pcVar7 == '\0') {
          pcVar6 = "\"";
        }
        fwrite(pcVar6,1,1,g_pp_output_stream);
      }
      puVar3 = pragma_warn_expected_token('~');
      if (puVar3 != (uchar *)0x0) {
        if (g_opt_E_preprocess != 0) {
          fwrite(")",1,1,g_pp_output_stream);
        }
        if (cell[0xc] != *pcVar7) {
          diag_warning(1,0x264);
          pbVar4 = token_next((c1_token_reader *)&g_token_position);
          pragma_skip_to_dash(pbVar4);
          return;
        }
        pcVar7 = str_dup_arena(*(char **)(cell + 8),0);
        *(c1_u8 **)(cell + 8) = pcVar7;
        list_push_front(g_include_alias_table,(void **)cell);
      }
    }
  }
  return;
}

