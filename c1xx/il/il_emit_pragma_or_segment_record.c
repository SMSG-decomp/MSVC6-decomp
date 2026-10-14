void __cdecl il_emit_pragma_or_segment_record(int sub)

{
  char cVar1;
  c1_u8 *pcVar2;
  c1_u8 cVar3;
  byte bVar4;
  c1_u8 cVar5;
  c1_u8 *pcVar6;
  int iVar7;
  c1_line_map_row *pcVar8;
  uint uVar9;
  uint id;
  char *pcVar10;
  ushort uVar11;
  
  pcVar2 = g_arenas[0].cur;
  if (g_ilstore_status == 4) {
    return;
  }
  if (((g_c9il_mode == '\0') && (sub != 0xb)) && ((g_compile_flags_cc & 0x1000) == 0)) {
    return;
  }
  if (g_opt_Zg != '\0') {
    return;
  }
  switch(sub) {
  case 2:
    if (((byte)g_compile_flags_c8 & 0x80) != 0) {
      return;
    }
    if (g_c9il_mode == '\0') {
      il_emit_source_file_change(sub,sub);
      return;
    }
    break;
  case 0xb:
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_pragma_comment **)pcVar2 = g_pragma_comment_list;
    *(int *)(pcVar2 + 4) = g_comment_record_kind;
    if (g_comment_record_kind == 7) {
      uVar9 = (byte)*g_comment_record_text + 1;
    }
    else {
      uVar9 = 0xffffffff;
      pcVar10 = g_comment_record_text;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
    }
    pcVar6 = arena_alloc_copy((c1_u8 *)g_comment_record_text,0,uVar9);
    *(c1_u8 **)(pcVar2 + 8) = pcVar6;
    g_pragma_comment_list = (c1_pragma_comment *)pcVar2;
    return;
  case 0x24:
    if (((byte)g_compile_flags_c8 & 0x80) != 0) {
      return;
    }
    if (g_c9il_mode == '\0') {
      if (g_il_line_base == 0xffffffff) {
        if ((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags3 & 1) != 0)) {
          return;
        }
        g_il_line_base = g_function_start_line;
        pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
        g_il_line_offset = ((pcVar8->line - pcVar8->position) - g_il_line_base) + g_token_position;
        break;
      }
      pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      g_il_line_offset = ((pcVar8->line - pcVar8->position) - g_il_line_base) + g_token_position;
      if ((int)g_il_line_offset < 0x10000) {
        return;
      }
    }
    sub = 1;
  case 1:
    iVar7 = il_line_number_emit_limit();
    if (iVar7 == 0) {
      return;
    }
  }
  if (sub != 0x23) {
    il_emit_byte_record('O');
    iVar7 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (byte)sub;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
  }
  pcVar10 = *(char **)(&g_pragma_subop_codes + sub * 8);
  if (pcVar10 != (char *)0x0) {
    cVar1 = *pcVar10;
    cVar3 = g_il_pragma_byte_operand;
    uVar11 = g_asm_align_size;
    uVar9 = g_il_line_offset;
    while (g_il_pragma_byte_operand = cVar3, g_asm_align_size = uVar11, g_il_line_offset = uVar9,
          cVar1 != '\0') {
      pcVar10 = pcVar10 + 1;
      switch(cVar1) {
      case '\x01':
        pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
        uVar9 = (pcVar8->line - pcVar8->position) + g_token_position;
        g_il_line_base = uVar9;
        if (g_c9il_mode != '\0') goto LAB_1040d712;
        iVar7 = il_buffer_reserve(&g_il_ex.bytes,6);
        g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
        if ((g_il_ex.open != 0) &&
           (iVar7 = il_buffer_put_byte7(&g_il_ex,uVar9), (char)iVar7 == '\0')) {
          *g_il_ex.bytes.cur = 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          *(uint *)g_il_ex.bytes.cur = uVar9;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
        }
        g_il_last_line_offset = 0;
        break;
      case '\x02':
        g_il_last_line_offset = uVar9;
LAB_1040d712:
        uVar11 = (ushort)uVar9;
        iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
        bVar4 = g_il_ex.open & (byte)iVar7 & 1;
        g_il_ex.open = bVar4;
        goto LAB_1040d72e;
      case '\x03':
        if (g_c9il_mode == '\0') {
          il_emit_end_of_globals();
          pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          uVar9 = pcVar8->file->key_ref;
          id = uVar9 >> 3;
          g_il_last_file_key = id;
          if (g_c9il_mode != '\0') goto LAB_1040d79f;
          iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
          g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
          if (g_il_ex.open != 0) {
            bVar4 = (byte)id;
            if (id < 0x3fff80) {
              if (0x3fff < id) {
                *g_il_ex.bytes.cur = bVar4 | 0xc0;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar9 >> 9);
                goto LAB_1047e617;
              }
              *g_il_ex.bytes.cur = bVar4 & 0x3f | 0x80;
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              *g_il_ex.bytes.cur = (c1_u8)(uVar9 >> 9);
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            }
            else {
              *g_il_ex.bytes.cur = bVar4 + 0x80;
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            }
          }
        }
        else {
          pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          if ((pcVar8->file->entity & 0xffffff) == 0) {
            il_emit_symbol(0x12,(c1_symbol *)0x0);
          }
          pcVar8 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          uVar9 = pcVar8->file->entity;
          id = uVar9 & 0xffffff;
          if (g_c9il_mode == '\0') {
            iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
            g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
            if (g_il_ex.open != 0) {
              if (id < 0x3fff80) {
                bVar4 = (byte)uVar9;
                if (id < 0x4000) {
                  *g_il_ex.bytes.cur = bVar4 & 0x3f | 0x80;
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                  *g_il_ex.bytes.cur = (c1_u8)(id >> 6);
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                }
                else {
                  *g_il_ex.bytes.cur = bVar4 | 0xc0;
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                  *g_il_ex.bytes.cur = (c1_u8)(id >> 6);
LAB_1047e617:
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                  *g_il_ex.bytes.cur = (c1_u8)(id >> 0xe);
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                }
              }
              else {
                *g_il_ex.bytes.cur = (char)id + 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
            }
          }
          else {
LAB_1040d79f:
            il_buffer_put_id(&g_il_ex,id);
          }
        }
        break;
      case '\f':
        uVar11 = (ushort)g_asm_instruction_record.length;
        cVar3 = il_buffer_reserve_ok(&g_il_ex,uVar11 + 3);
        if (cVar3 != '\0') {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar11);
          il_buffer_put_bytes(&g_il_ex,(uint *)&g_asm_instruction_record,(uint)uVar11);
        }
        break;
      case '\r':
        cVar5 = il_buffer_reserve_ok(&g_il_ex,1);
        if (cVar5 != '\0') {
          *g_il_ex.bytes.cur = cVar3;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
        break;
      case '\x0e':
        cVar3 = il_buffer_reserve_ok(&g_il_ex,3);
        if (cVar3 != '\0') {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar11);
        }
        break;
      case '\x14':
        g_opt_Oa = g_opt_Oa | g_opt_Ow;
        uVar9 = il_function_option_word();
        cVar3 = il_buffer_reserve_ok(&g_il_ex,5);
        if ((cVar3 != '\0') && (iVar7 = il_buffer_put_byte7(&g_il_ex,uVar9), (char)iVar7 == '\0')) {
          *g_il_ex.bytes.cur = 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          *(uint *)g_il_ex.bytes.cur = uVar9;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
        }
        break;
      case '\x15':
        uVar11 = CONCAT11((undefined1)g_pragma_inline_recursion,(undefined1)g_pragma_inline_depth);
        bVar4 = il_buffer_reserve_ok(&g_il_ex,3);
LAB_1040d72e:
        if (bVar4 != 0) {
          il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar11);
        }
        break;
      case '\x17':
        pragma_warning_state_emit((byte)sub);
      }
      cVar3 = g_il_pragma_byte_operand;
      uVar11 = g_asm_align_size;
      uVar9 = g_il_line_offset;
      cVar1 = *pcVar10;
    }
  }
  return;
}

