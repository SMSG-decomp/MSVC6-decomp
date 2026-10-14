c1_lookup_result * __thiscall hash_scope_lookup(c1xx_hash_scope *scope,fe_name *name,int mode)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_symbol *pcVar3;
  c1_lookup_result *result;
  
  if (scope->buckets == (c1_sym_link **)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = scope_lookup_skip_type_aliases(scope->buckets[name->flags & scope->mask & 0xffff],name)
    ;
    pcVar2 = g_arenas[5].cur;
    if ((pcVar3 != (c1_symbol *)0x0) &&
       ((scope->using_list == (c1_using_cell **)0x0 || (mode != 0)))) {
      g_arenas[5].cur = g_arenas[5].cur + 8;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      pcVar1 = g_arenas[5].cur;
      if (pcVar2 == (c1_u8 *)0x0) {
        return (c1_lookup_result *)0x0;
      }
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 != (c1_u8 *)0x0) {
        *(c1_symbol **)pcVar1 = pcVar3;
        *(c1xx_hash_scope **)(pcVar1 + 4) = scope;
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        *(c1_u8 **)pcVar2 = pcVar1;
        *(c1_u8 **)(pcVar2 + 4) = pcVar1;
        return (c1_lookup_result *)pcVar2;
      }
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      return (c1_lookup_result *)pcVar2;
    }
  }
  result = (c1_lookup_result *)g_arenas[5].cur;
  if (scope->using_list == (c1_using_cell **)0x0) {
    return (c1_lookup_result *)0x0;
  }
  pcVar2 = g_arenas[5].cur;
  if (mode == 0) {
    if (pcVar3 == (c1_symbol *)0x0) goto LAB_10492626;
    g_arenas[5].cur = g_arenas[5].cur + 8;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    pcVar1 = g_arenas[5].cur;
    if (result != (c1_lookup_result *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 == (c1_u8 *)0x0) {
        pcVar2[0] = '\0';
        pcVar2[1] = '\0';
        pcVar2[2] = '\0';
        pcVar2[3] = '\0';
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
      }
      else {
        *(c1_symbol **)pcVar1 = pcVar3;
        *(c1xx_hash_scope **)(pcVar1 + 4) = scope;
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        *(c1_u8 **)result = pcVar1;
        *(c1_u8 **)((int)result + 4) = pcVar1;
      }
      goto LAB_1049265e;
    }
  }
  else {
    if (mode != 2) {
      return (c1_lookup_result *)0x0;
    }
    if (pcVar3 != (c1_symbol *)0x0) {
      return (c1_lookup_result *)0x0;
    }
LAB_10492626:
    g_arenas[5].cur = g_arenas[5].cur + 8;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (result != (c1_lookup_result *)0x0) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      goto LAB_1049265e;
    }
  }
  result = (c1_lookup_result *)0x0;
LAB_1049265e:
  using_list_lookup(scope->using_list,name,result);
  if (result->head == (c1_lookup_entry *)0x0) {
    return (c1_lookup_result *)0x0;
  }
  return result;
}

