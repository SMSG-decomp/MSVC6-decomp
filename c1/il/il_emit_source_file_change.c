char __cdecl il_emit_source_file_change(int kind,int kind_arg)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  PB puVar7;
  uint id;
  byte *pbVar8;
  ushort uVar9;
  undefined4 in_stack_00000010;
  
  piVar6 = include_line_map_find(&g_lex_position,g_token_position);
  puVar7 = (PB)g_il_last_file_key;
  if (*(uint *)(piVar6[2] + 8) >> 3 != g_il_last_file_key) {
    if (1 < g_il_block_level) {
      puVar7 = (PB)_unlink(g_object_file_name);
    }
    if (kind != 0x23) {
      il_emit_byte_record('O');
      iVar4 = il_buffer_reserve(&g_il_ex.bytes,2);
      bVar1 = (byte)iVar4 & 1;
      puVar7 = (PB)(uint)bVar1;
      g_il_ex.open = g_il_ex.open & bVar1;
      if (g_il_ex.open != 0) {
        *g_il_ex.bytes.pbEnd = (uchar)kind;
        puVar7 = g_il_ex.bytes.pbEnd + 1;
        g_il_ex.bytes.pbEnd = puVar7;
      }
    }
    pbVar8 = (byte *)g_pragma_subop_codes[kind].codes;
    if (pbVar8 != (byte *)0x0) {
      bVar1 = *pbVar8;
      cVar2 = g_il_pragma_byte_operand;
      uVar5 = g_il_line_offset;
      while (puVar7 = (PB)(uint)bVar1, g_il_pragma_byte_operand = cVar2, g_il_line_offset = uVar5,
            bVar1 != 0) {
        pbVar8 = pbVar8 + 1;
        switch(bVar1) {
        case 1:
          piVar6 = include_line_map_find(&g_lex_position,g_token_position);
          uVar5 = (piVar6[1] - *piVar6) + g_token_position;
          g_il_line_base = uVar5;
          if (g_c9il_mode != '\0') goto LAB_106047d5;
          iVar4 = il_buffer_reserve(&g_il_ex.bytes,6);
          g_il_ex.open = g_il_ex.open & (byte)iVar4 & 1;
          if ((g_il_ex.open != 0) &&
             (iVar4 = il_buffer_put_byte7(&g_il_ex,uVar5), (char)iVar4 == '\0')) {
            *g_il_ex.bytes.pbEnd = 0x80;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            *(uint *)g_il_ex.bytes.pbEnd = uVar5;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
          }
          g_il_last_line_offset = 0;
          break;
        case 2:
          g_il_last_line_offset = uVar5;
LAB_106047d5:
          uVar9 = (ushort)uVar5;
          iVar4 = il_buffer_reserve(&g_il_ex.bytes,4);
          bVar1 = g_il_ex.open & (byte)iVar4 & 1;
          g_il_ex.open = bVar1;
          goto LAB_106047f1;
        case 3:
          if (g_c9il_mode == '\0') {
            il_emit_end_of_globals();
            piVar6 = include_line_map_find(&g_lex_position,g_token_position);
            uVar5 = *(uint *)(piVar6[2] + 8);
            id = uVar5 >> 3;
            g_il_last_file_key = id;
            if (g_c9il_mode != '\0') goto LAB_10604862;
            iVar4 = il_buffer_reserve(&g_il_ex.bytes,4);
            g_il_ex.open = g_il_ex.open & (byte)iVar4 & 1;
            if (g_il_ex.open != 0) {
              bVar1 = (byte)id;
              if (id < 0x3fff80) {
                if (0x3fff < id) {
                  *g_il_ex.bytes.pbEnd = bVar1 | 0xc0;
                  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                  *g_il_ex.bytes.pbEnd = (uchar)(uVar5 >> 9);
                  goto LAB_1063a658;
                }
                *g_il_ex.bytes.pbEnd = bVar1 & 0x3f | 0x80;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                *g_il_ex.bytes.pbEnd = (uchar)(uVar5 >> 9);
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              }
              else {
                *g_il_ex.bytes.pbEnd = bVar1 + 0x80;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              }
            }
          }
          else {
            piVar6 = include_line_map_find(&g_lex_position,g_token_position);
            if ((*(uint *)(piVar6[2] + 0xc) & 0xffffff) == 0) {
              il_emit_symbol(0x12,(c1_symbol *)0x0);
            }
            piVar6 = include_line_map_find(&g_lex_position,g_token_position);
            uVar5 = *(uint *)(piVar6[2] + 0xc);
            id = uVar5 & 0xffffff;
            if (g_c9il_mode == '\0') {
              iVar4 = il_buffer_reserve(&g_il_ex.bytes,4);
              g_il_ex.open = g_il_ex.open & (byte)iVar4 & 1;
              if (g_il_ex.open != 0) {
                if (id < 0x3fff80) {
                  bVar1 = (byte)uVar5;
                  if (id < 0x4000) {
                    *g_il_ex.bytes.pbEnd = bVar1 & 0x3f | 0x80;
                    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                    *g_il_ex.bytes.pbEnd = (uchar)(id >> 6);
                    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                  }
                  else {
                    *g_il_ex.bytes.pbEnd = bVar1 | 0xc0;
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
          uVar9 = (ushort)g_asm_instruction_record[0];
          cVar2 = il_buffer_reserve_ok(&g_il_ex,uVar9 + 3);
          if (cVar2 != '\0') {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar9);
            il_buffer_put_bytes(&g_il_ex,(uint *)g_asm_instruction_record,(uint)uVar9);
          }
          break;
        case 0xd:
          cVar3 = il_buffer_reserve_ok(&g_il_ex,1);
          if (cVar3 != '\0') {
            *g_il_ex.bytes.pbEnd = cVar2;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          }
          break;
        case 0xe:
          uVar5 = (uint)in_stack_00000010 >> 0x10;
          in_stack_00000010 = CONCAT22((short)uVar5,g_asm_align_size);
          cVar2 = il_buffer_reserve_ok(&g_il_ex,3);
          if (cVar2 != '\0') {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,(ushort)in_stack_00000010);
          }
          break;
        case 0x14:
          g_opt_Oa = g_opt_Oa | g_opt_Ow;
          uVar5 = il_function_option_word();
          cVar2 = il_buffer_reserve_ok(&g_il_ex,5);
          if ((cVar2 != '\0') && (iVar4 = il_buffer_put_byte7(&g_il_ex,uVar5), (char)iVar4 == '\0'))
          {
            *g_il_ex.bytes.pbEnd = 0x80;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            *(uint *)g_il_ex.bytes.pbEnd = uVar5;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
          }
          break;
        case 0x15:
          uVar9 = CONCAT11((undefined1)g_pragma_inline_recursion,(undefined1)g_pragma_inline_depth);
          bVar1 = il_buffer_reserve_ok(&g_il_ex,3);
LAB_106047f1:
          if (bVar1 != 0) {
            il_buffer_put_compact_u16_unchecked(&g_il_ex,uVar9);
          }
          break;
        case 0x17:
          pragma_warning_state_emit((c1_u8)kind);
        }
        kind = kind_arg;
        cVar2 = g_il_pragma_byte_operand;
        uVar5 = g_il_line_offset;
        bVar1 = *pbVar8;
      }
    }
  }
  return (char)puVar7;
}

