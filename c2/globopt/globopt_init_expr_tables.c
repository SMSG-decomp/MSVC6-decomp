void globopt_init_expr_tables(void)

{
  c2_symbol_cell **ppcVar1;
  c2_bitset *pcVar2;
  uint32_t uVar3;
  c2_symbol_cell *pcVar4;
  int iVar5;
  c2_symbol_cell *pcVar6;
  c2_symbol_cell *member_cell;
  c2_cse_expr **bucket;
  c2_symbol *member;
  
  arena_reset(0xe);
  g_expr_count = 0;
  bucket = g_expr_hash;
  for (iVar5 = 0x65; iVar5 != 0; iVar5 = iVar5 + -1) {
    *bucket = (c2_cse_expr *)0x0;
    bucket = bucket + 1;
  }
  g_address_expr_count = 0;
  g_address_expr_list = (c2_symbol *)0xffffffff;
  uVar3 = g_alias_class_max * 4 + 4;
  g_alias_class_kill_sets = arena_alloc(0xe,uVar3);
  g_alias_class_kill_sets2 = arena_alloc(0xe,uVar3);
  g_alias_class_head_sets = arena_alloc(0xe,uVar3);
  g_alias_class_member_sets = arena_alloc(0xe,uVar3);
  iVar5 = bitset_iter_next(g_alias_bitset_symbols);
  while (iVar5 != -1) {
    pcVar2 = bitset_new(0xe);
    g_alias_class_kill_sets2[iVar5] = pcVar2;
    pcVar2 = bitset_new(0xe);
    g_alias_class_kill_sets[iVar5] = pcVar2;
    iVar5 = bitset_iter_next((c2_bitset *)0x0);
  }
  uVar3 = bitset_iter_next(g_alias_bitset_memory_classes);
  do {
    if (uVar3 == 0xffffffff) {
      g_call_killed_exprs = bitset_new(0xe);
      return;
    }
    pcVar2 = bitset_new(0xe);
    g_alias_class_kill_sets[uVar3] = pcVar2;
    pcVar2 = bitset_new(0xe);
    g_alias_class_head_sets[uVar3] = pcVar2;
    pcVar2 = bitset_new(0xe);
    g_alias_class_member_sets[uVar3] = pcVar2;
    pcVar4 = alias_class_members(uVar3);
    pcVar6 = (c2_symbol_cell *)0x0;
joined_r0x1072996c:
    if (pcVar4 != (c2_symbol_cell *)0x0) {
      do {
        member = pcVar4->sym;
        member_cell = pcVar4;
        if (member->cls == '\f') {
          member_cell = (member->u30).members;
          pcVar6 = pcVar4;
          if (member_cell == (c2_symbol_cell *)0x0) {
            pcVar4 = pcVar4->next;
            goto joined_r0x1072996c;
          }
          member = member_cell->sym;
        }
        bitset_set(g_alias_class_head_sets[uVar3],member->id);
        for (; member != (c2_symbol *)0x0; member = member->part_next) {
          bitset_set(g_alias_class_member_sets[uVar3],member->id);
        }
        pcVar4 = member_cell->next;
      } while (pcVar4 != (c2_symbol_cell *)0x0);
      if (pcVar6 == (c2_symbol_cell *)0x0) goto LAB_1072996e;
      ppcVar1 = &pcVar6->next;
      pcVar6 = (c2_symbol_cell *)0x0;
      pcVar4 = *ppcVar1;
      goto joined_r0x1072996c;
    }
LAB_1072996e:
    uVar3 = bitset_iter_next((c2_bitset *)0x0);
  } while( true );
}

