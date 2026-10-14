uint * __cdecl decl_specifiers_of_symbol(uint *spec,c1_symbol *sym)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint local_18;
  c1_symbol *local_14;
  void *local_10;
  void *local_c;
  int local_8;
  byte local_4;
  
  local_18._0_1_ = sym->storage;
  local_18._1_1_ = sym->flags21;
  local_18._2_1_ = sym->flags22;
  local_18._3_1_ = sym->flags23;
  if (((sym->flags23 & 1) == 0) ||
     (local_14 = sym_segment_record(sym), local_14 == (c1_symbol *)0x0)) {
    local_18 = local_18 & 0xfeffffff;
    local_14 = (c1_symbol *)0x0;
  }
  else {
    local_18 = local_18 | 0x1000000;
  }
  if (((sym->flags21 & 0x40) == 0) || (local_c = sym_extra_record(sym), local_c == (void *)0x0)) {
    local_c = (void *)0x0;
    local_18 = local_18 & 0xffffbfff;
  }
  else {
    local_18 = local_18 | 0x4000;
  }
  bVar1 = sym->kind & 0x1f;
  if ((((bVar1 == 7) || (bVar1 == 8)) && ((*(byte *)((int)&sym->tail + 10) & 0x80) != 0)) &&
     (local_8 = sym_list_1b58_value(sym), local_8 != 0)) {
    bVar1 = local_4 | 1;
  }
  else {
    bVar1 = local_4 & 0xfe;
    local_8 = 0;
  }
  bVar2 = sym->kind & 0x1f;
  if ((((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) &&
     ((*(byte *)((int)&sym->tail + 0xb) & 1) != 0)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  if ((sym->flags23 & 0x80) == 0) {
    local_10 = (void *)0x0;
  }
  else {
    local_10 = symtab_1b40_lookup(sym);
  }
  if (((sym->kind & 0x1f) == 4) && ((((sym->detail).cls)->layout_flags3c & 0x80) != 0)) {
    bVar1 = cVar3 << 3 | bVar1 & 0xf7 | 2;
  }
  else {
    bVar1 = cVar3 << 3 | bVar1 & 0xf5;
  }
  local_4 = bVar1 & 0xfb;
  puVar5 = &local_18;
  puVar6 = spec;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return spec;
}

