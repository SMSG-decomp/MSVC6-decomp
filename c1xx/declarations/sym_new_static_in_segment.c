c1_symbol * __cdecl sym_new_static_in_segment(void *name,c1_type *type,void *segment)

{
  c1_symbol *sym;
  byte bVar1;
  
  sym = sym_new_object(name,'\0');
  sym->type = type;
  bVar1 = sym->storage & 0xf8 ^ 3;
  sym->storage = bVar1;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  sym->storage = (sym->storage ^ bVar1 & 7) & 7 ^ sym->storage;
  sym_mark_referenced(sym);
  if (segment != (void *)0x0) {
    sym_set_segment(sym,segment);
    g_file_scope_decl_since_body = 1;
    return sym;
  }
  sym->flags23 = sym->flags23 & 0xfe;
  g_file_scope_decl_since_body = 1;
  return sym;
}

