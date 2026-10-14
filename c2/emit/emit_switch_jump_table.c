c2_tuple * __fastcall
emit_switch_jump_table
          (c2_switch_case_range *cases,c2_tuple *default_label,int ncases,int32_t step_lo,
          int32_t step_hi,c2_operand *selector,c2_tuple *anchor,int range_already_checked)

{
  uint32_t *puVar1;
  uint uVar2;
  c2_switch_case_range *pcVar3;
  c2_switch_case_range *last_case;
  c2_const_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  uint32_t span;
  int min_hi;
  int iVar7;
  ushort type;
  c2_insert_fn *splice_fn;
  uint min_lo;
  
  min_lo = cases->first;
  last_case = (c2_switch_case_range *)list_nth((c2_link *)cases,ncases + -1);
  span = last_case->last - min_lo;
  if (min_lo != 0) {
    min_hi = (int)min_lo >> 0x1f;
    splice_fn = tuple_splice_after;
    pcVar4 = operand_new_intconst(selector->type,min_lo,min_hi);
    pcVar5 = tuple_new_binary_temp(0x16e,selector->type,selector,pcVar4,splice_fn,anchor);
    anchor = tuple_new(0x15b,selector->type,selector,pcVar5->dst,tuple_splice_after,pcVar5);
    pcVar3 = cases;
    for (iVar7 = ncases; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar1 = &pcVar3->first;
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - min_lo;
      pcVar3->first_high = (pcVar3->first_high - min_hi) - (uint)(uVar2 < min_lo);
      puVar1 = &pcVar3->last;
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - min_lo;
      pcVar3->last_high = (pcVar3->last_high - min_hi) - (uint)(uVar2 < min_lo);
      pcVar3 = pcVar3->next;
    }
  }
  if (((g_switch_range_check != 0) && (range_already_checked == 0)) &&
     (g_switch_default_unreachable == 0)) {
    type = selector->type & 0xfff | 0x2000;
    splice_fn = tuple_splice_after;
    pcVar4 = operand_new_intconst(type,span,(int)span >> 0x1f);
    pcVar6 = (c2_operand *)node_clone((c2_node *)selector);
    pcVar6 = operand_set_type(pcVar6,type);
    pcVar5 = tuple_new_compare(0x17d,type,pcVar6,pcVar4,splice_fn,anchor);
    anchor = tuple_new_branch(0x185,'\x04',(c2_node *)default_label,pcVar5->dst,pcVar5,
                              tuple_splice_after,pcVar5);
  }
  pcVar5 = tuple_new_switch(0x18d,selector->type,selector,default_label,(c2_switch_case *)0x0,
                            tuple_splice_after,anchor);
  pcVar5->switch_flags =
       (g_switch_default_unreachable & 1U) << 1 | pcVar5->switch_flags & 0xfffffffd;
  switch_attach_case_targets(pcVar5,cases,ncases);
  return pcVar5;
}

