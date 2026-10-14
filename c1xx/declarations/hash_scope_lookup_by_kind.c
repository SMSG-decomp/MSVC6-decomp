c1_lookup_result * __thiscall
hash_scope_lookup_by_kind(c1xx_hash_scope *scope,fe_name *name,uint flags,byte *found)

{
  c1_symbol *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_scope_stack *pcVar4;
  byte bVar5;
  uint uVar6;
  c1_symbol_vector *pcVar7;
  c1_sym_link *entry;
  c1_u32 *pcVar8;
  c1_lookup_result *result;
  c1_u32 *pcStack_4;
  
  pcVar4 = g_current_scope;
  pcVar8 = (c1_u32 *)0x0;
  pcStack_4 = (c1_u32 *)0x0;
  if (((flags & 0x800) != 0) && (scope->kind == '\0')) {
    if (scope->outer == (c1xx_scope *)0x0) {
      scope_note_visited_namespace(g_current_scope,(int)g_current_scope->global_ns);
    }
    else {
      pcVar1 = scope->ns;
      if (g_current_scope->visited_namespaces == (c1_symbol_vector *)0x0) {
        pcVar7 = (c1_symbol_vector *)symtab_record_new_kind4();
        pcVar4->visited_namespaces = pcVar7;
      }
      pcVar7 = (c1_symbol_vector *)
               vector_find_or_add((short *)pcVar4->visited_namespaces,(int)pcVar1);
      pcVar4->visited_namespaces = pcVar7;
    }
  }
  if (scope->buckets != (c1_sym_link **)0x0) {
    entry = scope->buckets[name->flags & scope->mask & 0xffff];
    *found = 1;
    for (; pcVar8 = (c1_u32 *)0x0, entry != (c1_sym_link *)0x0; entry = entry->next) {
      if (entry->name == name) {
        pcVar8 = &entry[-1].position;
        if (((entry[-1].position & 0x1f) == 0x1a) && (g_current_scope->keep_aliases == '\0')) {
          pcVar1 = ((entry->type).alias)->target;
          bVar5 = pcVar1->kind & 0x1f;
          if ((((bVar5 == 0x10) || (((bVar5 == 7 || (bVar5 == 6)) || (bVar5 == 0x11)))) ||
              ((bVar5 == 8 || (bVar5 == 0x1b)))) ||
             ((bVar5 == 0x1a &&
              (((bVar5 = **(byte **)pcVar1->type & 0x1f, bVar5 == 0x10 || (bVar5 == 7)) ||
               ((bVar5 == 6 || (((bVar5 == 0x11 || (bVar5 == 8)) || (bVar5 == 0x1b)))))))))) {
            pcStack_4 = pcVar8;
          }
          do {
            pcVar8 = *(c1_u32 **)pcVar8[5];
          } while ((*pcVar8 & 0x1f) == 0x1a);
          entry = (c1_sym_link *)(pcVar8 + 2);
        }
        uVar6 = sym_kind_in_lookup_mask((c1_u8 *)entry,flags);
        if ((char)uVar6 != '\0') {
          if ((entry[-1].position & 0x200000) != 0) {
            entry = (c1_sym_link *)hash_scope_entry_pick((int)entry);
          }
          pcVar8 = &entry[-1].position;
          break;
        }
      }
    }
  }
  result = (c1_lookup_result *)g_arenas[5].cur;
  pcVar3 = g_arenas[5].cur;
  if ((scope->using_list == (c1_using_cell **)0x0) || ((flags & 0x200) != 0)) {
    if (pcVar8 != (c1_u32 *)0x0) {
      if (pcStack_4 == (c1_u32 *)0x0) {
        g_arenas[5].cur = g_arenas[5].cur + 8;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        pcVar2 = g_arenas[5].cur;
        if (result != (c1_lookup_result *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 0xc;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar2 != (c1_u8 *)0x0) {
            *(c1_u32 **)pcVar2 = pcVar8;
            *(c1xx_hash_scope **)(pcVar2 + 4) = scope;
            pcVar2[8] = '\0';
            pcVar2[9] = '\0';
            pcVar2[10] = '\0';
            pcVar2[0xb] = '\0';
            *(c1_u8 **)result = pcVar2;
            *(c1_u8 **)((int)result + 4) = pcVar2;
            return result;
          }
LAB_104929b5:
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
          pcVar3[4] = '\0';
          pcVar3[5] = '\0';
          pcVar3[6] = '\0';
          pcVar3[7] = '\0';
          return result;
        }
      }
      else {
        g_arenas[5].cur = g_arenas[5].cur + 8;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        pcVar2 = g_arenas[5].cur;
        if (result != (c1_lookup_result *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 0xc;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar2 != (c1_u8 *)0x0) {
            *(c1xx_hash_scope **)(pcVar2 + 4) = scope;
            *(c1_u32 **)pcVar2 = pcStack_4;
            pcVar2[8] = '\0';
            pcVar2[9] = '\0';
            pcVar2[10] = '\0';
            pcVar2[0xb] = '\0';
            *(c1_u8 **)result = pcVar2;
            *(c1_u8 **)((int)result + 4) = pcVar2;
            return result;
          }
          goto LAB_104929b5;
        }
      }
    }
    return (c1_lookup_result *)0x0;
  }
  if (pcVar8 == (c1_u32 *)0x0) {
    g_arenas[5].cur = g_arenas[5].cur + 8;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (result != (c1_lookup_result *)0x0) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3[4] = '\0';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      goto LAB_10492850;
    }
LAB_10492921:
    result = (c1_lookup_result *)0x0;
  }
  else {
    if (pcStack_4 == (c1_u32 *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 8;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      pcVar2 = g_arenas[5].cur;
      if (result == (c1_lookup_result *)0x0) goto LAB_10492921;
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar2 != (c1_u8 *)0x0) {
        *(c1_u32 **)pcVar2 = pcVar8;
        *(c1xx_hash_scope **)(pcVar2 + 4) = scope;
        pcVar2[8] = '\0';
        pcVar2[9] = '\0';
        pcVar2[10] = '\0';
        pcVar2[0xb] = '\0';
        *(c1_u8 **)result = pcVar2;
        *(c1_u8 **)((int)result + 4) = pcVar2;
        goto LAB_10492850;
      }
    }
    else {
      g_arenas[5].cur = g_arenas[5].cur + 8;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      pcVar2 = g_arenas[5].cur;
      if (result == (c1_lookup_result *)0x0) goto LAB_10492921;
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar2 != (c1_u8 *)0x0) {
        *(c1xx_hash_scope **)(pcVar2 + 4) = scope;
        *(c1_u32 **)pcVar2 = pcStack_4;
        pcVar2[8] = '\0';
        pcVar2[9] = '\0';
        pcVar2[10] = '\0';
        pcVar2[0xb] = '\0';
        *(c1_u8 **)result = pcVar2;
        *(c1_u8 **)((int)result + 4) = pcVar2;
        goto LAB_10492850;
      }
    }
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3[4] = '\0';
    pcVar3[5] = '\0';
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
  }
LAB_10492850:
  using_list_lookup_by_kind(scope->using_list,name,flags | 0x200,found,result);
  return (c1_lookup_result *)(-(uint)(result->head != (c1_lookup_entry *)0x0) & (uint)result);
}

