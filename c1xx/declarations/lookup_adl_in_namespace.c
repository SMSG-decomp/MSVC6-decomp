c1_symbol_vector * __cdecl
lookup_adl_in_namespace(c1xx_scope *scope,void *name,c1_symbol_vector *vec)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  c1_symbol_vector *pcVar4;
  c1_symbol *found_sym;
  
  piVar2 = scope_lookup_unique((int *)scope,name);
  if (piVar2 == (int *)0x0) {
    found_sym = (c1_symbol *)0x0;
  }
  else {
    found_sym = (c1_symbol *)*piVar2;
  }
  if (found_sym == (c1_symbol *)0x0) {
    return vec;
  }
  bVar1 = found_sym->kind & 0x1f;
  if ((bVar1 != 7) && (bVar1 != 6)) {
    if (bVar1 == 0x1a) {
      iVar3 = sym_is_kind_6_7_through_alias(*(c1_symbol **)found_sym->type);
      if ((char)iVar3 != '\0') goto LAB_104a5c73;
    }
    if ((found_sym->kind & 0x1f) != 0x10) {
      return (c1_symbol_vector *)0x0;
    }
  }
LAB_104a5c73:
  if (vec == (c1_symbol_vector *)0x0) {
    vec = symtab_record_new(1);
  }
  pcVar4 = (c1_symbol_vector *)vector_find_or_add((short *)vec,(int)found_sym);
  return pcVar4;
}

