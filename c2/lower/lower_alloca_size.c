c2_tuple * __fastcall lower_alloca_size(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_eh_alloca_marker *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)t;
  pcVar4 = find_next_use_of_dst(t,&local_4);
  if ((pcVar4->op != 0x15a) && (pcVar4->op != 0x16a)) {
    return t->next;
  }
  pcVar5 = (c2_operand *)find_next_use_of_dst(pcVar4,&local_4);
  for (pcVar1 = *(c2_operand **)&pcVar5->u18; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) &&
       ((pcVar1->flags & 0x20) == 0)) {
      pcVar5 = pcVar1;
    }
  }
  pcVar4 = pcVar5->sym->def;
  if ((((pcVar4->op == 0x16a) && ((1 << (pcVar4->src->kind & 0x1f) & 6U) != 0)) &&
      ((pcVar2 = pcVar4->src->sym->def, pcVar2 != (c2_tuple *)0x0 &&
       ((pcVar2->kind == '\x12' && ((pcVar2->u20).intrinsic.id == 0xdf)))))) ||
     ((pcVar4->kind == '\x12' && ((pcVar4->u20).intrinsic.id == 0xdf)))) {
    pcVar3 = g_eh_alloca_markers;
    if (pcVar4->op == 0x16a) {
      pcVar4 = pcVar4->src->sym->def;
    }
    for (; (pcVar3 != (c2_eh_alloca_marker *)0x0 && (pcVar3->intrinsic != pcVar4));
        pcVar3 = pcVar3->next) {
    }
    pcVar4 = pcVar3->addr_def;
    if ((pcVar4->op != 0x32) && (pcVar4->kind != '\x0e')) {
      pcVar4 = lower_alloca_size(pcVar4);
    }
  }
  if ((((pcVar4->op == 0x15a) || (pcVar4->op == 0x16a)) && ((pcVar4->type & 0xf000) == 0x4000)) &&
     ((pcVar4->src->kind == '\x01' && ((pcVar4->src->u18).reg == g_reg_symbols + 0x1f)))) {
    pcVar4 = pcVar4->prev->prev;
  }
  return pcVar4;
}

