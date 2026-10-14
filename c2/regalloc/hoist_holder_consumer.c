uint32_t __thiscall hoist_holder_consumer(c2_tuple *pos,uint32_t n)

{
  uint32_t uVar1;
  c2_symbol *reg;
  c2_operand *pcVar2;
  uint uVar3;
  c2_tuple *pcVar4;
  uint32_t uVar5;
  c2_tuple *t;
  c2_operand *pcVar6;
  int iVar7;
  uint32_t *local_c;
  c2_operand *local_8;
  c2_tuple *local_4;
  
  local_c = g_local_register_order;
  uVar1 = g_local_register_order[0];
  do {
    if (uVar1 == 0) {
      return 0;
    }
    local_c = local_c + 1;
    if ((g_register_holders[uVar1] != (c2_symbol *)0x0) &&
       (uVar5 = bitset_test(g_local_conflicts[uVar1],n), uVar5 == 0)) {
      reg = g_register_holders[uVar1];
      local_4 = pos->next;
      t = find_next_use_of_temp(reg,local_4,&local_8);
      pcVar6 = find_dst_reg_operand(reg,t);
      if (pcVar6 == (c2_operand *)0x0) {
        pcVar2 = t->dst;
        for (pcVar6 = pcVar2; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if ((pcVar6->kind == '\x01') && (((pcVar6->u18).reg)->cls == '\x03')) goto LAB_1075a869;
        }
        pcVar6 = t->src;
        while( true ) {
          if (pcVar6 == (c2_operand *)0x0) {
            for (; pcVar4 = pos, pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
              for (; pcVar4 != t; pcVar4 = pcVar4->next) {
                for (pcVar6 = pcVar4->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
                  iVar7 = operands_may_alias(pcVar2,pcVar6);
                  if ((iVar7 != 0) ||
                     (((((pcVar6->kind == '\x01' && (((pcVar6->u18).reg)->cls == '\x03')) &&
                        (pcVar2->kind == '\x01')) &&
                       ((uVar3 = ((pcVar2->u18).reg)->storage->id, uVar3 != 0 && (uVar3 < 9)))) &&
                      ((uVar3 != 5 &&
                       (uVar5 = bitset_test(g_local_conflicts[uVar3],((pcVar6->u18).reg)->id),
                       uVar5 == 0)))))) goto LAB_1075a869;
                }
              }
            }
            pcVar6 = t->src;
            do {
              if (pcVar6 == (c2_operand *)0x0) {
                assign_source_operand_registers(t);
                assign_destination_operand_registers(t);
                tuple_unlink(t);
                tuple_insert_before(pos,t);
                return uVar1;
              }
              pcVar4 = local_4;
              if (pcVar6 != local_8) {
                for (; pcVar4 != t; pcVar4 = pcVar4->next) {
                  for (pcVar2 = pcVar4->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                    iVar7 = operands_may_alias(pcVar6,pcVar2);
                    if (iVar7 != 0) goto LAB_1075a869;
                  }
                }
              }
              pcVar6 = pcVar6->next;
            } while( true );
          }
          if (((pcVar6->kind == '\x01') && (((pcVar6->u18).reg)->cls == '\x03')) &&
             ((pcVar6->u18).reg != reg)) break;
          pcVar6 = pcVar6->next;
        }
      }
    }
LAB_1075a869:
    uVar1 = *local_c;
  } while( true );
}

