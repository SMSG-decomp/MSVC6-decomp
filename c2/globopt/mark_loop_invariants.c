void __fastcall mark_loop_invariants(c2_loop *loop)

{
  byte bVar1;
  c2_loop *loop_00;
  c2_block *pcVar2;
  c2_block *pcVar3;
  c2_symbol *pcVar4;
  c2_block *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  uint uVar8;
  c2_tuple *pcVar9;
  c2_tuple *pcVar10;
  c2_symbol_cell **ppcVar11;
  c2_bitset *src;
  c2_bitset *dst;
  c2_symbol_cell *pcVar12;
  uint32_t uVar13;
  c2_symbol *pcVar14;
  c2_symbol_cell *pcVar15;
  c2_symbol_cell *pcVar16;
  c2_operand *local_4;
  
  for (loop_00 = loop->inner; loop_00 != (c2_loop *)0x0; loop_00 = loop_00->next) {
    mark_loop_invariants(loop_00);
  }
  pcVar3 = loop->last->next;
  pcVar2 = loop->first;
  for (pcVar5 = pcVar2; pcVar5 != pcVar3; pcVar5 = pcVar5->next) {
    if ((pcVar5->flags & 1) == 0) {
      pcVar9 = pcVar5->end;
      for (pcVar10 = pcVar5->head->next; pcVar10 != pcVar9; pcVar10 = pcVar10->next) {
        if ((pcVar10->flags & 1) != 0) {
          for (pcVar6 = pcVar10->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
            switch(mark_loop_invariants_dst_jump_index[pcVar6->kind]) {
            case 0:
              pcVar14 = pcVar6->sym;
              if (pcVar14->def == (c2_tuple *)0x0) {
                for (pcVar4 = pcVar14->storage; pcVar4 != (c2_symbol *)0x0;
                    pcVar4 = pcVar4->part_next) {
                  if (pcVar4 == pcVar14) {
LAB_10748b26:
                    bitset_set(g_loop_killed_syms,pcVar4->id);
                  }
                  else if ((pcVar4->offset < pcVar14->size + pcVar14->offset) &&
                          (pcVar14->offset < pcVar4->size + pcVar4->offset)) goto LAB_10748b26;
                }
              }
              goto LAB_10748aa8;
            case 1:
              pcVar14 = (c2_symbol *)pcVar6->tag;
              break;
            case 2:
              pcVar14 = pcVar6->sym;
            }
            uVar13 = sparse_set_test_and_add(g_alias_class_expanded,(uint32_t)pcVar14);
            if (uVar13 == 0) {
              pcVar12 = alias_class_members((uint32_t)pcVar14);
              pcVar15 = (c2_symbol_cell *)0x0;
joined_r0x10748b5b:
              if (pcVar12 != (c2_symbol_cell *)0x0) {
                do {
                  pcVar14 = pcVar12->sym;
                  pcVar16 = pcVar12;
                  if (pcVar14->cls == '\f') {
                    pcVar16 = (pcVar14->u30).members;
                    pcVar15 = pcVar12;
                    if (pcVar16 == (c2_symbol_cell *)0x0) {
                      pcVar12 = pcVar12->next;
                      goto joined_r0x10748b5b;
                    }
                    pcVar14 = pcVar16->sym;
                  }
                  for (pcVar4 = pcVar14->storage; pcVar4 != (c2_symbol *)0x0;
                      pcVar4 = pcVar4->part_next) {
                    if (pcVar4 == pcVar14) {
LAB_10748b75:
                      bitset_set(g_loop_killed_syms,pcVar4->id);
                    }
                    else if ((pcVar4->offset < pcVar14->size + pcVar14->offset) &&
                            (pcVar14->offset < pcVar4->size + pcVar4->offset)) goto LAB_10748b75;
                  }
                  pcVar12 = pcVar16->next;
                } while (pcVar12 != (c2_symbol_cell *)0x0);
                if (pcVar15 == (c2_symbol_cell *)0x0) goto LAB_10748aa8;
                ppcVar11 = &pcVar15->next;
                pcVar15 = (c2_symbol_cell *)0x0;
                pcVar12 = *ppcVar11;
                goto joined_r0x10748b5b;
              }
            }
LAB_10748aa8:
          }
        }
      }
    }
  }
  dst = bitset_new(0xc);
  src = g_trackable_syms;
  loop->invariant_syms = dst;
  bitset_copy(dst,src);
  bitset_andnot(dst,g_loop_killed_syms);
  for (pcVar5 = pcVar2; pcVar5 != pcVar3; pcVar5 = pcVar5->next) {
    if ((pcVar5->flags & 1) == 0) {
      pcVar10 = pcVar5->end;
      for (pcVar9 = pcVar5->head->next; pcVar9 != pcVar10; pcVar9 = pcVar9->next) {
        if ((pcVar9->flags & 1) != 0) {
          pcVar6 = pcVar9->src;
joined_r0x10748c52:
          if (pcVar6 != (c2_operand *)0x0) {
            bVar1 = pcVar6->flags11;
            pcVar6->flags11 = bVar1 & 0x7f;
            switch(pcVar6->kind) {
            case '\x01':
            case '\x02':
              if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0))
              goto override_jmp_10748c6c_case_4;
              uVar13 = bitset_test(g_loop_killed_syms,pcVar6->sym->id);
              goto joined_r0x10748ce0;
            default:
              goto override_jmp_10748c6c_case_1;
            case '\x05':
              goto override_jmp_10748c6c_case_2;
            case '\x06':
              goto override_jmp_10748c6c_case_3;
            case '\v':
              goto override_jmp_10748c6c_case_4;
            }
          }
        }
      }
    }
  }
  do {
    if (pcVar2 == pcVar3) {
      return;
    }
    uVar8 = pcVar2->flags;
    if ((uVar8 & 1) == 0) {
      pcVar9 = pcVar2->end;
      for (pcVar10 = pcVar2->head->next; pcVar10 != pcVar9; pcVar10 = pcVar10->next) {
        if (((((pcVar10->flags & 1) != 0) && (pcVar6 = pcVar10->dst, pcVar6 != (c2_operand *)0x0))
            && ((1 << (pcVar6->kind & 0x1f) & 6U) != 0)) &&
           ((pcVar6->sym->def != (c2_tuple *)0x0 && ((pcVar6->flags11 & 0x80) == 0)))) {
          for (pcVar7 = pcVar10->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
            if ((pcVar7->flags11 & 0x80) == 0) goto LAB_10748d7e;
          }
          pcVar6->flags11 = pcVar6->flags11 | 0x80;
          find_next_use_of_dst(pcVar10,&local_4);
          local_4->flags11 = local_4->flags11 | 0x80;
        }
LAB_10748d7e:
      }
      pcVar2->flags = uVar8 | 1;
    }
    pcVar2 = pcVar2->next;
  } while( true );
override_jmp_10748c6c_case_3:
  pcVar12 = alias_class_members(pcVar6->tag);
  pcVar15 = (c2_symbol_cell *)0x0;
joined_r0x10748c9e:
  if (pcVar12 != (c2_symbol_cell *)0x0) {
    do {
      pcVar14 = pcVar12->sym;
      pcVar16 = pcVar12;
      if (pcVar14->cls == '\f') {
        pcVar16 = (pcVar14->u30).members;
        pcVar15 = pcVar12;
        if (pcVar16 == (c2_symbol_cell *)0x0) {
          pcVar12 = pcVar12->next;
          goto joined_r0x10748c9e;
        }
        pcVar14 = pcVar16->sym;
      }
      for (pcVar14 = pcVar14->storage; pcVar14 != (c2_symbol *)0x0; pcVar14 = pcVar14->part_next) {
        uVar13 = bitset_test(g_loop_killed_syms,pcVar14->id);
        if (uVar13 != 0) goto override_jmp_10748c6c_case_4;
      }
      pcVar12 = pcVar16->next;
    } while (pcVar12 != (c2_symbol_cell *)0x0);
    if (pcVar15 == (c2_symbol_cell *)0x0) goto override_jmp_10748c6c_case_2;
    ppcVar11 = &pcVar15->next;
    pcVar15 = (c2_symbol_cell *)0x0;
    pcVar12 = *ppcVar11;
    goto joined_r0x10748c9e;
  }
override_jmp_10748c6c_case_2:
  if (pcVar6->op == 0x14c) {
    pcVar7 = pcVar6->base;
    if (((1 << (pcVar7->kind & 0x1f) & 6U) == 0) || (pcVar7->sym->def == (c2_tuple *)0x0)) {
      uVar13 = bitset_test(g_loop_killed_syms,pcVar7->sym->id);
joined_r0x10748ce0:
      if (uVar13 == 0) goto override_jmp_10748c6c_case_1;
    }
  }
  else {
override_jmp_10748c6c_case_1:
    pcVar6->flags11 = bVar1 & 0x7f | 0x80;
  }
override_jmp_10748c6c_case_4:
  pcVar6 = pcVar6->next;
  goto joined_r0x10748c52;
}

