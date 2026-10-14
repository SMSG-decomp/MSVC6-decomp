c1_symbol * __cdecl eh_throw_info_symbol(c1_type *type,c1_vector **catchables)

{
  c1_u8 *item;
  c1_vector *catchables_00;
  int iVar1;
  int iVar2;
  char *out;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  c1_catch_handler *pcVar6;
  c1_u8 *pcVar7;
  c1_type *pcStack_1818;
  c1_catch_handler local_1814 [171];
  undefined4 uStack_4;
  
  uStack_4 = 0x104ab038;
  eh_exception_type_init(local_1814,type);
  catchables_00 = eh_collect_catchable_types(&(local_1814[0].match_type)->code,0);
  *catchables = catchables_00;
  iVar1 = eh_count_usable_catchable_types(catchables_00);
  if (iVar1 == 0) {
    diag_error(700,type);
    vector_for_each(*catchables,eh_warn_throw_type_access);
    return (c1_symbol *)0x0;
  }
  iVar2 = format_snprintf((char *)&local_1814[0].catchable,"_TI%d",0x1800,iVar1);
  out = eh_append_cv_letters(local_1814,(char *)((int)&local_1814[0].catchable + iVar2));
  decorate_name_3(out,(char *)&local_1814[0].catchable,local_1814[0].object_type,'\0');
  name = name_intern((char *)&local_1814[0].catchable);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar3 != (c1_lookup_entry *)0x0) {
      return pcVar3->sym;
    }
  }
  pcStack_1818 = (c1_type *)0x0;
  pcVar4 = eh_new_compiler_data_object(name,&pcStack_1818,"_ThrowInfo",0);
  item = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x20;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  *(c1_symbol **)item = pcVar4;
  pcVar5 = eh_catchable_type_array_symbol(local_1814[0].match_type,*catchables,iVar1);
  *(c1_symbol **)(item + 8) = pcVar5;
  pcVar6 = local_1814;
  pcVar7 = item + 0xc;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(c1_type **)pcVar7 = pcVar6->type;
    pcVar6 = (c1_catch_handler *)&pcVar6->match_type;
    pcVar7 = pcVar7 + 4;
  }
  iVar1 = *(int *)((int)*(*catchables)->data + 0x18);
  if ((iVar1 == 0) || ((*(byte *)(*(int *)(iVar1 + 0x24) + 0x41) & 0x10) != 0)) {
    item[4] = '\0';
    item[5] = '\0';
    item[6] = '\0';
    item[7] = '\0';
  }
  else {
    *(undefined4 *)(item + 4) = *(undefined4 *)((int)*(*catchables)->data + 0x14);
  }
  if (PTR_104d2cb4 == (c1_vector *)0x0) {
    PTR_104d2cb4 = vector_new(0,4);
  }
  vector_push(PTR_104d2cb4,item);
  return pcVar4;
}

