void __cdecl keyword_unreserve(byte *name)

{
  name_intern_keyword(name);
  g_last_name->flags = g_last_name->flags & 0xfffeffff;
  return;
}

