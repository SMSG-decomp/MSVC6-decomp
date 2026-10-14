c2_tuple * __fastcall merge_test_branch_chain(c2_tuple *t,c2_tuple *t2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *br;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  int iVar9;
  c2_tuple *t_00;
  c2_tuple *pcVar10;
  c2_tuple *local_18;
  c2_tuple *local_14;
  c2_operand *local_10;
  
  t_00 = t->next;
  if ((t_00->op == 0xf) &&
     (((cVar1 = (char)t_00->type, cVar1 == '\x02' || (cVar1 == '\x01')) &&
      (local_10 = t->src->next, local_10->kind == '\a')))) {
    pcVar5 = t->prev;
    local_14 = t;
    local_18 = t2;
    while( true ) {
      while ((pcVar8 = pcVar5, pcVar8 != (c2_tuple *)0x0 && ((pcVar8->flags & 1) == 0))) {
        if (pcVar8->kind != '\x19') {
          return local_18;
        }
        pcVar5 = pcVar8->prev;
      }
      t2 = local_18;
      if (pcVar8->op != 0xf) break;
      pcVar4 = pcVar8->prev;
      pcVar5 = pcVar4->prev;
      if (pcVar4->op != 0x33) {
        return local_18;
      }
      if ((char)pcVar8->type != '\x02') {
        return local_18;
      }
      for (pcVar10 = t_00->next; pcVar10 != (c2_tuple *)0x0; pcVar10 = pcVar10->next) {
        if (((pcVar10->flags & 1) != 0) || (pcVar10->kind == '\x1a')) {
          if ((pcVar10 != (c2_tuple *)0x0) &&
             (((pcVar10->flags & 1) == 0 && (pcVar10->kind == '\x1a')))) goto LAB_1072331f;
          break;
        }
      }
      pcVar10 = (c2_tuple *)0x0;
LAB_1072331f:
      bVar2 = (byte)pcVar8->type;
      bVar3 = (byte)t_00->type;
      if (bVar2 == bVar3) {
        if (*(int *)((int)&pcVar8->src->sym->u30 + 2) != *(int *)((int)&t_00->src->sym->u30 + 2)) {
          return local_18;
        }
      }
      else {
        if (bVar2 != g_cond_inverse[bVar3]) {
          return local_18;
        }
        if (pcVar10 == (c2_tuple *)0x0) {
          return local_18;
        }
        if (*(c2_tuple **)((int)&pcVar8->src->sym->u30 + 2) != pcVar10) {
          return local_18;
        }
      }
      pcVar6 = pcVar4->src->next;
      iVar9 = operand_compare(pcVar4->src,t->src);
      if ((iVar9 == 0) && (pcVar6->kind == '\a')) {
        br = t->prev;
        (pcVar6->u18).lo = (pcVar6->u18).lo | (local_10->u18).lo;
        for (; (br != (c2_tuple *)0x0 && ((br->flags & 1) == 0)); br = br->prev) {
        }
        bVar2 = (byte)br->type;
        bVar3 = (byte)t_00->type;
        if ((bVar2 != bVar3) && (bVar2 != g_cond_inverse[bVar3])) {
          return local_18;
        }
        pcVar7 = *(c2_tuple **)((int)&br->src->sym->u30 + 2);
        if (pcVar7 == *(c2_tuple **)((int)&t_00->src->sym->u30 + 2)) {
          *(byte *)&br->type = bVar3;
        }
        else {
          if (pcVar7 != pcVar10) {
            return local_18;
          }
          branch_invert_condition(br);
          tuple_retarget(br,*(c2_node **)((int)&t_00->src->sym->u30 + 2),0);
        }
        if (local_18 == t_00) {
          local_18 = t_00->next;
        }
        tuple_unlink_free(local_14);
        branch_free(t_00);
        local_10 = pcVar6;
        local_14 = pcVar4;
        t = pcVar4;
        t_00 = pcVar8;
      }
    }
  }
  return t2;
}

