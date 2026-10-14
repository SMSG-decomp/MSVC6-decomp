void __cdecl intrinsic_unmark_function(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  byte bVar2;
  
  pcVar1 = &sym->storage;
  sym->kind = sym->kind & 0xe7 | 7;
  bVar2 = *pcVar1 & 0xf8 ^ 1;
  *pcVar1 = bVar2;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  bVar2 = (*pcVar1 ^ bVar2 & 7) & 7 ^ *pcVar1;
  *pcVar1 = bVar2;
  *pcVar1 = bVar2 | 0x20;
  return;
}

