c2_tuple * __fastcall clone_tuple_list(c2_tuple *orig)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_switch_case *pcVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  c2_node *pcVar7;
  uint32_t stamp;
  c2_tuple *clone;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_node *referrer;
  c2_symbol *dst_temp;
  c2_symbol *src_temp;
  
  stamp = g_tuple_visit_stamp + 1;
  pcVar9 = orig;
  g_tuple_visit_stamp = stamp;
  do {
    if ((pcVar9->flags & 1) == 0) {
      if (pcVar9->kind == '\x1a') {
        (pcVar9->u20).visit_stamp = g_tuple_visit_stamp;
      }
    }
    else {
      for (pcVar2 = pcVar9->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        bVar1 = pcVar2->kind;
        if (((((1 << (bVar1 & 0x1f) & 6U) != 0) &&
             (pcVar3 = pcVar2->sym, pcVar3->def != (c2_tuple *)0x0)) &&
            ((pcVar3->storage->u28).free_next = (c2_symbol *)0x0, bVar1 == 1)) &&
           (((dst_temp = (pcVar2->u18).reg, dst_temp->cls == '\x03' &&
             (dst_temp->def != (c2_tuple *)0x0)) && (dst_temp != pcVar3)))) {
          (dst_temp->storage->u28).free_next = (c2_symbol *)0x0;
        }
      }
      for (pcVar2 = pcVar9->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        bVar1 = pcVar2->kind;
        if ((((1 << (bVar1 & 0x1f) & 6U) != 0) &&
            (pcVar3 = pcVar2->sym, pcVar3->def != (c2_tuple *)0x0)) &&
           (((pcVar3->storage->u28).free_next = (c2_symbol *)0x0, bVar1 == 1 &&
            (((src_temp = (pcVar2->u18).reg, src_temp->cls == '\x03' &&
              (src_temp->def != (c2_tuple *)0x0)) && (src_temp != pcVar3)))))) {
          (src_temp->storage->u28).free_next = (c2_symbol *)0x0;
        }
      }
    }
    pcVar9 = pcVar9->next;
  } while (pcVar9 != (c2_tuple *)0x0);
  clone = clone_tuple_with_fresh_temps(orig);
  pcVar9 = orig->next;
  pcVar6 = clone;
  while (pcVar8 = clone, pcVar9 != (c2_tuple *)0x0) {
    pcVar8 = clone_tuple_with_fresh_temps(pcVar9);
    pcVar9 = pcVar9->next;
    pcVar6->next = pcVar8;
    pcVar8->prev = pcVar6;
    pcVar6 = pcVar8;
  }
  do {
    if (pcVar8 == (c2_tuple *)0x0) {
      return clone;
    }
    if (pcVar8->kind == '\x11') {
      if ((pcVar8->src->kind == '\x04') &&
         (pcVar9 = *(c2_tuple **)&(pcVar8->src->sym->u30).globopt.marks, pcVar9 != (c2_tuple *)0x0))
      {
        if (pcVar9->kind != '\x1a') {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\tuple.c",0x642);
        }
        if ((pcVar9->u20).cond_cells == (c2_cond_cell *)stamp) {
          pcVar9 = clone_find_corresponding_label(pcVar9,orig,clone);
          tuple_retarget(pcVar8,(c2_node *)pcVar9,0);
        }
      }
    }
    else if (pcVar8->kind == '\x13') {
      pcVar9 = clone_find_corresponding_label((pcVar8->u20).default_label,orig,clone);
      (pcVar8->u20).default_label = pcVar9;
      label_add_ref(pcVar9,(c2_node *)pcVar8);
      pcVar4 = (pcVar8->u24).cases;
      (pcVar8->u24).cases = (c2_switch_case *)0x0;
      pcVar7 = (c2_node *)&pcVar8->u24;
      for (; pcVar4 != (c2_switch_case *)0x0; pcVar4 = pcVar4->next) {
        if ((pcVar4->label->u20).cond_cells != (c2_cond_cell *)stamp) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\tuple.c",0x663);
        }
        referrer = node_alloc('\x1d');
        pcVar9 = clone_find_corresponding_label(pcVar4->label,orig,clone);
        uVar5 = pcVar4->lo;
        referrer[1].next = (c2_node *)pcVar4->hi;
        referrer->rank_or_prev = uVar5;
        referrer->next = (c2_node *)0x0;
        pcVar7->next = referrer;
        referrer[1].op = (uint32_t)pcVar9;
        *(c2_tuple **)&referrer[1].kind = pcVar8;
        label_add_ref(pcVar9,referrer);
        pcVar7 = referrer;
      }
    }
    pcVar8 = pcVar8->next;
  } while( true );
}

