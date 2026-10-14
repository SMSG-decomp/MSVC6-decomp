c1_node * __cdecl tree_new_constant(c1_type *type,c1_u32 *value,int arena)

{
  char cVar1;
  char cVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  void *pvVar5;
  uint uVar6;
  float10 *a;
  c1_type *pcVar7;
  c1_type *pcVar8;
  int iVar9;
  fe_arena *a_00;
  c1_type local_10;
  
  a_00 = g_arenas + arena;
  pcVar3 = (c1_node *)a_00->cur;
  pcVar4 = (c1_node *)g_arenas[arena].end;
  a_00->cur = &pcVar3[1].op;
  if (pcVar4 < pcVar3 + 1) {
    arena_grow(a_00);
  }
  pcVar3->kind = '\x03';
  pcVar3->op = 'e';
  cVar2 = (char)type->code;
  pcVar8 = type;
  cVar1 = cVar2;
  while (cVar1 < '\0') {
    pcVar8 = pcVar8->base;
    cVar1 = (char)pcVar8->code;
  }
  pcVar7 = type;
  if ((pcVar8->code & 0x10) == 0) {
    while (cVar2 < '\0') {
      cVar2 = (char)pcVar7->base->code;
      pcVar7 = pcVar7->base;
    }
    if ((pcVar7->code & 0x20) != 0) {
      a = (float10 *)*value;
      pcVar3->left = a;
      iVar9 = float_const_compare_mask(6,a,(float10 *)&g_float_zero);
      if ((iVar9 != 0) ||
         (iVar9 = float_const_compare_mask(6,pcVar3->left,(float10 *)&g_float_one), iVar9 != 0)) {
        pcVar3->flags = pcVar3->flags | 1;
      }
    }
  }
  else {
    pcVar3->left = (void *)*value;
    pvVar5 = (void *)value[1];
    pcVar3->right = pvVar5;
    if (pcVar3->left == (void *)0x0 && pvVar5 == (void *)0x0) {
      pcVar3->kind = 0x83;
    }
  }
  if ((type->flags & 0x20) == 0x20) {
    pcVar3->type = type;
    return pcVar3;
  }
  local_10.base = type->base;
  uVar6._0_2_ = type->code;
  uVar6._2_2_ = type->flags;
  local_10.extra = type->extra;
  local_10.debug_index = type->debug_index;
  local_10._0_4_ = uVar6 | 0x200000;
  pcVar8 = type_intern(&local_10);
  pcVar3->type = pcVar8;
  return pcVar3;
}

