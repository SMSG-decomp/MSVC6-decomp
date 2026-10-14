void __cdecl il_emit_source_file_change(int sub,int sub_arg)

{
  char cVar1;
  c1_u8 cVar2;
  byte bVar3;
  c1_u8 cVar4;
  int iVar5;
  uint uVar6;
  c1_line_map_row *pcVar7;
  uint id;
  char *pcVar8;
  ushort uVar9;
  undefined4 in_stack_00000010;
  
  pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
  if (pcVar7->file->key_ref >> 3 != g_il_last_file_key) {
    if (1 < g_il_block_level) {
      _unlink(g_object_file_name);
    }
    if (sub != 0x23) {
      il_emit_byte_record('O');
      iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
      g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
      if (g_il_ex.open != 0) {
        *g_il_ex.bytes.cur = (c1_u8)sub;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
      }
    }
    pcVar8 = *(char **)(&g_pragma_subop_codes + sub * 8);
    if (pcVar8 != (char *)0x0) {
      cVar1 = *pcVar8;
      cVar2 = g_il_pragma_byte_operand;
      uVar6 = g_il_line_offset;
      while (g_il_pragma_byte_operand = cVar2, g_il_line_offset = uVar6, cVar1 != '\0') {
        pcVar8 = pcVar8 + 1;
        switch(cVar1) {
        case '\x01':
          pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          uVar6 = (pcVar7->line - pcVar7->position) + g_token_position;
          g_il_line_base = uVar6;
          if (g_c9il_mode != '\0') goto LAB_1040d712;
          iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
          g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
          if ((g_il_ex.open != 0) &&
             (iVar5 = il_buffer_put_byte7(&g_il_ex,uVar6), (char)iVar5 == '\0')) {
            *g_il_ex.bytes.cur = 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *(uint *)g_il_ex.bytes.cur = uVar6;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
          }
          g_il_last_line_offset = 0;
          break;
        case '\x02':
          g_il_last_line_offset = uVar6;
LAB_1040d712:
          uVar9 = (ushort)uVar6;
          iVar5 = il_buffer_reserve(&g_il_ex.bytes,4);
          bVar3 = g_il_ex.open & (byte)iVar5 & 1;
          g_il_ex.open = bVar3;
          goto LAB_1040d72e;
        case '\x03':
          if (g_c9il_mode == '\0') {
            il_emit_end_of_globals();
            pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
            uVar6 = pcVar7->file->key_ref;
            id = uVar6 >> 3;
            g_il_last_file_key = id;
            if (g_c9il_mode != '\0') goto LAB_1040d79f;
            iVar5 = il_buffer_reserve(&g_il_ex.bytes,4);
            g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
            if (g_il_ex.open != 0) {
              bVar3 = (byte)id;
              if (id < 0x3fff80) {
                if (0x3fff < id) {
                  *g_il_ex.bytes.cur = bVar3 | 0xc0;
                  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                  *g_il_ex.bytes.cur = (c1_u8)(uVar6 >> 9);
                  goto LAB_1047e617;
                }
                *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar6 >> 9);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
              else {
                *g_il_ex.bytes.cur = bVar3 + 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
            }
          }
          else {
            pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
            if ((pcVar7->file->entity & 0xffffff) == 0) {
              il_emit_symbol(0x12,(c1_symbol *)0x0);
            }
            pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
            uVar6 = pcVar7->file->entity;
            id = uVar6 & 0xffffff;
            if (g_c9il_mode == '\0') {
              iVar5 = il_buffer_reserve(&g_il_ex.bytes,4);
              g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
              if (g_il_ex.open != 0) {
                if (id < 0x3fff80) {
                  bVar3 = (byte)uVar6;
                  if (id < 0x4000) {
                    *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
                    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                    *g_il_ex.bytes.cur = (c1_u8)(id >> 6);
                    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                  }
                  else {
                    *g_il_ex.bytes.cur = bVar3 | 0xc0;
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
          uVar9 = (ushort)g_asm_instruction_record.length;
          cVar2 = il_buffer_reserve_ok(&g_il_ex,uVar9 + 3);
          if (cVar2 != '\0') {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar9);
            il_buffer_put_bytes(&g_il_ex,(uint *)&g_asm_instruction_record,(uint)uVar9);
          }
          break;
        case '\r':
          cVar4 = il_buffer_reserve_ok(&g_il_ex,1);
          if (cVar4 != '\0') {
            *g_il_ex.bytes.cur = cVar2;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
          break;
        case '\x0e':
          uVar6 = (uint)in_stack_00000010 >> 0x10;
          in_stack_00000010 = CONCAT22((short)uVar6,g_asm_align_size);
          cVar2 = il_buffer_reserve_ok(&g_il_ex,3);
          if (cVar2 != '\0') {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,(ushort)in_stack_00000010);
          }
          break;
        case '\x14':
          g_opt_Oa = g_opt_Oa | g_opt_Ow;
          uVar6 = il_function_option_word();
          cVar2 = il_buffer_reserve_ok(&g_il_ex,5);
          if ((cVar2 != '\0') && (iVar5 = il_buffer_put_byte7(&g_il_ex,uVar6), (char)iVar5 == '\0'))
          {
            *g_il_ex.bytes.cur = 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *(uint *)g_il_ex.bytes.cur = uVar6;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
          }
          break;
        case '\x15':
          uVar9 = CONCAT11((undefined1)g_pragma_inline_recursion,(undefined1)g_pragma_inline_depth);
          bVar3 = il_buffer_reserve_ok(&g_il_ex,3);
LAB_1040d72e:
          if (bVar3 != 0) {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar9);
          }
          break;
        case '\x17':
          pragma_warning_state_emit((byte)sub);
        }
        sub = sub_arg;
        cVar2 = g_il_pragma_byte_operand;
        uVar6 = g_il_line_offset;
        cVar1 = *pcVar8;
      }
    }
  }
  return;
}

