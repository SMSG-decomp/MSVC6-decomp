void __thiscall diag_format_message(c1_message *msg,c1_message_buffer *out)

{
  byte bVar1;
  fe_name *name;
  char byte_arg_2;
  char byte_arg;
  char cVar2;
  char cVar3;
  char byte_arg_4;
  char byte_arg_3;
  int iVar4;
  byte *pbVar5;
  c1_line_map_row *pcVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  c1_u32 cVar11;
  c1_symbol *pcVar12;
  c1_type *pcVar13;
  uint uStack_100;
  c1_message cStack_fc;
  c1_u32 cStack_b4;
  byte bStack_b0;
  char pad_af [3];
  byte *pbStack_a4;
  DWORD DStack_a0;
  c1_u32 cStack_9c;
  c1_u32 cStack_98;
  c1_symbol *pcStack_94;
  c1_u32 cStack_90;
  int iStack_8c;
  c1_symbol *pcStack_88;
  c1_type *pcStack_84;
  byte bStack_80;
  uint int64_lo;
  uint int64_hi;
  ulong local_74;
  char local_70;
  int local_6c;
  char local_68 [64];
  int local_28;
  byte *local_24;
  byte *local_20;
  void *seh_saved_esp;
  void *pvStack_14;
  void *seh_handler;
  void *seh_scope_table;
  int seh_try_level;
  
  seh_try_level = -1;
  seh_scope_table = &g_diag_format_message_scopetable;
  seh_handler = &_except_handler3;
  pvStack_14 = ExceptionList;
  seh_saved_esp = &stack0xfffffe78;
  if (msg->text == (char *)0x0) {
    return;
  }
  ExceptionList = &pvStack_14;
  iVar4 = format_buffer_acquire();
  format_buffer_free(iVar4);
  local_24 = (byte *)msg->text;
  iVar4 = 0;
  local_28 = 0;
  pbVar5 = local_24;
  local_20 = local_24;
LAB_1043c9ff:
  while (bVar1 = *local_20, bVar1 != 0) {
    if (bVar1 == 0x25) {
      if (local_20 != pbVar5) {
        uVar8 = (int)local_20 - (int)pbVar5;
        if (out->room < uVar8) {
          byte_arg_2 = diag_message_buffer_grow(out);
        }
        else {
          byte_arg_2 = '\x01';
        }
        if (byte_arg_2 == '\0') {
          cVar11 = out->room;
        }
        else {
          if (uVar8 <= out->room) {
LAB_1043ca42:
            strncpy(out->cur,(char *)pbVar5,uVar8);
            out->cur = out->cur + uVar8;
            out->room = out->room - uVar8;
            goto LAB_1043ca6a;
          }
          if (out->room < uVar8) goto LAB_10489a68;
          byte_arg = '\x01';
          while (cVar11 = out->room, byte_arg != '\0') {
            if (uVar8 <= cVar11) goto LAB_1043ca42;
LAB_10489a68:
            byte_arg = diag_message_buffer_grow(out);
          }
        }
        diag_message_buffer_append_n((int *)out,(char *)pbVar5,cVar11);
      }
LAB_1043ca6a:
      seh_try_level = 0;
      local_24 = (byte *)0x0;
      local_70 = '\0';
      iVar9 = iVar4;
      switch(local_20[1]) {
      case 0x24:
        local_20 = local_20 + 2;
LAB_10489b49:
        bStack_80 = *local_20;
        local_20 = local_20 + 1;
LAB_10489b55:
        iVar4 = iVar9;
        switch(bStack_80) {
        case 0x2a:
          goto switchD_10489b6c_caseD_2a;
        default:
          local_24 = (byte *)misc_string_get(0x134);
          goto LAB_10489bb5;
        case 0x42:
          pcStack_84 = msg->args[iVar9].type;
          iVar4 = iVar9 + 1;
          pcVar13 = pcStack_84;
          local_28 = iVar4;
          if (pcStack_84 != (c1_type *)0x0) {
            for (; (char)pcVar13->code < '\0'; pcVar13 = pcVar13->base) {
            }
            local_24 = (byte *)type_keyword_text(pcVar13->code);
          }
          goto LAB_10489bb5;
        case 0x43:
          pcVar12 = msg->args[iVar9].sym;
          iVar4 = iVar9 + 1;
          pcStack_88 = pcVar12;
          local_28 = iVar4;
          if (pcVar12 == (c1_symbol *)0x0) goto LAB_10489bb5;
          iStack_8c = format_buffer_alloc();
          if (((pcVar12->kind & 0x1f) != 0xf) ||
             (pcVar12 = g_scope_vector->entries[(short)pcVar12->key_ref], pcStack_88 = pcVar12,
             pcVar12 != (c1_symbol *)0x0)) {
            format_qualified_name(iStack_8c,&pcVar12->kind);
            local_24 = (byte *)format_buffer_text(iStack_8c);
            if ((local_70 == '\0') || (cStack_90 = pcVar12->position, cStack_90 == 0))
            goto LAB_10489bb5;
            diag_note(0x18a6,cStack_90,pcVar12);
          }
          break;
        case 0x44:
          pcVar12 = msg->args[iVar9].sym;
          iVar4 = iVar9 + 1;
          pcStack_94 = pcVar12;
          local_28 = iVar4;
          if (pcVar12 != (c1_symbol *)0x0) {
            if ((local_70 != '\0') && (cStack_98 = pcVar12->position, cStack_98 != 0)) {
              diag_note(0x18a6,cStack_98,pcVar12);
            }
            pcVar13 = (c1_type *)0x0;
            goto LAB_10489c9f;
          }
          goto LAB_10489bb5;
        case 0x45:
          DStack_a0 = msg->args[iVar9].value;
          local_28 = iVar9 + 1;
          FormatMessageA(0x1100,(LPCVOID)0x0,DStack_a0,0x400,(LPSTR)&local_24,0,(va_list *)0x0);
          break;
        case 0x49:
          name = msg->args[iVar9].name;
          iVar4 = iVar9 + 1;
          local_28 = iVar4;
          if ((name != (fe_name *)0x0) && (local_24 = (byte *)name->text, *local_24 == 0x3f)) {
            if (local_24[1] == 0x25) {
              local_24 = (byte *)0x104cab8c;
            }
            else {
              iVar9 = format_undecorated_name(0,name);
              local_24 = (byte *)format_buffer_text(iVar9);
            }
          }
          goto LAB_10489bb5;
        case 0x4c:
          _bStack_b0 = CONCAT31(pad_af,msg->args[iVar9].ch);
          iVar4 = iVar9 + 1;
          local_24 = (byte *)g_token_spelling[(byte)msg->args[iVar9].ch];
          local_28 = iVar4;
          goto LAB_10489bb5;
        case 0x4d:
          cStack_b4 = msg->args[iVar9].value;
          iVar4 = iVar9 + 1;
          local_28 = iVar4;
          if (cStack_b4 != 0) {
            local_24 = (byte *)misc_string_get(cStack_b4);
          }
          goto LAB_10489bb5;
        case 0x4e:
          if (out->room == 0) {
            cVar3 = diag_message_buffer_grow(out);
          }
          else {
            cVar3 = '\x01';
          }
          if (cVar3 != '\0') {
            *out->cur = '\n';
            out->cur = out->cur + 1;
          }
          cVar11 = g_diag_message_list.indent;
          if (out->room < g_diag_message_list.indent) {
            cVar3 = diag_message_buffer_grow(out);
          }
          else {
            cVar3 = '\x01';
          }
          if (cVar3 == '\0') {
            diag_message_buffer_fill((int *)out,' ',out->room);
          }
          else {
            while (cVar11 != 0) {
              *out->cur = ' ';
              out->cur = out->cur + 1;
              cVar11 = cVar11 - 1;
            }
          }
          local_24 = (byte *)0x104bc264;
LAB_10489bb5:
          if (local_24 == (byte *)0x0) {
            local_24 = (byte *)misc_string_get(0x134);
            goto LAB_10489bca;
          }
          goto LAB_1043cb14;
        case 0x4f:
          pbStack_a4 = (byte *)0x0;
          local_28 = iVar9 + 1;
          FormatMessageA(0x1100,(LPCVOID)0x0,msg->args[iVar9].value,0x400,(LPSTR)&pbStack_a4,0,
                         (va_list *)0x0);
          local_24 = pbStack_a4;
          iVar4 = iVar9 + 1;
          goto LAB_10489bb5;
        case 0x50:
          uStack_100 = msg->args[iVar9].value;
          iVar4 = iVar9 + 1;
          local_28 = iVar4;
          if (g_line_map_cached_row.position == uStack_100) {
            pcVar6 = &g_line_map_cached_row;
          }
          else {
            pcVar6 = pp_line_map_find_entry(&g_line_map,uStack_100);
          }
          iVar9 = (pcVar6->line - pcVar6->position) + uStack_100;
          pcVar7 = pp_position_file_name((int *)&uStack_100);
          diag_message_from_format(&cStack_fc.base,"%s(%d)",pcVar7,iVar9);
          diag_format_message(&cStack_fc,out);
          local_24 = (byte *)0x104bc264;
          goto LAB_10489bb5;
        case 0x53:
          pcVar12 = msg->args[iVar9].sym;
          iVar4 = iVar9 + 1;
          local_28 = iVar4;
          if (pcVar12 != (c1_symbol *)0x0) {
            if ((local_70 != '\0') && (pcVar12->position != 0)) {
              diag_note(0x18a6,pcVar12->position,pcVar12);
            }
            if ((pcVar12->kind & 0x1f) == 0x12) {
              local_24 = base_path_text_for_diag(*(int **)pcVar12->type,0);
            }
            else {
              local_24 = (byte *)diag_symbol_display_name(pcVar12);
            }
          }
          goto LAB_10489bb5;
        case 0x54:
          pcVar13 = msg->args[iVar9].type;
          iVar4 = iVar9 + 1;
          local_28 = iVar4;
          if (pcVar13 == (c1_type *)0x0) {
            local_24 = (byte *)misc_string_get(0x159);
          }
          else {
            pcVar12 = (c1_symbol *)0x0;
LAB_10489c9f:
            iVar4 = format_symbol_declaration_text(pcVar12,pcVar13);
            local_24 = (byte *)format_buffer_text(iVar4);
            iVar4 = iVar9 + 1;
          }
          goto LAB_10489bb5;
        case 0x65:
          cStack_9c = msg->args[iVar9].value;
          local_28 = iVar9 + 1;
          local_24 = (byte *)strerror(cStack_9c);
          iVar4 = iVar9 + 1;
          goto LAB_10489bb5;
        case 0x70:
          goto switchD_10489b6c_caseD_70;
        case 0x73:
          goto switchD_10489b6c_caseD_73;
        }
        iVar4 = iVar9 + 1;
        goto LAB_10489bb5;
      default:
        local_24 = (byte *)0x104c0ea8;
LAB_10489bca:
        diag_format_message_append_fragment
                  ((char *)local_24,out,iVar4,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 0x44:
      case 0x55:
      case 0x58:
        int64_lo = msg->args[iVar4].value;
        int64_hi = *(uint *)((int)msg->args + iVar4 * 8 + 4);
        local_6c = (-(uint)(local_20[1] != 0x58) & 0xfffffffa) + 0x10;
        local_28 = iVar4 + 1;
        local_24 = (byte *)int64_to_string((int *)&int64_lo,local_68,local_6c,
                                           (uint)(local_20[1] == 0x55));
        local_20 = local_20 + 2;
        diag_format_message_append_fragment
                  ((char *)local_24,out,iVar4 + 1,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 99:
        cVar3 = msg->args[iVar4].ch;
        iVar4 = iVar4 + 1;
        local_28 = iVar4;
        if (out->room == 0) {
          cVar2 = diag_message_buffer_grow(out);
        }
        else {
          cVar2 = '\x01';
        }
        if (cVar2 != '\0') {
          *out->cur = cVar3;
          out->cur = out->cur + 1;
        }
        local_20 = local_20 + 2;
        diag_format_message_append_fragment
                  ((char *)local_24,out,iVar4,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 100:
      case 0x75:
      case 0x78:
        goto switchD_1043ca8d_caseD_64;
      case 0x73:
        local_20 = local_20 + 2;
switchD_10489b6c_caseD_73:
        local_24 = (byte *)msg->args[iVar9].text;
        local_28 = iVar9 + 1;
        diag_format_message_append_fragment
                  ((char *)local_24,out,local_28,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      }
    }
    local_20 = local_20 + 1;
    if (((byte)_mbctype_exref[bVar1 + 1] & 4) != 0) {
      diag_format_message_body
                (local_20,pbVar5,out,msg,iVar4,(c1_diag_format_frame *)&stack0xfffffffc);
      return;
    }
  }
  if (local_20 <= pbVar5) goto LAB_1043cb89;
  uVar8 = (int)local_20 - (int)pbVar5;
  if (out->room < uVar8) {
    byte_arg_4 = diag_message_buffer_grow(out);
  }
  else {
    byte_arg_4 = '\x01';
  }
  if (byte_arg_4 == '\0') {
    cVar11 = out->room;
    goto LAB_1048a0c6;
  }
  if (uVar8 <= out->room) goto LAB_1043cbc5;
  if (out->room < uVar8) goto LAB_1048a0b9;
  byte_arg_3 = '\x01';
  goto LAB_1048a0aa;
switchD_1043ca8d_caseD_64:
  local_6c = (-(uint)(local_20[1] != 0x78) & 0xfffffffa) + 0x10;
  local_74 = msg->args[iVar4].value;
  iVar4 = iVar4 + 1;
  local_28 = iVar4;
  if (local_20[1] == 0x75) {
    local_24 = (byte *)_ultoa(local_74,local_68,10);
  }
  else {
    local_24 = (byte *)_ltoa(local_74,local_68,local_6c);
  }
  local_20 = local_20 + 2;
  if (local_24 != (byte *)0x0) {
LAB_1043cb14:
    pbVar5 = local_24;
    uVar8 = 0xffffffff;
    pbVar10 = local_24;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      bVar1 = *pbVar10;
      pbVar10 = pbVar10 + 1;
    } while (bVar1 != 0);
    uVar8 = ~uVar8 - 1;
    if (out->room < uVar8) {
      cVar3 = diag_message_buffer_grow(out);
    }
    else {
      cVar3 = '\x01';
    }
    if (cVar3 == '\0') {
      cVar11 = out->room;
    }
    else {
      do {
        if (uVar8 <= out->room) {
          strncpy(out->cur,(char *)pbVar5,uVar8);
          out->cur = out->cur + uVar8;
          out->room = out->room - uVar8;
          goto LAB_1043cb6b;
        }
        if (out->room < uVar8) {
          cVar3 = diag_message_buffer_grow(out);
        }
        else {
          cVar3 = '\x01';
        }
      } while (cVar3 != '\0');
      cVar11 = out->room;
    }
    diag_message_buffer_append_n((int *)out,(char *)pbVar5,cVar11);
  }
LAB_1043cb6b:
  local_24 = local_20;
  seh_try_level = -1;
  pbVar5 = local_20;
  goto LAB_1043c9ff;
switchD_10489b6c_caseD_70:
  local_70 = '\x01';
  goto LAB_10489b49;
switchD_10489b6c_caseD_2a:
  bStack_80 = msg->args[iVar9].ch;
  iVar9 = iVar9 + 1;
  local_28 = iVar9;
  goto LAB_10489b55;
LAB_1048a0aa:
  if (byte_arg_3 == '\0') goto LAB_1048a0c2;
  if (uVar8 <= out->room) goto LAB_1043cbc5;
LAB_1048a0b9:
  byte_arg_3 = diag_message_buffer_grow(out);
  goto LAB_1048a0aa;
LAB_1043cbc5:
  strncpy(out->cur,(char *)pbVar5,uVar8);
  out->cur = out->cur + uVar8;
  out->room = out->room - uVar8;
  goto LAB_1043cb89;
LAB_1048a0c2:
  cVar11 = out->room;
LAB_1048a0c6:
  diag_message_buffer_append_n((int *)out,(char *)pbVar5,cVar11);
LAB_1043cb89:
  format_buffer_leave();
  ExceptionList = pvStack_14;
  return;
}

