void ** __cdecl
lookup_member_match_overload_part_1
          (byte kind,uint cc_flags,int zero,c1_symbol *probe_reg,c1_sym_link *cell,c1_symbol *cand,
          int *old_params,int new_params,c1_type *new_this_type,c1_sym_link *next_cell,
          c1_sym_link *cur_cell,c1_sym_link *cursor,int *deduction_args,int *deduction2_args,
          c1_type *type,char complain,char skip_templates,c1_symbol *probe,c1_declarator *d,int mode
          )

{
  c1_u32 *pcVar1;
  char cVar2;
  c1_arg_value cVar3;
  c1_u8 *pcVar4;
  c1_declarator *pcVar5;
  byte bVar6;
  uint arg_word10;
  int iVar7;
  void **ppvVar8;
  c1_type *pcVar9;
  c1_type *pcVar10;
  c1_type *pcVar11;
  c1_symbol *pcVar12;
  uint *arg_copy;
  uint *arg_copy_2;
  uint *arg_copy_3;
  uint *arg_copy_4;
  c1_symbol *pcVar13;
  c1_deferred_action *pcVar14;
  c1_arg_item *pcVar15;
  
  pcVar13 = cand;
  if (kind == 0x1a) {
    pcVar13 = ((cell->type).alias)->target;
  }
  if ((*(byte *)((int)&pcVar13->tail + 9) & 0x20) == 0) goto LAB_1040de26;
LAB_1040deb6:
  do {
    cell = next_cell;
    zero = 0;
    if ((cursor == (c1_sym_link *)0x0) || (next_cell == (c1_sym_link *)0x0)) {
      if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
        pcVar14 = g_deferred_actions_head;
        if (g_tmpl_deduction_depth < 1) {
          do {
            (**pcVar14->vtbl)();
            pcVar14 = pcVar14->next;
          } while (pcVar14 != (c1_deferred_action *)0x0);
        }
        g_deferred_actions_tail = (c1_deferred_action *)0x0;
        g_deferred_actions_head = (c1_deferred_action *)0x0;
      }
      return (void **)0x0;
    }
    cur_cell = next_cell;
    iVar7 = sym_is_data_or_function_2((c1_symbol *)&cursor[-1].position);
    if (((char)iVar7 == '\0') && ((cursor[-1].position & 0x1f) != 0x1a)) {
      next_cell = next_cell->next;
    }
    else {
      next_cell = (c1_sym_link *)0x0;
    }
    cand = (c1_symbol *)&cell[-1].position;
    kind = (byte)cell[-1].position & 0x1f;
    pcVar13 = cand;
    if (kind == 0x1a) {
      pcVar13 = ((cell->type).alias)->target;
    }
  } while (((*(byte *)((int)&pcVar13->tail + 9) & 0x20) != 0) && (skip_templates != '\0'));
  if (complain != '\0') {
    if ((g_compile_flags_cc & 0x40) != 0) {
      pcVar13 = cand;
      if (kind == 0x1a) {
        pcVar13 = ((cell->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar13->tail + 9) & 0x20) != 0) goto LAB_1040deb6;
    }
    cc_flags = g_compile_flags_cc;
    probe_reg = probe;
    if ((((g_compile_flags_cc & 8) != 0) && ((g_compile_flags_cc & 0x20000) == 0)) &&
       ((*(byte *)((int)&probe->tail + 9) & 0x40) != 0)) {
      ppvVar8 = lookup_member_match_overload_part_1
                          (kind,g_compile_flags_cc,0,probe,cell,cand,old_params,new_params,
                           new_this_type,next_cell,cell,cursor,deduction_args,deduction2_args,type,
                           complain,skip_templates,probe,d,mode);
      return ppvVar8;
    }
LAB_1040de26:
    if (((cc_flags & 0x200000) == 0) && ((*(byte *)((int)&probe_reg->tail + 9) & 0x60) == 0)) {
      pcVar13 = cand;
      if (kind == 0x1a) {
        pcVar13 = ((cell->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar13->tail + 9) & 0x20) != 0) {
        pcVar13 = cand;
        if ((cand->kind & 0x1f) == 0x1a) {
          pcVar13 = ((cell->type).alias)->target;
        }
        tmpl_deduction_begin
                  ((c1_tmpl_deduction *)&stack0x0000002c,pcVar13,(c1_arg_list *)zero,(byte)zero,
                   (byte)zero);
        bVar6 = tmpl_compare_argument_lists((c1_tmpl_deduction *)&stack0x0000002c,probe_reg);
        pcVar5 = d;
        pcVar13 = probe;
        cc_flags = g_compile_flags_cc;
        if (bVar6 != 0) {
          if (((g_compile_flags_cc & 8) == 0) || ((probe_reg->flags21 & 4) == 0)) {
            bVar6 = *(byte *)((int)&probe->tail + 9);
            if ((probe_reg->flags23 & 0x40) == 0) {
              *(byte *)((int)&probe->tail + 9) = bVar6 | 0x80;
            }
            else {
              *(byte *)((int)&probe->tail + 9) = bVar6 | 0x80;
            }
            if (d != (c1_declarator *)0x0) {
              d->flags57 = d->flags57 | 1;
            }
          }
          else {
            *(byte *)((int)&probe->tail + 9) = *(byte *)((int)&probe->tail + 9) | 0x40;
            if (d != (c1_declarator *)0x0) {
              d->flags56 = d->flags56 | 0x20;
            }
          }
          iVar7 = mode;
          if (mode == 1) {
            iVar7 = 2;
          }
          pcVar12 = cand;
          if ((cand->kind & 0x1f) == 0x1a) {
            pcVar12 = ((cell->type).alias)->target;
          }
          decl_check_default_argument_redefinition
                    (*(c1_function_params **)
                      (((uint)pcVar12->type & -(uint)((pcVar12->type->code & 0x80) != 0)) + 8),
                     (c1_function_params *)new_params,probe,iVar7);
          if (pcVar5 == (c1_declarator *)0x0) {
            if ((cand->kind & 0x1f) == 0x1a) {
              cand = ((cell->type).alias)->target;
            }
            symtab_1604_insert(pcVar13,cand);
            pcVar4 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar4 == (c1_u8 *)0x0) {
              symtab_15f4_insert(probe,(void *)0x0);
            }
            else {
              pcVar4[0] = '\0';
              pcVar4[1] = '\0';
              pcVar4[2] = '\0';
              pcVar4[3] = '\0';
              pcVar4[4] = '\0';
              pcVar4[5] = '\0';
              pcVar4[6] = '\0';
              pcVar4[7] = '\0';
              pcVar15 = (c1_arg_item *)*deduction_args;
              if ((*(byte *)(deduction_args + 2) & 1) != 0) {
                pcVar4[8] = pcVar4[8] | 1;
              }
              do {
                if ((pcVar15->kind & 3) == 0) {
                  arg_copy_3 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_3 == (uint *)0x0) {
LAB_10471c93:
                    arg_copy_3 = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy_3,pcVar15);
                    cVar3 = pcVar15->value;
                    *arg_copy_3 = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    *(c1_arg_value *)(arg_copy_3 + 4) = cVar3;
                  }
                }
                else {
                  arg_copy_4 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_4 == (uint *)0x0) goto LAB_10471c93;
                  arg_copy_3 = (uint *)tmpl_argument_copy_nontype((c1_arg_item *)arg_copy_4,pcVar15)
                  ;
                }
                if (*(int *)pcVar4 == 0) {
                  *(uint **)pcVar4 = arg_copy_3;
                }
                else {
                  *(uint **)(*(int *)(pcVar4 + 4) + 4) = arg_copy_3;
                  ((c1_arg_item *)arg_copy_3)->prev = *(c1_arg_item **)(pcVar4 + 4);
                }
                *(uint **)(pcVar4 + 4) = arg_copy_3;
                pcVar15 = pcVar15->next;
              } while (pcVar15 != (c1_arg_item *)0x0);
              symtab_15f4_insert(probe,pcVar4);
            }
          }
          else {
            if ((cand->kind & 0x1f) == 0x1a) {
              cand = ((cell->type).alias)->target;
            }
            pcVar5->specialized_template = cand;
            pcVar4 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar4 == (c1_u8 *)0x0) {
              pcVar5->template_args = (c1_arg_list *)0x0;
            }
            else {
              pcVar4[0] = '\0';
              pcVar4[1] = '\0';
              pcVar4[2] = '\0';
              pcVar4[3] = '\0';
              pcVar4[4] = '\0';
              pcVar4[5] = '\0';
              pcVar4[6] = '\0';
              pcVar4[7] = '\0';
              pcVar15 = (c1_arg_item *)*deduction_args;
              if ((*(byte *)(deduction_args + 2) & 1) != 0) {
                pcVar4[8] = pcVar4[8] | 1;
              }
              do {
                if ((pcVar15->kind & 3) == 0) {
                  arg_copy = arena_alloc(g_arenas,0x14);
                  if (arg_copy == (uint *)0x0) {
LAB_10471b98:
                    arg_copy = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy,pcVar15);
                    cVar3 = pcVar15->value;
                    *arg_copy = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    *(c1_arg_value *)(arg_copy + 4) = cVar3;
                  }
                }
                else {
                  arg_copy_2 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_2 == (uint *)0x0) goto LAB_10471b98;
                  arg_copy = (uint *)tmpl_argument_copy_nontype((c1_arg_item *)arg_copy_2,pcVar15);
                }
                if (*(int *)pcVar4 == 0) {
                  *(uint **)pcVar4 = arg_copy;
                }
                else {
                  *(uint **)(*(int *)(pcVar4 + 4) + 4) = arg_copy;
                  ((c1_arg_item *)arg_copy)->prev = *(c1_arg_item **)(pcVar4 + 4);
                }
                *(uint **)(pcVar4 + 4) = arg_copy;
                pcVar15 = pcVar15->next;
              } while (pcVar15 != (c1_arg_item *)0x0);
              pcVar5->template_args = (c1_arg_list *)pcVar4;
            }
          }
          goto LAB_1040deb6;
        }
      }
    }
    if ((cc_flags & 0x20) != 0) {
      bVar6 = cand->kind & 0x1f;
      pcVar13 = cand;
      if (bVar6 == 0x1a) {
        pcVar13 = ((cell->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar13->tail + 9) & 0x20) == 0) {
        pcVar13 = cand;
        if (bVar6 == 0x1a) {
          pcVar13 = ((cell->type).alias)->target;
        }
        if ((*(byte *)((int)&pcVar13->tail + 9) & 0x40) == 0) {
          pcVar13 = cand;
          if (bVar6 == 0x1a) {
            pcVar13 = ((cell->type).alias)->target;
          }
          if ((pcVar13->kind & 0x1f) != 8) {
            ppvVar8 = lookup_member_match_overload_part_2
                                (zero,probe_reg,cell,cand,old_params,new_params,new_this_type,
                                 next_cell,cur_cell,cursor,deduction_args,deduction2_args,type,
                                 complain,skip_templates,probe,d,mode);
            return ppvVar8;
          }
        }
      }
    }
  }
  pcVar13 = cand;
  if ((cand->kind & 0x1f) == 0x1a) {
    pcVar13 = ((cell->type).alias)->target;
  }
  pcVar11 = pcVar13->type;
  old_params = (int *)(pcVar11->extra).params;
  pcVar9 = ((c1_function_params *)old_params)->this_type;
  if (type != pcVar11) {
    if (new_this_type != pcVar9) {
      if (new_this_type == (c1_type *)0x0) {
        if ((((c1_function_params *)old_params)->flags & 1) == 0) goto LAB_1040deb6;
      }
      else {
        if (pcVar9 == (c1_type *)0x0) goto LAB_1040deb6;
        cVar2 = (char)new_this_type->code;
        pcVar10 = new_this_type;
        while (cVar2 < '\0') {
          pcVar10 = pcVar10->base;
          cVar2 = (char)pcVar10->code;
        }
        if ((pcVar10->code & 0x8f) == 0x83) {
          pcVar10 = type_skip_arrays(pcVar10->base);
        }
        cVar2 = (char)pcVar9->code;
        while (cVar2 < '\0') {
          pcVar9 = pcVar9->base;
          cVar2 = (char)pcVar9->code;
        }
        if ((pcVar9->code & 0x8f) == 0x83) {
          pcVar9 = type_skip_arrays(pcVar9->base);
        }
        if (((pcVar9->flags ^ pcVar10->flags) & 0x3e0) != 0) goto LAB_1040deb6;
      }
    }
    if ((*(c1_type_list **)(new_params + 0xc) != ((c1_function_params *)old_params)->list) ||
       (((*(byte *)(new_params + 4) != 0 && (((c1_function_params *)old_params)->default_count != 0)
         ) && (*(byte *)(new_params + 4) <= ((c1_function_params *)old_params)->default_count)))) {
      arg_word10 = type_compare_parameter_lists
                             (&(*(c1_type_list **)(new_params + 0xc))->count,
                              &((c1_function_params *)old_params)->list->count);
      if (arg_word10 == 1) {
        if (complain != '\0') {
          if ((*(byte *)((int)&probe->tail + 9) & 0x20) == 0) {
            pcVar13 = cand;
            if ((cand->kind & 0x1f) == 0x1a) {
              pcVar13 = ((cur_cell->type).alias)->target;
            }
            if ((*(byte *)((int)&pcVar13->tail + 9) & 0x40) != 0) goto LAB_1040dff3;
          }
          pcVar1 = &cur_cell[-1].position;
          pcVar13 = (c1_symbol *)pcVar1;
          if ((cur_cell[-1].position & 0x1f) == 0x1a) {
            pcVar13 = ((cur_cell->type).alias)->target;
          }
          diag_error(0x243,probe,pcVar13);
          pcVar13 = (c1_symbol *)pcVar1;
          if ((*pcVar1 & 0x1f) == 0x1a) {
            pcVar13 = ((cur_cell->type).alias)->target;
          }
          pcVar13->flags3 = pcVar13->flags3 | 4;
          if ((*pcVar1 & 0x1f) == 0x1a) {
            return (void **)((cur_cell->type).alias)->target;
          }
          goto LAB_10472047;
        }
        goto LAB_1040deb6;
      }
      if (arg_word10 == 2) goto LAB_1040deb6;
    }
  }
LAB_1040dff3:
  pcVar13 = probe;
  if (complain != '\0') {
    if (g_block_depth < 2) {
      if ((g_current_scope->current->kind == 0xff) && ((cand->kind & 0x1f) == 0x1a)) {
        ((cur_cell->type).alias)->hidden = '\x01';
        goto LAB_1040deb6;
      }
    }
    else if (((cand->kind & 0x1f) == 0x1a) &&
            (pcVar12 = ((cur_cell->type).alias)->target, probe != pcVar12)) {
      diag_error(0x373,probe,pcVar12);
    }
  }
  pcVar9 = type_function_return(pcVar11);
  pcVar10 = type_function_return(type);
  iVar7 = type_compare_template_instance_chain(pcVar10,pcVar9);
  pcVar12 = probe;
  if (iVar7 == 0) {
    pcVar11 = type_function_return(pcVar11);
    pcVar9 = type_function_return(type);
    if ((pcVar9 == pcVar11) && (complain != '\0')) {
      if ((g_compile_flags_cc & 0x40) == 0) {
        pcVar12 = (c1_symbol *)&cur_cell[-1].position;
        if ((cur_cell[-1].position & 0x1f) == 0x1a) {
          pcVar12 = ((cur_cell->type).alias)->target;
        }
        if ((((*(byte *)((int)&pcVar12->tail + 9) & 0x80) != 0) && ((pcVar13->flags23 & 0x40) == 0))
           && (*(byte *)((int)&pcVar13->tail + 9) = *(byte *)((int)&pcVar13->tail + 9) | 0x80,
              d != (c1_declarator *)0x0)) {
          d->flags57 = d->flags57 | 1;
        }
      }
      if (((g_compile_flags_cc & 0x41) == 0) && ((g_compile_flags_cc & 0x20000) == 0)) {
        pcVar13 = (c1_symbol *)&cur_cell[-1].position;
        if ((cur_cell[-1].position & 0x1f) == 0x1a) {
          pcVar13 = ((cur_cell->type).alias)->target;
        }
        decl_check_default_argument_redefinition
                  ((c1_function_params *)new_params,(c1_function_params *)old_params,pcVar13,mode);
      }
    }
    if ((cur_cell[-1].position & 0x1f) != 0x1a) {
      return (void **)&cur_cell[-1].position;
    }
    return (void **)((cur_cell->type).alias)->target;
  }
  if (complain != '\0') {
    if ((cand->kind & 0x1f) == 0x1a) {
      cand = ((cur_cell->type).alias)->target;
    }
    if ((((*(byte *)((int)&cand->tail + 9) & 0x40) == 0) &&
        ((*(byte *)((int)&probe->tail + 9) & 0x40) == 0)) &&
       (((g_compile_flags_cc & 0x100000) == 0 && ((g_compile_flags_cc & 0x200000) == 0)))) {
      pcVar13 = (c1_symbol *)&cur_cell[-1].position;
      if ((cur_cell[-1].position & 0x1f) == 0x1a) {
        pcVar13 = ((cur_cell->type).alias)->target;
      }
      diag_error(0x22c,probe,pcVar13);
      pcVar12->flags3 = pcVar12->flags3 | 4;
      if ((cur_cell[-1].position & 0x1f) == 0x1a) {
        return (void **)((cur_cell->type).alias)->target;
      }
LAB_10472047:
      return (void **)&cur_cell[-1].position;
    }
  }
  goto LAB_1040deb6;
}

