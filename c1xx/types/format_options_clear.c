void __cdecl format_options_clear(uint bits)

{
  _g_format_name_flags = _g_format_name_flags & ~bits;
  return;
}

