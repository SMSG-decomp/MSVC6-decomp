void __cdecl pch_relocate_symbol_symtab(c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  
  pcVar2 = sym->type;
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  if ((pcVar2->code & 0x100) != 0) {
    pch_relocate_slot_once(&g_pch_image,(uint)&sym->tag_members);
    pch_relocate_symtab_entries(sym->tag_members,(void *)0x0,(void *)0x0);
  }
  return;
}

