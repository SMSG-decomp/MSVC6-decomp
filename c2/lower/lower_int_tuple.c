c2_node * __fastcall lower_int_tuple(c2_tuple *t)

{
  uint8_t uVar1;
  uint16_t uVar2;
  uint uVar3;
  c2_operand *pcVar4;
  uint uVar5;
  c2_operand *pcVar6;
  c2_symbol *sym;
  c2_const_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_node *pcVar9;
  c2_symbol *pcVar10;
  c2_tuple *pcVar11;
  c2_operand *pcVar12;
  ushort uVar13;
  int iVar14;
  uint32_t uVar15;
  uint64_t uVar16;
  code *pcVar17;
  c2_operand *local_c;
  c2_operand *divisor_temp;
  uint32_t local_4;
  c2_insert_fn *insert_fn;
  
  if ((((1 << (t->kind & 0x1f) & 0x2000U) == 0) && (t->kind != 0x11)) &&
     ((4 < (t->type & 0xfff) || ((t->src != (c2_operand *)0x0 && (4 < (t->src->type & 0xfff))))))) {
    local_4 = 0x1071b5c6;
    t = lower_int64_tuple(t);
  }
  switch(t->op) {
  case 0x15a:
    pcVar6 = t->dst;
    if ((pcVar6->kind != '\x01') || (((pcVar6->u18).reg)->cls != '\x01')) {
      pcVar4 = operand_new_hardreg(5,0x1004);
      tuple_replace_dst(t,pcVar6,pcVar4);
      pcVar6 = operand_new_hardreg(5,0x1004);
      tuple_append_src(t,pcVar6);
      return (c2_node *)t;
    }
    break;
  case 0x15b:
  case 0x15d:
  case 0x15e:
  case 0x1ad:
    t->op = 1;
    return (c2_node *)t;
  case 0x15f:
    pcVar6 = t->src;
    if ((1 << (pcVar6->kind & 0x1f) & 0x380U) != 0) {
      t->op = 1;
      constant_convert_to(pcVar6,t->type,t);
      return (c2_node *)t;
    }
    uVar13 = pcVar6->type;
    if ((uVar13 & 0xf000) != 0x2000) {
      t->op = ((uVar13 & 0xfff) != 1) + 0xc4;
      return (c2_node *)t;
    }
    uVar2 = t->type;
    if (((uVar2 & 0xfff) == 2) || (g_opt_favor_speed == 0)) {
      t->op = ((uVar13 & 0xfff) != 1) + 0xc2;
      return (c2_node *)t;
    }
    iVar14 = operand_readable_as_dword(pcVar6);
    if (iVar14 == 0) {
      tuple_legalize_mem_operands(t);
      pcVar17 = tuple_insert_before;
      pcVar8 = t;
      pcVar7 = operand_new_intconst(0x1004,0,0);
      pcVar8 = tuple_new_unary_temp(0x11a,0x1004,pcVar7,pcVar17,pcVar8);
      pcVar6 = pcVar8->dst;
      pcVar8 = tuple_new_binary_temp(1,t->src->type,t->src,pcVar6,tuple_insert_before,t);
      pcVar10 = (pcVar6->u18).reg;
      uVar2 = t->type;
      pcVar6 = pcVar8->dst;
      (pcVar6->u18).reg = pcVar10;
      sym = symbol_get_part(pcVar6->sym,uVar2,4,0);
      pcVar6 = operand_new_reg(0x149,uVar2,sym,pcVar10);
      tuple_replace_src(t,t->src,pcVar6);
      t->op = 1;
      return (c2_node *)pcVar8;
    }
    if ((pcVar6->type & 0xfff) == 2) {
      uVar15 = 0xffff;
    }
    else {
      uVar15 = 0xff;
    }
    pcVar7 = operand_new_intconst(uVar2,uVar15,0);
    tuple_append_src(t,pcVar7);
    uVar13 = t->type;
    pcVar6 = t->src;
    pcVar10 = symbol_get_part(pcVar6->sym,uVar13,uVar13 & 0xfff,0);
    pcVar6->sym = pcVar10;
    pcVar6->type = uVar13;
  case 0x172:
    t->op = 0x2e;
    return (c2_node *)t;
  case 0x160:
    t->op = 0x24;
    return (c2_node *)t;
  case 0x161:
    t->op = 0x23;
    return (c2_node *)t;
  case 0x16a:
  case 0x16b:
    uVar13 = t->type & 0xfff;
    if (((uVar13 != 0) && (uVar13 < 9)) &&
       ((uVar13 = t->type & 0xfff, (uVar13 & uVar13 - 1) == 0 && (t->dst->next == (c2_operand *)0x0)
        ))) {
      lower_small_block_copy_as_scalar(t);
      return (c2_node *)t;
    }
    pcVar8 = lower_block_copy(t);
    return (c2_node *)pcVar8;
  case 0x16c:
    uVar13 = t->type;
    pcVar10 = reg_find_subreg(g_reg_symbols + 1,(uVar13 & 0xfff) << 3,0);
    pcVar6 = t->src;
    pcVar17 = tuple_insert_after;
    pcVar8 = t;
    pcVar4 = operand_new_temp_in_reg(pcVar10->id,uVar13);
    pcVar8 = tuple_new(1,uVar13,pcVar4,pcVar6,pcVar17,pcVar8);
    pcVar11 = pcVar8->next->next;
    pcVar8->dst->sym->def = pcVar8;
    if ((pcVar11 == (c2_tuple *)0x0) || (pcVar11->op != 0x19e)) {
      pcVar11 = tuple_new_pseudo(0x19e,t->type);
      tuple_insert_after(pcVar8,pcVar11);
    }
    pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar8->dst);
    tuple_append_src(pcVar11,pcVar6);
    if (t->dst != (c2_operand *)0x0) {
      tuple_append_dst(pcVar8,t->dst);
      if (((t->dst->kind == '\x01') && (pcVar10 = t->dst->sym, pcVar10->cls == '\x03')) &&
         (pcVar10->def != (c2_tuple *)0x0)) {
        pcVar10->def = pcVar8;
        tuple_unlink_free(t);
        return (c2_node *)pcVar8;
      }
    }
    goto LAB_1071bd93;
  case 0x16d:
    t->op = 0x2d;
    return (c2_node *)t;
  case 0x16e:
    t->op = 0x32;
    return (c2_node *)t;
  case 0x16f:
    pcVar6 = t->src->next;
    if (pcVar6->kind == '\a') {
      uVar5 = pcVar6->tag;
      uVar3 = (pcVar6->u18).lo;
      if (((-1 < (int)uVar5) &&
          (((0 < (int)uVar5 || (uVar3 != 0)) &&
           ((uVar3 - 1 & uVar3) == 0 && (uVar5 - (uVar3 == 0) & uVar5) == 0)))) &&
         ((((g_opt_basic == 0 || ((1 << (t->dst->kind & 0x1f) & 6U) == 0)) ||
           (pcVar10 = t->dst->sym, pcVar10->cls != '\x03')) ||
          ((local_c = (c2_operand *)find_next_use_of_symbol_2(t,pcVar10),
           local_c == (c2_operand *)0x0 || (local_c->op != 0x178)))))) {
        pcVar6 = t->src->next;
        uVar15 = log2_floor((pcVar6->u18).lo);
        (pcVar6->u18).lo = uVar15;
        pcVar6->tag = (int)uVar15 >> 0x1f;
        t->op = 0x2a;
        return (c2_node *)t;
      }
    }
    t->op = (-(uint)(1 < (t->type & 0xfff)) & 0xbb) + 6;
    return (c2_node *)t;
  case 0x170:
    pcVar6 = load_operand_into_register(t,t->src->next,g_reg_symbols + 1);
    tuple_legalize_mem_operands(pcVar6->sym->def);
    tuple_replace_src(t,t->src->next,pcVar6);
    pcVar6 = t->dst;
    pcVar4 = operand_new_temp_in_reg(3,pcVar6->type);
    pcVar8 = tuple_new(1,t->type,pcVar6,pcVar4,tuple_insert_after,t);
    if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
      pcVar6->sym->def = pcVar8;
    }
    tuple_replace_dst(t,pcVar6,pcVar4);
    pcVar4->sym->def = t;
    pcVar6 = operand_new_hardreg(1,0x1004);
    tuple_append_dst(t,pcVar6);
    t->op = (-(uint)((t->type & 0xf000) != 0x2000) & 0xffffffe4) + 0x22;
    return (c2_node *)t;
  case 0x171:
    t->op = 0x2a;
    narrow_shift_count(t);
    return (c2_node *)t;
  case 0x173:
    t->op = 0x30;
    return (c2_node *)t;
  case 0x174:
    t->op = 0x34;
    return (c2_node *)t;
  case 0x175:
    pcVar6 = t->src;
    pcVar4 = pcVar6->next;
    if ((pcVar4->kind == '\a') && ((pcVar4->u18).reg == (c2_symbol *)0x0)) {
      warning(3,0x2d3);
    }
    uVar13 = t->type & 0xf000;
    if (((uVar13 == 0x2000) && (pcVar4->kind == '\a')) &&
       ((uVar5 = (pcVar4->u18).lo, 0 < (int)uVar5 && ((uVar5 & uVar5 - 1) == 0)))) {
      uVar15 = log2_floor(uVar5);
      (pcVar4->u18).lo = uVar15;
      t->op = 0x2b;
      pcVar4->tag = (int)uVar15 >> 0x1f;
      return (c2_node *)t;
    }
    if ((uVar13 == 0x1000) && (pcVar4->kind == '\a')) {
      divisor_temp = (pcVar4->u18).children;
      if (g_opt_favor_speed == 0) {
        if (divisor_temp != (c2_operand *)0x2) goto LAB_1071b8d1;
      }
      else {
        uVar5 = ((uint)divisor_temp ^ (int)divisor_temp >> 0x1f) - ((int)divisor_temp >> 0x1f);
        if (((int)uVar5 < 1) || ((uVar5 & uVar5 - 1) != 0)) goto LAB_1071b8d1;
      }
      if (divisor_temp != (c2_operand *)0x0) {
        iVar14 = (t->type & 0xfff) << 3;
        pcVar10 = reg_find_subreg(g_reg_symbols + 1,iVar14,0);
        uVar15 = pcVar10->id;
        pcVar10 = reg_find_subreg(g_reg_symbols + 3,iVar14,0);
        local_4 = pcVar10->id;
        pcVar10 = g_reg_symbols + uVar15;
        local_c = load_operand_into_register(t,pcVar6,pcVar10);
        tuple_legalize_mem_operands(local_c->sym->def);
        uVar13 = t->type;
        pcVar6 = operand_new_temp(uVar13);
        pcVar6->u18 = *(c2_operand_u18 *)(g_divide_high_reg_by_size + (uVar13 >> 1 & 0x7ff));
        emit_sign_extend_high(uVar13,local_c->sym->def,pcVar6,&local_c);
        uVar15 = ((uint)divisor_temp ^ (int)divisor_temp >> 0x1f) - ((int)divisor_temp >> 0x1f);
        if (uVar15 == 2) {
          pcVar8 = tuple_new_binary_temp(0x32,t->type,local_c,pcVar6,tuple_insert_before,t);
          pcVar6 = pcVar8->dst;
          uVar15 = 1;
          (pcVar6->u18).reg = pcVar10;
        }
        else {
          insert_fn = tuple_insert_before;
          pcVar8 = t;
          pcVar7 = operand_new_intconst(t->type,uVar15 - 1,(int)(uVar15 - 1) >> 0x1f);
          pcVar8 = tuple_new_binary_temp(0x2e,t->type,pcVar6,pcVar7,insert_fn,pcVar8);
          pcVar6 = pcVar8->dst;
          uVar2 = t->type;
          (pcVar6->u18).reg = g_reg_symbols + local_4;
          pcVar8 = tuple_new_binary_temp(0x2d,uVar2,local_c,pcVar6,tuple_insert_before,t);
          pcVar6 = pcVar8->dst;
          (pcVar6->u18).reg = pcVar10;
          uVar15 = log2_floor(uVar15);
        }
        if ((int)divisor_temp < 1) {
          insert_fn = tuple_insert_before;
          pcVar8 = t;
          pcVar7 = operand_new_intconst(0x1004,uVar15,(int)uVar15 >> 0x1f);
          pcVar8 = tuple_new_binary_temp(0x29,t->type,pcVar6,pcVar7,insert_fn,pcVar8);
          pcVar6 = pcVar8->dst;
          pcVar4 = t->src;
          (pcVar6->u18).reg = pcVar10;
          tuple_replace_src(t,pcVar4,pcVar6);
          tuple_remove_src(t,t->src->next);
          pcVar9 = (c2_node *)lower_int_tuple_case_161(t);
          return pcVar9;
        }
        tuple_replace_src(t,t->src,pcVar6);
        t->op = 0x29;
        (t->src->next->u18).lo = uVar15;
        return (c2_node *)t;
      }
    }
LAB_1071b8d1:
    t->op = (uVar13 != 0x2000) + 0x1f;
    return (c2_node *)t;
  case 0x176:
    pcVar6 = t->src;
    pcVar4 = pcVar6->next;
    uVar1 = pcVar4->kind;
    if ((uVar1 == '\a') && ((pcVar4->u18).reg == (c2_symbol *)0x0)) {
      warning(3,0x2d4);
    }
    if (((g_opt_favor_speed != 0) && ((t->type & 0xf000) == 0x1000)) && (uVar1 == '\a')) {
      uVar5 = (pcVar4->u18).lo;
      local_4 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
      if (((0 < (int)local_4) && ((local_4 & local_4 - 1) == 0)) && (uVar5 != 0)) {
        if ((int)uVar5 < 0) {
          pcVar10 = reg_find_subreg(g_reg_symbols + 1,(t->type & 0xfff) << 3,0);
          pcVar10 = g_reg_symbols + pcVar10->id;
          local_c = load_operand_into_register(t,pcVar6,pcVar10);
          tuple_legalize_mem_operands(local_c->sym->def);
          uVar13 = t->type;
          uVar15 = g_divide_high_reg_by_size[uVar13 >> 1 & 0x7ff]->id;
          divisor_temp = operand_new_temp_in_reg(uVar15,uVar13);
          emit_sign_extend_high(uVar13,local_c->sym->def,divisor_temp,&local_c);
          pcVar8 = tuple_new_binary_temp(0x34,t->type,local_c,divisor_temp,tuple_insert_before,t);
          uVar2 = t->type;
          (pcVar8->dst->u18).reg = pcVar10;
          divisor_temp = operand_new_temp_in_reg(uVar15,uVar2);
          tuple_append_dst(pcVar8,divisor_temp);
          pcVar6 = pcVar8->dst;
          uVar2 = t->type;
          divisor_temp->sym->def = pcVar8;
          pcVar11 = tuple_new_binary_temp(0x32,uVar2,pcVar6,divisor_temp,tuple_insert_before,t);
          uVar2 = t->type;
          (pcVar11->dst->u18).reg = pcVar10;
          divisor_temp = operand_new_temp_in_reg(uVar15,uVar2);
          tuple_append_dst(pcVar11,divisor_temp);
          divisor_temp->sym->def = pcVar11;
          insert_fn = tuple_insert_before;
          pcVar8 = t;
          pcVar7 = operand_new_intconst(t->type,local_4 - 1,(int)(local_4 - 1) >> 0x1f);
          pcVar8 = tuple_new_binary_temp(0x2e,t->type,pcVar11->dst,pcVar7,insert_fn,pcVar8);
          pcVar6 = pcVar8->dst;
          uVar2 = t->type;
          (pcVar6->u18).reg = pcVar10;
          pcVar8 = tuple_new_binary_temp(0x34,uVar2,pcVar6,divisor_temp,tuple_insert_before,t);
          uVar2 = t->type;
          (pcVar8->dst->u18).reg = pcVar10;
          pcVar12 = operand_new_temp_in_reg(uVar15,uVar2);
          tuple_append_dst(pcVar8,pcVar12);
          pcVar6 = pcVar8->dst;
          pcVar4 = t->src;
          pcVar12->sym->def = pcVar8;
          t->op = 0x32;
          tuple_replace_src(t,pcVar4,pcVar6);
          tuple_replace_src(t,t->src->next,pcVar12);
          return (c2_node *)t;
        }
        tuple_legalize_mem_operands(t);
        t->op = 0x166;
        pcVar7 = operand_new_intconst(0x1004,0x183,0);
        pcVar7->flags = pcVar7->flags | 0x10;
        pcVar7->next = t->src;
        t->src = pcVar7;
        return (c2_node *)t;
      }
    }
    break;
  case 0x177:
    t->op = (-(uint)((t->type & 0xf000) != 0x2000) & 0xfffffffe) + 0x2b;
    narrow_shift_count(t);
    return (c2_node *)t;
  case 0x17d:
    t->op = 0x2f;
    return (c2_node *)t;
  case 0x184:
    t->op = 0xe;
    return (c2_node *)t;
  case 0x185:
    pcVar10 = t->src->next->sym;
    if (((pcVar10->cls == '\x03') && (pcVar8 = pcVar10->def, pcVar8 != (c2_tuple *)0x0)) &&
       ((pcVar8->type & 0xf000) == 0x2000)) {
      *(byte *)&t->type = g_unsigned_cc[(byte)t->type];
    }
    t->op = 0xf;
    return (c2_node *)t;
  case 0x186:
    t->op = 0x10;
    return (c2_node *)t;
  case 0x18d:
    if ((t->switch_flags & 1) != 0) {
      pcVar8 = lower_switch_chain(t);
      return (c2_node *)pcVar8;
    }
    break;
  case 399:
    pcVar8 = lower_select(t);
    return (c2_node *)pcVar8;
  case 400:
    pcVar8 = lower_intrinsic(t);
    return (c2_node *)pcVar8;
  case 0x192:
  case 0x193:
  case 0x194:
  case 0x196:
  case 0x197:
  case 0x198:
  case 0x199:
  case 0x19a:
    pcVar8 = seh_lower_pseudo_op(t);
    return (c2_node *)pcVar8;
  case 0x1a5:
    pcVar8 = cxx_eh_lower_save_esp(t);
    return (c2_node *)pcVar8;
  case 0x1a7:
    insert_fn = tuple_insert_before;
    pcVar7 = operand_new_intconst(0x1004,0,0);
    pcVar8 = tuple_new_exit(8,0x1004,(c2_operand *)0x0,pcVar7,insert_fn,t);
    tuple_unlink_free(pcVar8->next);
    return (c2_node *)pcVar8;
  case 0x1a8:
    if ((g_cur_function->flags & 0x18000) == 0) {
      t->op = 0x145;
      return (c2_node *)t;
    }
    for (pcVar8 = tuple_next_real_before_boundary(t); pcVar8 != (c2_tuple *)0x0;
        pcVar8 = tuple_next_real_before_boundary(pcVar8)) {
      if (pcVar8->op != 0x1a0) {
        if ((pcVar8 != (c2_tuple *)0x0) && (pcVar8->op == 0x1a8)) {
          uVar2 = t->type;
          if ((uVar2 != pcVar8->type) && ((pcVar8->type & 0xfff) < (uVar2 & 0xfff))) {
            operand_set_type(pcVar8->dst,uVar2);
            pcVar6 = pcVar8->src;
            operand_set_type(pcVar6,t->type);
            pcVar4 = t->src;
            uVar16 = const_normalize(pcVar8->type,(pcVar4->u18).lo,pcVar4->tag);
            uVar5 = pcVar4->tag;
            (pcVar6->u18).lo = (pcVar6->u18).lo | (uint)uVar16 ^ (pcVar4->u18).lo;
            uVar2 = t->type;
            pcVar6->tag = pcVar6->tag | (uint)(uVar16 >> 0x20) ^ uVar5;
            pcVar8->type = uVar2;
          }
          for (local_c = t->src; local_c != (c2_operand *)0x0; local_c = local_c->next) {
            if (local_c->kind == '\v') {
              tuple_merge_memeffect_src(pcVar8,local_c);
            }
          }
          for (local_c = t->dst; local_c != (c2_operand *)0x0; local_c = local_c->next) {
            if (local_c->kind == '\v') {
              tuple_merge_memeffect_dst(pcVar8,local_c);
            }
          }
          t->op = 0x145;
          return (c2_node *)t;
        }
        break;
      }
    }
    pcVar8 = tuple_new(1,t->type,t->dst,t->src,tuple_insert_before,t);
    pcVar6 = pcVar8->dst;
    pcVar4 = t->dst->next;
    t->dst->next = (c2_operand *)0x0;
    pcVar12 = t->src;
    pcVar6->next = pcVar4;
    pcVar6 = pcVar8->src;
    pcVar4 = pcVar12->next;
    pcVar12->next = (c2_operand *)0x0;
    pcVar6->next = pcVar4;
LAB_1071bd93:
    tuple_unlink_free(t);
    t = pcVar8;
    break;
  case 0x1ab:
    node_list_free((c2_node *)(t->u20).cond_cells);
    t->op = 0x145;
    return (c2_node *)t;
  }
  return (c2_node *)t;
}

