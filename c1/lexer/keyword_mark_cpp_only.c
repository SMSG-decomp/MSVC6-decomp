void __cdecl keyword_mark_cpp_only(byte *spelling)

{
  name_intern_keyword(spelling);
  if ((g_last_name->flags & 0x10000) != 0) {
    g_last_name->token_kind = 0xf6;
    g_last_name->keyword_class = '\x02';
  }
  return;
}

