void diag_format_message_conversions_fragment
               (fe_message_buffer *buf,fe_message *m,int index,c1_diag_format_frame *frame)

{
  byte bVar1;
  code cVar2;
  c1_u32 cVar3;
  ulong _Val;
  byte *literal;
  DWORD DVar4;
  c1_symbol *pcVar5;
  fe_name *pfVar6;
  char cVar7;
  c1_u8 cVar8;
  c1_type *pcVar9;
  char *pcVar10;
  fe_line_map_row *pfVar11;
  int iVar12;
  byte *scan;
  c1_u8 *pcVar13;
  uint n;
  uint uVar14;
  
code_r0x1064312a:
  pcVar13 = frame[-1].cursor + 2;
  frame[-1].cursor = pcVar13;
LAB_10643133:
  cVar8 = *pcVar13;
  frame[-1].directive = cVar8;
  pcVar13 = pcVar13 + 1;
  frame[-1].cursor = pcVar13;
LAB_1064313c:
  switch(cVar8) {
  case '*':
    goto switchD_10643153_caseD_2a;
  default:
    uVar14 = 0x134;
    break;
  case 'B':
    pcVar9 = m->args[index].type;
    frame[-1].b_type = pcVar9;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pcVar9 == (c1_type *)0x0) goto LAB_10643277;
    for (; frame[-1].b_base_cursor = pcVar9, (char)pcVar9->code < '\0'; pcVar9 = pcVar9->base) {
    }
    pcVar10 = type_keyword_text(pcVar9->code);
LAB_106431e4:
    frame[-1].piece = pcVar10;
LAB_10643277:
    pcVar10 = frame[-1].piece;
    if (pcVar10 == (char *)0x0) {
      pcVar10 = misc_string_get(0x134);
LAB_1064328f:
      frame[-1].piece = pcVar10;
      diag_format_message_append_fragment(pcVar10,buf,index,frame);
      return;
    }
LAB_1061e44f:
    frame[-1].append_text = pcVar10;
    uVar14 = 0xffffffff;
    do {
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      cVar7 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar7 != '\0');
    uVar14 = ~uVar14 - 1;
    frame[-1].append_length = uVar14;
    if (buf->room < uVar14) {
      cVar7 = diag_message_buffer_grow(buf);
    }
    else {
      cVar7 = '\x01';
    }
    frame[-1].append_fits = cVar7;
    if (cVar7 == '\0') {
      uVar14 = buf->room;
      pcVar10 = frame[-1].append_text;
    }
    else {
      do {
        if (uVar14 <= buf->room) {
          strncpy(buf->cur,frame[-1].append_text,uVar14);
          buf->cur = buf->cur + uVar14;
          buf->room = buf->room - uVar14;
          goto LAB_1061e4a6;
        }
        if (buf->room < uVar14) {
          cVar7 = diag_message_buffer_grow(buf);
        }
        else {
          cVar7 = '\x01';
        }
        frame[-1].append_retry_ok = cVar7;
      } while (cVar7 != '\0');
      uVar14 = buf->room;
      pcVar10 = frame[-1].append_text;
    }
    diag_message_buffer_append_n(buf,pcVar10,uVar14);
LAB_1061e4a6:
    literal = frame[-1].cursor;
    frame[-1].piece = (char *)literal;
    frame[-1].seh_try_level = -1;
    m = frame[-1].msg;
    scan = literal;
    while( true ) {
      bVar1 = *scan;
      if (bVar1 == 0) {
        if (scan <= literal) goto LAB_1061e4c4;
        uVar14 = (int)scan - (int)literal;
        if (buf->room < uVar14) {
          cVar7 = diag_message_buffer_grow(buf);
        }
        else {
          cVar7 = '\x01';
        }
        if (cVar7 == '\0') {
          uVar14 = buf->room;
          goto LAB_106435ee;
        }
        if (uVar14 <= buf->room) goto LAB_1061e500;
        if (buf->room < uVar14) goto LAB_106435e1;
        cVar7 = '\x01';
        goto LAB_106435d2;
      }
      if (bVar1 == 0x25) break;
      cVar2 = _mbctype_exref[bVar1 + 1];
      scan = frame[-1].cursor + 1;
      frame[-1].cursor = scan;
      if (((byte)cVar2 & 4) != 0) {
        diag_format_message_literal_fragment(scan,literal,buf,m,index,frame);
        return;
      }
    }
    if (scan != literal) {
      uVar14 = (int)scan - (int)literal;
      frame[-1].literal_length = uVar14;
      frame[-1].literal_start = literal;
      if (buf->room < uVar14) {
        cVar7 = diag_message_buffer_grow(buf);
        uVar14 = frame[-1].literal_length;
      }
      else {
        cVar7 = '\x01';
      }
      if (cVar7 == '\0') {
        n = buf->room;
        pcVar13 = frame[-1].literal_start;
LAB_1064306f:
        diag_message_buffer_append_n(buf,(char *)pcVar13,n);
      }
      else {
        if (buf->room < uVar14) {
          if (buf->room < uVar14) goto LAB_10643058;
          cVar7 = '\x01';
          while (n = buf->room, cVar7 != '\0') {
            if (uVar14 <= n) goto LAB_1061e3d2;
LAB_10643058:
            cVar7 = diag_message_buffer_grow(buf);
            uVar14 = frame[-1].literal_length;
          }
          pcVar13 = frame[-1].literal_start;
          goto LAB_1064306f;
        }
LAB_1061e3d2:
        strncpy(buf->cur,(char *)frame[-1].literal_start,frame[-1].literal_length);
        cVar3 = frame[-1].literal_length;
        buf->cur = buf->cur + cVar3;
        buf->room = buf->room - cVar3;
      }
      scan = frame[-1].cursor;
    }
    frame[-1].seh_try_level = 0;
    frame[-1].piece = (char *)0x0;
    frame[-1].see_declaration = '\0';
    bVar1 = scan[1];
    switch(bVar1) {
    case 0x24:
      goto code_r0x1064312a;
    default:
      pcVar10 = "%";
      goto LAB_1064328f;
    case 0x44:
    case 0x55:
    case 0x58:
      frame[-1].int64_lo = m->args[index].value;
      frame[-1].int64_hi = *(c1_u32 *)((int)m->args + index * 8 + 4);
      frame[-1].arg_index = index + 1;
      cVar8 = frame[-1].cursor[1];
      iVar12 = (-(uint)(cVar8 != 'X') & 0xfffffffa) + 0x10;
      frame[-1].radix = iVar12;
      pcVar10 = int64_to_string((int *)&frame[-1].int64_lo,frame[-1].number_text,iVar12,
                                (uint)(cVar8 == 'U'));
      frame[-1].piece = pcVar10;
      frame[-1].cursor = frame[-1].cursor + 2;
      diag_format_message_append_fragment(pcVar10,buf,index + 1,frame);
      return;
    case 99:
      frame[-1].c_char = m->args[index].ch;
      frame[-1].arg_index = index + 1;
      if (buf->room == 0) {
        cVar7 = diag_message_buffer_grow(buf);
      }
      else {
        cVar7 = '\x01';
      }
      frame[-1].c_fits = cVar7;
      if (cVar7 != '\0') {
        *buf->cur = frame[-1].c_char;
        buf->cur = buf->cur + 1;
      }
      frame[-1].cursor = frame[-1].cursor + 2;
      diag_format_message_append_fragment(frame[-1].piece,buf,index + 1,frame);
      return;
    case 100:
    case 0x75:
    case 0x78:
      goto switchD_1061e37c_caseD_64;
    case 0x73:
      frame[-1].cursor = frame[-1].cursor + 2;
switchD_10643153_caseD_73:
      pcVar10 = m->args[index].text;
      frame[-1].piece = pcVar10;
      frame[-1].arg_index = index + 1;
      diag_format_message_append_fragment(pcVar10,buf,index + 1,frame);
      return;
    }
  case 'C':
    pcVar5 = m->args[index].sym;
    frame[-1].c_symbol = pcVar5;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pcVar5 == (c1_symbol *)0x0) goto LAB_10643277;
    if (frame[-1].see_declaration != '\0') {
      cVar3 = pcVar5->position;
      frame[-1].c_position = cVar3;
      if (cVar3 != 0) {
        diag_note(0x18a6,cVar3,pcVar5);
      }
    }
    pfVar6 = pcVar5->name;
    frame[-1].c_name = pfVar6;
    pcVar10 = pfVar6->text;
    goto LAB_106431e4;
  case 'D':
    pcVar5 = m->args[index].sym;
    frame[-1].d_symbol = pcVar5;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pcVar5 == (c1_symbol *)0x0) goto LAB_10643277;
    if (frame[-1].see_declaration != '\0') {
      cVar3 = pcVar5->position;
      frame[-1].d_position = cVar3;
      if (cVar3 != 0) {
        diag_note(0x18a6,cVar3,pcVar5);
      }
    }
    iVar12 = format_declaration_text(pcVar5,(c1_type *)0x0);
    pcVar10 = format_buffer_text(iVar12);
    goto LAB_106431e4;
  case 'E':
    DVar4 = m->args[index].value;
    frame[-1].e_error = DVar4;
    index = index + 1;
    frame[-1].arg_index = index;
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar4,0x400,(LPSTR)&frame[-1].piece,0,(va_list *)0x0);
    goto LAB_10643277;
  case 'I':
    pfVar6 = m->args[index].name;
    frame[-1].i_name = pfVar6;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pfVar6 != (fe_name *)0x0) {
      frame[-1].piece = pfVar6->text;
    }
    goto LAB_10643277;
  case 'L':
    frame[-1].l_token.code = m->args[index].ch;
    index = index + 1;
    frame[-1].arg_index = index;
    frame[-1].piece = g_token_spelling[frame[-1].l_token.word & 0xff];
    goto LAB_10643277;
  case 'M':
    uVar14 = m->args[index].value;
    frame[-1].m_string_id = uVar14;
    index = index + 1;
    frame[-1].arg_index = index;
    if (uVar14 == 0) goto LAB_10643277;
    break;
  case 'N':
    if (buf->room == 0) {
      cVar7 = diag_message_buffer_grow(buf);
    }
    else {
      cVar7 = '\x01';
    }
    frame[-1].n_newline_fits = cVar7;
    if (cVar7 != '\0') {
      *buf->cur = '\n';
      buf->cur = buf->cur + 1;
    }
    uVar14 = g_diag_message_list.indent;
    frame[-1].n_indent = g_diag_message_list.indent;
    frame[-1].n_indent_left = uVar14;
    if (buf->room < uVar14) {
      cVar7 = diag_message_buffer_grow(buf);
    }
    else {
      cVar7 = '\x01';
    }
    frame[-1].n_indent_fits = cVar7;
    if (cVar7 == '\0') {
      diag_message_buffer_fill(buf,' ',buf->room);
    }
    else {
      while( true ) {
        frame[-1].n_indent_left = uVar14 - 1;
        if (uVar14 == 0) break;
        *buf->cur = ' ';
        buf->cur = buf->cur + 1;
        uVar14 = uVar14 - 1;
      }
    }
    frame[-1].piece = "";
    goto LAB_10643277;
  case 'O':
    DVar4 = m->args[index].value;
    frame[-1].o_error = DVar4;
    index = index + 1;
    frame[-1].arg_index = index;
    frame[-1].o_text = (char *)0x0;
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar4,0x400,(LPSTR)&frame[-1].o_text,0,(va_list *)0x0);
    pcVar10 = frame[-1].o_text;
    goto LAB_106431e4;
  case 'P':
    uVar14 = m->args[index].value;
    frame[-1].p_position = uVar14;
    index = index + 1;
    frame[-1].arg_index = index;
    frame[-1].p_file_position = uVar14;
    frame[-1].p_line_position = uVar14;
    if (g_line_map_cached_row.position == uVar14) {
      pfVar11 = &g_line_map_cached_row;
    }
    else {
      pfVar11 = pp_line_map_find_entry(&g_line_map,uVar14);
    }
    frame[-1].p_line_row = pfVar11;
    iVar12 = (pfVar11->line - pfVar11->position) + frame[-1].p_file_position;
    pcVar10 = pp_position_file_name(&frame[-1].p_file_position);
    diag_message_from_format(&frame[-1].p_message.base,"%s(%d)",pcVar10,iVar12);
    diag_format_message(&frame[-1].p_message,buf);
    frame[-1].piece = "";
    goto LAB_10643277;
  case 'S':
    pcVar5 = m->args[index].sym;
    frame[-1].s_symbol = pcVar5;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pcVar5 == (c1_symbol *)0x0) goto LAB_10643277;
    if (frame[-1].see_declaration != '\0') {
      cVar3 = pcVar5->position;
      frame[-1].s_position = cVar3;
      if (cVar3 != 0) {
        diag_note(0x18a6,cVar3,pcVar5);
      }
    }
    pfVar6 = pcVar5->name;
    frame[-1].s_name = pfVar6;
    pcVar10 = pfVar6->text;
    goto LAB_106431e4;
  case 'T':
    pcVar9 = m->args[index].type;
    frame[-1].t_type = pcVar9;
    index = index + 1;
    frame[-1].arg_index = index;
    if (pcVar9 != (c1_type *)0x0) {
      iVar12 = format_declaration_text((c1_symbol *)0x0,pcVar9);
      pcVar10 = format_buffer_text(iVar12);
      goto LAB_106431e4;
    }
    uVar14 = 0x159;
    break;
  case 'e':
    uVar14 = m->args[index].value;
    frame[-1].errno_value = uVar14;
    index = index + 1;
    frame[-1].arg_index = index;
    pcVar10 = strerror(uVar14);
    goto LAB_106431e4;
  case 'p':
    goto switchD_10643153_caseD_70;
  case 's':
    goto switchD_10643153_caseD_73;
  }
  pcVar10 = misc_string_get(uVar14);
  goto LAB_106431e4;
switchD_10643153_caseD_70:
  frame[-1].see_declaration = '\x01';
  goto LAB_10643133;
LAB_106435d2:
  if (cVar7 == '\0') goto LAB_106435ea;
  if (uVar14 <= buf->room) goto LAB_1061e500;
LAB_106435e1:
  cVar7 = diag_message_buffer_grow(buf);
  goto LAB_106435d2;
LAB_1061e500:
  strncpy(buf->cur,(char *)literal,uVar14);
  buf->cur = buf->cur + uVar14;
  buf->room = buf->room - uVar14;
  goto LAB_1061e4c4;
switchD_1061e37c_caseD_64:
  iVar12 = (-(uint)(bVar1 != 0x78) & 0xfffffffa) + 0x10;
  frame[-1].radix = iVar12;
  _Val = m->args[index].value;
  frame[-1].int_value = _Val;
  index = index + 1;
  frame[-1].arg_index = index;
  if (bVar1 == 0x75) {
    pcVar10 = _ultoa(_Val,frame[-1].number_text,10);
  }
  else {
    pcVar10 = _ltoa(_Val,frame[-1].number_text,iVar12);
  }
  frame[-1].piece = pcVar10;
  frame[-1].cursor = frame[-1].cursor + 2;
  if (pcVar10 != (char *)0x0) goto LAB_1061e44f;
  goto LAB_1061e4a6;
switchD_10643153_caseD_2a:
  cVar8 = m->args[index].ch;
  frame[-1].directive = cVar8;
  index = index + 1;
  frame[-1].arg_index = index;
  goto LAB_1064313c;
LAB_106435ea:
  uVar14 = buf->room;
LAB_106435ee:
  diag_message_buffer_append_n(buf,(char *)literal,uVar14);
LAB_1061e4c4:
  format_buffer_leave();
  ExceptionList = frame[-1].seh_next;
  return;
}

