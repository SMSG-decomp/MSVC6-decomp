c2_tuple * __fastcall lower_float_intrinsic(c2_tuple *t)

{
  ushort uVar1;
  uint16_t uVar2;
  c2_symbol *sym;
  c2_operand *new_op;
  c2_const_operand *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  uint uVar9;
  int iVar10;
  code *insert_fn_00;
  int local_c;
  c2_insert_fn *insert_fn;
  
  uVar1 = (t->u20).intrinsic.id;
  uVar9 = (uint)uVar1;
  local_c = 0;
  iVar10 = ((g_intrinsic_desc[uVar9].x87_flags & 7) - 7) + g_fp_lower_depth;
  pcVar4 = t->src;
  while (pcVar5 = pcVar4, pcVar5 != (c2_operand *)0x0) {
    local_c = local_c + 1;
    pcVar4 = pcVar5->next;
    if (((pcVar5->kind != '\x01') || (pcVar5->sym->cls != '\x03')) ||
       (pcVar5->sym->def == (c2_tuple *)0x0)) {
      new_op = emit_load_into_register(0x60,t,pcVar5,g_reg_symbols + 0x1f);
      if (g_fp_lower_depth == 7) {
        x87_spill_stack_entries(t->prev,1,0);
      }
      if (t->prev->dst->kind == '\x01') {
        g_fp_lower_depth = g_fp_lower_depth + 1;
        (new_op->u18).reg = g_reg_symbols + 0x1f;
        g_fp_lower_stack_syms[g_fp_lower_depth] = new_op->sym;
      }
      else {
        bind_result_to_register(t->prev,g_reg_symbols + 0x1f);
      }
      tuple_replace_src(t,pcVar5,new_op);
    }
  }
  if (0 < iVar10) {
    x87_spill_stack_entries(t,iVar10,local_c);
  }
  pcVar4 = t->src;
  if (((pcVar4 != (c2_operand *)0x0) && (pcVar4->next != (c2_operand *)0x0)) &&
     (g_fp_lower_stack_syms[g_fp_lower_depth] != pcVar4->sym)) {
    emit_fxch(t,0x4008);
  }
  iVar10 = g_fp_lower_depth;
  if (uVar9 == 0x6f || uVar1 < 0x6f) {
    if (uVar1 < 0x6e) {
      switch(uVar9) {
      case 0x10:
      case 0x11:
        goto switchD_1076f647_caseD_10;
      case 0x5c:
      case 0x5d:
      case 0x6a:
      case 0x6b:
        goto switchD_1076f647_caseD_5c;
      case 0x60:
      case 0x61:
        if (((g_opt_favor_speed != 0) && (g_opt_global != 0)) && (g_opt_float_consistency == 0)) {
          pcVar4 = t->src;
          insert_fn = tuple_insert_before;
          pcVar6 = t;
          pcVar3 = operand_new_intconst(0x1004,(uint)(t->u20).intrinsic.id,0);
          pcVar6 = tuple_new_binary(0x166,t->type,t->dst,pcVar3,pcVar4,insert_fn,pcVar6);
          tuple_unlink_free(t);
          pcVar4 = pcVar6->dst;
          if (((1 << (pcVar4->kind & 0x1f) & 6U) == 0) ||
             (sym = pcVar4->sym, sym->def == (c2_tuple *)0x0)) {
            uVar2 = pcVar6->type;
            pcVar5 = operand_new_temp(uVar2);
            tuple_new(0x15b,uVar2,pcVar4,pcVar5,tuple_insert_after,pcVar6);
            tuple_replace_dst(pcVar6,pcVar6->dst,pcVar5);
            pcVar5->sym->def = pcVar6;
          }
          else if (sym->storage->part_next == (c2_symbol *)0x0) {
            sym->def = pcVar6;
          }
          else {
            symbol_mark_overlapping_parts(sym,pcVar6);
          }
          pcVar4 = pcVar6->src->next;
          g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
          g_fp_lower_depth = g_fp_lower_depth + -1;
          (pcVar4->u18).reg = (c2_symbol *)0x107ad15c;
          pcVar8 = tuple_new_pseudo(0x19e,0x4008);
          pcVar4 = operand_new_temp(0x4008);
          tuple_append_dst(pcVar8,pcVar4);
          pcVar4->sym->def = pcVar8;
          tuple_insert_before(pcVar6,pcVar8);
          tuple_append_src(pcVar6,pcVar4);
          if (g_fp_lower_depth == 7) {
            x87_spill_stack_entries(pcVar8,1,0);
          }
          pcVar4 = pcVar8->dst;
          if (pcVar4->kind == '\x01') {
            g_fp_lower_depth = g_fp_lower_depth + 1;
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar4->sym;
          }
          else {
            bind_result_to_register(pcVar8,g_reg_symbols + 0x1f);
          }
          pcVar8 = tuple_new_pseudo(0x19e,0x4008);
          pcVar4 = operand_new_temp(0x4008);
          tuple_append_dst(pcVar8,pcVar4);
          pcVar4->sym->def = pcVar8;
          tuple_insert_before(pcVar6,pcVar8);
          tuple_append_src(pcVar6,pcVar4);
          if (g_fp_lower_depth == 7) {
            x87_spill_stack_entries(pcVar8,1,0);
          }
          pcVar4 = pcVar8->dst;
          if (pcVar4->kind == '\x01') {
            g_fp_lower_depth = g_fp_lower_depth + 1;
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar4->sym;
          }
          else {
            bind_result_to_register(pcVar8,g_reg_symbols + 0x1f);
          }
          pcVar4 = pcVar6->src;
          g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
          (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
          iVar10 = g_fp_lower_depth + -2;
          pcVar4 = pcVar4->next->next;
          g_fp_lower_depth = iVar10;
          (pcVar4->u18).reg = (c2_symbol *)0x107ad1b0;
          (pcVar4->next->u18).reg = (c2_symbol *)0x107ad204;
          if (iVar10 == 7) {
            x87_spill_stack_entries(pcVar6,1,0);
            iVar10 = g_fp_lower_depth;
          }
          pcVar4 = pcVar6->dst;
          if (pcVar4->kind == '\x01') {
            g_fp_lower_depth = iVar10 + 1;
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[iVar10 + 1] = pcVar4->sym;
            return pcVar6;
          }
          bind_result_to_register(pcVar6,g_reg_symbols + 0x1f);
          return pcVar6;
        }
        break;
      case 100:
      case 0x65:
      case 0x68:
      case 0x69:
        if ((g_opt_global != 0) && (g_opt_float_consistency == 0)) {
          uVar2 = (t->u20).intrinsic.id;
          if ((uVar2 == 100) || (uVar7 = 0x83, uVar2 == 0x65)) {
            uVar7 = 0x84;
          }
          pcVar8 = emit_x87_unary_tuple(t,0x91);
          insert_fn = tuple_insert_before;
          pcVar6 = pcVar8;
          pcVar3 = operand_new_intconst(0x1004,0,0);
          pcVar6 = tuple_new_unary_temp(uVar7,pcVar8->type,pcVar3,insert_fn,pcVar6);
          tuple_remove_src(pcVar6,pcVar6->src);
          tuple_append_src(pcVar8,pcVar6->dst);
          if (g_fp_lower_depth == 7) {
            x87_spill_stack_entries(pcVar6,1,0);
          }
          pcVar4 = pcVar6->dst;
          if (pcVar4->kind == '\x01') {
            iVar10 = g_fp_lower_depth + 1;
            g_fp_lower_depth = iVar10;
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[iVar10] = pcVar4->sym;
          }
          else {
            bind_result_to_register(pcVar6,g_reg_symbols + 0x1f);
          }
          emit_fxch(pcVar8,pcVar8->type);
          pcVar4 = pcVar8->src;
          (pcVar4->u18).reg = g_reg_symbols + 0x1f;
          pcVar4 = pcVar4->next;
          g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
          (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
          (pcVar4->u18).reg = (c2_symbol *)0x107ad1b0;
LAB_1076f73d:
          pcVar4 = pcVar8->dst;
          iVar10 = g_fp_lower_depth + -1;
          g_fp_lower_depth = iVar10;
          if (pcVar4->kind == '\x01') {
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[iVar10] = pcVar4->sym;
            return pcVar8;
          }
          goto LAB_1076f752;
        }
      }
switchD_1076f647_caseD_12:
      pcVar4 = t->src;
      (pcVar4->u18).reg = g_reg_symbols + 0x1f;
      pcVar4 = pcVar4->next;
      g_fp_lower_stack_syms[iVar10] = (c2_symbol *)0x0;
      if (pcVar4 != (c2_operand *)0x0) {
        (&g_fp_lower_depth)[iVar10] = 0;
        (pcVar4->u18).reg = (c2_symbol *)0x107ad1b0;
      }
      pcVar8 = emit_float_ci_helper_call(t);
      uVar9 = (uint)(pcVar8->u24).call.x87_pops;
      if (uVar9 != 0) {
        g_fp_lower_depth = g_fp_lower_depth - uVar9;
      }
      iVar10 = g_fp_lower_depth;
      pcVar4 = pcVar8->dst;
      if (pcVar4->kind == '\x01') {
        (pcVar4->u18).reg = g_reg_symbols + 0x1f;
        g_fp_lower_stack_syms[iVar10] = pcVar4->sym;
        return pcVar8;
      }
      goto LAB_1076f752;
    }
switchD_1076f647_caseD_5c:
    if ((g_opt_global == 0) || (g_opt_float_consistency != 0)) goto switchD_1076f647_caseD_12;
switchD_1076f647_caseD_10:
    uVar7 = intrinsic_machine_opcode(uVar9);
    pcVar8 = emit_x87_unary_tuple(t,uVar7);
    iVar10 = g_fp_lower_depth;
    pcVar4 = pcVar8->src;
    g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
    (pcVar4->u18).reg = g_reg_symbols + 0x1f;
  }
  else {
    if (uVar9 != 0x85 && 0x84 < uVar1) {
      if (uVar9 == 0xe6) goto switchD_1076f647_caseD_5c;
      if (uVar9 == 0x185) {
        pcVar6 = tuple_new_nooperands(0x8e,0x400a,tuple_insert_before,t);
        tuple_unlink_free(t);
        return pcVar6;
      }
      goto switchD_1076f647_caseD_12;
    }
    if (uVar1 < 0x84) {
      switch(uVar9) {
      case 0x72:
      case 0x73:
        if ((g_opt_global != 0) && (g_opt_float_consistency == 0)) {
          pcVar6 = emit_x87_unary_tuple(t,0x88);
          iVar10 = g_fp_lower_depth;
          pcVar4 = pcVar6->src;
          g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
          (pcVar4->u18).reg = g_reg_symbols + 0x1f;
          pcVar4 = pcVar6->dst;
          if (pcVar4->kind == '\x01') {
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
            g_fp_lower_stack_syms[iVar10] = pcVar4->sym;
            pcVar6 = (c2_tuple *)emit_fstp_discard(pcVar6);
            return pcVar6;
          }
          bind_result_to_register(pcVar6,g_reg_symbols + 0x1f);
          g_fp_lower_depth = g_fp_lower_depth + -1;
          pcVar6 = (c2_tuple *)emit_fstp_discard(pcVar6);
          return pcVar6;
        }
        break;
      case 0x82:
      case 0x83:
        if ((g_opt_global != 0) && (g_opt_float_consistency == 0)) {
          pcVar8 = emit_x87_unary_tuple(t,0x86);
          insert_fn_00 = tuple_insert_before;
          pcVar6 = pcVar8;
          pcVar3 = operand_new_intconst(0x1004,0,0);
          pcVar6 = tuple_new_unary_temp(0x94,pcVar8->type,pcVar3,insert_fn_00,pcVar6);
          tuple_remove_src(pcVar6,pcVar6->src);
          tuple_append_src(pcVar8,pcVar6->dst);
          if (g_fp_lower_depth == 7) {
            x87_spill_stack_entries(pcVar6,1,0);
          }
          pcVar4 = pcVar6->dst;
          if (pcVar4->kind == '\x01') {
            g_fp_lower_depth = g_fp_lower_depth + 1;
            g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar4->sym;
            (pcVar4->u18).reg = g_reg_symbols + 0x1f;
          }
          else {
            bind_result_to_register(pcVar6,g_reg_symbols + 0x1f);
          }
          pcVar4 = pcVar8->src;
          (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
          g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
          (pcVar4->u18).reg = g_reg_symbols + 0x20;
          (pcVar4->next->u18).reg = (c2_symbol *)0x107ad15c;
          goto LAB_1076f73d;
        }
      }
      goto switchD_1076f647_caseD_12;
    }
    if ((g_opt_global == 0) || (g_opt_float_consistency != 0)) goto switchD_1076f647_caseD_12;
    pcVar4 = t->src->next;
    t->src->next = (c2_operand *)0x0;
    pcVar8 = emit_x87_unary_tuple(t,0x86);
    pcVar5 = pcVar8->src;
    g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
    (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
    iVar10 = g_fp_lower_depth + -1;
    pcVar5->next = pcVar4;
    (pcVar5->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_depth = iVar10;
    (pcVar5->next->u18).reg = (c2_symbol *)0x107ad1b0;
  }
  pcVar4 = pcVar8->dst;
  if (pcVar4->kind == '\x01') {
    (pcVar4->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[iVar10] = pcVar4->sym;
    return pcVar8;
  }
LAB_1076f752:
  bind_result_to_register(pcVar8,g_reg_symbols + 0x1f);
  g_fp_lower_depth = g_fp_lower_depth + -1;
  return pcVar8;
}

