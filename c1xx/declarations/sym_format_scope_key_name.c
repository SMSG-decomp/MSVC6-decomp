char * __cdecl sym_format_scope_key_name(c1_symbol *sym,c1_symbol *scope_owner)

{
  byte bVar1;
  char *separator;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) || (separator = "D", bVar1 == 6)) {
    separator = "E";
  }
  _snprintf(g_scope_key_name_buffer,0x1800,"%s.%s.%s",sym->name->text,scope_owner->name->text,
            separator);
  return g_scope_key_name_buffer;
}

