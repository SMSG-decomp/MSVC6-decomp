void __fastcall split_memory_operands_g5(c2_function *fn)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  ushort uVar5;
  c2_bitset *bs;
  c2_operand *pcVar6;
  uint32_t uVar7;
  uint uVar8;
  uint n;
  int iVar9;
  
  g_local_register_order[6] = -(uint)(g_ebp_allocatable != 0) & 6;
  bs = bitset_new(6);
  pcVar2 = fn->cfg->first;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      bitset_free(bs);
      return;
    }
    g_g5_split_cursor = g_local_register_order_len + -1;
    if (g_no_global_candidates == 0) {
      bitset_copy(bs,pcVar2->set28);
    }
    else {
      bitset_clear_all(bs);
    }
    pcVar3 = pcVar2->head;
    for (t = pcVar2->end; t != pcVar3; t = t->prev) {
      if ((t->flags & 1) != 0) {
        uVar5 = t->line;
        if (uVar5 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar5;
          g_cur_line = uVar5;
        }
        for (pcVar4 = t->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((pcVar4->type & 0xf000) != 0x4000) && (pcVar4->kind == '\x01')) {
            if ((pcVar4->sym->cls == '\x03') && (pcVar4->sym->def != (c2_tuple *)0x0)) {
              if (((pcVar4->u18).reg)->cls == '\x01') {
                uVar7 = ((pcVar4->u18).reg)->storage->id;
                pcVar6 = operand_list_find_regid(uVar7,t->src);
                if (pcVar6 == (c2_operand *)0x0) {
                  if (pcVar4->next != (c2_operand *)0x0) {
                    pcVar6 = operand_list_find_regid(uVar7,pcVar4->next);
                    goto joined_r0x1073377a;
                  }
                  goto joined_r0x10733783;
                }
              }
            }
            else {
              uVar7 = ((pcVar4->u18).reg)->storage->id;
              pcVar6 = operand_list_find_regid(uVar7,t->src);
joined_r0x1073377a:
              if (pcVar6 == (c2_operand *)0x0) {
joined_r0x10733783:
                if (((uVar7 != 0) && (uVar7 < 9)) && (uVar7 != 5)) {
                  bitset_clear(bs,uVar7);
                }
              }
            }
          }
        }
        for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((pcVar4->type & 0xf000) != 0x4000) && (pcVar4->kind == '\x01')) {
            uVar1 = pcVar4->sym->cls;
            if ((uVar1 == '\x03') && (pcVar4->sym->def != (c2_tuple *)0x0)) {
              if ((((((pcVar4->u18).reg)->cls == '\x01') &&
                   (uVar8 = ((pcVar4->u18).reg)->storage->id, uVar8 != 0)) && (uVar8 < 9)) &&
                 (uVar8 != 5)) {
                uVar7 = bitset_test(bs,uVar8);
joined_r0x107337c8:
                if (uVar7 == 0) {
                  bitset_set(bs,uVar8);
                }
              }
            }
            else if ((((uVar1 != '\x01') && (uVar8 = ((pcVar4->u18).reg)->storage->id, uVar8 != 0))
                     && (uVar8 < 9)) && (uVar8 != 5)) {
              uVar7 = bitset_test(bs,uVar8);
              goto joined_r0x107337c8;
            }
          }
        }
        uVar8 = t->op;
        if (((uVar8 != 0) && (uVar8 < 0x144)) &&
           (((g_x86_op_flags[uVar8] & 0x400) != 0 &&
            (uVar8 = pick_g5_split_register(bs,0), uVar8 != 0)))) {
          iVar9 = 0;
          do {
            if (iVar9 == 0) {
              pcVar4 = t->dst;
            }
            else {
              pcVar4 = t->src;
            }
            for (; n = uVar8, pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              uVar1 = pcVar4->kind;
              if ((((uVar1 == '\x02') || (uVar1 == '\x06')) &&
                  ((((pcVar4->type & 0xf000) != 0x4000 &&
                    (((uVar1 != '\v' && (uVar1 != '\n')) && ((pcVar4->flags & 0x20) == 0)))) &&
                   (((uVar1 != '\x01' || (pcVar4->sym->cls != '\x01')) &&
                    (uVar5 = pcVar4->type & 0xfff, uVar5 != 2)))))) &&
                 (((uVar5 != 1 || (uVar8 < 5)) || (n = pick_g5_split_register(bs,1), n != 0)))) {
                g5_split_memory_operand(t,pcVar4,n,(uint)(iVar9 == 0));
                g_reg_symbols[n].flags5 = g_reg_symbols[n].flags5 | 0x10;
                bitset_set(bs,n);
                break;
              }
            }
            iVar9 = iVar9 + 1;
            uVar8 = n;
          } while (iVar9 < 2);
        }
      }
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

