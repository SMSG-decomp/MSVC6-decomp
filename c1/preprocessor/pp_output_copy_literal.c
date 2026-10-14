void __cdecl pp_output_copy_literal(byte first,char wide)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint _Ch;
  int local_18;
  
  local_18 = 0;
  if (wide != '\0') {
    fputc(0x4c,g_pp_output_stream);
  }
  _Ch = (uint)first;
LAB_10625f17:
  fputc(_Ch,g_pp_output_stream);
LAB_10625f46:
  bVar2 = *g_input_ptr;
  _wide = (uint)bVar2;
  pbVar3 = g_input_ptr + 1;
  switch(g_char_class[bVar2]) {
  case '\0':
    if (bVar2 == 0x3f) goto LAB_1062ded3;
    local_18 = 0;
    if (bVar2 != 0x5c) {
      g_input_ptr = pbVar3;
      lex_buffer_refill();
      goto LAB_10625f46;
    }
    g_input_ptr = pbVar3;
    fputc(0x5c,g_pp_output_stream);
    iVar4 = lex_line_splice();
    if (iVar4 != 0) goto LAB_10625f46;
    g_compile_flags_c8 = g_compile_flags_c8 | 0x4000;
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    fputc((uint)bVar2,g_pp_output_stream);
    if ((g_char_flags[bVar2] & 8) == 0) {
      if ((bVar2 & 0xdf) != 0x58) {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffbfff;
        goto LAB_10625f46;
      }
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      bVar1 = g_char_flags[bVar2];
      while (_wide = (uint)bVar2, (bVar1 & 2) != 0) {
        fputc(_wide,g_pp_output_stream);
        bVar2 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        bVar1 = g_char_flags[bVar2];
      }
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffbfff;
      pbVar3 = g_input_ptr;
    }
    else {
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      iVar4 = 1;
      _wide = (uint)bVar2;
      do {
        if ((g_char_flags[_wide] & 8) == 0) break;
        fputc(_wide,g_pp_output_stream);
        bVar2 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        iVar4 = iVar4 + 1;
        _wide = (uint)bVar2;
      } while (iVar4 < 3);
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffbfff;
      pbVar3 = g_input_ptr;
    }
    break;
  case '\x01':
    g_input_ptr = pbVar3;
    if (bVar2 == 0xd) goto LAB_10625f46;
    break;
  case '\x05':
    return;
  case '#':
    goto switchD_10625f7a_caseD_23;
  }
  g_input_ptr = pbVar3;
  fputc(_wide,g_pp_output_stream);
  if ((bVar2 == first) && ((local_18 < 2 || (first != 0x27)))) {
    return;
  }
  local_18 = 0;
  goto LAB_10625f46;
switchD_10625f7a_caseD_23:
  g_input_ptr = pbVar3;
  fputc((uint)bVar2,g_pp_output_stream);
  bVar2 = lex_skip_mbcs_trail_byte();
  fputc((uint)bVar2,g_pp_output_stream);
  goto LAB_10625f46;
LAB_1062ded3:
  local_18 = local_18 + 1;
  _Ch = 0x3f;
  g_input_ptr = pbVar3;
  goto LAB_10625f17;
}

