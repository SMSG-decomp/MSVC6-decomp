char * __cdecl sym_namespace_member_dotted_name(c1_symbol *sym)

{
  uint uVar1;
  char *pcVar2;
  
  if ((sym->scope_index != 0) &&
     ((g_scope_vector->entries[(short)sym->scope_index]->kind & 0x1f) == 0x19)) {
    uVar1 = decorate_symbol_codes(sym);
    if (uVar1 == 0) {
      pcVar2 = sym_format_scope_key_name(sym,g_scope_vector->entries[(short)sym->scope_index]);
      return pcVar2;
    }
  }
  return (char *)0x0;
}

