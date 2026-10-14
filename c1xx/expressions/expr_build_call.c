int __cdecl expr_build_call(c1_node *callee,c1_node *args)

{
  uint uVar1;
  int iVar2;
  c1_ovl_candidate *pcVar3;
  int is_constructor;
  c1_node *pcVar4;
  c1_symbol *pcVar5;
  byte bVar6;
  ushort uVar7;
  c1_conversion *conv;
  c1_u16 ret_code;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  c1_type *pcVar10;
  char cVar11;
  c1_symbol *sym;
  c1_node *pcVar12;
  int *template_args;
  c1_node *local_4;
  
  pcVar12 = (c1_node *)0x0;
  sym = (c1_symbol *)0x0;
  cVar11 = '\0';
  template_args = (int *)0x0;
  if (callee == (c1_node *)0x0) {
    return 0;
  }
  if (callee->op != 0x98) {
    if (((callee->type->code & 0x300) != 0) &&
       (pcVar5 = class_lookup_member_set
                           (g_current_scope,(callee->type->extra).cls,g_name_operator_call,2,0),
       pcVar5 != (c1_symbol *)0x0)) {
      sym = pcVar5;
      iVar2 = expr_count_call_arguments(args);
      if (iVar2 < 0) {
        return 0;
      }
      pcVar4 = expr_build_address_of(callee,6);
      pcVar12 = pcVar4;
      pcVar3 = ovl_resolve_call(*(c1_symbol **)(*(int *)pcVar5->type + 8),pcVar4,args,iVar2,
                                (int *)0x0,1);
      if (pcVar3 != (c1_ovl_candidate *)0x0) {
        pcVar5 = pcVar3->alias;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = pcVar3->function;
        }
        expr_set_overload_target_and_check_access(sym,(int)pcVar5);
        pcVar12 = expr_build_call_node(pcVar5,pcVar4,(int)args,(int)pcVar3->conversions,iVar2,0);
        return (int)pcVar12;
      }
    }
    goto LAB_1042c38e;
  }
  pcVar10 = callee->type;
  uVar7 = pcVar10->code;
  if ((uVar7 & 0xfff) == 0x802) {
    return 0;
  }
  if (args == (c1_node *)0x0) {
    if ((uVar7 & 0x200) == 0) {
      pcVar4 = tree_new_int_constant(0);
      goto LAB_1042c4ec;
    }
  }
  else {
    bVar6 = args->kind & 7;
    if (bVar6 == 2) {
      if (args->right != (void *)0x0) {
        if ((uVar7 & 0x200) == 0) {
          diag_error(0x234,pcVar10);
          return 0;
        }
        goto LAB_1042c4d3;
      }
      pcVar4 = args->left;
    }
    else if (bVar6 == 1) {
      pcVar4 = args->left;
    }
    else {
      pcVar4 = args;
      if (bVar6 != 0) goto LAB_1042c4d3;
    }
LAB_1042c4ec:
    if (pcVar4 != (c1_node *)0x0) {
      g_compile_flags_c8 = g_compile_flags_c8 | 1;
      pcVar4->link = (c1_node *)0x0;
      conv = (c1_conversion *)g_arenas[5].cur;
      g_arenas[5].cur = g_arenas[5].cur + 0x50;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (conv == (c1_conversion *)0x0) {
        conv = (c1_conversion *)0x0;
      }
      else {
        conv->op = 'd';
        *(c1_u8 *)((int)conv + 1) = '\x05';
        *(c1_u8 *)((int)conv + 2) = '\0';
        *(c1_node **)((int)conv + 4) = pcVar4;
        pcVar9 = pcVar4->type;
        *(c1_type **)((int)conv + 0xc) = pcVar10;
        *(c1_type **)((int)conv + 8) = pcVar9;
        conv_compute_conversion(conv);
      }
      if ((conv->flags4e & 1) != 0) {
        pcVar12 = conv_apply_conversion(conv,(c1_node *)0x0);
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
        return (int)pcVar12;
      }
      conv_report_cannot_convert(conv,'\x01');
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
      return 0;
    }
  }
LAB_1042c4d3:
  is_constructor._0_1_ = expr_build_constructor_reference(callee);
  if ((char)is_constructor == '\0') {
    iVar2 = expr_build_call_return_null();
    return iVar2;
  }
LAB_1042c38e:
  uVar1 = expr_count_call_arguments(args);
  while( true ) {
    if ((int)uVar1 < 0) {
      return 0;
    }
    if (callee->op == '\x06') break;
    if (callee->op == 'S') {
      iVar2 = expr_member_call_object_known(callee);
      cVar11 = (char)iVar2;
      pcVar12 = callee->left;
      if (*(char *)callee->right != '\x06') {
LAB_10470fcf:
        diag_error(0x40);
        return 0;
      }
      pcVar5 = *(c1_symbol **)((int)callee->right + 0x10);
      pcVar8 = *(c1_symbol **)(*(int *)pcVar5->type + 8);
      sym = pcVar5;
      goto LAB_1042c3ee;
    }
    local_4 = (c1_node *)0x0;
    if (callee->op == 0x93) {
      callee = pm_lower_member_function_call(callee,&local_4);
    }
    pcVar10 = callee->type;
    if ((pcVar10->code != 0x80c) && (pcVar10->code != 0x80e)) {
      ret_code = pcVar10->code;
      pcVar9 = pcVar10;
      if (((byte)ret_code & 0x83) != 0x81) {
        uVar7 = ret_code & 0x8f;
        if (((uVar7 != 0x86) && ((-1 < (char)(byte)ret_code || (uVar7 != 0x84)))) &&
           ((uVar7 != 0x8e || ((callee->op != 0x99 && (callee->op != 0x9a)))))) goto LAB_10470fcf;
        ret_code = pcVar10->base->code;
        pcVar9 = pcVar10->base;
      }
      cVar11 = ovl_check_c_call_argument_count(pcVar10,pcVar9,uVar1);
      if (cVar11 == '\0') {
        return 0;
      }
      pcVar10 = pcVar9->base;
      pcVar12 = ovl_convert_call_arguments((c1_symbol *)0x0,pcVar9,args,(c1_conversion *)0x0,uVar1);
      pcVar12 = tree_new_node('p',callee,pcVar12,pcVar10);
      if (local_4 != (c1_node *)0x0) {
        pcVar12 = tree_new_binary_typed_right('7',local_4,pcVar12);
      }
      pcVar12 = expr_build_call_with_temporaries(pcVar12,(c1_symbol *)0x0,ret_code);
      return (int)pcVar12;
    }
    callee = callee->left;
    uVar1 = expr_count_call_arguments(args);
  }
  pcVar5 = callee->left;
  template_args = callee->right;
  pcVar8 = pcVar5;
  if ((pcVar5->kind & 0x1f) == 0x12) {
    pcVar8 = *(c1_symbol **)(*(int *)pcVar5->type + 8);
    sym = pcVar5;
  }
  bVar6 = pcVar8->kind & 0x1f;
  if ((((((bVar6 != 0x10) && (bVar6 != 7)) && (bVar6 != 6)) && ((bVar6 != 0x11 && (bVar6 != 8)))) &&
      (bVar6 != 0x1b)) &&
     ((bVar6 != 0x1a ||
      (((((bVar6 = **(byte **)pcVar8->type & 0x1f, bVar6 != 0x10 && (bVar6 != 7)) &&
         ((bVar6 != 6 && (((bVar6 != 0x11 && (bVar6 != 8)) && (bVar6 != 0x1b)))))) &&
        ((bVar6 = **(byte **)pcVar8->type & 0x1f, bVar6 != 0x10 && (bVar6 != 7)))) &&
       ((bVar6 != 6 && (((bVar6 != 0x11 && (bVar6 != 8)) && (bVar6 != 0x1b)))))))))) {
    diag_error(0x40);
    return 0;
  }
  if (pcVar8->name == g_name_setjmp) {
    if ((g_current_function->flags22 & 1) == 0) {
      diag_warning(4,0x263,pcVar8);
    }
    else {
      diag_error(0x1ea,0x53);
    }
    g_current_function->flags5 = g_current_function->flags5 | 2;
  }
  else if (pcVar8->name == g_name_Catch) {
    iVar2 = func_check_naked_and_setjmp
                      (pcVar8,pcVar5,cVar11,sym,pcVar12,(int)template_args,uVar1,args);
    return iVar2;
  }
LAB_1042c3ee:
  if (((pcVar5->flags1 & 8) == 0) && (cVar11 == '\0')) {
    bVar6 = 0;
  }
  else {
    bVar6 = 1;
  }
  pcVar5->flags1 = pcVar5->flags1 & 0xf7;
  pcVar3 = ovl_resolve_call(pcVar8,pcVar12,args,uVar1,template_args,1);
  if (pcVar3 == (c1_ovl_candidate *)0x0) {
    return 0;
  }
  pcVar8 = pcVar3->alias;
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = pcVar3->function;
  }
  if ((sym != (c1_symbol *)0x0) && (pcVar8 != (c1_symbol *)0x0)) {
    expr_set_overload_target_and_check_access(sym,(int)pcVar8);
  }
  if ((((pcVar8->flags1 & 4) != 0) && (pcVar12 == (c1_node *)0x0)) &&
     ((pcVar8->flags1 & 0x10) == 0x10)) {
    pcVar10 = *(c1_type **)
               (**(int **)(((uint)pcVar8->type & -(uint)((pcVar8->type->code & 0x80) != 0)) + 8) + 4
               );
    pcVar9 = pcVar10;
    uVar1 = sym_new_local_key();
    pcVar12 = tree_new_leaf_9c(uVar1,pcVar9);
    pcVar12 = tree_new_cast((c1_type *)
                            **(undefined4 **)
                              (((uint)pcVar8->type & -(uint)((pcVar8->type->code & 0x80) != 0)) + 8)
                            ,pcVar12);
    pcVar4 = expr_build_call_of(pcVar8,(c1_symbol *)0x0,pcVar12,args,'\0',1,'\x01');
    eh_register_temporary_destructor(pcVar12,pcVar10);
    if (pcVar4 != (c1_node *)0x0) {
      pcVar4->kind = pcVar4->kind | 0x20;
    }
    return (int)pcVar4;
  }
  pcVar12 = expr_build_call_node
                      (pcVar8,pcVar12,(int)args,(int)pcVar3->conversions,uVar1,
                       -(uint)bVar6 & (uint)pcVar5);
  return (int)pcVar12;
}

