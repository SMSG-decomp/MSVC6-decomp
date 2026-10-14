c1_u8 * __cdecl pp_import_parse_line(c1_vector **out,char *angle)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_u8 *item;
  int iVar3;
  c1xx_token *tok;
  char *diag_text;
  c1xx_token *tok_2;
  c1_vector *v;
  c1_vector *v_00;
  short n;
  c1_u8 *local_10;
  c1_string_value local_8;
  char *attr_name;
  char *diag_text_2;
  
  *out = (c1_vector *)0x0;
  iVar3 = g_opt_E_preprocess;
  g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
  local_10 = (c1_u8 *)0x0;
  g_opt_E_preprocess = 0;
  tok = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
  bVar1 = tok->code;
  if (bVar1 == 7) {
    if ((tok->value1 & 0x10000) != 0) {
LAB_104a1e71:
      diag_error(2);
      lex_skip_whitespace();
      g_opt_E_preprocess = iVar3;
      return local_10;
    }
    local_10 = tok->value;
    *angle = '\0';
LAB_104a1d27:
    v_00 = (c1_vector *)0x0;
    tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    cVar2 = tok_2->code;
    while( true ) {
      if (cVar2 == '-') {
        g_opt_E_preprocess = iVar3;
        return local_10;
      }
      v = (c1_vector *)0x0;
      if (v_00 == (c1_vector *)0x0) {
        v_00 = vector_new(3,5);
        *out = v_00;
      }
      else if (cVar2 == '7') {
        tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      }
      item = g_arenas[5].cur;
      if (tok_2->code != '\x06') break;
      g_arenas[5].cur = g_arenas[5].cur + 8;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      attr_name = *(char **)((int)tok_2->value + 4);
      item[4] = '\0';
      item[5] = '\0';
      item[6] = '\0';
      item[7] = '\0';
      *(char **)item = attr_name;
      vector_push(v_00,item);
      tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (tok_2->code == 'v') {
        tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        do {
          if (v == (c1_vector *)0x0) {
            v = vector_new(3,5);
          }
          else {
            if (tok_2->code != '7') goto LAB_104a1ed7;
            tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          }
          if (tok_2->code != '\a') goto LAB_104a1ed7;
          local_8.text = tok_2->value;
          local_8._4_4_ = tok_2->value1;
          if ((local_8._4_4_ & 0x10000) != 0) goto LAB_104a1e71;
          tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          cVar2 = tok_2->code;
          while (cVar2 == '\a') {
            lex_concatenate_strings(&local_8,(c1_string_value *)&tok_2->value);
            tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
            cVar2 = tok_2->code;
          }
          vector_push(v,local_8.text);
        } while (tok_2->code != '~');
        *(c1_vector **)(item + 4) = v;
        tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      }
      cVar2 = tok_2->code;
    }
LAB_104a1ed7:
    if (tok_2->code != 6) {
      diag_error(0x3b,0x73,g_token_spelling[tok_2->code]);
      lex_skip_whitespace();
      g_opt_E_preprocess = iVar3;
      return local_10;
    }
    diag_text_2 = tok_2->value;
    n = 0x3d;
  }
  else {
    if (bVar1 == 0x44) {
      diag_text = pp_include_parse_angle_name('\x01');
      if (diag_text == (char *)0x0) goto LAB_104a1ce9;
      local_10 = str_dup_arena(diag_text,5);
      *angle = '\x01';
      goto LAB_104a1d27;
    }
    diag_text_2 = g_token_spelling[bVar1];
    n = 0x302;
  }
  diag_error(n,diag_text_2);
LAB_104a1ce9:
  lex_skip_whitespace();
  g_opt_E_preprocess = iVar3;
  return local_10;
}

