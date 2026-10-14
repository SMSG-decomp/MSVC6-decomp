c2_operand * __fastcall
fold_float_constants(c2_tuple *user,uint16_t type,c2_operand *k,c2_operand *opnd)

{
  uint32_t uVar1;
  c2_float_const *out;
  uint32_t uVar2;
  int32_t iVar3;
  c2_operand *pcVar4;
  int iVar5;
  c2_float_fold_entry *pcVar6;
  
  if (((type & 0xf000) != 0x4000) && (user->op != 0x15f)) {
    return (c2_operand *)0x0;
  }
  if (k->kind != '\t') {
    return (c2_operand *)0x0;
  }
  if ((opnd != (c2_operand *)0x0) && (opnd->kind != '\t')) {
    return (c2_operand *)0x0;
  }
  uVar1 = user->op;
  switch(*(undefined1 *)(uVar1 + 0x1070d052)) {
  case 1:
    pcVar4 = constant_convert_to(k,type,user);
    return pcVar4;
  case 2:
    out = arena_alloc(0,0xc);
    float_fold_subtract_constants(&g_ld_const_zero,(c2_float_const *)k->sym,out);
LAB_1070d138:
    pcVar4 = operand_new_fconst(type,out);
    tuple_replace_src(user,k,pcVar4);
    pcVar4 = constant_convert_to(pcVar4,type,user);
    return pcVar4;
  case 3:
    pcVar4 = constant_convert_to(k,type,user);
    return pcVar4;
  case 5:
    iVar5 = float_const_compare_mask(1,(c2_float_const *)k->sym,&g_ld_const_zero);
    if (iVar5 != 0) {
      return (c2_operand *)0x0;
    }
  case 4:
    out = arena_alloc(0,0xc);
    uVar2 = 0x16d;
    pcVar6 = g_float_fold_handler_table;
    do {
      if (uVar2 == uVar1) break;
      uVar2 = pcVar6[1].op;
      pcVar6 = pcVar6 + 1;
    } while (uVar2 != 0);
    iVar3 = (*pcVar6->fold)((c2_float_const *)k->sym,(c2_float_const *)opnd->sym,out);
    if (iVar3 == 0) goto LAB_1070d138;
    if (g_opt_vb_float_checks != 0) {
      return (c2_operand *)0x0;
    }
    if ((g_expr_pass_mode == 2) && (g_const_overflow_warned == 0)) {
      warning(2,0x2f4);
      g_const_overflow_warned = 1;
    }
  }
  return (c2_operand *)0x0;
}

