void __cdecl ns_using_declare_target(c1_symbol **result,c1_symbol *sym)

{
  c1_symbol *pcVar1;
  byte bVar2;
  
  pcVar1 = *result;
  bVar2 = pcVar1->kind & 0x1f;
  if ((((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) && (bVar2 != 0x1a)) {
    sym->next = (c1_symbol *)pcVar1->type;
    pcVar1->type = (c1_type *)&sym->name;
    return;
  }
  pcVar1 = decl_new_using_alias(g_current_scope,sym,pcVar1);
  *result = pcVar1;
  return;
}

