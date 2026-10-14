void __cdecl intrinsic_mark_function(c1_symbol *sym,int index)

{
  byte bVar1;
  
  sym->kind = sym->kind & 0xe6 | 6;
  bVar1 = sym->storage & 0xf8 ^ 1;
  sym->storage = bVar1;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  sym->storage = (sym->storage ^ bVar1 & 7) & 7 ^ sym->storage;
  (sym->detail).halves.lo = g_intrinsic_table[index].number;
  (sym->detail).halves.hi = g_intrinsic_table[index].attributes;
  return;
}

