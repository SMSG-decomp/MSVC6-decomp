void __fastcall generate_prolog_epilog(c2_function *fn)

{
  ushort uVar1;
  uint uVar2;
  c2_function *pcVar3;
  c2_tuple *cursor;
  c2_const_operand *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  uint8_t *puVar7;
  c2_fe_symbol *pcVar8;
  c2_operand *pcVar9;
  byte bVar10;
  char *name;
  uint16_t type;
  uint32_t frame_bytes;
  int iVar11;
  bool aligned_frame;
  uint8_t uVar12;
  uint32_t uVar13;
  code *pcVar14;
  uint32_t shrink_wrapped_mask;
  int pushed_bytes;
  int framed;
  int ebp_bias;
  c2_insert_fn *insert_fn;
  
  iVar11 = 0;
  shrink_wrapped_mask = 0;
  ebp_bias = fn->x28;
  framed = 0;
  g_chkstk_call_tuple = (c2_tuple *)0x0;
  g_eh_prolog_call_tuple = (c2_tuple *)0x0;
  if ((g_cur_func_sym->attrs & 0x400) != 0) {
    g_chkstk_call_tuple = (c2_tuple *)0x0;
    g_eh_prolog_call_tuple = (c2_tuple *)0x0;
    return;
  }
  uVar2 = fn->flags;
  if (((((uVar2 & 0x10) == 0) && (ebp_bias < 1)) && (g_opt_global != 0)) && ((uVar2 & 1) != 0)) {
    iVar11 = function_references_ebp(fn->cfg->first->head);
  }
  cursor = find_tuple_of_kind(fn->cfg->first->head,'\x17');
  pcVar8 = g_cur_func_sym;
  uVar1 = cursor->line;
  if (uVar1 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar1;
    g_cur_line = uVar1;
  }
  if (((uVar2 & 0x600000) != 0) && (g_cur_func_sym->frame_size == 0)) {
    bVar10 = g_reg_symbols[6].flags5 & 0x10;
    fn->flags = uVar2 & 0xff9fffff;
    if (bVar10 == 0) {
      fn->flags = uVar2 & 0xff9fffff | 0x10;
    }
  }
  uVar2 = fn->flags;
  aligned_frame = (uVar2 & 0x600000) != 0;
  if (((g_opt_global == 0) || (iVar11 != 0)) ||
     ((((uVar2 & 0x10) == 0 || (aligned_frame)) &&
      ((((pcVar8->frame_size != 0 || ((uVar2 & 0xc0) != 0)) || ((uVar2 & 0x100000) != 0)) ||
       ((iVar11._0_1_ = pcVar8->level, iVar11._1_1_ = pcVar8->combine, iVar11._2_2_ = pcVar8->u44,
        iVar11 != 0 && (iVar11 = function_references_ebp(cursor), iVar11 != 0)))))))) {
    framed = 1;
    if (aligned_frame) {
      g_opt_qif = 0;
    }
    if ((g_opt_favor_speed != 0) || ((g_cur_function->flags & 0x18000) == 0)) {
      cursor = insert_push_reg(6,cursor);
      iVar11 = ebp_bias;
      pcVar14 = tuple_insert_after;
      if (ebp_bias < 1) {
        pcVar5 = operand_new_hardreg(5,0x1004);
        pcVar6 = operand_new_hardreg(6,0x1004);
        uVar13 = 1;
      }
      else {
        pcVar6 = (c2_operand *)0x0;
        pcVar5 = operand_new_hardreg(5,0x1004);
        pcVar5 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,-iVar11,pcVar5,pcVar6);
        pcVar6 = operand_new_hardreg(6,0x1004);
        uVar13 = 0x12;
      }
      cursor = tuple_new(uVar13,0x1004,pcVar6,pcVar5,pcVar14,cursor);
    }
    if (aligned_frame) {
      pcVar14 = tuple_insert_after;
      pcVar4 = operand_new_intconst(0x1004,0xfffffff8,0);
      pcVar5 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      cursor = tuple_new_binary(0x2e,0x1004,pcVar6,pcVar5,pcVar4,pcVar14,cursor);
      pcVar5 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(cursor,pcVar5);
    }
  }
  else {
    fn->flags = uVar2 | 0x100;
  }
  pcVar3 = g_cur_function;
  fn->flags = (g_reg_symbols[6].flags5 & 0x10) << 1 | fn->flags & 0xffffffdf;
  if ((pcVar3->fsym->attrs & 0x1000) != 0) {
    cursor = seh_emit_prolog(cursor,1);
  }
  if ((g_cur_function->flags & 0x18000) != 0) {
    cursor = cxx_eh_emit_prolog(cursor,1);
  }
  frame_bytes = g_cur_func_sym->frame_size;
  if (g_eh_record_pushed != 0) {
    frame_bytes = frame_bytes - g_frame_eh_record->size;
  }
  if (frame_bytes != 0) {
    if ((g_force_stack_probe == 0) && (frame_bytes < (uint)g_opt_stack_probe_size)) {
      if (aligned_frame) {
        pushed_bytes = 0;
        bVar10 = 4;
        puVar7 = &g_reg_symbols[4].flags5;
        do {
          if (((g_callee_saved_mask & 1 << (bVar10 & 0x1f)) != 0) && ((*puVar7 & 0x10) != 0)) {
            pushed_bytes = pushed_bytes + 4;
          }
          puVar7 = puVar7 + 0x54;
          bVar10 = bVar10 + 1;
        } while ((int)puVar7 < 0x107ac9d6);
        if ((pushed_bytes + frame_bytes & 7) != 0) {
          frame_bytes = frame_bytes + 4;
        }
      }
      pcVar14 = tuple_insert_after;
      pcVar4 = operand_new_intconst(0x1004,frame_bytes,0);
      pcVar5 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      cursor = tuple_new_binary(0x32,0x1004,pcVar6,pcVar5,pcVar4,pcVar14,cursor);
      pcVar5 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(cursor,pcVar5);
    }
    else {
      pcVar14 = tuple_insert_after;
      pcVar4 = operand_new_intconst(0x1004,frame_bytes,0);
      pcVar5 = operand_new_hardreg(1,0x1004);
      cursor = tuple_new(1,0x1004,pcVar5,pcVar4,pcVar14,cursor);
      name = "__chkstk";
      if (g_opt_basic != 0) {
        name = "___vbaChkstk";
      }
      pcVar14 = tuple_insert_after;
      uVar12 = '\x04';
      pcVar8 = fe_symbol_lookup_name(name);
      pcVar5 = operand_new_codeaddr(0x153,pcVar8);
      pcVar6 = operand_new_hardreg(1,0x1004);
      cursor = tuple_new_call(0xe,0x1004,pcVar6,pcVar5,uVar12,pcVar14,cursor);
      pcVar5 = operand_new_hardreg(1,0x1004);
      tuple_append_src(cursor,pcVar5);
      pcVar5 = operand_new_hardreg(5,0x1004);
      tuple_append_src(cursor,pcVar5);
      pcVar5 = operand_new_hardreg(5,0x1004);
      tuple_append_dst(cursor,pcVar5);
      pcVar5 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(cursor,pcVar5);
      g_chkstk_call_tuple = cursor;
    }
  }
  if ((((fn->fsym->attrs & 0x1000) != 0) || ((fn->flags & 0x10000) != 0)) ||
     (g_opt_edit_and_continue != 0)) {
    g_reg_symbols[4].flags5 = g_reg_symbols[4].flags5 | 0x10;
    g_reg_symbols[7].flags5 = g_reg_symbols[7].flags5 | 0x10;
    g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 | 0x10;
  }
  if (g_opt_runtime_checks != 0) {
    if (g_opt_global != 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x612);
    }
    if ((g_opt_runtime_checks != 0) && (frame_bytes != 0)) {
      if (g_eh_record_pushed == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = g_frame_eh_record->size;
      }
      emit_gz_stack_fill(fn,cursor,frame_bytes,-(uVar13 + frame_bytes));
    }
  }
  if (((g_opt_global == 0) || (aligned_frame)) ||
     (((fn->fsym->attrs & 0x1000) != 0 ||
      (((fn->flags & 0x10000) != 0 || ((fn->flags & 0xc0) != 0)))))) {
    shrink_wrapped_mask = 0;
  }
  else {
    cursor = shrink_wrap_callee_saves(fn,cursor,&shrink_wrapped_mask);
  }
  cursor = emit_callee_saved_pushes(fn,cursor,shrink_wrapped_mask);
  if ((g_cur_function->fsym->attrs & 0x1000) != 0) {
    seh_emit_prolog(cursor,0);
  }
  if ((g_cur_function->flags & 0x18000) != 0) {
    cxx_eh_emit_prolog(cursor,0);
  }
  if (g_eh_record_pushed != 0) {
    frame_bytes = frame_bytes + g_frame_eh_record->size;
  }
  cursor = tuple_find_prev_of_kind(fn->cfg->last->end,'\x18');
  uVar1 = cursor->line;
  if (uVar1 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar1;
    g_cur_line = uVar1;
  }
  cursor = cursor->prev;
  if ((fn->flags & 0x80) != 0) {
    pcVar6 = (c2_operand *)0x0;
    pcVar5 = operand_new_hardreg(6,0x1004);
    pcVar5 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,
                              fn->callee_save_pushes * -4 - frame_bytes,pcVar5,pcVar6);
    pcVar14 = tuple_insert_after;
    pcVar6 = operand_new_hardreg(5,0x1004);
    cursor = tuple_new(0x12,0x1004,pcVar6,pcVar5,pcVar14,cursor);
    fn->x3c = frame_bytes;
    fn->x38 = (uint32_t)cursor;
  }
  if ((g_cur_function->fsym->attrs & 0x1000) != 0) {
    cursor = seh_emit_epilog(cursor);
  }
  if ((g_cur_function->flags & 0x18000) != 0) {
    cursor = cxx_eh_emit_epilog(cursor);
  }
  cursor = emit_callee_saved_pops(fn,cursor,shrink_wrapped_mask);
  if (((g_opt_runtime_checks != 0) && (uVar2 = fn->flags, (uVar2 & 0xc0) == 0)) &&
     (((uVar2 & 0x200) != 0 || ((uVar2 & 1) != 0)))) {
    if (frame_bytes != 0) {
      pcVar14 = tuple_insert_after;
      pcVar4 = operand_new_intconst(0x1004,fn->fsym->frame_size,0);
      pcVar5 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      cursor = tuple_new_binary(0x2d,0x1004,pcVar6,pcVar5,pcVar4,pcVar14,cursor);
      pcVar5 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(cursor,pcVar5);
    }
    pcVar14 = tuple_insert_after;
    pcVar5 = operand_new_hardreg(5,0x1004);
    pcVar6 = operand_new_hardreg(6,0x1004);
    cursor = tuple_new_compare(0x17d,0x1004,pcVar6,pcVar5,pcVar14,cursor);
    pcVar14 = tuple_insert_after;
    uVar12 = '\x04';
    cursor->op = 0x2f;
    (cursor->dst->u18).reg = g_reg_symbols + 0x42;
    pcVar8 = fe_symbol_lookup_name("__chkesp");
    pcVar5 = operand_new_codeaddr(0x153,pcVar8);
    cursor = tuple_new_call(0xe,0x1004,(c2_operand *)0x0,pcVar5,uVar12,pcVar14,cursor);
    tuple_append_src(cursor,cursor->prev->dst);
    pcVar5 = operand_new_hardreg(5,0x1004);
    tuple_append_src(cursor,pcVar5);
    pcVar5 = operand_new_hardreg(0x42,0x8000);
    tuple_append_dst(cursor,pcVar5);
  }
  if (framed == 0) {
    if ((g_opt_favor_speed == 0) && ((g_cur_function->flags & 0x18000) != 0)) {
      insert_fn = tuple_insert_after;
      pcVar5 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(6,0x1004);
      pcVar9 = operand_new_hardreg(5,0x1004);
      cursor = tuple_new_binary(0xa7,0x1004,pcVar9,pcVar6,pcVar5,insert_fn,cursor);
      pcVar5 = operand_new_hardreg(6,0x1004);
      tuple_append_dst(cursor,pcVar5);
      g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 | 0x10;
      fn->flags = fn->flags | 0x20;
      goto LAB_107369c4;
    }
    if (frame_bytes == 0) goto LAB_107369c4;
    insert_fn = tuple_insert_after;
    pcVar4 = operand_new_intconst(0x1004,frame_bytes,0);
    pcVar5 = operand_new_hardreg(5,0x1004);
    pcVar6 = operand_new_hardreg(5,0x1004);
    cursor = tuple_new_binary(0x2d,0x1004,pcVar6,pcVar5,pcVar4,insert_fn,cursor);
    type = 0x8000;
    iVar11 = 0x42;
  }
  else {
    if (0 < ebp_bias) {
      insert_fn = tuple_insert_after;
      pcVar4 = operand_new_intconst(0x1004,ebp_bias,ebp_bias >> 0x1f);
      pcVar5 = operand_new_hardreg(6,0x1004);
      pcVar6 = operand_new_hardreg(6,0x1004);
      cursor = tuple_new_binary(0x2d,0x1004,pcVar6,pcVar5,pcVar4,insert_fn,cursor);
      pcVar5 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(cursor,pcVar5);
    }
    if (frame_bytes == 0) {
      cursor = insert_pop_reg(6,cursor);
      goto LAB_107369c4;
    }
    insert_fn = tuple_insert_after;
    if (g_opt_favor_speed != 0) {
      pcVar5 = operand_new_hardreg(6,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      cursor = tuple_new(1,0x1004,pcVar6,pcVar5,insert_fn,cursor);
      cursor = insert_pop_reg(6,cursor);
      goto LAB_107369c4;
    }
    pcVar5 = operand_new_hardreg(5,0x1004);
    pcVar6 = operand_new_hardreg(6,0x1004);
    pcVar9 = operand_new_hardreg(5,0x1004);
    cursor = tuple_new_binary(0xa7,0x1004,pcVar9,pcVar6,pcVar5,insert_fn,cursor);
    type = 0x1004;
    iVar11 = 6;
  }
  pcVar5 = operand_new_hardreg(iVar11,type);
  tuple_append_dst(cursor,pcVar5);
LAB_107369c4:
  if ((g_cur_func_sym->attrs & 0x1c) == 0) {
    uVar13 = 0;
  }
  else {
    uVar13._0_1_ = g_cur_func_sym->level;
    uVar13._1_1_ = g_cur_func_sym->combine;
    uVar13._2_2_ = g_cur_func_sym->u44;
  }
  pcVar4 = operand_new_intconst(0x1004,uVar13,0);
  cursor = tuple_new_exit(8,0x1004,(c2_operand *)0x0,pcVar4,tuple_insert_after,cursor);
  pcVar5 = operand_new_hardreg(0x42,0x8000);
  tuple_append_dst(cursor,pcVar5);
  return;
}

