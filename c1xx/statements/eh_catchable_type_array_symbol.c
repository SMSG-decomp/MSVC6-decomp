c1_symbol * __cdecl eh_catchable_type_array_symbol(c1_type *type,c1_vector *catchables,int count)

{
  c1_catchable_type *ct;
  bool bVar1;
  c1_u8 *item;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  c1_symbol *pcVar5;
  int *pmd;
  short sVar6;
  c1_vector *v;
  c1_type *pcStack_24;
  char local_20 [32];
  
  sVar6 = 0;
  v = (c1_vector *)0x0;
  format_snprintf(local_20,"_CTA%d",0x20,count);
  name = eh_intern_prefixed_type_name(type,local_20);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar2 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar2 != (c1_lookup_entry *)0x0) {
      return pcVar2->sym;
    }
  }
  pcStack_24 = (c1_type *)0x0;
  bVar1 = true;
  pcVar3 = eh_new_compiler_data_object(name,&pcStack_24,"_CatchableTypeArray",0);
  while (item = g_arenas[4].cur, catchables != (c1_vector *)0x0) {
    iVar4 = (int)sVar6;
    if ((int)(uint)catchables->count <= iVar4) break;
    sVar6 = sVar6 + 1;
    ct = catchables->data[iVar4];
    if ((ct->flags & 20000) == 0) {
      pcVar5 = class_copy_ctor_closure_of(ct->copy_ctor);
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = ct->copy_ctor;
      }
      pmd = (int *)rtti_base_displacement_pmd((int *)ct);
      pcVar5 = eh_catchable_type_symbol(ct,pmd,pcVar5);
      if (v == (c1_vector *)0x0) {
        v = vector_new(0,4);
      }
      vector_push(v,pcVar5);
    }
    else if (g_warning_state->level == 4) {
      if (bVar1) {
        bVar1 = false;
        diag_warning(4,0x2a1,type);
      }
      eh_warn_throw_type_access(ct);
    }
  }
  g_arenas[4].cur = g_arenas[4].cur + 0xc;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  *(c1_symbol **)item = pcVar3;
  *(c1_vector **)(item + 8) = v;
  *(int *)(item + 4) = count;
  if (PTR_104d2cb0 == (c1_vector *)0x0) {
    PTR_104d2cb0 = vector_new(0,4);
  }
  vector_push(PTR_104d2cb0,item);
  return pcVar3;
}

