char * __cdecl sym_format_qualified_function_name(c1_symbol *sym,char *buf,uint size)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) && (sym->scope_index != 0)) {
    _snprintf(buf,size,"%s::%s",g_scope_vector->entries[(short)sym->scope_index]->name->text,
              sym->name->text);
    buf[size - 1] = '\0';
    return buf;
  }
  return sym->name->text;
}

