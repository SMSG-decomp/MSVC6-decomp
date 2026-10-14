c1xx_class_scope * __thiscall
class_scope_new(c1_scope_stack *stack,int arena,c1_u8 kind,c1_symbol *tag)

{
  c1xx_class_scope *scope;
  c1xx_class_scope *pcVar1;
  c1_u8 *pcVar2;
  void *pvVar3;
  c1_arg_list *args;
  c1_sym_list *params;
  c1xx_block_scope *pcVar4;
  c1_arena *a;
  c1_symbol *tmpl;
  char in_block;
  char prefix;
  int prefix_count;
  
  a = g_arenas + arena;
  scope = (c1xx_class_scope *)a->cur;
  pcVar1 = (c1xx_class_scope *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(scope + 1);
  if (pcVar1 < scope + 1) {
    arena_grow(a);
  }
  if (scope == (c1xx_class_scope *)0x0) {
    scope_push_child(stack,(c1xx_scope *)0x0);
    return (c1xx_class_scope *)0x0;
  }
  scope->outer = (c1xx_scope *)0x0;
  scope->kind = kind;
  scope->parent = (c1xx_scope *)0x0;
  scope->usings = (c1_using_directive *)0x0;
  ((c1_scope_body *)&scope->cls)->cls = tag;
  scope->binding = (c1xx_block_scope *)0x0;
  scope->reached = '\0';
  scope->vtbl = (c1xx_class_scope_vtbl *)&PTR_vtable_true_al_104bcb60;
  if (((tag->kind & 0x1f) == 4) && ((((tag->detail).cls)->flags3e & 1) != 0)) {
    if ((((tag->detail).cls)->flags3f & 0x80) == 0) {
      pvVar3 = symtab_1608_lookup(tag);
    }
    else {
      pvVar3 = tmpl_template_of_instance(tag);
      pvVar3 = tmpl_lookup_parameter_list(pvVar3);
    }
    pcVar2 = g_arenas[3].cur;
    if (pvVar3 == (void *)0x0) {
      pvVar3 = tmpl_template_of_instance(((c1_scope_body *)&scope->cls)->cls);
      tmpl = ((c1_scope_body *)&scope->cls)->cls;
      prefix_count = 0;
      prefix = '\0';
      in_block = '\0';
      args = symtab_15f4_lookup(tmpl);
      params = tmpl_lookup_parameter_list(pvVar3);
      pcVar4 = tmpl_bind_arguments(params,args,tmpl,in_block,prefix,prefix_count);
      scope->binding = pcVar4;
      scope_push_child(stack,(c1xx_scope *)scope);
      return scope;
    }
    g_arenas[3].cur = g_arenas[3].cur + 0x18;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    if (pcVar2 != (c1_u8 *)0x0) {
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      pcVar2[8] = 0xfa;
      pcVar2[0xc] = '\0';
      pcVar2[0xd] = '\0';
      pcVar2[0xe] = '\0';
      pcVar2[0xf] = '\0';
      pcVar2[0x10] = '\0';
      pcVar2[0x11] = '\0';
      pcVar2[0x12] = '\0';
      pcVar2[0x13] = '\0';
      *(void **)(pcVar2 + 0x14) = pvVar3;
      *(undefined ***)pcVar2 = &PTR_block_scope_has_entries_104bcac0;
      scope->binding = (c1xx_block_scope *)pcVar2;
      scope_push_child(stack,(c1xx_scope *)scope);
      return scope;
    }
    scope->binding = (c1xx_block_scope *)0x0;
  }
  scope_push_child(stack,(c1xx_scope *)scope);
  return scope;
}

