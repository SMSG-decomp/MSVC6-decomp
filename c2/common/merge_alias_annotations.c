void __fastcall
merge_alias_annotations
          (c2_tuple *run_start,c2_tuple *t,c2_tuple *twin_run_start,c2_tuple *t2,c2_tuple *skip)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *local_8;
  
  local_8 = t;
joined_r0x1073dbf1:
  if ((local_8 == (c2_tuple *)0x0) || (t2 == (c2_tuple *)0x0)) {
    return;
  }
  for (; ((local_8->kind == '\x1a' || ((local_8->op == 0x1bc || (local_8 == skip)))) &&
         (local_8 != run_start)); local_8 = local_8->prev) {
  }
  for (; ((t2->kind == '\x1a' || (t2->op == 0x1bc)) && (t2 != twin_run_start)); t2 = t2->prev) {
  }
  pcVar1 = local_8->dst;
  pcVar2 = t2->dst;
  pcVar3 = (c2_operand *)0x0;
joined_r0x1073dc44:
  do {
    while( true ) {
      if ((pcVar1 == (c2_operand *)0x0) || (pcVar2 == (c2_operand *)0x0)) goto joined_r0x1073dc6a;
      pcVar4 = pcVar3;
      if (pcVar1->kind != '\x06') break;
      if ((pcVar2->kind == '\x06') && (pcVar1->tag == pcVar2->tag)) goto LAB_1073dc5d;
      pcVar4 = operand_new_memeffect(pcVar1->tag);
      pcVar4->next = pcVar3;
      if (pcVar2->kind == '\x06') goto LAB_1073dc5d;
      pcVar1 = pcVar1->next;
      pcVar3 = pcVar4;
    }
    if ((pcVar1->kind == '\v') && ((pcVar2->kind != '\v' || (pcVar1->sym != pcVar2->sym)))) {
      pcVar4 = operand_new_memeffect((uint32_t)pcVar1->sym);
      pcVar4->next = pcVar3;
      if (pcVar2->kind != '\v') {
        pcVar1 = pcVar1->next;
        pcVar3 = pcVar4;
        goto joined_r0x1073dc44;
      }
    }
LAB_1073dc5d:
    pcVar1 = pcVar1->next;
    pcVar2 = pcVar2->next;
    pcVar3 = pcVar4;
  } while( true );
joined_r0x1073dc6a:
  while (pcVar3 != (c2_operand *)0x0) {
    pcVar1 = pcVar3->next;
    pcVar3->next = (c2_operand *)0x0;
    tuple_append_dst(t2,pcVar3);
    pcVar3 = pcVar1;
  }
  pcVar1 = local_8->src;
  pcVar2 = t2->src;
  pcVar3 = (c2_operand *)0x0;
joined_r0x1073dc7a:
  do {
    while( true ) {
      if ((pcVar1 == (c2_operand *)0x0) || (pcVar2 == (c2_operand *)0x0)) goto joined_r0x1073dca0;
      pcVar4 = pcVar3;
      if (pcVar1->kind != '\x06') break;
      if ((pcVar2->kind == '\x06') && (pcVar1->tag == pcVar2->tag)) goto LAB_1073dc93;
      pcVar4 = operand_new_memeffect(pcVar1->tag);
      pcVar4->next = pcVar3;
      if (pcVar2->kind == '\x06') goto LAB_1073dc93;
      pcVar1 = pcVar1->next;
      pcVar3 = pcVar4;
    }
    if ((pcVar1->kind == '\v') && ((pcVar2->kind != '\v' || (pcVar1->sym != pcVar2->sym)))) {
      pcVar4 = operand_new_memeffect((uint32_t)pcVar1->sym);
      pcVar4->next = pcVar3;
      if (pcVar2->kind != '\v') {
        pcVar1 = pcVar1->next;
        pcVar3 = pcVar4;
        goto joined_r0x1073dc7a;
      }
    }
LAB_1073dc93:
    pcVar1 = pcVar1->next;
    pcVar2 = pcVar2->next;
    pcVar3 = pcVar4;
  } while( true );
joined_r0x1073dca0:
  while (pcVar3 != (c2_operand *)0x0) {
    pcVar1 = pcVar3->next;
    pcVar3->next = (c2_operand *)0x0;
    tuple_append_src(t2,pcVar3);
    pcVar3 = pcVar1;
  }
  for (; ((local_8->kind == '\x1a' || (local_8->op == 0x1bc)) && (local_8 != run_start));
      local_8 = local_8->prev) {
  }
  for (; ((t2->kind == '\x1a' || (t2->op == 0x1bc)) && (t2 != twin_run_start)); t2 = t2->prev) {
  }
  if (local_8 == run_start) {
    return;
  }
  if (t2 == twin_run_start) {
    return;
  }
  local_8 = local_8->prev;
  t2 = t2->prev;
  goto joined_r0x1073dbf1;
}

