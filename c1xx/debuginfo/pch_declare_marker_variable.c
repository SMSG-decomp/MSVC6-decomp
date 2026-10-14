void __cdecl pch_declare_marker_variable(void)

{
  void *name;
  c1_symbol *sym;
  byte bVar1;
  char local;
  
  local = '\0';
  name = name_intern(g_pch_symbol_name);
  sym = sym_new_object(name,local);
  bVar1 = sym->storage;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  bVar1 = (sym->storage ^ bVar1 & 7) & 7 ^ sym->storage;
  sym->storage = bVar1;
  sym->storage = bVar1 & 0xf8 ^ 2;
  sym_mark_referenced(sym);
  sym->flags1 = sym->flags1 & 0xfe | 2;
  return;
}

