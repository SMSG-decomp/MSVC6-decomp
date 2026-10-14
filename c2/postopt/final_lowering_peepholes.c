void __fastcall final_lowering_peepholes(c2_function *fn)

{
  uint *puVar1;
  ushort uVar2;
  c2_symbol *pcVar3;
  uint uVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_fe_symbol *pcVar7;
  c2_tuple *t;
  c2_tuple *pcVar8;
  c2_float_const *a;
  c2_tuple *next;
  int iVar9;
  c2_operand *pcVar10;
  c2_tuple *pcVar11;
  uint32_t uVar12;
  c2_operand *src1;
  c2_const_operand *pcVar13;
  c2_symbol *pcVar14;
  uint16_t uVar15;
  c2_tuple *pcVar16;
  uint64_t uVar17;
  code *insert_fn_00;
  c2_symbol *pcVar18;
  c2_operand *in_stack_ffffffc0;
  c2_operand *in_stack_ffffffc4;
  c2_operand *in_stack_ffffffc8;
  uint32_t size;
  c2_operand *in_stack_ffffffd0;
  c2_tuple *in_stack_ffffffd4;
  uint32_t shift;
  c2_operand *pcStack_20;
  c2_function *fn_00;
  c2_cfg *cfg;
  c2_operand *pcStack_8;
  c2_operand *pcStack_4;
  c2_tuple *return_label;
  c2_symbol *flags_live_sym;
  c2_insert_fn *insert_fn;
  uint8_t fcomp_cc;
  uint8_t fcompp_cc;
  c2_tuple *end;
  uint32_t src_lo;
  
  pcVar16 = (c2_tuple *)0x0;
  pcVar18 = (c2_symbol *)0x0;
  return_label = (c2_tuple *)0x0;
  size = 0;
  shift = 0;
  fn_00 = fn;
  merge_esp_adjustments(fn);
  if (g_opt_cpu_target == 6) {
    narrow_logical_immediates(fn);
    final_peepholes_walk(fn);
  }
  cfg = fn->cfg;
  end = cfg->last->end;
  pcVar6 = cfg->first->head->next;
  if (pcVar6 != end) {
    do {
      next = pcVar6->next;
      if ((pcVar6->flags & 1) == 0) goto LAB_10737c64;
      uVar2 = pcVar6->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      pcVar5 = find_src_overlapping_reg(pcVar6,g_reg_symbols + 0x42);
      if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
         (pcVar5->sym->def != (c2_tuple *)0x0)) {
        pcVar18 = (c2_symbol *)0x0;
      }
      pcVar5 = find_dst_clobbering_reg(pcVar6,g_reg_symbols + 0x42);
      flags_live_sym = pcVar18;
      if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
         (pcVar5->sym->def != (c2_tuple *)0x0)) {
        flags_live_sym = pcVar5->sym;
      }
      if (pcVar6->src != (c2_operand *)0x0) {
        rewrite_index_times_two_as_base(pcVar6,pcVar6->src);
        swap_ebp_base_with_index(pcVar6,pcVar6->src,1);
        pcVar5 = pcVar6->src->next;
        if (pcVar5 != (c2_operand *)0x0) {
          swap_ebp_base_with_index(pcVar6,pcVar5,1);
        }
      }
      if (pcVar6->dst != (c2_operand *)0x0) {
        swap_ebp_base_with_index(pcVar6,pcVar6->dst,0);
      }
      uVar4 = pcVar6->op;
      pcVar11 = pcVar6;
      pcVar18 = flags_live_sym;
      if (0x60 < uVar4) {
        if (uVar4 < 0x18c) {
          if (uVar4 != 0x18b) {
            if (uVar4 < 0x11a) {
              if (uVar4 == 0x119) {
                pcVar5 = pcVar6->src;
                pcVar6->op = 0x31;
                pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                pcVar6->src = pcVar10;
                pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                pcVar6->src->next = pcVar10;
                pcVar10->next = pcVar5;
                pcVar18 = flags_live_sym;
                if (pcVar5 == (c2_operand *)0x0) goto LAB_10737d96;
              }
              else {
                switch(uVar4) {
                case 99:
                  pcVar16 = pcVar6->prev;
                  for (pcVar8 = pcVar16;
                      (((pcVar8->op == 0x32 && (pcVar8->src->kind == '\x01')) &&
                       ((pcVar8->src->u18).reg == g_reg_symbols + 5)) || (pcVar8->op == 0xd));
                      pcVar8 = pcVar8->prev) {
                  }
                  if (((pcVar8->op == 0x60) && (pcVar8->src->kind == '\x01')) &&
                     ((pcVar3 = (pcVar8->src->u18).reg, pcVar3->cls == '\x01' &&
                      (pcVar3->id == 0x1f)))) {
                    pcVar5 = pcVar6->dst;
                    pcVar6->op = 0x62;
                    if (pcVar5->kind == '\x01') {
                      (pcVar5->u18).reg =
                           (c2_symbol *)(&g_pdb_il_module_index + ((pcVar5->u18).reg)->id * 0x15);
                    }
                    x87_fix_stack_effect_dsts(pcVar6);
                    tuple_unlink_free(pcVar8);
                    pcVar18 = flags_live_sym;
                    goto LAB_10737c64;
                  }
                  if (((pcVar6->dst->kind == '\x01') &&
                      (pcVar3 = (pcVar6->dst->u18).reg, pcVar3->cls == '\x01')) &&
                     (pcVar3->id == 0x1f)) {
                    if (pcVar16->op == 0x6e) {
                      pcVar16 = pcVar16->prev;
                    }
                    if ((pcVar16->op == 0x5c) &&
                       ((1 << (pcVar16->src->next->kind & 0x1f) & 0x60U) != 0)) {
                      pcVar16->op = 0x5d;
                      pcVar5 = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,
                                               g_reg_symbols + 0x1f);
                    }
                    else {
                      if ((pcVar16->op != 0x62) || ((1 << (pcVar16->dst->kind & 0x1f) & 0x60U) == 0)
                         ) break;
                      pcVar16->op = 99;
                      pcVar5 = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,
                                               g_reg_symbols + 0x1f);
                    }
LAB_10738749:
                    tuple_append_dst(pcVar16,pcVar5);
                    goto switchD_107386f9_caseD_192;
                  }
                  break;
                case 0xae:
                  if (g_opt_favor_speed != 0) {
                    sahf_to_test_ah(pcVar6);
                    pcVar18 = flags_live_sym;
                  }
                  break;
                case 0xc2:
                case 0xc3:
                  if (((g_opt_cpu_target == 6) || (g_opt_favor_speed != 0)) &&
                     (((flags_live_sym == (c2_symbol *)0x0 &&
                       (((pcVar5 = pcVar6->dst, pcVar5->kind == '\x01' &&
                         (pcVar5->next == (c2_operand *)0x0)) && (pcVar6->src->kind == '\x01')))) &&
                      (pcVar5 = find_src_overlapping_reg(pcVar6,(pcVar5->u18).reg),
                      pcVar18 = flags_live_sym, pcVar5 == (c2_operand *)0x0)))) {
                    iVar9 = substitution_allowed((pcVar6->dst->u18).reg,pcVar6->src->type & 0xfff,0)
                    ;
                    pcVar18 = flags_live_sym;
                    if (iVar9 == 0) goto LAB_10737c64;
                    pcVar5 = pcVar6->dst;
                    insert_fn_00 = tuple_insert_before;
                    pcVar16 = pcVar6;
                    in_stack_ffffffc0 = pcVar5;
                    pcVar10 = operand_new_hardreg(((pcVar5->u18).reg)->id,pcVar5->type);
                    src1 = operand_new_hardreg(((pcVar5->u18).reg)->id,pcVar5->type);
                    pcVar5 = operand_new_hardreg(((pcVar5->u18).reg)->id,pcVar5->type);
                    pcVar16 = tuple_new_binary(0x34,pcVar6->dst->type,pcVar5,src1,pcVar10,
                                               insert_fn_00,pcVar16);
                    set_flags_effects(pcVar16);
                    pcVar6->op = 1;
                    operand_retype(pcVar6->dst,pcVar6->src->type,0);
                    pcVar6->type = pcVar6->src->type;
                    pcVar18 = flags_live_sym;
                  }
                  break;
                case 0x118:
                  pcVar6->op = 0x2c;
                  pcVar5 = pcVar6->src->next;
                  pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                  pcVar6->src = pcVar10;
                  pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                  pcVar6->src->next = pcVar10;
                  pcVar10->next = pcVar5;
                  pcVar18 = flags_live_sym;
                }
              }
            }
            else {
              if (uVar4 != 0x11a) {
                if (uVar4 == 0x166) {
                  iVar9 = expand_multi_op_pseudo(pcVar6);
                  pcVar18 = flags_live_sym;
                  if (iVar9 == 0) goto switchD_10737d33_caseD_2;
                  tuple_unlink_free(pcVar6);
                  pcVar18 = flags_live_sym;
                }
                else {
                  if (uVar4 != 0x187) goto switchD_10737d33_caseD_2;
                  pcVar13 = operand_new_intconst(0x1004,0,0);
                  pcVar16 = tuple_new_exit(8,0x1004,(c2_operand *)0x0,pcVar13,tuple_insert_after,
                                           pcVar6);
                  pcVar5 = operand_new_hardreg(1,0x1004);
                  tuple_append_src(pcVar16,pcVar5);
                  pcVar5 = operand_new_hardreg(0x42,0x8000);
                  tuple_append_dst(pcVar16,pcVar5);
                  insert_fn = tuple_insert_after;
                  pcVar18 = pcVar6->src->sym;
                  puVar1 = (uint *)((int)&pcVar18->copy_equivs + 2);
                  *puVar1 = *puVar1 | 1;
                  pcVar16 = pcVar6;
                  pcVar5 = operand_new_codeaddr(0x153,pcVar18);
                  pcVar10 = operand_new_hardreg(1,0x1004);
                  tuple_new(1,0x1004,pcVar10,pcVar5,insert_fn,pcVar16);
                  tuple_unlink_free(pcVar6);
                  pcVar18 = flags_live_sym;
                }
                goto LAB_10737c64;
              }
              if (pcVar6->dst->kind != '\x01') {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\finlower.c",0xe8);
              }
              pcVar6->op = 0x34;
              node_free((c2_node *)pcVar6->src);
              pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
              pcVar6->src = pcVar5;
              pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
              pcVar6->src->next = pcVar5;
              pcVar18 = flags_live_sym;
            }
            goto switchD_10737d33_caseD_2;
          }
          goto switchD_107386f9_caseD_192;
        }
        switch(uVar4) {
        case 0x18c:
          if (g_opt_global == 0) goto switchD_107386f9_caseD_192;
          if (pcVar16 == (c2_tuple *)0x0) {
            pcVar7 = label_symbol_new();
            pcVar16 = tuple_new_label(pcVar7);
            pcVar18 = flags_live_sym;
            return_label = pcVar16;
          }
          tuple_retarget(pcVar6,(c2_node *)pcVar16,0);
          break;
        default:
          goto switchD_10737d33_caseD_2;
        case 0x19e:
          pcVar5 = pcVar6->dst;
          if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
             (pcVar5->sym->def != (c2_tuple *)0x0)) {
            pcVar16 = find_next_use_of_dst(pcVar6,&pcStack_4);
            pcVar5 = operand_new_hardreg(((pcVar6->dst->u18).reg)->id,pcVar6->dst->type);
            goto LAB_10738749;
          }
        case 0x192:
        case 0x195:
        case 0x197:
        case 0x19a:
        case 0x1a5:
switchD_107386f9_caseD_192:
          tuple_unlink_free(pcVar6);
          pcVar18 = flags_live_sym;
          break;
        case 0x1a4:
          pcVar6->op = 0x145;
          tuple_unlink_free(pcVar6);
          pcVar18 = flags_live_sym;
        }
        goto LAB_10737c64;
      }
      if (uVar4 == 0x60) {
        if ((g_opt_float_consistency == 0) && (pcVar6->prev->op == 99)) {
          pcVar5 = pcVar6->src;
          pcVar10 = pcVar6->prev->dst;
          if ((pcVar5->type == pcVar10->type) &&
             ((((pcVar5->kind == '\x02' && (pcVar10->kind == '\x02')) &&
               (iVar9 = operand_compare(pcVar5,pcVar10), iVar9 == 0)) &&
              ((pcVar6->src->type & 0xfff) != 10)))) {
            pcVar16 = pcVar6->prev;
            pcVar16->op = 0x62;
            x87_fix_stack_effect_dsts(pcVar16);
            tuple_unlink_free(pcVar6);
            pcVar18 = flags_live_sym;
            goto LAB_10737c64;
          }
        }
        pcVar18 = flags_live_sym;
        if ((pcVar6->src->kind != '\x01') || (((pcVar6->src->u18).reg)->cls != '\x01'))
        goto switchD_10737d33_caseD_2;
        next = x87_eliminate_fld_stack_copy(pcVar6);
        pcVar18 = flags_live_sym;
        goto LAB_10737c64;
      }
      switch(uVar4) {
      case 1:
        pcVar5 = pcVar6->dst;
        if (pcVar5->kind == '\x01') {
          if (flags_live_sym == (c2_symbol *)0x0) {
            if (uVar4 == 1) {
              in_stack_ffffffc8 = pcVar6->src;
              in_stack_ffffffc4 = pcVar5;
            }
            pcVar5 = pcVar6->src;
            if ((1 << (pcVar5->kind & 0x1f) & 0x380U) != 0) {
              if ((pcVar5->u18).reg == (c2_symbol *)0x0) {
                pcVar6->op = 0x34;
                node_free((c2_node *)pcVar5);
                pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                pcVar6->src = pcVar5;
                pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                pcVar6->src->next = pcVar5;
              }
              else {
                pcVar5 = pcVar6->src;
                uVar17 = const_normalize(pcVar5->type,0xffffffff,-1);
                if ((pcVar5->u18).reg != (c2_symbol *)uVar17) goto LAB_10737c3d;
                pcVar6->op = 0x30;
                pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar6->dst);
                pcVar6->src = pcVar10;
                pcVar10->next = pcVar5;
              }
LAB_10737d96:
              pcVar5 = operand_new_hardreg(0x42,0x8000);
              tuple_append_dst(pcVar6,pcVar5);
              pcVar18 = flags_live_sym;
              break;
            }
            iVar9 = final_op_is_simple_alu(pcVar6->prev);
            if (((iVar9 != 0) && (pcVar5 = pcVar6->src, pcVar5->next == (c2_operand *)0x0)) &&
               ((pcVar5->kind == '\x01' &&
                ((pcVar5->sym->cls == '\x03' && (pcVar5->sym->def != (c2_tuple *)0x0)))))) {
              pcVar16 = pcVar6->prev;
              if ((pcVar16->dst->kind == '\x01') &&
                 (pcVar10 = pcVar16->src->next, pcVar10->kind == '\x01')) {
                pcVar18 = (pcVar6->dst->u18).reg;
                if ((((pcVar18 != (pcVar5->u18).reg) &&
                     ((pcVar16->dst->u18).reg == (pcVar5->u18).reg)) &&
                    (pcVar18 == (pcVar10->u18).reg)) && (pcVar6->dst->next == (c2_operand *)0x0)) {
                  tuple_swap_first_srcs(pcVar16);
                  pcVar5 = pcVar16->dst;
                  pcVar10 = operand_new_hardreg(((pcVar16->src->u18).reg)->id,pcVar5->type);
                  tuple_replace_dst(pcVar16,pcVar5,pcVar10);
                  pcVar5 = operand_new_hardreg(((pcVar16->dst->u18).reg)->id,pcVar6->src->type);
                  tuple_replace_src(pcVar6,pcVar6->src,pcVar5);
                  goto LAB_10737c3d;
                }
              }
            }
            if ((((in_stack_ffffffc4->kind == '\x01') && (in_stack_ffffffc8->kind == '\x01')) &&
                ((in_stack_ffffffc8->sym->cls == '\r' &&
                 ((pcVar5 = (in_stack_ffffffc8->sym->u28).const_operand, pcVar5->kind == '\a' &&
                  ((pcVar5->u18).reg == (c2_symbol *)0x0 && pcVar5->tag == 0)))))) &&
               ((in_stack_ffffffc4->u18).reg != (in_stack_ffffffc8->u18).reg)) {
              pcVar6->op = 0x34;
              tuple_replace_src(pcVar6,in_stack_ffffffc8,pcVar6->dst);
              tuple_append_src(pcVar6,pcVar6->dst);
              set_flags_effects(pcVar6);
              pcVar18 = flags_live_sym;
              break;
            }
          }
LAB_10737c3d:
          pcVar5 = pcVar6->src;
          if ((pcVar5->kind == '\x01') && ((pcVar6->dst->u18).reg == (pcVar5->u18).reg)) {
            pcVar11 = pcVar6->prev;
            tuple_unlink_free(pcVar11->next);
            pcVar18 = flags_live_sym;
          }
          else {
            pcVar18 = flags_live_sym;
            if ((g_opt_favor_speed == 0) &&
               (((pcVar5->kind == '\a' && ((pcVar6->type & 0xfff) == 4)) &&
                ((pcVar5->u18).reg == (c2_symbol *)(int)*(char *)&pcVar5->u18)))) {
              insert_fn = tuple_insert_after;
              pcVar16 = pcVar6;
              pcVar10 = operand_new_hardreg(5,0x1004);
              pcVar13 = operand_new_intconst(0x1004,(pcVar5->u18).lo,pcVar5->tag);
              pcVar5 = operand_new_hardreg(5,0x1004);
              pcVar16 = tuple_new_binary(0xd,0x1004,pcVar5,pcVar13,pcVar10,insert_fn,pcVar16);
              pcVar11 = insert_pop_reg(((pcVar6->dst->u18).reg)->id,pcVar16);
              pcVar18 = flags_live_sym;
              goto LAB_107381da;
            }
          }
        }
        else if (((g_opt_favor_speed == 0) && (flags_live_sym == (c2_symbol *)0x0)) &&
                ((pcVar10 = pcVar6->src, (1 << (pcVar10->kind & 0x1f) & 0x380U) != 0 &&
                 ((pcVar5->flags & 0x40) == 0)))) {
          src_lo = (pcVar10->u18).lo;
          if (src_lo == 0) {
            uVar15 = pcVar6->type;
            uVar12 = 0x2e;
          }
          else {
            uVar17 = const_normalize(pcVar10->type,0xffffffff,-1);
            pcVar18 = flags_live_sym;
            if (src_lo != (uint32_t)uVar17) break;
            pcVar10 = pcVar6->src;
            pcVar5 = pcVar6->dst;
            uVar15 = pcVar6->type;
            uVar12 = 0x30;
          }
          pcVar11 = tuple_new_binary(uVar12,uVar15,pcVar5,pcVar5,pcVar10,(c2_insert_fn *)0x0,
                                     (c2_tuple *)0x0);
          tuple_replace(pcVar6,(c2_node *)pcVar11);
          pcVar5 = operand_new_hardreg(0x42,0x8000);
          tuple_append_dst(pcVar11,pcVar5);
        }
        break;
      case 0xe:
        if (((g_opt_favor_speed == 0) && (next->op == 0x2d)) &&
           ((next->dst->kind == '\x01' &&
            (((next->dst->u18).reg == g_reg_symbols + 5 &&
             (pcVar5 = next->src->next, pcVar5->kind == '\a')))))) {
          pcVar18 = (pcVar5->u18).reg;
          if (pcVar18 == (c2_symbol *)0x4) {
            tuple_unlink_free(next);
          }
          else {
            if (pcVar18 != (c2_symbol *)0x8) goto LAB_10738232;
            tuple_unlink_free(next);
            insert_pop_reg(2,pcVar6);
          }
          next = insert_pop_reg(2,pcVar6);
        }
LAB_10738232:
        pcVar18 = flags_live_sym;
        if ((g_opt_global != 0) && ((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0)) {
          pcVar7 = call_target_function_symbol(pcVar6);
          if ((pcVar7 == (c2_fe_symbol *)0x0) || ((pcVar7->attrs & 0x80) == 0)) {
            in_stack_ffffffc0 = (c2_operand *)0x0;
            t = tuple_next_real_in_block(pcVar6);
            pcVar8 = t;
            pcVar16 = pcVar6;
            if (flags_live_sym == (c2_symbol *)0x0) {
              while (t = pcVar8, t != (c2_tuple *)0x0) {
                if (((t->flags & 1) == 0) ||
                   (((((t->op != 1 || (t->dst->kind != '\x01')) || (t->src->kind != '\x01')) ||
                     ((t->dst->u18).reg != (t->src->u18).reg)) && (t->op != 0x19e))))
                goto LAB_107382ab;
                pcVar8 = tuple_next_real_in_block(t);
                pcVar16 = t;
              }
            }
            else {
LAB_107382ab:
              iVar9 = 0;
              if (t != (c2_tuple *)0x0) {
                while (((t->kind == '\x11' && ((t->u20).cond_cells == (c2_cond_cell *)0x0)) &&
                       ((t->op != 0x18b && (t->op != 0x18c))))) {
                  in_stack_ffffffc0 = (c2_operand *)0x1;
                  pcVar16 = *(c2_tuple **)((int)&t->src->sym->u30 + 2);
                  t = tuple_next_real(pcVar16);
                  if ((4 < iVar9) || (iVar9 = iVar9 + 1, t == (c2_tuple *)0x0)) break;
                }
              }
            }
            for (in_stack_ffffffd4 = pcVar16->next; pcVar18 = flags_live_sym,
                in_stack_ffffffd4 != (c2_tuple *)0x0; in_stack_ffffffd4 = in_stack_ffffffd4->next) {
              if (in_stack_ffffffd4->kind == '\x1a') {
                in_stack_ffffffc0 = (c2_operand *)0x1;
              }
              else if ((in_stack_ffffffd4->flags & 1) != 0) {
                if ((in_stack_ffffffd4 != (c2_tuple *)0x0) &&
                   (((((in_stack_ffffffd4->op == 8 &&
                       (pcVar5 = in_stack_ffffffd4->src, pcVar5 != (c2_operand *)0x0)) &&
                      (pcVar5->kind == '\a')) &&
                     ((pcVar5->u18).reg == (c2_symbol *)0x0 && pcVar5->tag == 0)) ||
                    (in_stack_ffffffd4->op == 0x18c)))) goto LAB_10738300;
                break;
              }
            }
          }
          else {
            pcVar16 = tuple_find_next_kind_in_block(pcVar6,'\x11');
            if (pcVar16->op == 0x18c) {
              tuple_unlink_free(pcVar16);
            }
            in_stack_ffffffc0 = (c2_operand *)0x1;
LAB_10738300:
            pcVar16 = in_stack_ffffffd4;
            pcVar11 = tuple_new_branch(0x10,'\0',(c2_node *)pcVar6->src,(c2_operand *)0x0,
                                       (c2_tuple *)0x0,tuple_insert_before,pcVar6);
            tuple_unlink_free(pcVar6);
            pcVar18 = flags_live_sym;
            if (in_stack_ffffffc0 == (c2_operand *)0x0) {
              tuple_unlink_free(in_stack_ffffffd4);
              pcVar18 = flags_live_sym;
            }
            in_stack_ffffffd4 = pcVar16;
            next = pcVar11->next;
          }
        }
        break;
      case 0x12:
        pcVar5 = pcVar6->src;
        if ((pcVar5->kind == '\x05') &&
           ((pcVar5->base_sym == (c2_symbol *)0x0 && (flags_live_sym == (c2_symbol *)0x0)))) {
          uVar12 = pcVar5->op;
          if ((uVar12 == 0x14c) && ((pcVar5->base->u18).reg == (pcVar6->dst->u18).reg)) {
            uVar12 = pcVar5->disp;
            tuple_replace_src(pcVar6,pcVar5,pcVar6->dst);
            if (uVar12 == 0xffffffff) {
              pcVar6->op = 0x1e;
            }
            else if (uVar12 == 1) {
              pcVar6->op = 0x21;
            }
            else {
              pcVar6->op = 0x2d;
              pcVar13 = operand_new_intconst(0x1004,uVar12,(int)uVar12 >> 0x1f);
              tuple_append_src(pcVar6,pcVar13);
            }
            iVar9 = fold_adjacent_reg_arith(pcVar6,(c2_tuple **)&stack0xffffffb8);
            pcVar18 = flags_live_sym;
            if (iVar9 != 0) goto LAB_10737c64;
            set_flags_effects(pcVar6);
            pcVar18 = flags_live_sym;
          }
          else if (((uVar12 == 0x14d) && (pcVar5->disp == 0)) && ((pcVar5->flags & 0xf) == 0)) {
            pcVar10 = pcVar6->dst;
            pcVar3 = (pcVar5->base->u18).reg;
            if (pcVar3 == (pcVar10->u18).reg) {
              uVar12 = ((pcVar5->index->u18).reg)->id;
            }
            else {
              if ((pcVar5->index->u18).reg != (pcVar10->u18).reg) {
                if (((next != (c2_tuple *)0x0) && (next->op == 0x32)) &&
                   (((next->src->next->kind == '\x01' &&
                     (iVar9 = operand_lists_equal(pcVar10,next->dst), pcVar18 = flags_live_sym,
                     iVar9 != 0)) &&
                    (((pcVar5 = find_dst_clobbering_reg(next,g_reg_symbols + 0x42),
                      pcVar18 = flags_live_sym, pcVar5 == (c2_operand *)0x0 ||
                      ((1 << (pcVar5->kind & 0x1f) & 6U) == 0)) ||
                     (pcVar5->sym->def == (c2_tuple *)0x0)))))) {
                  pcVar5 = pcVar6->src;
                  pcVar14 = (pcVar5->base->u18).reg;
                  pcVar3 = (next->src->next->u18).reg;
                  if (pcVar14 == pcVar3) {
                    pcVar14 = (pcVar5->index->u18).reg;
                  }
                  else if ((pcVar5->index->u18).reg != pcVar3) break;
                  uVar12 = pcVar14->id;
                  pcVar6->op = 1;
                  pcVar10 = operand_new_hardreg(uVar12,0x1004);
                  tuple_replace_src(pcVar6,pcVar5,pcVar10);
                  tuple_unlink_free(next);
                  next = pcVar6;
                  pcVar18 = flags_live_sym;
                }
                break;
              }
              uVar12 = pcVar3->id;
            }
            tuple_replace_src(pcVar6,pcVar5,pcVar10);
            pcVar6->op = 0x2d;
            pcVar5 = operand_new_hardreg(uVar12,0x1004);
            tuple_append_src(pcVar6,pcVar5);
            next = pcVar6;
            set_flags_effects(pcVar6);
            pcVar18 = flags_live_sym;
          }
          else if (((uVar12 == 0x14f) && (1 < (pcVar5->flags & 0xf))) && (pcVar5->disp == 0)) {
            uVar4 = pcVar5->flags & 0xf;
            if ((pcVar5->index->u18).reg == (pcVar6->dst->u18).reg) {
              tuple_replace_src(pcVar6,pcVar6->src,pcVar6->dst);
              pcVar6->op = 0x2a;
              pcVar13 = operand_new_intconst(pcVar6->type,uVar4,0);
              tuple_append_src(pcVar6,pcVar13);
              set_flags_effects(pcVar6);
              pcVar18 = flags_live_sym;
            }
            else {
              if (g_opt_favor_speed == 0) {
                tuple_new(1,pcVar6->type,pcVar6->dst,pcVar5->index,tuple_insert_before,pcVar6);
                final_lowering_peepholes_part
                          (uVar4,pcVar6,next,flags_live_sym,(int)in_stack_ffffffc0,in_stack_ffffffc4
                           ,in_stack_ffffffc8,size,in_stack_ffffffd0,in_stack_ffffffd4,return_label,
                           shift,fn_00,fcompp_cc,fcomp_cc,end,cfg);
                return;
              }
            }
          }
        }
        break;
      case 0x1e:
      case 0x21:
        if ((flags_live_sym != (c2_symbol *)0x0) ||
           (iVar9 = fold_adjacent_reg_arith(pcVar6,(c2_tuple **)&stack0xffffffb8),
           pcVar18 = flags_live_sym, iVar9 == 0)) break;
        goto LAB_10737c64;
      case 0x2d:
      case 0x32:
        if (flags_live_sym == (c2_symbol *)0x0) {
          if (((((next != (c2_tuple *)0x0) &&
                (next->op == (-(uint)(uVar4 != 0x2d) & 0xfffffffb) + 0x32)) &&
               (iVar9 = operand_lists_equal(pcVar6->dst,next->dst), iVar9 != 0)) &&
              (((1 << (pcVar6->dst->kind & 0x1f) & 0x7eU) == 0 || ((pcVar6->dst->flags & 0x40) == 0)
               ))) && ((((((1 << (next->dst->kind & 0x1f) & 0x7eU) == 0 ||
                          ((next->dst->flags & 0x40) == 0)) &&
                         (iVar9 = operand_lists_equal(pcVar6->src->next,next->src->next), iVar9 != 0
                         )) && (((pcVar5 = pcVar6->src->next,
                                 (1 << (pcVar5->kind & 0x1f) & 0x7eU) == 0 ||
                                 ((pcVar5->flags & 0x40) == 0)) &&
                                ((pcVar5 = next->src->next,
                                 (1 << (pcVar5->kind & 0x1f) & 0x7eU) == 0 ||
                                 ((pcVar5->flags & 0x40) == 0)))))) &&
                       (((pcVar5 = find_dst_clobbering_reg(next,g_reg_symbols + 0x42),
                         pcVar5 == (c2_operand *)0x0 || ((1 << (pcVar5->kind & 0x1f) & 6U) == 0)) ||
                        (pcVar5->sym->def == (c2_tuple *)0x0)))))) {
            pcVar16 = pcVar6->prev;
            tuple_unlink_free(pcVar6);
            tuple_unlink_free(next);
            next = pcVar16->next;
            goto LAB_10737c64;
          }
          if ((pcVar6->src->kind == '\x01') && (pcVar6->src->next->kind == '\a')) {
            iVar9 = fold_adjacent_reg_arith(pcVar6,(c2_tuple **)&stack0xffffffb8);
            if (iVar9 != 0) goto LAB_10737c64;
            if ((pcVar6->op != 0x2d) && (pcVar6->op != 0x32)) break;
          }
        }
        if ((g_opt_favor_speed == 0) &&
           (((pcVar6->src->kind == '\x01' && (pcVar6->src->next->kind == '\a')) &&
            ((pcVar6->type & 0xfff) == 4)))) {
          if (flags_live_sym != (c2_symbol *)0x0) {
            pcVar16 = pcVar6->next;
            while ((pcVar16 != (c2_tuple *)0x0 &&
                   (((pcVar16->flags & 1) == 0 ||
                    (in_stack_ffffffd0 = find_src_symbol_ref(pcVar16,flags_live_sym),
                    in_stack_ffffffd0 == (c2_operand *)0x0))))) {
              pcVar16 = pcVar16->next;
            }
            if ((in_stack_ffffffd0->u18).reg != g_reg_symbols + 0x48) break;
          }
          add_sub_const_to_inc_dec(pcVar6);
        }
        if (((pcVar6->op == 0x32) && (pcVar6->dst->kind == '\x01')) &&
           (((pcVar6->dst->u18).reg == g_reg_symbols + 5 &&
            (pcVar5 = pcVar6->src->next, pcVar5->kind == '\a')))) {
          pcVar3 = (pcVar5->u18).reg;
          if (pcVar3 == (c2_symbol *)0x4) {
            pcVar11 = insert_push_reg(2,pcVar6);
          }
          else {
            if ((g_opt_favor_speed != 0) || (pcVar3 != (c2_symbol *)0x8)) goto LAB_1073801a;
            pcVar11 = insert_push_reg(2,pcVar6);
            next = insert_push_reg(2,pcVar11);
          }
        }
        else {
LAB_1073801a:
          if ((pcVar6->op != 0x2d) ||
             ((((pcVar6->dst->kind != '\x01' || ((pcVar6->dst->u18).reg != g_reg_symbols + 5)) ||
               (pcVar6->src->next->kind != '\a')) ||
              ((pcVar16 = tuple_next_real(pcVar6), pcVar16 == (c2_tuple *)0x0 ||
               (pcVar16->kind != '\x0f')))))) break;
          pcVar3 = (pcVar6->src->next->u18).reg;
          if (pcVar3 == (c2_symbol *)0x4) {
            pcVar11 = insert_pop_reg(2,pcVar6);
          }
          else {
            if ((g_opt_favor_speed != 0) || (pcVar3 != (c2_symbol *)0x8)) break;
            pcVar11 = insert_pop_reg(2,pcVar6);
            next = insert_pop_reg(2,pcVar11);
          }
        }
LAB_107381da:
        tuple_unlink_free(pcVar6);
        break;
      case 0x2e:
      case 0x30:
      case 0x33:
        size = 0;
        if ((g_opt_cpu_target != 6) &&
           (iVar9 = narrow_immediate_operation
                              (pcVar6,(uint32_t *)&stack0xffffffcc,(uint32_t *)&stack0xffffffdc),
           pcVar18 = flags_live_sym, iVar9 != 0)) {
          narrow_and_or_constant(pcVar6,size,shift);
          pcVar18 = flags_live_sym;
        }
        break;
      case 0x2f:
        if (uVar4 == 0x2f) {
          in_stack_ffffffc8 = pcVar6->src;
          if (((in_stack_ffffffc8->kind == '\x01') && (in_stack_ffffffc8->sym->cls == '\r')) &&
             ((pcVar5 = (in_stack_ffffffc8->sym->u28).const_operand, pcVar5->kind == '\a' &&
              ((pcVar5->u18).reg == (c2_symbol *)0x0 && pcVar5->tag == 0)))) {
            in_stack_ffffffc4 = in_stack_ffffffc8->next;
          }
          else {
            in_stack_ffffffc4 = in_stack_ffffffc8;
            in_stack_ffffffc8 = in_stack_ffffffc8->next;
          }
        }
        pcVar5 = pcVar6->src;
        if (((pcVar5->kind == '\x01') && (pcVar10 = pcVar5->next, pcVar10->kind == '\a')) &&
           ((pcVar10->u18).reg == (c2_symbol *)0x0)) {
          pcVar6->op = 0x33;
          tuple_replace_src(pcVar6,pcVar10,pcVar5);
          pcVar18 = flags_live_sym;
        }
        break;
      case 0x45:
      case 0x47:
      case 0x48:
      case 0x49:
      case 0x4a:
        goto switchD_10737d33_caseD_45;
      case 0x46:
        pcVar5 = pcVar6->src;
        pcVar10 = pcVar5->next;
        if (((pcVar10->op == 0x14b) &&
            (a = float_constant_pool_lookup(pcVar10->sym->fe), a != (c2_float_const *)0x0)) &&
           (iVar9 = float_const_compare_mask(1,a,&g_ld_const_two), iVar9 != 0)) {
          pcVar6->op = 0x45;
          tuple_replace_src(pcVar6,pcVar10,pcVar5);
        }
        goto switchD_10737d33_caseD_45;
      case 0x4b:
      case 0x4c:
      case 0x4d:
      case 0x4e:
      case 0x4f:
      case 0x50:
        goto switchD_10737d33_caseD_4b;
      case 0x5d:
        pcVar16 = pcVar6->prev;
        if (pcVar16->op != 0x60) break;
        if (((pcVar16->src->kind == '\x01') &&
            (pcVar3 = (pcVar16->src->u18).reg, pcVar3->cls == '\x01')) && (pcVar3->id == 0x1f)) {
          pcVar5 = pcVar6->src->next;
          if ((pcVar5->kind == '\x01') && (((pcVar5->u18).reg)->cls == '\x01')) {
            uVar12 = x87_reg_after_pop(((pcVar5->u18).reg)->id);
            pcVar5 = operand_new_hardreg(uVar12,pcVar5->type);
            tuple_replace_src(pcVar6,pcVar6->src->next,pcVar5);
          }
          tuple_replace_src(pcVar6,pcVar6->src,pcVar6->prev->src);
          pcVar6->op = 0x5c;
          x87_fix_stack_effect_dsts(pcVar6);
          tuple_unlink_free(pcVar6->prev);
          pcVar18 = flags_live_sym;
        }
        else {
          if (((((pcVar6->type != pcVar16->type) ||
                ((1 << (pcVar16->src->kind & 0x1f) & 0x60U) == 0)) ||
               ((pcVar5 = pcVar6->src, pcVar5->kind != '\x01' ||
                ((((pcVar5->u18).reg)->cls != '\x01' || (((pcVar5->u18).reg)->id != 0x1f)))))) ||
              (pcVar5->next->kind != '\x01')) ||
             ((pcVar3 = (pcVar5->next->u18).reg, pcVar3->cls != '\x01' || (pcVar3->id != 0x20))))
          break;
          pcVar6->op = 0x5c;
          x87_fix_stack_effect_dsts(pcVar6);
          tuple_replace_src(pcVar6,pcVar6->src->next,pcVar6->prev->src);
          tuple_unlink_free(pcVar6->prev);
          pcVar16 = find_next_use_of_dst(pcVar6,&pcStack_20);
          pcVar16 = find_next_use_of_dst(pcVar16,&pcStack_20);
          pcVar16 = find_next_use_of_dst(pcVar16,&pcStack_20);
          fcomp_cc = x86_fixed_reg_class(pcVar16);
          set_condition_code(pcVar16,g_cond_swapped_operands[fcomp_cc]);
          pcVar18 = flags_live_sym;
        }
        goto LAB_10737c64;
      case 0x5e:
        pcVar16 = pcVar6->prev;
        if ((((pcVar16->op != 0x60) ||
             ((uVar15 = pcVar6->type, uVar15 != pcVar16->type && (pcVar16->src->kind != '\x01'))))
            || ((pcVar16->src->kind == '\x01' && (((pcVar16->src->u18).reg)->id != 0x1f)))) ||
           ((pcVar6->next->op != 0x6e || (pcVar6->next->next->op != 0xae)))) break;
        pcVar5 = pcVar16->src;
        if ((pcVar5->kind == '\x01') && (((pcVar5->u18).reg)->cls == '\x01')) {
          uVar12 = x87_reg_after_pop(((pcVar5->u18).reg)->id);
          pcVar5 = operand_new_hardreg(uVar12,uVar15);
        }
        pcVar6->op = 0x5d;
        tuple_replace_src(pcVar6,pcVar6->src->next,pcVar5);
        pcVar6 = find_next_use_of_dst(pcVar6->next->next,&pcStack_8);
        fcompp_cc = x86_fixed_reg_class(pcVar6);
        set_condition_code(pcVar6,g_cond_swapped_operands[fcompp_cc]);
        tuple_unlink_free(pcVar16);
        pcVar18 = flags_live_sym;
        goto LAB_10737c64;
      case 0x5f:
        next = x87_fold_fxch_into_load_order(pcVar6);
        pcVar18 = flags_live_sym;
        goto LAB_10737c64;
      }
switchD_10737d33_caseD_2:
      delete_identity_alu_op(pcVar11,(int)pcVar18);
LAB_10737c64:
      fn = fn_00;
      pcVar16 = return_label;
      pcVar6 = next;
      return_label = pcVar16;
      fn_00 = fn;
    } while (pcVar6 != end);
    if (pcVar16 != (c2_tuple *)0x0) {
      pcVar6 = tuple_find_prev_of_kind(cfg->last->end,'\x18');
      tuple_insert_before(pcVar6,pcVar16);
    }
  }
  return;
switchD_10737d33_caseD_45:
  x87_fold_into_pop_form(pcVar6);
switchD_10737d33_caseD_4b:
  next = x87_arith_peephole(pcVar6);
  pcVar18 = flags_live_sym;
  goto LAB_10737c64;
}

