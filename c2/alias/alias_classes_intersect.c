uint32_t __fastcall alias_classes_intersect(uint32_t a,uint32_t b)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if (((a == b) || (a == 1)) || (b == 1)) {
    return 1;
  }
  if (g_alias_class_count <= a) {
    iVar3 = a - g_alias_class_count;
    a = g_alias_secondary_records[iVar3].parent;
    if (b < g_alias_class_count) goto LAB_10702522;
    if ((a == g_alias_secondary_records[b - g_alias_class_count].parent) &&
       (g_alias_field_overlap_test != 0)) {
      return 1 << ((byte)g_alias_secondary_records[b - g_alias_class_count].bit & 0x1f) &
             g_alias_secondary_records[iVar3].overlap;
    }
  }
  if (g_alias_class_count <= b) {
    b = g_alias_secondary_records[b - g_alias_class_count].parent;
  }
LAB_10702522:
  puVar2 = g_alias_class_symbol_sets[b]->words;
  uVar1 = (g_alias_class_symbol_sets[a]->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar1 != 0) {
    iVar3 = (int)g_alias_class_symbol_sets[a]->words - (int)puVar2;
    do {
      if ((*puVar2 & *(uint *)(iVar3 + (int)puVar2)) != 0) {
        return 1;
      }
      puVar2 = puVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 0;
}

