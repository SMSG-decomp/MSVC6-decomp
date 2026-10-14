void incr_fix_symbol_section_numbers(void)

{
  short *psVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  void *pvVar5;
  c2_coff_aux_fndef *pcVar6;
  int iVar7;
  uint32_t bf_line;
  int iVar8;
  c2_coff_slot **ppcVar9;
  uint index;
  c2_coff_aux_bf *prev_bf_aux;
  c2_coff_aux_fndef *prev_fndef_aux;
  c2_coff_file_payload *prev_file_payload;
  int line_delta;
  c2_coff_file_payload *file_payload;
  c2_coff_aux_bf *bf_aux;
  c2_coff_slot *slot;
  
  bf_line = 0xffffffff;
  prev_file_payload = (c2_coff_file_payload *)0x0;
  prev_bf_aux = (c2_coff_aux_bf *)0x0;
  prev_fndef_aux = (c2_coff_aux_fndef *)0x0;
  index = 0;
  if (g_coff_symbol_slot_count != 0) {
    iVar8 = 4;
    ppcVar9 = g_coff_symbol_slots;
    do {
      slot = *(c2_coff_slot **)((int)ppcVar9 + iVar8 + -4);
      bf_aux = prev_bf_aux;
      file_payload = prev_file_payload;
      if (slot->kind == 3) {
        pvVar5 = slot->payload;
        sVar3 = *(short *)((int)pvVar5 + 0xc);
        if (sVar3 < -2) {
          sVar3 = (short)g_incr_section_renumber_map[-3 - sVar3].new_number;
          *(short *)((int)pvVar5 + 0xc) = sVar3;
          if (*(char *)((int)pvVar5 + 0x11) != '\0') {
            if (*(char *)((int)pvVar5 + 0x10) == 'e') {
              if (*(char *)((int)pvVar5 + 1) == 'b') {
                bf_aux = *(c2_coff_aux_bf **)(*(int *)((int)ppcVar9 + iVar8) + 8);
                uVar4 = bf_aux->line;
                bf_aux->line = (uint16_t)bf_line;
                line_delta = bf_line - uVar4;
                bf_line = 0xffffffff;
                bf_aux->next_bf = 0;
                if (prev_bf_aux != (c2_coff_aux_bf *)0x0) {
                  prev_bf_aux->next_bf = index;
                }
              }
              else if (*(char *)((int)pvVar5 + 1) == 'e') {
                psVar1 = (short *)(*(int *)(*(int *)((int)ppcVar9 + iVar8) + 8) + 4);
                *psVar1 = *psVar1 + (short)line_delta;
              }
            }
            else if (((*(byte *)((int)pvVar5 + 0xe) & 0x30) == 0x20) && (0 < sVar3)) {
              pcVar6 = *(c2_coff_aux_fndef **)(*(int *)((int)ppcVar9 + iVar8) + 8);
              pcVar6->next_function = 0;
              if (prev_fndef_aux != (c2_coff_aux_fndef *)0x0) {
                prev_fndef_aux->next_function = index;
              }
              bf_line = global_symbol_exp_offset(slot->key);
              ppcVar9 = g_coff_symbol_slots;
              prev_fndef_aux = pcVar6;
            }
          }
        }
        else if (sVar3 < 1) {
          if (((slot->key != 0) &&
              (iVar7 = incr_global_needs_record(slot->key), ppcVar9 = g_coff_symbol_slots,
              iVar7 != 0)) &&
             (cVar2 = *(char *)((int)pvVar5 + 0x11),
             *(c2_coff_slot **)((int)g_coff_symbol_slots + iVar8 + -4) = &g_coff_free_slot_record,
             cVar2 != '\0')) {
            *(c2_coff_slot **)((int)ppcVar9 + iVar8) = &g_coff_free_slot_record;
          }
        }
        else {
          *(c2_coff_slot **)((int)ppcVar9 + iVar8 + -4) = &g_coff_free_slot_record;
        }
      }
      else if (slot->kind == 1) {
        file_payload = slot->payload;
        file_payload->value = 0;
        if (prev_file_payload != (c2_coff_file_payload *)0x0) {
          prev_file_payload->value = index;
        }
      }
      prev_file_payload = file_payload;
      prev_bf_aux = bf_aux;
      index = index + 1;
      iVar8 = iVar8 + 4;
    } while (index < g_coff_symbol_slot_count);
  }
  return;
}

