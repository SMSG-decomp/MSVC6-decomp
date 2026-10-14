char * __cdecl decorate_scope_prefix(char *out,c1_symbol *sym)

{
  char *out_00;
  
  out_00 = decorate_name_with_backreference(out,(int)sym->name,0);
  if (sym->scope_index != 0) {
    out_00 = decorate_scope_chain(out_00,&g_scope_vector->entries[(short)sym->scope_index]->kind);
  }
  *out_00 = '@';
  return out_00 + 1;
}

