void __cdecl pch_relocate_symbol_free_lists(void)

{
  uint *slot;
  int iVar1;
  char cVar2;
  void *cell;
  void **link_slot;
  uint **ppuVar3;
  
  ppuVar3 = g_symbol_free_lists + 1;
  do {
    slot = *ppuVar3;
    if (slot != (uint *)0x0) {
      pch_relocate_slot_once(&g_pch_image,(uint)slot);
      pch_relocate_symbol((byte *)(slot + -2));
      cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)(slot + 1));
      if (cVar2 != '\0') {
        cell = (void *)slot[1];
        if ((*(byte *)((int)cell + -8) & 0x1f) == 4) {
          pch_relocate_symbol_list(cell);
          cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)((int)cell + 0x2c));
          if (cVar2 != '\0') {
            iVar1 = *(int *)((int)cell + 0x2c);
            pch_relocate_slot_once(&g_pch_image,iVar1 + 8);
            link_slot = (void **)(iVar1 + 4);
            cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)link_slot);
            if (cVar2 != '\0') {
              cell = *link_slot;
              if ((*(byte *)((int)cell + -8) & 0x1f) != 4) goto LAB_10643ab3;
              pch_relocate_tag_symbol_list(cell);
            }
          }
        }
        else {
LAB_10643ab3:
          pch_relocate_symbol_list(cell);
        }
      }
    }
    ppuVar3 = ppuVar3 + 1;
    if (0x1065d56b < (int)ppuVar3) {
      return;
    }
  } while( true );
}

