void __fastcall pch_fixup_hash_scope(c1_scope_object *scope)

{
  c1_scope_entries *slot;
  void *cell;
  int iVar1;
  char cVar2;
  uint index;
  void *pvVar3;
  void **link_slot;
  void **link_slot_2;
  uint uStack_4;
  
  pch_fixup_block_scope(scope);
  slot = &scope->entries;
  pch_relocate_slot_once(&g_pch_image,(uint)slot);
  index = 0;
  uStack_4 = 0;
  if (scope->mask != 0xffffffff) {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint)(slot->buckets + index));
      pvVar3 = slot->buckets[index];
      if (pvVar3 != (void *)0x0) {
        if ((*(byte *)((int)pvVar3 - 8) & 0x1f) == 4) {
          pch_relocate_slot_once(&g_pch_image,(uint)pvVar3);
          pch_relocate_symbol((byte *)((int)pvVar3 - 8));
          cVar2 = pch_relocate_slot_once(&g_pch_image,(int)pvVar3 + 4U);
          if (cVar2 != '\0') {
            cell = *(void **)((int)pvVar3 + 4U);
            if ((*(byte *)((int)cell + -8) & 0x1f) == 4) {
              pch_relocate_tag_symbol_list(cell);
            }
            else {
              pch_relocate_symbol_list(cell);
            }
          }
          cVar2 = pch_relocate_slot_once(&g_pch_image,(int)pvVar3 + 0x2cU);
          if (cVar2 != '\0') {
            iVar1 = *(int *)((int)pvVar3 + 0x2cU);
            pch_relocate_slot_once(&g_pch_image,iVar1 + 8);
            link_slot = (void **)(iVar1 + 4);
            cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)link_slot);
            if (cVar2 != '\0') {
              pvVar3 = *link_slot;
              if ((*(byte *)((int)pvVar3 + -8) & 0x1f) == 4) {
                pch_relocate_tag_symbol_list(pvVar3);
              }
              else {
                pch_relocate_slot_once(&g_pch_image,(uint)pvVar3);
                pch_relocate_symbol((byte *)((int)pvVar3 + -8));
                cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)((int)pvVar3 + 4));
                if (cVar2 != '\0') {
                  pvVar3 = *(void **)((int)pvVar3 + 4);
                  if ((*(byte *)((int)pvVar3 + -8) & 0x1f) != 4) goto LAB_10643cfb;
                  pch_relocate_tag_symbol_list(pvVar3);
                }
              }
            }
          }
        }
        else {
          pch_relocate_slot_once(&g_pch_image,(uint)pvVar3);
          pch_relocate_symbol((byte *)((int)pvVar3 - 8));
          cVar2 = pch_relocate_slot_once(&g_pch_image,(int)pvVar3 + 4U);
          if (cVar2 != '\0') {
            pvVar3 = *(void **)((int)pvVar3 + 4U);
            if ((*(byte *)((int)pvVar3 + -8) & 0x1f) == 4) {
              pch_relocate_symbol_list(pvVar3);
              cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)((int)pvVar3 + 0x2c));
              if (cVar2 != '\0') {
                iVar1 = *(int *)((int)pvVar3 + 0x2c);
                pch_relocate_slot_once(&g_pch_image,iVar1 + 8);
                link_slot_2 = (void **)(iVar1 + 4);
                cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)link_slot_2);
                if (cVar2 != '\0') {
                  pvVar3 = *link_slot_2;
                  if ((*(byte *)((int)pvVar3 + -8) & 0x1f) != 4) goto LAB_10643cfb;
                  pch_relocate_tag_symbol_list(pvVar3);
                }
              }
            }
            else {
LAB_10643cfb:
              pch_relocate_symbol_list(pvVar3);
            }
          }
        }
      }
      uStack_4 = uStack_4 + 1;
      index = uStack_4 & 0xffff;
    } while (index < scope->mask + 1);
  }
  return;
}

