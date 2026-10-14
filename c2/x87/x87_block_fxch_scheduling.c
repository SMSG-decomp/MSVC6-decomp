void __fastcall x87_block_fxch_scheduling(c2_function *fn)

{
  c2_block *pcVar1;
  c2_tuple *t;
  c2_tuple *t2;
  int iVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  
  if ((g_opt_favor_speed != 0) && ((fn->flags & 8) != 0)) {
    for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
      t = pcVar1->head;
      t2 = pcVar1->end;
      g_x87_tos = 7;
      g_x87_next_value_id = 0;
      puVar3 = g_x87_stack_ids + 7;
      do {
        *puVar3 = g_x87_next_value_id;
        puVar3 = puVar3 + -1;
        g_x87_next_value_id = g_x87_next_value_id + 1;
      } while (0x107990e7 < (int)puVar3);
      iVar2 = x87_simulate_stack_ids(t,t2);
      if (-1 < iVar2) {
        x87_snapshot_stack();
        g_x87_tos = 7;
        uVar4 = 0;
        puVar3 = g_x87_stack_ids + 7;
        do {
          *puVar3 = uVar4;
          puVar3 = puVar3 + -1;
          uVar4 = uVar4 + 1;
        } while (0x107990e7 < (int)puVar3);
        x87_rewrite_stack_operands(t,t2);
        for (; (((t2 != (c2_tuple *)0x0 && (t2 != t)) && ((t2->type & 0xf000) != 0x4000)) &&
               (((t2->kind != '\x0e' && (t2->kind != '\x12')) && (t2->op != 0x5b)))); t2 = t2->prev)
        {
        }
        x87_restore_stack_order(t2->next);
      }
    }
  }
  return;
}

