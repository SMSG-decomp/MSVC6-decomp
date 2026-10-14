void __fastcall pch_fixup_hash_scope(c1xx_hash_scope *scope)

{
  c1_sym_link ***slot;
  int cell;
  uint *slot_00;
  char cVar1;
  byte bVar2;
  uint bucket;
  c1_symbol_type_word entry;
  c1_type *slot_01;
  uint *pair_list_slot;
  c1_symbol_type_word slot_02;
  uint local_4;
  uint *pair_list_slot_2;
  
  pch_fixup_scope_common(scope);
  slot = &scope->buckets;
  pch_relocate_slot_once(&g_pch_image,(uint *)slot);
  bucket = 0;
  local_4 = 0;
  if (scope->mask != 0xffffffff) {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint *)(*slot + bucket));
      slot_02 = (c1_symbol_type_word)((c1_symbol_type_word *)(*slot + bucket))->type;
      if (slot_02 != (c1_symbol_type_word)0x0) {
        if ((*(byte *)((int)slot_02 + -8) & 0x1f) == 4) {
          pch_relocate_slot_once(&g_pch_image,(uint *)slot_02.entries);
          pch_relocate_symbol((byte *)((int)slot_02 + -8));
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&(slot_02.ns)->scope_index);
          if (cVar1 != '\0') {
            entry = *(c1_symbol_type_word *)&(slot_02.ns)->scope_index;
            if (((entry.members + -0x10)->position & 0x1f) == 4) {
              pch_relocate_class_member_list((int)entry);
            }
            else {
              bVar2 = (byte)(entry.members + -0x10)->position & 0x1f;
              if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
                pch_relocate_symbol_list_c((int)entry);
              }
              else {
LAB_1048a95f:
                pch_relocate_symbol_list((int)entry);
              }
            }
          }
          slot_01 = slot_02.type + 2;
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)slot_01);
          if (cVar1 != '\0') {
            cell._0_2_ = slot_01->code;
            cell._2_2_ = slot_01->flags;
            pch_relocate_class_scope_list(cell);
          }
        }
        else {
          bVar2 = *(byte *)&slot_02.type[-1].extra & 0x1f;
          if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
            pch_relocate_slot_once(&g_pch_image,(uint *)slot_02.entries);
            pch_relocate_symbol((byte *)&slot_02.type[-1].extra.count);
            cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&(slot_02.ns)->scope_index);
            if (cVar1 != '\0') {
              entry = (c1_symbol_type_word)*(c1_symbol_type_word *)&(slot_02.ns)->scope_index;
              if ((*(byte *)&entry.type[-1].extra & 0x1f) == 4) {
                pch_relocate_class_member_list((int)entry);
              }
              else {
                bVar2 = *(byte *)&entry.type[-1].extra & 0x1f;
                if ((bVar2 != 0x10) && (bVar2 != 0x11)) goto LAB_1048a978;
                pch_relocate_symbol_list_c((int)entry);
              }
            }
LAB_1048a8ed:
            cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&(slot_02.type)->debug_index);
            if (cVar1 != '\0') {
              entry = *(c1_symbol_type_word *)&(slot_02.type)->debug_index;
LAB_1048a905:
              pch_relocate_symbol_list((int)entry);
            }
          }
          else {
            pch_relocate_slot_once(&g_pch_image,(uint *)slot_02.entries);
            pch_relocate_symbol((byte *)&slot_02.type[-1].extra.count);
            cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&(slot_02.alias)->qualifier);
            if (cVar1 != '\0') {
              entry = (c1_symbol_type_word)(slot_02.alias)->qualifier;
              slot_02 = entry;
              if ((*(byte *)((int)entry + -8) & 0x1f) == 4) goto LAB_1048a95f;
              bVar2 = *(byte *)((int)entry + -8) & 0x1f;
              if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
LAB_1048a978:
                pch_relocate_symbol_list((int)entry);
                goto LAB_1048a8ed;
              }
              goto LAB_1048a905;
            }
          }
        }
      }
      local_4 = local_4 + 1;
      bucket = local_4 & 0xffff;
    } while (bucket < scope->mask + 1);
  }
  pch_relocate_slot_once(&g_pch_image,(uint *)&scope->using_list);
  pair_list_slot_2 = (uint *)scope->using_list;
  if (pair_list_slot_2 != (uint *)0x0) {
    pch_relocate_slot_once(&g_pch_image,pair_list_slot_2);
    slot_00 = (uint *)*pair_list_slot_2;
    pch_relocate_slot_once(&g_pch_image,slot_00);
    pair_list_slot = slot_00 + 1;
    pch_relocate_slot_once(&g_pch_image,pair_list_slot);
    if (*pair_list_slot != 0) {
      pch_fixup_pair_list(*pair_list_slot);
    }
  }
  return;
}

