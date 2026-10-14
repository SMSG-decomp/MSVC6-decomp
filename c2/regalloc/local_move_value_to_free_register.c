int __fastcall local_move_value_to_free_register(uint32_t regno,c2_tuple *t)

{
  c2_symbol *pcVar1;
  uint32_t n;
  c2_operand *pcVar2;
  uint32_t uVar3;
  uint uVar4;
  uint32_t *puVar5;
  uint32_t uVar6;
  c2_symbol *pcVar7;
  c2_tuple *pcVar8;
  
  pcVar1 = g_register_holders[regno];
  n = pcVar1->id;
  puVar5 = g_local_register_order;
  uVar3 = g_local_register_order[0];
  while( true ) {
    puVar5 = puVar5 + 1;
    if (uVar3 == 0) {
      return 0;
    }
    if ((g_register_holders[uVar3] == (c2_symbol *)0x0) &&
       (uVar6 = bitset_test(g_local_conflicts[uVar3],n), pcVar8 = t, uVar6 == 0)) break;
LAB_1078bd89:
    uVar3 = *puVar5;
  }
  do {
    if ((pcVar8->flags & 1) != 0) {
      for (pcVar2 = pcVar8->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x01')) &&
            (((pcVar2->u18).reg)->storage->id == regno)) && ((pcVar2->flags11 & 0x10) != 0))
        goto joined_r0x1078bda3;
      }
      for (pcVar2 = pcVar8->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage->id == uVar3))
        goto LAB_1078bd89;
      }
    }
    pcVar8 = pcVar8->prev;
  } while( true );
joined_r0x1078bda3:
  if (t == (c2_tuple *)0x0) {
LAB_1078be92:
    g_register_holders[uVar3] = pcVar1;
    g_register_holders[regno] = (c2_symbol *)0x0;
    g_reg_symbols[uVar3].flags5 = g_reg_symbols[uVar3].flags5 | 0x10;
    g_reg_symbols[uVar3].u34.refs = 0x1000000;
    return 1;
  }
  if ((t->flags & 1) != 0) {
    for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if (((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x01')) &&
         (((pcVar2->u18).reg)->storage->id == regno)) {
        uVar4 = pcVar2->sym->offset;
        pcVar7 = reg_find_subreg(g_reg_symbols + uVar3,(pcVar2->type & 0xfff) << 3,
                                 (uVar4 & (3 < (int)uVar4) - 1) << 3);
        (pcVar2->u18).reg = pcVar7;
        if ((pcVar2->flags11 & 0x10) != 0) goto LAB_1078be92;
      }
    }
    for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if (((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x01')) &&
         (((pcVar2->u18).reg)->storage->id == regno)) {
        uVar4 = pcVar2->sym->offset;
        pcVar7 = reg_find_subreg(g_reg_symbols + uVar3,(pcVar2->type & 0xfff) << 3,
                                 (uVar4 & (3 < (int)uVar4) - 1) << 3);
        (pcVar2->u18).reg = pcVar7;
      }
    }
  }
  t = t->prev;
  goto joined_r0x1078bda3;
}

