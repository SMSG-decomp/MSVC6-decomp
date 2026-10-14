c2_node * __fastcall emit_tree_as_tuples(c2_tuple *t)

{
  ushort uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  uint uVar5;
  int iVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_symbol *pcVar9;
  int iVar10;
  c2_operand *local_14;
  int local_10;
  c2_operand *local_c;
  uint32_t local_8;
  c2_operand *local_4;
  
  if (t->flags12 == '\x01') {
    tuple_relink_mem_subops(t);
    if ((t->kind == '\x0e') || (t->kind == '\x12')) {
      pcVar9 = reverse_operand_list((c2_symbol *)t->src);
      t->src = (c2_operand *)pcVar9;
    }
    uVar4 = is_reorderable_binary_opcode((c2_node *)t);
    if (((uVar4 == 0) || (iVar10 = compare_operand_cost_desc(t->src,t->src->next), iVar10 < 1)) ||
       ((t->type & 0xf000) == 0x4000)) {
      pcVar3 = t->src;
      while (pcVar7 = pcVar3, pcVar7 != (c2_operand *)0x0) {
        pcVar3 = pcVar7->next;
        if ((((1 << (pcVar7->kind & 0x1f) & 6U) != 0) &&
            (pcVar8 = pcVar7->sym->def, pcVar8 != (c2_tuple *)0x0)) &&
           (local_14 = (c2_operand *)emit_tree_as_tuples(pcVar8),
           (1 << (local_14->kind & 0x1f) & 0xffeU) != 0)) {
          uVar1 = pcVar7->type;
          if (uVar1 != local_14->type) {
            pcVar9 = symbol_get_part(local_14->sym,uVar1,uVar1 & 0xfff,0);
            local_14->sym = pcVar9;
            local_14->type = pcVar7->type;
          }
          tuple_replace_src(t,pcVar7,local_14);
        }
      }
    }
    else {
      local_c = t->src;
      pcVar3 = local_c->next;
      uVar5 = 1 << (pcVar3->kind & 0x1f);
      if (((uVar5 & 6) == 0) || (pcVar8 = pcVar3->sym->def, pcVar8 == (c2_tuple *)0x0)) {
        if (((((uVar5 & 0x60) != 0) &&
             ((pcVar7 = pcVar3->base, pcVar7 == (c2_operand *)0x0 ||
              (((1 << (pcVar7->kind & 0x1f) & 6U) != 0 && (pcVar7->sym->def != (c2_tuple *)0x0))))))
            && ((pcVar2 = pcVar3->index, pcVar2 == (c2_operand *)0x0 ||
                (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0))))
               )) && ((pcVar7 != pcVar2 &&
                      (local_14 = (c2_operand *)emit_tree_as_tuples(pcVar7->sym->def),
                      (1 << (local_14->kind & 0x1f) & 0xffeU) != 0)))) {
          node_free((c2_node *)pcVar3->base);
          pcVar3->base = local_14;
          tuple_append_base_index(t,pcVar3);
        }
      }
      else {
        local_14 = (c2_operand *)emit_tree_as_tuples(pcVar8);
        if ((1 << (local_14->kind & 0x1f) & 0xffeU) != 0) {
          uVar1 = pcVar3->type;
          if (uVar1 != local_14->type) {
            pcVar9 = symbol_get_part(local_14->sym,uVar1,uVar1 & 0xfff,0);
            local_14->sym = pcVar9;
            local_14->type = uVar1;
          }
          tuple_replace_src(t,pcVar3,local_14);
        }
      }
      pcVar3 = local_c;
      uVar5 = 1 << (local_c->kind & 0x1f);
      if (((uVar5 & 6) == 0) || (pcVar8 = local_c->sym->def, pcVar8 == (c2_tuple *)0x0)) {
        if (((((uVar5 & 0x60) != 0) &&
             ((pcVar7 = local_c->base, pcVar7 == (c2_operand *)0x0 ||
              (((1 << (pcVar7->kind & 0x1f) & 6U) != 0 && (pcVar7->sym->def != (c2_tuple *)0x0))))))
            && ((pcVar2 = local_c->index, pcVar2 == (c2_operand *)0x0 ||
                (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0))))
               )) && ((pcVar7 != pcVar2 &&
                      (local_14 = (c2_operand *)emit_tree_as_tuples(pcVar7->sym->def),
                      (1 << (local_14->kind & 0x1f) & 0xffeU) != 0)))) {
          node_free((c2_node *)pcVar3->base);
          pcVar3->base = local_14;
          tuple_append_base_index(t,pcVar3);
        }
      }
      else {
        local_14 = (c2_operand *)emit_tree_as_tuples(pcVar8);
        if ((1 << (local_14->kind & 0x1f) & 0xffeU) != 0) {
          uVar1 = pcVar3->type;
          if (uVar1 != local_14->type) {
            pcVar9 = symbol_get_part(local_14->sym,uVar1,uVar1 & 0xfff,0);
            local_14->sym = pcVar9;
            local_14->type = uVar1;
          }
          tuple_replace_src(t,pcVar3,local_14);
        }
      }
    }
    if ((t->kind == '\x0e') || (t->kind == '\x12')) {
      pcVar9 = reverse_operand_list((c2_symbol *)t->src);
      t->src = (c2_operand *)pcVar9;
    }
    tuple_insert_before(g_simplify_insert_before,t);
    return (c2_node *)t;
  }
  local_c = t->dst;
  local_c->flags = local_c->flags & 0xef;
  local_14 = operand_new_temp(local_c->type);
  pcVar3 = operand_claim(local_14);
  t->dst = pcVar3;
  pcVar9 = pcVar3->sym;
  if (pcVar9->storage->part_next == (c2_symbol *)0x0) {
    pcVar9->def = t;
  }
  else {
    symbol_mark_overlapping_parts(pcVar9,t);
  }
  if (t->op == 400) {
    local_14 = t->src;
    iVar10 = 0;
    local_10 = 0;
    if (local_14 != (c2_operand *)0x0) {
      do {
        local_14 = local_14->next;
        iVar10 = iVar10 + 1;
      } while (local_14 != (c2_operand *)0x0);
      local_14 = (c2_operand *)0x0;
      local_10 = iVar10;
    }
  }
  else if (t->op == 399) {
    local_10 = 3;
  }
  else {
    uVar4 = is_unary_il_opcode((c2_node *)t);
    local_10 = 2 - (uint)(uVar4 != 0);
  }
  pcVar3 = t->src;
  iVar10 = 0;
  t->src = (c2_operand *)0x0;
  uVar4 = is_reorderable_binary_opcode((c2_node *)t);
  pcVar8 = t;
  if (((uVar4 == 0) || (iVar6 = compare_operand_cost_desc(pcVar3,pcVar3->next), iVar6 < 1)) ||
     ((t->type & 0xf000) == 0x4000)) {
    local_8 = t->op;
    while (pcVar3 != (c2_operand *)0x0) {
      local_4 = pcVar3->next;
      pcVar3->next = (c2_operand *)0x0;
      if (iVar10 == local_10) {
        tuple_relink_mem_subops(pcVar8);
        tuple_insert_before(g_simplify_insert_before,pcVar8);
      }
      local_14 = (c2_operand *)emit_operand_subtree(pcVar3);
      if (iVar10 == local_10) {
        pcVar8 = tuple_new_binary_temp
                           (local_8,t->type,pcVar8->dst,local_14,(c2_insert_fn *)0x0,(c2_tuple *)0x0
                           );
        iVar10 = 2;
        pcVar3 = local_4;
      }
      else if (local_8 == 0x15f) {
        pcVar8 = convert_operand(&local_14,pcVar8->type,&g_simplify_insert_before->prev);
        node_free((c2_node *)t);
        if (pcVar8 == (c2_tuple *)0x0) {
          if ((((1 << (local_14->kind & 0x1f) & 6U) != 0) && (local_14->sym->def != (c2_tuple *)0x0)
              ) && (((1 << (local_c->kind & 0x1f) & 6U) != 0 &&
                    (local_c->sym->def != (c2_tuple *)0x0)))) {
            pcVar8 = local_14->sym->def;
            if ((local_14->flags & 0x10) == 0) {
              node_free((c2_node *)local_14);
            }
            pcVar7 = local_c;
            local_14 = (c2_operand *)node_clone((c2_node *)local_c);
            pcVar9 = symbol_get_part(local_14->sym,pcVar8->type,pcVar8->type & 0xfff,0);
            pcVar3 = pcVar8->dst;
            local_14->sym = pcVar9;
            pcVar9 = pcVar3->sym;
            local_14->type = pcVar8->type;
            symbol_free_chain(pcVar9->storage);
            tuple_replace_dst(pcVar8,pcVar3,local_14);
            pcVar9 = local_14->sym;
            if (pcVar9->storage->part_next == (c2_symbol *)0x0) {
              pcVar9->def = pcVar8;
              return (c2_node *)pcVar7;
            }
            symbol_mark_overlapping_parts(pcVar9,pcVar8);
            return (c2_node *)pcVar7;
          }
          pcVar8 = tuple_new_unary_temp
                             (0x15b,local_14->type,local_14,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
          iVar10 = iVar10 + 1;
          tuple_unlink(pcVar8);
          tuple_unlink_mem_subops(pcVar8);
          pcVar3 = local_4;
        }
        else {
          if (pcVar8 != local_14->sym->def) {
            tuple_relink_mem_subops(pcVar8);
            pcVar8 = local_14->sym->def;
          }
          iVar10 = iVar10 + 1;
          tuple_unlink(pcVar8);
          tuple_unlink_mem_subops(pcVar8);
          pcVar3 = local_4;
        }
      }
      else {
        tuple_append_src(pcVar8,local_14);
        iVar10 = iVar10 + 1;
        pcVar3 = local_4;
      }
    }
  }
  else {
    pcVar7 = (c2_operand *)emit_operand_subtree(pcVar3->next);
    pcVar3 = (c2_operand *)emit_operand_subtree(pcVar3);
    pcVar7->next = (c2_operand *)0x0;
    pcVar3->next = (c2_operand *)0x0;
    tuple_append_src(t,pcVar3);
    tuple_append_src(t,pcVar7);
  }
  pcVar3 = pcVar8->dst;
  symbol_free_chain(pcVar3->sym->storage);
  pcVar7 = local_c;
  tuple_replace_dst(pcVar8,pcVar3,local_c);
  uVar5 = 1 << (pcVar7->kind & 0x1f);
  if (((uVar5 & 6) == 0) || (pcVar9 = pcVar7->sym, pcVar9->def == (c2_tuple *)0x0)) {
    if (((((uVar5 & 0x60) != 0) &&
         ((pcVar3 = pcVar7->base, pcVar3 == (c2_operand *)0x0 ||
          (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 && (pcVar3->sym->def != (c2_tuple *)0x0)))))) &&
        ((pcVar2 = pcVar7->index, pcVar2 == (c2_operand *)0x0 ||
         (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))))) &&
       (pcVar3 != pcVar2)) {
      emit_operand_subtree(pcVar7);
      pcVar7->flags = pcVar7->flags | 0x10;
    }
  }
  else if (pcVar9->storage->part_next == (c2_symbol *)0x0) {
    pcVar9->def = pcVar8;
  }
  else {
    symbol_mark_overlapping_parts(pcVar9,pcVar8);
  }
  tuple_relink_mem_subops(pcVar8);
  tuple_insert_before(g_simplify_insert_before,pcVar8);
  return (c2_node *)pcVar8;
}

