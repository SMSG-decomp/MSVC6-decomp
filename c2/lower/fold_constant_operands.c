c2_node * __fastcall fold_constant_operands(c2_tuple *t,c2_tuple *user)

{
  c2_symbol *offset;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  int iVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_symbol *pcVar6;
  c2_operand *pcVar7;
  c2_operand *pcVar8;
  c2_operand *pcStack_8;
  
  iVar3 = tuple_is_commutative(t);
  if (iVar3 == 0) {
    uVar4 = is_unary_il_opcode((c2_node *)t);
    if (uVar4 == 0) {
      uVar4 = is_reorderable_binary_opcode((c2_node *)t);
      if (uVar4 == 0) {
        return (c2_node *)t;
      }
      pcVar8 = t->src;
      if ((pcVar8->kind == '\a') && (pcVar8->next->kind == '\a')) {
        pcVar8 = fold_integer_constants(t,t->type,pcVar8,pcVar8->next);
        if (pcVar8 == (c2_operand *)0x0) {
          return (c2_node *)t;
        }
        pcVar8 = t->src->next;
      }
      else {
        if (pcVar8->kind != '\t') {
          return (c2_node *)t;
        }
        if (pcVar8->next->kind != '\t') {
          return (c2_node *)t;
        }
        pcVar8 = fold_float_constants(t,t->type,pcVar8,pcVar8->next);
        if (pcVar8 == (c2_operand *)0x0) {
          return (c2_node *)t;
        }
        pcVar8 = t->src->next;
      }
      tuple_remove_src(t,pcVar8);
    }
    else {
      pcVar8 = t->src;
      if (pcVar8->kind == '\a') {
        pcVar8 = fold_integer_constants(t,t->type,pcVar8,(c2_operand *)0x0);
      }
      else {
        if (pcVar8->kind != '\t') {
          return (c2_node *)t;
        }
        pcVar8 = fold_float_constants(t,t->type,pcVar8,(c2_operand *)0x0);
      }
      if (pcVar8 == (c2_operand *)0x0) {
        return (c2_node *)t;
      }
    }
    t = (c2_tuple *)tuple_forward_src_and_free(t,user);
    g_simplify_changed = 1;
  }
  else {
    if ((1 << (byte)(t->type >> 0xc) & 0xeU) == 0) {
      if ((t->type & 0xf000) == 0x4000) {
        pcVar8 = t->src;
        pcVar7 = (c2_operand *)0x0;
        while (pcVar2 = pcVar7, pcVar1 = pcVar8, pcVar1 != (c2_operand *)0x0) {
          pcVar8 = pcVar1->next;
          pcVar7 = pcVar2;
          if (((pcVar1->kind == '\t') && (pcVar7 = pcVar1, pcVar2 != (c2_operand *)0x0)) &&
             (pcVar7 = fold_float_constants(t,t->type,pcVar2,pcVar1), pcVar7 != (c2_operand *)0x0))
          {
            tuple_remove_src(t,pcVar1);
            g_simplify_changed = 1;
          }
        }
      }
    }
    else {
      pcStack_8 = (c2_operand *)0x0;
      pcVar8 = t->src;
      pcVar7 = (c2_operand *)0x0;
      while (pcVar2 = pcVar7, pcVar1 = pcVar8, pcVar1 != (c2_operand *)0x0) {
        pcVar8 = pcVar1->next;
        pcVar7 = pcVar2;
        if (pcVar1->kind == '\a') {
          pcVar7 = pcVar1;
          if ((pcVar2 != (c2_operand *)0x0) &&
             (pcVar5 = fold_integer_constants(t,t->type,pcVar2,pcVar1), pcVar7 = pcVar2,
             pcVar5 != (c2_operand *)0x0)) {
            tuple_remove_src(t,pcVar1);
            g_simplify_changed = 1;
          }
        }
        else if ((pcVar1->kind == '\x03') && (t->op == 0x16d)) {
          pcStack_8 = pcVar1;
        }
      }
      if (((g_opt_dlp == 0) && (pcStack_8 != (c2_operand *)0x0)) && (pcVar2 != (c2_operand *)0x0)) {
        pcVar6 = pcStack_8->sym;
        offset = (pcVar2->u18).reg;
        if ((-1 < (int)&offset->fe + pcVar6->offset) &&
           (((pcVar6->type & 0xf000) == 0x5000 || ((int)offset < (int)(pcVar6->type & 0xfff))))) {
          pcVar6 = symbol_get_part(pcVar6,0x5000,0,(int32_t)offset);
          pcStack_8->sym = pcVar6;
          tuple_remove_src(t,pcVar2);
        }
      }
    }
    if (t->src->next == (c2_operand *)0x0) {
      pcVar8 = tuple_forward_src_and_free(t,user);
      return (c2_node *)pcVar8;
    }
  }
  return (c2_node *)(c2_operand *)t;
}

