void __fastcall globdf_expr_tuple_transfer(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *parent;
  c2_symbol *s;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  c2_bitset *pcVar5;
  uint32_t uVar6;
  c2_bitset **ppcVar7;
  bool bVar8;
  c2_symbol *local_8;
  uint32_t local_4;
  
  uVar1 = t->flags13;
  if (uVar1 == '\x11') {
    return;
  }
  g_tuple_visit_count = g_tuple_visit_count + 1;
  local_8 = (c2_symbol *)0x0;
  if (((t->op == 0x15b) && (t->dst->kind == '\x06')) &&
     ((pcVar2 = t->dst->base, (1 << (pcVar2->kind & 0x1f) & 6U) == 0 ||
      (pcVar2->sym->def == (c2_tuple *)0x0)))) {
    local_8 = pcVar2->sym;
    uVar6 = local_8->id;
    local_4 = bitset_test(g_globdf_block_gen,uVar6);
    bitset_set(g_globdf_block_gen,uVar6);
    bitset_clear(g_globdf_block_kill,uVar6);
  }
  for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    switch(globdf_expr_tuple_transfer_case_index[pcVar2->kind]) {
    case 0:
      if (uVar1 != '\x01') {
        pcVar3 = pcVar2->sym;
        if ((((pcVar3->u18).expr == (c2_cse_expr *)0x0) ||
            (((pcVar3->u30).sizeopt.width_facts & 1) != 0)) || (uVar1 == '\x0e')) {
          globdf_kill_dependents_tree(pcVar3,(c2_symbol *)0x0);
        }
        else {
          pcVar5 = pcVar3->kills;
          if (pcVar5 != (c2_bitset *)0x0) {
            bitset_or(g_df_block_expr_killed,pcVar5);
            bitset_or(g_globdf_block_kill,pcVar5);
            bitset_andnot(g_globdf_block_gen,pcVar5);
          }
          parent = pcVar3->storage;
          for (s = parent; s != (c2_symbol *)0x0; s = s->part_next) {
            if (s != pcVar3) {
              if ((s->offset < pcVar3->size + pcVar3->offset) &&
                 (pcVar3->offset < s->size + s->offset)) {
                globdf_kill_symbol_tree(s,parent);
              }
            }
          }
        }
        if (((pcVar3->cls == '\a') || (pcVar3->cls == '\b')) || ((pcVar3->flags5 & 2) != 0)) {
          pcVar3 = (c2_symbol *)(uint)(pcVar3->storage->fe->u3e).alias_class;
          ppcVar7 = g_alias_class_kill_sets2;
          goto LAB_1070fe67;
        }
      }
      break;
    case 1:
      pcVar5 = g_alias_class_kill_sets[pcVar2->tag];
      bitset_or(g_df_block_expr_killed,pcVar5);
      bitset_or(g_globdf_block_kill,pcVar5);
      bitset_andnot(g_globdf_block_gen,pcVar5);
      uVar6 = ((pcVar2->u18).reg)->id;
      bitset_set(g_globdf_block_gen,uVar6);
      bitset_clear(g_globdf_block_kill,uVar6);
      break;
    case 2:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globdf.c",0x1088);
    case 3:
      pcVar3 = pcVar2->sym;
      ppcVar7 = g_alias_class_kill_sets;
LAB_1070fe67:
      pcVar5 = ppcVar7[(int)pcVar3];
      bitset_or(g_df_block_expr_killed,pcVar5);
      bitset_or(g_globdf_block_kill,pcVar5);
      bitset_andnot(g_globdf_block_gen,pcVar5);
    }
  }
  pcVar2 = t->dst;
  bVar8 = true;
  if (pcVar2 == (c2_operand *)0x0) goto LAB_1070fd76;
  if (((1 << (pcVar2->kind & 0x1f) & 6U) == 0) || ((pcVar2->sym->u18).expr == (c2_cse_expr *)0x0)) {
    if (local_8 == (c2_symbol *)0x0) goto LAB_1070fd76;
    uVar6 = local_8->id;
    uVar4 = bitset_test(g_globdf_block_gen,uVar6);
    bVar8 = uVar4 != 0;
    if ((local_4 != 0) || (uVar4 == 0)) goto LAB_1070fd76;
    bitset_set(g_globdf_block_kill,uVar6);
    bitset_set(g_df_block_expr_killed,uVar6);
    pcVar5 = g_globdf_block_gen;
  }
  else {
    uVar6 = pcVar2->sym->id;
    bitset_set(g_globdf_block_gen,uVar6);
    pcVar5 = g_globdf_block_kill;
  }
  bitset_clear(pcVar5,uVar6);
LAB_1070fd76:
  if ((t->op == 0x15b) && (bVar8)) {
    uVar6 = ((t->u14).expr)->id;
    bitset_set(g_globdf_block_gen,uVar6);
    bitset_clear(g_globdf_block_kill,uVar6);
  }
  return;
}

