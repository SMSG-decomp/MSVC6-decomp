int __cdecl lex_buffer_refill(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = g_macro_expansion_depth;
  if (g_input_ptr[-1] != 0x3f) {
    if (g_input_ptr[-1] == 0x5c) {
      if ((g_macro_expansion_depth == 0) && (iVar3 = lex_line_splice(), iVar3 != 0)) {
        return 1;
      }
      return 0x10;
    }
    if (g_macro_expansion_depth == 0) {
      lex_check_end_of_file();
      return 1;
    }
    bVar1 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (bVar1 == 0x41) {
      pp_macro_save_expansion
                ((uint *)g_macro_expansion_frames[g_macro_expansion_depth].text,
                 (int)g_macro_text_cursor);
      g_macro_text_cursor = g_macro_expansion_frames[g_macro_expansion_depth].text;
      pp_macro_next_text_segment();
      return 2;
    }
    if (bVar1 == 0x44) {
      iVar3 = pp_macro_expansion_end();
      return (-(uint)(iVar3 != 0) & 4) + 4;
    }
    if (bVar1 == 0x52) {
      bVar4 = g_macro_expansion_depth == 1;
      g_input_ptr = g_macro_expansion_frames[g_macro_expansion_depth].saved_input;
      g_macro_expansion_frames[g_macro_expansion_depth].active = 0;
      if (bVar4) {
        g_macro_arg_cursor = g_macro_arg_buffer;
        g_macro_text_cursor = g_macro_text_buffer;
      }
      if ((g_macro_text_pending == 0) && (g_browse_file != (char *)0x0)) {
        (*g_il_emitter->vtbl->input_refilled)();
        iVar3 = g_macro_expansion_depth;
      }
      g_macro_text_pending = 0;
      g_macro_expansion_depth = iVar3 + -1;
      return 0x20;
    }
    return 0;
  }
  pbVar2 = g_input_ptr + 1;
  if (*g_input_ptr != 0x3f) {
    while ((pbVar2[-1] == 0 && (g_macro_expansion_depth == 0))) {
      g_input_ptr = pbVar2;
      lex_check_end_of_file();
      g_input_ptr[-1] = 0x3f;
      pbVar2 = g_input_ptr + 1;
      if (*g_input_ptr == 0x3f) {
        g_input_ptr = pbVar2;
        iVar3 = lex_trigraph_replace(pbVar2,'?');
        return iVar3;
      }
    }
    g_input_ptr = pbVar2 + -1;
    return 0x40;
  }
  bVar1 = *pbVar2;
  g_input_ptr = g_input_ptr + 2;
joined_r0x10602833:
  if (bVar1 < 0x3f) {
    switch((&switchD_1060283d::switchdataD_1060289c)[bVar1]) {
    case 0:
      if (g_macro_expansion_depth == 0) goto code_r0x1062a05e;
    default:
      goto switchD_1060283d_caseD_1;
    case 0x21:
      g_input_ptr[-1] = 0x7c;
      break;
    case 0x27:
      g_input_ptr[-1] = 0x5e;
      break;
    case 0x28:
      g_input_ptr[-1] = 0x5b;
      break;
    case 0x29:
      g_input_ptr[-1] = 0x5d;
      break;
    case 0x2d:
      g_input_ptr[-1] = 0x7e;
      break;
    case 0x2f:
      g_input_ptr[-1] = 0x5c;
      break;
    case 0x3c:
      g_input_ptr[-1] = 0x7b;
      break;
    case 0x3d:
      g_input_ptr[-1] = 0x23;
      break;
    case 0x3e:
      g_input_ptr[-1] = 0x7d;
    }
    g_input_ptr = g_input_ptr + -1;
    return 1;
  }
switchD_1060283d_caseD_1:
  pbVar2 = g_input_ptr + -2;
  g_input_ptr = g_input_ptr + -1;
  *pbVar2 = 0x3f;
  pbVar2 = g_input_ptr + -2;
  g_input_ptr = g_input_ptr + -1;
  *pbVar2 = 0x3f;
  return 0x40;
code_r0x1062a05e:
  lex_check_end_of_file();
  bVar1 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  goto joined_r0x10602833;
}

