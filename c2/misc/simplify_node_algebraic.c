c2_tuple * __fastcall simplify_node_algebraic(c2_tuple *t,c2_tuple *parent)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  c2_operand *pcVar5;
  c2_operand *b;
  c2_symbol *sym;
  bool bVar6;
  bool bVar7;
  ushort uVar8;
  uint16_t uVar9;
  uint32_t uVar10;
  c2_operand *pcVar11;
  int iVar12;
  c2_float_const *out;
  c2_tuple *not_x;
  c2_operand *pcVar13;
  c2_operand *pcVar14;
  c2_tuple *pcVar15;
  c2_const_operand *pcVar16;
  c2_tuple_u20 *pcVar17;
  uint uVar18;
  c2_operand *term;
  uint hi;
  int64_t iVar19;
  uint64_t uVar20;
  c2_operand *local_10;
  c2_operand *rest;
  
  if ((1 << (t->kind & 0x1f) & 0xffeU) != 0) {
switchD_10707dd0_caseD_162:
    return (c2_tuple *)(c2_operand *)t;
  }
LAB_10707d80:
  pcVar13 = (((c2_operand *)t)->u18).children;
  while (pcVar14 = pcVar13, pcVar14 != (c2_operand *)0x0) {
    pcVar13 = pcVar14->next;
    if (((((c2_operand *)t)->u18).children == pcVar14) && (pcVar13 == (c2_operand *)0x0)) break;
    if (((1 << (pcVar14->kind & 0x1f) & 0x380U) == 0) ||
       ((pcVar14 == (((c2_operand *)t)->u18).children &&
        (iVar12 = tuple_is_commutative(t), iVar12 == 0)))) {
      if ((((c2_operand *)t)->op == pcVar14->op) &&
         ((((c2_operand *)t)->type == pcVar14->type &&
          (iVar12 = tuple_is_commutative(t), iVar12 != 0)))) {
        if (pcVar13 == (c2_operand *)0x0) {
          pcVar13 = (pcVar14->u18).children;
        }
        append_operand_list(t,(c2_tuple *)pcVar14);
        tuple_remove_src(t,pcVar14);
      }
    }
    else {
      pcVar11 = identity_constant_for_op(((c2_operand *)t)->op,((c2_operand *)t)->type);
      if ((((c2_operand *)t)->type & 0xf000) == 0x4000) {
        if ((pcVar11 == (c2_operand *)0x0) ||
           (iVar12 = float_const_compare_mask
                               (1,(c2_float_const *)pcVar14->sym,(c2_float_const *)pcVar11->sym),
           iVar12 == 0)) goto LAB_10707e3b;
        bVar7 = true;
      }
      else if (((pcVar11 == (c2_operand *)0x0) || ((pcVar14->u18).reg != (pcVar11->u18).reg)) ||
              (pcVar14->tag != pcVar11->tag)) {
LAB_10707e3b:
        bVar7 = false;
      }
      else {
        bVar7 = true;
      }
      if (pcVar11 != (c2_operand *)0x0) {
        node_free((c2_node *)pcVar11);
      }
      pcVar11 = absorbing_constant_for_op(((c2_operand *)t)->op,((c2_operand *)t)->type);
      if ((((c2_operand *)t)->type & 0xf000) == 0x4000) {
        if ((pcVar11 == (c2_operand *)0x0) ||
           (iVar12 = float_const_compare_mask
                               (1,(c2_float_const *)pcVar14->sym,(c2_float_const *)pcVar11->sym),
           iVar12 == 0)) goto LAB_10707e7a;
        bVar6 = true;
      }
      else if (((pcVar11 == (c2_operand *)0x0) || ((pcVar14->u18).reg != (pcVar11->u18).reg)) ||
              (pcVar14->tag != pcVar11->tag)) {
LAB_10707e7a:
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (pcVar11 != (c2_operand *)0x0) {
        node_free((c2_node *)pcVar11);
      }
      if (bVar7) {
        discard_expression_tree((c2_node *)pcVar14);
        tuple_remove_src(t,pcVar14);
        g_simplify_changed = 1;
      }
      else if (bVar6) {
        tuple_detach_src((c2_node *)t,pcVar14);
        discard_expression_tree((c2_node *)t);
        if ((((c2_operand *)t)->u18).children != (c2_operand *)0x0) {
          node_list_free((c2_node *)(((c2_operand *)t)->u18).children);
        }
        (((c2_operand *)t)->u18).children = pcVar14;
        goto LAB_10708633;
      }
    }
  }
  if ((((((c2_operand *)t)->u18).children)->next == (c2_operand *)0x0) &&
     (uVar10 = is_unary_il_opcode((c2_node *)t), uVar10 == 0)) {
    pcVar13 = tuple_forward_src_and_free(t,parent);
    return (c2_tuple *)pcVar13;
  }
  pcVar14 = (((c2_operand *)t)->u18).children;
  pcVar13 = pcVar14->next;
  switch(((c2_operand *)t)->op) {
  case 0x15f:
    uVar10 = pcVar14->op;
    while ((((uVar10 == 0x15f &&
             ((iVar12 = conversion_changes_value(pcVar14->type,((c2_operand *)t)->type), iVar12 == 0
              || (iVar12 = conversion_changes_value(pcVar14->type,((pcVar14->u18).children)->type),
                 iVar12 == 0)))) &&
            (((uVar8 = pcVar14->type, (1 << (byte)(uVar8 >> 0xc) & 0xeU) == 0 ||
              (uVar3 = ((pcVar14->u18).children)->type, (1 << (byte)(uVar3 >> 0xc) & 0xeU) == 0)) ||
             ((((uVar8 & 0xf000) != 0x2000 || ((uVar3 & 0xf000) != 0x1000)) &&
              ((((uVar3 ^ uVar8) & 0xfff) != 0 ||
               (((uVar8 & 0xf000) != 0x1000 || ((uVar3 & 0xf000) != 0x2000)))))))))) &&
           (((((c2_operand *)t)->type & 0xf000) != 0x4000 ||
            ((uVar8 != 0x1008 || (((pcVar14->u18).children)->type != 0x2008))))))) {
      pcVar14 = tuple_forward_src_and_free((c2_tuple *)pcVar14,t);
      g_simplify_changed = 1;
      uVar10 = pcVar14->op;
    }
    if (((c2_operand *)t)->type != pcVar14->type) {
      return (c2_tuple *)(c2_operand *)t;
    }
    pcVar13 = tuple_forward_src_and_free(t,parent);
    g_simplify_changed = 1;
    return (c2_tuple *)pcVar13;
  case 0x160:
    if (pcVar14->op == 0x160) {
      pcVar13 = tuple_forward_src_and_free(t,parent);
      pcVar13 = tuple_forward_src_and_free((c2_tuple *)pcVar13,parent);
      g_simplify_changed = 1;
      return (c2_tuple *)pcVar13;
    }
    if (pcVar14->op != 0x161) {
      return (c2_tuple *)(c2_operand *)t;
    }
    tuple_forward_src_and_free((c2_tuple *)pcVar14,t);
    ((c2_operand *)t)->op = 0x16d;
    pcVar16 = operand_new_intconst(((c2_operand *)t)->type,0xffffffff,-1);
    tuple_append_src(t,pcVar16);
    break;
  case 0x161:
    uVar10 = try_negate_in_place((c2_node *)pcVar14,t,3);
    if (uVar10 == 0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    goto LAB_10708633;
  default:
    goto switchD_10707dd0_caseD_162;
  case 0x16d:
    term = (((c2_operand *)t)->u18).children;
    if ((((c2_operand *)t)->u18).children == (c2_operand *)0x0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    goto LAB_10708300;
  case 0x16e:
    iVar12 = compare_trees((c2_node *)pcVar14,(c2_node *)pcVar13);
    if ((iVar12 == 0) &&
       (iVar12 = tree_has_side_effect_or_mem_read((c2_node *)pcVar14), iVar12 == 0)) {
      discard_expression_tree((c2_node *)t);
      if (parent == (c2_tuple *)0x0) {
        uVar9 = ((c2_operand *)t)->type;
        bVar1 = (byte)(uVar9 >> 8);
joined_r0x10792631:
        if ((1 << (bVar1 >> 4) & 0xeU) == 0) {
          pcVar13 = operand_new_fconst(uVar9,&g_ld_const_zero);
          g_simplify_changed = 1;
          return (c2_tuple *)pcVar13;
        }
        pcVar16 = operand_new_intconst(uVar9,0,0);
        g_simplify_changed = 1;
        return (c2_tuple *)pcVar16;
      }
      uVar9 = ((c2_operand *)t)->type;
      if ((1 << (byte)(uVar9 >> 0xc) & 0xeU) != 0) {
        pcVar16 = operand_new_intconst(uVar9,0,0);
        pcVar13 = tuple_replace_src(parent,(c2_operand *)t,pcVar16);
        g_simplify_changed = 1;
        return (c2_tuple *)pcVar13;
      }
      goto LAB_10792454;
    }
    if (((pcVar14->kind != '\a') || ((pcVar14->u18).reg != (c2_symbol *)0x0 || pcVar14->tag != 0))
       && ((pcVar14->kind != '\t' ||
           (iVar12 = float_const_compare_mask(1,(c2_float_const *)pcVar14->sym,&g_ld_const_zero),
           iVar12 == 0)))) {
      if (pcVar14->kind != '\x03') {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (pcVar13->kind != '\x03') {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (pcVar14->sym->storage != pcVar13->sym->storage) {
        return (c2_tuple *)(c2_operand *)t;
      }
      uVar10 = pcVar14->sym->offset - pcVar13->sym->offset;
      pcVar16 = operand_new_intconst(((c2_operand *)t)->type,uVar10,(int)uVar10 >> 0x1f);
      if (parent == (c2_tuple *)0x0) {
        g_simplify_changed = 1;
        return (c2_tuple *)pcVar16;
      }
      pcVar13 = tuple_replace_src(parent,(c2_operand *)t,pcVar16);
      g_simplify_changed = 1;
      return (c2_tuple *)pcVar13;
    }
    negate_operand((c2_node *)pcVar13,t);
    pcVar13 = pcVar14;
    goto LAB_107924d0;
  case 0x16f:
    goto switchD_10707dd0_caseD_16f;
  case 0x171:
    if (((pcVar14->op == 0x16f) &&
        (pcVar11 = operand_list_find_constant((pcVar14->u18).children), pcVar11 != (c2_operand *)0x0
        )) && (iVar12 = shift_by_constant_to_mul(t), iVar12 != 0)) {
LAB_10792360:
      append_operand_list(t,(c2_tuple *)pcVar14);
      tuple_remove_src(t,pcVar14);
      pcVar15 = (c2_tuple *)fold_constant_operands(t,parent);
      return pcVar15;
    }
  case 0x177:
    if (pcVar14->op == ((c2_operand *)t)->op) {
      if (pcVar13->kind != '\a') {
        return (c2_tuple *)(c2_operand *)t;
      }
      pcVar11 = ((pcVar14->u18).children)->next;
      if (pcVar11->kind == '\a') {
        uVar8 = pcVar14->type;
        pcVar5 = (pcVar14->u18).children;
        (((c2_operand *)t)->u18).children = pcVar5;
        pcVar5->next = pcVar14;
        pcVar14->next = (c2_operand *)0x0;
        pcVar14->op = 0x16d;
        if (4 < (uVar8 & 0xfff)) {
          pcVar14->type = 0x1004;
          operand_set_type((c2_operand *)pcVar14->tag,0x1004);
        }
        (pcVar14->u18).children = pcVar11;
        pcVar11->next = pcVar13;
        pcVar13->next = (c2_operand *)0x0;
        g_simplify_changed = 1;
        return (c2_tuple *)(c2_operand *)t;
      }
    }
    if (pcVar13->kind != '\a') {
      return (c2_tuple *)(c2_operand *)t;
    }
    iVar12 = fold_shift_into_mask((c2_tuple *)pcVar14,(c2_tuple *)0x0,t);
    if (iVar12 != 0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    uVar20 = shift_mask_constant(t);
    shrink_constants_to_demanded_bits(pcVar14,(uint32_t)uVar20,(uint32_t)(uVar20 >> 0x20));
    return (c2_tuple *)(c2_operand *)t;
  case 0x172:
  case 0x173:
    pcVar13 = (((c2_operand *)t)->u18).children;
    if (pcVar13 == (c2_operand *)0x0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    do {
      if ((1 << (pcVar13->kind & 0x1f) & 0xffeU) == 0) {
        for (pcVar14 = (((c2_operand *)t)->u18).children; pcVar14 != (c2_operand *)0x0;
            pcVar14 = pcVar14->next) {
          if (pcVar14->kind == '\a') {
            if (((c2_operand *)t)->op == 0x172) {
              uVar20._0_4_ = pcVar14->u18;
              uVar20._4_4_ = pcVar14->tag;
            }
            else {
              uVar20 = const_normalize(((c2_operand *)t)->type,~(pcVar14->u18).lo,~pcVar14->tag);
            }
            shrink_constants_to_demanded_bits(pcVar13,(uint32_t)uVar20,(uint32_t)(uVar20 >> 0x20));
          }
        }
      }
      pcVar13 = pcVar13->next;
    } while (pcVar13 != (c2_operand *)0x0);
    return (c2_tuple *)(c2_operand *)t;
  case 0x174:
    while( true ) {
      if (pcVar14 == (c2_operand *)0x0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (((pcVar14->kind == '\a') && (iVar12 = const_compare(pcVar14,0xffffffff,-1), iVar12 == 0))
         && ((((c2_operand *)t)->u18).children != pcVar14)) break;
      pcVar14 = pcVar14->next;
    }
    tuple_remove_src(t,pcVar14);
    pcVar13 = (((c2_operand *)t)->u18).children;
    tuple_detach_src((c2_node *)t,pcVar13);
    not_x = tuple_new_unary_temp
                      (0x160,((c2_operand *)t)->type,pcVar13,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_unlink_mem_subops(not_x);
    rest = (((c2_operand *)t)->u18).children;
    not_x->flags12 = '\x02';
    not_x->next = (c2_tuple *)rest;
    (((c2_operand *)t)->u18).children = (c2_operand *)not_x;
    break;
  case 0x175:
    if (((((g_opt_float_consistency == 0) && ((((c2_operand *)t)->type & 0xf000) == 0x4000)) &&
         (pcVar13 != (c2_operand *)0x0)) &&
        ((pcVar13->next == (c2_operand *)0x0 && (pcVar13->kind == '\t')))) &&
       (iVar12 = float_const_compare_mask(1,(c2_float_const *)pcVar13->sym,&g_ld_const_zero),
       iVar12 == 0)) {
      ((c2_operand *)t)->op = 0x16f;
      out = arena_alloc(0,0xc);
      float_fold_divide_constants
                (&g_ld_const_one,(c2_float_const *)((((c2_operand *)t)->u18).children)->next->sym,
                 out);
      pcVar13 = operand_new_fconst(((((c2_operand *)t)->u18).children)->next->type,out);
      tuple_replace_src(t,((((c2_operand *)t)->u18).children)->next,pcVar13);
      g_simplify_changed = 1;
      return (c2_tuple *)(c2_operand *)t;
    }
    goto switchD_10707dd0_caseD_16f;
  case 0x176:
    if (pcVar13->kind != '\a') {
LAB_1070850c:
      if (((((c2_operand *)t)->type & 0xf000) == 0x1000) &&
         (uVar10 = try_negate_in_place((c2_node *)pcVar13,t,0), uVar10 != 0)) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if ((((c2_operand *)t)->type & 0xf000) != 0x2000) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (pcVar13->kind != '\a') {
        return (c2_tuple *)(c2_operand *)t;
      }
      uVar18 = pcVar13->tag;
      uVar4 = (pcVar13->u18).lo;
      if ((int)uVar18 < 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (((int)uVar18 < 1) && (uVar4 == 0)) {
        return (c2_tuple *)(c2_operand *)t;
      }
      hi = uVar18 - (uVar4 == 0);
      if ((uVar4 - 1 & uVar4) != 0 || (hi & uVar18) != 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      ((c2_operand *)t)->op = 0x172;
      uVar20 = const_normalize(((c2_operand *)t)->type,uVar4 - 1,hi);
      pcVar13->u18 = (c2_operand_u18)(int)uVar20;
      pcVar13->tag = (int)(uVar20 >> 0x20);
      g_simplify_changed = 1;
      return (c2_tuple *)(c2_operand *)t;
    }
    if ((pcVar13->u18).reg == (c2_symbol *)0x0 && pcVar13->tag == 0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    if (((pcVar13->u18).reg != (c2_symbol *)0x1) || (pcVar13->tag != 0)) goto LAB_1070850c;
    discard_expression_tree((c2_node *)t);
    if (parent == (c2_tuple *)0x0) {
      uVar9 = ((c2_operand *)t)->type;
      bVar1 = (byte)(uVar9 >> 8);
      goto joined_r0x10792631;
    }
    uVar9 = ((c2_operand *)t)->type;
    if ((1 << (byte)(uVar9 >> 0xc) & 0xeU) != 0) {
      pcVar13 = operand_new_intconst(uVar9,0,0);
      goto LAB_10792460;
    }
LAB_10792454:
    pcVar13 = operand_new_fconst(uVar9,&g_ld_const_zero);
LAB_10792460:
    pcVar13 = tuple_replace_src(parent,(c2_operand *)t,pcVar13);
    g_simplify_changed = 1;
    return (c2_tuple *)pcVar13;
  case 0x178:
    if (((pcVar14->kind != '\a') || ((pcVar14->flags11 & 0x40) != 0)) && (pcVar14->kind != '\t')) {
      return (c2_tuple *)(c2_operand *)t;
    }
LAB_107924d0:
    tuple_remove_src(t,pcVar13);
LAB_10708633:
    pcVar13 = tuple_forward_src_and_free(t,parent);
    g_simplify_changed = 1;
    return (c2_tuple *)pcVar13;
  case 0x17d:
    pcVar11 = pcVar14;
    if (pcVar14->op != 399) {
      pcVar11 = pcVar13;
      pcVar13 = pcVar14;
    }
    if (pcVar11->op != 399) {
      return (c2_tuple *)(c2_operand *)t;
    }
    pcVar14 = (pcVar11->u18).children;
    if (pcVar14->op != 0x17d) {
      return (c2_tuple *)(c2_operand *)t;
    }
    if (parent == (c2_tuple *)0x0) {
      pcVar17 = (c2_tuple_u20 *)&g_simplify_context_tuple->type;
    }
    else {
      pcVar17 = &parent->u20;
    }
    pcVar5 = pcVar14->next;
    bVar1 = pcVar17->cc;
    b = pcVar5->next;
    if ((bVar1 != 1) && (bVar1 != 2)) {
      return (c2_tuple *)(c2_operand *)t;
    }
    iVar12 = compare_trees((c2_node *)pcVar5,(c2_node *)b);
    if (iVar12 == 0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    iVar12 = compare_trees((c2_node *)pcVar13,(c2_node *)b);
    if (((iVar12 == 0) &&
        (iVar12 = tree_has_side_effect_or_mem_read((c2_node *)pcVar13), iVar12 == 0)) &&
       (pcVar5->kind == '\a')) {
      bVar2 = *(byte *)&pcVar11->base_sym;
      if (bVar1 == 1) {
        bVar2 = g_cond_inverse[bVar2];
      }
    }
    else {
      iVar12 = compare_trees((c2_node *)pcVar13,(c2_node *)pcVar5);
      if (iVar12 != 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      iVar12 = tree_has_side_effect_or_mem_read((c2_node *)pcVar13);
      if (iVar12 != 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if (b->kind != '\a') {
        return (c2_tuple *)(c2_operand *)t;
      }
      bVar2 = *(byte *)&pcVar11->base_sym;
      if (bVar1 == 2) {
        bVar2 = g_cond_inverse[bVar2];
      }
    }
    if (parent != (c2_tuple *)0x0) {
      sym = *(c2_symbol **)(pcVar14->tag + 0x14);
      if (sym->storage->part_next == (c2_symbol *)0x0) {
        sym->def = (c2_tuple *)pcVar14;
      }
      else {
        symbol_mark_overlapping_parts(sym,(c2_tuple *)pcVar14);
      }
      pcVar13 = parent->src->next;
      if ((1 << (pcVar13->kind & 0x1f) & 0xffeU) == 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      if ((1 << (pcVar13->next->kind & 0x1f) & 0xffeU) == 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
      iVar12 = select_is_profitable
                         (parent->type,(int)pcVar14,pcVar13,pcVar13->next,g_cond_inverse[bVar2],0);
      if (iVar12 == 0) {
        return (c2_tuple *)(c2_operand *)t;
      }
    }
    pcVar17->cc = bVar2;
    tuple_detach_src((c2_node *)pcVar11,pcVar14);
    if (parent == (c2_tuple *)0x0) {
      node_list_remove_rank(g_simplify_context_tuple,(int)t);
      tuple_push_cell20((c2_node *)g_simplify_context_tuple,(uint32_t)pcVar14);
      node_free((c2_node *)t);
      return (c2_tuple *)pcVar14;
    }
    tuple_replace_src(parent,(c2_operand *)t,pcVar14);
    return (c2_tuple *)pcVar14;
  case 399:
    pcVar13 = simplify_select_same_arms(t,parent);
    if ((pcVar13 == (c2_operand *)0x0) &&
       (pcVar13 = (c2_operand *)simplify_select_of_powers_of_two(t,parent),
       pcVar13 == (c2_operand *)0x0)) {
      return (c2_tuple *)(c2_operand *)t;
    }
    g_simplify_changed = 1;
    return (c2_tuple *)pcVar13;
  }
  g_simplify_changed = 1;
  goto LAB_1070820f;
switchD_10707dd0_caseD_16f:
  pcVar14 = (((c2_operand *)t)->u18).children;
  do {
    if (pcVar14 == (c2_operand *)0x0) {
      return (c2_tuple *)(c2_operand *)t;
    }
    if (((c2_operand *)t)->op == 0x16f) {
      if ((((pcVar14->op == 0x171) || (pcVar14->op == 0x177)) &&
          (pcVar13 = operand_list_find_constant((((c2_operand *)t)->u18).children),
          pcVar13 != (c2_operand *)0x0)) &&
         ((pcVar14->op == 0x171 &&
          (iVar12 = shift_by_constant_to_mul((c2_tuple *)pcVar14), iVar12 != 0))))
      goto LAB_10792360;
LAB_107080c1:
      if (pcVar14->op == 0x161) break;
      if (pcVar14->kind == '\a') {
        iVar12 = const_compare(pcVar14,0xffffffff,-1);
        if (iVar12 == 0) {
          tuple_remove_src(t,pcVar14);
          goto LAB_107081f7;
        }
        if ((pcVar14->type & 0xf000) == 0x2000) {
          uVar20 = const_normalize(pcVar14->type,-(pcVar14->u18).lo,
                                   -(pcVar14->tag + (uint)((pcVar14->u18).lo != 0)));
          uVar18 = (uint)(uVar20 >> 0x20);
          if ((uVar18 < pcVar14->tag) ||
             ((uVar18 <= pcVar14->tag && ((c2_symbol *)uVar20 < (pcVar14->u18).reg)))) {
            tuple_detach_src((c2_node *)t,pcVar14);
            uVar10 = try_negate_in_place((c2_node *)t,parent,2);
            if (uVar10 == 0) {
              tuple_append_src(t,pcVar14);
              return (c2_tuple *)(c2_operand *)t;
            }
            tuple_append_src(t,pcVar14);
            goto LAB_10792572;
          }
        }
        uVar10 = try_negate_in_place((c2_node *)t,parent,0);
        if (uVar10 != 0) {
LAB_10792572:
          pcVar15 = negate_operand((c2_node *)pcVar14,t);
          fold_constant_operands(pcVar15,t);
          return (c2_tuple *)(c2_operand *)t;
        }
      }
    }
    else {
      pcVar13 = (((c2_operand *)t)->u18).children;
      if ((pcVar13->next == pcVar14) && (pcVar14->kind == '\a')) {
        uVar18 = pcVar14->tag;
        uVar4 = (pcVar14->u18).lo;
        if ((((-1 < (int)uVar18) && ((0 < (int)uVar18 || (uVar4 != 0)))) &&
            ((uVar4 - 1 & uVar4) == 0 && (uVar18 - (uVar4 == 0) & uVar18) == 0)) &&
           (((((c2_operand *)t)->type & 0xf000) == 0x2000 ||
            (iVar12 = is_known_nonnegative(pcVar13), iVar12 != 0)))) {
          uVar8 = ((c2_operand *)t)->type;
          if (4 < (uVar8 & 0xfff)) {
            uVar8 = (-(ushort)((uVar8 & 0xf000) != 0x1000) & 0x1000) + 0x1004;
          }
          iVar19 = shift_loop_noop((pcVar14->u18).lo,pcVar14->tag);
          uVar20 = const_normalize(uVar8,(uint32_t)iVar19,(int32_t)((ulonglong)iVar19 >> 0x20));
          (pcVar14->u18).lo = (uint32_t)uVar20;
          (((c2_operand *)t)->u18).children = pcVar13;
          pcVar13->next = pcVar14;
          pcVar14->tag = (uint32_t)(uVar20 >> 0x20);
          pcVar14->type = uVar8;
          ((c2_operand *)t)->op = 0x177;
          pcVar14->next = (c2_operand *)0x0;
          g_simplify_changed = 1;
          goto LAB_1070820f;
        }
      }
      if ((((c2_operand *)t)->type & 0xf000) != 0x2000) goto LAB_107080c1;
    }
    pcVar14 = pcVar14->next;
  } while( true );
  tuple_forward_src_and_free((c2_tuple *)pcVar14,t);
  g_simplify_changed = 1;
LAB_107081f7:
  pcVar15 = simplify_node_algebraic(t,parent);
  t = negate_operand((c2_node *)pcVar15,parent);
LAB_1070820f:
  if ((1 << (((c2_operand *)t)->kind & 0x1f) & 0xffeU) != 0) {
    return (c2_tuple *)(c2_operand *)t;
  }
  goto LAB_10707d80;
LAB_10708300:
  local_10 = term->next;
  if (term->op == 0x161) {
    pcVar13 = (((c2_operand *)t)->u18).children;
    while (pcVar14 = pcVar13, pcVar14 != (c2_operand *)0x0) {
      pcVar13 = pcVar14->next;
      iVar12 = compare_trees((c2_node *)pcVar14,(c2_node *)(term->u18).reg);
      if ((iVar12 == 0) &&
         (iVar12 = tree_has_side_effect_or_mem_read((c2_node *)pcVar14), iVar12 == 0)) {
        if (local_10 == pcVar14) {
          local_10 = pcVar13;
        }
        discard_expression_tree((c2_node *)pcVar14);
        tuple_remove_src(t,pcVar14);
        discard_expression_tree((c2_node *)term);
        uVar9 = term->type;
        if ((1 << (byte)(uVar9 >> 0xc) & 0xeU) == 0) {
          pcVar11 = operand_new_fconst(uVar9,&g_ld_const_zero);
        }
        else {
          pcVar11 = operand_new_intconst(uVar9,0,0);
        }
        goto LAB_1070839e;
      }
      if (((pcVar14->kind == '\x03') && (((term->u18).children)->kind == '\x03')) &&
         (pcVar14->sym->storage == ((term->u18).children)->sym->storage)) goto code_r0x107083d4;
    }
  }
  goto LAB_10708311;
code_r0x107083d4:
  uVar10 = pcVar14->sym->offset - ((term->u18).children)->sym->offset;
  pcVar11 = operand_new_intconst(((c2_operand *)t)->type,uVar10,(int)uVar10 >> 0x1f);
  if (local_10 == pcVar14) {
    local_10 = pcVar13;
  }
  tuple_remove_src(t,pcVar14);
LAB_1070839e:
  tuple_replace_src(t,term,pcVar11);
  g_simplify_changed = 1;
LAB_10708311:
  term = local_10;
  if (local_10 == (c2_operand *)0x0) {
    return (c2_tuple *)(c2_operand *)t;
  }
  goto LAB_10708300;
}

