void __fastcall coff_incr_drop_sections(uint16_t *sections,int n,uint32_t keep_key)

{
  char cVar1;
  c2_coff_section_out *sec;
  void *pvVar2;
  uint32_t key;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int slot_section;
  int *number_cursor;
  uint uVar6;
  c2_coff_slot **slots;
  int iVar7;
  c2_coff_section **ppcVar8;
  char *pcVar9;
  bool bVar10;
  int max_section;
  int local_34;
  int min_section;
  int sym_aux_left;
  int local_24;
  int section_numbers [8];
  int new_min;
  c2_coff_slot *slot;
  
  max_section = -1;
  sym_aux_left = 0;
  local_34 = 0;
  bVar10 = false;
  iVar7 = 0;
  uVar6 = 0xffffffff;
  if (0 < n) {
    number_cursor = section_numbers;
    iVar7 = n * 4;
    local_24 = n;
    do {
      puVar4 = coff_chunked_array_get(g_coff_sections,(uint)*sections);
      sec = (c2_coff_section_out *)*puVar4;
      *(undefined4 **)((int)&g_coff_machine + iVar7) = puVar4;
      coff_list_remove_value(sec);
      if (g_coff_section_numbers_final == 0) {
        uVar6 = -(uint)sec->header_number - 2;
      }
      else {
        uVar6 = (uint)sec->header_number;
      }
      *number_cursor = uVar6;
      if (sec->symbol_index < (uint)max_section) {
        max_section = sec->symbol_index;
      }
      if (sec->data_offset != 0) {
        coff_free_range_add(sec->data_offset,
                            sec->nrelocs * 10 + (uint)sec->nlines * 6 + sec->size_of_raw_data);
        sec->size_of_raw_data = 0;
        sec->nrelocs = 0;
        sec->nlines = 0;
        sec->reloc_offset = 0;
        sec->line_offset = 0;
      }
      sections = sections + 1;
      number_cursor = number_cursor + 1;
      local_24 = local_24 + -1;
      iVar7 = iVar7 + -4;
    } while (local_24 != 0);
    iVar7 = n;
    uVar6 = max_section;
    if (7 < n) goto LAB_10782ed8;
  }
  ppcVar8 = g_coff_reuse_sections + iVar7;
  for (iVar5 = 8 - iVar7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppcVar8 = (c2_coff_section *)0x0;
    ppcVar8 = ppcVar8 + 1;
  }
LAB_10782ed8:
  g_coff_reuse_section_index = 0;
  bVar3 = true;
  min_section = section_numbers[0];
  max_section = section_numbers[0];
  if (1 < n) {
    number_cursor = section_numbers;
    iVar7 = n + -1;
    do {
      number_cursor = number_cursor + 1;
      iVar5 = *number_cursor;
      new_min = iVar5;
      if ((min_section <= iVar5) && (new_min = min_section, max_section < iVar5)) {
        max_section = iVar5;
      }
      min_section = new_min;
      if (iVar5 != number_cursor[-1] + 1) {
        bVar3 = false;
      }
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (uVar6 < g_coff_first_free_slot) {
    g_coff_first_free_slot = uVar6;
  }
  slots = g_coff_symbol_slots;
  if (uVar6 < g_coff_symbol_slot_count) {
    do {
      slot = slots[uVar6];
      switch(slot->kind) {
      case 1:
        if (bVar10) {
          puVar4 = slot->payload;
          slots[uVar6] = &g_coff_free_slot_record;
          bVar10 = false;
          slot_section = -1;
          pcVar9 = (char *)*puVar4;
          do {
            if (slot_section == 0) break;
            slot_section = slot_section + -1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          local_34 = (~slot_section - 1U) / 0x12 + 1;
        }
        break;
      case 2:
        if (g_coff_section_numbers_final == 0) {
          slot_section = -2 - (uint)*(ushort *)((int)slot->payload + 0x30);
        }
        else {
          slot_section = (int)*(ushort *)((int)slot->payload + 0x30);
        }
        bVar10 = false;
        if ((min_section <= slot_section) && (slot_section <= max_section)) {
          if (!bVar3) {
            iVar7 = 0;
            if (0 < n) {
              number_cursor = section_numbers;
              do {
                if (*number_cursor == slot_section) break;
                iVar7 = iVar7 + 1;
                number_cursor = number_cursor + 1;
              } while (iVar7 < n);
            }
            if (iVar7 == n) break;
          }
          if (slot_section != 0) {
            bVar10 = slot_section == max_section;
            if (bVar10) {
              g_coff_function_slot_mark = uVar6;
            }
            local_34 = 1;
            goto LAB_10783039;
          }
        }
        break;
      case 3:
        pvVar2 = slot->payload;
        iVar7 = (int)*(short *)((int)pvVar2 + 0xc);
        if ((min_section <= iVar7) && (iVar7 <= max_section)) {
          if (!bVar3) {
            iVar5 = 0;
            if (0 < n) {
              number_cursor = section_numbers;
              do {
                if (*number_cursor == iVar7) break;
                iVar5 = iVar5 + 1;
                number_cursor = number_cursor + 1;
              } while (iVar5 < n);
            }
            if (iVar5 == n) break;
          }
          if (iVar7 != 0) {
            sym_aux_left = (int)*(byte *)((int)pvVar2 + 0x11);
            if ((keep_key == 0) || (slot->key != keep_key)) {
              key = slot->key;
              slots[uVar6] = &g_coff_free_slot_record;
              if (key != 0) {
                coff_hash_remove(key);
                slots = g_coff_symbol_slots;
              }
            }
            else {
              *(undefined2 *)((int)pvVar2 + 0xc) = 0;
              *(undefined1 *)((int)pvVar2 + 0x11) = 0;
              *(undefined4 *)((int)pvVar2 + 8) = 0;
            }
          }
        }
        break;
      case 4:
        if (0 < sym_aux_left) {
          sym_aux_left = sym_aux_left + -1;
LAB_10783039:
          slots[uVar6] = &g_coff_free_slot_record;
        }
        break;
      case 5:
        if (0 < local_34) {
          local_34 = local_34 + -1;
          goto LAB_10783039;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < g_coff_symbol_slot_count);
  }
  return;
}

