void __fastcall recompute_last_use_flags(c2_function *fn,int reg_class)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  c2_block *pcVar3;
  c2_tuple *t;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_symbol *pcVar6;
  byte bVar7;
  c2_bitset *dst;
  uint32_t uVar8;
  int iVar9;
  c2_operand *pcVar10;
  
  dst = bitset_new(6);
  pcVar3 = fn->cfg->first;
  do {
    if (pcVar3 == (c2_block *)0x0) {
      bitset_free(dst);
      return;
    }
    if ((pcVar3->flags & 0x80000) != 0) {
      pcVar3->flags = pcVar3->flags & 0xfff7ffff;
      bitset_copy(dst,pcVar3->live_out);
      pcVar4 = pcVar3->head;
      for (t = pcVar3->end; t != pcVar4; t = t->prev) {
        if ((t->flags & 1) != 0) {
          for (pcVar5 = t->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if ((pcVar5->kind == '\x01') && (g_type_class[pcVar5->type >> 0xc] == reg_class)) {
              pcVar6 = (pcVar5->u18).reg;
              uVar2 = pcVar6->cls;
              if (uVar2 == '\x01') {
                if (pcVar5->sym->cls != '\x01') {
                  pcVar10 = find_src_reg_operand(pcVar6,t);
                  if (pcVar10 == (c2_operand *)0x0) {
                    bVar7 = pcVar5->flags11 | 0x10;
                  }
                  else {
                    bVar7 = pcVar5->flags11 & 0xef;
                  }
                  pcVar5->flags11 = bVar7;
                }
              }
              else if (uVar2 == '\x02') {
                bitset_clear(dst,pcVar6->id);
              }
              else if (uVar2 == '\x03') {
                pcVar10 = find_src_reg_operand(pcVar6,t);
                if (pcVar10 == (c2_operand *)0x0) {
                  bVar7 = pcVar5->flags11 | 0x10;
                }
                else {
                  bVar7 = pcVar5->flags11 & 0xef;
                }
                pcVar5->flags11 = bVar7;
                if ((pcVar5->type & 0xfff) == 1) {
                  puVar1 = &((pcVar5->u18).reg)->flags5;
                  *puVar1 = *puVar1 | 0x80;
                }
              }
            }
          }
          for (pcVar5 = t->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if (pcVar5->kind == '\x01') {
              pcVar5->rank = 0;
              if (g_type_class[pcVar5->type >> 0xc] == reg_class) {
                pcVar6 = (pcVar5->u18).reg;
                uVar2 = pcVar6->cls;
                if (uVar2 == '\x01') {
                  if (pcVar5->sym->cls != '\x01') {
                    pcVar10 = find_dst_reg_operand(pcVar6,t);
                    if ((pcVar10 != (c2_operand *)0x0) && (pcVar10->sym->cls == '\x03'))
                    goto LAB_10716de2;
                    pcVar5->flags11 = pcVar5->flags11 | 0x10;
                  }
                }
                else if (uVar2 == '\x02') {
                  uVar8 = bitset_test(dst,pcVar6->id);
                  if ((uVar8 == 0) && (iVar9 = operand_list_has_same_reg(pcVar5), iVar9 == 0)) {
                    pcVar5->flags11 = pcVar5->flags11 | 0x10;
                    bitset_set(dst,((pcVar5->u18).reg)->id);
                  }
                  else {
LAB_10716de2:
                    pcVar5->flags11 = pcVar5->flags11 & 0xef;
                  }
                }
                else if (uVar2 == '\x03') {
                  pcVar10 = find_dst_reg_operand(pcVar6,t);
                  if (pcVar10 == (c2_operand *)0x0) {
                    bVar7 = pcVar5->flags11 | 0x10;
                  }
                  else {
                    bVar7 = pcVar5->flags11 & 0xef;
                  }
                  pcVar5->flags11 = bVar7;
                  if ((pcVar5->type & 0xfff) == 1) {
                    puVar1 = &((pcVar5->u18).reg)->flags5;
                    *puVar1 = *puVar1 | 0x80;
                  }
                }
              }
            }
            else if (pcVar5->kind == '\x02') {
              pcVar5->rank = 0;
            }
          }
        }
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

