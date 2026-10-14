c1_type * __cdecl type_function_map_parameters(c1_type *type,void *callback)

{
  bool bVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 *pcVar5;
  ushort uVar6;
  c1_symbol *params;
  c1_type *pcVar7;
  c1_type cStack_10;
  c1_function_params *src;
  
  pcVar5 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x10;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  bVar1 = false;
  uVar6 = type->code & 0x8f;
  if (((uVar6 == 0x86) || (uVar6 == 0x84)) || (pcVar7 = type, uVar6 == 0x8e)) {
    bVar1 = true;
    pcVar7 = (c1_type *)(-(uint)((type->base->code & 0x80) != 0) & (uint)type->base);
  }
  src = (pcVar7->extra).params;
  *(c1_type **)pcVar5 = src->this_type;
  cVar2 = src->flags;
  cVar3 = src->pad06[0];
  cVar4 = src->pad06[1];
  pcVar5[4] = src->default_count;
  pcVar5[5] = cVar2;
  pcVar5[6] = cVar3;
  pcVar5[7] = cVar4;
  *(c1_node **)(pcVar5 + 8) = src->defaults;
  *(c1_type_list **)(pcVar5 + 0xc) = src->list;
  params = (c1_symbol *)(*callback)(pcVar5);
  if (((pcVar7->extra).cls != params) &&
     (cStack_10.extra.params = type_function_intern((c1_function_params *)params),
     (pcVar7->extra).cls != cStack_10.extra.cls)) {
    cStack_10.code = pcVar7->code;
    cStack_10.flags = pcVar7->flags;
    cStack_10.base = pcVar7->base;
    cStack_10.debug_index = pcVar7->debug_index;
    pcVar7 = type_intern(&cStack_10);
  }
  if (bVar1) {
    if (type->base != pcVar7) {
      cStack_10.code = type->code;
      cStack_10.flags = type->flags;
      cStack_10.extra = type->extra;
      cStack_10.debug_index = type->debug_index;
      cStack_10.base = pcVar7;
      pcVar7 = type_intern(&cStack_10);
      return pcVar7;
    }
    return type;
  }
  return pcVar7;
}

