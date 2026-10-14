c1_node * __thiscall conv_build_resolved_function_address(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *pcVar1;
  char cVar2;
  byte bVar3;
  c1_node *pcVar4;
  int iVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  fe_name **ppfVar9;
  uint uStack_48;
  c1xx_ovl_set_iter cStack_44;
  undefined4 *puStack_34;
  c1_tmpl_deduction cStack_30;
  
  if (((*(byte *)((int)&((conv->via).function)->tail + 9) & 0x40) != 0) &&
     ((((conv->via).function)->flags2 & 4) == 0)) {
    pcVar6 = conv->overload_set;
    if ((pcVar6->kind & 0x1f) == 0x12) {
      pcVar6 = *(c1_symbol **)(*(int *)pcVar6->type + 8);
    }
    ovl_set_iter_init(&cStack_44,(void *)0x0);
    puStack_34 = (undefined4 *)0x0;
    cStack_44.vtbl = (c1xx_ovl_set_iter_vtbl *)&UNK_104cb244;
    if ((pcVar6->kind & 0x1f) == 0x1b) {
      puStack_34 = *(undefined4 **)pcVar6->type;
      cStack_44.current = (c1_sym_link *)0x0;
      ppfVar9 = &((c1_symbol *)*puStack_34)->name;
      cStack_44.start = (c1_sym_link *)ppfVar9;
      iVar5 = sym_is_data_or_function_2((c1_symbol *)*puStack_34);
      if (((char)iVar5 == '\0') && ((cStack_44.start[-1].position & 0x1f) != 0x1a)) {
        puStack_34 = (undefined4 *)puStack_34[2];
        cStack_44.next = (cStack_44.start)->type;
      }
      else {
        puStack_34 = (undefined4 *)puStack_34[2];
        cStack_44.next = (c1_sym_link *)ppfVar9;
      }
    }
    else {
      sym_overload_iter_init(&cStack_44,(c1_u8 *)&pcVar6->name);
    }
    do {
      do {
        cVar2 = ovl_set_iter_next(&cStack_44);
        if (cVar2 == '\0') {
          if (puStack_34 == (undefined4 *)0x0) goto LAB_1043f1d0;
          cStack_44.current = (c1_sym_link *)0x0;
          ppfVar9 = &((c1_symbol *)*puStack_34)->name;
          cStack_44.start = (c1_sym_link *)ppfVar9;
          iVar5 = sym_is_data_or_function_2((c1_symbol *)*puStack_34);
          cStack_44.next = (c1_sym_link *)ppfVar9;
          if (((char)iVar5 == '\0') && ((cStack_44.start[-1].position & 0x1f) != 0x1a)) {
            cStack_44.next = (cStack_44.start)->type;
          }
          puStack_34 = (undefined4 *)puStack_34[2];
        }
        pcVar6 = (c1_symbol *)&cStack_44.current[-1].position;
        pcVar8 = pcVar6;
        if ((cStack_44.current[-1].position & 0x1f) == 0x1a) {
          pcVar8 = (((cStack_44.current)->type).alias)->target;
        }
      } while ((*(byte *)((int)&pcVar8->tail + 9) & 0x20) == 0);
      if ((*(c1_u32 *)pcVar6 & 0x1f) == 0x1a) {
        pcVar6 = (((cStack_44.current)->type).alias)->target;
      }
      tmpl_deduction_begin(&cStack_30,pcVar6,(c1_arg_list *)0x0,0,'\0');
      bVar3 = tmpl_compare_argument_lists(&cStack_30,(conv->via).function);
    } while (bVar3 == 0);
    pcVar6 = (c1_symbol *)&cStack_44.current[-1].position;
    if ((cStack_44.current[-1].position & 0x1f) == 0x1a) {
      pcVar6 = (((cStack_44.current)->type).alias)->target;
    }
    bVar3 = 0;
    pcVar7 = type_base(conv->target);
    tmpl_deduce_from_target_type(pcVar7,pcVar6,bVar3);
  }
LAB_1043f1d0:
  pcVar6 = (conv->via).function;
  if (((pcVar6->flags1 & 0x10) == 0x10) || ((pcVar6->flags1 & 0x20) == 0x20)) {
    diag_error(0x115,pcVar6);
    pcVar4 = (c1_node *)0x0;
  }
  else {
    pcVar8 = conv->function_ref->left;
    if ((pcVar8->kind & 0x1f) == 0x12) {
      expr_set_overload_target_and_check_access(pcVar8,(int)pcVar6);
    }
    pcVar4 = conv->function_ref;
    pcVar7 = ((conv->via).function)->type;
    if (((pcVar7->code & 0x8f) == 0x85) && ((((pcVar7->extra).cls)->flags5 & 1) == 0)) {
      if (g_ms_extensions == '\0') {
        uStack_48 = 0;
        pcVar4 = expr_strip_to_function_ref(conv->expr,&uStack_48);
        if ((((uStack_48 & 4) != 0) || (pcVar4->right == (void *)0x0)) || ((uStack_48 & 2) == 0)) {
          diag_begin_global(g_token_position);
          bVar3 = diag_warning(1,0xfd,(conv->via).function);
          if ((g_opt_Zc != '\0') && (bVar3 != 0)) {
            diag_note(0x1839,5,0);
          }
          diag_end_global();
        }
      }
      pcVar4 = expr_address_of_member(pcVar8);
    }
    else {
      pcVar4->left = (conv->via).function;
      pcVar4->type = conv->first->source;
    }
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->reference_symbol)((int)(conv->via).function);
    }
    pcVar1 = conv->first;
    iVar5 = conv->target_kind;
    pcVar1->target_symbol = conv->target_symbol;
    pcVar1->target_kind = iVar5;
    pcVar1 = conv->first;
    pcVar1->expr = pcVar4;
    pcVar4 = conv_apply_conversion(pcVar1,dest);
    if (conv->target_class == 0xf) {
      if (dest != (c1_node *)0x0) {
        pcVar4 = tree_new_init_assign(dest,pcVar4);
      }
      pcVar4 = expr_build_builtin_unary(0x3d,pcVar4);
      return pcVar4;
    }
    if (dest != (c1_node *)0x0) {
      pcVar4 = conv_store_converted_value(conv,dest,pcVar4);
      return pcVar4;
    }
  }
  return pcVar4;
}

