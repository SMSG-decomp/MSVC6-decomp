void __cdecl parse_error_resync_token(void)

{
  uint uVar1;
  
  if (g_yy_lookahead == (byte *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)g_token_class[*g_yy_lookahead];
  }
  switch(uVar1) {
  case 5:
  case 0x6d:
  case 0xf7:
    if ((g_parse_resync_statics_guard & 2) == 0) {
      g_parse_resync_statics_guard = g_parse_resync_statics_guard | 2;
      g_parse_resync_end_position = 0;
      c1xx_atexit(&parse_error_resync_end_position_dtor);
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)g_yy_lookahead);
    if (g_token_position != g_parse_resync_end_position) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_semicolon);
      g_parse_resync_end_feed = 1;
      g_parse_resync_end_position = g_token_position;
      return;
    }
    if (g_parse_resync_end_feed == 1) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_semicolon);
      g_parse_resync_end_feed = 2;
      return;
    }
    if (g_parse_resync_end_feed == 2) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_rbrace);
      g_parse_resync_end_feed = 3;
      return;
    }
    diag_fatal_simple(1);
  case 0x75:
  case 0x7b:
    if ((g_parse_resync_statics_guard & 1) == 0) {
      g_parse_resync_statics_guard = g_parse_resync_statics_guard | 1;
      g_parse_resync_brace_position = 0;
      c1xx_atexit(&parse_error_resync_brace_position_dtor);
    }
    if (g_token_position != g_parse_resync_brace_position) {
      if (g_yy_lookahead == (byte *)0x0) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = (uint)g_token_class[*g_yy_lookahead];
      }
      diag_error(0x8f,0x7f,uVar1);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)g_yy_lookahead);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_semicolon);
      g_parse_resync_brace_position = g_token_position;
      return;
    }
    break;
  case 0x7e:
  case 0xbf:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
      return;
    }
  }
  return;
}

