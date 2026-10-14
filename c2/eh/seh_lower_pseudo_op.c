c2_tuple * __fastcall seh_lower_pseudo_op(c2_tuple *t)

{
  uint16_t type;
  c2_seh_try_scope *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_bitset *dst;
  uint32_t uVar9;
  uint8_t call_conv;
  code *pcVar10;
  c2_insert_fn *insert_fn;
  
  if (t->kind == '\x11') {
    if (t->op == 0x188) {
      pcVar6 = operand_new_codeaddr(0x154,t->src->sym);
      insert_fn = tuple_insert_before;
      call_conv = '\x04';
      *(uint *)((int)&pcVar6->sym->copy_equivs + 2) =
           *(uint *)((int)&pcVar6->sym->copy_equivs + 2) | 1;
      pcVar8 = t;
      pcVar7 = operand_new_hardreg(0x42,0x8000);
      pcVar8 = tuple_new_call(0xe,0x1004,pcVar7,pcVar6,call_conv,insert_fn,pcVar8);
      dst = bitset_new(8);
      bitset_set_range(dst,9);
      bitset_clear(dst,0);
      pcVar6 = operand_new_regset(dst);
      tuple_append_dst(pcVar8,pcVar6);
      pcVar8 = tail_return_esi(t);
      return pcVar8;
    }
    insert_fn = tuple_insert_after;
    pcVar8 = t;
    pcVar5 = operand_new_intconst(0x1004,0,0);
    pcVar6 = operand_new_hardreg(5,0x1004);
    tuple_new_exit(8,0x1004,pcVar6,pcVar5,insert_fn,pcVar8);
    return t;
  }
  if (t->kind == '\x12') {
    pcVar8 = t;
    switch((&BYTE_10760c09)[(t->u20).intrinsic.id]) {
    case 0:
      pcVar4 = fe_symbol_lookup_name("__abnormal_termination");
      pcVar6 = operand_new_codeaddr(0x153,pcVar4);
      pcVar8 = build_helper_call((c2_node *)t,0xe,pcVar6,'\0');
      return pcVar8;
    case 1:
      if (g_seh_record == (c2_symbol *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\ehgen.c",0x1bb);
      }
      if ((g_cur_function->flags & 0x2000) == 0) {
        return t;
      }
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0);
      pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
      pcVar10 = tuple_insert_after;
      pcVar6->flags11 = pcVar6->flags11 | 8;
      pcVar7 = operand_new_hardreg(5,0x1004);
      tuple_new(0x15b,0x1004,pcVar6,pcVar7,pcVar10,pcVar8);
      return t;
    case 2:
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,4);
      pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
      if (t->dst == (c2_operand *)0x0) {
        node_free((c2_node *)pcVar6);
        t->op = 0x145;
        return t;
      }
      pcVar8 = tuple_new(0x15b,0x1004,t->dst,pcVar6,tuple_insert_after,t);
      if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) {
        pcVar2 = pcVar8->dst->sym;
        if (pcVar2->storage->part_next == (c2_symbol *)0x0) {
          pcVar2->def = pcVar8;
          t->op = 0x145;
          return t;
        }
        symbol_mark_overlapping_parts(pcVar2,pcVar8);
      }
      goto LAB_10772757;
    case 3:
      if ((g_cur_function->flags & 8) != 0) {
        tuple_new_nooperands(0x8e,0x4004,tuple_insert_before,t);
      }
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,8);
      pcVar6 = operand_new_symaddr(0x14a,pcVar2);
      pcVar8 = tuple_new_unary_temp(0x15a,0x1004,pcVar6,tuple_insert_before,t);
      tuple_append_src(t,pcVar8->dst);
      lower_tuple(pcVar8);
      pcVar4 = fe_symbol_lookup_name("__local_unwind2");
      pcVar6 = operand_new_codeaddr(0x153,pcVar4);
      pcVar8 = build_helper_call((c2_node *)t,0xe,pcVar6,'\0');
      return pcVar8;
    case 4:
      pcVar6 = t->src->sym->def->src;
      if ((pcVar6->u18).reg == (c2_symbol *)0x0) {
        pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0);
        pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
        pcVar6->flags = pcVar6->flags | 0x40;
      }
      else {
        pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0);
        pcVar7 = operand_new_sym(0x14a,0x1004,pcVar2);
        pcVar7->flags11 = pcVar7->flags11 | 8;
        pcVar3 = tuple_new_unary_temp(1,0x1004,pcVar7,tuple_insert_before,t);
        pcVar7 = pcVar3->dst;
        pcVar3 = tuple_new_binary_temp(0x32,0x1004,pcVar7,pcVar6,tuple_insert_before,t);
        pcVar6 = pcVar3->dst;
        retie_register_chain(pcVar7,pcVar6);
      }
      pcVar10 = tuple_insert_before;
      pcVar7 = operand_new_hardreg(5,0x1004);
      uVar9 = 1;
      break;
    case 5:
      if ((g_cur_function->flags & 8) != 0) {
        tuple_new_nooperands(0x8e,0x4004,tuple_insert_before,t);
      }
      pcVar6 = t->src->sym->def->src;
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0x14);
      pcVar7 = operand_new_sym(0x14a,0x1004,pcVar2);
      pcVar10 = tuple_insert_after;
      pcVar7->flags11 = pcVar7->flags11 | 8;
      uVar9 = 0x15b;
    }
    tuple_new(uVar9,0x1004,pcVar7,pcVar6,pcVar10,pcVar8);
    tuple_free_src_defs(t);
    t->op = 0x145;
    return t;
  }
  switch(t->op) {
  case 0x192:
    if (g_opt_basic == 0) {
      if ((g_cur_function->flags & 8) != 0) {
        tuple_new_nooperands(0x8e,0x4004,tuple_insert_before,t);
      }
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0x14);
      pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
      pcVar10 = tuple_insert_before;
      uVar9 = ((t->u20).cond_cells)->cc;
      pcVar6->flags11 = pcVar6->flags11 | 8;
      pcVar8 = t;
      pcVar5 = operand_new_intconst(0x1004,uVar9,(int)uVar9 >> 0x1f);
      tuple_new(1,0x1004,pcVar6,pcVar5,pcVar10,pcVar8);
      break;
    }
    goto LAB_10772562;
  case 0x193:
    pcVar1 = (t->u20).seh_scope;
    if ((g_cur_function->flags & 8) != 0) {
      tuple_new_nooperands(0x8e,0x4004,tuple_insert_before,t);
    }
    if (g_opt_basic == 0) {
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0x14);
      pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
      uVar9 = pcVar1->enclosing_level;
      pcVar10 = tuple_insert_after;
      pcVar6->flags11 = pcVar6->flags11 | 8;
      pcVar8 = t;
      pcVar5 = operand_new_intconst(0x1004,uVar9,(int)uVar9 >> 0x1f);
      tuple_new(1,0x1004,pcVar6,pcVar5,pcVar10,pcVar8);
    }
    else if (pcVar1->kind == 2) {
      if (pcVar1->continuation_label == (c2_fe_symbol *)0x0) {
        pcVar5 = operand_new_intconst(0x1004,0,0);
      }
      else {
        pcVar5 = operand_new_codeaddr(0x153,pcVar1->continuation_label);
      }
      pcVar10 = tuple_insert_before;
      pcVar8 = t;
      pcVar6 = operand_new_hardreg(5,0x1004);
      pcVar7 = operand_new_hardreg(5,0x1004);
      tuple_new_binary(0xd,0x1004,pcVar7,pcVar5,pcVar6,pcVar10,pcVar8);
      t->op = 0x145;
      break;
    }
    t->op = 0x145;
    break;
  case 0x197:
    if (g_opt_basic != 0) goto LAB_10772562;
    pcVar2 = symbol_get_part(g_seh_record,0x1004,0,0x14);
    pcVar6 = operand_new_sym(0x14a,0x1004,pcVar2);
    pcVar10 = tuple_insert_after;
    pcVar6->flags11 = pcVar6->flags11 | 8;
    uVar9 = ((t->u20).seh_scope)->enclosing_level;
    pcVar8 = t;
    pcVar5 = operand_new_intconst(0x1004,uVar9,(int)uVar9 >> 0x1f);
    tuple_new(1,0x1004,pcVar6,pcVar5,pcVar10,pcVar8);
    break;
  case 0x198:
    if ((((t->u20).seh_scope)->flags & 1) != 0) {
      pcVar6 = t->dst;
      if (((pcVar6 == (c2_operand *)0x0) || ((1 << (pcVar6->kind & 0x1f) & 0x1eU) == 0)) ||
         (pcVar6->sym->fe != ((t->u20).seh_scope)->exception_info_local)) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\ehgen.c",0x13b);
      }
      tuple_detach_dst(t,pcVar6);
      pcVar2 = symbol_get_part(g_seh_record,0x1004,0,4);
      pcVar7 = operand_new_sym(0x14a,0x1004,pcVar2);
      pcVar7->flags11 = pcVar7->flags11 | 8;
      pcVar8 = tuple_new_unary_temp(1,g_ptr_type,pcVar7,tuple_insert_after,t);
      pcVar10 = tuple_insert_after;
      pcVar7 = operand_new_mem(0x14c,g_ptr_type,(c2_symbol *)0x0,0,pcVar8->dst,(c2_operand *)0x0,2);
      pcVar8 = tuple_new_unary_temp(1,g_ptr_type,pcVar7,pcVar10,pcVar8);
      pcVar7 = operand_new_mem(0x14c,g_ptr_type,(c2_symbol *)0x0,0,pcVar8->dst,(c2_operand *)0x0,2);
      tuple_new(1,g_ptr_type,pcVar6,pcVar7,tuple_insert_after,pcVar8);
    }
    break;
  case 0x199:
    pcVar6 = t->src;
    tuple_detach_src((c2_node *)t,pcVar6);
    type = t->type;
    insert_fn = tuple_insert_after;
    pcVar8 = t;
    pcVar7 = operand_new_hardreg(1,type);
    tuple_new(1,type,pcVar7,pcVar6,insert_fn,pcVar8);
    t->op = 0x145;
    break;
  case 0x19a:
    insert_fn = tuple_insert_before;
    pcVar8 = t;
    pcVar5 = operand_new_intconst(0x1004,0,0);
    tuple_new_exit(8,0x1004,(c2_operand *)0x0,pcVar5,insert_fn,pcVar8);
  }
  if (g_opt_basic != 0) {
LAB_10772562:
    if (t->op != 0x145) {
      if (t->op == 0x194) {
        t->op = 0x19c;
        pcVar8 = tuple_new_pseudo(0x19c,0x1004);
        tuple_insert_after(g_seh_try_end_label,pcVar8);
        return t;
      }
LAB_10772757:
      t->op = 0x145;
      return t;
    }
  }
  return t;
}

