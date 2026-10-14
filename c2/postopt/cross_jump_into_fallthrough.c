int __fastcall cross_jump_into_fallthrough(c2_tuple *jmp)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  c2_tuple *pcVar4;
  c2_tuple *a;
  c2_tuple *b;
  
  iVar2 = 0;
  bVar1 = false;
  pcVar4 = *(c2_tuple **)&(jmp->src->sym->u30).globopt.marks;
  a = jmp;
  b = pcVar4;
  while( true ) {
    b = b->prev;
    for (a = a->prev; (a->kind == '\x1a' || (a->op == 0x1bc)); a = a->prev) {
      if (a == pcVar4) goto LAB_1073d4fa;
      bVar1 = true;
    }
    for (; (b->kind == '\x1a' || (b->op == 0x1bc)); b = b->prev) {
    }
    if ((b == jmp) ||
       (((a->kind == '\x11' &&
         ((((a->u20).cond_cells != (c2_cond_cell *)0x0 || (a->op == 0x18b)) &&
          (g_opt_favor_speed != 0)))) || (iVar3 = tuples_equal(a,b), iVar3 == 0)))) break;
    iVar2 = iVar2 + 1;
  }
LAB_1073d4fa:
  if (iVar2 != 0) {
    if (bVar1) {
      cross_jump_fix_labels(a,jmp,b,pcVar4,0xffffffff,1);
    }
    merge_alias_annotations(a->next,jmp->prev,b->next,pcVar4->prev,(c2_tuple *)0x0);
    pcVar4 = label_after_or_create(b);
    tuple_retarget(jmp,(c2_node *)pcVar4,0);
    tuple_range_free(a->next,jmp);
    return 1;
  }
  return 0;
}

