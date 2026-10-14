uint32_t __thiscall move_holder_to_free_register(c2_tuple *t,uint32_t temp_id)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  uint uVar3;
  uint32_t *puVar4;
  c2_tuple *pcVar5;
  uint32_t uVar6;
  c2_symbol *pcVar7;
  uint32_t uVar8;
  c2_operand *pcVar9;
  uint32_t *local_8;
  
  local_8 = g_local_register_order;
  uVar8 = g_local_register_order[0];
  pcVar9 = (c2_operand *)temp_id;
  if (g_local_register_order[0] == 0) {
    return 0;
  }
  do {
    local_8 = local_8 + 1;
    if (g_register_holders[uVar8] == (c2_symbol *)0x0) {
      puVar4 = g_local_register_order;
      uVar1 = g_local_register_order[0];
      while (puVar4 = puVar4 + 1, uVar1 != 0) {
        if (((g_register_holders[uVar1] != (c2_symbol *)0x0) &&
            (uVar6 = bitset_test(g_local_conflicts[uVar1],temp_id), uVar6 == 0)) &&
           (uVar6 = bitset_test(g_local_conflicts[uVar8],g_register_holders[uVar1]->id), pcVar5 = t,
           uVar6 == 0)) {
          for (; pcVar5 != (c2_tuple *)0x0; pcVar5 = pcVar5->prev) {
            if ((pcVar5->flags & 1) != 0) {
              for (pcVar9 = pcVar5->dst; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
                if (((pcVar9->kind == '\x01') && (((pcVar9->u18).reg)->cls == '\x01')) &&
                   ((((pcVar9->u18).reg)->storage->id == uVar1 && ((pcVar9->flags11 & 0x10) != 0))))
                goto LAB_1075a6d5;
              }
              for (pcVar2 = pcVar5->src; pcVar9 = (c2_operand *)0x0, pcVar2 != (c2_operand *)0x0;
                  pcVar2 = pcVar2->next) {
                if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage->id == uVar8)) {
                  pcVar9 = (c2_operand *)0x0;
                  goto LAB_1075a608;
                }
              }
            }
          }
LAB_1075a6d5:
          if (pcVar9 != (c2_operand *)0x0) goto joined_r0x1075a6e1;
        }
LAB_1075a608:
        uVar1 = *puVar4;
      }
    }
    uVar8 = *local_8;
    if (*local_8 == 0) {
      return 0;
    }
  } while( true );
joined_r0x1075a6e1:
  if (t == (c2_tuple *)0x0) {
LAB_1075a7e6:
    g_register_holders[uVar8] = g_register_holders[uVar1];
    g_register_holders[uVar1] = (c2_symbol *)0x0;
    g_reg_symbols[uVar8].flags5 = g_reg_symbols[uVar8].flags5 | 0x10;
    g_reg_symbols[uVar8].u34.refs = 0x1000000;
    return uVar1;
  }
  if ((t->flags & 1) != 0) {
    for (pcVar9 = t->dst; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
      if (((pcVar9->kind == '\x01') && (((pcVar9->u18).reg)->cls == '\x01')) &&
         (((pcVar9->u18).reg)->storage->id == uVar1)) {
        uVar3 = pcVar9->sym->offset;
        pcVar7 = reg_find_subreg(g_reg_symbols + uVar8,(pcVar9->type & 0xfff) << 3,
                                 (uVar3 & (3 < (int)uVar3) - 1) * 8);
        (pcVar9->u18).reg = pcVar7;
        if ((pcVar9->flags11 & 0x10) != 0) goto LAB_1075a7e6;
      }
    }
    for (pcVar9 = t->src; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
      if (((pcVar9->kind == '\x01') && (((pcVar9->u18).reg)->cls == '\x01')) &&
         (((pcVar9->u18).reg)->storage->id == uVar1)) {
        uVar3 = pcVar9->sym->offset;
        pcVar7 = reg_find_subreg(g_reg_symbols + uVar8,(pcVar9->type & 0xfff) << 3,
                                 (uVar3 & (3 < (int)uVar3) - 1) * 8);
        (pcVar9->u18).reg = pcVar7;
      }
    }
  }
  t = t->prev;
  goto joined_r0x1075a6e1;
}

