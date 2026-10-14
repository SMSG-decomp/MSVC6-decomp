void __thiscall
using_list_lookup_by_kind
          (c1_using_cell **list,fe_name *name,uint mask,c1_u8 *found,c1_lookup_result *result)

{
  c1_using_cell *pcVar1;
  c1xx_hash_scope *scope;
  c1_lookup_entry *pcVar2;
  c1_lookup_result *pcVar3;
  
  for (pcVar1 = *list; pcVar1 != (c1_using_cell *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->active != 0) &&
       (scope = pcVar1->ns->info->scope,
       pcVar3 = (*scope->vtbl->lookup_by_kind)(scope,name,mask,found),
       pcVar3 != (c1_lookup_result *)0x0)) {
      pcVar2 = pcVar3->tail;
      if (result->head == (c1_lookup_entry *)0x0) {
        result->head = pcVar3->head;
      }
      else {
        result->tail->next = pcVar3->head;
      }
      result->tail = pcVar2;
    }
  }
  return;
}

