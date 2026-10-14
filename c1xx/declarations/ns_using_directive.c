void __cdecl ns_using_directive(c1_symbol *target,fe_name *name,int depth,c1_u8 implicit)

{
  byte bVar1;
  c1_symbol *ns;
  c1xx_scope *pcVar2;
  c1_using_directive *pcVar3;
  c1_lookup_entry *pcVar4;
  c1_lookup_entry *pcVar5;
  c1_namespace_symbol *skip_ns;
  c1_namespace_symbol *cur_ns;
  c1_namespace_symbol *enclosing_ns;
  c1_using_directive *pcVar6;
  c1xx_scope *scope;
  c1_keyed_cell *cell;
  
  if (implicit == '\0') {
    if ((target == (c1_symbol *)0x0) || ((target->kind & 0x1f) != 0x12)) {
      if (name == (fe_name *)0x0) {
        name = target->name;
      }
      pcVar4 = lookup_name_in_context(g_current_scope,name,0x100);
      if (pcVar4 == (c1_lookup_entry *)0x0) {
        diag_error(0x367,name);
        return;
      }
      _implicit = pcVar4->sym;
      if (target == (c1_symbol *)0x0) {
        target = _implicit;
      }
      if (_implicit->scope_index != 0) {
        enclosing_ns = (c1_namespace_symbol *)g_scope_vector->entries[(short)_implicit->scope_index]
        ;
        pcVar4 = lookup_namespace_in_enclosing_scopes(g_current_scope,enclosing_ns);
        if (pcVar4 == (c1_lookup_entry *)0x0) {
          do {
            enclosing_ns = (c1_namespace_symbol *)
                           g_scope_vector->entries[(short)enclosing_ns->scope_index];
            if ((c1_symbol *)enclosing_ns == (c1_symbol *)0x0) {
              if (pcVar4 == (c1_lookup_entry *)0x0) {
                diag_fatal(1,".\\nspace.cpp",0x299);
              }
              goto LAB_104acecd;
            }
            pcVar5 = lookup_namespace_in_enclosing_scopes(g_current_scope,enclosing_ns);
            pcVar4 = (c1_lookup_entry *)0x0;
          } while (pcVar5 == (c1_lookup_entry *)0x0);
          scope = pcVar5->scope;
        }
        else {
LAB_104acecd:
          scope = pcVar4->scope;
        }
        goto LAB_104acd72;
      }
    }
    else {
      if (g_current_scope->current->kind == '\0') {
        target = sym_new_scoped_copy(target,0);
      }
      cell = *(c1_keyed_cell **)target->type;
      ns = cell->sym;
      _implicit = cell->sym;
      bVar1 = ns->kind;
      while( true ) {
        if ((bVar1 & 0x1f) != 0x19) {
          diag_error(0x363,target);
          return;
        }
        pcVar4 = lookup_namespace_in_enclosing_scopes(g_current_scope,(c1_namespace_symbol *)ns);
        if ((pcVar4 != (c1_lookup_entry *)0x0) || (cell = cell->key, cell == (c1_keyed_cell *)0x0))
        break;
        ns = cell->sym;
        bVar1 = ns->kind;
      }
    }
    scope = pcVar4->scope;
  }
  else {
    _implicit = target;
    scope = g_current_scope->current;
  }
LAB_104acd72:
  if ((_implicit->kind & 0x1f) == 0x19) {
    skip_ns = (c1_namespace_symbol *)0x0;
    if ((g_current_scope->current->kind == '\0') &&
       (g_current_scope->current != g_current_scope->global_scope)) {
      skip_ns = (c1_namespace_symbol *)scope_current_namespace(g_current_scope);
    }
    ns_add_using_namespace((c1xx_hash_scope *)scope,(c1_namespace_symbol *)_implicit,skip_ns);
    pcVar6 = (c1_using_directive *)g_arenas[0].cur;
    pcVar2 = g_current_scope->current;
    if (pcVar2 != g_current_scope->global_scope) {
      g_arenas[0].cur = g_arenas[0].cur + 0x14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar6 == (c1_using_directive *)0x0) {
        pcVar6 = (c1_using_directive *)0x0;
      }
      else {
        pcVar3 = pcVar2->usings;
        pcVar6->name = target;
        *(c1_symbol **)((int)pcVar6 + 4) = _implicit;
        *(c1xx_scope **)((int)pcVar6 + 8) = scope;
        *(int *)((int)pcVar6 + 0xc) = depth + 1;
        *(c1_using_directive **)((int)pcVar6 + 0x10) = pcVar3;
      }
      pcVar2->usings = pcVar6;
    }
    if (((g_current_scope->current->kind == '\0') &&
        (g_current_scope->current != g_current_scope->global_scope)) &&
       (cur_ns = (c1_namespace_symbol *)scope_current_namespace(g_current_scope),
       (cur_ns->info->flags & 2) != 0)) {
      ns_propagate_using_directive(g_current_scope,cur_ns,(c1_namespace_symbol *)_implicit,cur_ns);
    }
    return;
  }
  diag_error(0x367,_implicit->name);
  return;
}

