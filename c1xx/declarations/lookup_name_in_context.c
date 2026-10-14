c1_lookup_entry * __thiscall lookup_name_in_context(c1_scope_stack *ctx,void *name,uint mask)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_u8 *pcVar3;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar4;
  c1_symbol *pcVar5;
  byte bVar6;
  short n;
  uint flags;
  byte found;
  uint scope_index;
  
  if ((ctx->qualified == '\0') || (((byte)g_compile_flags_c8 & 8) != 0)) {
    bVar1 = ctx->depth;
    scope_index = CONCAT31(scope_index._1_3_,bVar1);
    found = 1;
    result = (*ctx->contexts[bVar1]->vtbl->lookup_by_kind)(ctx->contexts[bVar1],name,mask,&found);
    while( true ) {
      if (result != (c1_lookup_result *)0x0) {
        pcVar4 = lookup_check_ambiguous_symbol(result,'\x01');
        return pcVar4;
      }
      bVar6 = bVar1 - 1;
      scope_index._1_3_ = (undefined3)(scope_index >> 8);
      scope_index = CONCAT31(scope_index._1_3_,bVar6);
      if (bVar1 == 0) break;
      result = (*ctx->contexts[bVar6]->vtbl->lookup_by_kind)(ctx->contexts[bVar6],name,mask,&found);
      bVar1 = bVar6;
    }
  }
  else if (ctx->qual_class == (c1_symbol *)0x0) {
    if (ctx->reported == '\0') {
      if (ctx->access_op == 'S') {
        n = 0xe3;
      }
      else {
        n = 0xe4;
      }
      diag_error(n,name);
      ctx->reported = '\x01';
      pcVar4 = (c1_lookup_entry *)lookup_name_in_context_return_zero();
      return pcVar4;
    }
  }
  else {
    if (mask == 0x32) {
      cVar2 = ctx->reported;
      flags = 0x32;
    }
    else {
      cVar2 = ctx->reported;
      flags = mask | 0x40;
    }
    pcVar5 = class_lookup_member_set
                       (ctx,ctx->qual_class,name,flags,(-(uint)(cVar2 != '\0') & 0xfffffe7f) + 0x181
                       );
    pcVar3 = g_arenas[5].cur;
    if (pcVar5 == (c1_symbol *)0x0) {
      if (ctx->reported == '\0') {
        diag_error(0x27,0x49,name,ctx->qual_class);
        return (c1_lookup_entry *)0x0;
      }
    }
    else {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar3 != (c1_u8 *)0x0) {
        pcVar5 = expr_resolve_overload_set_member(pcVar5,(c1_symbol *)0x0);
        *(c1_symbol **)pcVar3 = pcVar5;
        pcVar3[4] = '\0';
        pcVar3[5] = '\0';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        pcVar3[8] = '\0';
        pcVar3[9] = '\0';
        pcVar3[10] = '\0';
        pcVar3[0xb] = '\0';
        return (c1_lookup_entry *)pcVar3;
      }
    }
  }
  return (c1_lookup_entry *)0x0;
}

