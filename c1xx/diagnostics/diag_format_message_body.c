void diag_format_message_body
               (byte *cursor,byte *literal,c1_message_buffer *out,c1_message *msg,int index,
               c1_diag_format_frame *frame)

{
  byte bVar1;
  ulong _Val;
  DWORD DVar2;
  fe_name *name;
  char cVar3;
  char *pcVar4;
  int iVar5;
  c1_line_map_row *pcVar6;
  c1_u8 cVar7;
  uint uVar8;
  byte *cursor_00;
  int iVar9;
  c1_u32 cVar10;
  c1_u8 *s;
  c1_symbol *pcVar11;
  uint n;
  c1_type *pcVar12;
  byte ctype;
  
  frame[-1].cursor = cursor + 1;
  cursor_00 = cursor + 1;
LAB_1043c9ff:
  while (bVar1 = *cursor_00, bVar1 != 0) {
    if (bVar1 == 0x25) {
      if (cursor_00 == literal) goto LAB_1043ca6a;
      uVar8 = (int)cursor_00 - (int)literal;
      frame[-1].literal_length = uVar8;
      frame[-1].literal_start = literal;
      if (out->room < uVar8) {
        cVar3 = diag_message_buffer_grow(out);
        uVar8 = frame[-1].literal_length;
      }
      else {
        cVar3 = '\x01';
      }
      if (cVar3 == '\0') {
        n = out->room;
        s = frame[-1].literal_start;
LAB_10489a7f:
        diag_message_buffer_append_n((int *)out,(char *)s,n);
      }
      else {
        if (out->room < uVar8) {
          if (out->room < uVar8) goto LAB_10489a68;
          cVar3 = '\x01';
          while (n = out->room, cVar3 != '\0') {
            if (uVar8 <= n) goto LAB_1043ca42;
LAB_10489a68:
            cVar3 = diag_message_buffer_grow(out);
            uVar8 = frame[-1].literal_length;
          }
          s = frame[-1].literal_start;
          goto LAB_10489a7f;
        }
LAB_1043ca42:
        strncpy(out->cur,(char *)frame[-1].literal_start,frame[-1].literal_length);
        cVar10 = frame[-1].literal_length;
        out->cur = out->cur + cVar10;
        out->room = out->room - cVar10;
      }
      cursor_00 = frame[-1].cursor;
LAB_1043ca6a:
      pcVar4 = (char *)0x0;
      frame[-1].seh_try_level = 0;
      frame[-1].piece = (char *)0x0;
      frame[-1].see_declaration = '\0';
      iVar9 = index;
      switch(cursor_00[1]) {
      case 0x24:
        frame[-1].cursor = frame[-1].cursor + 2;
LAB_10489b49:
        cVar7 = *frame[-1].cursor;
        frame[-1].directive = cVar7;
        frame[-1].cursor = frame[-1].cursor + 1;
LAB_10489b55:
        index = iVar9;
        switch(cVar7) {
        case '*':
          goto switchD_10489b6c_caseD_2a;
        default:
          pcVar4 = misc_string_get(0x134);
          frame[-1].piece = pcVar4;
          goto LAB_10489bb5;
        case 'B':
          pcVar12 = msg->args[iVar9].type;
          frame[-1].b_type = pcVar12;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (pcVar12 != (c1_type *)0x0) {
            for (; frame[-1].b_base_cursor = pcVar12, (char)pcVar12->code < '\0';
                pcVar12 = pcVar12->base) {
            }
            pcVar4 = type_keyword_text(pcVar12->code);
            frame[-1].piece = pcVar4;
          }
          goto LAB_10489bb5;
        case 'C':
          pcVar11 = msg->args[iVar9].sym;
          frame[-1].c_symbol = pcVar11;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (pcVar11 == (c1_symbol *)0x0) goto LAB_10489bb5;
          iVar5 = format_buffer_alloc();
          frame[-1].c_buffer = iVar5;
          if ((pcVar11->kind & 0x1f) == 0xf) {
            pcVar11 = g_scope_vector->entries[(short)pcVar11->key_ref];
            frame[-1].c_scope_symbol = pcVar11;
            frame[-1].c_symbol = pcVar11;
            if (pcVar11 == (c1_symbol *)0x0) break;
          }
          format_qualified_name(iVar5,&pcVar11->kind);
          pcVar4 = format_buffer_text(frame[-1].c_buffer);
          frame[-1].piece = pcVar4;
          if (frame[-1].see_declaration == '\0') goto LAB_10489bb5;
          cVar10 = pcVar11->position;
          frame[-1].c_position = cVar10;
          if (cVar10 == 0) goto LAB_10489bb5;
          diag_note(0x18a6,cVar10,pcVar11);
          break;
        case 'D':
          pcVar11 = msg->args[iVar9].sym;
          frame[-1].d_symbol = pcVar11;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (pcVar11 != (c1_symbol *)0x0) {
            if (frame[-1].see_declaration != '\0') {
              cVar10 = pcVar11->position;
              frame[-1].d_position = cVar10;
              if (cVar10 != 0) {
                diag_note(0x18a6,cVar10,pcVar11);
              }
            }
            pcVar12 = (c1_type *)0x0;
            goto LAB_10489c9f;
          }
          goto LAB_10489bb5;
        case 'E':
          DVar2 = msg->args[iVar9].value;
          frame[-1].e_error = DVar2;
          frame[-1].arg_index = iVar9 + 1;
          FormatMessageA(0x1100,(LPCVOID)0x0,DVar2,0x400,(LPSTR)&frame[-1].piece,0,(va_list *)0x0);
          break;
        case 'I':
          name = msg->args[iVar9].name;
          frame[-1].i_name = name;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (name != (fe_name *)0x0) {
            pcVar4 = name->text;
            frame[-1].piece = pcVar4;
            if (*pcVar4 == '?') {
              if (pcVar4[1] == '%') {
                pcVar4 = "`anonymous-namespace\'";
                frame[-1].piece = "`anonymous-namespace\'";
              }
              else {
                iVar9 = format_undecorated_name(0,name);
                pcVar4 = format_buffer_text(iVar9);
                frame[-1].piece = pcVar4;
              }
            }
          }
          goto LAB_10489bb5;
        case 'L':
          frame[-1].l_token = msg->args[iVar9].ch;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          uVar8._0_1_ = frame[-0xffffffff00000001].l_token;
          uVar8._1_1_ = frame[-0xffffffff00000001].pad0d5[0];
          uVar8._2_1_ = frame[-0xffffffff00000001].pad0d5[1];
          uVar8._3_1_ = frame[-0xffffffff00000001].pad0d5[2];
          pcVar4 = g_token_spelling[uVar8 & 0xff];
          frame[-1].piece = pcVar4;
          goto LAB_10489bb5;
        case 'M':
          cVar10 = msg->args[iVar9].value;
          frame[-1].m_string_id = cVar10;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (cVar10 != 0) {
            pcVar4 = misc_string_get(cVar10);
            frame[-1].piece = pcVar4;
          }
          goto LAB_10489bb5;
        case 'N':
          if (out->room == 0) {
            cVar3 = diag_message_buffer_grow(out);
          }
          else {
            cVar3 = '\x01';
          }
          frame[-1].n_newline_fits = cVar3;
          if (cVar3 != '\0') {
            *out->cur = '\n';
            out->cur = out->cur + 1;
          }
          cVar10 = g_diag_message_list.indent;
          frame[-1].n_indent = g_diag_message_list.indent;
          frame[-1].n_indent_left = cVar10;
          if (out->room < cVar10) {
            cVar3 = diag_message_buffer_grow(out);
          }
          else {
            cVar3 = '\x01';
          }
          frame[-1].n_indent_fits = cVar3;
          if (cVar3 == '\0') {
            diag_message_buffer_fill((int *)out,' ',out->room);
          }
          else {
            while( true ) {
              frame[-1].n_indent_left = cVar10 - 1;
              if (cVar10 == 0) break;
              *out->cur = ' ';
              out->cur = out->cur + 1;
              cVar10 = cVar10 - 1;
            }
          }
          pcVar4 = "";
          frame[-1].piece = "";
LAB_10489bb5:
          if ((c1_u8 *)pcVar4 == (c1_u8 *)0x0) {
            pcVar4 = misc_string_get(0x134);
            goto LAB_10489bca;
          }
          goto LAB_1043cb14;
        case 'O':
          DVar2 = msg->args[iVar9].value;
          frame[-1].o_error = DVar2;
          frame[-1].arg_index = iVar9 + 1;
          frame[-1].o_text = (char *)0x0;
          FormatMessageA(0x1100,(LPCVOID)0x0,DVar2,0x400,(LPSTR)&frame[-1].o_text,0,(va_list *)0x0);
          pcVar4 = frame[-1].o_text;
          frame[-1].piece = pcVar4;
          index = iVar9 + 1;
          goto LAB_10489bb5;
        case 'P':
          uVar8 = msg->args[iVar9].value;
          frame[-1].p_position = uVar8;
          frame[-1].arg_index = iVar9 + 1;
          frame[-1].p_file_position = uVar8;
          frame[-1].p_line_position = uVar8;
          if (g_line_map_cached_row.position == uVar8) {
            pcVar6 = &g_line_map_cached_row;
          }
          else {
            pcVar6 = pp_line_map_find_entry(&g_line_map,uVar8);
          }
          frame[-1].p_line_row = pcVar6;
          iVar5 = (pcVar6->line - pcVar6->position) + frame[-1].p_file_position;
          pcVar4 = pp_position_file_name((int *)&frame[-1].p_file_position);
          diag_message_from_format(&frame[-1].p_message.base,"%s(%d)",pcVar4,iVar5);
          diag_format_message(&frame[-1].p_message,out);
          pcVar4 = "";
          frame[-1].piece = "";
          index = iVar9 + 1;
          goto LAB_10489bb5;
        case 'S':
          pcVar11 = msg->args[iVar9].sym;
          frame[-1].s_symbol = pcVar11;
          index = iVar9 + 1;
          frame[-1].arg_index = index;
          if (pcVar11 != (c1_symbol *)0x0) {
            if (frame[-1].see_declaration != '\0') {
              cVar10 = pcVar11->position;
              frame[-1].s_position = cVar10;
              if (cVar10 != 0) {
                diag_note(0x18a6,cVar10,pcVar11);
              }
            }
            if ((pcVar11->kind & 0x1f) == 0x12) {
              pcVar4 = (char *)base_path_text_for_diag(*(int **)pcVar11->type,0);
              frame[-1].piece = pcVar4;
            }
            else {
              pcVar4 = diag_symbol_display_name(pcVar11);
              frame[-1].piece = pcVar4;
            }
          }
          goto LAB_10489bb5;
        case 'T':
          pcVar12 = msg->args[iVar9].type;
          frame[-1].t_type = pcVar12;
          frame[-1].arg_index = iVar9 + 1;
          if (pcVar12 == (c1_type *)0x0) {
            pcVar4 = misc_string_get(0x159);
            frame[-1].piece = pcVar4;
            index = iVar9 + 1;
          }
          else {
            pcVar11 = (c1_symbol *)0x0;
LAB_10489c9f:
            iVar5 = format_symbol_declaration_text(pcVar11,pcVar12);
            pcVar4 = format_buffer_text(iVar5);
            frame[-1].piece = pcVar4;
            index = iVar9 + 1;
          }
          goto LAB_10489bb5;
        case 'e':
          cVar10 = msg->args[iVar9].value;
          frame[-1].errno_value = cVar10;
          frame[-1].arg_index = iVar9 + 1;
          pcVar4 = strerror(cVar10);
          frame[-1].piece = pcVar4;
          index = iVar9 + 1;
          goto LAB_10489bb5;
        case 'p':
          goto switchD_10489b6c_caseD_70;
        case 's':
          goto switchD_10489b6c_caseD_73;
        }
        index = iVar9 + 1;
        pcVar4 = frame[-1].piece;
        goto LAB_10489bb5;
      default:
        pcVar4 = "%";
LAB_10489bca:
        frame[-1].piece = pcVar4;
        diag_format_message_append_fragment(pcVar4,out,index,frame);
        return;
      case 0x44:
      case 0x55:
      case 0x58:
        frame[-1].int64_lo = (c1_u32)msg->args[index].sym;
        frame[-1].int64_hi = *(c1_u32 *)((int)msg->args + index * 8 + 4);
        frame[-1].arg_index = index + 1;
        cVar7 = frame[-1].cursor[1];
        iVar9 = (-(uint)(cVar7 != 'X') & 0xfffffffa) + 0x10;
        frame[-1].radix = iVar9;
        pcVar4 = int64_to_string((int *)&frame[-1].int64_lo,frame[-1].number_text,iVar9,
                                 (uint)(cVar7 == 'U'));
        frame[-1].piece = pcVar4;
        frame[-1].cursor = frame[-1].cursor + 2;
        diag_format_message_append_fragment(pcVar4,out,index + 1,frame);
        return;
      case 99:
        frame[-1].c_char = msg->args[index].ch;
        frame[-1].arg_index = index + 1;
        if (out->room == 0) {
          cVar3 = diag_message_buffer_grow(out);
          frame[-1].c_fits = cVar3;
          pcVar4 = frame[-1].piece;
        }
        else {
          cVar3 = '\x01';
          frame[-1].c_fits = '\x01';
        }
        if (cVar3 != '\0') {
          *out->cur = frame[-1].c_char;
          out->cur = out->cur + 1;
          pcVar4 = frame[-1].piece;
        }
        frame[-1].cursor = frame[-1].cursor + 2;
        diag_format_message_append_fragment(pcVar4,out,index + 1,frame);
        return;
      case 100:
      case 0x75:
      case 0x78:
        goto switchD_1043ca8d_caseD_64;
      case 0x73:
        frame[-1].cursor = frame[-1].cursor + 2;
switchD_10489b6c_caseD_73:
        pcVar4 = msg->args[iVar9].text;
        frame[-1].piece = pcVar4;
        frame[-1].arg_index = iVar9 + 1;
        diag_format_message_append_fragment(pcVar4,out,iVar9 + 1,frame);
        return;
      }
    }
    ctype = (byte)_mbctype_exref[bVar1 + 1];
    cursor_00 = frame[-1].cursor + 1;
    frame[-1].cursor = cursor_00;
    if ((ctype & 4) != 0) {
      diag_format_message_body(cursor_00,literal,out,msg,index,frame);
      return;
    }
  }
  if (cursor_00 <= literal) goto LAB_1043cb89;
  uVar8 = (int)cursor_00 - (int)literal;
  if (out->room < uVar8) {
    cVar3 = diag_message_buffer_grow(out);
  }
  else {
    cVar3 = '\x01';
  }
  if (cVar3 == '\0') {
    cVar10 = out->room;
    goto LAB_1048a0c6;
  }
  if (uVar8 <= out->room) goto LAB_1043cbc5;
  if (out->room < uVar8) goto LAB_1048a0b9;
  cVar3 = '\x01';
LAB_1048a0aa:
  if (cVar3 == '\0') goto LAB_1048a0c2;
  if (uVar8 <= out->room) goto LAB_1043cbc5;
LAB_1048a0b9:
  cVar3 = diag_message_buffer_grow(out);
  goto LAB_1048a0aa;
LAB_1043cbc5:
  strncpy(out->cur,(char *)literal,uVar8);
  out->cur = out->cur + uVar8;
  out->room = out->room - uVar8;
  goto LAB_1043cb89;
switchD_1043ca8d_caseD_64:
  cVar7 = frame[-1].cursor[1];
  iVar9 = (-(uint)(cVar7 != 'x') & 0xfffffffa) + 0x10;
  frame[-1].radix = iVar9;
  _Val = msg->args[index].value;
  frame[-1].int_value = _Val;
  index = index + 1;
  frame[-1].arg_index = index;
  if (cVar7 == 'u') {
    pcVar4 = _ultoa(_Val,frame[-1].number_text,10);
  }
  else {
    pcVar4 = _ltoa(_Val,frame[-1].number_text,iVar9);
  }
  frame[-1].piece = pcVar4;
  frame[-1].cursor = frame[-1].cursor + 2;
  if ((c1_u8 *)pcVar4 != (c1_u8 *)0x0) {
LAB_1043cb14:
    frame[-1].append_text = pcVar4;
    uVar8 = 0xffffffff;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar7 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar7 != '\0');
    uVar8 = ~uVar8 - 1;
    frame[-1].append_length = uVar8;
    if (out->room < uVar8) {
      cVar3 = diag_message_buffer_grow(out);
    }
    else {
      cVar3 = '\x01';
    }
    frame[-1].append_fits = cVar3;
    if (cVar3 == '\0') {
      cVar10 = out->room;
      pcVar4 = frame[-1].append_text;
    }
    else {
      do {
        if (uVar8 <= out->room) {
          strncpy(out->cur,frame[-1].append_text,uVar8);
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
        frame[-1].append_retry_ok = cVar3;
      } while (cVar3 != '\0');
      cVar10 = out->room;
      pcVar4 = frame[-1].append_text;
    }
    diag_message_buffer_append_n((int *)out,pcVar4,cVar10);
  }
LAB_1043cb6b:
  literal = frame[-1].cursor;
  frame[-1].piece = (char *)literal;
  frame[-1].seh_try_level = -1;
  msg = frame[-1].msg;
  cursor_00 = literal;
  goto LAB_1043c9ff;
switchD_10489b6c_caseD_70:
  frame[-1].see_declaration = '\x01';
  goto LAB_10489b49;
switchD_10489b6c_caseD_2a:
  cVar7 = msg->args[iVar9].ch;
  frame[-1].directive = cVar7;
  iVar9 = iVar9 + 1;
  frame[-1].arg_index = iVar9;
  goto LAB_10489b55;
LAB_1048a0c2:
  cVar10 = out->room;
LAB_1048a0c6:
  diag_message_buffer_append_n((int *)out,(char *)literal,cVar10);
LAB_1043cb89:
  format_buffer_leave();
  ExceptionList = frame[-1].seh_next;
  return;
}

