void __fastcall compute_local_conflicts_backward(c2_function *fn)

{
  c2_register_preference **ppcVar1;
  uint8_t uVar2;
  byte bVar3;
  ushort uVar4;
  c2_block *pcVar5;
  c2_tuple *t;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  c2_symbol *pcVar8;
  c2_bitset *dst;
  c2_bitset *src;
  uint32_t uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint32_t uVar13;
  c2_operand *pcVar14;
  byte bVar15;
  c2_symbol *pcVar16;
  c2_symbol *dst_reg;
  
  reset_register_constant_scores();
  dst = bitset_new(6);
  src = bitset_new(6);
  pcVar5 = fn->cfg->first;
  do {
    if (pcVar5 == (c2_block *)0x0) {
      bitset_free(src);
      bitset_free(dst);
      return;
    }
    if (g_opt_favor_speed == 0) {
      bVar3 = 0;
    }
    else {
      bVar3 = (byte)pcVar5->loop_depth;
    }
    bitset_copy(dst,pcVar5->set28);
    pcVar6 = pcVar5->head;
    for (t = pcVar5->end; t != pcVar6; t = t->prev) {
      if ((t->flags & 1) != 0) {
        uVar4 = t->line;
        if (uVar4 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar4;
          g_cur_line = uVar4;
        }
        for (pcVar7 = t->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if (pcVar7->kind == '\x01') {
            pcVar8 = pcVar7->sym;
            uVar2 = pcVar8->cls;
            if ((uVar2 == '\x03') && (pcVar8->def != (c2_tuple *)0x0)) {
              pcVar8 = (pcVar7->u18).reg;
              if (pcVar8->cls == '\x01') {
                (pcVar8->storage->u34).refs = 0x1000000;
                pcVar14 = find_src_reg_operand(pcVar8,t);
                if (((pcVar14 == (c2_operand *)0x0) && (uVar11 = pcVar8->storage->id, uVar11 != 0))
                   && ((uVar11 < 9 && (uVar11 != 5)))) {
                  bitset_clear(dst,uVar11);
                  g_reg_symbols[uVar11].flags5 = g_reg_symbols[uVar11].flags5 | 0x10;
                }
              }
              else {
                if ((pcVar7->type & 0xfff) == 1) {
                  uVar9 = pcVar8->id;
                  bitset_set(g_local_conflicts[7],uVar9);
                  bitset_set(g_local_conflicts[8],uVar9);
                  bitset_set(g_local_conflicts[6],uVar9);
                  pcVar8->flags5 = pcVar8->flags5 | 0x80;
                }
                pcVar14 = find_src_reg_operand(pcVar8,t);
                if ((((pcVar14 == (c2_operand *)0x0) && (bitset_clear(src,pcVar8->id), t->op == 1))
                    && (t->src->kind == '\x01')) &&
                   (pcVar16 = (t->src->u18).reg, pcVar16->cls == '\x01')) {
                  pcVar16 = pcVar16->storage;
                  uVar11 = pcVar16->id;
                  if (((uVar11 != 0) && (uVar11 < 9)) && (uVar11 != 5)) {
                    pcVar8->order_next = pcVar16;
                  }
                }
              }
            }
            else if (uVar2 == '\x01') {
              pcVar16 = ((pcVar7->u18).reg)->storage;
              uVar11 = pcVar16->id;
              if (((uVar11 != 0) && (uVar11 < 9)) && (uVar11 != 5)) {
                bitset_or(g_local_conflicts[uVar11],src);
                g_reg_symbols[uVar11].flags5 = g_reg_symbols[uVar11].flags5 | 0x10;
LAB_107341cf:
                (pcVar16->u34).refs = 0x1000000;
              }
            }
            else if ((pcVar7->type & 0xf000) != 0x4000) {
              pcVar16 = ((pcVar7->u18).reg)->storage;
              uVar9 = pcVar16->id;
              bitset_clear(dst,uVar9);
              g_reg_symbols[uVar9].flags5 = g_reg_symbols[uVar9].flags5 | 0x10;
              if (uVar2 != '\r') goto LAB_107341cf;
              iVar12 = (pcVar16->u34).refs;
              if (iVar12 < 0x1000000) {
                iVar10 = load_saving(pcVar8);
                (pcVar16->u34).source_links = (c2_copy_link *)(iVar12 - (iVar10 << (bVar3 & 0x1f)));
              }
            }
          }
          else if (pcVar7->kind == '\n') {
            uVar11 = bitset_iter_next((c2_bitset *)pcVar7->sym);
            while (uVar11 != 0xffffffff) {
              if (((uVar11 != 0) && (uVar11 < 9)) && (uVar11 != 5)) {
                bitset_or(g_local_conflicts[uVar11],src);
                g_reg_symbols[uVar11].flags5 = g_reg_symbols[uVar11].flags5 | 0x10;
                g_reg_symbols[uVar11].u34.refs = 0x1000000;
              }
              uVar11 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
        for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if (pcVar7->kind == '\x01') {
            pcVar8 = pcVar7->sym;
            bVar15 = pcVar7->flags11 & 0xef;
            uVar2 = pcVar8->cls;
            pcVar7->flags11 = bVar15;
            if ((uVar2 == '\x03') && (pcVar8->def != (c2_tuple *)0x0)) {
              pcVar8 = (pcVar7->u18).reg;
              if (pcVar8->cls == '\x01') {
                uVar11 = pcVar8->storage->id;
                if (((uVar11 != 0) && (uVar11 < 9)) &&
                   ((uVar11 != 5 && (uVar9 = bitset_test(dst,uVar11), uVar9 == 0)))) {
                  bitset_or(g_local_conflicts[uVar11],src);
                  bitset_set(dst,uVar11);
                  pcVar7->flags11 = bVar15 | 0x10;
                }
              }
              else {
                if ((pcVar7->type & 0xfff) == 1) {
                  uVar9 = pcVar8->id;
                  bitset_set(g_local_conflicts[7],uVar9);
                  bitset_set(g_local_conflicts[8],uVar9);
                  bitset_set(g_local_conflicts[6],uVar9);
                  pcVar8->flags5 = pcVar8->flags5 | 0x80;
                }
                pcVar14 = find_dst_reg_operand(pcVar8,t);
                if (pcVar14 == (c2_operand *)0x0) {
                  uVar9 = pcVar8->id;
                  bitset_set(src,uVar9);
                  pcVar7->flags11 = pcVar7->flags11 | 0x10;
                  if (dst->chunks != (c2_bitset_chunk *)0x0) {
                    iVar12 = bitset_iter_next(dst);
                    while (iVar12 != -1) {
                      bitset_set(g_local_conflicts[iVar12],uVar9);
                      iVar12 = bitset_iter_next((c2_bitset *)0x0);
                    }
                  }
                  if ((((t->op == 1) && (t->dst->kind == '\x01')) &&
                      (pcVar16 = (t->dst->u18).reg, pcVar16->cls == '\x01')) &&
                     ((pcVar7->flags & 0x20) == 0)) {
                    pcVar16 = pcVar16->storage;
                    uVar11 = pcVar16->id;
                    if (((uVar11 != 0) && (uVar11 < 9)) && (uVar11 != 5)) {
                      pcVar8->order_next = pcVar16;
                      goto LAB_10734455;
                    }
                  }
                  pcVar8->order_next = (c2_symbol *)0x0;
                }
              }
            }
            else if ((uVar2 != '\x01') && ((pcVar7->type & 0xf000) != 0x4000)) {
              dst_reg = ((pcVar7->u18).reg)->storage;
              uVar9 = dst_reg->id;
              uVar13 = bitset_test(dst,uVar9);
              if (uVar13 == 0) {
                bitset_or(g_local_conflicts[uVar9],src);
                bitset_set(dst,uVar9);
                pcVar7->flags11 = bVar15 | 0x10;
              }
              if (pcVar8->cls == '\r') {
                if ((dst_reg->u34).refs < 0x1000000) {
                  uVar9 = memory_operand_saving(t,pcVar8);
                  ppcVar1 = &((pcVar7->u18).range)->self->prefs;
                  *ppcVar1 = (c2_register_preference *)
                             ((int)&(*ppcVar1)->next + (uVar9 << (bVar3 & 0x1f)));
                }
              }
              else {
                (dst_reg->u34).refs = 0x1000000;
              }
            }
          }
LAB_10734455:
        }
      }
    }
    pcVar5 = pcVar5->next;
  } while( true );
}

