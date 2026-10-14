uint32_t __fastcall tuple_reads_value_defined_before(c2_tuple *t,c2_tuple *limit)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  uint32_t uVar4;
  c2_tuple *t_00;
  c2_operand *pcVar5;
  uint local_c;
  
  local_c = 0;
  iVar3 = tuple_ordinal_less(t,limit);
  if (iVar3 != 0) {
    return 0;
  }
  if ((t->kind == '\x0e') || (t->kind == '\x12')) {
    for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      if ((((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
            (pcVar2 = pcVar1->sym->def, pcVar2 != (c2_tuple *)0x0)) &&
           ((pcVar2->op == 0x15a || (pcVar2->op == 0x16a)))) &&
          (iVar3 = tuple_ordinal_less(pcVar2,limit), iVar3 != 0)) &&
         ((pcVar5 = pcVar2->src, pcVar5->kind != '\x02' || ((pcVar5->sym->flags7 & 4) == 0)))) {
        t_00 = tuple_new_pseudo(0x1aa,pcVar2->type);
        tuple_detach_src((c2_node *)pcVar2,pcVar5);
        tuple_append_src(t_00,pcVar5);
        pcVar5 = operand_new_temp_sym(pcVar2->type);
        pcVar5->sym->flags7 = pcVar5->sym->flags7 | 6;
        tuple_append_dst(t_00,pcVar5);
        tuple_append_src(pcVar2,pcVar5);
        tuple_insert_before(pcVar2,t_00);
        local_c = 1;
      }
    }
  }
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
       (pcVar2 = pcVar1->sym->def, pcVar2 != (c2_tuple *)0x0)) {
      uVar4 = tuple_reads_value_defined_before(pcVar2,limit);
      local_c = local_c | uVar4;
    }
  }
  return local_c;
}

