c2_tuple * __fastcall lower_x87_tuple(c2_tuple *t)

{
  byte bVar1;
  ushort uVar2;
  uint il_op;
  int iVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_symbol *pcVar7;
  c2_const_operand *pcVar8;
  c2_fe_symbol *fs;
  c2_symbol *pcVar9;
  c2_tuple *pcVar10;
  c2_operand *pcVar11;
  c2_operand *dst;
  c2_operand *pcVar12;
  uint16_t uVar13;
  ushort uVar14;
  ushort uVar15;
  bool bVar16;
  longlong lVar17;
  code *pcVar18;
  c2_operand *local_18;
  c2_operand *local_14;
  int local_c;
  c2_symbol *local_4;
  c2_insert_fn *insert_fn;
  
  pcVar10 = t;
  if ((g_opt_favor_speed != 0) && (iVar3 = lower_float_move_as_integer(t), iVar3 != 0)) {
    return t;
  }
  iVar3 = tuple_is_commutative(t);
  if (((iVar3 != 0) && (pcVar5 = t->src, (1 << (pcVar5->kind & 0x1f) & 0x60U) != 0)) &&
     ((1 << (pcVar5->next->kind & 0x1f) & 0x1eU) != 0)) {
    tuple_detach_src((c2_node *)t,pcVar5);
    tuple_append_src(t,pcVar5);
  }
  iVar3 = g_fp_lower_depth;
  il_op = t->op;
  switch(il_op) {
  case 0x15a:
    pcVar5 = t->src;
    if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
       (pcVar5->sym->def != (c2_tuple *)0x0)) {
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
    }
    else {
      emit_x87_load_operand(t);
    }
    pcVar6 = find_next_use_of_dst(t,&local_14);
    iVar3 = g_fp_lower_depth;
    if (pcVar6->op != 400) {
      if (((pcVar6->u24).call.conv == '\x18') && (local_14 == pcVar6->src->next)) {
        tuple_replace_src(pcVar6,local_14,t->src);
        t->op = 0x145;
        g_fp_lower_depth = g_fp_lower_depth + -1;
        return pcVar10;
      }
      pcVar18 = tuple_insert_before;
      pcVar6 = t;
      pcVar8 = operand_new_intconst(0x1004,t->type & 0xfff,0);
      pcVar5 = operand_new_hardreg(5,0x1004);
      pcVar6 = tuple_new_binary_temp(0x32,0x1004,pcVar5,pcVar8,pcVar18,pcVar6);
      uVar13 = t->type;
      local_14 = operand_new_mem(0x14c,uVar13,(c2_symbol *)0x0,0,pcVar6->dst,(c2_operand *)0x0,2);
      tuple_new(99,uVar13,local_14,t->src,tuple_insert_after,pcVar6);
      pcVar5 = pcVar6->dst;
      (local_14->base->u18).reg = g_reg_symbols + 5;
      (pcVar5->u18).reg = g_reg_symbols + 5;
      g_fp_lower_depth = g_fp_lower_depth + -1;
      return pcVar10;
    }
    pcVar5 = t->src;
    t->op = 0x145;
    (pcVar5->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[iVar3] = pcVar5->sym;
    local_14->sym = pcVar5->sym;
    return pcVar10;
  case 0x15b:
    if (((t->dst->kind != '\x01') || (pcVar7 = t->dst->sym, pcVar7->cls != '\x03')) ||
       (pcVar7->def == (c2_tuple *)0x0)) {
      pcVar5 = t->src;
      t->op = 99;
      if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
         (pcVar5->sym->def != (c2_tuple *)0x0)) {
        (pcVar5->u18).reg = g_reg_symbols + 0x1f;
        g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
        g_fp_lower_depth = g_fp_lower_depth + -1;
        return pcVar10;
      }
      emit_x87_load_operand(t);
      g_fp_lower_depth = g_fp_lower_depth + -1;
      return pcVar10;
    }
    t->op = 0x60;
    break;
  case 0x15f:
    pcVar5 = t->src;
    if (pcVar5->kind == '\a') {
      if ((pcVar5->type & 0xfff) != 8) {
        uVar13 = t->dst->type;
        pcVar5->flags = pcVar5->flags & 0xef;
        t->src = (c2_operand *)0x0;
        local_18 = pcVar5;
        local_18 = constant_convert_to(pcVar5,uVar13,(c2_tuple *)0x0);
        local_14 = (c2_operand *)find_next_use_of_dst(t,(c2_operand **)&local_4);
        tuple_replace_src((c2_tuple *)local_14,(c2_operand *)local_4,local_18);
        t->op = 0x145;
        return pcVar10;
      }
      pcVar7 = symbol_new_temp_plain(pcVar5->type);
      pcVar18 = tuple_insert_before;
      pcVar6 = t;
      pcVar8 = operand_new_intconst(0x1004,(pcVar5->u18).lo,pcVar5->tag);
      pcVar9 = symbol_get_part(pcVar7,0x1004,4,0);
      pcVar5 = operand_new_sym(0x14a,0x1004,pcVar9);
      tuple_new(1,0x1004,pcVar5,pcVar8,pcVar18,pcVar6);
      pcVar18 = tuple_insert_before;
      pcVar6 = t;
      lVar17 = allshr((t->src->u18).lo,t->src->tag,' ');
      pcVar8 = operand_new_intconst(0x1004,(uint32_t)lVar17,(int32_t)((ulonglong)lVar17 >> 0x20));
      pcVar9 = symbol_get_part(pcVar7,0x1004,4,4);
      pcVar5 = operand_new_sym(0x14a,0x1004,pcVar9);
      tuple_new(1,0x1004,pcVar5,pcVar8,pcVar18,pcVar6);
      pcVar5 = operand_new_sym(0x14a,pcVar7->type,pcVar7);
      tuple_replace_src(t,t->src,pcVar5);
    }
    uVar15 = t->type;
    uVar14 = uVar15 & 0xf000;
    if (uVar14 == 0x4000) {
      pcVar5 = t->src;
      uVar2 = pcVar5->type;
      if ((uVar2 & 0xf000) == 0x4000) {
        uVar15 = t->dst->type;
        local_4 = (c2_symbol *)CONCAT22((short)((uint)t->dst >> 0x10),uVar15);
        if (((uVar15 & 0xfff) < (uVar2 & 0xfff)) &&
           ((pcVar6 = t->next, pcVar6->op != 0x15b ||
            ((((pcVar6->dst->kind == '\x01' && (pcVar7 = pcVar6->dst->sym, pcVar7->cls == '\x03'))
              && (pcVar7->def != (c2_tuple *)0x0)) ||
             ((((1 << (pcVar6->src->kind & 0x1f) & 6U) == 0 || (t->dst->sym != pcVar6->src->sym)) ||
              (pcVar6->type != uVar15)))))))) {
          bVar16 = false;
        }
        else {
          bVar16 = true;
        }
        if (((pcVar5->kind != '\x01') || (pcVar5->sym->cls != '\x03')) ||
           (iVar3 = g_fp_lower_depth, pcVar5->sym->def == (c2_tuple *)0x0)) {
          if (bVar16) {
            t->op = 0x60;
            t->type = (uVar2 ^ t->type) & 0xfff ^ t->type;
            iVar3 = g_fp_lower_depth;
            break;
          }
          emit_x87_load_operand(t);
          iVar3 = g_fp_lower_depth;
          pcVar5 = t->src;
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          g_fp_lower_stack_syms[iVar3] = pcVar5->sym;
        }
        pcVar12 = t->dst;
        if (((pcVar12->kind != '\x01') || (pcVar12->sym->cls != '\x03')) ||
           (pcVar12->sym->def == (c2_tuple *)0x0)) {
          g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          t->op = 99;
          g_fp_lower_depth = iVar3 + -1;
          return pcVar10;
        }
        if (bVar16) {
          find_next_use_of_dst(t,&local_18);
          pcVar5 = t->src;
          pcVar7 = symbol_get_part(pcVar5->sym,local_18->type,local_18->type & 0xfff,0);
          t->op = 0x145;
          local_18->sym = pcVar7;
          local_18->u18 = pcVar5->u18;
          return pcVar10;
        }
        uVar13 = pcVar12->type;
        g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
        (pcVar5->u18).reg = g_reg_symbols + 0x1f;
        pcVar12 = operand_new_temp_sym(uVar13);
        tuple_new(99,uVar13,pcVar12,pcVar5,tuple_insert_before,t);
        t->op = 0x60;
        tuple_replace_src(t,t->src,pcVar12);
        iVar3 = g_fp_lower_depth;
        pcVar5 = t->dst;
        if (pcVar5->kind == '\x01') {
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          g_fp_lower_stack_syms[iVar3] = pcVar5->sym;
          return pcVar10;
        }
        goto LAB_1076eb71;
      }
    }
    uVar2 = t->src->type;
    bVar16 = (uVar2 & 0xf000) == 0x1000;
    if (uVar14 != 0x4000) goto LAB_1075c4de;
    if (bVar16) {
LAB_1075c239:
      if (!bVar16) {
LAB_1075c4de:
        if ((g_opt_qifist == 0) || (uVar15 == 0x2008)) {
          bind_result_to_register(t,g_reg_symbols + 1);
        }
        iVar3 = g_fp_lower_depth;
        pcVar5 = t->src;
        if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
           (pcVar5->sym->def != (c2_tuple *)0x0)) {
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
        }
        else {
          emit_x87_load_operand(t);
        }
        g_fp_lower_depth = g_fp_lower_depth + -1;
        if ((g_opt_qifist != 0) && (t->type != 0x2008)) {
          pcVar7 = symbol_new_temp_plain(0x1008);
          pcVar12 = operand_new_sym(0x14a,0x1008,pcVar7);
          uVar15 = t->dst->type;
          pcVar7 = symbol_get_part(pcVar7,uVar15,uVar15 & 0xfff,0);
          pcVar11 = operand_new_sym(0x14a,uVar15,pcVar7);
          bVar1 = pcVar12->flags11;
          pcVar5 = t->src;
          pcVar11->flags11 = pcVar11->flags11 | 8;
          pcVar12->flags11 = bVar1 | 8;
          pcVar10 = tuple_new(0x5b,0x1008,pcVar12,pcVar5,tuple_insert_after,t);
          pcVar10 = tuple_new(0x15b,pcVar11->type,t->dst,pcVar11,tuple_insert_after,pcVar10);
          if (((1 << (pcVar10->dst->kind & 0x1f) & 6U) != 0) &&
             (pcVar7 = pcVar10->dst->sym, pcVar7->def != (c2_tuple *)0x0)) {
            if (pcVar7->storage->part_next == (c2_symbol *)0x0) {
              pcVar7->def = pcVar10;
              t->dst = (c2_operand *)0x0;
              tuple_unlink_free(t);
              return pcVar10;
            }
            symbol_mark_overlapping_parts(pcVar7,pcVar10);
          }
          t->dst = (c2_operand *)0x0;
          tuple_unlink_free(t);
          return pcVar10;
        }
        fs = fe_symbol_lookup_name("__ftol");
        local_18 = operand_for_symbol_ref(fs);
        local_18->sym->def = (c2_tuple *)((uint)local_18->sym->def | 0x10000);
        pcVar10 = build_helper_call((c2_node *)t,0xe,local_18,'\0');
        return pcVar10;
      }
    }
    else if (4 < (uVar2 & 0xfff)) {
      error(0x208);
      bVar16 = true;
      goto LAB_1075c239;
    }
    if (g_opt_float_consistency != 0) {
      local_c = 1;
      if ((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
         (pcVar6 = find_next_use_of_dst(t,(c2_operand **)&local_4), pcVar6->op == 0x15b)) {
        local_c = 0;
      }
    }
    pcVar5 = t->src;
    if (((pcVar5->kind != '\x01') || (pcVar5->sym->cls != '\x03')) ||
       (pcVar5->sym->def == (c2_tuple *)0x0)) {
      if ((bVar16) || (4 < (pcVar5->type & 0xfff))) {
        uVar15 = pcVar5->type;
        t->op = 0x56;
        bVar16 = g_fp_lower_depth == 7;
        t->type = (uVar15 ^ t->type) & 0xfff ^ t->type;
        if (bVar16) {
          x87_spill_stack_entries(t,1,0);
        }
        pcVar5 = t->dst;
        if (pcVar5->kind == '\x01') {
          g_fp_lower_depth = g_fp_lower_depth + 1;
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar5->sym;
        }
        else {
          bind_result_to_register(t,g_reg_symbols + 0x1f);
        }
        goto LAB_1075c2ce;
      }
      load_operand_into_register(t,pcVar5,g_reg_symbols);
    }
    if (g_fp_lower_depth == 7) {
      x87_spill_stack_entries(t,1,0);
    }
    pcVar5 = t->dst;
    if (pcVar5->kind == '\x01') {
      g_fp_lower_depth = g_fp_lower_depth + 1;
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar5->sym;
    }
    else {
      bind_result_to_register(t,g_reg_symbols + 0x1f);
    }
    if (bVar16) {
      uVar13 = t->src->type;
      pcVar7 = symbol_new_temp_plain(uVar13);
      local_4 = pcVar7;
      uVar15 = uVar13;
    }
    else {
      uVar14 = t->src->type;
      uVar15 = uVar14 & 0xf004 | 4;
      uVar13 = uVar14 & 0xf008 | 8;
      local_4 = symbol_new_temp_plain(uVar13);
      pcVar7 = symbol_get_part(local_4,uVar15,0,0);
    }
    pcVar5 = t->src;
    insert_fn = tuple_insert_before;
    pcVar10 = t;
    pcVar12 = operand_new_sym(0x14a,uVar15,pcVar7);
    pcVar10 = tuple_new(1,uVar15,pcVar12,pcVar5,insert_fn,pcVar10);
    if ((uVar15 & 0xfff) == 8) {
      lower_int64_tuple(pcVar10);
    }
    if (!bVar16) {
      pcVar18 = tuple_insert_before;
      pcVar6 = t;
      pcVar8 = operand_new_intconst(0x2004,0,0);
      pcVar7 = symbol_get_part(pcVar7,0x2004,0,4);
      pcVar5 = operand_new_sym(0x14a,0x2004,pcVar7);
      tuple_new(1,0x2004,pcVar5,pcVar8,pcVar18,pcVar6);
    }
    pcVar5 = operand_new_sym(0x14a,uVar13,local_4);
    tuple_replace_src(t,t->src,pcVar5);
    t->op = 0x56;
LAB_1075c2ce:
    if (g_opt_float_consistency == 0) {
      return pcVar10;
    }
    if (local_c == 0) {
      return pcVar10;
    }
    if (g_fp_lower_depth < 0) {
      return pcVar10;
    }
    x87_spill_stack_entries(t,1,0);
    return pcVar10;
  case 0x161:
  case 0x162:
    uVar4 = lookup_opcode_pair_table(g_il_to_x87_op_table,il_op);
    t->op = uVar4;
    iVar3 = g_fp_lower_depth;
    pcVar5 = t->src;
    if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
       (pcVar5->sym->def != (c2_tuple *)0x0)) {
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
    }
    else {
      emit_x87_load_operand(t);
    }
    pcVar5 = t->dst;
    if (pcVar5->kind == '\x01') {
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar5->sym;
      return pcVar10;
    }
LAB_1076eb71:
    bind_result_to_register(t,g_reg_symbols + 0x1f);
    g_fp_lower_depth = g_fp_lower_depth + -1;
    return pcVar10;
  case 0x16c:
    pcVar5 = t->src;
    if (((pcVar5->kind == '\x01') && (pcVar7 = pcVar5->sym, pcVar7->cls == '\x03')) &&
       (pcVar7->def != (c2_tuple *)0x0)) {
      pcVar5 = find_dst_symbol_ref(pcVar7->def,pcVar7);
      pcVar5->sym = g_reg_symbols + 0x1f;
      t->op = 0x145;
      g_fp_lower_stack_syms[0] = (c2_symbol *)0x0;
      g_fp_lower_depth = g_fp_lower_depth + -1;
      return pcVar10;
    }
    insert_fn = tuple_insert_after;
    pcVar6 = t;
    pcVar12 = operand_new_hardreg(0x1f,0x4008);
    tuple_new(0x60,t->type,pcVar12,pcVar5,insert_fn,pcVar6);
    t->op = 0x145;
    return pcVar10;
  case 0x175:
    pcVar5 = t->src->next;
    if ((pcVar5->kind == '\t') &&
       (iVar3 = float_const_compare_mask(1,(c2_float_const *)pcVar5->sym,&g_ld_const_zero),
       iVar3 != 0)) {
      warning(3,0x2d3);
      pcVar10 = lower_x87_tuple_case_16d(t,il_op,pcVar10);
      return pcVar10;
    }
  case 0x16d:
  case 0x16e:
  case 0x16f:
    uVar4 = lookup_opcode_pair_table(g_il_to_x87_op_table,il_op);
    t->op = uVar4;
    lower_x87_binary_op(t);
    return pcVar10;
  case 0x178:
    pcVar5 = t->src;
    if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
       (pcVar5->sym->def != (c2_tuple *)0x0)) {
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[iVar3] = (c2_symbol *)0x0;
    }
    else {
      emit_x87_load_operand(t);
    }
    pcVar5 = t->dst;
    if (pcVar5->kind == '\x01') {
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar5->sym;
    }
    else {
      bind_result_to_register(t,g_reg_symbols + 0x1f);
      g_fp_lower_depth = g_fp_lower_depth + -1;
    }
    pcVar5 = (c2_operand *)find_next_use_of_dst(t,(c2_operand **)0x0);
    if (((pcVar5->op == 0x15f) &&
        (pcVar12 = (c2_operand *)pcVar5->tag, (pcVar12->type & 0xf000) == 0x4000)) &&
       (((1 << (pcVar12->kind & 0x1f) & 6U) != 0 && (pcVar12->sym->def != (c2_tuple *)0x0)))) {
      pcVar5 = (c2_operand *)find_next_use_of_dst((c2_tuple *)pcVar5,(c2_operand **)0x0);
    }
    if (pcVar5->op == 0x15b) {
      for (pcVar12 = (c2_operand *)t->next;
          ((pcVar12 != pcVar5 && (pcVar12->kind != '\x0e')) && (pcVar12->op != 0x178));
          pcVar12 = pcVar12->next) {
      }
      local_14 = pcVar12;
      if (pcVar12->op == 0x15b) {
        local_18 = operand_new_temp(0x1004);
        (local_18->u18).reg = g_reg_symbols + 1;
        local_18->sym->def = t;
        tuple_append_dst(t,local_18);
        insert_fn = tuple_insert_after;
        pcVar11 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x42,g_reg_symbols + 0x42);
        pcVar5 = local_18;
        dst = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
        tuple_new_binary(0x178,0x1004,dst,pcVar5,pcVar11,insert_fn,(c2_tuple *)pcVar12);
        goto LAB_1076f416;
      }
    }
    pcVar5 = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
    tuple_append_dst(t,pcVar5);
LAB_1076f416:
    pcVar5 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x42,g_reg_symbols + 0x42);
    tuple_append_dst(t,pcVar5);
    return pcVar10;
  case 0x17d:
    local_14 = (c2_operand *)find_next_use_of_dst(t,&local_18);
    pcVar5 = t->src;
    *(byte *)&local_14->type = g_unsigned_cc[(byte)local_14->type];
    if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
       (pcVar5->sym->def != (c2_tuple *)0x0)) {
      pcVar12 = pcVar5->next;
      if (((pcVar12->kind == '\x01') && (pcVar7 = pcVar12->sym, pcVar7->cls == '\x03')) &&
         (pcVar7->def != (c2_tuple *)0x0)) {
        t->op = 0x5e;
        pcVar9 = g_fp_lower_stack_syms[g_fp_lower_depth];
        g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
        if (pcVar9->storage == pcVar7->storage) {
          (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
          (pcVar5->u18).reg = g_reg_symbols + 0x20;
          g_fp_lower_depth = g_fp_lower_depth + -2;
          (pcVar12->u18).reg = (c2_symbol *)0x107ad15c;
          tuple_swap_first_srcs(t);
          branch_swap_condition((c2_tuple *)local_14);
        }
        else {
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          pcVar5 = pcVar5->next;
          (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
          g_fp_lower_depth = g_fp_lower_depth + -2;
          (pcVar5->u18).reg = (c2_symbol *)0x107ad1b0;
        }
        goto LAB_1075c022;
      }
      t->op = 0x5d;
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
    }
    else {
      emit_x87_load_operand(t);
      pcVar5 = t->src->next;
      if (((pcVar5->kind == '\x01') && (pcVar5->sym->cls == '\x03')) &&
         (pcVar5->sym->def != (c2_tuple *)0x0)) {
        t->op = 0x5e;
        (pcVar5->u18).reg = (c2_symbol *)0x107ad1b0;
        (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
        g_fp_lower_depth = g_fp_lower_depth + -2;
        goto LAB_1075c022;
      }
      t->op = 0x5d;
    }
    g_fp_lower_depth = g_fp_lower_depth + -1;
LAB_1075c022:
    pcVar5 = operand_new_temp_in_reg(0x4a,0x8000);
    pcVar5->sym->def = t;
    pcVar6 = tuple_new_unary_temp(0x6e,0x2002,pcVar5,tuple_insert_after,t);
    local_14 = (c2_operand *)tuple_new(0xae,0x2001,t->dst,pcVar6->dst,tuple_insert_after,pcVar6);
    tuple_replace_dst(t,t->dst,pcVar5);
    bind_result_to_register(pcVar6,g_reg_symbols + 9);
    ((c2_operand *)local_14->tag)->sym->def = (c2_tuple *)local_14;
    return pcVar10;
  case 0x184:
    t->op = 0xe;
    lower_call_site(t);
    if (t->src->op == 0x146) {
      load_operand_into_register(t,t->src,g_reg_symbols);
    }
    pcVar5 = t->dst;
    if (((pcVar5 == (c2_operand *)0x0) || ((1 << (pcVar5->kind & 0x1f) & 6U) == 0)) ||
       ((pcVar5->sym->cls != '\x03' || (iVar3 = g_fp_lower_depth, (pcVar5->type & 0xf000) != 0x4000)
        ))) {
      emit_fstp_discard(t);
      return pcVar10;
    }
    break;
  case 400:
    pcVar10 = lower_float_intrinsic(t);
    return pcVar10;
  case 0x19e:
    pcVar5 = t->src;
    if (((pcVar5 != (c2_operand *)0x0) && (pcVar5->kind == '\x01')) &&
       ((pcVar5->sym->cls == '\x03' && (pcVar5->sym->def != (c2_tuple *)0x0)))) {
      uVar13 = t->type;
      insert_fn = tuple_insert_before;
      g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
      g_fp_lower_depth = g_fp_lower_depth + -1;
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      pcVar6 = t;
      pcVar12 = operand_new_reg(0x149,uVar13,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
      tuple_new(99,uVar13,pcVar12,pcVar5,insert_fn,pcVar6);
      t->op = 0x145;
      return pcVar10;
    }
  default:
    if ((il_op != 0) && (il_op < 0x144)) {
      return pcVar10;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lowerflt.c",0x37e);
  }
  if (iVar3 == 7) {
    x87_spill_stack_entries(t,1,0);
  }
  pcVar5 = t->dst;
  if (pcVar5->kind == '\x01') {
    g_fp_lower_depth = g_fp_lower_depth + 1;
    (pcVar5->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar5->sym;
    return pcVar10;
  }
  bind_result_to_register(t,g_reg_symbols + 0x1f);
  return pcVar10;
}

