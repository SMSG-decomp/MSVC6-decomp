c2_tuple * __fastcall
lower_switch_cases(c2_switch_case_range *cases,c2_tuple *default_label,uint ncases,
                  c2_operand *selector,c2_tuple *anchor)

{
  c2_switch_case_range *pcVar1;
  c2_operand *selector_00;
  c2_tuple *pcVar2;
  int iVar3;
  c2_switch_case_range *pcVar4;
  c2_switch_case_range *pcVar5;
  uint uVar6;
  uint uVar7;
  uint ncases_00;
  bool bVar8;
  uint local_40;
  c2_tuple *local_3c;
  c2_switch_case_range *local_38;
  uint local_34;
  c2_tuple *local_30;
  c2_tuple *local_2c;
  c2_tuple *local_28;
  uint local_24;
  c2_switch_case_range *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  ncases_00 = ncases;
  local_3c = default_label;
  if (ncases == 0) {
    pcVar2 = tuple_new_branch(0x186,'\0',(c2_node *)default_label,(c2_operand *)0x0,(c2_tuple *)0x0,
                              tuple_splice_after,anchor);
    return pcVar2;
  }
  switch_case_stats(cases,ncases,&local_18,&local_10,(int *)&ncases);
  local_1c = switch_narrow_int64_selector_thunk(cases,anchor,ncases_00,default_label);
  if ((g_switch_default_unreachable != 0) &&
     (iVar3 = switch_default_shares_case_target(cases,default_label), iVar3 != 0)) {
    pcVar4 = arena_alloc(4,0x20);
    local_30 = local_3c->next;
    local_2c = local_30->next;
    ncases = ncases - 1;
    pcVar4->last = 0;
    pcVar4->first = 0;
    pcVar4->next = cases;
    pcVar4->last_high = 0;
    pcVar4->first_high = 0;
    pcVar4->label = local_3c;
    tuple_unlink(local_3c->next);
    tuple_unlink(local_3c->next);
    local_38 = pcVar4;
    for (pcVar1 = cases; pcVar1 != (c2_switch_case_range *)0x0; pcVar1 = pcVar1->next) {
      pcVar5 = arena_alloc(4,0x20);
      pcVar4->next = pcVar5;
      pcVar5->last = pcVar1->last;
      pcVar5->last_high = pcVar1->last_high;
      pcVar5->first = pcVar1->first;
      pcVar5->first_high = pcVar1->first_high;
      pcVar5->label = pcVar1->label;
      pcVar4 = pcVar5;
    }
    pcVar4->next = (c2_switch_case_range *)0x0;
    local_34 = switch_prune_and_merge_cases(local_38);
    pcVar2 = local_30;
    if (local_34 == 0) {
      tuple_insert_after(local_3c,local_30);
      tuple_insert_after(pcVar2,local_2c);
      pcVar2 = tuple_new_branch(0x186,'\0',(c2_node *)local_38->label,(c2_operand *)0x0,
                                (c2_tuple *)0x0,tuple_splice_after,anchor);
      return pcVar2;
    }
    switch_case_stats(local_38->next,local_34,&local_14,&local_8,(int *)&local_40);
    uVar6 = g_switch_thresholds[g_opt_favor_speed == 0].min_cases;
    if (ncases < uVar6) {
      if ((uVar6 <= local_40) || (ncases <= local_40)) {
        if ((selector->type & 0xfff) < 5) {
          if (g_opt_favor_speed == 0) {
            if (local_4 == 0) {
              uVar6 = switch_jump_table_size(local_34,local_8);
              uVar7 = switch_compare_chain_size(cases,ncases_00);
              if (uVar6 < uVar7) goto LAB_1074e630;
            }
          }
          else if (((local_4 == 0) && (local_8 < 0xff)) ||
                  ((local_4 == 0 && (local_8 <= local_40 * 4)))) {
            bVar8 = 3 < ncases;
            goto LAB_1074e628;
          }
        }
        goto LAB_1074e5c6;
      }
    }
    else {
      if (uVar6 <= local_40) {
        if ((selector->type & 0xfff) < 5) {
          if (((local_c == 0) && (local_10 < 0xff)) || ((local_c == 0 && (local_10 <= ncases * 4))))
          {
            if (g_opt_favor_speed == 0) {
              uVar6 = local_c - (local_10 < 2);
              if ((local_4 < uVar6) || ((local_4 == uVar6 && (local_8 < local_10 - 2))))
              goto LAB_1074e630;
            }
          }
          else if (((local_4 == 0) && (local_8 < 0xff)) ||
                  (((local_4 == 0 && (local_8 <= local_40 * 4)) || (local_40 < ncases))))
          goto LAB_1074e630;
        }
        else {
          bVar8 = local_40 < ncases;
LAB_1074e628:
          if (bVar8) goto LAB_1074e630;
        }
        goto LAB_1074e5c6;
      }
      if ((selector->type & 0xfff) < 5) {
        if (g_opt_favor_speed == 0) {
          if (local_c == 0) {
            uVar6 = switch_compare_chain_size(local_38->next,local_34);
            uVar7 = switch_jump_table_size(ncases_00,local_10);
            if (uVar6 < uVar7) goto LAB_1074e630;
          }
LAB_1074e5c6:
          pcVar2 = local_30;
          tuple_insert_after(local_3c,local_30);
          tuple_insert_after(pcVar2,local_2c);
          default_label = local_3c;
          goto LAB_1074e3dc;
        }
        if (((local_c == 0) && (local_10 < 0xff)) || ((local_c == 0 && (local_10 <= ncases << 2))))
        {
          bVar8 = local_40 < 2;
          goto LAB_1074e628;
        }
      }
    }
LAB_1074e630:
    ncases_00 = local_34;
    cases = local_38->next;
    ncases = local_40;
    local_10 = local_8;
    g_switch_default_unreachable = 0;
    local_c = local_4;
    node_free((c2_node *)local_30);
    node_free((c2_node *)local_2c);
    default_label = local_3c;
  }
LAB_1074e3dc:
  if (ncases < g_switch_thresholds[g_opt_favor_speed == 0].min_cases) {
    pcVar2 = emit_switch_compare_chain(cases,default_label,ncases_00,selector,anchor);
    return pcVar2;
  }
  if ((selector->type & 0xfff) < 5) {
    if (g_opt_favor_speed == 0) {
      if (local_c == 0) {
        uVar6 = switch_jump_table_size(ncases_00,local_10);
        uVar7 = switch_compare_chain_size(cases,ncases_00);
        if (uVar6 < uVar7) goto LAB_1074e436;
      }
    }
    else {
      if (((local_c == 0) && (local_10 < 0xff)) || ((local_c == 0 && (local_10 <= ncases * 4)))) {
LAB_1074e436:
        pcVar2 = emit_switch_jump_table(cases,default_label,ncases_00,1,0,selector,anchor,local_1c);
        return pcVar2;
      }
    }
  }
  switch_choose_split(cases,local_18,ncases_00,local_10,local_c,&local_20,(int *)&local_24);
  selector_00 = selector;
  pcVar2 = emit_switch_split_compare(local_20,&local_28,selector,anchor);
  pcVar2 = lower_switch_cases(cases,default_label,local_24,selector_00,pcVar2);
  tuple_splice_after(pcVar2,local_28);
  pcVar2 = lower_switch_cases(local_20->next,default_label,(ncases_00 - local_24) - 1,selector_00,
                              local_28);
  return pcVar2;
}

