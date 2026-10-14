c2_tuple * __fastcall shrink_wrap_callee_saves(c2_function *fn,c2_tuple *after,uint32_t *skip_mask)

{
  c2_block **ppcVar1;
  c2_bitset **ppcVar2;
  uint *puVar3;
  byte bVar4;
  c2_cfg *pcVar5;
  c2_edge *pcVar6;
  int *piVar7;
  c2_loop *pcVar8;
  int iVar9;
  c2_tuple *t;
  uint8_t *puVar10;
  c2_block *pcVar11;
  c2_block *pcVar12;
  c2_block *restore_block;
  byte regno;
  c2_tuple *pcVar13;
  c2_operand *pcVar14;
  c2_block *pcVar15;
  int reg_offset;
  uint uVar16;
  c2_symbol *reg;
  bool changed;
  uint32_t usable_mask;
  uint32_t reg_mask;
  c2_callee_save_site **ppcVar17;
  int inner_offset;
  int outer_regno;
  int outer_offset;
  c2_callee_save_site *saves [9];
  c2_callee_save_site *restores [9];
  c2_edge *split_edge;
  c2_callee_save_site *split_site;
  c2_block **edge_end;
  c2_callee_save_site *site;
  c2_callee_save_site *restore_site;
  c2_block *walk_block;
  c2_block *site_block;
  c2_edge *pred_edge;
  
  *skip_mask = 0;
  if (fn->cfg->last->preds == (c2_edge *)0x0) {
    return after;
  }
  if ((fn->flags & 1) != 0) {
    for (pcVar13 = fn->cfg->first->head; pcVar13 != (c2_tuple *)0x0; pcVar13 = pcVar13->next) {
      if ((pcVar13->kind == '\x15') &&
         (pcVar14 = find_dst_clobbering_reg(pcVar13,g_reg_symbols + 5), pcVar14 != (c2_operand *)0x0
         )) {
        return after;
      }
    }
  }
  cfg_rebuild_basic(fn);
  cfg_remove_unreachable_blocks(fn);
  cfg_number_blocks(fn);
  cfg_compute_dominators(fn);
  cfg_compute_loops(fn);
  cfg_number_blocks(fn);
  regno = 4;
  puVar10 = &g_reg_symbols[4].flags5;
  usable_mask = g_callee_saved_mask;
  do {
    if ((*puVar10 & 0x10) == 0) {
      usable_mask = usable_mask & ~(1 << (regno & 0x1f));
    }
    puVar10 = puVar10 + 0x54;
    regno = regno + 1;
  } while ((int)puVar10 < 0x107ac9d6);
  pcVar11 = fn->cfg->first;
  for (pcVar12 = pcVar11; pcVar12 != (c2_block *)0x0; pcVar12 = pcVar12->next) {
    pcVar12->de = (c2_bitset *)0x0;
  }
  for (; pcVar11 != (c2_block *)0x0; pcVar11 = pcVar11->next) {
    pcVar13 = after;
    if (pcVar11->rpo != 1) {
      pcVar13 = pcVar11->head->next;
    }
    if (pcVar13 != pcVar11->end->prev->next) {
      do {
        if ((pcVar13->flags & 1) != 0) {
          shrink_wrap_collect_regs(pcVar13,pcVar11);
          if (pcVar13->kind == '\x13') {
            for (pcVar6 = pcVar11->succs; pcVar6 != (c2_edge *)0x0; pcVar6 = pcVar6->next_succ) {
              shrink_wrap_collect_regs(pcVar13,pcVar6->to);
            }
          }
          if (((pcVar13->op == 1) && (pcVar13->src->kind == '\x01')) &&
             (((pcVar13->src->u18).reg)->storage == g_reg_symbols + 5)) {
            if ((fn->flags & 0x10) != 0) {
              return after;
            }
            if (pcVar13->dst->kind != '\x01') {
              return after;
            }
            if (((pcVar13->dst->u18).reg)->storage != g_reg_symbols + 6) {
              return after;
            }
          }
        }
        pcVar13 = pcVar13->next;
      } while (pcVar13 != pcVar11->end->prev->next);
    }
    reg_mask = (uint)pcVar11->de & usable_mask;
    pcVar11->de = (c2_bitset *)reg_mask;
    if (pcVar11->loop != (c2_loop *)0x0) {
      pcVar8 = pcVar11->loop->parent;
      while (pcVar8 != (c2_loop *)0x0) {
        ppcVar1 = &pcVar8->first;
        pcVar8 = pcVar8->parent;
        (*ppcVar1)->de = (c2_bitset *)((uint)(*ppcVar1)->de | reg_mask);
      }
    }
  }
  do {
    pcVar5 = fn->cfg;
    pcVar12 = pcVar5->first;
    pcVar11 = pcVar12;
    do {
      for (; pcVar11 != (c2_block *)0x0; pcVar11 = pcVar11->next) {
        pcVar11->avail_out = (c2_block_slot)pcVar11->de;
        pcVar11->avail_in = (c2_block_slot)pcVar11->de;
      }
      pcVar11 = pcVar5->last;
      do {
        changed = false;
        pcVar15 = pcVar11;
        if (pcVar11 == (c2_block *)0x0) break;
        do {
          pcVar6 = pcVar15->preds;
          reg_mask = *(uint32_t *)&pcVar15->avail_in;
          while (pcVar6 != (c2_edge *)0x0) {
            ppcVar1 = &pcVar6->from;
            pcVar6 = pcVar6->next_pred;
            (pcVar15->avail_in).set =
                 (c2_bitset *)((uint)(pcVar15->avail_in).set | (uint)((*ppcVar1)->avail_in).set);
          }
          if ((c2_bitset *)reg_mask != (pcVar15->avail_in).set) {
            changed = true;
          }
          pcVar15 = pcVar15->prev;
        } while (pcVar15 != (c2_block *)0x0);
      } while (changed);
      do {
        changed = false;
        pcVar11 = pcVar12;
        if (pcVar12 == (c2_block *)0x0) break;
        do {
          pcVar6 = pcVar11->succs;
          reg_mask = *(uint32_t *)&pcVar11->avail_out;
          while (pcVar6 != (c2_edge *)0x0) {
            ppcVar1 = &pcVar6->to;
            pcVar6 = pcVar6->next_succ;
            (pcVar11->avail_out).set =
                 (c2_bitset *)((uint)(pcVar11->avail_out).set | (uint)((*ppcVar1)->avail_out).set);
          }
          if ((c2_bitset *)reg_mask != (pcVar11->avail_out).set) {
            changed = true;
          }
          pcVar11 = pcVar11->next;
        } while (pcVar11 != (c2_block *)0x0);
      } while (changed);
      changed = false;
      pcVar11 = pcVar12;
      if (pcVar12 == (c2_block *)0x0) break;
      do {
        reg_mask = (uint)(pcVar11->avail_in).set & (uint)(pcVar11->avail_out).set;
        pcVar11->avail_in = (c2_block_slot)reg_mask;
        if ((c2_bitset *)reg_mask != pcVar11->de) {
          pcVar11->de = (c2_bitset *)reg_mask;
          changed = true;
        }
        pcVar11 = pcVar11->next;
      } while (pcVar11 != (c2_block *)0x0);
      pcVar11 = pcVar12;
    } while (changed);
    ppcVar17 = saves;
    for (reg_offset = 9; reg_offset != 0; reg_offset = reg_offset + -1) {
      *ppcVar17 = (c2_callee_save_site *)0x0;
      ppcVar17 = ppcVar17 + 1;
    }
    ppcVar17 = restores;
    for (reg_offset = 9; reg_offset != 0; reg_offset = reg_offset + -1) {
      *ppcVar17 = (c2_callee_save_site *)0x0;
      ppcVar17 = ppcVar17 + 1;
    }
    shrink_wrap_place_saves(fn,saves,restores);
    changed = false;
    regno = 4;
    reg_offset = 0;
    do {
      site = *(c2_callee_save_site **)((int)saves + reg_offset + 0x10);
      if ((site != (c2_callee_save_site *)0x0) &&
         (((site->next != (c2_callee_save_site *)0x0 || (site->block == (c2_block *)0x0)) ||
          (*(int *)((int)restores + reg_offset + 0x10) == 0)))) {
        changed = true;
        for (; site != (c2_callee_save_site *)0x0; site = site->next) {
          if (site->edge == (c2_edge *)0x0) {
            site_block = site->block;
            uVar16 = 1 << (regno & 0x1f);
            if ((uVar16 & (uint)site_block->de) == 0) {
              site_block->de = (c2_bitset *)((uint)site_block->de | uVar16);
            }
            else {
              pred_edge = site_block->preds;
              while (pred_edge != (c2_edge *)0x0) {
                ppcVar1 = &pred_edge->from;
                pred_edge = pred_edge->next_pred;
                ppcVar2 = &(*ppcVar1)->de;
                *ppcVar2 = (c2_bitset *)((uint)*ppcVar2 | uVar16);
              }
            }
          }
          else {
            ppcVar2 = &site->edge->from->de;
            *ppcVar2 = (c2_bitset *)((uint)*ppcVar2 | 1 << (regno & 0x1f));
          }
        }
      }
      restore_site = *(c2_callee_save_site **)((int)restores + reg_offset + 0x10);
      if ((restore_site != (c2_callee_save_site *)0x0) &&
         ((restore_site->next != (c2_callee_save_site *)0x0 ||
          (restore_site->block == (c2_block *)0x0)))) {
        changed = true;
        for (; restore_site != (c2_callee_save_site *)0x0; restore_site = restore_site->next) {
          if (restore_site->edge == (c2_edge *)0x0) {
            pcVar12 = restore_site->block;
            uVar16 = 1 << (regno & 0x1f);
            if ((uVar16 & (uint)pcVar12->de) == 0) {
              pcVar12->de = (c2_bitset *)((uint)pcVar12->de | uVar16);
            }
            else {
              pcVar6 = pcVar12->succs;
              while (pcVar6 != (c2_edge *)0x0) {
                edge_end = &pcVar6->to;
                pcVar6 = pcVar6->next_succ;
                (*edge_end)->de = (c2_bitset *)((uint)(*edge_end)->de | uVar16);
              }
            }
          }
          else {
            ppcVar2 = &restore_site->edge->to->de;
            *ppcVar2 = (c2_bitset *)((uint)*ppcVar2 | 1 << (regno & 0x1f));
          }
        }
      }
      reg_offset = reg_offset + 4;
      regno = regno + 1;
    } while (reg_offset < 0x11);
    if (!changed) {
      reg_offset = 0;
      regno = 4;
      do {
        split_site = *(c2_callee_save_site **)((int)saves + reg_offset + 0x10);
        if (split_site != (c2_callee_save_site *)0x0) {
          split_edge = split_site->edge;
          if (split_edge != (c2_edge *)0x0) {
            pcVar12 = split_site->block->next;
            if (pcVar12->rpo == -1) {
              split_site->block = pcVar12;
            }
            else {
              pcVar12 = split_edge_with_new_block(fn,split_edge,split_edge->from,split_edge->to);
              *(c2_block **)(*(int *)((int)saves + reg_offset + 0x10) + 4) = pcVar12;
              iVar9 = *(int *)(*(int *)((int)saves + reg_offset + 0x10) + 4);
              *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(*(int *)(iVar9 + 4) + 0x2c);
              piVar7 = *(int **)(*(int *)((int)saves + reg_offset + 0x10) + 4);
              piVar7[0xb] = piVar7[0xb] & *(uint *)(*piVar7 + 0x2c);
            }
            **(undefined4 **)((int)saves + reg_offset + 0x10) = 0;
          }
          iVar9 = *(int *)(*(int *)((int)saves + reg_offset + 0x10) + 4);
          uVar16 = 1 << (regno & 0x1f);
          *(uint *)(iVar9 + 0x2c) = *(uint *)(iVar9 + 0x2c) | uVar16;
          split_site = *(c2_callee_save_site **)((int)restores + reg_offset + 0x10);
          split_edge = split_site->edge;
          if (split_edge != (c2_edge *)0x0) {
            pcVar12 = split_site->block->next;
            if (pcVar12->rpo == -1) {
              split_site->block = pcVar12;
            }
            else {
              pcVar12 = split_edge_with_new_block(fn,split_edge,split_edge->from,split_edge->to);
              *(c2_block **)(*(int *)((int)restores + reg_offset + 0x10) + 4) = pcVar12;
              iVar9 = *(int *)(*(int *)((int)restores + reg_offset + 0x10) + 4);
              *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(*(int *)(iVar9 + 4) + 0x2c);
              piVar7 = *(int **)(*(int *)((int)restores + reg_offset + 0x10) + 4);
              piVar7[0xb] = piVar7[0xb] & *(uint *)(*piVar7 + 0x2c);
            }
            **(undefined4 **)((int)restores + reg_offset + 0x10) = 0;
          }
          puVar3 = (uint *)(*(int *)(*(int *)((int)restores + reg_offset + 0x10) + 4) + 0x2c);
          *puVar3 = *puVar3 | uVar16;
        }
        reg_offset = reg_offset + 4;
        regno = regno + 1;
      } while (reg_offset < 0x11);
      do {
        changed = false;
        outer_regno = 4;
        outer_offset = 0;
        do {
          if (*(int *)((int)saves + outer_offset + 0x10) != 0) {
            reg_offset = 4;
            inner_offset = 0;
            do {
              if ((reg_offset != outer_regno) &&
                 (iVar9 = *(int *)((int)saves + inner_offset + 0x10), iVar9 != 0)) {
                walk_block = *(c2_block **)(*(int *)((int)saves + outer_offset + 0x10) + 4);
                uVar16 = 1 << ((byte)reg_offset & 0x1f);
                if ((((uint)walk_block->de & uVar16) == 0) &&
                   ((*(uint *)(*(int *)(*(int *)((int)restores + outer_offset + 0x10) + 4) + 0x2c) &
                    uVar16) != 0)) {
                  if (walk_block != *(c2_block **)(iVar9 + 4)) {
                    do {
                      walk_block->de = (c2_bitset *)((uint)walk_block->de | uVar16);
                      walk_block = walk_block->next;
                    } while (walk_block !=
                             *(c2_block **)(*(int *)((int)saves + inner_offset + 0x10) + 4));
                  }
                  changed = true;
                  *(undefined4 *)(*(int *)((int)saves + inner_offset + 0x10) + 4) =
                       *(undefined4 *)(*(int *)((int)saves + outer_offset + 0x10) + 4);
                  **(undefined4 **)((int)saves + inner_offset + 0x10) =
                       **(undefined4 **)((int)saves + outer_offset + 0x10);
                }
                restore_block = *(c2_block **)(*(int *)((int)restores + outer_offset + 0x10) + 4);
                if ((((uint)restore_block->de & uVar16) == 0) &&
                   ((*(uint *)(*(int *)(*(int *)((int)saves + outer_offset + 0x10) + 4) + 0x2c) &
                    uVar16) != 0)) {
                  if (restore_block !=
                      *(c2_block **)(*(int *)((int)restores + inner_offset + 0x10) + 4)) {
                    do {
                      restore_block->de = (c2_bitset *)((uint)restore_block->de | uVar16);
                      restore_block = restore_block->prev;
                    } while (restore_block !=
                             *(c2_block **)(*(int *)((int)restores + inner_offset + 0x10) + 4));
                  }
                  changed = true;
                  *(undefined4 *)(*(int *)((int)restores + inner_offset + 0x10) + 4) =
                       *(undefined4 *)(*(int *)((int)restores + outer_offset + 0x10) + 4);
                  **(undefined4 **)((int)restores + inner_offset + 0x10) =
                       **(undefined4 **)((int)restores + outer_offset + 0x10);
                }
              }
              inner_offset = inner_offset + 4;
              reg_offset = reg_offset + 1;
            } while (inner_offset < 0x11);
          }
          outer_offset = outer_offset + 4;
          outer_regno = outer_regno + 1;
        } while (outer_offset < 0x11);
      } while (changed);
      g_cur_line = 0;
      outer_regno = 8;
      reg = g_reg_symbols + 8;
      reg_offset = 0;
      do {
        piVar7 = *(int **)((int)saves + reg_offset + 0x20);
        if (piVar7 != (int *)0x0) {
          iVar9 = *piVar7;
          *skip_mask = *skip_mask | 1 << ((byte)outer_regno & 0x1f);
          if (iVar9 == 0) {
            pcVar13 = after;
            if ((*(short *)(piVar7[1] + 0x6c) != 1) &&
               ((pcVar13 = tuple_next_real_in_block(*(c2_tuple **)(piVar7[1] + 0x1c)),
                pcVar13 == (c2_tuple *)0x0 || (pcVar13->kind != '\x1a')))) {
              pcVar13 = *(c2_tuple **)
                         (*(int *)(*(int *)((int)saves + reg_offset + 0x20) + 4) + 0x1c);
            }
          }
          else {
            pcVar13 = *(c2_tuple **)(*(int *)(piVar7[1] + 0x20) + 0xc);
          }
          emit_callee_save_push(fn,reg,pcVar13);
          piVar7 = *(int **)((int)restores + reg_offset + 0x20);
          if (*piVar7 == 0) {
            pcVar13 = tuple_prev_real_in_block(*(c2_tuple **)(piVar7[1] + 0x20));
            if (pcVar13 == (c2_tuple *)0x0) {
              pcVar13 = *(c2_tuple **)
                         (*(int *)(*(int *)(*(int *)((int)restores + reg_offset + 0x20) + 4) + 0x20)
                         + 0xc);
            }
            else {
              if ((1 << (pcVar13->kind & 0x1f) & 0xa0000U) != 0) {
                if ((pcVar13->kind == 0x11) &&
                   (((pcVar13->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar13->op == 0x18b)))) {
                  t = pcVar13->prev;
                  usable_mask = t->op;
                  if (((usable_mask == 0x2f) || ((usable_mask == 0x33 || (usable_mask == 0x30)))) &&
                     (pcVar14 = find_src_overlapping_reg(t,reg), pcVar14 == (c2_operand *)0x0)) {
                    pcVar13 = t;
                  }
                }
                pcVar13 = pcVar13->prev;
              }
              if (pcVar13->kind == '\x0f') {
                pcVar13 = pcVar13->prev;
              }
            }
          }
          else {
            pcVar13 = *(c2_tuple **)(*(int *)(piVar7[1] + 0x20) + 0xc);
          }
          bVar4 = pcVar13->flags;
          while ((((bVar4 & 1) == 0 && (pcVar13->kind != '\x1a')) && (pcVar13->kind != '\x19'))) {
            pcVar13 = pcVar13->prev;
            bVar4 = pcVar13->flags;
          }
          emit_callee_save_pop(reg,pcVar13);
        }
        reg_offset = reg_offset + -4;
        outer_regno = outer_regno + -1;
        reg = reg + -1;
      } while (-0x11 < reg_offset);
      return after;
    }
  } while( true );
}

