c2_symbol * __fastcall number_assignment(c2_tuple *t,int record_equivalence)

{
  uint16_t type;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_copy_link *pcVar4;
  c2_symbol_cell *pcVar5;
  uint32_t bucket;
  c2_cse_expr *pcVar6;
  uint uVar7;
  c2_copy_link *pcVar8;
  c2_bitset *pcVar9;
  c2_symbol_cell *pcVar10;
  c2_symbol *dst_sym;
  c2_symbol *src_sym;
  c2_copy_link *copy_links;
  c2_symbol *expr;
  uint32_t expr_id;
  
  pcVar1 = t->dst;
  type = t->type;
  pcVar2 = t->src;
  cse_set_key_operands(2,pcVar1,pcVar2);
  bucket = hash_expression(0x15b,type);
  pcVar6 = cse_lookup(bucket,0x15b,type);
  if (pcVar6 != (c2_cse_expr *)0x0) {
    pcVar3 = pcVar6->sym;
    (t->u14).arg = pcVar3;
    return pcVar3;
  }
  pcVar6 = cse_insert(bucket,0x15b,type);
  expr = pcVar6->sym;
  uVar7 = 1 << (pcVar2->kind & 0x1f);
  if ((uVar7 & 6) == 0) {
    if ((uVar7 & 0x60) == 0) {
      src_sym = (c2_symbol *)0x0;
    }
    else {
      src_sym = (pcVar2->u18).reg;
    }
  }
  else {
    src_sym = pcVar2->sym;
  }
  if ((1 << (pcVar1->kind & 0x1f) & 6U) == 0) {
    dst_sym = (pcVar1->u18).reg;
  }
  else {
    dst_sym = pcVar1->sym;
  }
  if (src_sym != (c2_symbol *)0x0) {
    pcVar4 = (src_sym->u34).source_links;
    for (pcVar8 = pcVar4; pcVar8 != (c2_copy_link *)0x0; pcVar8 = pcVar8->next_of_source) {
      if (pcVar8->copy == expr) goto LAB_1070da0c;
    }
    pcVar8 = arena_alloc(0xd,0x10);
    copy_links = (expr->u38).copy_links;
    pcVar8->copy = expr;
    pcVar8->next_of_source = pcVar4;
    (src_sym->u34).source_links = pcVar8;
    pcVar8->source = src_sym;
    pcVar8->next_of_copy = copy_links;
    (expr->u38).copy_links = pcVar8;
    if (expr->dependents == (c2_bitset *)0x0) {
      pcVar9 = bitset_new(0xd);
      expr->dependents = pcVar9;
      bitset_set(pcVar9,expr->id);
    }
    if (src_sym->dependents == (c2_bitset *)0x0) {
      pcVar9 = bitset_new(0xd);
      src_sym->dependents = pcVar9;
      bitset_set(pcVar9,src_sym->id);
    }
    propagate_kill_sets(expr);
LAB_1070da0c:
    if (src_sym->kills == (c2_bitset *)0x0) {
      pcVar9 = bitset_new(0xd);
      src_sym->kills = pcVar9;
    }
    expr_id = expr->id;
    bitset_set(src_sym->kills,expr_id);
    if (src_sym->cls == '\x03') {
      bitset_set(g_call_killed_exprs,expr_id);
    }
  }
  pcVar4 = (dst_sym->u34).source_links;
  for (pcVar8 = pcVar4; pcVar8 != (c2_copy_link *)0x0; pcVar8 = pcVar8->next_of_source) {
    if (pcVar8->copy == expr) goto LAB_1070da94;
  }
  pcVar8 = arena_alloc(0xd,0x10);
  copy_links = (expr->u38).copy_links;
  pcVar8->copy = expr;
  pcVar8->next_of_source = pcVar4;
  (dst_sym->u34).source_links = pcVar8;
  pcVar8->source = dst_sym;
  pcVar8->next_of_copy = copy_links;
  (expr->u38).copy_links = pcVar8;
  if (expr->dependents == (c2_bitset *)0x0) {
    pcVar9 = bitset_new(0xd);
    expr->dependents = pcVar9;
    bitset_set(pcVar9,expr->id);
  }
  if (dst_sym->dependents == (c2_bitset *)0x0) {
    pcVar9 = bitset_new(0xd);
    dst_sym->dependents = pcVar9;
    bitset_set(pcVar9,dst_sym->id);
  }
  propagate_kill_sets(expr);
LAB_1070da94:
  if (dst_sym->kills == (c2_bitset *)0x0) {
    pcVar9 = bitset_new(0xd);
    dst_sym->kills = pcVar9;
  }
  bitset_set(dst_sym->kills,expr->id);
  if (record_equivalence != 0) {
    if (src_sym == dst_sym) {
      (t->u14).expr = expr;
      return expr;
    }
    pcVar10 = arena_alloc(0xd,8);
    pcVar5 = dst_sym->copy_equivs;
    pcVar10->sym = expr;
    pcVar10->next = pcVar5;
    dst_sym->copy_equivs = pcVar10;
  }
  (t->u14).expr = expr;
  return expr;
}

