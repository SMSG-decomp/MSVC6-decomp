c2_tuple * __fastcall
emit_switch_compare_chain
          (c2_switch_case_range *cases,c2_tuple *default_label,int ncases,c2_operand *selector,
          c2_tuple *anchor)

{
  uint16_t uVar1;
  int iVar2;
  c2_tuple *pcVar3;
  c2_const_operand *pcVar4;
  c2_tuple *cond_def;
  uint32_t lo;
  uint uVar5;
  int hi;
  uint8_t uVar6;
  uint hi_00;
  bool bVar7;
  c2_operand *cond;
  c2_insert_fn *splice_fn;
  
  uVar1 = selector->type;
  iVar2 = switch_dec_chain_profitable(cases,ncases,uVar1);
  if (iVar2 == 0) {
    switch_narrow_to_byte_compares_thunk(cases,anchor,ncases);
    for (iVar2 = ncases + -1; (-1 < iVar2 && ((g_switch_default_unreachable == 0 || (iVar2 != 0))));
        iVar2 = iVar2 + -1) {
      lo = cases->first;
      hi = cases->first_high;
      if ((lo == cases->last) && (hi == cases->last_high)) {
        uVar1 = selector->type;
        splice_fn = tuple_splice_after;
        pcVar4 = operand_new_intconst(uVar1,lo,hi);
        cond_def = tuple_new_compare(0x17d,uVar1,selector,pcVar4,splice_fn,anchor);
        cond = cond_def->dst;
        pcVar3 = cases->label;
        uVar6 = '\x01';
      }
      else {
        if ((lo == 0 && hi == 0) || ((iVar2 == ncases + -1 && ((lo != 1 || (hi != 0)))))) {
          uVar6 = '\x03';
        }
        else {
          bVar7 = lo == 0;
          lo = lo - 1;
          uVar6 = '\x05';
          hi = hi - (uint)bVar7;
        }
        uVar1 = selector->type;
        splice_fn = tuple_splice_after;
        pcVar4 = operand_new_intconst(uVar1,lo,hi);
        pcVar3 = tuple_new_compare(0x17d,uVar1,selector,pcVar4,splice_fn,anchor);
        pcVar3 = tuple_new_branch(0x185,uVar6,(c2_node *)default_label,pcVar3->dst,pcVar3,
                                  tuple_splice_after,pcVar3);
        uVar5 = cases->last;
        hi_00 = cases->last_high;
        if (((uVar5 & hi_00) == 0xffffffff) && ((selector->type & 0xf000) == 0x1000)) {
          uVar5 = 0;
          hi_00 = 0;
          uVar6 = '\x03';
        }
        else {
          uVar6 = '\x05';
        }
        uVar1 = selector->type;
        splice_fn = tuple_splice_after;
        pcVar4 = operand_new_intconst(uVar1,uVar5,hi_00);
        cond_def = tuple_new_compare(0x17d,uVar1,selector,pcVar4,splice_fn,pcVar3);
        cond = cond_def->dst;
        pcVar3 = cases->label;
      }
      anchor = tuple_new_branch(0x185,uVar6,(c2_node *)pcVar3,cond,cond_def,tuple_splice_after,
                                cond_def);
      cases = cases->next;
    }
    if (g_switch_default_unreachable != 0) {
      default_label = cases->label;
    }
    pcVar3 = tuple_new_branch(0x186,'\0',(c2_node *)default_label,(c2_operand *)0x0,(c2_tuple *)0x0,
                              tuple_splice_after,anchor);
    return pcVar3;
  }
  pcVar3 = tuple_new_switch(0x18d,uVar1,selector,default_label,(c2_switch_case *)0x0,
                            tuple_splice_after,anchor);
  uVar5 = pcVar3->switch_flags & 0xfffffffd;
  pcVar3->switch_flags =
       CONCAT31((int3)(uVar5 >> 8),(byte)((g_switch_default_unreachable & 1U) << 1) | (byte)uVar5) |
       1;
  switch_attach_case_targets(pcVar3,cases,ncases);
  return pcVar3;
}

