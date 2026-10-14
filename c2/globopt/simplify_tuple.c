c2_tuple * __fastcall simplify_tuple(c2_tuple *t,c2_block *block,c2_function *fn)

{
  c2_operand *pcVar1;
  bool bVar2;
  uint8_t uVar3;
  ushort uVar4;
  int iVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  c2_tuple *anchor;
  uint32_t uVar8;
  c2_tuple *pcVar9;
  uint uVar10;
  c2_operand *pcVar11;
  c2_switch_case *pcVar12;
  c2_block *to;
  uint16_t uVar13;
  c2_symbol *pcVar14;
  int is_signed;
  uint32_t b_lo;
  uint32_t local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  uint32_t a_lo;
  uint32_t local_4;
  c2_tuple *target;
  
  if ((t->op != 0x18d) && (iVar5 = node_has_side_effects((c2_node *)t), iVar5 != 0)) {
    if (t->op != 0x19e) {
      return t;
    }
    if (t->src->kind != '\a') {
      return t;
    }
    tuple_delete(t);
    return (c2_tuple *)0x0;
  }
  pcVar6 = fold_integer_constants(t,t->type,t->src,t->src->next);
  if ((pcVar6 != (c2_operand *)0x0) ||
     (pcVar6 = fold_float_constants(t,t->type,t->src,t->src->next), pcVar6 != (c2_operand *)0x0)) {
    pcVar11 = t->src->next;
    if (pcVar11 != (c2_operand *)0x0) {
      tuple_remove_src(t,pcVar11);
    }
    if (pcVar6 != t->src) {
      tuple_replace_src(t,t->src,pcVar6);
    }
    t->op = 0x15b;
    return t;
  }
  if ((((1 << (byte)(t->type >> 0xc) & 0xeU) == 0) && (t->op != 0x15f)) && (t->op != 0x17d)) {
    return t;
  }
  pcVar6 = t->src;
  uVar8 = t->op;
  pcVar11 = pcVar6->next;
  local_10 = pcVar11;
  local_c = pcVar6;
  if (uVar8 == 0x16d) {
    if (pcVar6->kind == '\a') {
      tuple_swap_first_srcs(t);
      pcVar6 = t->src;
      pcVar11 = pcVar6->next;
    }
    local_10 = pcVar11;
    local_c = pcVar6;
    if (pcVar6->kind == '\x03') {
      if (pcVar11->kind != '\a') goto LAB_1070cbca;
      if (g_opt_dlp == 0) {
        if (-1 < (int)&((pcVar11->u18).reg)->fe + pcVar6->sym->offset) {
          pcVar7 = symbol_get_part(pcVar6->sym,0x5000,0,(int32_t)(pcVar11->u18).reg);
          pcVar6->sym = pcVar7;
          goto LAB_1070cc83;
        }
      }
    }
    if (((pcVar11->kind == '\a') && ((pcVar11->u18).reg == (c2_symbol *)0x0 && pcVar11->tag == 0))
       && ((g_opt_dlp == 0 || (pcVar6->kind != '\x03')))) {
LAB_1070cc83:
      if (pcVar11 != (c2_operand *)0x0) {
        tuple_remove_src(t,pcVar11);
      }
      pcVar6 = t->src;
      t->op = 0x15b;
      pcVar6->type = t->type;
      pcVar11 = t->src;
      if (pcVar11->kind == '\a') {
        constant_convert(CONCAT22((short)((uint)pcVar6 >> 0x10),pcVar11->type),pcVar11);
      }
      if (g_opt_dlp == 0) {
        return t;
      }
      if ((1 << (t->dst->kind & 0x1f) & 6U) == 0) {
        return t;
      }
      if (t->dst->sym->def == (c2_tuple *)0x0) {
        return t;
      }
      if (t->src->kind != '\x03') {
        return t;
      }
      t->op = 0x169;
      return t;
    }
  }
  else if (uVar8 == 0x16f) {
    if (pcVar6->kind == '\a') {
      tuple_swap_first_srcs(t);
      pcVar6 = t->src;
      pcVar11 = pcVar6->next;
    }
    local_10 = pcVar11;
    local_c = pcVar6;
    if (pcVar11->kind == '\a') {
      if ((pcVar11->u18).reg == (c2_symbol *)0x0 && pcVar11->tag == 0) {
        tuple_swap_first_srcs(t);
        pcVar11 = t->src->next;
        goto LAB_1070cc83;
      }
      if (((pcVar11->u18).reg == (c2_symbol *)0x1) && (pcVar11->tag == 0)) goto LAB_1070cc83;
    }
  }
  else if ((uVar8 == 0x15b) && (iVar5 = operand_compare(t->dst,pcVar6), iVar5 == 0)) {
    tuple_delete(t);
    return (c2_tuple *)0x0;
  }
LAB_1070cbca:
  if (t->op != 0x17d) goto LAB_1070cbd7;
  pcVar6 = t->src;
  bVar2 = false;
  pcVar11 = pcVar6->next;
  iVar5 = operand_compare(pcVar6,pcVar11);
  if (iVar5 == 0) {
    uVar4 = t->type & 0xf000;
    local_4 = 0;
    uVar8 = 1;
    b_lo = 1;
    local_14 = 0;
    if (uVar4 == 0x4000) {
      is_signed = 1;
      bVar2 = true;
    }
    else {
      is_signed = (int)(uVar4 == 0x1000);
      bVar2 = true;
    }
    goto switchD_1070ce04_default;
  }
  if ((pcVar6->kind != '\t') || (pcVar11->kind != '\t')) {
switchD_1079036a_default:
    pcVar1 = t->src;
    if ((pcVar1->kind == '\x03') && (pcVar1->next->kind == '\x03')) {
      if (pcVar1->sym->storage == pcVar1->next->sym->storage) {
        is_signed = 0;
        compare_consumer_condition(t);
        bVar2 = true;
        uVar8 = t->src->sym->offset;
        local_4 = (int)uVar8 >> 0x1f;
        b_lo = t->src->next->sym->offset;
        local_14 = (int)b_lo >> 0x1f;
      }
      else {
        is_signed = 0;
        compare_consumer_condition(t);
        local_4 = 0;
        bVar2 = true;
        b_lo = 1;
        local_14 = 0;
        uVar8 = 0;
      }
    }
    else {
      b_lo = a_lo;
      local_14 = local_4;
      uVar8 = a_lo;
      if ((t->type & 0xf000) == 0x2000) {
        is_signed = 0;
        uVar3 = compare_consumer_condition(t);
        b_lo = a_lo;
        local_14 = local_4;
        uVar8 = a_lo;
        switch(uVar3) {
        case '\x03':
          if (pcVar11->kind == '\a') {
            uVar10 = (pcVar11->u18).lo | pcVar11->tag;
LAB_1070ce20:
            if (uVar10 == 0) {
              local_4 = 0;
              bVar2 = true;
              b_lo = 0;
              local_14 = 0;
              uVar8 = 1;
            }
          }
          break;
        case '\x04':
          if (pcVar6->kind == '\a') {
            uVar10 = (pcVar6->u18).lo | pcVar6->tag;
LAB_1070ce66:
            if (uVar10 == 0) {
              local_4 = 0;
              bVar2 = true;
              b_lo = 1;
              local_14 = 0;
              uVar8 = 0;
            }
          }
          break;
        case '\x05':
          if (pcVar6->kind == '\a') {
            uVar10 = (pcVar6->u18).lo | pcVar6->tag;
            goto LAB_1070ce66;
          }
          break;
        case '\x06':
          if (pcVar11->kind == '\a') {
            uVar10 = (pcVar11->u18).lo | pcVar11->tag;
            goto LAB_1070ce20;
          }
        }
      }
    }
    goto switchD_1070ce04_default;
  }
  uVar3 = compare_consumer_condition(t);
  is_signed = 0;
  switch(uVar3) {
  case '\x01':
    uVar8 = float_const_compare_mask(1,(c2_float_const *)pcVar6->sym,(c2_float_const *)pcVar11->sym)
    ;
    local_4 = (int)uVar8 >> 0x1f;
    bVar2 = true;
    b_lo = 1;
    local_14 = 0;
    break;
  case '\x02':
    uVar8 = float_const_compare_mask(1,(c2_float_const *)pcVar6->sym,(c2_float_const *)pcVar11->sym)
    ;
    local_4 = (int)uVar8 >> 0x1f;
    bVar2 = true;
    b_lo = 1;
    local_14 = 0;
    break;
  case '\x03':
    pcVar7 = pcVar11->sym;
    pcVar14 = pcVar6->sym;
    uVar13 = 4;
    goto LAB_107903cd;
  case '\x04':
    pcVar7 = pcVar11->sym;
    pcVar14 = pcVar6->sym;
    uVar13 = 2;
    goto LAB_1079037b;
  case '\x05':
    pcVar7 = pcVar11->sym;
    pcVar14 = pcVar6->sym;
    uVar13 = 5;
LAB_107903cd:
    b_lo = float_const_compare_mask(uVar13,(c2_float_const *)pcVar14,(c2_float_const *)pcVar7);
    local_14 = (int)b_lo >> 0x1f;
    if (b_lo == 0) {
      bVar2 = true;
      local_4 = 0;
      uVar8 = 1;
    }
    else {
      bVar2 = true;
      local_4 = 0;
      uVar8 = 0;
    }
    break;
  case '\x06':
    pcVar7 = pcVar11->sym;
    pcVar14 = pcVar6->sym;
    uVar13 = 3;
LAB_1079037b:
    uVar8 = float_const_compare_mask(uVar13,(c2_float_const *)pcVar14,(c2_float_const *)pcVar7);
    local_4 = (int)uVar8 >> 0x1f;
    if (uVar8 == 0) {
      bVar2 = true;
      b_lo = 1;
      local_14 = 0;
    }
    else {
      bVar2 = true;
      b_lo = 0;
      local_14 = 0;
    }
    break;
  default:
    goto switchD_1079036a_default;
  }
switchD_1070ce04_default:
  pcVar11 = local_10;
  pcVar6 = local_c;
  if (bVar2) {
LAB_1070ceee:
    anchor = find_next_use_of_dst(t,&local_10);
    if (anchor->kind == '\x10') {
      iVar5 = fold_constant_compare
                        (is_signed,t->type & 0xfff,uVar8,local_4,b_lo,local_14,(anchor->u20).cc);
      if (iVar5 == 0) {
        pcVar6 = anchor->src->next->next;
      }
      else {
        pcVar6 = anchor->src->next;
      }
      pcVar9 = tuple_new(0x15b,anchor->type,anchor->dst,pcVar6,tuple_insert_after,anchor);
      if (((1 << (pcVar9->dst->kind & 0x1f) & 6U) != 0) &&
         (pcVar7 = pcVar9->dst->sym, pcVar7->def != (c2_tuple *)0x0)) {
        if (pcVar7->storage->part_next == (c2_symbol *)0x0) {
          pcVar7->def = pcVar9;
        }
        else {
          symbol_mark_overlapping_parts(pcVar7,pcVar9);
        }
      }
      tuple_delete(t);
      tuple_delete(anchor);
      g_next_tuple_cursor = pcVar9->next;
      return pcVar9;
    }
    if (g_fold_flag_f120 == 0) {
      return t;
    }
    uVar3 = (uint8_t)anchor->type;
    local_c = (c2_operand *)CONCAT31(local_c._1_3_,uVar3);
    iVar5 = fold_constant_compare(is_signed,t->type & 0xfff,uVar8,local_4,b_lo,local_14,uVar3);
    node_list_remove_rank(anchor,(int)t);
    tuple_delete(t);
    if (iVar5 == 0) {
      pcVar9 = *(c2_tuple **)((int)&anchor->src->sym->u30 + 2);
      to = (pcVar9->u14).block;
      if (to == (c2_block *)0x0) {
        pcVar9 = tuple_find_prev_of_kind(pcVar9,'\x19');
        to = (pcVar9->u14).block;
      }
      if (g_next_tuple_cursor == anchor) {
        g_next_tuple_cursor = anchor->next;
      }
      tuple_delete(anchor);
    }
    else {
      to = block->next;
      anchor->op = 0x186;
      tuple_remove_src(anchor,local_10);
      *(undefined1 *)&anchor->type = 0;
    }
    remove_loop_back_edge(block,to,fn);
    return (c2_tuple *)0x0;
  }
LAB_1070cbd7:
  if (pcVar6->kind != '\a') {
    return t;
  }
  local_14 = 0;
  if ((pcVar11 != (c2_operand *)0x0) && (pcVar11->kind != '\a')) {
    return t;
  }
  uVar8 = (pcVar6->u18).lo;
  local_4 = pcVar6->tag;
  if (pcVar11 == (c2_operand *)0x0) {
    b_lo = 0;
  }
  else {
    b_lo = (pcVar11->u18).lo;
    local_14 = pcVar11->tag;
  }
  is_signed = (int)((t->type & 0xf000) == 0x1000);
  a_lo = uVar8;
  if (t->op == 0x17d) goto LAB_1070ceee;
  if (t->op != 0x18d) {
    return t;
  }
  pcVar12 = (t->u24).cases;
  local_c = (c2_operand *)0x0;
  if (pcVar12 != (c2_switch_case *)0x0) {
    do {
      local_10 = (c2_operand *)(t->type & 0xfff);
      iVar5 = fold_constant_compare
                        (is_signed,(int)local_10,pcVar12->lo,pcVar12->lo >> 0x1f,uVar8,local_4,
                         '\x05');
      uVar8 = a_lo;
      if ((iVar5 == 0) ||
         (iVar5 = fold_constant_compare
                            (is_signed,t->type & 0xfff,a_lo,local_4,pcVar12->hi,pcVar12->hi >> 0x1f,
                             '\x05'), pcVar6 = (c2_operand *)pcVar12, iVar5 == 0)) {
        remove_loop_back_edge(block,(pcVar12->label->u14).block,fn);
        pcVar6 = local_c;
      }
      local_c = pcVar6;
      pcVar12 = pcVar12->next;
    } while (pcVar12 != (c2_switch_case *)0x0);
    if (local_c != (c2_operand *)0x0) {
      target = (c2_tuple *)local_c->sym;
      remove_loop_back_edge(block,(((t->u20).default_label)->u14).block,fn);
      goto LAB_1079056d;
    }
  }
  target = (t->u20).default_label;
LAB_1079056d:
  tuple_new_branch(0x186,'\0',(c2_node *)target,(c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after
                   ,t);
  switch_free(t);
  return (c2_tuple *)0x0;
}

