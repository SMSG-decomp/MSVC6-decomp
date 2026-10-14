void ** __cdecl
ovl_chain_find_function_with_type
          (c1_symbol *sym,c1_type *type,char complain,char skip_templates,c1_symbol *probe,
          c1_declarator *d,int mode)

{
  fe_name **ppfVar1;
  c1_u32 *pcVar2;
  char cVar3;
  c1_arg_value cVar4;
  c1_u8 *pcVar5;
  int iVar6;
  uint word;
  void **ppvVar7;
  c1_type *pcVar8;
  c1_type *pcVar9;
  c1_type *pcVar10;
  c1_type_extra *pcVar11;
  uint *arg_copy;
  uint *arg_copy_2;
  c1_symbol *pcVar12;
  uint *arg_copy_3;
  uint *arg_copy_4;
  c1_symbol *pcVar13;
  byte bVar14;
  c1_deferred_action *pcVar15;
  c1_arg_item *pcVar16;
  int *old_params;
  c1_type *pcVar17;
  c1_type *pcVar18;
  c1_sym_link *pcVar19;
  c1_sym_link *pcVar20;
  c1_tmpl_deduction deduction;
  c1_tmpl_deduction deduction2;
  int *new_params;
  c1_sym_link *cur_cell;
  
  new_params = (int *)(type->extra).params;
  ppfVar1 = &sym->name;
  pcVar10 = ((c1_function_params *)new_params)->this_type;
  pcVar18 = (c1_type *)0x0;
  pcVar20 = (c1_sym_link *)ppfVar1;
  if (((ppfVar1 != (fe_name **)0x0) &&
      (iVar6 = sym_is_data_or_function_2(sym), pcVar18 = (c1_type *)ppfVar1, (char)iVar6 == '\0'))
     && ((sym->kind & 0x1f) != 0x1a)) {
    pcVar18 = sym->type;
  }
LAB_1040deb6:
  do {
    pcVar17 = pcVar18;
    if ((pcVar20 == (c1_sym_link *)0x0) || (pcVar17 == (c1_type *)0x0)) {
      if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
        pcVar15 = g_deferred_actions_head;
        if (g_tmpl_deduction_depth < 1) {
          do {
            (**pcVar15->vtbl)();
            pcVar15 = pcVar15->next;
          } while (pcVar15 != (c1_deferred_action *)0x0);
        }
        g_deferred_actions_tail = (c1_deferred_action *)0x0;
        g_deferred_actions_head = (c1_deferred_action *)0x0;
      }
      return (void **)0x0;
    }
    cur_cell = (c1_sym_link *)pcVar17;
    pcVar19 = pcVar20;
    iVar6 = sym_is_data_or_function_2((c1_symbol *)&pcVar20[-1].position);
    if (((char)iVar6 == '\0') && ((pcVar20[-1].position & 0x1f) != 0x1a)) {
      pcVar18 = pcVar17->base;
    }
    else {
      pcVar18 = (c1_type *)0x0;
    }
    pcVar12 = (c1_symbol *)&pcVar17[-1].extra;
    bVar14 = *(byte *)&pcVar17[-1].extra & 0x1f;
    pcVar11 = (c1_type_extra *)pcVar12;
    if (bVar14 == 0x1a) {
      pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
    }
    pcVar20 = pcVar19;
  } while (((*(byte *)((int)pcVar11 + 0x35) & 0x20) != 0) && (skip_templates != '\0'));
  if (complain != '\0') {
    if ((g_compile_flags_cc & 0x40) != 0) {
      pcVar11 = (c1_type_extra *)pcVar12;
      if (bVar14 == 0x1a) {
        pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
      }
      if ((*(byte *)((int)pcVar11 + 0x35) & 0x20) != 0) goto LAB_1040deb6;
    }
    if ((((g_compile_flags_cc & 8) != 0) && ((g_compile_flags_cc & 0x20000) == 0)) &&
       ((*(byte *)((int)&probe->tail + 9) & 0x40) != 0)) {
      ppvVar7 = lookup_member_match_overload_part_1
                          (bVar14,g_compile_flags_cc,0,probe,(c1_sym_link *)pcVar17,pcVar12,
                           old_params,(int)new_params,pcVar10,(c1_sym_link *)pcVar18,cur_cell,
                           pcVar19,(int *)deduction.args,(int *)deduction2.args,type,complain,
                           skip_templates,probe,d,mode);
      return ppvVar7;
    }
    if (((g_compile_flags_cc & 0x200000) == 0) && ((*(byte *)((int)&probe->tail + 9) & 0x60) == 0))
    {
      pcVar11 = (c1_type_extra *)pcVar12;
      if (bVar14 == 0x1a) {
        pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
      }
      if ((*(byte *)((int)pcVar11 + 0x35) & 0x20) != 0) {
        pcVar13 = pcVar12;
        if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
          pcVar13 = *(c1_symbol **)pcVar17->debug_index;
        }
        tmpl_deduction_begin(&deduction,pcVar13,(c1_arg_list *)0x0,0,'\0');
        bVar14 = tmpl_compare_argument_lists(&deduction,probe);
        if (bVar14 != 0) {
          if (((g_compile_flags_cc & 8) == 0) || ((probe->flags21 & 4) == 0)) {
            bVar14 = *(byte *)((int)&probe->tail + 9);
            if ((probe->flags23 & 0x40) == 0) {
              *(byte *)((int)&probe->tail + 9) = bVar14 | 0x80;
            }
            else {
              *(byte *)((int)&probe->tail + 9) = bVar14 | 0x80;
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
          iVar6 = mode;
          if (mode == 1) {
            iVar6 = 2;
          }
          pcVar11 = (c1_type_extra *)pcVar12;
          if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
            pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
          }
          decl_check_default_argument_redefinition
                    (*(c1_function_params **)
                      (((uint)pcVar11[5].cls & -(uint)(((pcVar11[5].cls)->kind & 0x80) != 0)) + 8),
                     (c1_function_params *)new_params,probe,iVar6);
          if (d == (c1_declarator *)0x0) {
            if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
              pcVar12 = *(c1_symbol **)pcVar17->debug_index;
            }
            symtab_1604_insert(probe,pcVar12);
            pcVar5 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar5 == (c1_u8 *)0x0) {
              symtab_15f4_insert(probe,(void *)0x0);
              pcVar20 = pcVar19;
            }
            else {
              pcVar5[0] = '\0';
              pcVar5[1] = '\0';
              pcVar5[2] = '\0';
              pcVar5[3] = '\0';
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              pcVar5[6] = '\0';
              pcVar5[7] = '\0';
              pcVar16 = (deduction.args)->first;
              if (((deduction.args)->flags & 1) != 0) {
                pcVar5[8] = pcVar5[8] | 1;
              }
              do {
                if ((pcVar16->kind & 3) == 0) {
                  arg_copy_3 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_3 == (uint *)0x0) {
LAB_10471c93:
                    arg_copy_3 = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy_3,pcVar16);
                    cVar4 = pcVar16->value;
                    *arg_copy_3 = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    *(c1_arg_value *)(arg_copy_3 + 4) = cVar4;
                  }
                }
                else {
                  arg_copy_4 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_4 == (uint *)0x0) goto LAB_10471c93;
                  arg_copy_3 = (uint *)tmpl_argument_copy_nontype((c1_arg_item *)arg_copy_4,pcVar16)
                  ;
                }
                if (*(int *)pcVar5 == 0) {
                  *(uint **)pcVar5 = arg_copy_3;
                }
                else {
                  *(uint **)(*(int *)(pcVar5 + 4) + 4) = arg_copy_3;
                  ((c1_arg_item *)arg_copy_3)->prev = *(c1_arg_item **)(pcVar5 + 4);
                }
                *(uint **)(pcVar5 + 4) = arg_copy_3;
                pcVar16 = pcVar16->next;
              } while (pcVar16 != (c1_arg_item *)0x0);
              symtab_15f4_insert(probe,pcVar5);
              pcVar20 = pcVar19;
            }
          }
          else {
            if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
              pcVar12 = *(c1_symbol **)pcVar17->debug_index;
            }
            d->specialized_template = pcVar12;
            pcVar5 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar5 == (c1_u8 *)0x0) {
              d->template_args = (c1_arg_list *)0x0;
              pcVar20 = pcVar19;
            }
            else {
              pcVar5[0] = '\0';
              pcVar5[1] = '\0';
              pcVar5[2] = '\0';
              pcVar5[3] = '\0';
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              pcVar5[6] = '\0';
              pcVar5[7] = '\0';
              pcVar16 = (deduction.args)->first;
              if (((deduction.args)->flags & 1) != 0) {
                pcVar5[8] = pcVar5[8] | 1;
              }
              do {
                if ((pcVar16->kind & 3) == 0) {
                  arg_copy = arena_alloc(g_arenas,0x14);
                  if (arg_copy == (uint *)0x0) {
LAB_10471b98:
                    arg_copy = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy,pcVar16);
                    cVar4 = pcVar16->value;
                    *arg_copy = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    *(c1_arg_value *)(arg_copy + 4) = cVar4;
                  }
                }
                else {
                  arg_copy_2 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_2 == (uint *)0x0) goto LAB_10471b98;
                  arg_copy = (uint *)tmpl_argument_copy_nontype((c1_arg_item *)arg_copy_2,pcVar16);
                }
                if (*(int *)pcVar5 == 0) {
                  *(uint **)pcVar5 = arg_copy;
                }
                else {
                  *(uint **)(*(int *)(pcVar5 + 4) + 4) = arg_copy;
                  ((c1_arg_item *)arg_copy)->prev = *(c1_arg_item **)(pcVar5 + 4);
                }
                *(uint **)(pcVar5 + 4) = arg_copy;
                pcVar16 = pcVar16->next;
              } while (pcVar16 != (c1_arg_item *)0x0);
              d->template_args = (c1_arg_list *)pcVar5;
              pcVar20 = pcVar19;
            }
          }
          goto LAB_1040deb6;
        }
      }
    }
    pcVar20 = pcVar19;
    if ((g_compile_flags_cc & 0x20) != 0) {
      bVar14 = *(byte *)pcVar12 & 0x1f;
      pcVar11 = (c1_type_extra *)pcVar12;
      if (bVar14 == 0x1a) {
        pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
      }
      if ((*(byte *)((int)pcVar11 + 0x35) & 0x20) == 0) {
        pcVar11 = (c1_type_extra *)pcVar12;
        if (bVar14 == 0x1a) {
          pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
        }
        if ((*(byte *)((int)pcVar11 + 0x35) & 0x40) == 0) {
          pcVar11 = (c1_type_extra *)pcVar12;
          if (bVar14 == 0x1a) {
            pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
          }
          if ((*(byte *)pcVar11 & 0x1f) != 8) {
            ppvVar7 = lookup_member_match_overload_part_2
                                (0,probe,(c1_sym_link *)pcVar17,pcVar12,old_params,(int)new_params,
                                 pcVar10,(c1_sym_link *)pcVar18,cur_cell,pcVar19,
                                 (int *)deduction.args,(int *)deduction2.args,type,complain,
                                 skip_templates,probe,d,mode);
            return ppvVar7;
          }
        }
      }
    }
  }
  pcVar11 = (c1_type_extra *)pcVar12;
  if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
    pcVar11 = *(c1_type_extra **)pcVar17->debug_index;
  }
  pcVar17 = (c1_type *)pcVar11[5].cls;
  old_params = (int *)(pcVar17->extra).params;
  pcVar8 = ((c1_function_params *)old_params)->this_type;
  if (type != pcVar17) {
    if (pcVar10 != pcVar8) {
      if (pcVar10 == (c1_type *)0x0) {
        if ((((c1_function_params *)old_params)->flags & 1) == 0) goto LAB_1040deb6;
      }
      else {
        if (pcVar8 == (c1_type *)0x0) goto LAB_1040deb6;
        cVar3 = (char)pcVar10->code;
        pcVar9 = pcVar10;
        while (cVar3 < '\0') {
          pcVar9 = pcVar9->base;
          cVar3 = (char)pcVar9->code;
        }
        if ((pcVar9->code & 0x8f) == 0x83) {
          pcVar9 = type_skip_arrays(pcVar9->base);
        }
        cVar3 = (char)pcVar8->code;
        while (cVar3 < '\0') {
          pcVar8 = pcVar8->base;
          cVar3 = (char)pcVar8->code;
        }
        if ((pcVar8->code & 0x8f) == 0x83) {
          pcVar8 = type_skip_arrays(pcVar8->base);
        }
        if (((pcVar8->flags ^ pcVar9->flags) & 0x3e0) != 0) goto LAB_1040deb6;
      }
    }
    if ((((c1_function_params *)new_params)->list != ((c1_function_params *)old_params)->list) ||
       (((((c1_function_params *)new_params)->default_count != 0 &&
         (((c1_function_params *)old_params)->default_count != 0)) &&
        (((c1_function_params *)new_params)->default_count <=
         ((c1_function_params *)old_params)->default_count)))) {
      word = type_compare_parameter_lists
                       (&((c1_function_params *)new_params)->list->count,
                        &((c1_function_params *)old_params)->list->count);
      if (word == 1) {
        if (complain == '\0') goto LAB_1040deb6;
        if ((*(byte *)((int)&probe->tail + 9) & 0x20) != 0) {
LAB_10471ec9:
          pcVar2 = &cur_cell[-1].position;
          pcVar12 = (c1_symbol *)pcVar2;
          if ((cur_cell[-1].position & 0x1f) == 0x1a) {
            pcVar12 = ((cur_cell->type).alias)->target;
          }
          diag_error(0x243,probe,pcVar12);
          pcVar12 = (c1_symbol *)pcVar2;
          if ((*pcVar2 & 0x1f) == 0x1a) {
            pcVar12 = ((cur_cell->type).alias)->target;
          }
          pcVar12->flags3 = pcVar12->flags3 | 4;
          if ((*pcVar2 & 0x1f) != 0x1a) {
            return (void **)pcVar2;
          }
          return (void **)((cur_cell->type).alias)->target;
        }
        pcVar13 = pcVar12;
        if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
          pcVar13 = ((cur_cell->type).alias)->target;
        }
        if ((*(byte *)((int)&pcVar13->tail + 9) & 0x40) == 0) goto LAB_10471ec9;
      }
      else if (word == 2) goto LAB_1040deb6;
    }
  }
  pcVar19 = cur_cell;
  if (complain != '\0') {
    if (g_block_depth < 2) {
      if ((g_current_scope->current->kind == 0xff) && ((*(byte *)pcVar12 & 0x1f) == 0x1a)) {
        ((cur_cell->type).alias)->hidden = '\x01';
        goto LAB_1040deb6;
      }
    }
    else if (((*(byte *)pcVar12 & 0x1f) == 0x1a) &&
            (pcVar13 = ((cur_cell->type).alias)->target, probe != pcVar13)) {
      diag_error(0x373,probe,pcVar13);
    }
  }
  pcVar8 = type_function_return(pcVar17);
  pcVar9 = type_function_return(type);
  iVar6 = type_compare_template_instance_chain(pcVar9,pcVar8);
  if (iVar6 == 0) {
    pcVar10 = type_function_return(pcVar17);
    pcVar18 = type_function_return(type);
    if ((pcVar18 == pcVar10) && (complain != '\0')) {
      if ((g_compile_flags_cc & 0x40) == 0) {
        pcVar12 = (c1_symbol *)&cur_cell[-1].position;
        if ((cur_cell[-1].position & 0x1f) == 0x1a) {
          pcVar12 = ((cur_cell->type).alias)->target;
        }
        if ((((*(byte *)((int)&pcVar12->tail + 9) & 0x80) != 0) && ((probe->flags23 & 0x40) == 0))
           && (*(byte *)((int)&probe->tail + 9) = *(byte *)((int)&probe->tail + 9) | 0x80,
              d != (c1_declarator *)0x0)) {
          d->flags57 = d->flags57 | 1;
        }
      }
      if (((g_compile_flags_cc & 0x41) == 0) && ((g_compile_flags_cc & 0x20000) == 0)) {
        pcVar12 = (c1_symbol *)&cur_cell[-1].position;
        if ((cur_cell[-1].position & 0x1f) == 0x1a) {
          pcVar12 = ((cur_cell->type).alias)->target;
        }
        decl_check_default_argument_redefinition
                  ((c1_function_params *)new_params,(c1_function_params *)old_params,pcVar12,mode);
      }
    }
    if ((cur_cell[-1].position & 0x1f) != 0x1a) {
      return (void **)&cur_cell[-1].position;
    }
    return (void **)((cur_cell->type).alias)->target;
  }
  if (complain != '\0') {
    if ((*(byte *)pcVar12 & 0x1f) == 0x1a) {
      pcVar12 = ((pcVar19->type).alias)->target;
    }
    if ((((*(byte *)((int)&pcVar12->tail + 9) & 0x40) == 0) &&
        ((*(byte *)((int)&probe->tail + 9) & 0x40) == 0)) &&
       (((g_compile_flags_cc & 0x100000) == 0 && ((g_compile_flags_cc & 0x200000) == 0)))) {
      pcVar2 = &pcVar19[-1].position;
      pcVar12 = (c1_symbol *)pcVar2;
      if ((pcVar19[-1].position & 0x1f) == 0x1a) {
        pcVar12 = ((pcVar19->type).alias)->target;
      }
      diag_error(0x22c,probe,pcVar12);
      probe->flags3 = probe->flags3 | 4;
      if ((*pcVar2 & 0x1f) != 0x1a) {
        return (void **)pcVar2;
      }
      return (void **)((pcVar19->type).alias)->target;
    }
  }
  goto LAB_1040deb6;
}

