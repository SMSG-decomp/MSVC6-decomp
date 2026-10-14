void __cdecl
decl_function_type_add_default_arguments
          (c1_symbol *sym,c1_node *new_defaults,c1_function_params *old_params,
          c1_function_params *new_params,c1_node *new_last)

{
  uint uVar1;
  bool bVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_u8 cVar5;
  c1_u8 cVar6;
  c1_u8 cVar7;
  c1_u8 *params;
  c1_node *pcVar8;
  ushort uVar9;
  c1_node *pcVar10;
  uint uVar11;
  c1_type *pcVar12;
  c1_type *pcVar13;
  c1_type local_10;
  c1_function_params *extra_words;
  
  params = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x10;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  bVar2 = false;
  pcVar13 = sym->type;
  uVar9 = pcVar13->code & 0x8f;
  if (((uVar9 == 0x86) || (uVar9 == 0x84)) || (pcVar12 = pcVar13, uVar9 == 0x8e)) {
    bVar2 = true;
    pcVar12 = pcVar13->base;
  }
  extra_words = (pcVar12->extra).params;
  *(c1_type **)params = extra_words->this_type;
  cVar5 = extra_words->flags;
  cVar6 = extra_words->pad06[0];
  cVar7 = extra_words->pad06[1];
  params[4] = extra_words->default_count;
  params[5] = cVar5;
  params[6] = cVar6;
  params[7] = cVar7;
  *(c1_node **)(params + 8) = extra_words->defaults;
  *(c1_type_list **)(params + 0xc) = extra_words->list;
  if (old_params->default_count == '\0') {
    *(c1_node **)(params + 8) = new_params->defaults;
  }
  else {
    g_context_arena_index = 0;
    g_compile_flags_cc = g_compile_flags_cc | 0x10;
    g_expr_arena_index = 0;
    pcVar10 = tree_copy_to_arena(old_params->defaults,0);
    *(c1_node **)(params + 8) = pcVar10;
    pcVar8 = pcVar10->right;
    pcVar4 = pcVar10;
    while (pcVar3 = pcVar8, pcVar3 != (c1_node *)0x0) {
      pcVar4 = pcVar3;
      pcVar8 = pcVar3->right;
    }
    pcVar4->right = new_defaults;
    new_defaults->link = pcVar4;
    pcVar10->link = new_last;
    uVar11 = g_compile_flags_cc & 0xffffffef;
    if (((g_compile_flags_c8 & 0x32000000) == 0) &&
       (((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)) &&
        (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))))) {
      uVar1 = g_compile_flags_cc & 1;
      g_context_arena_index = 5;
      g_expr_arena_index = 5;
      g_compile_flags_cc = uVar11;
      if (uVar1 != 0) {
        g_context_arena_index = 4;
        g_expr_arena_index = 4;
      }
    }
    else {
      g_context_arena_index = 0;
      g_expr_arena_index = 0;
      g_compile_flags_cc = uVar11;
    }
  }
  params[4] = new_params->default_count;
  if (((pcVar12->extra).cls != (c1_symbol *)params) &&
     (local_10.extra.params = type_function_intern((c1_function_params *)params),
     (pcVar12->extra).cls != local_10.extra.cls)) {
    local_10.code = pcVar12->code;
    local_10.flags = pcVar12->flags;
    local_10.base = pcVar12->base;
    local_10.debug_index = pcVar12->debug_index;
    pcVar12 = type_intern(&local_10);
  }
  if (!bVar2) {
    sym->type = pcVar12;
    return;
  }
  if (pcVar13->base != pcVar12) {
    local_10.code = pcVar13->code;
    local_10.flags = pcVar13->flags;
    local_10.extra = pcVar13->extra;
    local_10.debug_index = pcVar13->debug_index;
    local_10.base = pcVar12;
    pcVar13 = type_intern(&local_10);
    sym->type = pcVar13;
    return;
  }
  sym->type = pcVar13;
  return;
}

