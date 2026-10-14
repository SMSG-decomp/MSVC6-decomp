c1_type * __cdecl type_as_member_function(c1_type *type)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 *params;
  c1_type *pcVar4;
  c1_type_extra cVar5;
  c1_type local_20;
  c1_type local_10;
  undefined4 code_flags;
  c1_function_params *extra_words;
  
  params = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x10;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  extra_words = (type->extra).params;
  *(c1_type **)params = extra_words->this_type;
  cVar1 = extra_words->flags;
  cVar2 = extra_words->pad06[0];
  cVar3 = extra_words->pad06[1];
  params[4] = extra_words->default_count;
  params[5] = cVar1;
  params[6] = cVar2;
  params[7] = cVar3;
  *(c1_node **)(params + 8) = extra_words->defaults;
  *(c1_type_list **)(params + 0xc) = extra_words->list;
  pcVar4 = type_this_pointer((c1_symbol *)0x0,0x20,0);
  *(c1_type **)params = pcVar4;
  if ((type->extra).cls != (c1_symbol *)params) {
    cVar5.params = type_function_intern((c1_function_params *)params);
    if ((type->extra).cls != cVar5.cls) {
      local_20.code = type->code;
      local_20.flags = type->flags;
      local_20.base = type->base;
      local_20.debug_index = type->debug_index;
      local_20.extra.params = cVar5.params;
      type = type_intern(&local_20);
    }
  }
  if (type->code != 0x85) {
    code_flags._0_2_ = type->code;
    code_flags._2_2_ = type->flags;
    local_10.extra = type->extra;
    local_10.base = type->base;
    local_10.debug_index = type->debug_index;
    local_10.flags = code_flags._2_2_;
    local_10.code = (c1_u16)CONCAT31((uint3)((uint)code_flags >> 8) & 0xc0,0x85);
    pcVar4 = type_intern(&local_10);
    return pcVar4;
  }
  return type;
}

