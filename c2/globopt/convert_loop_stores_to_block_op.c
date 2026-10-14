void __fastcall convert_loop_stores_to_block_op(c2_loop *loop,c2_function *fn)

{
  ushort uVar1;
  bool bVar2;
  uint32_t uVar3;
  uint16_t uVar4;
  c2_list_cell *pcVar5;
  c2_tuple *pcVar6;
  c2_block *block;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  int iVar9;
  c2_operand *pcVar10;
  c2_operand *pcVar11;
  c2_tuple *pcVar12;
  undefined2 extraout_var;
  c2_operand *v;
  c2_operand *local_60;
  c2_symbol *local_58;
  uint32_t src_type;
  c2_operand *local_50;
  uint32_t local_4c;
  c2_block *local_48;
  uint32_t local_44;
  c2_operand *local_40;
  uint32_t src_alias_class;
  uint32_t dst_alias_class;
  c2_tuple *local_34;
  c2_block *local_30;
  uint32_t local_2c;
  c2_tuple *local_28;
  c2_symbol *local_24;
  uint32_t dst_type;
  c2_tuple *local_1c;
  uint32_t fill_type;
  c2_operand *local_14;
  int local_10;
  c2_function *local_c;
  uint32_t elem_size;
  uint32_t local_4;
  uint32_t abs_step_lo;
  uint32_t step_lo;
  
  if (loop->trip_count != (c2_operand *)0x0) {
    local_c = fn;
    reset_iv_worklists();
    pcVar5 = collect_iv_candidates(loop,3);
    if (pcVar5 != (c2_list_cell *)0x0) {
      pcVar6 = iv_worklist_pop();
      while (pcVar6 != (c2_tuple *)0x0) {
        v = (c2_operand *)0x0;
        if (pcVar6->line != 0) {
          g_current_line_abs = local_c->line_base + (uint)pcVar6->line;
          g_cur_line = pcVar6->line;
        }
        block = tuple_get_block(pcVar6);
        uVar7 = block_dominates_loop_exits(block,loop);
        if (uVar7 != 0) {
          if (pcVar6->op == 0x15b) {
            local_2c = 0;
            pcVar11 = pcVar6->dst;
            local_1c = (c2_tuple *)0x0;
            src_type = CONCAT22((short)((uint)loop >> 0x10),pcVar11->type);
            local_14 = pcVar11->base;
            dst_alias_class = pcVar11->tag;
            elem_size = pcVar11->type & 0xfff;
            local_24 = local_14->sym;
            local_4 = 0;
            local_28 = pcVar6;
            dst_type = src_type;
            fill_type = src_type;
            pcVar8 = iv_increment_tuple(local_24);
            if (pcVar8 != (c2_tuple *)0x0) {
              local_44 = pcVar8->op;
              local_60 = iv_find_copy_source(pcVar8->src->next,loop);
              local_48 = tuple_get_block(pcVar8);
              uVar7 = is_loop_invariant_operand(pcVar6->src);
              local_30 = local_48;
              if (uVar7 == 0) {
                if ((pcVar6->type & 0xf000) == 0x5000) {
                  pcVar11 = pcVar6->src;
                  local_34 = (c2_tuple *)0x0;
                  v = pcVar11->base;
                  src_alias_class = pcVar11->tag;
                  uVar1 = pcVar11->type;
                  local_58 = v->sym;
                  pcVar12 = iv_increment_tuple(local_58);
                  if (pcVar12 != (c2_tuple *)0x0) {
                    local_4c = pcVar12->op;
                    pcVar11 = pcVar12->src->next;
                    goto LAB_1074742a;
                  }
                }
                else {
                  local_34 = pcVar6->prev;
                  pcVar11 = local_34->src;
                  v = pcVar11->base;
                  src_alias_class = pcVar11->tag;
                  uVar1 = pcVar11->type;
                  local_58 = v->sym;
                  pcVar12 = iv_increment_tuple(local_58);
                  if (pcVar12 != (c2_tuple *)0x0) {
                    local_4c = pcVar12->op;
LAB_10747421:
                    pcVar11 = pcVar12->src->next;
LAB_1074742a:
                    src_type = (uint32_t)uVar1;
                    local_40 = (c2_operand *)0x0;
                    bVar2 = false;
                    local_50 = iv_find_copy_source(pcVar11,loop);
                    local_48 = tuple_get_block(pcVar12);
                    goto LAB_10747226;
                  }
                }
              }
              else {
                local_40 = pcVar6->src;
                local_58 = local_24;
                bVar2 = true;
                local_34 = (c2_tuple *)0x0;
                pcVar12 = pcVar8;
                local_50 = local_60;
                local_4c = local_44;
                src_alias_class = dst_alias_class;
LAB_10747226:
                iVar9 = types_compatible((uint16_t)dst_type,(uint16_t)src_type);
                if ((((iVar9 != 0) && (iVar9 = operand_compare(local_60,local_50), iVar9 == 0)) &&
                    (local_44 == local_4c)) &&
                   (((local_30 == local_48 && (local_60->kind == '\a')) &&
                    ((uVar7 = block_dominates_loop_exits(local_30,loop), uVar7 != 0 &&
                     ((uVar7 = block_range_dominated(pcVar6,pcVar8), uVar7 != 0 &&
                      (uVar7 = block_range_dominated(pcVar6,pcVar12), pcVar8 = local_1c, uVar7 != 0)
                      ))))))) {
                  if (local_28 == (c2_tuple *)0x0) {
                    pcVar11 = operand_list_find_kind_b(local_1c->dst);
                  }
                  else {
                    pcVar11 = local_28->dst;
                  }
                  if (bVar2) {
                    pcVar10 = (c2_operand *)0x0;
                  }
                  else if (local_34 == (c2_tuple *)0x0) {
                    if (local_28 == (c2_tuple *)0x0) {
                      pcVar10 = operand_list_find_kind_b(pcVar8->src);
                    }
                    else {
                      pcVar10 = local_28->src;
                    }
                  }
                  else {
                    pcVar10 = local_34->src;
                  }
                  if (pcVar8 == (c2_tuple *)0x0) {
                    local_10 = 0;
                  }
                  else {
                    local_10 = (int)(short)(pcVar8->u24).intrinsic_flag;
                  }
                  iVar9 = loop_stores_may_alias(pcVar11,pcVar10,pcVar6,loop,&local_10);
                  if (iVar9 == 0) {
                    uVar7 = local_60->tag;
                    step_lo = (local_60->u18).lo;
                    uVar3 = uVar7;
                    abs_step_lo = step_lo;
                    if (((int)uVar7 < 1) && ((int)uVar7 < 0)) {
                      uVar3 = -(uVar7 + (step_lo != 0));
                      abs_step_lo = -step_lo;
                    }
                    if (((((elem_size == abs_step_lo) && (local_4 == uVar3)) && (local_44 == 0x16d))
                        && (-1 < (int)uVar7)) && ((0 < (int)uVar7 || (step_lo != 0)))) {
                      pcVar11 = trip_count_scaled(loop,local_c,elem_size,local_4);
                      if (bVar2) {
                        pcVar6 = emit_block_fill_intrinsic
                                           (local_14,dst_alias_class,local_40,0,(uint16_t)fill_type,
                                            (uint8_t)local_2c,(int)pcVar11,g_preheader_insert_point)
                        ;
                      }
                      else {
                        pcVar6 = emit_block_fill_intrinsic
                                           (local_14,dst_alias_class,v,src_alias_class,
                                            (uint16_t)fill_type,(uint8_t)local_2c,(int)pcVar11,
                                            g_preheader_insert_point);
                        if (local_34 != (c2_tuple *)0x0) {
                          symbol_remove_use(local_58,local_34);
                          tuple_unlink_free(local_34);
                        }
                      }
                      pcVar12 = local_28;
                      (pcVar6->u24).intrinsic_flag = (uint16_t)local_10;
                      if (local_28 == (c2_tuple *)0x0) {
                        tuple_unlink_free(pcVar8->src->next->next->sym->def);
                        pcVar6 = pcVar8->src->next->sym->def;
                        if (!bVar2) {
                          symbol_remove_use(local_58,pcVar6);
                        }
                        tuple_unlink_free(pcVar6);
                        pcVar6 = pcVar8->src->sym->def;
                        symbol_remove_use(local_24,pcVar6);
                        tuple_unlink_free(pcVar6);
                      }
                      else {
                        symbol_remove_use(local_24,local_28);
                        pcVar8 = pcVar12;
                      }
                      tuple_unlink_free(pcVar8);
                    }
                  }
                }
              }
            }
          }
          else {
            local_28 = (c2_tuple *)0x0;
            local_34 = (c2_tuple *)0x0;
            local_2c = 0;
            local_1c = pcVar6;
            pcVar11 = convert_loop_stores_size_case(1,pcVar6);
            local_14 = pcVar11;
            pcVar10 = convert_loop_stores_size_case(3,pcVar6);
            pcVar10 = iv_find_copy_source(pcVar10,loop);
            uVar4 = block_op_element_type(pcVar6,&local_2c);
            fill_type = CONCAT22(extraout_var,uVar4);
            if (pcVar10->kind == '\a') {
              elem_size = (pcVar10->u18).lo;
              local_4 = pcVar10->tag;
              pcVar10 = operand_list_find_kind_b(pcVar6->dst);
              local_58 = pcVar11->sym;
              dst_alias_class = (uint32_t)pcVar10->sym;
              dst_type = CONCAT22(dst_type._2_2_,pcVar11->type);
              local_24 = local_58;
              pcVar8 = iv_increment_tuple(local_58);
              if (pcVar8 != (c2_tuple *)0x0) {
                local_44 = pcVar8->op;
                local_60 = iv_find_copy_source(pcVar8->src->next,loop);
                local_48 = tuple_get_block(pcVar8);
                local_30 = local_48;
                if ((pcVar6->u20).intrinsic.id == 0xad) {
                  bVar2 = true;
                  local_40 = convert_loop_stores_size_case(2,pcVar6);
                  src_type = dst_type;
                  pcVar12 = pcVar8;
                  local_50 = local_60;
                  local_4c = local_44;
                  src_alias_class = dst_alias_class;
                  goto LAB_10747226;
                }
                v = convert_loop_stores_size_case(2,pcVar6);
                pcVar11 = operand_list_find_kind_b(pcVar6->src);
                uVar1 = v->type;
                src_alias_class = (uint32_t)pcVar11->sym;
                local_58 = v->sym;
                pcVar12 = iv_increment_tuple(local_58);
                if (pcVar12 != (c2_tuple *)0x0) {
                  local_4c = pcVar12->op;
                  goto LAB_10747421;
                }
              }
            }
          }
        }
        pcVar6 = iv_worklist_pop();
      }
    }
  }
  return;
}

