c1_symbol * __cdecl type_parse_based_specifier(void *name)

{
  c1_type *pcVar1;
  c1_lookup_entry *pcVar2;
  ushort uVar3;
  c1_symbol *sym;
  
  pcVar2 = lookup_name_in_context(g_current_scope,name,0x132);
  if (pcVar2 == (c1_lookup_entry *)0x0) {
    diag_error(0x41,name);
    return (c1_symbol *)0x0;
  }
  sym = pcVar2->sym;
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  pcVar1 = sym->type;
  if (((((char)pcVar1->code < '\0') && (pcVar1 != (c1_type *)0x0)) &&
      ((uVar3 = pcVar1->code & 0x8f, uVar3 == 0x86 || (uVar3 == 0x82)))) &&
     ((pcVar1->flags & 8) == 0)) {
    if ((sym->kind & 0x1f) == 3) {
      diag_error(0x125,sym);
      return (c1_symbol *)0x0;
    }
    if (g_opt_Zi != '\0') {
      sym_mark_referenced(sym);
      return sym;
    }
  }
  else {
    diag_error(0xd5,name);
  }
  return sym;
}

