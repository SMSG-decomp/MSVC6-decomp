void __fastcall cxx_eh_lower_scopes(c2_function *fn)

{
  uint32_t *puVar1;
  byte bVar2;
  ushort uVar3;
  uint16_t uVar4;
  c2_tuple *first;
  c2_symbol *pcVar5;
  int iVar6;
  c2_tuple *chain_end;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  c2_tuple *next_real;
  c2_tuple *eh_pseudo;
  c2_operand *pcVar9;
  c2_eh_op_construct *pcVar10;
  c2_cxx_try_block *open_try;
  int local_18;
  uint local_10;
  c2_operand *local_8;
  c2_tuple *local_4;
  c2_cxx_try_block *try_head;
  
  open_try = (c2_cxx_try_block *)0x0;
  local_18 = 0;
  local_10 = 0;
  first = fn->cfg->first->head;
  pcVar8 = first;
  try_head = g_cxx_try_records;
  while (g_cxx_try_records = try_head, pcVar8 != (c2_tuple *)0x0) {
    local_4 = pcVar8->next;
    if ((pcVar8->flags & 1) != 0) {
      uVar3 = pcVar8->line;
      if (uVar3 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar3;
        g_cur_line = uVar3;
      }
      switch(pcVar8->op) {
      case 0x186:
        open_try = try_head;
        if ((try_head != (c2_cxx_try_block *)0x0) &&
           (*(int *)((int)&pcVar8->src->sym->u34 + 2) != try_head->index)) {
          if ((g_opt_eh_enabled == 0) && ((fn->flags & 8) != 0)) {
            tuple_new_intrinsic(400,0x400a,(c2_operand *)0x0,(c2_operand *)0x0,(c2_operand *)0x0,
                                (c2_operand *)0x0,(c2_operand *)0x0,0x185,tuple_insert_before,pcVar8
                               );
          }
          pcVar9 = pcVar8->src;
          next_real = tuple_next_real(*(c2_tuple **)((int)&pcVar9->sym->u30 + 2));
          if ((next_real != (c2_tuple *)0x0) && (next_real->op != 0x1a6)) {
            eh_pseudo = tuple_new_pseudo(0x1a9,0x1004);
            pcVar9 = (c2_operand *)node_clone((c2_node *)pcVar9);
            bVar2 = pcVar9->flags;
            eh_pseudo->src = pcVar9;
            pcVar9->flags = bVar2 | 0x10;
            pcVar10 = arena_alloc(1,0x10);
            pcVar10->object = g_eh_current_state;
            (eh_pseudo->u20).eh_construct = pcVar10;
            tuple_insert_before(pcVar8,eh_pseudo);
          }
        }
        break;
      case 400:
        uVar4 = (pcVar8->u20).intrinsic.id;
        if (uVar4 == 0xde) {
          local_18 = local_18 + 1;
        }
        else if (uVar4 == 0xdf) {
          local_18 = local_18 + -1;
          pcVar9 = pcVar8->src->sym->def->src;
          if ((((1 << (pcVar9->kind & 0x1f) & 6U) != 0) &&
              (pcVar5 = pcVar9->sym, pcVar5->cls == '\x03')) && (pcVar5->def == (c2_tuple *)0x0)) {
            pcVar8 = find_next_use_of_dst(pcVar8,&local_8);
            pcVar8 = find_next_use_of_dst(pcVar8,&local_8);
            pcVar9 = pcVar8->dst;
            if (((pcVar9 != (c2_operand *)0x0) && ((1 << (pcVar9->kind & 0x1f) & 6U) != 0)) &&
               (pcVar9->sym->def != (c2_tuple *)0x0)) {
              reader_spill_eh_value(pcVar8);
            }
          }
        }
        break;
      case 0x1a0:
        if ((g_opt_eh_enabled != 0) &&
           ((((fn->fsym->attrs & 0x800) != 0 && ((fn->flags & 0x10000) == 0)) ||
            ((g_cur_function != fn &&
             (((g_cur_function->fsym->attrs & 0x800) != 0 &&
              ((g_cur_function->flags & 0x10000) == 0)))))))) {
          puVar1 = &((pcVar8->u20).eh_construct)->flags;
          *puVar1 = *puVar1 | 0x10;
        }
        if ((((((pcVar8->u20).cond_cells)->kind & 0x10) == 0) && (local_18 != 0)) &&
           (iVar6 = tree_has_unbalanced_intrinsic(pcVar8,0), iVar6 != 0)) {
          chain_end = follow_single_use_chain(pcVar8);
          number_tuples_in_range(first,&chain_end->next);
          uVar7 = tuple_reads_value_defined_before(chain_end,pcVar8);
          local_10 = local_10 | uVar7;
        }
        cxx_eh_create_unwind_funclet(pcVar8);
        break;
      case 0x1a1:
        if ((g_opt_eh_enabled == 0) ||
           (((((fn->fsym->attrs & 0x800) == 0 || ((fn->flags & 0x10000) != 0)) &&
             ((g_cur_function == fn ||
              (((g_cur_function->fsym->attrs & 0x800) == 0 ||
               ((g_cur_function->flags & 0x10000) != 0)))))) ||
            (((byte)((pcVar8->u20).eh_construct)->flags & 7) != 2)))) {
          cxx_eh_lower_scope_exit(pcVar8);
        }
        else {
          tuple_unlink_free(pcVar8);
        }
        break;
      case 0x1a2:
        cxx_eh_lower_catch_end(pcVar8);
        break;
      case 0x1a4:
        open_try = ((pcVar8->u20).eh_try)->try_block;
        g_cxx_try_records = open_try;
        open_try->outer = try_head;
        cxx_eh_lower_object_marker(pcVar8);
        if ((g_opt_eh_enabled == 0) && ((fn->flags & 8) != 0)) {
          tuple_new_intrinsic(400,0x400a,(c2_operand *)0x0,(c2_operand *)0x0,(c2_operand *)0x0,
                              (c2_operand *)0x0,(c2_operand *)0x0,0x185,tuple_insert_after,pcVar8);
        }
        break;
      case 0x1a5:
        if (open_try == (c2_cxx_try_block *)((pcVar8->u20).cond_cells)->cc) {
          open_try = try_head->outer;
          g_cxx_try_records = open_try;
        }
        cxx_eh_lower_object_marker(pcVar8);
        break;
      case 0x1a6:
        cxx_eh_lower_object_marker(pcVar8);
        if ((g_opt_eh_enabled == 0) && ((fn->flags & 8) != 0)) {
          tuple_new_intrinsic(400,0x400a,(c2_operand *)0x0,(c2_operand *)0x0,(c2_operand *)0x0,
                              (c2_operand *)0x0,(c2_operand *)0x0,0x185,tuple_insert_before,pcVar8);
        }
      }
    }
    pcVar8 = local_4;
    try_head = g_cxx_try_records;
  }
  g_eh_object_move_pending = g_eh_object_move_pending | local_10;
  if (g_eh_current_state == (c2_eh_state *)0x0) {
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\ehexcept.c",0x241);
}

