int __fastcall select_is_profitable(uint16_t cls,int a2,void *a3,void *a4,uint8_t a5,int a6)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *a;
  uint32_t uVar3;
  int iVar4;
  byte cc;
  c2_insert_fn *insert_fn;
  c2_tuple *pcVar5;
  c2_operand *local_c;
  
  local_c = (c2_operand *)0x0;
  if (((cls & 0xf000) != 0x5000) && ((cls & 0xf000) != 0x4000)) {
    if ((a6 != 0) && (iVar4 = operand_compare(a3,a4), iVar4 == 0)) {
      return 1;
    }
    if (*(int *)(a2 + 4) == 0x17d) {
      pcVar1 = *(c2_operand **)(a2 + 0x18);
      if (((1 << (pcVar1->kind & 0x1f) & 0x380U) == 0) ||
         ((1 << (pcVar1->next->kind & 0x1f) & 0x380U) == 0)) {
        if (a6 != 0) {
          if ((a5 == '\x01') || (a5 == '\x02')) {
            if ((pcVar1->kind == 7) && ((pcVar1->u18).reg == (c2_symbol *)0x0 && pcVar1->tag == 0))
            {
              local_c = pcVar1->next;
            }
            else {
              pcVar2 = pcVar1->next;
              if ((pcVar2->kind == '\a') &&
                 ((pcVar2->u18).reg == (c2_symbol *)0x0 && pcVar2->tag == 0)) {
                local_c = pcVar1;
              }
            }
          }
          if (local_c != (c2_operand *)0x0) {
            if (((*(char *)((int)a4 + 8) == '\a') &&
                (*(int *)((int)a4 + 0x18) == 0 && *(int *)((int)a4 + 0x1c) == 0)) &&
               (iVar4 = operand_compare(local_c,a3), iVar4 == 0)) {
              return 1;
            }
            if (((*(char *)((int)a3 + 8) == '\a') &&
                (*(int *)((int)a3 + 0x18) == 0 && *(int *)((int)a3 + 0x1c) == 0)) &&
               (iVar4 = operand_compare(local_c,a4), iVar4 == 0)) {
              return 1;
            }
          }
        }
        pcVar5 = (c2_tuple *)0x0;
        insert_fn = (c2_insert_fn *)0x0;
        cc = g_cond_inverse[a5];
        pcVar1 = (c2_operand *)node_clone(a4);
        pcVar2 = (c2_operand *)node_clone(a3);
        a = (c2_operand *)node_clone(*(c2_node **)(a2 + 0x1c));
        pcVar5 = tuple_new_ternary_temp(399,cls,a,pcVar2,pcVar1,cc,insert_fn,pcVar5);
        uVar3 = select_cost_within_threshold(pcVar5);
        symbol_free_chain(pcVar5->dst->sym);
        node_free((c2_node *)pcVar5);
        return uVar3;
      }
    }
  }
  return 0;
}

