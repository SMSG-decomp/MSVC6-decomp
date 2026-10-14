void __cdecl pragma_include_alias(void)

{
  uchar *puVar1;
  char cVar2;
  uchar *node;
  int iVar3;
  c1_token *pcVar4;
  char *pcVar5;
  wchar_t *pwVar6;
  c1_u8 *pcVar7;
  uint uVar8;
  
  iVar3 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x24);
  if (iVar3 == 0) {
    diag_fatal(0x49,".\\p0pragma.c",0xbec);
  }
  pcVar4 = pragma_warn_expected_token('v');
  if (pcVar4 != (c1_token *)0x0) {
    if (g_opt_E_preprocess != 0) {
      fwrite(L"(",1,1,g_pp_output_stream);
    }
    node = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + 0x10;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    puVar1 = node + 0xc;
    pcVar5 = pp_include_parse_filename('\0',(char *)puVar1);
    *(char **)(node + 4) = pcVar5;
    if (pcVar5 == (char *)0x0) {
      diag_warning(1,0x264);
      pcVar4 = token_next(&g_token_position);
      pragma_skip_to_dash(pcVar4);
      return;
    }
    if (g_opt_E_preprocess != 0) {
      pwVar6 = L"<(";
      if (*puVar1 == '\0') {
        pwVar6 = L"\"<(";
      }
      fwrite(pwVar6,1,1,g_pp_output_stream);
      uVar8 = 0xffffffff;
      pcVar5 = *(char **)(node + 4);
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      fwrite(*(char **)(node + 4),~uVar8 - 1,1,g_pp_output_stream);
      pwVar6 = L">\"<(";
      if (*puVar1 == '\0') {
        pwVar6 = L"\"<(";
      }
      fwrite(pwVar6,1,1,g_pp_output_stream);
    }
    pcVar4 = pragma_warn_expected_token('7');
    if (pcVar4 != (c1_token *)0x0) {
      if (g_opt_E_preprocess != 0) {
        fwrite(",",1,1,g_pp_output_stream);
      }
      pcVar7 = str_dup_arena(*(char **)(node + 4),0);
      puVar1 = node + 0xd;
      *(c1_u8 **)(node + 4) = pcVar7;
      pcVar5 = pp_include_parse_filename('\0',(char *)puVar1);
      *(char **)(node + 8) = pcVar5;
      if (pcVar5 == (char *)0x0) {
        diag_warning(1,0x264);
        pcVar4 = token_next(&g_token_position);
        pragma_skip_to_dash(pcVar4);
        return;
      }
      if (g_opt_E_preprocess != 0) {
        pwVar6 = L"<(";
        if (*puVar1 == '\0') {
          pwVar6 = L"\"<(";
        }
        fwrite(pwVar6,1,1,g_pp_output_stream);
        uVar8 = 0xffffffff;
        pcVar5 = *(char **)(node + 8);
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        fwrite(*(char **)(node + 8),~uVar8 - 1,1,g_pp_output_stream);
        pwVar6 = L">\"<(";
        if (*puVar1 == '\0') {
          pwVar6 = L"\"<(";
        }
        fwrite(pwVar6,1,1,g_pp_output_stream);
      }
      pcVar4 = pragma_warn_expected_token('~');
      if (pcVar4 != (c1_token *)0x0) {
        if (g_opt_E_preprocess != 0) {
          fwrite(")",1,1,g_pp_output_stream);
        }
        if (node[0xc] != *puVar1) {
          diag_warning(1,0x264);
          pcVar4 = token_next(&g_token_position);
          pragma_skip_to_dash(pcVar4);
          return;
        }
        pcVar7 = str_dup_arena(*(char **)(node + 8),0);
        *(c1_u8 **)(node + 8) = pcVar7;
        slist_push_front(g_include_alias_table,(void **)node);
      }
    }
  }
  return;
}

