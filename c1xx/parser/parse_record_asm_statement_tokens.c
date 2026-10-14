void __thiscall parse_record_asm_statement_tokens(c1xx_token_stream *stream)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  byte *token;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  c1_line_map_row *pcVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int local_4;
  
  bVar1 = true;
  bVar2 = false;
  local_4 = 0;
  piVar9 = (int *)0x0;
LAB_1045e214:
  do {
    pbVar3 = token_next((c1_token_reader *)&g_token_position);
    token = arena_or_pool_alloc(0x30,0);
    if (token == (byte *)0x0) {
      token = (byte *)0x0;
    }
    else {
      pbVar10 = token;
      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pbVar10 = *(undefined4 *)pbVar3;
        pbVar3 = pbVar3 + 4;
        pbVar10 = pbVar10 + 4;
      }
    }
    if ((bVar2) && (*token != 0x75)) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
      if (local_4 < 1) {
        return;
      }
      iVar8 = lex_line_number_of_position(piVar9 + 1);
LAB_1045e39a:
      piVar9 = piVar9 + 1;
      goto LAB_1045e3be;
    }
    bVar2 = false;
    switch(*token) {
    case 0x6d:
      if (local_4 < 1) {
        return;
      }
      if (g_line_map_cached_row.position == piVar9[1]) {
        pcVar7 = &g_line_map_cached_row;
      }
      else {
        pcVar7 = pp_line_map_find_entry(&g_line_map,piVar9[1]);
      }
      iVar8 = (pcVar7->line - pcVar7->position) + piVar9[1];
      goto LAB_1045e39a;
    case 0x75:
      piVar4 = arena_alloc(g_arenas + 4,8);
      if (piVar4 == (int *)0x0) {
        piVar9 = (int *)0x0;
        local_4 = local_4 + 1;
        (*stream->vtbl->append)(stream,(int)token);
        bVar1 = false;
      }
      else {
        *piVar4 = (int)piVar9;
        piVar4[1] = g_token_position;
        local_4 = local_4 + 1;
        (*stream->vtbl->append)(stream,(int)token);
        bVar1 = false;
        piVar9 = piVar4;
      }
      break;
    case 0x7b:
      if (piVar9 == (int *)0x0) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
        if (local_4 < 1) {
          return;
        }
        pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,iRam00000004);
        iVar8 = (pcVar7->line - pcVar7->position) + iRam00000004;
        piVar9 = &iRam00000004;
        goto LAB_1045e3be;
      }
      piVar9 = (int *)*piVar9;
      local_4 = local_4 + -1;
      if (piVar9 == (int *)0x0) {
        (*stream->vtbl->append)(stream,(int)token);
        if (local_4 < 1) {
          return;
        }
        pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,iRam00000004);
        iVar8 = (pcVar7->line - pcVar7->position) + iRam00000004;
        piVar9 = &iRam00000004;
        goto LAB_1045e3be;
      }
      (*stream->vtbl->append)(stream,(int)token);
      bVar1 = false;
      break;
    case 0x7f:
      iVar8 = (*g_token_source->stream->vtbl->at_end)();
      if (iVar8 == 1) {
        lex_skip_line_comment();
        (*stream->vtbl->append)(stream,(int)token);
        bVar1 = false;
        break;
      }
      do {
        token = token_next((c1_token_reader *)&g_token_position);
      } while (*token != 0xf2);
    default:
      (*stream->vtbl->append)(stream,(int)token);
      bVar1 = false;
      break;
    case 0xf2:
      if (!bVar1) {
        if (piVar9 != (int *)0x0) goto code_r0x1045e2f1;
        (*stream->vtbl->append)(stream,(int)token);
        if (local_4 < 1) {
          return;
        }
        iVar8 = lex_line_number_of_position(&iRam00000004);
        piVar9 = &iRam00000004;
LAB_1045e3be:
        pcVar5 = pp_position_file_name(piVar9);
        pcVar6 = misc_string_get(0x168);
        diag_fatal(0x4b,pcVar6,pcVar5,iVar8);
      }
      g_token_position = *(int *)(token + 8);
      bVar2 = true;
      (*stream->vtbl->append)(stream,(int)token);
      bVar1 = false;
    }
  } while( true );
code_r0x1045e2f1:
  g_token_position = *(int *)(token + 8);
  (*stream->vtbl->append)(stream,(int)token);
  bVar1 = false;
  goto LAB_1045e214;
}

