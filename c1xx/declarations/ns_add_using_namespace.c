void __thiscall
ns_add_using_namespace(c1xx_hash_scope *scope,c1_namespace_symbol *ns,c1_namespace_symbol *skip)

{
  c1_using_directive *pcVar1;
  c1_symbol *pcVar2;
  bool bVar3;
  c1_scope_stack *pcVar4;
  c1_u8 *pcVar5;
  c1_using_cell **ppcVar6;
  c1_using_cell *pcVar7;
  int depth;
  c1_u8 implicit;
  
  if (scope == ns->info->scope) {
    diag_warning(4,0x203,ns->name);
    return;
  }
  if (scope->using_list == (c1_using_cell **)0x0) {
    ppcVar6 = arena_alloc(g_arenas,4);
    if (ppcVar6 == (c1_using_cell **)0x0) {
      bVar3 = true;
      scope->using_list = (c1_using_cell **)0x0;
    }
    else {
      pcVar7 = arena_alloc(g_arenas,0xc);
      if (pcVar7 == (c1_using_cell *)0x0) {
        bVar3 = true;
        *ppcVar6 = (c1_using_cell *)0x0;
        scope->using_list = ppcVar6;
      }
      else {
        pcVar7->ns = ns;
        pcVar7->next = (c1_using_cell *)0x0;
        pcVar7->active = 1;
        *ppcVar6 = pcVar7;
        bVar3 = true;
        scope->using_list = ppcVar6;
      }
    }
  }
  else {
    using_list_add(scope->using_list,ns);
    bVar3 = false;
  }
  pcVar4 = g_current_scope;
  ppcVar6 = (c1_using_cell **)g_arenas[0].cur;
  for (pcVar1 = ns->info->scope->usings; g_current_scope = pcVar4,
      g_arenas[0].cur = (c1_u8 *)ppcVar6, pcVar1 != (c1_using_directive *)0x0; pcVar1 = pcVar1->next
      ) {
    if (pcVar1->ns != skip) {
      pcVar2 = pcVar1->name;
      if (((pcVar2->kind & 0x1f) == 0x19) && (((uint)pcVar2->type->base & 0x10000) != 0)) {
        depth = pcVar1->depth;
        implicit = '\x01';
      }
      else {
        depth = pcVar1->depth;
        implicit = '\0';
      }
      ns_using_directive(pcVar2,(fe_name *)0x0,depth,implicit);
    }
    pcVar4 = g_current_scope;
    ppcVar6 = (c1_using_cell **)g_arenas[0].cur;
  }
  if ((scope->kind == '\0') && (scope->outer != (c1xx_scope *)0x0)) {
    pcVar2 = scope->ns;
    if (pcVar4->using_namespaces == (c1_using_cell **)0x0) {
      g_arenas[0].cur = (c1_u8 *)(ppcVar6 + 1);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      pcVar5 = g_arenas[0].cur;
      if (ppcVar6 == (c1_using_cell **)0x0) {
        pcVar4->using_namespaces = (c1_using_cell **)0x0;
      }
      else {
        g_arenas[0].cur = g_arenas[0].cur + 0xc;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar5 == (c1_u8 *)0x0) {
          *ppcVar6 = (c1_using_cell *)0x0;
          pcVar4->using_namespaces = ppcVar6;
        }
        else {
          *(c1_symbol **)pcVar5 = pcVar2;
          pcVar5[4] = '\0';
          pcVar5[5] = '\0';
          pcVar5[6] = '\0';
          pcVar5[7] = '\0';
          pcVar5[8] = '\x01';
          pcVar5[9] = '\0';
          pcVar5[10] = '\0';
          pcVar5[0xb] = '\0';
          *ppcVar6 = (c1_using_cell *)pcVar5;
          pcVar4->using_namespaces = ppcVar6;
        }
      }
    }
    else {
      using_list_add(pcVar4->using_namespaces,(c1_namespace_symbol *)pcVar2);
    }
  }
  if ((scope->buckets == (c1_sym_link **)0x0) && (bVar3)) {
    scope_push_block(g_current_scope,(c1xx_scope *)scope);
  }
  return;
}

