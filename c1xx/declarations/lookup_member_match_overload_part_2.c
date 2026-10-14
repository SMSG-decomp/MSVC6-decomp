void ** __cdecl
lookup_member_match_overload_part_2
          (int zero,c1_symbol *probe_reg,c1_sym_link *cell,c1_symbol *cand,int *old_params,
          int new_params,c1_type *new_this_type,c1_sym_link *next_cell,c1_sym_link *cur_cell,
          c1_sym_link *cursor,int *deduction_args,int *deduction2_args,c1_type *type,char complain,
          char skip_templates,c1_symbol *probe,c1_declarator *d,int mode)

{
  c1_u32 *pcVar1;
  char cVar2;
  c1_u8 *pcVar3;
  c1_sym_link *cell_00;
  c1_declarator *pcVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  void **ppvVar9;
  c1_type *pcVar10;
  c1_type *pcVar11;
  c1_type *pcVar12;
  uint *arg_copy_2;
  uint *arg_copy_3;
  c1_symbol *pcVar13;
  uint *arg_copy_4;
  c1_arg_item *pcVar14;
  uint *arg_copy;
  c1_symbol *pcVar15;
  c1_deferred_action *pcVar16;
  c1_arg_item *pcVar17;
  uint arg_value;
  uint arg_value_2;
  uint arg_value_3;
  
  tmpl_deduction_begin
            ((c1_tmpl_deduction *)&stack0x0000005c,probe_reg,(c1_arg_list *)zero,(byte)zero,
             (byte)zero);
  pcVar15 = cand;
  if ((cand->kind & 0x1f) == 0x1a) {
    pcVar15 = ((cell->type).alias)->target;
  }
  bVar5 = tmpl_compare_argument_lists((c1_tmpl_deduction *)&stack0x0000005c,pcVar15);
  if (bVar5 != 0) {
    if ((cand->kind & 0x1f) == 0x1a) {
      cand = ((cur_cell->type).alias)->target;
    }
    if (((cand->flags2 & 4) == 0) && ((cand->flags21 & 4) != 0)) {
      bVar5 = *(byte *)((int)&cand->tail + 9) | 0x40;
    }
    else {
      bVar5 = *(byte *)((int)&cand->tail + 9) | 0x80;
    }
    *(byte *)((int)&cand->tail + 9) = bVar5;
    symtab_1604_insert(cand,probe);
    pcVar3 = g_arenas[0].cur;
    old_params = (int *)(g_arenas[0].cur + 0xc);
    g_arenas[0].cur = (c1_u8 *)old_params;
    if (g_arenas[0].end < old_params) {
      arena_grow(g_arenas);
    }
    if (pcVar3 == (c1_u8 *)0x0) {
      symtab_15f4_insert(cand,(void *)0x0);
    }
    else {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3[4] = '\0';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      pcVar17 = (c1_arg_item *)*deduction2_args;
      if ((*(byte *)(deduction2_args + 2) & 1) != 0) {
        pcVar3[8] = pcVar3[8] | 1;
      }
      do {
        if ((pcVar17->kind & 3) == 0) {
          arg_copy = arena_alloc(g_arenas,0x14);
          if (arg_copy == (uint *)0x0) {
LAB_10471e28:
            arg_copy = (uint *)0x0;
          }
          else {
            tmpl_argument_copy_base((c1_arg_item *)arg_copy,pcVar17);
            arg_value = *(uint *)&pcVar17->value;
            *arg_copy = (uint)&PTR_pch_fixup_list_object_104c4c3c;
            arg_copy[4] = arg_value;
          }
        }
        else {
          pcVar14 = arena_alloc(g_arenas,0x14);
          if (pcVar14 == (c1_arg_item *)0x0) goto LAB_10471e28;
          arg_copy = (uint *)tmpl_argument_copy_nontype(pcVar14,pcVar17);
        }
        if (*(int *)pcVar3 == 0) {
          *(uint **)pcVar3 = arg_copy;
        }
        else {
          *(uint **)(*(int *)(pcVar3 + 4) + 4) = arg_copy;
          ((c1_arg_item *)arg_copy)->prev = *(c1_arg_item **)(pcVar3 + 4);
        }
        *(uint **)(pcVar3 + 4) = arg_copy;
        pcVar17 = pcVar17->next;
      } while (pcVar17 != (c1_arg_item *)0x0);
      symtab_15f4_insert(cand,pcVar3);
    }
  }
LAB_1040deb6:
  do {
    cell_00 = next_cell;
    if ((cursor == (c1_sym_link *)0x0) || (next_cell == (c1_sym_link *)0x0)) {
      if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
        pcVar16 = g_deferred_actions_head;
        if (g_tmpl_deduction_depth < 1) {
          do {
            (**pcVar16->vtbl)();
            pcVar16 = pcVar16->next;
          } while (pcVar16 != (c1_deferred_action *)0x0);
        }
        g_deferred_actions_tail = (c1_deferred_action *)0x0;
        g_deferred_actions_head = (c1_deferred_action *)0x0;
      }
      return (void **)0x0;
    }
    iVar7 = sym_is_data_or_function_2((c1_symbol *)&cursor[-1].position);
    pcVar15 = probe;
    if (((char)iVar7 == '\0') && ((cursor[-1].position & 0x1f) != 0x1a)) {
      next_cell = next_cell->next;
    }
    else {
      next_cell = (c1_sym_link *)0x0;
    }
    pcVar13 = (c1_symbol *)&cell_00[-1].position;
    bVar5 = (byte)cell_00[-1].position & 0x1f;
    pcVar8 = pcVar13;
    if (bVar5 == 0x1a) {
      pcVar8 = ((cell_00->type).alias)->target;
    }
  } while (((*(byte *)((int)&pcVar8->tail + 9) & 0x20) != 0) && (skip_templates != '\0'));
  if (complain != '\0') {
    if ((g_compile_flags_cc & 0x40) != 0) {
      pcVar8 = pcVar13;
      if (bVar5 == 0x1a) {
        pcVar8 = ((cell_00->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar8->tail + 9) & 0x20) != 0) goto LAB_1040deb6;
    }
    if ((((g_compile_flags_cc & 8) != 0) && ((g_compile_flags_cc & 0x20000) == 0)) &&
       ((*(byte *)((int)&probe->tail + 9) & 0x40) != 0)) {
      ppvVar9 = lookup_member_match_overload_part_1
                          (bVar5,g_compile_flags_cc,0,probe,cell_00,pcVar13,old_params,new_params,
                           new_this_type,next_cell,cell_00,cursor,deduction_args,deduction2_args,
                           type,complain,skip_templates,probe,d,mode);
      return ppvVar9;
    }
    if (((g_compile_flags_cc & 0x200000) == 0) && ((*(byte *)((int)&probe->tail + 9) & 0x60) == 0))
    {
      pcVar8 = pcVar13;
      if (bVar5 == 0x1a) {
        pcVar8 = ((cell_00->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar8->tail + 9) & 0x20) != 0) {
        pcVar8 = pcVar13;
        if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
          pcVar8 = ((cell_00->type).alias)->target;
        }
        tmpl_deduction_begin((c1_tmpl_deduction *)&stack0x0000002c,pcVar8,(c1_arg_list *)0x0,0,'\0')
        ;
        bVar5 = tmpl_compare_argument_lists((c1_tmpl_deduction *)&stack0x0000002c,pcVar15);
        pcVar4 = d;
        pcVar8 = probe;
        if (bVar5 != 0) {
          if (((g_compile_flags_cc & 8) == 0) || ((pcVar15->flags21 & 4) == 0)) {
            bVar5 = *(byte *)((int)&probe->tail + 9);
            if ((pcVar15->flags23 & 0x40) == 0) {
              *(byte *)((int)&probe->tail + 9) = bVar5 | 0x80;
            }
            else {
              *(byte *)((int)&probe->tail + 9) = bVar5 | 0x80;
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
          pcVar15 = pcVar13;
          if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
            pcVar15 = ((cell_00->type).alias)->target;
          }
          decl_check_default_argument_redefinition
                    (*(c1_function_params **)
                      (((uint)pcVar15->type & -(uint)((pcVar15->type->code & 0x80) != 0)) + 8),
                     (c1_function_params *)new_params,probe,iVar7);
          if (pcVar4 == (c1_declarator *)0x0) {
            if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
              pcVar13 = ((cell_00->type).alias)->target;
            }
            symtab_1604_insert(pcVar8,pcVar13);
            pcVar3 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar3 == (c1_u8 *)0x0) {
              symtab_15f4_insert(probe,(void *)0x0);
            }
            else {
              pcVar3[0] = '\0';
              pcVar3[1] = '\0';
              pcVar3[2] = '\0';
              pcVar3[3] = '\0';
              pcVar3[4] = '\0';
              pcVar3[5] = '\0';
              pcVar3[6] = '\0';
              pcVar3[7] = '\0';
              pcVar17 = (c1_arg_item *)*deduction_args;
              if ((*(byte *)(deduction_args + 2) & 1) != 0) {
                pcVar3[8] = pcVar3[8] | 1;
              }
              do {
                if ((pcVar17->kind & 3) == 0) {
                  arg_copy_4 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_4 == (uint *)0x0) {
LAB_10471c93:
                    arg_copy_4 = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy_4,pcVar17);
                    arg_value_3 = *(uint *)&pcVar17->value;
                    *arg_copy_4 = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    arg_copy_4[4] = arg_value_3;
                  }
                }
                else {
                  pcVar14 = arena_alloc(g_arenas,0x14);
                  if (pcVar14 == (c1_arg_item *)0x0) goto LAB_10471c93;
                  arg_copy_4 = (uint *)tmpl_argument_copy_nontype(pcVar14,pcVar17);
                }
                if (*(int *)pcVar3 == 0) {
                  *(uint **)pcVar3 = arg_copy_4;
                }
                else {
                  *(uint **)(*(int *)(pcVar3 + 4) + 4) = arg_copy_4;
                  ((c1_arg_item *)arg_copy_4)->prev = *(c1_arg_item **)(pcVar3 + 4);
                }
                *(uint **)(pcVar3 + 4) = arg_copy_4;
                pcVar17 = pcVar17->next;
              } while (pcVar17 != (c1_arg_item *)0x0);
              symtab_15f4_insert(probe,pcVar3);
            }
          }
          else {
            if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
              pcVar13 = ((cell_00->type).alias)->target;
            }
            pcVar4->specialized_template = pcVar13;
            pcVar3 = g_arenas[0].cur;
            old_params = (int *)(g_arenas[0].cur + 0xc);
            g_arenas[0].cur = (c1_u8 *)old_params;
            if (g_arenas[0].end < old_params) {
              arena_grow(g_arenas);
            }
            if (pcVar3 == (c1_u8 *)0x0) {
              pcVar4->template_args = (c1_arg_list *)0x0;
            }
            else {
              pcVar3[0] = '\0';
              pcVar3[1] = '\0';
              pcVar3[2] = '\0';
              pcVar3[3] = '\0';
              pcVar3[4] = '\0';
              pcVar3[5] = '\0';
              pcVar3[6] = '\0';
              pcVar3[7] = '\0';
              pcVar17 = (c1_arg_item *)*deduction_args;
              if ((*(byte *)(deduction_args + 2) & 1) != 0) {
                pcVar3[8] = pcVar3[8] | 1;
              }
              do {
                if ((pcVar17->kind & 3) == 0) {
                  arg_copy_2 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_2 == (uint *)0x0) {
LAB_10471b98:
                    arg_copy_2 = (uint *)0x0;
                  }
                  else {
                    tmpl_argument_copy_base((c1_arg_item *)arg_copy_2,pcVar17);
                    arg_value_2 = *(uint *)&pcVar17->value;
                    *arg_copy_2 = (uint)&PTR_pch_fixup_list_object_104c4c3c;
                    arg_copy_2[4] = arg_value_2;
                  }
                }
                else {
                  arg_copy_3 = arena_alloc(g_arenas,0x14);
                  if (arg_copy_3 == (uint *)0x0) goto LAB_10471b98;
                  arg_copy_2 = (uint *)tmpl_argument_copy_nontype((c1_arg_item *)arg_copy_3,pcVar17)
                  ;
                }
                if (*(int *)pcVar3 == 0) {
                  *(uint **)pcVar3 = arg_copy_2;
                }
                else {
                  *(uint **)(*(int *)(pcVar3 + 4) + 4) = arg_copy_2;
                  ((c1_arg_item *)arg_copy_2)->prev = *(c1_arg_item **)(pcVar3 + 4);
                }
                *(uint **)(pcVar3 + 4) = arg_copy_2;
                pcVar17 = pcVar17->next;
              } while (pcVar17 != (c1_arg_item *)0x0);
              pcVar4->template_args = (c1_arg_list *)pcVar3;
            }
          }
          goto LAB_1040deb6;
        }
      }
    }
    if ((g_compile_flags_cc & 0x20) != 0) {
      bVar5 = (byte)*(c1_u32 *)pcVar13 & 0x1f;
      pcVar8 = pcVar13;
      if (bVar5 == 0x1a) {
        pcVar8 = ((cell_00->type).alias)->target;
      }
      if ((*(byte *)((int)&pcVar8->tail + 9) & 0x20) == 0) {
        pcVar8 = pcVar13;
        if (bVar5 == 0x1a) {
          pcVar8 = ((cell_00->type).alias)->target;
        }
        if ((*(byte *)((int)&pcVar8->tail + 9) & 0x40) == 0) {
          pcVar8 = pcVar13;
          if (bVar5 == 0x1a) {
            pcVar8 = ((cell_00->type).alias)->target;
          }
          if ((*(c1_u32 *)&pcVar8->kind & 0x1f) != 8) {
            ppvVar9 = lookup_member_match_overload_part_2
                                (0,pcVar15,cell_00,pcVar13,old_params,new_params,new_this_type,
                                 next_cell,cell_00,cursor,deduction_args,deduction2_args,type,
                                 complain,skip_templates,probe,d,mode);
            return ppvVar9;
          }
        }
      }
    }
  }
  pcVar15 = pcVar13;
  if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
    pcVar15 = ((cell_00->type).alias)->target;
  }
  pcVar12 = pcVar15->type;
  old_params = (int *)(pcVar12->extra).params;
  pcVar10 = ((c1_function_params *)old_params)->this_type;
  if (type != pcVar12) {
    if (new_this_type != pcVar10) {
      if (new_this_type == (c1_type *)0x0) {
        if ((((c1_function_params *)old_params)->flags & 1) == 0) goto LAB_1040deb6;
      }
      else {
        if (pcVar10 == (c1_type *)0x0) goto LAB_1040deb6;
        cVar2 = (char)new_this_type->code;
        pcVar11 = new_this_type;
        while (cVar2 < '\0') {
          pcVar11 = pcVar11->base;
          cVar2 = (char)pcVar11->code;
        }
        if ((pcVar11->code & 0x8f) == 0x83) {
          pcVar11 = type_skip_arrays(pcVar11->base);
        }
        cVar2 = (char)pcVar10->code;
        while (cVar2 < '\0') {
          pcVar10 = pcVar10->base;
          cVar2 = (char)pcVar10->code;
        }
        if ((pcVar10->code & 0x8f) == 0x83) {
          pcVar10 = type_skip_arrays(pcVar10->base);
        }
        if (((pcVar10->flags ^ pcVar11->flags) & 0x3e0) != 0) goto LAB_1040deb6;
      }
    }
    if ((*(c1_type_list **)(new_params + 0xc) != ((c1_function_params *)old_params)->list) ||
       (((*(byte *)(new_params + 4) != 0 && (((c1_function_params *)old_params)->default_count != 0)
         ) && (*(byte *)(new_params + 4) <= ((c1_function_params *)old_params)->default_count)))) {
      uVar6 = type_compare_parameter_lists
                        (&(*(c1_type_list **)(new_params + 0xc))->count,
                         &((c1_function_params *)old_params)->list->count);
      if (uVar6 == 1) {
        if (complain != '\0') {
          if ((*(byte *)((int)&probe->tail + 9) & 0x20) == 0) {
            pcVar15 = pcVar13;
            if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
              pcVar15 = ((cell_00->type).alias)->target;
            }
            if ((*(byte *)((int)&pcVar15->tail + 9) & 0x40) != 0) goto LAB_1040dff3;
          }
          pcVar1 = &cell_00[-1].position;
          pcVar15 = (c1_symbol *)pcVar1;
          if ((cell_00[-1].position & 0x1f) == 0x1a) {
            pcVar15 = ((cell_00->type).alias)->target;
          }
          diag_error(0x243,probe,pcVar15);
          pcVar15 = (c1_symbol *)pcVar1;
          if ((*pcVar1 & 0x1f) == 0x1a) {
            pcVar15 = ((cell_00->type).alias)->target;
          }
          pcVar15->flags3 = pcVar15->flags3 | 4;
          if ((*pcVar1 & 0x1f) == 0x1a) {
            return (void **)((cell_00->type).alias)->target;
          }
          goto LAB_10472047;
        }
        goto LAB_1040deb6;
      }
      if (uVar6 == 2) goto LAB_1040deb6;
    }
  }
LAB_1040dff3:
  pcVar15 = probe;
  if (complain != '\0') {
    if (g_block_depth < 2) {
      if ((g_current_scope->current->kind == 0xff) && ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a)) {
        ((cell_00->type).alias)->hidden = '\x01';
        goto LAB_1040deb6;
      }
    }
    else if (((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) &&
            (pcVar8 = ((cell_00->type).alias)->target, probe != pcVar8)) {
      diag_error(0x373,probe,pcVar8);
    }
  }
  pcVar10 = type_function_return(pcVar12);
  pcVar11 = type_function_return(type);
  iVar7 = type_compare_template_instance_chain(pcVar11,pcVar10);
  pcVar8 = probe;
  if (iVar7 == 0) {
    pcVar12 = type_function_return(pcVar12);
    pcVar10 = type_function_return(type);
    if ((pcVar10 == pcVar12) && (complain != '\0')) {
      if ((g_compile_flags_cc & 0x40) == 0) {
        pcVar13 = (c1_symbol *)&cell_00[-1].position;
        if ((cell_00[-1].position & 0x1f) == 0x1a) {
          pcVar13 = ((cell_00->type).alias)->target;
        }
        if ((((*(byte *)((int)&pcVar13->tail + 9) & 0x80) != 0) && ((pcVar15->flags23 & 0x40) == 0))
           && (*(byte *)((int)&pcVar15->tail + 9) = *(byte *)((int)&pcVar15->tail + 9) | 0x80,
              d != (c1_declarator *)0x0)) {
          d->flags57 = d->flags57 | 1;
        }
      }
      if (((g_compile_flags_cc & 0x41) == 0) && ((g_compile_flags_cc & 0x20000) == 0)) {
        pcVar15 = (c1_symbol *)&cell_00[-1].position;
        if ((cell_00[-1].position & 0x1f) == 0x1a) {
          pcVar15 = ((cell_00->type).alias)->target;
        }
        decl_check_default_argument_redefinition
                  ((c1_function_params *)new_params,(c1_function_params *)old_params,pcVar15,mode);
      }
    }
    if ((cell_00[-1].position & 0x1f) != 0x1a) {
      return (void **)&cell_00[-1].position;
    }
    return (void **)((cell_00->type).alias)->target;
  }
  if (complain != '\0') {
    if ((*(c1_u32 *)pcVar13 & 0x1f) == 0x1a) {
      pcVar13 = ((cell_00->type).alias)->target;
    }
    if ((((*(byte *)((int)&pcVar13->tail + 9) & 0x40) == 0) &&
        ((*(byte *)((int)&probe->tail + 9) & 0x40) == 0)) &&
       (((g_compile_flags_cc & 0x100000) == 0 && ((g_compile_flags_cc & 0x200000) == 0)))) {
      pcVar15 = (c1_symbol *)&cell_00[-1].position;
      if ((cell_00[-1].position & 0x1f) == 0x1a) {
        pcVar15 = ((cell_00->type).alias)->target;
      }
      diag_error(0x22c,probe,pcVar15);
      pcVar8->flags3 = pcVar8->flags3 | 4;
      if ((cell_00[-1].position & 0x1f) == 0x1a) {
        return (void **)((cell_00->type).alias)->target;
      }
LAB_10472047:
      return (void **)&cell_00[-1].position;
    }
  }
  goto LAB_1040deb6;
}

