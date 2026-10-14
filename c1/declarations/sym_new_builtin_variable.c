void __cdecl sym_new_builtin_variable(void)

{
  fe_name *name;
  c1_symbol *sym;
  byte bVar1;
  char level;
  
  level = '\0';
  name = name_intern(g_pch_symbol_name);
  sym = sym_new_object(name,level);
  bVar1 = sym->storage;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  bVar1 = (sym->storage ^ bVar1 & 7) & 7 ^ sym->storage;
  sym->storage = bVar1;
  sym->storage = bVar1 & 0xf8 ^ 2;
  sym_mark_referenced(sym);
  return;
}

