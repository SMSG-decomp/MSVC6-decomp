char * __cdecl decorate_scope_prefix_2(char *out,c1_symbol *sym)

{
  char cVar1;
  int buf;
  char *pcVar2;
  
  if (sym->scope_index != 0) {
    pcVar2 = decorate_scope_prefix_2(out,g_scope_vector->entries[(short)sym->scope_index]);
    *pcVar2 = ':';
    pcVar2[1] = ':';
    out = pcVar2 + 2;
  }
  if (((sym->kind & 0x1f) == 4) && ((((sym->detail).cls)->flags3e & 1) != 0)) {
    buf = format_buffer_acquire();
    format_options_set(1);
    format_class_template_instance_name(buf,sym);
    pcVar2 = format_buffer_text(buf);
    format_options_clear(1);
    format_buffer_leave();
  }
  else {
    pcVar2 = sym->name->text;
  }
  cVar1 = *pcVar2;
  *out = cVar1;
  while (cVar1 != '\0') {
    cVar1 = pcVar2[1];
    out = out + 1;
    pcVar2 = pcVar2 + 1;
    *out = cVar1;
  }
  return out;
}

