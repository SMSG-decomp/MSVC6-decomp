void __fastcall liveness_transfer_tuple(c2_tuple *t,c2_bitset *live,c2_bitset *killed_below)

{
  uint8_t uVar1;
  uint16_t uVar2;
  c2_fe_symbol *pcVar3;
  c2_symbol_cell **ppcVar4;
  c2_symbol *pcVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  c2_symbol_cell *pcVar9;
  uint32_t uVar10;
  c2_symbol *pcVar11;
  c2_operand *pcVar12;
  c2_tuple *pcVar13;
  uint uVar14;
  c2_symbol *pcVar15;
  byte bVar16;
  c2_symbol_cell *pcVar17;
  c2_operand *pcVar18;
  c2_symbol_cell *pcVar19;
  
  uVar1 = t->flags13;
  if (uVar1 == '\x02') {
    return;
  }
  if (uVar1 == '\x01') {
    return;
  }
  g_tuple_visit_count = g_tuple_visit_count + 1;
  if (((g_liveness_mode == 0) || (uVar1 != '\x03')) &&
     (pcVar12 = t->dst, pcVar12 != (c2_operand *)0x0)) {
    if (((t->op == 0x15b) && (iVar6 = operand_compare(pcVar12,t->src), iVar6 == 0)) &&
       (iVar6 = node_has_side_effects((c2_node *)t), iVar6 == 0)) {
LAB_1070671d:
      if (t->flags13 != '\x04') {
        for (pcVar12 = t->src; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
          if (((1 << (pcVar12->kind & 0x1f) & 6U) != 0) &&
             (((pcVar12->sym->u30).sizeopt.width_facts & 1) != 0)) {
            g_liveness_repeat_needed = 1;
          }
        }
      }
      tuple_delete(t);
      return;
    }
    bVar16 = pcVar12->kind;
    g_dead_dst_overlap_live = 0;
    if ((1 << (bVar16 & 0x1f) & 6U) == 0) {
      if ((bVar16 == 6) && ((pcVar12->u18).reg != (c2_symbol *)0x0)) {
        if (((((pcVar12->u18).reg)->u30).globopt.killed != '\0') &&
           (((1 << (pcVar12->base->kind & 0x1f) & 6U) == 0 ||
            (pcVar12->base->sym->def == (c2_tuple *)0x0)))) {
          pcVar18 = (c2_operand *)killed_below;
          for (pcVar13 = t->next; pcVar13 != (c2_tuple *)0x0; pcVar13 = pcVar13->next) {
            if ((pcVar13->flags & 1) != 0) {
              for (pcVar18 = pcVar13->dst; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next) {
                if ((pcVar18->kind == '\x06') &&
                   (iVar6 = operand_compare(pcVar18,pcVar12), iVar6 == 0)) goto LAB_10706932;
              }
            }
          }
LAB_10706932:
          iVar6 = range_src_may_alias(t->next,&pcVar13->next,pcVar18);
          if ((iVar6 == 0) && (iVar6 = node_has_side_effects((c2_node *)t), iVar6 == 0))
          goto LAB_1070671d;
        }
      }
      else if (((bVar16 == 0xb) && (t->kind == '\x12')) &&
              (((uVar2 = (t->u20).intrinsic.id, uVar2 == 0xad || (uVar2 == 0xac)) &&
               (pcVar11 = alias_class_single_member((uint32_t)pcVar12->sym),
               pcVar11 != (c2_symbol *)0x0)))) {
        if (pcVar11->def == (c2_tuple *)0x0) {
          uVar7 = bitset_test(killed_below,pcVar11->id);
        }
        else {
          uVar7 = (uint32_t)(pcVar11->u30).globopt.killed;
        }
        if (uVar7 == 0) {
          for (pcVar15 = pcVar11->storage; pcVar15 != (c2_symbol *)0x0; pcVar15 = pcVar15->part_next
              ) {
            if (pcVar15 == pcVar11) {
LAB_107068bd:
              if (pcVar15->def == (c2_tuple *)0x0) {
                uVar7 = bitset_test(live,pcVar15->id);
              }
              else {
                uVar7 = (uint32_t)(pcVar15->u30).globopt.live;
              }
              if (uVar7 != 0) goto LAB_107065dc;
            }
            else if ((pcVar15->offset < pcVar11->size + pcVar11->offset) &&
                    (pcVar11->offset < pcVar15->size + pcVar15->offset)) goto LAB_107068bd;
          }
        }
        goto LAB_1070671d;
      }
    }
    else {
      pcVar11 = pcVar12->sym;
      if (pcVar11->def == (c2_tuple *)0x0) {
        uVar14 = bitset_test(killed_below,pcVar11->id);
      }
      else {
        uVar14 = (uint)(pcVar11->u30).globopt.killed;
      }
      if (uVar14 == 0) {
        for (pcVar15 = pcVar11->storage; pcVar15 != (c2_symbol *)0x0; pcVar15 = pcVar15->part_next)
        {
          if (pcVar15 == pcVar11) {
LAB_107065c4:
            if (pcVar15->def == (c2_tuple *)0x0) {
              uVar14 = bitset_test(live,pcVar15->id);
            }
            else {
              uVar14 = (uint)(pcVar15->u30).globopt.live;
            }
            if (uVar14 != 0) goto LAB_107065dc;
          }
          else if ((pcVar15->offset < pcVar11->size + pcVar11->offset) &&
                  (pcVar11->offset < pcVar15->size + pcVar15->offset)) goto LAB_107065c4;
        }
      }
      if (((g_liveness_mode != 0) && (t->op == 0x15b)) && (t->flags13 == '\x04')) {
        pcVar11 = t->src->sym;
        if (pcVar11->def == (c2_tuple *)0x0) {
          uVar7 = bitset_test(live,pcVar11->id);
        }
        else {
          uVar7 = (uint32_t)(pcVar11->u30).globopt.live;
        }
        if (uVar7 != 0) goto LAB_107065e6;
      }
      iVar6 = node_has_side_effects((c2_node *)t);
      if (iVar6 == 0) goto LAB_1070671d;
      uVar1 = t->kind;
      if (((uVar1 == '\x0e') || (uVar1 == '\x12')) || ((uVar1 == '\x15' || (t->op == 0x16b)))) {
        iVar6 = node_has_side_effects((c2_node *)pcVar12);
        if (iVar6 == 0) {
          tuple_remove_dst(t,pcVar12);
        }
        else if (((1 << (pcVar12->kind & 0x1f) & 6U) != 0) &&
                (pcVar11 = pcVar12->sym, pcVar11->cls == '\x03')) {
          if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
            pcVar11->def = (c2_tuple *)0x0;
          }
          else {
            symbol_mark_overlapping_parts(pcVar11,(c2_tuple *)0x0);
          }
          if (pcVar12->kind == '\x01') {
            operand_make_sym(pcVar12);
          }
        }
      }
      else {
        iVar6 = node_has_side_effects((c2_node *)pcVar12);
        if ((iVar6 == 0) && (t->kind == '\f')) {
          pcVar11 = symbol_new_temp(pcVar12->type);
          pcVar11->def = t;
          tuple_remove_dst(t,pcVar12);
          pcVar12 = operand_new_reg(0x149,pcVar11->type,pcVar11,pcVar11);
          tuple_append_dst(t,pcVar12);
        }
        if (((pcVar12->kind == '\x01') && (pcVar12->sym->cls == '\x03')) &&
           (pcVar12->sym->def != (c2_tuple *)0x0)) {
          pcVar13 = tuple_new_pseudo(0x19e,pcVar12->type);
          tuple_append_src(pcVar13,pcVar12);
          tuple_insert_after(t,pcVar13);
          if (t->op == 0x17d) {
            t->op = 0x16e;
          }
        }
      }
    }
  }
LAB_107065e6:
  pcVar11 = g_pending_memory_stores;
  for (pcVar12 = t->dst; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
    if (pcVar12->kind < 3) {
      pcVar15 = pcVar12->sym;
      pcVar13 = pcVar15->def;
      if (pcVar13 == (c2_tuple *)0x0) {
        uVar14 = bitset_test(live,pcVar15->id);
        pcVar11 = g_pending_memory_stores;
      }
      else {
        uVar14 = (uint)(pcVar15->u30).globopt.live;
      }
      if ((uVar14 == 0) && (g_dead_dst_overlap_live == 0)) {
        pcVar12->flags11 = pcVar12->flags11 | 0x10;
      }
      if (pcVar13 == (c2_tuple *)0x0) {
        pcVar5 = pcVar15->storage;
        if (pcVar5 != (c2_symbol *)0x0) {
          iVar6 = pcVar15->offset;
          do {
            if ((iVar6 <= pcVar5->offset) &&
               (pcVar5->size + pcVar5->offset <= pcVar15->size + iVar6)) {
              uVar7 = pcVar5->id;
              bitset_clear(live,uVar7);
              bitset_set(killed_below,uVar7);
              pcVar11 = g_pending_memory_stores;
            }
            pcVar5 = pcVar5->part_next;
          } while (pcVar5 != (c2_symbol *)0x0);
        }
      }
      else {
        pcVar5 = pcVar15->storage;
        if (pcVar5 != (c2_symbol *)0x0) {
          iVar6 = pcVar15->offset;
          do {
            if ((iVar6 <= pcVar5->offset) &&
               (pcVar5->size + pcVar5->offset <= pcVar15->size + iVar6)) {
              (pcVar5->u30).globopt.live = '\0';
              (pcVar5->u30).globopt.killed = '\x01';
            }
            pcVar5 = pcVar5->part_next;
          } while (pcVar5 != (c2_symbol *)0x0);
        }
      }
      if ((pcVar11 != (c2_symbol *)0x0) && (t->op == 0x15b)) {
        if (pcVar15 == (c2_symbol *)0x0) {
          while (pcVar11 != (c2_symbol *)0x0) {
            g_pending_memory_stores = (pcVar11->u28).free_next;
            (pcVar11->u30).globopt.killed = '\0';
            pcVar11 = g_pending_memory_stores;
          }
        }
        else {
          if (pcVar15->storage == pcVar15) {
            do {
              liveness_mark_copy_sources(pcVar15);
              pcVar15 = pcVar15->part_next;
            } while (pcVar15 != (c2_symbol *)0x0);
          }
          else {
            liveness_mark_copy_sources(pcVar15);
          }
          pcVar11 = (c2_symbol *)0x0;
          while (pcVar15 = g_pending_memory_stores, g_pending_memory_stores = pcVar11,
                pcVar15 != (c2_symbol *)0x0) {
            g_pending_memory_stores = (pcVar15->u28).free_next;
            if ((pcVar15->u30).globopt.killed != '\0') {
              (pcVar15->u28).free_next = pcVar11;
              pcVar11 = pcVar15;
            }
          }
        }
      }
    }
    else if (((pcVar12->kind == 6) && (pcVar15 = (pcVar12->u18).reg, pcVar15 != (c2_symbol *)0x0))
            && ((pcVar15->u30).globopt.killed == '\0')) {
      (pcVar15->u28).free_next = pcVar11;
      (pcVar15->u30).globopt.killed = '\x01';
      pcVar11 = pcVar15;
      g_pending_memory_stores = pcVar15;
    }
  }
  uVar7 = t->op;
  if ((((((uVar7 == 0x191) && (pcVar12 = t->dst, pcVar12 != (c2_operand *)0x0)) &&
        ((1 << (pcVar12->kind & 0x1f) & 6U) != 0)) &&
       (((pcVar12->type & 0xf000) == 0x5000 &&
        (pcVar18 = pcVar12->next, pcVar18 != (c2_operand *)0x0)))) &&
      ((1 << (pcVar18->kind & 0x1f) & 6U) != 0)) && ((pcVar18->type & 0xf000) == 0x5000)) {
    pcVar11 = pcVar12->sym;
    pcVar15 = pcVar18->sym;
    pcVar5 = pcVar11->storage;
    if (((pcVar5 == pcVar15->storage) && (pcVar11->offset == 0)) &&
       ((pcVar11->size == 4 &&
        (((pcVar15->offset == 4 && (pcVar15->size == 4)) && (pcVar5->size == 8)))))) {
      pcVar13 = pcVar5->def;
      bVar16 = pcVar12->flags11 & 0xef;
      pcVar12->sym = pcVar5;
      pcVar12->flags11 = bVar16;
      if (pcVar13 == (c2_tuple *)0x0) {
        uVar14 = bitset_test(live,pcVar5->id);
      }
      else {
        uVar14 = (uint)(pcVar5->u30).globopt.live;
      }
      if ((uVar14 == 0) && (g_dead_dst_overlap_live == 0)) {
        pcVar12->flags11 = bVar16 | 0x10;
      }
      if (pcVar13 == (c2_tuple *)0x0) {
        pcVar15 = pcVar5->storage;
        if (pcVar15 != (c2_symbol *)0x0) {
          iVar6 = pcVar5->offset;
          do {
            if ((iVar6 <= pcVar15->offset) &&
               (pcVar15->size + pcVar15->offset <= pcVar5->size + iVar6)) {
              uVar10 = pcVar15->id;
              bitset_clear(live,uVar10);
              bitset_set(killed_below,uVar10);
            }
            pcVar15 = pcVar15->part_next;
          } while (pcVar15 != (c2_symbol *)0x0);
        }
      }
      else {
        pcVar15 = pcVar5->storage;
        if (pcVar15 != (c2_symbol *)0x0) {
          iVar6 = pcVar5->offset;
          do {
            if ((iVar6 <= pcVar15->offset) &&
               (pcVar15->size + pcVar15->offset <= pcVar5->size + iVar6)) {
              (pcVar15->u30).globopt.live = '\0';
              (pcVar15->u30).globopt.killed = '\x01';
            }
            pcVar15 = pcVar15->part_next;
          } while (pcVar15 != (c2_symbol *)0x0);
        }
      }
      t->dst->sym = pcVar11;
    }
  }
  pcVar12 = t->src;
  do {
    if (pcVar12 == (c2_operand *)0x0) {
      return;
    }
    switch(pcVar12->kind) {
    case '\0':
      halt_baddata();
    case '\x01':
    case '\x02':
      pcVar11 = pcVar12->sym;
      if (pcVar11->def == (c2_tuple *)0x0) {
        uVar10 = pcVar11->id;
        uVar8 = bitset_test(live,uVar10);
        if (uVar8 == 0) {
          pcVar12->flags11 = pcVar12->flags11 | 0x10;
          bitset_set(live,uVar10);
        }
        for (pcVar15 = pcVar11->storage; pcVar15 != (c2_symbol *)0x0; pcVar15 = pcVar15->part_next)
        {
          if (pcVar15 == pcVar11) {
LAB_10706ab6:
            bitset_clear(killed_below,pcVar15->id);
          }
          else if ((pcVar15->offset < pcVar11->size + pcVar11->offset) &&
                  (pcVar11->offset < pcVar15->size + pcVar15->offset)) goto LAB_10706ab6;
        }
      }
      else {
        if ((pcVar11->u30).globopt.live == '\0') {
          bVar16 = pcVar12->flags11;
          (pcVar11->u30).globopt.live = '\x01';
          pcVar12->flags11 = bVar16 | 0x10;
        }
        for (pcVar15 = pcVar11->storage; pcVar15 != (c2_symbol *)0x0; pcVar15 = pcVar15->part_next)
        {
          if (pcVar15 == pcVar11) {
LAB_10706b19:
            (pcVar15->u30).globopt.killed = '\0';
          }
          else if ((pcVar15->offset < pcVar11->size + pcVar11->offset) &&
                  (pcVar11->offset < pcVar15->size + pcVar15->offset)) goto LAB_10706b19;
        }
      }
      break;
    case '\x03':
      if (uVar7 == 0x15a) {
        pcVar11 = pcVar12->sym;
        pcVar3 = pcVar11->storage->fe;
        if ((((pcVar3 != (c2_fe_symbol *)0x0) && (pcVar3->cls == '\x01')) &&
            (((byte)pcVar3->storage & 0x70) == 0x10)) &&
           ((pcVar3->name == (char *)0x0 && ((pcVar3->storage & 0x40000) != 0)))) {
          pcVar13 = pcVar11->def;
          if (pcVar13 == (c2_tuple *)0x0) {
            uVar10 = bitset_test(live,pcVar11->id);
          }
          else {
            uVar10 = (uint32_t)(pcVar11->u30).globopt.live;
          }
          if ((uVar10 == 0) && (g_dead_dst_overlap_live == 0)) {
            pcVar12->flags11 = pcVar12->flags11 | 0x10;
          }
          if (pcVar13 == (c2_tuple *)0x0) {
            pcVar15 = pcVar11->storage;
            if (pcVar15 != (c2_symbol *)0x0) {
              iVar6 = pcVar11->offset;
              do {
                if ((iVar6 <= pcVar15->offset) &&
                   (pcVar15->size + pcVar15->offset <= pcVar11->size + iVar6)) {
                  uVar10 = pcVar15->id;
                  bitset_clear(live,uVar10);
                  bitset_set(killed_below,uVar10);
                }
                pcVar15 = pcVar15->part_next;
              } while (pcVar15 != (c2_symbol *)0x0);
            }
          }
          else {
            pcVar15 = pcVar11->storage;
            if (pcVar15 != (c2_symbol *)0x0) {
              iVar6 = pcVar11->offset;
              do {
                if ((iVar6 <= pcVar15->offset) &&
                   (pcVar15->size + pcVar15->offset <= pcVar11->size + iVar6)) {
                  (pcVar15->u30).globopt.live = '\0';
                  (pcVar15->u30).globopt.killed = '\x01';
                }
                pcVar15 = pcVar15->part_next;
              } while (pcVar15 != (c2_symbol *)0x0);
            }
          }
        }
      }
      break;
    case '\x06':
      pcVar9 = alias_class_members(pcVar12->tag);
      pcVar17 = (c2_symbol_cell *)0x0;
joined_r0x10706b52:
      if (pcVar9 != (c2_symbol_cell *)0x0) {
        do {
          pcVar11 = pcVar9->sym;
          pcVar19 = pcVar9;
          if (pcVar11->cls == '\f') {
            pcVar19 = (pcVar11->u30).members;
            pcVar17 = pcVar9;
            if (pcVar19 == (c2_symbol_cell *)0x0) {
              pcVar9 = pcVar9->next;
              goto joined_r0x10706b52;
            }
            pcVar11 = pcVar19->sym;
          }
          if (pcVar11->def == (c2_tuple *)0x0) {
            uVar10 = bitset_test(live,pcVar11->id);
          }
          else {
            uVar10 = (uint32_t)(pcVar11->u30).globopt.live;
          }
          if (uVar10 == 0) {
            bitset_set(live,pcVar11->id);
          }
          for (pcVar11 = pcVar11->storage; pcVar11 != (c2_symbol *)0x0; pcVar11 = pcVar11->part_next
              ) {
            bitset_clear(killed_below,pcVar11->id);
          }
          pcVar9 = pcVar19->next;
        } while (pcVar9 != (c2_symbol_cell *)0x0);
        if (pcVar17 == (c2_symbol_cell *)0x0) goto LAB_10706b54;
        ppcVar4 = &pcVar17->next;
        pcVar17 = (c2_symbol_cell *)0x0;
        pcVar9 = *ppcVar4;
        goto joined_r0x10706b52;
      }
LAB_10706b54:
      uVar10 = pcVar12->tag;
      if (uVar10 == 0) {
        while (g_pending_memory_stores != (c2_symbol *)0x0) {
          pcVar11 = (g_pending_memory_stores->u28).free_next;
          (g_pending_memory_stores->u30).globopt.killed = '\0';
          g_pending_memory_stores = pcVar11;
        }
      }
      else {
        pcVar11 = (c2_symbol *)0x0;
        pcVar15 = g_pending_memory_stores;
        while (g_pending_memory_stores = pcVar11, pcVar15 != (c2_symbol *)0x0) {
          g_pending_memory_stores = (pcVar15->u28).free_next;
          uVar8 = alias_classes_intersect(uVar10,(((pcVar15->u18).expr)->operands->next->u18).lo);
          if (uVar8 == 0) {
            (pcVar15->u28).free_next = pcVar11;
            pcVar11 = pcVar15;
            pcVar15 = g_pending_memory_stores;
          }
          else {
            (pcVar15->u30).globopt.killed = '\0';
            pcVar15 = g_pending_memory_stores;
          }
        }
      }
      break;
    case '\n':
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globdf.c",0xc9d);
    case '\v':
      pcVar9 = alias_class_members((uint32_t)pcVar12->sym);
      pcVar17 = (c2_symbol_cell *)0x0;
joined_r0x10706c44:
      if (pcVar9 != (c2_symbol_cell *)0x0) {
        do {
          pcVar11 = pcVar9->sym;
          pcVar19 = pcVar9;
          if (pcVar11->cls == '\f') {
            pcVar19 = (pcVar11->u30).members;
            pcVar17 = pcVar9;
            if (pcVar19 == (c2_symbol_cell *)0x0) {
              pcVar9 = pcVar9->next;
              goto joined_r0x10706c44;
            }
            pcVar11 = pcVar19->sym;
          }
          if (pcVar11->def == (c2_tuple *)0x0) {
            uVar10 = bitset_test(live,pcVar11->id);
          }
          else {
            uVar10 = (uint32_t)(pcVar11->u30).globopt.live;
          }
          if (uVar10 == 0) {
            bitset_set(live,pcVar11->id);
          }
          for (pcVar11 = pcVar11->storage; pcVar11 != (c2_symbol *)0x0; pcVar11 = pcVar11->part_next
              ) {
            bitset_clear(killed_below,pcVar11->id);
          }
          pcVar9 = pcVar19->next;
        } while (pcVar9 != (c2_symbol_cell *)0x0);
        if (pcVar17 == (c2_symbol_cell *)0x0) goto joined_r0x10706ca3;
        ppcVar4 = &pcVar17->next;
        pcVar17 = (c2_symbol_cell *)0x0;
        pcVar9 = *ppcVar4;
        goto joined_r0x10706c44;
      }
joined_r0x10706ca3:
      while (g_pending_memory_stores != (c2_symbol *)0x0) {
        pcVar11 = (g_pending_memory_stores->u28).free_next;
        (g_pending_memory_stores->u30).globopt.killed = '\0';
        g_pending_memory_stores = pcVar11;
      }
    }
    pcVar12 = pcVar12->next;
  } while( true );
LAB_107065dc:
  g_dead_dst_overlap_live = 1;
  goto LAB_107065e6;
}

