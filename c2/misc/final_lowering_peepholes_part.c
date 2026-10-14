void final_lowering_peepholes_part
               (uint32_t shift,c2_tuple *t,c2_tuple *next,c2_symbol *flags_live,int keep_ret,
               c2_operand *zero_reg_opnd,c2_operand *zero_const_opnd,uint32_t narrow_size,
               c2_operand *later_ref,c2_tuple *scan,c2_tuple *ret_label,uint32_t narrow_shift,
               c2_function *fn,uint8_t fcomp_class,uint8_t fcom_class,c2_tuple *end,c2_cfg *cfg)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  c2_symbol *pcVar4;
  byte bVar5;
  c2_const_operand *pcVar6;
  c2_operand *pcVar7;
  c2_fe_symbol *pcVar8;
  c2_tuple *t_00;
  c2_tuple *pcVar9;
  c2_float_const *a;
  c2_tuple *pcVar10;
  int iVar11;
  c2_operand *pcVar12;
  uint32_t uVar13;
  c2_operand *src1;
  c2_tuple *pcVar14;
  c2_symbol *pcVar15;
  uint16_t uVar16;
  uint64_t uVar17;
  undefined3 in_stack_00000041;
  undefined3 in_stack_00000045;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  uint32_t src_lo;
  
code_r0x10737b9f:
  tuple_replace_src(t,t->src,t->dst);
  t->op = 0x2a;
  pcVar6 = operand_new_intconst(t->type,shift,(int)shift >> 0x1f);
  tuple_append_src(t,pcVar6);
  set_flags_effects(t);
  pcVar14 = t;
switchD_10737d33_caseD_2:
  delete_identity_alu_op(pcVar14,(int)flags_live);
  pcVar10 = next;
LAB_10737c64:
  do {
    next = pcVar10;
    pcVar9 = ret_label;
    t = next;
    if (next == end) {
      if (ret_label != (c2_tuple *)0x0) {
        pcVar14 = tuple_find_prev_of_kind(cfg->last->end,'\x18');
        tuple_insert_before(pcVar14,pcVar9);
      }
      return;
    }
    pcVar10 = next->next;
  } while ((next->flags & 1) == 0);
  uVar2 = next->line;
  if (uVar2 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar2;
    g_cur_line = uVar2;
  }
  next = next->next;
  pcVar7 = find_src_overlapping_reg(t,g_reg_symbols + 0x42);
  if (((pcVar7 != (c2_operand *)0x0) && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
     (pcVar7->sym->def != (c2_tuple *)0x0)) {
    flags_live = (c2_symbol *)0x0;
  }
  pcVar7 = find_dst_clobbering_reg(t,g_reg_symbols + 0x42);
  if (((pcVar7 != (c2_operand *)0x0) && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
     (pcVar7->sym->def != (c2_tuple *)0x0)) {
    flags_live = pcVar7->sym;
  }
  if (t->src != (c2_operand *)0x0) {
    rewrite_index_times_two_as_base(t,t->src);
    swap_ebp_base_with_index(t,t->src,1);
    pcVar7 = t->src->next;
    if (pcVar7 != (c2_operand *)0x0) {
      swap_ebp_base_with_index(t,pcVar7,1);
    }
  }
  if (t->dst != (c2_operand *)0x0) {
    swap_ebp_base_with_index(t,t->dst,0);
  }
  pcVar4 = flags_live;
  uVar3 = t->op;
  pcVar14 = t;
  if (uVar3 < 0x61) {
    if (uVar3 != 0x60) {
      switch(uVar3) {
      case 1:
        pcVar7 = t->dst;
        if (pcVar7->kind != '\x01') {
          if (((g_opt_favor_speed != 0) || (flags_live != (c2_symbol *)0x0)) ||
             ((pcVar12 = t->src, (1 << (pcVar12->kind & 0x1f) & 0x380U) == 0 ||
              ((pcVar7->flags & 0x40) != 0)))) goto switchD_10737d33_caseD_2;
          src_lo = (pcVar12->u18).lo;
          if (src_lo == 0) {
            uVar16 = t->type;
            uVar13 = 0x2e;
          }
          else {
            uVar17 = const_normalize(pcVar12->type,0xffffffff,-1);
            if (src_lo != (uint32_t)uVar17) goto switchD_10737d33_caseD_2;
            pcVar12 = t->src;
            pcVar7 = t->dst;
            uVar16 = t->type;
            uVar13 = 0x30;
          }
          pcVar14 = tuple_new_binary(uVar13,uVar16,pcVar7,pcVar7,pcVar12,(c2_insert_fn *)0x0,
                                     (c2_tuple *)0x0);
          tuple_replace(t,(c2_node *)pcVar14);
          pcVar7 = operand_new_hardreg(0x42,0x8000);
          tuple_append_dst(pcVar14,pcVar7);
          goto switchD_10737d33_caseD_2;
        }
        if (flags_live == (c2_symbol *)0x0) {
          if (uVar3 == 1) {
            zero_const_opnd = t->src;
            zero_reg_opnd = pcVar7;
          }
          pcVar7 = t->src;
          if ((1 << (pcVar7->kind & 0x1f) & 0x380U) != 0) {
            if ((pcVar7->u18).reg == (c2_symbol *)0x0) {
              t->op = 0x34;
              node_free((c2_node *)pcVar7);
              pcVar7 = (c2_operand *)node_clone((c2_node *)t->dst);
              t->src = pcVar7;
              pcVar7 = (c2_operand *)node_clone((c2_node *)t->dst);
              t->src->next = pcVar7;
            }
            else {
              pcVar7 = t->src;
              uVar17 = const_normalize(pcVar7->type,0xffffffff,-1);
              if ((pcVar7->u18).reg != (c2_symbol *)uVar17) goto LAB_10737c3d;
              t->op = 0x30;
              pcVar12 = (c2_operand *)node_clone((c2_node *)t->dst);
              t->src = pcVar12;
              pcVar12->next = pcVar7;
            }
LAB_10737d96:
            pcVar7 = operand_new_hardreg(0x42,0x8000);
            tuple_append_dst(t,pcVar7);
            goto switchD_10737d33_caseD_2;
          }
          iVar11 = final_op_is_simple_alu(t->prev);
          if (((iVar11 != 0) && (pcVar7 = t->src, pcVar7->next == (c2_operand *)0x0)) &&
             ((pcVar7->kind == '\x01' &&
              ((pcVar7->sym->cls == '\x03' && (pcVar7->sym->def != (c2_tuple *)0x0)))))) {
            pcVar10 = t->prev;
            if ((pcVar10->dst->kind == '\x01') &&
               (pcVar12 = pcVar10->src->next, pcVar12->kind == '\x01')) {
              pcVar4 = (t->dst->u18).reg;
              if ((((pcVar4 != (pcVar7->u18).reg) && ((pcVar10->dst->u18).reg == (pcVar7->u18).reg))
                  && (pcVar4 == (pcVar12->u18).reg)) && (t->dst->next == (c2_operand *)0x0)) {
                tuple_swap_first_srcs(pcVar10);
                pcVar7 = pcVar10->dst;
                pcVar12 = operand_new_hardreg(((pcVar10->src->u18).reg)->id,pcVar7->type);
                tuple_replace_dst(pcVar10,pcVar7,pcVar12);
                pcVar7 = operand_new_hardreg(((pcVar10->dst->u18).reg)->id,t->src->type);
                tuple_replace_src(t,t->src,pcVar7);
                goto LAB_10737c3d;
              }
            }
          }
          if ((((zero_reg_opnd->kind == '\x01') && (zero_const_opnd->kind == '\x01')) &&
              ((zero_const_opnd->sym->cls == '\r' &&
               ((pcVar7 = (zero_const_opnd->sym->u28).const_operand, pcVar7->kind == '\a' &&
                ((pcVar7->u18).reg == (c2_symbol *)0x0 && pcVar7->tag == 0)))))) &&
             ((zero_reg_opnd->u18).reg != (zero_const_opnd->u18).reg)) {
            t->op = 0x34;
            tuple_replace_src(t,zero_const_opnd,t->dst);
            tuple_append_src(t,t->dst);
            set_flags_effects(t);
            goto switchD_10737d33_caseD_2;
          }
        }
LAB_10737c3d:
        pcVar7 = t->src;
        if ((pcVar7->kind == '\x01') && ((t->dst->u18).reg == (pcVar7->u18).reg)) {
          pcVar14 = t->prev;
          tuple_unlink_free(pcVar14->next);
          goto switchD_10737d33_caseD_2;
        }
        if ((((g_opt_favor_speed != 0) || (pcVar7->kind != '\a')) || ((t->type & 0xfff) != 4)) ||
           ((pcVar7->u18).reg != (c2_symbol *)(int)*(char *)&pcVar7->u18))
        goto switchD_10737d33_caseD_2;
        insert_fn = tuple_insert_after;
        pcVar12 = operand_new_hardreg(5,0x1004);
        pcVar6 = operand_new_intconst(0x1004,(pcVar7->u18).lo,pcVar7->tag);
        pcVar7 = operand_new_hardreg(5,0x1004);
        pcVar14 = tuple_new_binary(0xd,0x1004,pcVar7,pcVar6,pcVar12,insert_fn,pcVar14);
        pcVar14 = insert_pop_reg(((t->dst->u18).reg)->id,pcVar14);
        goto LAB_107381da;
      default:
        goto switchD_10737d33_caseD_2;
      case 0xe:
        if (((g_opt_favor_speed == 0) && (next->op == 0x2d)) &&
           ((next->dst->kind == '\x01' &&
            (((next->dst->u18).reg == g_reg_symbols + 5 &&
             (pcVar7 = next->src->next, pcVar7->kind == '\a')))))) {
          pcVar4 = (pcVar7->u18).reg;
          if (pcVar4 == (c2_symbol *)0x4) {
            tuple_unlink_free(next);
          }
          else {
            if (pcVar4 != (c2_symbol *)0x8) goto LAB_10738232;
            tuple_unlink_free(next);
            insert_pop_reg(2,t);
          }
          next = insert_pop_reg(2,t);
        }
LAB_10738232:
        if ((g_opt_global == 0) || ((t->u20).cond_cells != (c2_cond_cell *)0x0))
        goto switchD_10737d33_caseD_2;
        pcVar8 = call_target_function_symbol(t);
        if ((pcVar8 == (c2_fe_symbol *)0x0) || ((pcVar8->attrs & 0x80) == 0)) {
          keep_ret = 0;
          t_00 = tuple_next_real_in_block(t);
          pcVar9 = t_00;
          pcVar10 = t;
          if (flags_live == (c2_symbol *)0x0) goto LAB_1073826f;
          goto LAB_107382ab;
        }
        pcVar14 = tuple_find_next_kind_in_block(t,'\x11');
        if (pcVar14->op == 0x18c) {
          tuple_unlink_free(pcVar14);
        }
        keep_ret = 1;
        goto LAB_10738300;
      case 0x12:
        pcVar7 = t->src;
        if ((pcVar7->kind != '\x05') ||
           ((pcVar7->base_sym != (c2_symbol *)0x0 || (flags_live != (c2_symbol *)0x0))))
        goto switchD_10737d33_caseD_2;
        uVar13 = pcVar7->op;
        if ((uVar13 != 0x14c) || ((pcVar7->base->u18).reg != (t->dst->u18).reg)) {
          if (((uVar13 != 0x14d) || (pcVar7->disp != 0)) || ((pcVar7->flags & 0xf) != 0)) {
            if (((uVar13 != 0x14f) || ((pcVar7->flags & 0xf) < 2)) || (pcVar7->disp != 0))
            goto switchD_10737d33_caseD_2;
            shift = pcVar7->flags & 0xf;
            if ((pcVar7->index->u18).reg == (t->dst->u18).reg) goto code_r0x10737b9f;
            if (g_opt_favor_speed == 0) {
              tuple_new(1,t->type,t->dst,pcVar7->index,tuple_insert_before,t);
              final_lowering_peepholes_part
                        (shift,t,next,flags_live,keep_ret,zero_reg_opnd,zero_const_opnd,narrow_size,
                         later_ref,scan,ret_label,narrow_shift,fn,fcomp_class,fcom_class,end,cfg);
              return;
            }
            goto switchD_10737d33_caseD_2;
          }
          pcVar12 = t->dst;
          pcVar4 = (pcVar7->base->u18).reg;
          if (pcVar4 == (pcVar12->u18).reg) {
            uVar13 = ((pcVar7->index->u18).reg)->id;
          }
          else {
            if ((pcVar7->index->u18).reg != (pcVar12->u18).reg) {
              if (((next == (c2_tuple *)0x0) || (next->op != 0x32)) ||
                 (((next->src->next->kind != '\x01' ||
                   (iVar11 = operand_lists_equal(pcVar12,next->dst), iVar11 == 0)) ||
                  (((pcVar7 = find_dst_clobbering_reg(next,g_reg_symbols + 0x42),
                    pcVar7 != (c2_operand *)0x0 && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
                   (pcVar7->sym->def != (c2_tuple *)0x0)))))) goto switchD_10737d33_caseD_2;
              pcVar7 = t->src;
              pcVar15 = (pcVar7->base->u18).reg;
              pcVar4 = (next->src->next->u18).reg;
              if (pcVar15 == pcVar4) {
                pcVar15 = (pcVar7->index->u18).reg;
              }
              else if ((pcVar7->index->u18).reg != pcVar4) goto switchD_10737d33_caseD_2;
              uVar13 = pcVar15->id;
              t->op = 1;
              pcVar12 = operand_new_hardreg(uVar13,0x1004);
              tuple_replace_src(t,pcVar7,pcVar12);
              tuple_unlink_free(next);
              next = t;
              goto switchD_10737d33_caseD_2;
            }
            uVar13 = pcVar4->id;
          }
          tuple_replace_src(t,pcVar7,pcVar12);
          t->op = 0x2d;
          pcVar7 = operand_new_hardreg(uVar13,0x1004);
          tuple_append_src(t,pcVar7);
          next = t;
          set_flags_effects(t);
          goto switchD_10737d33_caseD_2;
        }
        uVar13 = pcVar7->disp;
        tuple_replace_src(t,pcVar7,t->dst);
        if (uVar13 == 0xffffffff) {
          t->op = 0x1e;
        }
        else if (uVar13 == 1) {
          t->op = 0x21;
        }
        else {
          t->op = 0x2d;
          pcVar6 = operand_new_intconst(0x1004,uVar13,(int)uVar13 >> 0x1f);
          tuple_append_src(t,pcVar6);
        }
        iVar11 = fold_adjacent_reg_arith(t,&next);
        pcVar10 = next;
        if (iVar11 == 0) {
          set_flags_effects(t);
          goto switchD_10737d33_caseD_2;
        }
        break;
      case 0x1e:
      case 0x21:
        if ((flags_live != (c2_symbol *)0x0) ||
           (iVar11 = fold_adjacent_reg_arith(t,&next), pcVar10 = next, iVar11 == 0))
        goto switchD_10737d33_caseD_2;
        break;
      case 0x2d:
      case 0x32:
        if (flags_live == (c2_symbol *)0x0) {
          if (((((((next != (c2_tuple *)0x0) &&
                  (next->op == (-(uint)(uVar3 != 0x2d) & 0xfffffffb) + 0x32)) &&
                 (iVar11 = operand_lists_equal(t->dst,next->dst), iVar11 != 0)) &&
                (((1 << (t->dst->kind & 0x1f) & 0x7eU) == 0 || ((t->dst->flags & 0x40) == 0)))) &&
               (((1 << (next->dst->kind & 0x1f) & 0x7eU) == 0 || ((next->dst->flags & 0x40) == 0))))
              && (iVar11 = operand_lists_equal(t->src->next,next->src->next), iVar11 != 0)) &&
             ((((pcVar7 = t->src->next, (1 << (pcVar7->kind & 0x1f) & 0x7eU) == 0 ||
                ((pcVar7->flags & 0x40) == 0)) &&
               ((pcVar7 = next->src->next, (1 << (pcVar7->kind & 0x1f) & 0x7eU) == 0 ||
                ((pcVar7->flags & 0x40) == 0)))) &&
              (((pcVar7 = find_dst_clobbering_reg(next,g_reg_symbols + 0x42),
                pcVar7 == (c2_operand *)0x0 || ((1 << (pcVar7->kind & 0x1f) & 6U) == 0)) ||
               (pcVar7->sym->def == (c2_tuple *)0x0)))))) {
            pcVar14 = t->prev;
            tuple_unlink_free(t);
            tuple_unlink_free(next);
            pcVar10 = pcVar14->next;
            break;
          }
          if ((t->src->kind == '\x01') && (t->src->next->kind == '\a')) {
            iVar11 = fold_adjacent_reg_arith(t,&next);
            pcVar10 = next;
            if (iVar11 != 0) break;
            if ((t->op != 0x2d) && (t->op != 0x32)) goto switchD_10737d33_caseD_2;
          }
        }
        if ((g_opt_favor_speed != 0) ||
           (((t->src->kind != '\x01' || (t->src->next->kind != '\a')) || ((t->type & 0xfff) != 4))))
        goto LAB_1073800e;
        if (pcVar4 == (c2_symbol *)0x0) goto LAB_1077c90b;
        pcVar10 = t->next;
        pcVar7 = later_ref;
        if (pcVar10 == (c2_tuple *)0x0) goto LAB_1077c8fe;
        goto LAB_1077c8e1;
      case 0x2e:
      case 0x30:
      case 0x33:
        narrow_size = 0;
        if ((g_opt_cpu_target != 6) &&
           (iVar11 = narrow_immediate_operation(t,&narrow_size,&narrow_shift), iVar11 != 0)) {
          narrow_and_or_constant(t,narrow_size,narrow_shift);
        }
        goto switchD_10737d33_caseD_2;
      case 0x2f:
        if (uVar3 == 0x2f) {
          zero_const_opnd = t->src;
          if (((zero_const_opnd->kind == '\x01') && (zero_const_opnd->sym->cls == '\r')) &&
             ((pcVar7 = (zero_const_opnd->sym->u28).const_operand, pcVar7->kind == '\a' &&
              ((pcVar7->u18).reg == (c2_symbol *)0x0 && pcVar7->tag == 0)))) {
            zero_reg_opnd = zero_const_opnd->next;
          }
          else {
            zero_reg_opnd = zero_const_opnd;
            zero_const_opnd = zero_const_opnd->next;
          }
        }
        pcVar7 = t->src;
        if (((pcVar7->kind == '\x01') && (pcVar12 = pcVar7->next, pcVar12->kind == '\a')) &&
           ((pcVar12->u18).reg == (c2_symbol *)0x0)) {
          t->op = 0x33;
          tuple_replace_src(t,pcVar12,pcVar7);
        }
        goto switchD_10737d33_caseD_2;
      case 0x46:
        pcVar7 = t->src;
        pcVar12 = pcVar7->next;
        if (((pcVar12->op == 0x14b) &&
            (a = float_constant_pool_lookup(pcVar12->sym->fe), a != (c2_float_const *)0x0)) &&
           (iVar11 = float_const_compare_mask(1,a,&g_ld_const_two), iVar11 != 0)) {
          t->op = 0x45;
          tuple_replace_src(t,pcVar12,pcVar7);
        }
      case 0x45:
      case 0x47:
      case 0x48:
      case 0x49:
      case 0x4a:
        next = x87_fold_into_pop_form(t);
switchD_10737d33_caseD_4b:
        pcVar10 = x87_arith_peephole(t);
        break;
      case 0x4b:
      case 0x4c:
      case 0x4d:
      case 0x4e:
      case 0x4f:
      case 0x50:
        goto switchD_10737d33_caseD_4b;
      case 0x5d:
        pcVar10 = t->prev;
        if (pcVar10->op != 0x60) goto switchD_10737d33_caseD_2;
        if (((pcVar10->src->kind == '\x01') &&
            (pcVar4 = (pcVar10->src->u18).reg, pcVar4->cls == '\x01')) && (pcVar4->id == 0x1f)) {
          pcVar7 = t->src->next;
          if ((pcVar7->kind == '\x01') && (((pcVar7->u18).reg)->cls == '\x01')) {
            uVar13 = x87_reg_after_pop(((pcVar7->u18).reg)->id);
            pcVar7 = operand_new_hardreg(uVar13,pcVar7->type);
            tuple_replace_src(t,t->src->next,pcVar7);
          }
          tuple_replace_src(t,t->src,t->prev->src);
          t->op = 0x5c;
          x87_fix_stack_effect_dsts(t);
          tuple_unlink_free(t->prev);
          pcVar10 = next;
        }
        else {
          if ((((t->type != pcVar10->type) || ((1 << (pcVar10->src->kind & 0x1f) & 0x60U) == 0)) ||
              ((pcVar7 = t->src, pcVar7->kind != '\x01' ||
               ((((pcVar7->u18).reg)->cls != '\x01' || (((pcVar7->u18).reg)->id != 0x1f)))))) ||
             ((pcVar7->next->kind != '\x01' ||
              ((pcVar4 = (pcVar7->next->u18).reg, pcVar4->cls != '\x01' || (pcVar4->id != 0x20))))))
          goto switchD_10737d33_caseD_2;
          t->op = 0x5c;
          x87_fix_stack_effect_dsts(t);
          tuple_replace_src(t,t->src->next,t->prev->src);
          tuple_unlink_free(t->prev);
          pcVar14 = find_next_use_of_dst(t,(c2_operand **)&stack0x00000038);
          pcVar14 = find_next_use_of_dst(pcVar14,(c2_operand **)&stack0x00000038);
          pcVar14 = find_next_use_of_dst(pcVar14,(c2_operand **)&stack0x00000038);
          bVar5 = x86_fixed_reg_class(pcVar14);
          _fcom_class = CONCAT31(in_stack_00000045,bVar5);
          set_condition_code(pcVar14,g_cond_swapped_operands[bVar5]);
          pcVar10 = next;
        }
        break;
      case 0x5e:
        pcVar10 = t->prev;
        if ((((pcVar10->op != 0x60) ||
             ((uVar16 = t->type, uVar16 != pcVar10->type && (pcVar10->src->kind != '\x01')))) ||
            ((pcVar10->src->kind == '\x01' && (((pcVar10->src->u18).reg)->id != 0x1f)))) ||
           ((t->next->op != 0x6e || (t->next->next->op != 0xae)))) goto switchD_10737d33_caseD_2;
        pcVar7 = pcVar10->src;
        if ((pcVar7->kind == '\x01') && (((pcVar7->u18).reg)->cls == '\x01')) {
          uVar13 = x87_reg_after_pop(((pcVar7->u18).reg)->id);
          pcVar7 = operand_new_hardreg(uVar13,uVar16);
        }
        t->op = 0x5d;
        tuple_replace_src(t,t->src->next,pcVar7);
        pcVar14 = find_next_use_of_dst(t->next->next,(c2_operand **)&stack0x00000050);
        bVar5 = x86_fixed_reg_class(pcVar14);
        _fcomp_class = CONCAT31(in_stack_00000041,bVar5);
        set_condition_code(pcVar14,g_cond_swapped_operands[bVar5]);
        tuple_unlink_free(pcVar10);
        pcVar10 = next;
        break;
      case 0x5f:
        pcVar10 = x87_fold_fxch_into_load_order(t);
      }
      goto LAB_10737c64;
    }
    if ((g_opt_float_consistency == 0) && (t->prev->op == 99)) {
      pcVar7 = t->src;
      pcVar12 = t->prev->dst;
      if (((pcVar7->type == pcVar12->type) &&
          (((pcVar7->kind == '\x02' && (pcVar12->kind == '\x02')) &&
           (iVar11 = operand_compare(pcVar7,pcVar12), iVar11 == 0)))) &&
         ((t->src->type & 0xfff) != 10)) {
        pcVar14 = t->prev;
        pcVar14->op = 0x62;
        x87_fix_stack_effect_dsts(pcVar14);
        tuple_unlink_free(t);
        pcVar10 = next;
        goto LAB_10737c64;
      }
    }
    if ((t->src->kind != '\x01') || (((t->src->u18).reg)->cls != '\x01'))
    goto switchD_10737d33_caseD_2;
    pcVar10 = x87_eliminate_fld_stack_copy(t);
    goto LAB_10737c64;
  }
  if (0x18b < uVar3) goto code_r0x107386f1;
  if (uVar3 == 0x18b) goto switchD_107386f9_caseD_192;
  if (0x119 < uVar3) {
    if (uVar3 == 0x11a) {
      if (t->dst->kind != '\x01') {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\finlower.c",0xe8);
      }
      t->op = 0x34;
      node_free((c2_node *)t->src);
      pcVar7 = (c2_operand *)node_clone((c2_node *)t->dst);
      t->src = pcVar7;
      pcVar7 = (c2_operand *)node_clone((c2_node *)t->dst);
      t->src->next = pcVar7;
      goto switchD_10737d33_caseD_2;
    }
    if (uVar3 == 0x166) {
      iVar11 = expand_multi_op_pseudo(t);
      if (iVar11 == 0) goto switchD_10737d33_caseD_2;
      tuple_unlink_free(t);
      pcVar10 = next;
    }
    else {
      if (uVar3 != 0x187) goto switchD_10737d33_caseD_2;
      pcVar6 = operand_new_intconst(0x1004,0,0);
      pcVar14 = tuple_new_exit(8,0x1004,(c2_operand *)0x0,pcVar6,tuple_insert_after,t);
      pcVar7 = operand_new_hardreg(1,0x1004);
      tuple_append_src(pcVar14,pcVar7);
      pcVar7 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(pcVar14,pcVar7);
      insert_fn = tuple_insert_after;
      pcVar4 = t->src->sym;
      puVar1 = (uint *)((int)&pcVar4->copy_equivs + 2);
      *puVar1 = *puVar1 | 1;
      pcVar14 = t;
      pcVar7 = operand_new_codeaddr(0x153,pcVar4);
      pcVar12 = operand_new_hardreg(1,0x1004);
      tuple_new(1,0x1004,pcVar12,pcVar7,insert_fn,pcVar14);
      tuple_unlink_free(t);
      pcVar10 = next;
    }
    goto LAB_10737c64;
  }
  if (uVar3 == 0x119) {
    pcVar7 = t->src;
    t->op = 0x31;
    pcVar12 = (c2_operand *)node_clone((c2_node *)t->dst);
    t->src = pcVar12;
    pcVar12 = (c2_operand *)node_clone((c2_node *)t->dst);
    t->src->next = pcVar12;
    pcVar12->next = pcVar7;
    if (pcVar7 == (c2_operand *)0x0) goto LAB_10737d96;
    goto switchD_10737d33_caseD_2;
  }
  switch(uVar3) {
  case 99:
    pcVar10 = t->prev;
    for (pcVar9 = pcVar10;
        (((pcVar9->op == 0x32 && (pcVar9->src->kind == '\x01')) &&
         ((pcVar9->src->u18).reg == g_reg_symbols + 5)) || (pcVar9->op == 0xd));
        pcVar9 = pcVar9->prev) {
    }
    if ((((pcVar9->op == 0x60) && (pcVar9->src->kind == '\x01')) &&
        (pcVar4 = (pcVar9->src->u18).reg, pcVar4->cls == '\x01')) && (pcVar4->id == 0x1f)) {
      pcVar7 = t->dst;
      t->op = 0x62;
      if (pcVar7->kind == '\x01') {
        (pcVar7->u18).reg = (c2_symbol *)(&g_pdb_il_module_index + ((pcVar7->u18).reg)->id * 0x15);
      }
      x87_fix_stack_effect_dsts(t);
      tuple_unlink_free(pcVar9);
      pcVar10 = next;
      goto LAB_10737c64;
    }
    if (((t->dst->kind != '\x01') || (pcVar4 = (t->dst->u18).reg, pcVar4->cls != '\x01')) ||
       (pcVar4->id != 0x1f)) goto switchD_10737d33_caseD_2;
    if (pcVar10->op == 0x6e) {
      pcVar10 = pcVar10->prev;
    }
    if ((pcVar10->op == 0x5c) && ((1 << (pcVar10->src->next->kind & 0x1f) & 0x60U) != 0)) {
      pcVar10->op = 0x5d;
      pcVar7 = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
      break;
    }
    if ((pcVar10->op != 0x62) || ((1 << (pcVar10->dst->kind & 0x1f) & 0x60U) == 0))
    goto switchD_10737d33_caseD_2;
    pcVar10->op = 99;
    pcVar7 = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
    break;
  default:
    goto switchD_10737d33_caseD_2;
  case 0xae:
    if (g_opt_favor_speed != 0) {
      sahf_to_test_ah(t);
    }
    goto switchD_10737d33_caseD_2;
  case 0xc2:
  case 0xc3:
    if (((((g_opt_cpu_target != 6) && (g_opt_favor_speed == 0)) || (flags_live != (c2_symbol *)0x0))
        || ((pcVar7 = t->dst, pcVar7->kind != '\x01' || (pcVar7->next != (c2_operand *)0x0)))) ||
       ((t->src->kind != '\x01' ||
        (pcVar7 = find_src_overlapping_reg(t,(pcVar7->u18).reg), pcVar7 != (c2_operand *)0x0))))
    goto switchD_10737d33_caseD_2;
    iVar11 = substitution_allowed((t->dst->u18).reg,t->src->type & 0xfff,0);
    pcVar10 = next;
    if (iVar11 != 0) goto code_r0x1077cd69;
    goto LAB_10737c64;
  case 0x118:
    t->op = 0x2c;
    pcVar7 = t->src->next;
    pcVar12 = (c2_operand *)node_clone((c2_node *)t->dst);
    t->src = pcVar12;
    pcVar12 = (c2_operand *)node_clone((c2_node *)t->dst);
    t->src->next = pcVar12;
    pcVar12->next = pcVar7;
    goto switchD_10737d33_caseD_2;
  }
  goto LAB_10738749;
code_r0x107386f1:
  switch(uVar3) {
  case 0x18c:
    if (g_opt_global != 0) {
      if (pcVar9 == (c2_tuple *)0x0) {
        pcVar8 = label_symbol_new();
        pcVar9 = tuple_new_label(pcVar8);
        ret_label = pcVar9;
      }
      tuple_retarget(t,(c2_node *)pcVar9,0);
      pcVar10 = next;
      goto LAB_10737c64;
    }
    break;
  default:
    goto switchD_10737d33_caseD_2;
  case 0x192:
  case 0x195:
  case 0x197:
  case 0x19a:
  case 0x1a5:
    break;
  case 0x19e:
    pcVar7 = t->dst;
    if (((pcVar7 != (c2_operand *)0x0) && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
       (pcVar7->sym->def != (c2_tuple *)0x0)) {
      pcVar10 = find_next_use_of_dst(t,(c2_operand **)&stack0x00000054);
      pcVar7 = operand_new_hardreg(((t->dst->u18).reg)->id,t->dst->type);
LAB_10738749:
      tuple_append_dst(pcVar10,pcVar7);
    }
    break;
  case 0x1a4:
    t->op = 0x145;
    tuple_unlink_free(t);
    pcVar10 = next;
    goto LAB_10737c64;
  }
switchD_107386f9_caseD_192:
  tuple_unlink_free(t);
  pcVar10 = next;
  goto LAB_10737c64;
code_r0x1077cd69:
  pcVar7 = t->dst;
  insert_fn_00 = tuple_insert_before;
  keep_ret = (int)pcVar7;
  pcVar10 = t;
  pcVar12 = operand_new_hardreg(((pcVar7->u18).reg)->id,pcVar7->type);
  src1 = operand_new_hardreg(((pcVar7->u18).reg)->id,pcVar7->type);
  pcVar7 = operand_new_hardreg(((pcVar7->u18).reg)->id,pcVar7->type);
  pcVar10 = tuple_new_binary(0x34,t->dst->type,pcVar7,src1,pcVar12,insert_fn_00,pcVar10);
  set_flags_effects(pcVar10);
  t->op = 1;
  operand_retype(t->dst,t->src->type,0);
  t->type = t->src->type;
  goto switchD_10737d33_caseD_2;
  while (pcVar10 = pcVar10->next, pcVar10 != (c2_tuple *)0x0) {
LAB_1077c8e1:
    if (((pcVar10->flags & 1) != 0) &&
       (pcVar7 = find_src_symbol_ref(pcVar10,pcVar4), pcVar7 != (c2_operand *)0x0)) break;
  }
LAB_1077c8fe:
  later_ref = pcVar7;
  if ((later_ref->u18).reg != g_reg_symbols + 0x48) goto switchD_10737d33_caseD_2;
LAB_1077c90b:
  add_sub_const_to_inc_dec(t);
LAB_1073800e:
  if (((t->op == 0x32) && (t->dst->kind == '\x01')) &&
     (((t->dst->u18).reg == g_reg_symbols + 5 && (pcVar7 = t->src->next, pcVar7->kind == '\a')))) {
    pcVar4 = (pcVar7->u18).reg;
    if (pcVar4 == (c2_symbol *)0x4) {
      pcVar14 = insert_push_reg(2,t);
      goto LAB_107381da;
    }
    if ((g_opt_favor_speed == 0) && (pcVar4 == (c2_symbol *)0x8)) {
      pcVar14 = insert_push_reg(2,t);
      next = insert_push_reg(2,pcVar14);
      goto LAB_107381da;
    }
  }
  if (((((t->op != 0x2d) || (t->dst->kind != '\x01')) || ((t->dst->u18).reg != g_reg_symbols + 5))
      || ((t->src->next->kind != '\a' || (pcVar10 = tuple_next_real(t), pcVar10 == (c2_tuple *)0x0))
         )) || (pcVar10->kind != '\x0f')) goto switchD_10737d33_caseD_2;
  pcVar4 = (t->src->next->u18).reg;
  if (pcVar4 == (c2_symbol *)0x4) {
    pcVar14 = insert_pop_reg(2,t);
  }
  else {
    if ((g_opt_favor_speed != 0) || (pcVar4 != (c2_symbol *)0x8)) goto switchD_10737d33_caseD_2;
    pcVar14 = insert_pop_reg(2,t);
    next = insert_pop_reg(2,pcVar14);
  }
LAB_107381da:
  tuple_unlink_free(t);
  goto switchD_10737d33_caseD_2;
LAB_1073826f:
  t_00 = pcVar9;
  if (t_00 == (c2_tuple *)0x0) goto LAB_107382b9;
  if (((t_00->flags & 1) == 0) ||
     (((((t_00->op != 1 || (t_00->dst->kind != '\x01')) || (t_00->src->kind != '\x01')) ||
       ((t_00->dst->u18).reg != (t_00->src->u18).reg)) && (t_00->op != 0x19e)))) goto LAB_107382ab;
  pcVar9 = tuple_next_real_in_block(t_00);
  pcVar10 = t_00;
  goto LAB_1073826f;
LAB_107382ab:
  iVar11 = 0;
  if (t_00 != (c2_tuple *)0x0) {
    while (((t_00->kind == '\x11' && ((t_00->u20).cond_cells == (c2_cond_cell *)0x0)) &&
           ((t_00->op != 0x18b && (t_00->op != 0x18c))))) {
      keep_ret = 1;
      pcVar10 = *(c2_tuple **)((int)&t_00->src->sym->u30 + 2);
      t_00 = tuple_next_real(pcVar10);
      if ((4 < iVar11) || (iVar11 = iVar11 + 1, t_00 == (c2_tuple *)0x0)) break;
    }
  }
LAB_107382b9:
  for (scan = pcVar10->next; scan != (c2_tuple *)0x0; scan = scan->next) {
    if (scan->kind == '\x1a') {
      keep_ret = 1;
    }
    else if ((scan->flags & 1) != 0) {
      if ((scan != (c2_tuple *)0x0) &&
         (((((scan->op == 8 && (pcVar7 = scan->src, pcVar7 != (c2_operand *)0x0)) &&
            (pcVar7->kind == '\a')) && ((pcVar7->u18).reg == (c2_symbol *)0x0 && pcVar7->tag == 0))
          || (scan->op == 0x18c)))) {
LAB_10738300:
        pcVar10 = scan;
        pcVar14 = tuple_new_branch(0x10,'\0',(c2_node *)t->src,(c2_operand *)0x0,(c2_tuple *)0x0,
                                   tuple_insert_before,t);
        tuple_unlink_free(t);
        if (keep_ret == 0) {
          tuple_unlink_free(pcVar10);
        }
        next = pcVar14->next;
      }
      break;
    }
  }
  goto switchD_10737d33_caseD_2;
}

