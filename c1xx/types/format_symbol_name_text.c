int __cdecl format_symbol_name_text(int buf,c1_symbol *sym)

{
  format_buffer_append_string(buf,sym->name->text);
  format_buffer_append_char(buf,' ');
  return buf;
}

