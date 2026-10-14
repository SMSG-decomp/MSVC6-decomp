c2_tuple * __fastcall x87_keep_float_temp_on_stack(c2_tuple *t)

{
  c2_operand *b;
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  int iVar6;
  uint32_t *puVar7;
  uint32_t uVar8;
  int local_4;
  
  b = t->dst;
  if (((((b->kind != '\x01') && (t->src->kind == '\x01')) &&
       (pcVar1 = t->src->sym, pcVar1->cls == '\x03')) &&
      ((pcVar2 = pcVar1->def, pcVar2 != (c2_tuple *)0x0 && (t->type == 0x4004)))) &&
     ((b->kind != '\x06' && (pcVar2->op == 0x60)))) {
    pcVar3 = pcVar2->src;
    if (((pcVar3->kind != '\x01') && (pcVar3->type == b->type)) &&
       ((pcVar3->kind != '\x06' || (pcVar3->index == (c2_operand *)0x0)))) {
      pcVar4 = pcVar2->next;
      if (pcVar4 != t) {
        local_4 = 0;
        pcVar5 = t->prev->next;
        iVar6 = local_4;
        for (; pcVar4 != pcVar5; pcVar4 = pcVar4->next) {
          local_4 = iVar6;
          if ((pcVar4->flags & 1) != 0) {
            local_4 = iVar6 + 1;
            if (10 < iVar6) {
              return (c2_tuple *)0x0;
            }
            for (pcVar3 = pcVar4->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
              iVar6 = operands_may_alias(pcVar3,b);
              if (iVar6 != 0) {
                return (c2_tuple *)0x0;
              }
            }
            for (pcVar3 = pcVar4->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
              iVar6 = operands_may_alias(pcVar3,b);
              if (iVar6 != 0) {
                return (c2_tuple *)0x0;
              }
            }
          }
          iVar6 = local_4;
        }
      }
      g_x87_tos = 7;
      g_x87_next_value_id = 0;
      puVar7 = g_x87_stack_ids + 7;
      do {
        *puVar7 = g_x87_next_value_id;
        puVar7 = puVar7 + -1;
        g_x87_next_value_id = g_x87_next_value_id + 1;
      } while (0x107990e7 < (int)puVar7);
      pcVar4 = t->prev;
      iVar6 = x87_simulate_stack_ids(pcVar2->next,pcVar4);
      if (iVar6 != -1) {
        x87_snapshot_stack();
        uVar8 = 0;
        puVar7 = g_x87_stack_ids + 7;
        do {
          *puVar7 = uVar8;
          puVar7 = puVar7 + -1;
          uVar8 = uVar8 + 1;
        } while (0x107990e7 < (int)puVar7);
        g_x87_tos = 6;
        x87_rewrite_stack_operands(pcVar2->next,pcVar4);
        x87_restore_stack_order(t);
        return pcVar2;
      }
    }
  }
  return (c2_tuple *)0x0;
}

