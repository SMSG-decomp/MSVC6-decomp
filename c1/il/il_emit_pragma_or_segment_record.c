char __cdecl il_emit_pragma_or_segment_record(int kind)

{
  uchar *puVar1;
  byte bVar2;
  char cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_u8 *pcVar6;
  int iVar7;
  c1_symbol *pcVar8;
  int *piVar9;
  uint uVar10;
  uint id;
  byte *pbVar11;
  ushort uVar12;
  char *pcVar13;
  
  puVar1 = g_arenas[0].cur;
  pcVar8 = (c1_symbol *)g_ilstore_status;
  if ((g_ilstore_status == 4) ||
     ((((g_c9il_mode == '\0' && (kind != 0xb)) &&
       (pcVar8 = (c1_symbol *)g_compile_flags_cc, (g_compile_flags_cc & 0x1000) == 0)) ||
      (pcVar8 = (c1_symbol *)(uint)g_opt_Zg, g_opt_Zg != '\0')))) goto LAB_10604809;
  pcVar8 = (c1_symbol *)(kind - 1);
  switch(kind) {
  case 1:
    goto switchD_10604678_caseD_1;
  case 2:
    if (((byte)g_compile_flags_c8 & 0x80) != 0) goto LAB_10604809;
    if (g_c9il_mode == '\0') {
      cVar3 = il_emit_source_file_change(kind,kind);
      return cVar3;
    }
    break;
  case 0xb:
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(fe_pragma_comment **)puVar1 = g_pragma_comment_list;
    *(int *)(puVar1 + 4) = g_comment_record_kind;
    if (g_comment_record_kind == 7) {
      uVar10 = (byte)*g_comment_record_text + 1;
    }
    else {
      uVar10 = 0xffffffff;
      pcVar13 = g_comment_record_text;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        cVar3 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar3 != '\0');
      uVar10 = ~uVar10;
    }
    pcVar6 = arena_alloc_copy((c1_u8 *)g_comment_record_text,0,uVar10);
    *(c1_u8 **)(puVar1 + 8) = pcVar6;
    g_pragma_comment_list = (fe_pragma_comment *)puVar1;
    return (char)pcVar6;
  case 0x24:
    if (((byte)g_compile_flags_c8 & 0x80) != 0) goto LAB_10604809;
    if (g_c9il_mode == '\0') {
      if (g_il_line_base == 0xffffffff) {
        if ((g_current_function != (c1_symbol *)0x0) &&
           (pcVar8 = g_current_function, (g_current_function->flags1 & 0x40) != 0))
        goto LAB_10604809;
        g_il_line_base = g_function_start_line;
        piVar9 = include_line_map_find(&g_lex_position,g_token_position);
        g_il_line_offset = ((piVar9[1] - *piVar9) - g_il_line_base) + g_token_position;
        pcVar8 = (c1_symbol *)g_token_position;
        break;
      }
      pcVar8 = (c1_symbol *)include_line_map_find(&g_lex_position,g_token_position);
      g_il_line_offset =
           ((*(int *)&pcVar8->flags4 - *(int *)pcVar8) - g_il_line_base) + g_token_position;
      if ((int)g_il_line_offset < 0x10000) goto LAB_10604809;
    }
    kind = 1;
switchD_10604678_caseD_1:
    pcVar8 = (c1_symbol *)il_line_number_emit_limit();
    if (pcVar8 == (c1_symbol *)0x0) goto LAB_10604809;
  }
  if (kind != 0x23) {
    il_emit_byte_record('O');
    iVar7 = il_buffer_reserve(&g_il_ex.bytes,2);
    bVar2 = (byte)iVar7 & 1;
    pcVar8 = (c1_symbol *)(uint)bVar2;
    g_il_ex.open = g_il_ex.open & bVar2;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (c1_u8)kind;
      pcVar8 = (c1_symbol *)(g_il_ex.bytes.pbEnd + 1);
      g_il_ex.bytes.pbEnd = (PB)pcVar8;
    }
  }
  pbVar11 = (byte *)g_pragma_subop_codes[kind].codes;
  if (pbVar11 != (byte *)0x0) {
    bVar2 = *pbVar11;
    cVar4 = g_il_pragma_byte_operand;
    uVar12 = g_asm_align_size;
    uVar10 = g_il_line_offset;
    while (pcVar8 = (c1_symbol *)(uint)bVar2, g_il_pragma_byte_operand = cVar4,
          g_asm_align_size = uVar12, g_il_line_offset = uVar10, bVar2 != 0) {
      pbVar11 = pbVar11 + 1;
      switch(bVar2) {
      case 1:
        piVar9 = include_line_map_find(&g_lex_position,g_token_position);
        uVar10 = (piVar9[1] - *piVar9) + g_token_position;
        g_il_line_base = uVar10;
        if (g_c9il_mode != '\0') goto LAB_106047d5;
        iVar7 = il_buffer_reserve(&g_il_ex.bytes,6);
        g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
        if ((g_il_ex.open != 0) &&
           (iVar7 = il_buffer_put_byte7(&g_il_ex,uVar10), (char)iVar7 == '\0')) {
          *g_il_ex.bytes.pbEnd = 0x80;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          *(uint *)g_il_ex.bytes.pbEnd = uVar10;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
        }
        g_il_last_line_offset = 0;
        break;
      case 2:
        g_il_last_line_offset = uVar10;
LAB_106047d5:
        uVar12 = (ushort)uVar10;
        iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
        bVar2 = g_il_ex.open & (byte)iVar7 & 1;
        g_il_ex.open = bVar2;
        goto LAB_106047f1;
      case 3:
        if (g_c9il_mode == '\0') {
          il_emit_end_of_globals();
          piVar9 = include_line_map_find(&g_lex_position,g_token_position);
          uVar10 = *(uint *)(piVar9[2] + 8);
          id = uVar10 >> 3;
          g_il_last_file_key = id;
          if (g_c9il_mode != '\0') goto LAB_10604862;
          iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
          g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
          if (g_il_ex.open != 0) {
            bVar2 = (byte)id;
            if (id < 0x3fff80) {
              if (0x3fff < id) {
                *g_il_ex.bytes.pbEnd = bVar2 | 0xc0;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                *g_il_ex.bytes.pbEnd = (uchar)(uVar10 >> 9);
                goto LAB_1063a658;
              }
              *g_il_ex.bytes.pbEnd = bVar2 & 0x3f | 0x80;
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              *g_il_ex.bytes.pbEnd = (uchar)(uVar10 >> 9);
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            }
            else {
              *g_il_ex.bytes.pbEnd = bVar2 + 0x80;
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            }
          }
        }
        else {
          piVar9 = include_line_map_find(&g_lex_position,g_token_position);
          if ((*(uint *)(piVar9[2] + 0xc) & 0xffffff) == 0) {
            il_emit_symbol(0x12,(c1_symbol *)0x0);
          }
          piVar9 = include_line_map_find(&g_lex_position,g_token_position);
          uVar10 = *(uint *)(piVar9[2] + 0xc);
          id = uVar10 & 0xffffff;
          if (g_c9il_mode == '\0') {
            iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
            g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
            if (g_il_ex.open != 0) {
              if (id < 0x3fff80) {
                bVar2 = (byte)uVar10;
                if (id < 0x4000) {
                  *g_il_ex.bytes.pbEnd = bVar2 & 0x3f | 0x80;
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                  *g_il_ex.bytes.pbEnd = (uchar)(id >> 6);
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                }
                else {
                  *g_il_ex.bytes.pbEnd = bVar2 | 0xc0;
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                  *g_il_ex.bytes.pbEnd = (uchar)(id >> 6);
LAB_1063a658:
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                  *g_il_ex.bytes.pbEnd = (uchar)(id >> 0xe);
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                }
              }
              else {
                *g_il_ex.bytes.pbEnd = (char)id + 0x80;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              }
            }
          }
          else {
LAB_10604862:
            il_buffer_put_id(&g_il_ex,id);
          }
        }
        break;
      case 0xc:
        uVar12 = (ushort)g_asm_instruction_record[0];
        cVar4 = il_buffer_reserve_ok(&g_il_ex,uVar12 + 3);
        if (cVar4 != '\0') {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar12);
          il_buffer_put_bytes(&g_il_ex,(uint *)g_asm_instruction_record,(uint)uVar12);
        }
        break;
      case 0xd:
        cVar5 = il_buffer_reserve_ok(&g_il_ex,1);
        if (cVar5 != '\0') {
          *g_il_ex.bytes.pbEnd = cVar4;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
        }
        break;
      case 0xe:
        cVar4 = il_buffer_reserve_ok(&g_il_ex,3);
        if (cVar4 != '\0') {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar12);
        }
        break;
      case 0x14:
        g_opt_Oa = g_opt_Oa | g_opt_Ow;
        uVar10 = il_function_option_word();
        cVar4 = il_buffer_reserve_ok(&g_il_ex,5);
        if ((cVar4 != '\0') && (iVar7 = il_buffer_put_byte7(&g_il_ex,uVar10), (char)iVar7 == '\0'))
        {
          *g_il_ex.bytes.pbEnd = 0x80;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          *(uint *)g_il_ex.bytes.pbEnd = uVar10;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
        }
        break;
      case 0x15:
        uVar12 = CONCAT11((undefined1)g_pragma_inline_recursion,(undefined1)g_pragma_inline_depth);
        bVar2 = il_buffer_reserve_ok(&g_il_ex,3);
LAB_106047f1:
        if (bVar2 != 0) {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar12);
        }
        break;
      case 0x17:
        pragma_warning_state_emit((c1_u8)kind);
      }
      cVar4 = g_il_pragma_byte_operand;
      uVar12 = g_asm_align_size;
      uVar10 = g_il_line_offset;
      bVar2 = *pbVar11;
    }
  }
LAB_10604809:
  return (char)pcVar8;
}

