int __cdecl format_declaration_text(c1_symbol *sym,c1_type *type)

{
  int buf;
  int handle;
  char *s;
  
  buf = format_buffer_alloc();
  if (type == (c1_type *)0x0) {
    if (sym == (c1_symbol *)0x0) {
      return buf;
    }
    type = sym->type;
    if (type == (c1_type *)0x0) goto LAB_1063cf01;
  }
  format_basic_type_name(buf,type,'\x01');
LAB_1063cf01:
  handle = format_declarator_name_text(sym,type);
  s = format_buffer_text(handle);
  format_buffer_append_string(buf,s);
  format_buffer_free(handle);
  return buf;
}

