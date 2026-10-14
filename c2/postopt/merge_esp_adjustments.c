void __fastcall merge_esp_adjustments(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  int adjust;
  int net_adjust;
  c2_operand *pcVar5;
  uint uVar6;
  c2_operand *base;
  c2_tuple *pcVar7;
  c2_tuple *t;
  c2_operand *index;
  c2_operand *src;
  c2_tuple *anchor;
  int pushed_bytes;
  uint pending_is_4;
  c2_insert_fn *insert_fn;
  
  if (g_opt_global != 0) {
    pcVar2 = fn->cfg->last->end;
    t = (c2_tuple *)0x0;
    pcVar3 = fn->cfg->first->head->next;
joined_r0x107387af:
    while (pcVar7 = pcVar3, pcVar7 != pcVar2) {
      pcVar3 = pcVar7->next;
      if (((pcVar7->kind == 0x1a) || ((1 << (pcVar7->kind & 0x1f) & 0xa0000U) != 0)) ||
         (net_adjust = pcVar7->op, net_adjust == 0x1b4)) goto LAB_107389db;
      if (((net_adjust != 0x2d) && (net_adjust != 0x32)) ||
         ((pcVar5 = pcVar7->src, pcVar5->kind != '\x01' ||
          (((pcVar5->u18).reg != g_reg_symbols + 5 || (pcVar5->next->kind != '\a'))))))
      goto LAB_10738841;
      if ((t != (c2_tuple *)0x0) && (pushed_bytes == 0)) {
        uVar4 = (t->src->next->u18).lo;
        if (t->op == 0x32) {
          uVar4 = -uVar4;
        }
        adjust = (pcVar5->next->u18).lo;
        if (net_adjust == 0x32) {
          adjust = -adjust;
        }
        uVar4 = adjust + uVar4;
        tuple_unlink_free(t);
        if ((int)uVar4 < 1) {
          if ((int)uVar4 < 0) {
            pcVar7->op = 0x32;
            net_adjust = -uVar4;
            goto LAB_107387f9;
          }
        }
        else {
          pcVar7->op = 0x2d;
          net_adjust = uVar4;
LAB_107387f9:
          pcVar5 = pcVar7->src->next;
          (pcVar5->u18).lo = net_adjust;
          pcVar5->tag = net_adjust >> 0x1f;
        }
        if (uVar4 != 0) {
          if (0x3f < (int)uVar4) goto LAB_107389db;
          goto LAB_107388bd;
        }
        goto LAB_1077d1a1;
      }
      pushed_bytes = 0;
LAB_107388bd:
      net_adjust = (pcVar7->src->next->u18).lo;
      if (pcVar7->op == 0x32) {
        net_adjust = -net_adjust;
      }
      pending_is_4 = (uint)(net_adjust == 4);
      t = pcVar7;
    }
  }
  return;
LAB_10738841:
  if ((t == (c2_tuple *)0x0) || ((pcVar7->flags & 1) == 0)) goto joined_r0x107387af;
  net_adjust = (t->src->next->u18).lo;
  if (t->op == 0x32) {
    net_adjust = -net_adjust;
  }
  pcVar5 = find_dst_clobbering_reg(pcVar7,g_reg_symbols + 5);
  if (pcVar5 != (c2_operand *)0x0) {
    if (pcVar7->op != 0xd) {
      t = (c2_tuple *)0x0;
      goto LAB_1073892c;
    }
    if ((pending_is_4 != 0) && (g_opt_favor_speed == 0)) {
      pcVar5 = pcVar7->src;
      uVar6 = 1 << (pcVar5->kind & 0x1f);
      if ((((uVar6 & 0x18) != 0) || ((uVar6 & 0x7e) == 0)) &&
         ((pcVar5->kind != 7 || (0xff < (int)(pcVar5->u18).reg)))) {
        uVar1 = pcVar7->line;
        if (uVar1 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
        insert_fn = tuple_insert_before;
        net_adjust = 2;
        index = (c2_operand *)0x0;
        src = pcVar5;
        anchor = pcVar7;
        base = operand_new_hardreg(5,0x1004);
        pcVar5 = operand_new_mem(0x14c,pcVar5->type,(c2_symbol *)0x0,0,base,index,net_adjust);
        tuple_new(1,pcVar7->type,pcVar5,src,insert_fn,anchor);
        tuple_remove_src(pcVar7,pcVar7->src);
        tuple_unlink_free(pcVar7);
        pcVar7 = t;
LAB_1077d1a1:
        tuple_unlink_free(pcVar7);
        goto LAB_107389db;
      }
    }
    pending_is_4 = 0;
    pushed_bytes = pushed_bytes + (pcVar7->type & 0xfff);
  }
  pcVar5 = find_src_overlapping_reg(pcVar7,g_reg_symbols + 5);
  if (pcVar5 != (c2_operand *)0x0) {
    if (pcVar7->kind == '\x0e') {
      if ((pcVar7->u24).call.conv == '\0') {
        uVar1 = pcVar3->type;
        pcVar7 = pcVar3;
        while ((uVar1 & 0xf000) == 0x4000) {
          pcVar7 = pcVar7->next;
          uVar1 = pcVar7->type;
        }
        if ((((pcVar7->op == 0x2d) && (pcVar5 = pcVar7->src, pcVar5->kind == '\x01')) &&
            ((pcVar5->u18).reg == g_reg_symbols + 5)) && (pcVar5->next->kind == '\a')) {
          if ((pcVar5->next->u18).reg == (c2_symbol *)pushed_bytes) {
            pushed_bytes = 0;
            goto joined_r0x107387af;
          }
        }
        else if (pushed_bytes == 0) goto joined_r0x107387af;
      }
      else if ((c2_cond_cell *)pushed_bytes == (pcVar7->u20).cond_cells) {
        pushed_bytes = 0;
        goto joined_r0x107387af;
      }
    }
    else if (pcVar7->op == 0xd) goto joined_r0x107387af;
LAB_107389db:
    t = (c2_tuple *)0x0;
    goto joined_r0x107387af;
  }
LAB_1073892c:
  if (net_adjust < 0) {
    for (pcVar5 = pcVar7->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
      if ((pcVar5->op == 0x14a) || (pcVar5->op == 0x14e)) {
        t = (c2_tuple *)0x0;
        break;
      }
    }
    for (pcVar5 = pcVar7->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
      if ((pcVar5->op == 0x14a) || (pcVar5->op == 0x14e)) goto LAB_107389db;
    }
  }
  goto joined_r0x107387af;
}

