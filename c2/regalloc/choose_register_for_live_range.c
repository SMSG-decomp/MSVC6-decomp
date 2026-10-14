void __fastcall
choose_register_for_live_range(c2_live_range *lr,int reg_class,c2_bitset *neighbours)

{
  c2_register_descriptor **ppcVar1;
  int32_t *piVar2;
  c2_bitset *pcVar3;
  c2_tuple *copy;
  c2_register_descriptor *reg;
  uint32_t uVar4;
  uint32_t *puVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  c2_live_range *neighbour;
  int iVar8;
  c2_register_preference *pref;
  c2_block *block;
  c2_list_cell *pcVar9;
  int *cost_cursor;
  c2_live_range *src_range;
  
  cost_cursor = g_chooser_costs;
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *cost_cursor = 0;
    cost_cursor = cost_cursor + 1;
  }
  if (neighbours->chunks != (c2_bitset_chunk *)0x0) {
    uVar4 = bitset_iter_next(neighbours);
    while (uVar4 != 0xffffffff) {
      neighbour = live_range_from_id(uVar4);
      neighbours = (c2_bitset *)neighbour->weight;
      if (0 < (int)neighbours) {
        pref = neighbour->prefs;
        if (pref != (c2_register_preference *)0x0) {
          pcVar3 = neighbour->allowed;
          do {
            uVar4 = pref->reg->id;
            uVar6 = bitset_test(pcVar3,uVar4);
            if (uVar6 != 0) {
              g_chooser_costs[uVar4] = g_chooser_costs[uVar4] + pref->count;
            }
            pref = pref->next;
          } while (pref != (c2_register_preference *)0x0);
        }
        pcVar3 = neighbour->allowed;
        iVar8 = bitset_popcount(pcVar3);
        if (iVar8 == 1) {
          uVar4 = 0;
          uVar6 = bitset_test(pcVar3,0);
          while (uVar6 == 0) {
            uVar4 = uVar4 + 1;
            uVar6 = bitset_test(pcVar3,uVar4);
          }
          g_chooser_costs[uVar4] = g_chooser_costs[uVar4] + (int)neighbours * 100;
        }
      }
      uVar4 = bitset_iter_next((c2_bitset *)0x0);
    }
  }
  pref = lr->prefs;
  while (pref != (c2_register_preference *)0x0) {
    ppcVar1 = &pref->reg;
    piVar2 = &pref->count;
    pref = pref->next;
    uVar4 = (*ppcVar1)->id;
    g_chooser_costs[uVar4] = g_chooser_costs[uVar4] - *piVar2;
  }
  uVar4 = 0;
  puVar5 = g_class_register_order[reg_class];
  if (*puVar5 != 0) {
    pcVar3 = lr->allowed;
    iVar8 = 0;
    do {
      uVar6 = bitset_test(pcVar3,*(uint32_t *)(iVar8 + (int)puVar5));
      if ((uVar6 != 0) &&
         ((uVar4 == 0 ||
          (g_chooser_costs[*(int *)(iVar8 + (int)g_class_register_order[reg_class])] <
           (int)neighbours)))) {
        uVar4 = *(uint32_t *)(iVar8 + (int)g_class_register_order[reg_class]);
        neighbours = (c2_bitset *)g_chooser_costs[uVar4];
      }
      iVar8 = iVar8 + 4;
      puVar5 = g_class_register_order[reg_class];
    } while (*(int *)(iVar8 + (int)puVar5) != 0);
  }
  lr->colour = g_reg_symbols + uVar4;
  bitset_free(lr->allowed);
  uVar6 = lr->id;
  block = lr->first_block;
  lr->allowed = (c2_bitset *)0x0;
  do {
    uVar7 = bitset_test(block->live,uVar6);
    if (uVar7 != 0) {
      bitset_set(block->set4c,uVar4);
      uVar7 = bitset_test(block->live_in,uVar6);
      if (uVar7 != 0) {
        bitset_set(block->set24,uVar4);
      }
      uVar7 = bitset_test(block->live_out,uVar6);
      if (uVar7 != 0) {
        bitset_set(block->set28,uVar4);
      }
      if (block == lr->last_block) {
        pcVar9 = g_pending_copy_list;
        if (g_pending_copy_list != (c2_list_cell *)0x0) {
          do {
            copy = (pcVar9->u04).tuple;
            neighbour = (copy->dst->u18).range;
            if (neighbour->kind == '\x01') {
              if (neighbour->self->id == uVar4) {
                mark_last_use_in_block(lr,copy);
              }
            }
            else {
              src_range = (copy->src->u18).range;
              if (src_range == lr) {
                uVar6 = neighbour->colour->id;
                src_range = lr;
              }
              else {
                uVar6 = src_range->colour->id;
              }
              if (uVar6 == uVar4) {
                mark_last_uses_in_range(src_range,copy);
              }
            }
            pcVar9 = pcVar9->next;
          } while (pcVar9 != (c2_list_cell *)0x0);
          free_split_cell_list(g_pending_copy_list);
          g_pending_copy_list = (c2_list_cell *)0x0;
        }
        uVar4 = bitset_iter_next(g_copy_related_ranges);
        if (uVar4 != 0xffffffff) {
          reg = lr->colour;
          do {
            neighbour = live_range_from_id(uVar4);
            add_register_preference(neighbour,reg);
            uVar4 = bitset_iter_next((c2_bitset *)0x0);
          } while (uVar4 != 0xffffffff);
        }
        bitset_clear_all(g_copy_related_ranges);
        return;
      }
    }
    block = block->next;
  } while( true );
}

