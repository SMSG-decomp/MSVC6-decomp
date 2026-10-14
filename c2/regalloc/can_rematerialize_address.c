int __fastcall
can_rematerialize_address(c2_tuple *def,c2_live_range *lr,c2_bitset *inputs,int budget)

{
  uint32_t n;
  c2_tuple *t;
  c2_tuple *pcVar1;
  c2_bitset *bs;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  bool bVar4;
  uint32_t uVar5;
  c2_bitset *dst;
  c2_operand *addr;
  int iVar6;
  c2_block *pcVar7;
  int local_1c;
  int local_18;
  int local_14;
  c2_operand *local_4;
  
  local_1c = 0;
  local_14 = 0;
  local_18 = 0;
  for (pcVar2 = def->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x02')) {
      if ((((pcVar2->u18).reg)->flags5 & 0x10) != 0) {
        return 0;
      }
      local_1c = local_1c + 1;
    }
  }
  if (def->src->op == 0x14e) {
    local_1c = local_1c + 1;
  }
  pcVar7 = lr->first_block;
  n = lr->id;
  do {
    uVar5 = bitset_test(pcVar7->live,n);
    if (uVar5 != 0) {
      bs = pcVar7->live_in;
      uVar5 = bitset_test(bs,n);
      if (uVar5 == 0) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
        dst = bitset_clone(inputs);
        bitset_andnot(dst,bs);
        if (dst->chunks != (c2_bitset_chunk *)0x0) {
          bitset_free(dst);
LAB_10768763:
          lr->flags5 = lr->flags5 | 4;
          return 0;
        }
        bitset_free(dst);
      }
      pcVar1 = pcVar7->end;
      for (t = pcVar7->head; t != pcVar1; t = t->next) {
        if ((t->flags & 1) != 0) {
          for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((pcVar2->kind == '\x01') && (pcVar3 = (pcVar2->u18).reg, pcVar3->cls == '\x02')) {
              if (pcVar3 == (c2_symbol *)lr) {
                if ((pcVar2->flags11 & 0x10) != 0) {
                  bVar4 = false;
                }
                addr = find_mem_operand_using(t,pcVar2,&local_4);
                iVar6 = address_rematerializable(addr,pcVar2,local_1c);
                if (iVar6 == 0) goto LAB_10768763;
                iVar6 = operand_list_has_same_reg(pcVar2);
                if (iVar6 == 0) {
                  iVar6 = remat_use_cost(addr,def);
                  local_14 = local_14 + iVar6;
                }
              }
              else {
                uVar5 = bitset_test(inputs,pcVar3->id);
                if (((uVar5 != 0) && (bVar4)) && ((pcVar2->flags11 & 0x10) != 0)) goto LAB_1076874a;
              }
            }
          }
          for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((pcVar2->kind == '\x01') && (pcVar3 = (pcVar2->u18).reg, pcVar3->cls == '\x02')) {
              if (pcVar3 == (c2_symbol *)lr) {
                bVar4 = true;
                local_18 = local_18 + 1;
              }
              else {
                uVar5 = bitset_test(inputs,pcVar3->id);
                if ((uVar5 != 0) && (bVar4)) {
LAB_1076874a:
                  lr->flags5 = lr->flags5 | 4;
                  return 0;
                }
              }
            }
          }
        }
      }
      if (pcVar7 == lr->last_block) {
        iVar6 = remat_definition_cost(def);
        return (uint)(local_14 <= iVar6 * local_18 + budget);
      }
    }
    pcVar7 = pcVar7->next;
  } while( true );
}

