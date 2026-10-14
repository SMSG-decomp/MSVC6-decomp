void __fastcall avail_transfer_tuple(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_symbol *parent;
  c2_symbol *s;
  bool bVar2;
  bool bVar3;
  c2_symbol *pcVar4;
  uint32_t uVar5;
  c2_bitset **ppcVar6;
  c2_symbol *local_c;
  int local_4;
  
  g_tuple_visit_count = g_tuple_visit_count + 1;
  if (t->flags13 == '\x11') {
    return;
  }
  local_c = (c2_symbol *)0x0;
  if (((t->op != 0x15b) || (t->dst->kind != '\x06')) ||
     ((pcVar1 = t->dst->base, (1 << (pcVar1->kind & 0x1f) & 6U) != 0 &&
      (pcVar1->sym->def != (c2_tuple *)0x0)))) goto LAB_1070ee20;
  local_c = pcVar1->sym;
  if (local_c->def == (c2_tuple *)0x0) {
    uVar5 = bitset_test(g_cur_avail_set,local_c->id);
    local_4 = 1;
    if (uVar5 == 0) goto LAB_1070ee94;
  }
  else {
LAB_1070ee94:
    local_4 = 0;
  }
  avail_gen_expression(local_c);
LAB_1070ee20:
  pcVar1 = t->dst;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      pcVar1 = t->dst;
      bVar2 = true;
      if (pcVar1 != (c2_operand *)0x0) {
        if (((1 << (pcVar1->kind & 0x1f) & 6U) == 0) ||
           ((pcVar1->sym->u18).expr == (c2_cse_expr *)0x0)) {
          if (local_c != (c2_symbol *)0x0) {
            if ((local_c->def == (c2_tuple *)0x0) &&
               (uVar5 = bitset_test(g_cur_avail_set,local_c->id), uVar5 != 0)) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
              bVar2 = false;
            }
            if ((local_4 == 0) && (bVar3)) {
              bitset_clear(g_cur_avail_set,local_c->id);
            }
          }
        }
        else if (t->flags13 == '\x01') {
          if (((((1 << (t->src->kind & 0x1f) & 6U) != 0) &&
               (pcVar4 = t->src->sym, (pcVar4->u18).expr != (c2_cse_expr *)0x0)) &&
              (pcVar4->def == (c2_tuple *)0x0)) &&
             (uVar5 = bitset_test(g_cur_avail_set,pcVar4->id), uVar5 != 0)) {
            avail_gen_expression(pcVar1->sym);
          }
        }
        else {
          avail_gen_expression(pcVar1->sym);
        }
      }
      if (((t->op == 0x15b) && (bVar2)) && ((t->u14).expr != (c2_symbol *)0x0)) {
        avail_gen_expression((t->u14).expr);
      }
      if ((t->kind == '\x14') || (t->op == 0x187)) {
        switch(t->op) {
        case 0x187:
        case 0x194:
        case 0x195:
        case 0x196:
        case 0x198:
        case 0x19a:
        case 0x19d:
        case 0x1a5:
          if (g_cse_full_mode != 0) {
            bitset_clear_all(g_cur_avail_set);
            return;
          }
          bitset_andnot(g_cur_avail_set,g_call_killed_exprs);
        }
      }
      return;
    }
    switch(avail_transfer_tuple_case_index[pcVar1->kind]) {
    case 0:
      if (t->flags13 != '\x01') {
        pcVar4 = pcVar1->sym;
        if ((((pcVar4->u18).expr == (c2_cse_expr *)0x0) ||
            (((pcVar4->u30).sizeopt.width_facts & 1) != 0)) || (t->flags13 == '\x0e')) {
          avail_kill_dependents(pcVar4,(c2_symbol *)0x0);
        }
        else {
          if (pcVar4->kills != (c2_bitset *)0x0) {
            bitset_andnot(g_cur_avail_set,pcVar4->kills);
          }
          parent = pcVar4->storage;
          for (s = parent; s != (c2_symbol *)0x0; s = s->part_next) {
            if (s != pcVar4) {
              if ((s->offset < pcVar4->size + pcVar4->offset) &&
                 (pcVar4->offset < s->size + s->offset)) {
                avail_kill_overlapping_loads(s,parent);
              }
            }
          }
        }
        pcVar4 = pcVar1->sym;
        if (((pcVar4->cls == '\a') || (pcVar4->cls == '\b')) || ((pcVar4->flags5 & 2) != 0)) {
          pcVar4 = (c2_symbol *)(uint)(pcVar4->storage->fe->u3e).alias_class;
          ppcVar6 = g_alias_class_kill_sets2;
          goto LAB_1070efe1;
        }
      }
      break;
    case 1:
      bitset_andnot(g_cur_avail_set,g_alias_class_kill_sets[pcVar1->tag]);
      avail_gen_expression((pcVar1->u18).reg);
      break;
    case 2:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globopt.c",0x22a5);
    case 3:
      pcVar4 = pcVar1->sym;
      ppcVar6 = g_alias_class_kill_sets;
LAB_1070efe1:
      bitset_andnot(g_cur_avail_set,ppcVar6[(int)pcVar4]);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

