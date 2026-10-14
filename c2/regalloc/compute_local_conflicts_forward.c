void __fastcall compute_local_conflicts_forward(c2_function *fn)

{
  uint8_t uVar1;
  ushort uVar2;
  c2_tuple *t;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  uint32_t uVar5;
  c2_symbol *pcVar6;
  c2_bitvec *v;
  c2_bitset *bs;
  c2_operand *pcVar7;
  uint32_t uVar8;
  uint uVar9;
  
  v = bitvec_new(6,9);
  bs = bitset_new(6);
  t = fn->cfg->first->head;
  do {
    if (t == (c2_tuple *)0x0) {
      bitset_free(bs);
      bitset_header_free(v);
      return;
    }
    if ((t->flags & 1) != 0) {
      uVar2 = t->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      for (pcVar3 = t->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (((pcVar3->kind == '\x01') && (pcVar3->sym->cls == '\x03')) &&
           (pcVar3->sym->def != (c2_tuple *)0x0)) {
          pcVar4 = (pcVar3->u18).reg;
          if (pcVar4->cls == '\x01') {
            uVar9 = pcVar4->storage->id;
            if (uVar9 < 9) {
              bitvec_clear(v,uVar9);
            }
          }
          else {
            pcVar7 = find_dst_reg_operand(pcVar4,t);
            if (((pcVar7 == (c2_operand *)0x0) && (bitset_clear(bs,pcVar4->id), t->op == 1)) &&
               ((t->dst->kind == '\x01' &&
                ((pcVar6 = (t->dst->u18).reg, pcVar6->cls == '\x01' && ((pcVar3->flags & 0x20) == 0)
                 ))))) {
              pcVar6 = pcVar6->storage;
              uVar9 = pcVar6->id;
              if ((uVar9 != 0) && ((uVar9 < 9 && (uVar9 != 5)))) {
                pcVar4->order_next = pcVar6;
              }
            }
            if ((pcVar3->type & 0xfff) == 1) {
              pcVar4 = (pcVar3->u18).reg;
              uVar5 = pcVar4->id;
              bitset_set(g_local_conflicts[7],uVar5);
              bitset_set(g_local_conflicts[8],uVar5);
              bitset_set(g_local_conflicts[6],uVar5);
              pcVar4->flags5 = pcVar4->flags5 | 0x80;
            }
          }
        }
      }
      for (pcVar3 = t->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (pcVar3->kind == '\x01') {
          uVar1 = pcVar3->sym->cls;
          if ((uVar1 == '\x03') && (pcVar3->sym->def != (c2_tuple *)0x0)) {
            pcVar4 = (pcVar3->u18).reg;
            if (pcVar4->cls == '\x01') {
              uVar9 = pcVar4->storage->id;
              if (((uVar9 != 0) && (uVar9 < 9)) && (uVar9 != 5)) {
                bitvec_set(v,uVar9);
                bitset_or(g_local_conflicts[uVar9],bs);
                g_reg_symbols[uVar9].flags5 = g_reg_symbols[uVar9].flags5 | 0x10;
              }
            }
            else {
              uVar5 = pcVar4->id;
              uVar8 = bitset_test(bs,uVar5);
              if (uVar8 == 0) {
                bitset_set(bs,uVar5);
                if (((t->op == 1) && (t->src->kind == '\x01')) &&
                   (pcVar6 = (t->src->u18).reg, pcVar6->cls == '\x01')) {
                  pcVar6 = pcVar6->storage;
                  uVar9 = pcVar6->id;
                  if (((uVar9 != 0) && (uVar9 < 9)) && (uVar9 != 5)) {
                    pcVar4->order_next = pcVar6;
                    goto LAB_10750bc8;
                  }
                }
                pcVar4->order_next = (c2_symbol *)0x0;
              }
LAB_10750bc8:
              uVar8 = bitvec_iter_next(v);
              while (uVar8 != 0xffffffff) {
                bitset_set(g_local_conflicts[uVar8],uVar5);
                uVar8 = bitvec_iter_next((c2_bitvec *)0x0);
              }
              if ((pcVar3->type & 0xfff) == 1) {
                uVar5 = pcVar4->id;
                bitset_set(g_local_conflicts[7],uVar5);
                bitset_set(g_local_conflicts[8],uVar5);
                bitset_set(g_local_conflicts[6],uVar5);
                pcVar4->flags5 = pcVar4->flags5 | 0x80;
              }
            }
          }
          else if (((uVar1 == '\x01') &&
                   ((uVar9 = ((pcVar3->u18).reg)->storage->id, uVar9 != 0 && (uVar9 < 9)))) &&
                  (uVar9 != 5)) {
            bitset_or(g_local_conflicts[uVar9],bs);
            g_reg_symbols[uVar9].flags5 = g_reg_symbols[uVar9].flags5 | 0x10;
          }
        }
        else if (pcVar3->kind == '\n') {
          uVar9 = bitset_iter_next((c2_bitset *)pcVar3->sym);
          while (uVar9 != 0xffffffff) {
            if (((uVar9 != 0) && (uVar9 < 9)) && (uVar9 != 5)) {
              bitset_or(g_local_conflicts[uVar9],bs);
              g_reg_symbols[uVar9].flags5 = g_reg_symbols[uVar9].flags5 | 0x10;
            }
            uVar9 = bitset_iter_next((c2_bitset *)0x0);
          }
        }
      }
    }
    t = t->next;
  } while( true );
}

