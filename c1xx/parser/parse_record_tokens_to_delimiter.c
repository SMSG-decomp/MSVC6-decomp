c1xx_token * __thiscall
parse_record_tokens_to_delimiter(c1xx_token_stream *stream,c1_u32 stop_set,char keep_delimiter)

{
  c1xx_token_stream_vtbl *pcVar1;
  int *piVar2;
  void *pvVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  c1_u8 cVar12;
  c1_u8 cVar13;
  c1_u8 cVar14;
  uint uVar15;
  c1xx_token *tok;
  c1xx_token *tok_2;
  uint uVar16;
  c1_value_cell *pcVar17;
  c1xx_token *pcVar18;
  c1xx_token *tok_3;
  c1xx_token *tok_4;
  c1_line_map_row *pcVar19;
  char *pcVar20;
  char *pcVar21;
  int iVar22;
  int *piVar23;
  byte *pbVar24;
  c1_value_cell *pcVar25;
  byte *pbVar26;
  byte *pbVar27;
  c1xx_token *pcVar28;
  bool bVar29;
  c1xx_token *pcStack_48;
  c1_value_cell *paren_cells;
  int local_34;
  c1_value_cell *brace_cells;
  int local_24;
  c1_value_cell *bracket_cells;
  int local_14;
  c1_value_cell *angle_cells;
  int local_4;
  
  bVar29 = false;
  bVar6 = false;
  brace_cells = (c1_value_cell *)0x0;
  bVar7 = false;
  local_24 = 0;
  paren_cells = (c1_value_cell *)0x0;
  bVar8 = false;
  local_34 = 0;
  bracket_cells = (c1_value_cell *)0x0;
  bVar10 = false;
  local_14 = 0;
  angle_cells = (c1_value_cell *)0x0;
  bVar11 = false;
  local_4 = 0;
  bVar9 = false;
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)))) &&
     ((((byte)g_compile_flags_cc & 0x10) == 0 && ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  if (((g_token_source->stream->flags & 1) == 0) && (stream->arena < g_token_source->stream->arena))
  {
    bVar6 = true;
  }
  pcVar1 = stream->vtbl;
  g_compile_flags_c8 = g_compile_flags_c8 | 0x4000000;
  tok = (c1xx_token *)token_new_position_marker(stream->arena);
  (*pcVar1->append)(stream,(int)tok);
  pcVar25 = (c1_value_cell *)0x0;
LAB_1043b000:
  do {
    if ((((bVar9) && (paren_cells == (c1_value_cell *)0x0)) && (pcVar25 == (c1_value_cell *)0x0)) &&
       (brace_cells == (c1_value_cell *)0x0)) goto LAB_1043ad01;
    pcVar18 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    pcStack_48 = pcVar18;
    if (((&g_token_static_records)[pcVar18->code] == 0) && (bVar6)) {
      pcStack_48 = (c1xx_token *)arena_or_pool_alloc(0x30,g_token_arena_index);
      if (pcStack_48 == (c1xx_token *)0x0) {
        pcStack_48 = (c1xx_token *)0x0;
      }
      else {
        pcVar28 = pcStack_48;
        for (iVar22 = 0xc; iVar22 != 0; iVar22 = iVar22 + -1) {
          cVar12 = pcVar18->unk01[0];
          cVar13 = pcVar18->unk01[1];
          cVar14 = pcVar18->unk01[2];
          pcVar28->code = pcVar18->code;
          pcVar28->unk01[0] = cVar12;
          pcVar28->unk01[1] = cVar13;
          pcVar28->unk01[2] = cVar14;
          pcVar18 = (c1xx_token *)(pcVar18->unk01 + 3);
          pcVar28 = (c1xx_token *)(pcVar28->unk01 + 3);
        }
      }
    }
    switch(pcStack_48->code) {
    case '*':
      (*stream->vtbl->append)(stream,(int)pcStack_48);
      g_compile_flags_c4 = g_compile_flags_c4 | 0x200000;
      parse_record_asm_statement_tokens(stream);
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffdfffff;
      goto LAB_1043b000;
    case '4':
      if ((((stop_set & 0x200) == 0) || (brace_cells != (c1_value_cell *)0x0)) ||
         ((paren_cells != (c1_value_cell *)0x0 || (pcVar25 != (c1_value_cell *)0x0)))) break;
      bVar29 = !bVar29;
      goto LAB_1043b086;
    case '6':
      uVar5 = stop_set & 0x100;
      goto LAB_1043b05a;
    case '7':
      uVar5 = stop_set & 0x80;
LAB_1043b05a:
      if ((((uVar5 != 0) && (brace_cells == (c1_value_cell *)0x0)) &&
          (paren_cells == (c1_value_cell *)0x0)) && (pcVar25 == (c1_value_cell *)0x0)) {
        bVar29 = angle_cells == (c1_value_cell *)0x0;
LAB_1043b086:
        if (bVar29) {
LAB_1043b08c:
          bVar9 = true;
        }
      }
      break;
    case '>':
      if ((g_compile_flags_c8 & 0x10000000) != 0) {
        if (angle_cells != (c1_value_cell *)0x0) {
          angle_cells = angle_cells->next;
          local_4 = local_4 + -1;
          if (angle_cells != (c1_value_cell *)0x0) break;
        }
        if ((stop_set & 0x400) != 0) {
          if (keep_delimiter == '\0') {
            if (bVar11) {
              bVar11 = false;
              break;
            }
          }
          else if (!bVar11) goto LAB_1045de70;
          bVar9 = true;
        }
LAB_1045de70:
        bVar11 = false;
      }
      break;
    case 'A':
      if ((((stop_set & 0x10) == 0) || (pcVar25 != (c1_value_cell *)0x0)) ||
         ((paren_cells != (c1_value_cell *)0x0 || (brace_cells != (c1_value_cell *)0x0)))) {
        bracket_cells = arena_alloc(g_arenas + 4,8);
        if (bracket_cells == (c1_value_cell *)0x0) {
          bracket_cells = (c1_value_cell *)0x0;
        }
        else {
          bracket_cells->next = pcVar25;
          bracket_cells->value = g_token_position;
        }
        local_14 = local_14 + 1;
        bVar10 = true;
        pcVar25 = bracket_cells;
        break;
      }
      goto LAB_1043b08c;
    case 'D':
      if ((g_compile_flags_c8 & 0x10000000) != 0) {
        pcVar17 = arena_alloc(g_arenas + 4,8);
        if (pcVar17 == (c1_value_cell *)0x0) {
          angle_cells = (c1_value_cell *)0x0;
          local_4 = local_4 + 1;
          bVar11 = true;
        }
        else {
          pcVar17->next = angle_cells;
          pcVar17->value = g_token_position;
          local_4 = local_4 + 1;
          bVar11 = true;
          angle_cells = pcVar17;
        }
      }
      break;
    case 'u':
      if (((stop_set & 1) != 0) && (brace_cells == (c1_value_cell *)0x0)) goto LAB_1043b08c;
      pcVar17 = arena_alloc(g_arenas + 4,8);
      if (pcVar17 == (c1_value_cell *)0x0) {
        brace_cells = (c1_value_cell *)0x0;
        local_24 = local_24 + 1;
        bVar7 = true;
      }
      else {
        pcVar17->next = brace_cells;
        pcVar17->value = g_token_position;
        local_24 = local_24 + 1;
        bVar7 = true;
        brace_cells = pcVar17;
      }
      break;
    case 'v':
      if (((((stop_set & 4) != 0) && (paren_cells == (c1_value_cell *)0x0)) &&
          (brace_cells == (c1_value_cell *)0x0)) && (pcVar25 == (c1_value_cell *)0x0))
      goto LAB_1043b08c;
      pcVar17 = arena_alloc(g_arenas + 4,8);
      if (pcVar17 == (c1_value_cell *)0x0) {
        paren_cells = (c1_value_cell *)0x0;
        local_34 = local_34 + 1;
        bVar8 = true;
      }
      else {
        pcVar17->next = paren_cells;
        pcVar17->value = g_token_position;
        local_34 = local_34 + 1;
        bVar8 = true;
        paren_cells = pcVar17;
      }
      break;
    case 'z':
      if (pcVar25 != (c1_value_cell *)0x0) {
        pcVar25 = pcVar25->next;
        local_14 = local_14 + -1;
        bracket_cells = pcVar25;
        if (pcVar25 != (c1_value_cell *)0x0) break;
      }
      if ((((stop_set & 0x20) != 0) && (paren_cells == (c1_value_cell *)0x0)) &&
         (brace_cells == (c1_value_cell *)0x0)) {
        if (keep_delimiter == '\0') {
          if (bVar10) {
            bVar10 = false;
            break;
          }
        }
        else if (!bVar10) goto LAB_1043af7a;
        bVar9 = true;
      }
LAB_1043af7a:
      bVar10 = false;
      break;
    case '{':
      if (brace_cells == (c1_value_cell *)0x0) {
LAB_1043ae2e:
        if ((stop_set & 2) != 0) {
          if (keep_delimiter == '\0') {
            if (!bVar7) goto LAB_1043ae49;
          }
          else if (bVar7) {
LAB_1043ae49:
            bVar9 = true;
          }
        }
        bVar7 = false;
      }
      else {
        brace_cells = brace_cells->next;
        local_24 = local_24 + -1;
        if (brace_cells == (c1_value_cell *)0x0) goto LAB_1043ae2e;
      }
      if (paren_cells != (c1_value_cell *)0x0) {
        iVar22 = lex_line_number_of_position(&paren_cells->value);
        pcVar20 = pp_position_file_name(&paren_cells->value);
        pcVar21 = misc_string_get(0x169);
        diag_error(0x3be,pcVar21,pcVar20,iVar22);
        local_34 = 0;
        paren_cells = (c1_value_cell *)0x0;
      }
      bVar8 = false;
      if (pcVar25 != (c1_value_cell *)0x0) {
        iVar22 = lex_line_number_of_position(&pcVar25->value);
LAB_1045dce5:
        pcVar20 = pp_position_file_name(&pcVar25->value);
        pcVar21 = misc_string_get(0x16a);
        diag_error(0x3be,pcVar21,pcVar20,iVar22);
        pcVar25 = (c1_value_cell *)0x0;
        local_14 = 0;
        bracket_cells = (c1_value_cell *)0x0;
      }
      goto LAB_1043afbe;
    case '~':
      if (paren_cells != (c1_value_cell *)0x0) {
        paren_cells = paren_cells->next;
        local_34 = local_34 + -1;
        if (paren_cells != (c1_value_cell *)0x0) break;
      }
      if ((((stop_set & 8) != 0) && (pcVar25 == (c1_value_cell *)0x0)) &&
         (brace_cells == (c1_value_cell *)0x0)) {
        if (keep_delimiter == '\0') {
          if (bVar8) {
            bVar8 = false;
            break;
          }
        }
        else if (!bVar8) goto LAB_1043aedc;
        bVar9 = true;
      }
LAB_1043aedc:
      bVar8 = false;
      break;
    case '\x7f':
      if ((((stop_set & 0x40) != 0) && (brace_cells == (c1_value_cell *)0x0)) &&
         (paren_cells == (c1_value_cell *)0x0)) {
        bVar9 = true;
      }
      if (pcVar25 != (c1_value_cell *)0x0) {
        pcVar19 = include_line_map_find((c1_line_map_state *)&g_lex_position,pcVar25->value);
        iVar22 = (pcVar19->line - pcVar19->position) + pcVar25->value;
        goto LAB_1045dce5;
      }
LAB_1043afbe:
      bVar10 = false;
      break;
    case 0x96:
      pbVar24 = (byte *)0x0;
      piVar2 = (int *)**(int **)(*(int *)pcStack_48->value + 0x14);
      if ((*(byte *)(*(int *)pcStack_48->value + 3) & 0x40) != 0) {
        (*stream->vtbl->append)(stream,(int)g_token_colon_colon);
      }
      while (piVar23 = piVar2, pbVar27 = (byte *)0x0, piVar2 != (int *)0x0) {
        do {
          pbVar4 = (byte *)piVar23[2];
          if ((((*pbVar4 & 0x1f) == 4) || (pbVar26 = pbVar27, (*pbVar4 & 0x1f) == 0x19)) &&
             (pbVar26 = pbVar4, pbVar4 == pbVar24)) break;
          piVar23 = (int *)*piVar23;
          pbVar27 = pbVar26;
        } while (piVar23 != (int *)0x0);
        pbVar24 = pbVar27;
        if (pbVar24 == (byte *)0x0) break;
        if (g_token_arena_index == 0) {
          tok_4 = (c1xx_token *)pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          tok_4 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (tok_4 == (c1xx_token *)0x0) {
          tok_4 = (c1xx_token *)0x0;
        }
        else {
          pvVar3 = *(void **)(pbVar24 + 8);
          tok_4->code = '\x06';
          tok_4->value = pvVar3;
          tok_4->value1 = g_token_position;
        }
        (*stream->vtbl->append)(stream,(int)tok_4);
        (*stream->vtbl->append)(stream,(int)g_token_colon_colon);
      }
      if (g_token_arena_index == 0) {
        tok_3 = (c1xx_token *)pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        tok_3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      pcVar25 = bracket_cells;
      if (tok_3 == (c1xx_token *)0x0) {
        (*stream->vtbl->append)(stream,0);
      }
      else {
        pvVar3 = *(void **)(piVar2[2] + 8);
        tok_3->code = '\x06';
        tok_3->value = pvVar3;
        tok_3->value1 = g_token_position;
        (*stream->vtbl->append)(stream,(int)tok_3);
      }
      goto LAB_1043b000;
    }
    bVar29 = pcStack_48->code == 0x97;
    if ((bVar9) && (keep_delimiter == '\0')) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcStack_48);
    }
    else {
      (*stream->vtbl->append)(stream,(int)pcStack_48);
    }
    if (bVar9) {
      if (paren_cells != (c1_value_cell *)0x0) {
        if (g_line_map_cached_row.position == paren_cells->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,paren_cells->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + paren_cells->value;
        pcVar20 = pp_position_file_name(&paren_cells->value);
        pcVar21 = misc_string_get(0x169);
        diag_error(0x3be,pcVar21,pcVar20,iVar22);
        local_34 = 0;
        paren_cells = (c1_value_cell *)0x0;
        bVar8 = false;
      }
      if (brace_cells != (c1_value_cell *)0x0) {
        if (g_line_map_cached_row.position == brace_cells->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,brace_cells->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + brace_cells->value;
        pcVar20 = pp_position_file_name(&brace_cells->value);
        pcVar21 = misc_string_get(0x168);
        diag_error(0x3be,pcVar21,pcVar20,iVar22);
        local_24 = 0;
        brace_cells = (c1_value_cell *)0x0;
        bVar7 = false;
      }
      if (pcVar25 != (c1_value_cell *)0x0) {
        if (g_line_map_cached_row.position == pcVar25->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,pcVar25->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + pcVar25->value;
        pcVar20 = pp_position_file_name(&pcVar25->value);
        pcVar21 = misc_string_get(0x16a);
        diag_error(0x3be,pcVar21,pcVar20,iVar22);
        local_14 = 0;
        bracket_cells = (c1_value_cell *)0x0;
        bVar10 = false;
        pcVar25 = (c1_value_cell *)0x0;
      }
    }
    else if (pcStack_48->code == 'm') {
LAB_1043ad01:
      pcVar1 = stream->vtbl;
      tok_2 = (c1xx_token *)token_new_position_marker(stream->arena);
      (*pcVar1->append)(stream,(int)tok_2);
      uVar15 = g_compile_flags_c8;
      uVar16 = g_compile_flags_c8 & 0xfbffffff;
      uVar5 = g_compile_flags_c8 & 0x32000000;
      g_compile_flags_c8 = uVar16;
      if (((uVar5 == 0) &&
          ((((uVar15 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
           ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) {
        g_context_arena_index = 5;
        if (((byte)g_compile_flags_cc & 1) != 0) {
          g_context_arena_index = 4;
        }
      }
      else {
        g_context_arena_index = 0;
      }
      g_expr_arena_index = g_context_arena_index;
      if (0 < local_4) {
        if (g_line_map_cached_row.position == angle_cells->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,angle_cells->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + angle_cells->value;
        pcVar20 = pp_position_file_name(&angle_cells->value);
        pcVar21 = misc_string_get(0x16c);
        diag_fatal(0x4b,pcVar21,pcVar20,iVar22);
      }
      if (0 < local_14) {
        if (g_line_map_cached_row.position == pcVar25->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,pcVar25->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + pcVar25->value;
        pcVar20 = pp_position_file_name(&pcVar25->value);
        pcVar21 = misc_string_get(0x16a);
        diag_fatal(0x4b,pcVar21,pcVar20,iVar22);
      }
      if (0 < local_34) {
        if (g_line_map_cached_row.position == paren_cells->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,paren_cells->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + paren_cells->value;
        pcVar20 = pp_position_file_name(&paren_cells->value);
        pcVar21 = misc_string_get(0x169);
        diag_fatal(0x4b,pcVar21,pcVar20,iVar22);
      }
      if (0 < local_24) {
        if (g_line_map_cached_row.position == brace_cells->value) {
          pcVar19 = &g_line_map_cached_row;
        }
        else {
          pcVar19 = pp_line_map_find_entry(&g_line_map,brace_cells->value);
        }
        iVar22 = (pcVar19->line - pcVar19->position) + brace_cells->value;
        pcVar20 = pp_position_file_name(&brace_cells->value);
        pcVar21 = misc_string_get(0x168);
        diag_fatal(0x4b,pcVar21,pcVar20,iVar22);
      }
      return pcStack_48;
    }
  } while( true );
}

