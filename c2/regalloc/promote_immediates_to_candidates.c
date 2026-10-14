int __fastcall promote_immediates_to_candidates(c2_tuple *t)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  uint uVar5;
  c2_operand *pcVar6;
  int iVar7;
  c2_symbol *pcVar8;
  uint32_t local_4;
  
  local_4 = 1;
  do {
    if (t == (c2_tuple *)0x0) {
      return local_4;
    }
    if ((t->flags & 1) != 0) {
      pcVar6 = t->dst;
      for (pcVar4 = pcVar6; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        uVar5 = (uint)pcVar4->type;
        if ((uVar5 & 0xfff) != 4) {
          if (pcVar4->kind == '\x01') {
            if (((pcVar4->u18).reg)->cls == '\x02') {
              pcVar8 = pcVar4->sym->storage;
              if ((int)(uVar5 & 0xfff) < pcVar8->size) {
                uVar1 = pcVar4->sym->cls;
joined_r0x1071a926:
                if (uVar1 != '\x03') {
                  pcVar8->flags5 = pcVar8->flags5 | 0x80;
                }
              }
            }
          }
          else if (pcVar4->kind == '\x02') {
            pcVar8 = pcVar4->sym->storage;
            if ((int)(uVar5 & 0xfff) < pcVar8->size) {
              uVar1 = pcVar4->sym->cls;
              goto joined_r0x1071a926;
            }
          }
        }
      }
      if (t->op == 0x12) {
        if (((pcVar6->u18).reg)->cls == '\x02') {
          pcVar6 = t->src;
          if (pcVar6->op == 0x14c) {
            pcVar4 = pcVar6->base;
            if (((((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
                 (pcVar8 = pcVar4->sym, pcVar8->def != (c2_tuple *)0x0)) &&
                (pcVar2 = (pcVar4->u18).reg, pcVar2->cls == '\x03')) &&
               (pcVar4 = find_dst_reg_operand(pcVar2,t), pcVar4 == (c2_operand *)0x0)) {
              pcVar3 = pcVar8->def;
              pcVar4 = find_src_reg_operand(pcVar2,pcVar3);
              if ((pcVar4 == (c2_operand *)0x0) && (pcVar8->storage->part_next == (c2_symbol *)0x0))
              {
                pcVar4 = find_dst_reg_operand(pcVar2,pcVar3);
                operand_make_sym(pcVar4);
                mark_operand_register_candidate(pcVar4);
                pcVar6 = pcVar6->base;
LAB_1071a9c4:
                operand_make_sym(pcVar6);
                mark_operand_register_candidate(pcVar6);
                pcVar8->def = (c2_tuple *)0x0;
              }
            }
          }
          else if (((((g_opt_favor_speed != 0) && (pcVar6->op == 0x14f)) &&
                    (pcVar4 = pcVar6->index, (1 << (pcVar4->kind & 0x1f) & 6U) != 0)) &&
                   ((pcVar8 = pcVar4->sym, pcVar8->def != (c2_tuple *)0x0 &&
                    (pcVar2 = (pcVar4->u18).reg, pcVar2->cls == '\x03')))) &&
                  (pcVar4 = find_dst_reg_operand(pcVar2,t), pcVar4 == (c2_operand *)0x0)) {
            pcVar3 = pcVar8->def;
            pcVar4 = find_src_reg_operand(pcVar2,pcVar3);
            if ((pcVar4 == (c2_operand *)0x0) && (pcVar8->storage->part_next == (c2_symbol *)0x0)) {
              pcVar4 = find_dst_reg_operand(pcVar2,pcVar3);
              operand_make_sym(pcVar4);
              mark_operand_register_candidate(pcVar4);
              pcVar6 = pcVar6->index;
              goto LAB_1071a9c4;
            }
          }
        }
      }
      else {
        for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if (pcVar6->kind == 7) {
            iVar7 = tuple_allows_constant_candidate(t);
            if (iVar7 != 0) goto LAB_1071aaed;
          }
          else if ((((1 << (pcVar6->kind & 0x1f) & 0x18U) != 0) &&
                   (iVar7 = tuple_allows_constant_candidate(t), iVar7 != 0)) &&
                  ((t->kind != '\x0e' && (t->kind != '\x11')))) {
LAB_1071aaed:
            pcVar6 = make_constant_candidate_operand(t,pcVar6,&local_4);
          }
        }
      }
    }
    t = t->next;
  } while( true );
}

