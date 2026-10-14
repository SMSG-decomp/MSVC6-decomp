void __fastcall late_stack_temp_forwarding(c2_function *fn)

{
  c2_cfg *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  uint32_t *puVar6;
  c2_bitset *dst;
  c2_bitset *src;
  c2_bitset *bs;
  uint32_t uVar7;
  int iVar8;
  c2_operand *pcVar9;
  c2_tuple *t;
  uint32_t uVar10;
  c2_tuple *local_10;
  uint32_t *local_c;
  
  dst = bitset_new(4);
  src = bitset_new(4);
  bs = bitset_new(4);
  pcVar1 = fn->cfg;
  local_c = (uint32_t *)0x0;
  pcVar2 = pcVar1->first->head;
  for (pcVar4 = pcVar2; pcVar4 != (c2_tuple *)0x0; pcVar4 = pcVar4->next) {
    if ((pcVar4->kind == 0x1a) || ((1 << (pcVar4->kind & 0x1f) & 0xa0000U) != 0)) {
      bitset_or(dst,src);
      bitset_or(src,dst);
    }
    else if ((pcVar4->flags & 1) != 0) {
      puVar6 = local_c;
      for (pcVar9 = pcVar4->src; local_c = puVar6, pcVar9 != (c2_operand *)0x0;
          pcVar9 = pcVar9->next) {
        if ((((1 << (pcVar9->kind & 0x1f) & 6U) == 0) ||
            (pcVar3 = pcVar9->sym, pcVar3->cls != '\x03')) || (pcVar3->def != (c2_tuple *)0x0)) {
          if (pcVar9->kind == 6) {
            pcVar5 = pcVar9->base;
            if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
               ((pcVar3 = pcVar5->sym, pcVar3->cls == '\x03' && (pcVar3->def == (c2_tuple *)0x0))))
            {
              uVar10 = pcVar3->id;
              bitset_clear(bs,uVar10);
              bitset_set(src,uVar10);
            }
            pcVar5 = pcVar9->index;
            if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
               ((pcVar3 = pcVar5->sym, pcVar3->cls == '\x03' && (pcVar3->def == (c2_tuple *)0x0))))
            {
              uVar10 = pcVar3->id;
              goto LAB_1073fb11;
            }
          }
        }
        else {
          uVar10 = pcVar3->id;
          uVar7 = bitset_test(bs,uVar10);
          if (uVar7 == 0) {
            if (((((((pcVar9->flags & 0x40) == 0) && ((pcVar9->flags11 & 8) == 0)) &&
                  ((pcVar4->type & 0xf000) != 0x4000)) &&
                 ((pcVar9->kind != '\x01' && (uVar7 = bitset_test(src,uVar10), uVar7 == 0)))) &&
                (uVar7 = bitset_test(dst,uVar10), uVar7 != 0)) &&
               (pcVar5 = pcVar4->dst, pcVar5->kind == '\x01')) {
              bitset_set(bs,uVar10);
              local_c = arena_alloc(4,0x10);
              *local_c = uVar10;
              local_c[1] = (uint32_t)pcVar5;
              local_c[2] = (uint32_t)pcVar4;
              local_c[3] = (uint32_t)puVar6;
            }
          }
          else {
LAB_1073fb11:
            bitset_clear(bs,uVar10);
          }
          bitset_set(src,uVar10);
        }
        puVar6 = local_c;
      }
      for (pcVar9 = pcVar4->dst; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
        if ((((1 << (pcVar9->kind & 0x1f) & 6U) != 0) &&
            (pcVar3 = pcVar9->sym, pcVar3->cls == '\x03')) && (pcVar3->def == (c2_tuple *)0x0)) {
          uVar10 = pcVar3->id;
          uVar7 = bitset_test(bs,uVar10);
          if (uVar7 != 0) {
            bitset_clear(bs,uVar10);
          }
          bitset_set(dst,uVar10);
        }
      }
    }
  }
  if (bs->chunks != (c2_bitset_chunk *)0x0) {
    pcVar4 = pcVar1->last->end;
    local_10 = pcVar2->next;
joined_r0x1073fc32:
    pcVar2 = local_10;
    if (pcVar2 != pcVar4) {
      local_10 = pcVar2->next;
      if (((pcVar2->flags & 1) != 0) && (pcVar9 = pcVar2->dst, pcVar9 != (c2_operand *)0x0)) {
        while (((1 << (pcVar9->kind & 0x1f) & 6U) == 0 ||
               ((pcVar9->sym->cls != '\x03' || (pcVar9->sym->def != (c2_tuple *)0x0))))) {
          pcVar9 = pcVar9->next;
          if (pcVar9 == (c2_operand *)0x0) goto joined_r0x1073fc32;
        }
        uVar10 = pcVar9->sym->id;
        uVar7 = bitset_test(bs,uVar10);
        if (uVar7 == 0) goto joined_r0x1073fc32;
        uVar7 = *local_c;
        puVar6 = local_c;
        while (uVar7 != uVar10) {
          puVar6 = (uint32_t *)puVar6[3];
          uVar7 = *puVar6;
        }
        t = (c2_tuple *)puVar6[2];
        uVar10 = t->op;
        if (((((uVar10 == 1) || (uVar10 == 0x38)) || (uVar10 == 0xc2)) ||
            ((uVar10 == 0xc3 || (uVar10 == 0xc4)))) ||
           ((uVar10 == 0xc5 || ((uVar10 == 0xd0 || (uVar10 == 0xe6)))))) {
          pcVar5 = (c2_operand *)puVar6[1];
          iVar8 = range_may_alias(pcVar2->next,&t->prev->next,pcVar5);
          if (iVar8 != 0) goto LAB_1073fcc1;
          tuple_replace_dst(pcVar2,pcVar9,pcVar5);
          if (local_10 == t) {
            local_10 = local_10->next;
          }
        }
        else {
LAB_1073fcc1:
          pcVar5 = pcVar2->src;
          if ((pcVar5->next != (c2_operand *)0x0) ||
             (((((uVar10 = pcVar2->op, uVar10 != 1 && (uVar10 != 0x38)) && (uVar10 != 0xc2)) &&
               (((uVar10 != 0xc3 && (uVar10 != 0xc4)) &&
                ((uVar10 != 0xc5 && ((uVar10 != 0xd0 && (uVar10 != 0xe6)))))))) ||
              (iVar8 = range_may_alias(pcVar2->next,&t->prev->next,pcVar5), iVar8 != 0))))
          goto joined_r0x1073fc32;
          pcVar9 = find_src_symbol_ref(t,pcVar9->sym);
          tuple_replace_src(t,pcVar9,pcVar5);
          t = pcVar2;
        }
        tuple_unlink_free(t);
      }
      goto joined_r0x1073fc32;
    }
  }
  return;
}

