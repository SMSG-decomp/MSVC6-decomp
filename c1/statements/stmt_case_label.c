void __cdecl stmt_case_label(c1_node *value)

{
  c1_type *pcVar1;
  void *pvVar2;
  void *pvVar3;
  c1_symbol *sym;
  uchar *rec;
  int iVar4;
  uint uVar5;
  uint uVar6;
  c1_case_record *next;
  c1_case_record *prev;
  ushort uVar7;
  uint value_hi;
  void *pvVar8;
  void *pvVar9;
  void *pvVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  if ((value->kind & 7) != 3) {
    diag_error(0x33);
    return;
  }
  pcVar1 = value->type;
  if (((pcVar1->code & 0x110) == 0) &&
     (((g_ms_extensions == '\0' || (-1 < (char)pcVar1->code)) ||
      ((uVar7 = pcVar1->code & 0x8f, uVar7 != 0x86 && (uVar7 != 0x82)))))) {
    diag_error(0x34,pcVar1);
    return;
  }
  pvVar2 = value->right;
  pvVar3 = value->left;
  pcVar1 = g_loop_top_label_stack->label->type;
  pvVar8 = pvVar3;
  pvVar9 = pvVar2;
  if (((int)pvVar2 < 1) && ((int)pvVar2 < 0)) {
    pvVar8 = (void *)-(int)pvVar3;
    pvVar9 = (void *)-((int)pvVar2 + (uint)(pvVar3 != (void *)0x0));
  }
  iVar4 = type_size_scalar(pcVar1);
  lVar11 = _allshl((char)iVar4 * '\b' - 1,0xffffffff,0xffffffff);
  lVar11 = _allshl(1,~(uint)lVar11,~(uint)((ulonglong)lVar11 >> 0x20));
  iVar4 = type_size_scalar(pcVar1);
  lVar12 = _allshl((char)iVar4 * '\b' - 1,0xffffffff,0xffffffff);
  pvVar10 = (void *)((uint)((ulonglong)lVar11 >> 0x20) | ~(uint)((ulonglong)lVar12 >> 0x20));
  if ((pvVar10 <= pvVar9) &&
     ((pvVar10 < pvVar9 || ((void *)((uint)lVar11 | ~(uint)lVar12) < pvVar8)))) {
    diag_warning(1,0xb2,pvVar3,pvVar2);
  }
  uVar13 = conv_cast_constant('c',(int)value,pcVar1);
  rec = g_arenas[4].cur;
  value_hi = (uint)(uVar13 >> 0x20);
  uVar5 = (uint)uVar13;
  g_arenas[4].cur = g_arenas[4].cur + 0x18;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  *(ulonglong *)(rec + 8) = uVar13;
  if (g_case_run_label == (c1_node *)0x0) {
    g_case_run_label = label_new(0x13);
    label_emit_definition(g_case_run_label);
  }
  sym = g_case_run_label->left;
  if (g_c9il_mode == '\0') {
    if ((sym->key_ref & 0xfffffff8) == 0) {
      uVar6 = il_symbol_key_assign(sym);
    }
    else {
      uVar6 = sym->key_ref >> 3;
    }
  }
  else {
    uVar6 = sym->entity & 0xffffff;
  }
  *(uint *)(rec + 0x10) = uVar6;
  sym_mark_referenced(g_case_run_label->left);
  uVar7 = pcVar1->code;
  if (((uVar7 & 0x2000) == 0) &&
     ((((g_ms_extensions != '\0' || ((uVar7 & 0xfff) != 0x11)) || ((uVar7 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    prev = (c1_case_record *)0x0;
    for (next = g_switch_case_stack->cases; next != (c1_case_record *)0x0; next = next->next) {
      if (((int)value_hi < next->value_hi) ||
         (((int)value_hi <= next->value_hi && (uVar5 <= next->value_lo)))) goto LAB_1061e91f;
      prev = next;
    }
  }
  else {
    prev = (c1_case_record *)0x0;
    for (next = g_switch_case_stack->cases; next != (c1_case_record *)0x0; next = next->next) {
      if ((value_hi < (uint)next->value_hi) ||
         ((value_hi == next->value_hi && (uVar5 <= next->value_lo)))) goto LAB_1061e91f;
      prev = next;
    }
  }
LAB_1061e8de:
  *(c1_case_record **)rec = next;
  if (prev != (c1_case_record *)0x0) {
    prev->next = (c1_case_record *)rec;
    return;
  }
  g_switch_case_stack->cases = (c1_case_record *)rec;
  return;
LAB_1061e91f:
  if ((next != (c1_case_record *)0x0) && (uVar5 == next->value_lo)) {
    stmt_check_duplicate_case(prev,next,value_hi,(c1_case_record *)rec);
    return;
  }
  goto LAB_1061e8de;
}

