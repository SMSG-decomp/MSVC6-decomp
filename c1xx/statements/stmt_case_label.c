void __cdecl stmt_case_label(c1_node *node)

{
  c1_type *pcVar1;
  c1_symbol *sym;
  c1_u8 *rec;
  c1_node *k;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  void **found;
  void **prev;
  ushort uVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  void *pvVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  
  k = fold_static_const_member(node);
  if ((k->kind & 7) != 3) {
    diag_error(0x33);
    return;
  }
  pcVar1 = k->type;
  if (((pcVar1->code & 0x110) == 0) &&
     (((g_ms_extensions == '\0' || (-1 < (char)pcVar1->code)) ||
      ((uVar5 = pcVar1->code & 0x8f, uVar5 != 0x86 && (uVar5 != 0x82)))))) {
    diag_error(0x34,pcVar1);
    return;
  }
  pvVar3 = k->right;
  pvVar6 = k->left;
  pcVar1 = g_loop_top_label_stack->label->type;
  pvVar7 = pvVar6;
  pvVar8 = pvVar3;
  if (((int)pvVar3 < 1) && ((int)pvVar3 < 0)) {
    pvVar7 = (void *)-(int)pvVar6;
    pvVar8 = (void *)-((int)pvVar3 + (uint)(pvVar6 != (void *)0x0));
  }
  iVar2 = type_size_scalar(pcVar1);
  lVar10 = _allshl((char)iVar2 * '\b' - 1,0xffffffff,0xffffffff);
  lVar10 = _allshl(1,~(uint)lVar10,~(uint)((ulonglong)lVar10 >> 0x20));
  iVar2 = type_size_scalar(pcVar1);
  lVar11 = _allshl((char)iVar2 * '\b' - 1,0xffffffff,0xffffffff);
  pvVar9 = (void *)((uint)((ulonglong)lVar10 >> 0x20) | ~(uint)((ulonglong)lVar11 >> 0x20));
  if ((pvVar9 <= pvVar8) && ((pvVar9 < pvVar8 || ((void *)((uint)lVar10 | ~(uint)lVar11) < pvVar7)))
     ) {
    diag_warning(1,0xb2,pvVar6,pvVar3);
  }
  uVar12 = conv_cast_constant(99,k,pcVar1);
  rec = g_arenas[6].cur;
  pvVar6 = (void *)(uVar12 >> 0x20);
  pvVar3 = (void *)uVar12;
  g_arenas[6].cur = g_arenas[6].cur + 0x18;
  if (g_arenas[6].end < g_arenas[6].cur) {
    arena_grow(g_arenas + 6);
  }
  *(ulonglong *)(rec + 8) = uVar12;
  if (g_case_label == (c1_node *)0x0) {
    g_case_label = label_new(0x13);
    label_emit_definition(g_case_label);
  }
  stmt_case_label_flow_state(k);
  sym = g_case_label->left;
  if (g_c9il_mode == '\0') {
    if ((sym->key_ref & 0xfffffff8) == 0) {
      uVar4 = il_symbol_key_assign(sym);
    }
    else {
      uVar4 = sym->key_ref >> 3;
    }
  }
  else {
    uVar4 = sym->entity & 0xffffff;
  }
  *(uint *)(rec + 0x10) = uVar4;
  sym_mark_referenced(g_case_label->left);
  uVar5 = pcVar1->code;
  if (((uVar5 & 0x2000) == 0) &&
     ((((uVar5 & 0xfff) != 0x11 || ((uVar5 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    prev = (void **)0x0;
    for (found = g_switch_case_stack->cases; found != (void **)0x0; found = *found) {
      if (((int)pvVar6 < (int)found[3]) || (((int)pvVar6 <= (int)found[3] && (pvVar3 <= found[2]))))
      goto LAB_10441b93;
      prev = found;
    }
  }
  else {
    prev = (void **)0x0;
    for (found = g_switch_case_stack->cases; found != (void **)0x0; found = *found) {
      if ((pvVar6 < found[3]) || ((pvVar6 == found[3] && (pvVar3 <= found[2])))) goto LAB_10441b93;
      prev = found;
    }
  }
LAB_10441b28:
  *(void ***)rec = found;
  if (prev != (void **)0x0) {
    *prev = rec;
    return;
  }
  g_switch_case_stack->cases = rec;
  return;
LAB_10441b93:
  if ((found != (void **)0x0) && (pvVar3 == found[2])) {
    stmt_check_duplicate_case(found,prev,(uint)pvVar3,(int)pvVar6,(void **)rec);
    return;
  }
  goto LAB_10441b28;
}

