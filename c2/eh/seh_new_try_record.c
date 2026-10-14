c2_seh_try_scope * seh_new_try_record(void)

{
  c2_seh_try_scope *pcVar1;
  c2_seh_try_scope *pcVar2;
  int iVar3;
  c2_seh_try_scope *scope;
  void *pvVar4;
  int32_t iVar5;
  
  scope = arena_alloc(1,0x4c);
  scope->level = g_seh_next_try_level;
  iVar3 = g_seh_except_nesting;
  g_seh_next_try_level = g_seh_next_try_level + 1;
  scope->kind = 0;
  scope->nesting = iVar3;
  pvVar4 = seh_innermost_scope_without_filter();
  if (pvVar4 == (void *)0x0) {
    iVar5 = -1;
  }
  else {
    iVar5 = *(int32_t *)((int)pvVar4 + 0xc);
  }
  scope->enclosing_level = iVar5;
  pvVar4 = seh_current_scope_record_2();
  if (pvVar4 == (void *)0x0) {
    iVar5 = -1;
  }
  else {
    iVar5 = *(int32_t *)((int)pvVar4 + 0xc);
  }
  scope->parent_level = iVar5;
  seh_scope_stack_push(scope);
  pcVar1 = (c2_seh_try_scope *)&g_seh_try_records;
  for (pcVar2 = g_seh_try_records; pcVar2 != (c2_seh_try_scope *)0x0; pcVar2 = pcVar2->next) {
    pcVar1 = pcVar2;
  }
  pcVar1->next = scope;
  return scope;
}

