c2_tuple * __fastcall lower_select_sbb(c2_tuple *sel,int emit,uint32_t *cost)

{
  byte bVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_tuple *t;
  c2_symbol *pcVar4;
  uint16_t type;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  c2_operand *pcVar9;
  c2_operand *new_op;
  c2_tuple *pcVar10;
  c2_operand *pcVar11;
  c2_const_operand *pcVar12;
  c2_tuple *pcVar13;
  c2_operand *pcVar14;
  uint64_t uVar15;
  c2_operand *pcVar16;
  code *pcVar17;
  c2_operand *local_38;
  c2_operand *local_30;
  int local_28;
  uint32_t local_24;
  c2_operand *local_1c;
  int local_18;
  c2_tuple *local_c;
  int32_t a_value;
  c2_insert_fn *insert_fn;
  
  pcVar14 = (c2_operand *)0x0;
  pcVar16 = sel->dst;
  bVar6 = false;
  bVar1 = pcVar16->kind;
  local_28 = 0;
  local_18 = 0;
  local_c = (c2_tuple *)0x0;
  local_24 = 0x145;
  bVar5 = false;
  *cost = 500;
  local_38 = pcVar16;
  if ((((1 << (bVar1 & 0x1f) & 6U) == 0) || (pcVar16->sym->def == (c2_tuple *)0x0)) && (emit != 0))
  {
    local_38 = operand_new_temp(pcVar16->type);
    tuple_new(1,pcVar16->type,pcVar16,local_38,tuple_insert_after,sel);
    tuple_replace_dst(sel,pcVar16,local_38);
    pcVar4 = local_38->sym;
    if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
      pcVar4->def = sel;
    }
    else {
      symbol_mark_overlapping_parts(pcVar4,sel);
    }
  }
  pcVar16 = sel->src;
  uVar2 = (sel->u20).cc;
  pcVar11 = pcVar16->next;
  local_1c = pcVar11->next;
  iVar7 = select_operands_allow_sbb(pcVar11,local_1c);
  if ((iVar7 == 0) && (emit == 0)) {
    return (c2_tuple *)0x0;
  }
  type = 0x1004;
  if ((local_38->type & 0xfff) != 2) {
    type = local_38->type;
  }
  t = pcVar16->sym->def;
  if (t->op == 0x10f) {
    return (c2_tuple *)0x0;
  }
  if (emit != 0) {
    pcVar9 = t->dst;
    (pcVar16->u18).reg = g_reg_symbols + 0x42;
    (pcVar9->u18).reg = g_reg_symbols + 0x42;
  }
  if (uVar2 == '\x01') {
    bVar6 = true;
LAB_10749915:
    pcVar9 = t->src;
    local_28 = 1;
    if (((1 << (pcVar9->kind & 0x1f) & 6U) == 0) ||
       (pcVar10 = pcVar9->sym->def, pcVar10 == (c2_tuple *)0x0)) {
      if (emit != 0) {
        pcVar9 = emit_load_into_register(1,t,pcVar9,g_reg_symbols);
        tuple_replace_src(t,t->src,pcVar9);
      }
LAB_10749a6a:
      local_18 = 1;
    }
    else if ((((pcVar10->op == 1) && (pcVar10->src->kind == '\x06')) &&
             (((pcVar10->type ^ t->type) & 0xfff) == 0)) &&
            ((uVar2 = pcVar9->next->kind, uVar2 == '\a' || (uVar2 == '\x01')))) goto LAB_10749a6a;
    pcVar9 = t->src->next;
    new_op = (c2_operand *)cost;
    if ((pcVar9->kind == '\a') && ((pcVar9->u18).reg == (c2_symbol *)0x0)) {
      if (emit == 0) {
        local_28 = 0;
      }
      else {
        new_op = (c2_operand *)node_clone((c2_node *)t->src);
        tuple_unlink_free(t);
        local_28 = 0;
      }
    }
    if (emit == 0) {
      pcVar9 = t->src;
      if (((pcVar9->kind == '\a') && ((pcVar9->u18).reg == (c2_symbol *)0x1)) ||
         ((pcVar9->next->kind == '\a' && ((pcVar9->next->u18).reg == (c2_symbol *)0x1)))) {
        local_28 = 0;
      }
    }
    else {
      if (local_28 != 0) {
        t->op = 0x32;
        new_op = operand_new_temp(t->type);
        tuple_replace_dst(t,t->dst,new_op);
        new_op->sym->def = t;
      }
      local_c = tuple_new_unary_temp(0x23,new_op->type,new_op,tuple_insert_before,sel);
      tuple_append_dst(local_c,pcVar16);
      pcVar16->sym->def = local_c;
    }
  }
  else {
    if (uVar2 == '\x02') goto LAB_10749915;
    if ((t->type & 0xf000) != 0x2000) {
      return (c2_tuple *)0x0;
    }
    if (uVar2 != '\x03') {
      if (uVar2 == '\x04') {
        bVar5 = true;
      }
      else if (uVar2 == '\x05') {
        bVar5 = true;
        bVar6 = true;
      }
      else {
        bVar6 = true;
      }
    }
    if (bVar5) {
      if (emit != 0) {
        tuple_swap_first_srcs(t);
      }
      if (t->src->kind == '\a') {
        if (emit != 0) {
          pcVar9 = emit_load_into_register(1,t,t->src,g_reg_symbols);
          tuple_replace_src(t,t->src,pcVar9);
        }
        local_18 = 1;
      }
    }
  }
  local_30 = pcVar11;
  if (bVar6) {
    local_30 = local_1c;
    local_1c = pcVar11;
  }
  if (local_30->kind == '\a') {
    if (local_1c->kind == '\a') {
      uVar15 = const_normalize(local_30->type,(local_30->u18).lo,local_30->tag);
      a_value = (int32_t)uVar15;
      uVar15 = const_normalize(local_1c->type,(local_1c->u18).lo,local_1c->tag);
      pcVar11 = (c2_operand *)uVar15;
      if ((undefined1 *)a_value == (undefined1 *)0xffffffff) {
        if (pcVar11 == (c2_operand *)0x0) {
          iVar7 = 0xe;
          local_30 = pcVar14;
          local_1c = pcVar11;
          goto LAB_10749b60;
        }
      }
      else if ((undefined1 *)a_value == (undefined1 *)0x1) {
        if (pcVar11 == (c2_operand *)0x0) {
          iVar7 = 0x10;
          local_30 = pcVar14;
          local_1c = pcVar11;
          goto LAB_10749b60;
        }
      }
      else if ((undefined1 *)a_value == (undefined1 *)0x0) {
        if (pcVar11 == (c2_operand *)0xffffffff) {
          iVar7 = 0x11;
          local_24 = 0x23;
          local_30 = pcVar14;
          local_1c = pcVar11;
        }
        else {
          if (pcVar11 != (c2_operand *)0x1) goto LAB_10749c94;
          iVar7 = 0xf;
          local_30 = pcVar14;
          local_1c = pcVar11;
        }
        goto LAB_10749b60;
      }
LAB_10749c94:
      if ((undefined1 *)a_value == (undefined1 *)((int)&pcVar11[-1].index + 3)) {
        iVar7 = 0x12;
        local_30 = local_1c;
        local_1c = pcVar11;
      }
      else if ((undefined1 *)a_value == (undefined1 *)((int)&pcVar11->next + 1)) {
        iVar7 = 0x14;
        local_24 = 0x23;
        local_30 = local_1c;
        local_1c = pcVar11;
      }
      else if (pcVar11 == (c2_operand *)0x0) {
        iVar7 = 0x13;
        local_1c = pcVar11;
      }
      else {
        iVar7 = 0x16;
        local_1c = pcVar11;
      }
    }
    else {
      iVar7 = 0x15;
      local_24 = 0x24;
      local_30 = local_1c;
    }
  }
  else {
    iVar7 = 0x13;
  }
LAB_10749b60:
  if (g_opt_favor_speed == 0) {
    iVar8 = 2;
  }
  else {
    iVar8 = g_opt_cpu_target + -4;
  }
  *cost = (uint)g_select_form_cost_table[iVar7][iVar8] +
          (uint)g_select_form_cost_table[2][iVar8] * local_18 +
          (uint)g_select_form_cost_table[6][iVar8] * local_28;
  if (emit == 0) {
    return (c2_tuple *)0x0;
  }
  insert_fn = tuple_insert_before;
  if (iVar7 == 0xe) {
    pcVar10 = sel;
    pcVar14 = operand_narrow_to(local_38,type,0);
    pcVar10 = tuple_new(0x119,type,pcVar14,pcVar16,insert_fn,pcVar10);
    local_38->sym->def = pcVar10;
  }
  else {
    pcVar10 = tuple_new_unary_temp(0x119,type,pcVar16,tuple_insert_before,sel);
  }
  if (local_c != (c2_tuple *)0x0) {
    tuple_append_src(pcVar10,local_c->dst);
    pcVar10->src->next->u18 = pcVar10->dst->u18;
  }
  flags_bind_compare_result(pcVar10,pcVar10->src);
  switch(iVar7) {
  case 0xe:
    goto override_jmp_10749d7f_case_0;
  default:
    pcVar16 = pcVar10->dst;
    break;
  case 0x11:
    pcVar10 = tuple_new_unary_temp(local_24,type,pcVar10->dst,tuple_insert_before,sel);
    pcVar16 = pcVar10->dst;
    break;
  case 0x12:
  case 0x13:
    pcVar17 = tuple_insert_before;
    pcVar16 = local_30;
    pcVar13 = sel;
    pcVar14 = operand_narrow_to(pcVar10->dst,local_30->type,0);
    pcVar11 = operand_narrow_to(local_38,local_30->type,0);
    pcVar10 = tuple_new_binary(g_select_form_opcodes[iVar7],local_30->type,pcVar11,pcVar14,pcVar16,
                               pcVar17,pcVar13);
    uVar3 = local_30->type;
    goto LAB_10749e2b;
  case 0x14:
  case 0x15:
    pcVar13 = tuple_new_unary_temp(local_24,type,pcVar10->dst,tuple_insert_before,sel);
    insert_fn = tuple_insert_before;
    pcVar16 = local_30;
    pcVar10 = sel;
    pcVar14 = operand_narrow_to(pcVar13->dst,local_30->type,0);
    pcVar11 = operand_narrow_to(local_38,local_30->type,0);
    pcVar10 = tuple_new_binary(g_select_form_opcodes[iVar7],local_30->type,pcVar11,pcVar14,pcVar16,
                               insert_fn,pcVar10);
    uVar3 = local_30->type;
LAB_10749e2b:
    if (((uVar3 & 0xfff) < 4) && (iVar7 = operand_readable_as_dword(local_30), iVar7 != 0)) {
      set_op_width(pcVar10,4);
    }
    goto override_jmp_10749d7f_case_0;
  case 0x16:
    insert_fn = tuple_insert_before;
    pcVar13 = sel;
    pcVar12 = operand_new_intconst(type,a_value - (int)local_1c,a_value - (int)local_1c >> 0x1f);
    pcVar13 = tuple_new_binary_temp(0x2e,type,pcVar10->dst,pcVar12,insert_fn,pcVar13);
    insert_fn = tuple_insert_before;
    pcVar10 = sel;
    pcVar12 = operand_new_intconst(type,(uint32_t)local_1c,(int)local_1c >> 0x1f);
    pcVar16 = pcVar13->dst;
    pcVar14 = operand_narrow_to(local_38,type,0);
    pcVar10 = tuple_new_binary(0x2d,type,pcVar14,pcVar16,pcVar12,insert_fn,pcVar10);
    goto override_jmp_10749d7f_case_0;
  }
  pcVar17 = tuple_insert_before;
  pcVar10 = sel;
  pcVar14 = operand_narrow_to(local_38,type,0);
  pcVar10 = tuple_new(g_select_form_opcodes[iVar7],type,pcVar14,pcVar16,pcVar17,pcVar10);
override_jmp_10749d7f_case_0:
  pcVar4 = pcVar10->dst->sym;
  if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
    pcVar4->def = pcVar10;
  }
  else {
    symbol_mark_overlapping_parts(pcVar4,pcVar10);
  }
  tie_dest_to_source_temp(pcVar10);
  tuple_unlink_free(sel);
  if (bVar5) {
    legalize_machine_tuple(t);
  }
  return pcVar10;
}

