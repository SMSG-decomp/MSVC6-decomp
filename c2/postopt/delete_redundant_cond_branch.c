c2_tuple * __fastcall delete_redundant_cond_branch(c2_tuple *jmp)

{
  c2_tuple *pcVar1;
  int iVar2;
  c2_tuple *pcVar3;
  
  pcVar3 = tuple_next_real(jmp);
  if (((((pcVar3->kind == '\x11') && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
       (pcVar3->op != 0x18b)) &&
      ((pcVar3->src->kind == '\x04' &&
       (iVar2 = *(int *)((int)&pcVar3->src->sym->u30 + 2), iVar2 != 0)))) &&
     ((pcVar3->op != 0x18c && (iVar2 == *(int *)((int)&jmp->src->sym->u30 + 2))))) {
    pcVar3 = jmp->next;
    branch_delete(jmp);
    return pcVar3;
  }
  if (pcVar3->op == 0x18c) {
    pcVar3 = tuple_new_jmp_before(*(c2_tuple **)((int)&jmp->src->sym->u30 + 2),jmp->next);
    branch_delete(jmp);
    return pcVar3;
  }
  for (pcVar1 = jmp; pcVar1 != pcVar3->next; pcVar1 = pcVar1->next) {
    if (pcVar1->kind == '\x1a') {
      return (c2_tuple *)0x0;
    }
  }
  if (((pcVar3->kind == '\x11') && ((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0)) &&
     ((g_cond_implies[(byte)pcVar3->type] & 1 << ((byte)jmp->type & 0x1f)) != 0)) {
    branch_delete(pcVar3);
    return jmp;
  }
  return (c2_tuple *)0x0;
}

