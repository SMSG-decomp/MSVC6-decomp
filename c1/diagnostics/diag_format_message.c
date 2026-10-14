void __thiscall diag_format_message(fe_message *m,fe_message_buffer *buf)

{
  fe_message_arg *pfVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  byte *pbVar7;
  c1_type *pcVar8;
  fe_line_map_row *pfVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  uint n;
  uint uStack_fc;
  fe_message fStack_f8;
  uint uStack_b0;
  uint arg_char;
  fe_name *pfStack_a8;
  DWORD DStack_a4;
  byte *pbStack_a0;
  DWORD DStack_9c;
  uint uStack_98;
  c1_u32 cStack_94;
  c1_symbol *pcStack_90;
  c1_u32 cStack_8c;
  c1_symbol *pcStack_88;
  c1_type *pcStack_84;
  byte bStack_80;
  c1_symbol *local_7c;
  int value_high;
  ulong local_74;
  char local_70;
  int local_6c;
  char local_68 [64];
  int local_28;
  byte *local_24;
  byte *local_20;
  void *saved_esp;
  void *pvStack_14;
  undefined *puStack_10;
  sehtable_entry *psStack_c;
  int try_level;
  
  try_level = -1;
  psStack_c = &g_diag_format_message_scopetable;
  puStack_10 = &_except_handler3;
  pvStack_14 = ExceptionList;
  saved_esp = &stack0xfffffe78;
  if (m->text == (char *)0x0) {
    return;
  }
  ExceptionList = &pvStack_14;
  iVar6 = format_buffer_acquire();
  format_buffer_free(iVar6);
  local_24 = (byte *)m->text;
  iVar6 = 0;
  local_28 = 0;
  pbVar7 = local_24;
  local_20 = local_24;
LAB_1061e344:
  while (bVar2 = *local_20, bVar2 != 0) {
    if (bVar2 == 0x25) {
      if (local_20 != pbVar7) {
        uVar12 = (int)local_20 - (int)pbVar7;
        if (buf->room < uVar12) {
          cVar4 = diag_message_buffer_grow(buf);
        }
        else {
          cVar4 = '\x01';
        }
        if (cVar4 == '\0') {
          n = buf->room;
        }
        else {
          if (uVar12 <= buf->room) {
LAB_1061e3d2:
            strncpy(buf->cur,(char *)pbVar7,uVar12);
            buf->cur = buf->cur + uVar12;
            buf->room = buf->room - uVar12;
            goto LAB_1061e357;
          }
          if (buf->room < uVar12) goto LAB_10643058;
          cVar4 = '\x01';
          while (n = buf->room, cVar4 != '\0') {
            if (uVar12 <= n) goto LAB_1061e3d2;
LAB_10643058:
            cVar4 = diag_message_buffer_grow(buf);
          }
        }
        diag_message_buffer_append_n(buf,(char *)pbVar7,n);
      }
LAB_1061e357:
      try_level = 0;
      local_24 = (byte *)0x0;
      local_70 = '\0';
      bVar2 = local_20[1];
      switch(bVar2) {
      case 0x24:
        local_20 = local_20 + 2;
LAB_10643133:
        bStack_80 = *local_20;
        local_20 = local_20 + 1;
LAB_1064313c:
        switch(bStack_80) {
        case 0x2a:
          goto switchD_10643153_caseD_2a;
        default:
          uVar12 = 0x134;
          break;
        case 0x42:
          pcStack_84 = m->args[iVar6].type;
          iVar6 = iVar6 + 1;
          pcVar8 = pcStack_84;
          local_28 = iVar6;
          if (pcStack_84 != (c1_type *)0x0) {
            for (; (char)pcVar8->code < '\0'; pcVar8 = pcVar8->base) {
            }
            local_24 = (byte *)type_keyword_text(pcVar8->code);
          }
          goto LAB_10643277;
        case 0x43:
          pcVar3 = m->args[iVar6].sym;
          iVar6 = iVar6 + 1;
          pcStack_88 = pcVar3;
          local_28 = iVar6;
          if (pcVar3 != (c1_symbol *)0x0) {
            if ((local_70 != '\0') && (cStack_8c = pcVar3->position, cStack_8c != 0)) {
              diag_note(0x18a6,cStack_8c,pcVar3);
            }
            local_24 = (byte *)pcVar3->name->text;
          }
          goto LAB_10643277;
        case 0x44:
          pcVar3 = m->args[iVar6].sym;
          iVar6 = iVar6 + 1;
          pcStack_90 = pcVar3;
          local_28 = iVar6;
          if (pcVar3 != (c1_symbol *)0x0) {
            if ((local_70 != '\0') && (cStack_94 = pcVar3->position, cStack_94 != 0)) {
              diag_note(0x18a6,cStack_94,pcVar3);
            }
            iVar11 = format_declaration_text(pcVar3,(c1_type *)0x0);
            local_24 = (byte *)format_buffer_text(iVar11);
          }
          goto LAB_10643277;
        case 0x45:
          DStack_9c = m->args[iVar6].value;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          FormatMessageA(0x1100,(LPCVOID)0x0,DStack_9c,0x400,(LPSTR)&local_24,0,(va_list *)0x0);
          goto LAB_10643277;
        case 0x49:
          pfStack_a8 = m->args[iVar6].name;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          if (pfStack_a8 != (fe_name *)0x0) {
            local_24 = (byte *)pfStack_a8->text;
          }
          goto LAB_10643277;
        case 0x4c:
          pfVar1 = m->args + iVar6;
          arg_char = CONCAT31(arg_char._1_3_,pfVar1->ch);
          iVar6 = iVar6 + 1;
          local_24 = (byte *)g_token_spelling[(byte)pfVar1->ch];
          local_28 = iVar6;
          goto LAB_10643277;
        case 0x4d:
          uVar12 = m->args[iVar6].value;
          iVar6 = iVar6 + 1;
          uStack_b0 = uVar12;
          local_28 = iVar6;
          if (uVar12 == 0) goto LAB_10643277;
          break;
        case 0x4e:
          if (buf->room == 0) {
            cVar4 = diag_message_buffer_grow(buf);
          }
          else {
            cVar4 = '\x01';
          }
          if (cVar4 != '\0') {
            *buf->cur = '\n';
            buf->cur = buf->cur + 1;
          }
          uVar12 = g_diag_message_list.indent;
          if (buf->room < g_diag_message_list.indent) {
            cVar4 = diag_message_buffer_grow(buf);
          }
          else {
            cVar4 = '\x01';
          }
          if (cVar4 == '\0') {
            diag_message_buffer_fill(buf,' ',buf->room);
          }
          else {
            while (uVar12 != 0) {
              *buf->cur = ' ';
              buf->cur = buf->cur + 1;
              uVar12 = uVar12 - 1;
            }
          }
          local_24 = &g_empty_string;
LAB_10643277:
          if (local_24 == (byte *)0x0) {
            local_24 = (byte *)misc_string_get(0x134);
            goto LAB_1064328f;
          }
          goto LAB_1061e44f;
        case 0x4f:
          DStack_a4 = m->args[iVar6].value;
          iVar6 = iVar6 + 1;
          pbStack_a0 = (byte *)0x0;
          local_28 = iVar6;
          FormatMessageA(0x1100,(LPCVOID)0x0,DStack_a4,0x400,(LPSTR)&pbStack_a0,0,(va_list *)0x0);
          local_24 = pbStack_a0;
          goto LAB_10643277;
        case 0x50:
          uStack_fc = m->args[iVar6].value;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          if (g_line_map_cached_row.position == uStack_fc) {
            pfVar9 = &g_line_map_cached_row;
          }
          else {
            pfVar9 = pp_line_map_find_entry(&g_line_map,uStack_fc);
          }
          iVar11 = (pfVar9->line - pfVar9->position) + uStack_fc;
          pcVar10 = pp_position_file_name((int *)&uStack_fc);
          diag_message_from_format(&fStack_f8.base,"%s(%d)",pcVar10,iVar11);
          diag_format_message(&fStack_f8,buf);
          local_24 = &g_empty_string;
          goto LAB_10643277;
        case 0x53:
          pcVar3 = m->args[iVar6].sym;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          if (pcVar3 != (c1_symbol *)0x0) {
            if ((local_70 != '\0') && (pcVar3->position != 0)) {
              diag_note(0x18a6,pcVar3->position,pcVar3);
            }
            local_24 = (byte *)pcVar3->name->text;
          }
          goto LAB_10643277;
        case 0x54:
          pfVar1 = m->args + iVar6;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          if (pfVar1->type != (c1_type *)0x0) {
            iVar11 = format_declaration_text((c1_symbol *)0x0,pfVar1->type);
            local_24 = (byte *)format_buffer_text(iVar11);
            goto LAB_10643277;
          }
          uVar12 = 0x159;
          break;
        case 0x65:
          uStack_98 = m->args[iVar6].value;
          iVar6 = iVar6 + 1;
          local_28 = iVar6;
          local_24 = (byte *)strerror(uStack_98);
          goto LAB_10643277;
        case 0x70:
          goto switchD_10643153_caseD_70;
        case 0x73:
          goto switchD_10643153_caseD_73;
        }
        local_24 = (byte *)misc_string_get(uVar12);
        goto LAB_10643277;
      default:
        local_24 = (byte *)0x1065ad1c;
LAB_1064328f:
        diag_format_message_append_fragment
                  ((char *)local_24,buf,iVar6,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 0x44:
      case 0x55:
      case 0x58:
        local_7c = m->args[iVar6].sym;
        value_high = *(int *)((int)m->args + iVar6 * 8 + 4);
        local_6c = (-(uint)(local_20[1] != 0x58) & 0xfffffffa) + 0x10;
        local_28 = iVar6 + 1;
        local_24 = (byte *)int64_to_string((int *)&local_7c,local_68,local_6c,
                                           (uint)(local_20[1] == 0x55));
        local_20 = local_20 + 2;
        diag_format_message_append_fragment
                  ((char *)local_24,buf,iVar6 + 1,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 99:
        cVar4 = m->args[iVar6].ch;
        iVar6 = iVar6 + 1;
        local_28 = iVar6;
        if (buf->room == 0) {
          cVar5 = diag_message_buffer_grow(buf);
        }
        else {
          cVar5 = '\x01';
        }
        if (cVar5 != '\0') {
          *buf->cur = cVar4;
          buf->cur = buf->cur + 1;
        }
        local_20 = local_20 + 2;
        diag_format_message_append_fragment
                  ((char *)local_24,buf,iVar6,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      case 100:
      case 0x75:
      case 0x78:
        goto switchD_1061e37c_caseD_64;
      case 0x73:
        local_20 = local_20 + 2;
switchD_10643153_caseD_73:
        local_24 = (byte *)m->args[iVar6].text;
        local_28 = iVar6 + 1;
        diag_format_message_append_fragment
                  ((char *)local_24,buf,local_28,(c1_diag_format_frame *)&stack0xfffffffc);
        return;
      }
    }
    local_20 = local_20 + 1;
    if (((byte)_mbctype_exref[bVar2 + 1] & 4) != 0) {
      diag_format_message_literal_fragment
                (local_20,pbVar7,buf,m,iVar6,(c1_diag_format_frame *)&stack0xfffffffc);
      return;
    }
  }
  if (local_20 <= pbVar7) goto LAB_1061e4c4;
  uVar12 = (int)local_20 - (int)pbVar7;
  if (buf->room < uVar12) {
    cVar4 = diag_message_buffer_grow(buf);
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar4 == '\0') {
    uVar12 = buf->room;
    goto LAB_106435ee;
  }
  if (uVar12 <= buf->room) goto LAB_1061e500;
  if (buf->room < uVar12) goto LAB_106435e1;
  cVar4 = '\x01';
  goto LAB_106435d2;
switchD_1061e37c_caseD_64:
  local_6c = (-(uint)(bVar2 != 0x78) & 0xfffffffa) + 0x10;
  local_74 = m->args[iVar6].value;
  iVar6 = iVar6 + 1;
  local_28 = iVar6;
  if (bVar2 == 0x75) {
    local_24 = (byte *)_ultoa(local_74,local_68,10);
  }
  else {
    local_24 = (byte *)_ltoa(local_74,local_68,local_6c);
  }
  local_20 = local_20 + 2;
  if (local_24 != (byte *)0x0) {
LAB_1061e44f:
    pbVar7 = local_24;
    uVar12 = 0xffffffff;
    pbVar13 = local_24;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      bVar2 = *pbVar13;
      pbVar13 = pbVar13 + 1;
    } while (bVar2 != 0);
    uVar12 = ~uVar12 - 1;
    if (buf->room < uVar12) {
      cVar4 = diag_message_buffer_grow(buf);
    }
    else {
      cVar4 = '\x01';
    }
    if (cVar4 == '\0') {
      uVar12 = buf->room;
    }
    else {
      do {
        if (uVar12 <= buf->room) {
          strncpy(buf->cur,(char *)pbVar7,uVar12);
          buf->cur = buf->cur + uVar12;
          buf->room = buf->room - uVar12;
          goto LAB_1061e4a6;
        }
        if (buf->room < uVar12) {
          cVar4 = diag_message_buffer_grow(buf);
        }
        else {
          cVar4 = '\x01';
        }
      } while (cVar4 != '\0');
      uVar12 = buf->room;
    }
    diag_message_buffer_append_n(buf,(char *)pbVar7,uVar12);
  }
LAB_1061e4a6:
  local_24 = local_20;
  try_level = -1;
  pbVar7 = local_20;
  goto LAB_1061e344;
switchD_10643153_caseD_70:
  local_70 = '\x01';
  goto LAB_10643133;
switchD_10643153_caseD_2a:
  bStack_80 = m->args[iVar6].ch;
  iVar6 = iVar6 + 1;
  local_28 = iVar6;
  goto LAB_1064313c;
LAB_106435d2:
  if (cVar4 == '\0') goto LAB_106435ea;
  if (uVar12 <= buf->room) goto LAB_1061e500;
LAB_106435e1:
  cVar4 = diag_message_buffer_grow(buf);
  goto LAB_106435d2;
LAB_1061e500:
  strncpy(buf->cur,(char *)pbVar7,uVar12);
  buf->cur = buf->cur + uVar12;
  buf->room = buf->room - uVar12;
  goto LAB_1061e4c4;
LAB_106435ea:
  uVar12 = buf->room;
LAB_106435ee:
  diag_message_buffer_append_n(buf,(char *)pbVar7,uVar12);
LAB_1061e4c4:
  format_buffer_leave();
  ExceptionList = pvStack_14;
  return;
}

