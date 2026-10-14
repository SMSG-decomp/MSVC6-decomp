void __fastcall compute_block_local_sets(c2_block *blocks,uint32_t candidate_count)

{
  byte bVar1;
  ushort uVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  uint uVar4;
  c2_symbol *pcVar5;
  c2_bitset *src;
  c2_operand *pcVar6;
  c2_symbol_cell **ppcVar7;
  c2_symbol **ppcVar8;
  c2_bitset *bs;
  c2_bitset *bs_00;
  c2_bitset *bs_01;
  uint32_t uVar9;
  c2_symbol_cell *pcVar10;
  c2_operand *pcVar11;
  c2_symbol *pcVar12;
  c2_symbol_cell *pcVar13;
  c2_symbol_cell *pcVar14;
  uint32_t uVar15;
  c2_symbol *pcVar16;
  uint local_10;
  
  do {
    if (blocks == (c2_block *)0x0) {
      return;
    }
    bs = bitset_new(6);
    bs_00 = bitset_new(6);
    bs_01 = bitset_new(6);
    pcVar3 = blocks->head;
    for (t = blocks->end; t != pcVar3; t = t->prev) {
      if ((t->flags & 1) != 0) {
        if ((t->kind == '\x14') || (local_10 = t->op, local_10 == 0x187)) {
          local_10 = t->op;
          switch(local_10) {
          case 0x187:
          case 0x194:
          case 0x196:
          case 0x198:
          case 0x19a:
          case 0x19c:
          case 0x1a5:
switchD_1071ae55_caseD_187:
            bitset_set_range(bs_01,candidate_count + 1);
            bitset_clear_all(bs_00);
            break;
          case 0x19d:
            if (((t->u20).cc & 1) != 0) goto switchD_1071ae55_caseD_187;
            if ((((t->u20).cc & 2) != 0) && (uVar15 = 1, g_candidate_count != 0)) {
              do {
                bitset_set(bs_01,uVar15);
                bitset_clear(bs_00,uVar15);
                uVar15 = uVar15 + 1;
              } while (uVar15 <= g_candidate_count);
            }
          }
        }
        for (pcVar11 = t->dst; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
          switch(pcVar11->kind) {
          case '\x01':
            pcVar11->flags = pcVar11->flags & 0xf0;
            if ((pcVar11->u18).reg == &g_register_candidate_home) {
              pcVar16 = (pcVar11->sym->u34).parent;
              pcVar12 = pcVar11->sym;
              if (pcVar16 != (c2_symbol *)0x0) {
                pcVar12 = pcVar16;
              }
              uVar15 = ((pcVar12->u30).ra)->id;
              uVar2 = t->type;
              g_candidate_symbols[uVar15] = pcVar12;
              if (((uVar2 & 0xf000) == 0x4000) ||
                 (((local_10 != 0 && (local_10 < 0x144)) && ((g_x86_op_flags[local_10] & 1) != 0))))
              {
                operand_make_sym(pcVar11);
                bitset_set(bs_01,uVar15);
                if (pcVar12->cls == '\x03') {
                  pcVar12->flags6 = pcVar12->flags6 | 2;
                }
              }
              else {
                uVar9 = bitset_test(bs_01,uVar15);
                if (uVar9 == 0) {
                  bitset_set(bs,uVar15);
                  bitset_set(bs_01,uVar15);
                }
              }
LAB_1071b043:
              bitset_clear(bs_00,uVar15);
              pcVar16 = pcVar12->storage;
              pcVar5 = pcVar16->part_next;
              goto joined_r0x1071b138;
            }
            break;
          case '\x02':
            pcVar12 = pcVar11->sym;
            if (((pcVar12->u30).ra != (c2_ra_candidate *)0x0) &&
               (uVar15 = ((pcVar12->u30).ra)->id, uVar15 != 0)) {
              if (((pcVar11->flags & 0x40) != 0) ||
                 (((((t->type & 0xf000) == 0x4000 ||
                    (((local_10 != 0 && (local_10 < 0x144)) && ((g_x86_op_flags[local_10] & 1) != 0)
                     ))) && ((pcVar12->type & 0xf000) != 0x4000)) ||
                  ((local_10 == 0x5b || (local_10 == 0x5a)))))) {
                bitset_set(bs_01,uVar15);
                uVar15 = ((pcVar12->u30).ra)->id;
                goto LAB_1071b043;
              }
              set_operand_home(pcVar11,&g_register_candidate_home);
              ppcVar8 = g_candidate_symbols;
              uVar15 = ((pcVar12->u30).ra)->id;
              pcVar11->flags = pcVar11->flags & 0xf0;
              ppcVar8[uVar15] = pcVar12;
              uVar9 = bitset_test(bs_01,uVar15);
              if (uVar9 == 0) {
                bitset_set(bs,uVar15);
                bitset_set(bs_01,uVar15);
              }
              bitset_clear(bs_00,uVar15);
            }
            pcVar16 = pcVar12->storage;
            pcVar5 = pcVar16->part_next;
joined_r0x1071b138:
            if (pcVar5 != (c2_symbol *)0x0) {
              for (pcVar16 = pcVar16->storage; pcVar16 != (c2_symbol *)0x0;
                  pcVar16 = pcVar16->part_next) {
                if (pcVar12 != pcVar16) {
                  if ((((pcVar12->offset < pcVar16->size + pcVar16->offset) &&
                       (pcVar16->offset < pcVar12->size + pcVar12->offset)) &&
                      ((pcVar16->u30).ra != (c2_ra_candidate *)0x0)) &&
                     (uVar15 = ((pcVar16->u30).ra)->id, uVar15 != 0)) {
                    bitset_set(bs_01,uVar15);
                    bitset_clear(bs_00,uVar15);
                  }
                }
              }
            }
            break;
          case '\x06':
            pcVar12 = (c2_symbol *)pcVar11->tag;
            goto LAB_1071b1b2;
          case '\v':
            pcVar12 = pcVar11->sym;
LAB_1071b1b2:
            pcVar10 = alias_class_members((uint32_t)pcVar12);
            pcVar13 = (c2_symbol_cell *)0x0;
joined_r0x1071b1bd:
            if (pcVar10 != (c2_symbol_cell *)0x0) {
              do {
                pcVar12 = pcVar10->sym;
                pcVar14 = pcVar10;
                if (pcVar12->cls == '\f') {
                  pcVar14 = (pcVar12->u30).members;
                  pcVar13 = pcVar10;
                  if (pcVar14 == (c2_symbol_cell *)0x0) {
                    pcVar10 = pcVar10->next;
                    goto joined_r0x1071b1bd;
                  }
                  pcVar12 = pcVar14->sym;
                }
                if (((pcVar12->u30).ra != (c2_ra_candidate *)0x0) &&
                   (src = ((pcVar12->u30).ra)->part_ids, src != (c2_bitset *)0x0)) {
                  bitset_or(bs_01,src);
                  bitset_andnot(bs_00,((pcVar12->u30).ra)->part_ids);
                }
                pcVar10 = pcVar14->next;
              } while (pcVar10 != (c2_symbol_cell *)0x0);
              if (pcVar13 == (c2_symbol_cell *)0x0) break;
              ppcVar7 = &pcVar13->next;
              pcVar13 = (c2_symbol_cell *)0x0;
              pcVar10 = *ppcVar7;
              goto joined_r0x1071b1bd;
            }
          }
        }
        for (pcVar11 = t->src; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
          if (pcVar11->kind == '\x01') {
            bVar1 = pcVar11->flags;
            pcVar11->flags = bVar1 & 0xf0;
            if ((pcVar11->u18).reg == &g_register_candidate_home) {
              pcVar12 = (pcVar11->sym->u34).parent;
              pcVar16 = pcVar11->sym;
              if (pcVar12 != (c2_symbol *)0x0) {
                pcVar16 = pcVar12;
              }
              uVar15 = ((pcVar16->u30).ra)->id;
              g_candidate_symbols[uVar15] = pcVar16;
              if (((pcVar16->cls == '\r') && ((pcVar16->flags5 & 0x10) == 0)) &&
                 ((blocks->loop == (c2_loop *)0x0 || (g_opt_favor_speed == 0)))) {
                pcVar11 = tuple_replace_src_with_base_copy(t,pcVar11,pcVar16);
              }
              else if ((((t->type & 0xf000) == 0x4000) ||
                       (((uVar4 = t->op, uVar4 != 0 && (uVar4 < 0x144)) &&
                        ((g_x86_op_flags[uVar4] & 1) != 0)))) && ((bVar1 & 0x20) == 0)) {
                operand_make_sym(pcVar11);
                if (pcVar16->cls == '\x03') {
                  pcVar16->flags6 = pcVar16->flags6 | 2;
                }
              }
              else {
                uVar9 = bitset_test(bs_01,uVar15);
                if (uVar9 == 0) {
                  bitset_set(bs,uVar15);
                }
LAB_1071af42:
                bitset_set(bs_00,uVar15);
              }
            }
          }
          else if (pcVar11->kind == '\x02') {
            pcVar12 = pcVar11->sym;
            if ((((pcVar12->u30).order_prev != (c2_symbol *)0x0) &&
                (((pcVar12->u30).order_prev)->fe != (c2_fe_symbol *)0x0)) &&
               ((pcVar11->flags & 0x40) == 0)) {
              if ((((t->type & 0xf000) == 0x4000) ||
                  (((uVar4 = t->op, uVar4 != 0 && (uVar4 < 0x144)) &&
                   ((g_x86_op_flags[uVar4] & 1) != 0)))) &&
                 (((pcVar11->flags & 0x20) == 0 && ((pcVar12->type & 0xf000) != 0x4000)))) {
                if (pcVar12->cls == '\x03') {
                  pcVar12->flags6 = pcVar12->flags6 | 2;
                }
              }
              else {
                pcVar6 = t->dst;
                if ((pcVar6 == (c2_operand *)0x0) ||
                   (((pcVar6->kind != '\x02' || ((pcVar6->flags & 0x40) == 0)) ||
                    (pcVar6->sym != pcVar12)))) {
                  set_operand_home(pcVar11,&g_register_candidate_home);
                  ppcVar8 = g_candidate_symbols;
                  pcVar11->flags = pcVar11->flags & 0xf0;
                  uVar15 = ((pcVar12->u30).ra)->id;
                  ppcVar8[uVar15] = pcVar12;
                  uVar9 = bitset_test(bs_01,uVar15);
                  if (uVar9 == 0) {
                    bitset_set(bs,uVar15);
                  }
                  goto LAB_1071af42;
                }
              }
            }
          }
        }
        mark_tied_operand_pair(t);
      }
    }
    blocks->ue = bs_00;
    blocks->de = bs;
    blocks->kill = bs_01;
    blocks = blocks->next;
  } while( true );
}

