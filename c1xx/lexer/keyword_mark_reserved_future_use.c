void __cdecl keyword_mark_reserved_future_use(byte *text)

{
  name_intern_keyword(text);
  if ((g_last_name->flags & 0x10000) != 0) {
    g_last_name->token_kind = 0xf6;
    g_last_name->keyword_class = '\x03';
  }
  return;
}

