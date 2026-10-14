c2_tuple * __fastcall clone_tuple_with_fresh_temps(c2_tuple *orig_t)

{
  char cVar1;
  c2_operand *pcVar2;
  c2_tuple *label;
  c2_tuple *t;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *pcVar5;
  c2_fe_symbol *pcVar6;
  
  t = (c2_tuple *)node_clone((c2_node *)orig_t);
  if (orig_t->kind == '\x1a') {
    pcVar6 = label_symbol_new();
    t->src = (c2_operand *)pcVar6;
    (pcVar6->u32).label_tuple = t;
    t->dst = (c2_operand *)0x0;
  }
  if ((t->flags & 1) != 0) {
    for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
         (pcVar5 = pcVar2->sym, (c2_symbol *)pcVar5->def != (c2_symbol *)0x0)) {
        pcVar3 = operand_resolve_part_new_temp((c2_operand *)pcVar5);
        pcVar4 = pcVar3->storage;
        pcVar2->sym = pcVar3;
        if (pcVar4->part_next == (c2_symbol *)0x0) {
          pcVar3->def = t;
        }
        else {
          symbol_mark_overlapping_parts(pcVar3,t);
        }
        if (pcVar2->kind == '\x01') {
          pcVar4 = (pcVar2->u18).reg;
          cVar1 = (char)*(uint32_t *)&pcVar4->cls;
          if ((cVar1 == '\x03') && ((c2_symbol *)pcVar4->def != (c2_symbol *)0x0)) {
            if (pcVar4 == pcVar5) {
              pcVar2->u18 = (c2_operand_u18)pcVar2->sym;
            }
            else {
              pcVar5 = operand_resolve_part_new_temp((c2_operand *)pcVar4);
              (pcVar2->u18).reg = pcVar5;
            }
          }
          else if (cVar1 != '\x01') {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\tuple.c",0x6e0);
          }
        }
      }
    }
    for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
         (pcVar5 = pcVar2->sym, (c2_symbol *)pcVar5->def != (c2_symbol *)0x0)) {
        pcVar4 = operand_resolve_part((c2_operand *)pcVar5);
        pcVar2->sym = pcVar4;
        if (pcVar2->kind == '\x01') {
          pcVar3 = (pcVar2->u18).reg;
          cVar1 = (char)*(uint32_t *)&pcVar3->cls;
          if ((cVar1 == '\x03') && ((c2_symbol *)pcVar3->def != (c2_symbol *)0x0)) {
            if (pcVar3 != pcVar5) {
              pcVar4 = operand_resolve_part((c2_operand *)pcVar3);
            }
            (pcVar2->u18).reg = pcVar4;
          }
          else if (cVar1 != '\x01') {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\tuple.c",0x6f3);
          }
        }
      }
    }
    if (t->kind == '\x11') {
      if ((t->u20).cond_cells != (c2_cond_cell *)0x0) {
        (t->u20).cond_cells = (c2_cond_cell *)0x0;
        tuple_push_cell20((c2_node *)t,(uint32_t)t->src->next->sym->def);
      }
      label = *(c2_tuple **)((int)&t->src->sym->u30 + 2);
      if (label != (c2_tuple *)0x0) {
        label_add_ref(label,(c2_node *)t);
      }
    }
  }
  return t;
}

