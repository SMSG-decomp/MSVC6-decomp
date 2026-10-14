uint32_t __fastcall thread_cond_branch_by_implication(c2_tuple *referrer)

{
  byte bVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_node *target;
  
  pcVar2 = tuple_next_real(*(c2_tuple **)((int)&referrer->src->sym->u30 + 2));
  if (((pcVar2->kind == '\x11') && ((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0)) &&
     (referrer != pcVar2)) {
    bVar1 = (byte)referrer->type;
    if ((g_cond_implies_not[bVar1] & 1 << ((byte)pcVar2->type & 0x1f)) != 0) {
      pcVar2 = label_after_or_create(pcVar2);
      tuple_retarget(referrer,(c2_node *)pcVar2,0);
      return 1;
    }
    target = (c2_node *)0x0;
    iVar3 = 4;
    do {
      if (((pcVar2->kind != '\x11') ||
          (((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar2->op != 0x18b)))) ||
         ((g_cond_implies[bVar1] & 1 << ((byte)pcVar2->type & 0x1f)) == 0)) break;
      if ((pcVar2->src->kind != '\x04') ||
         (target = *(c2_node **)&(pcVar2->src->sym->u30).globopt.marks,
         (c2_operand *)target == (c2_operand *)0x0)) {
        target = (c2_node *)pcVar2->src;
        break;
      }
      pcVar2 = tuple_next_real((c2_tuple *)target);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (((c2_operand *)target != (c2_operand *)0x0) &&
       ((target != g_jumpopt_last_threaded_target || (referrer != g_jumpopt_last_threaded_branch))))
    {
      tuple_retarget(referrer,target,0);
      g_jumpopt_last_threaded_target = target;
      g_jumpopt_last_threaded_branch = referrer;
      if (0 < iVar3) {
        return 1;
      }
    }
  }
  return 0;
}

