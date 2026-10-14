void __thiscall using_list_lookup(c1_using_cell **list,fe_name *name,c1_lookup_result *result)

{
  c1_using_cell *pcVar1;
  c1xx_hash_scope *scope;
  c1_lookup_entry *pcVar2;
  c1_lookup_result *found;
  
  for (pcVar1 = *list; pcVar1 != (c1_using_cell *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->active != 0) &&
       (scope = pcVar1->ns->info->scope, found = (*scope->vtbl->lookup)(scope,name,1),
       found != (c1_lookup_result *)0x0)) {
      pcVar2 = found->tail;
      if (result->head == (c1_lookup_entry *)0x0) {
        result->head = found->head;
      }
      else {
        result->tail->next = found->head;
      }
      result->tail = pcVar2;
    }
  }
  return;
}

