c1_symbol * __cdecl eh_catchable_type_symbol(c1_catchable_type *ct,int *pmd,c1_symbol *copy_fn)

{
  c1_u8 *item;
  int iVar1;
  char *pcVar2;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_symbol *pcVar4;
  c1_u8 cVar5;
  char *pcVar6;
  c1_u8 local_811;
  int local_810;
  c1_type *pcStack_80c;
  c1_symbol *local_808;
  char local_804 [2048];
  undefined1 local_4 [4];
  
  local_808 = rtti_type_descriptor_symbol((int)ct->type_unref);
  iVar1 = format_snprintf(local_804,"_CT%s",0x800,local_808->name->text);
  pcVar6 = local_804 + iVar1;
  if ((((byte)ct->flags & 0xd) == 8) &&
     ((ct->copy_ctor == (c1_symbol *)0x0 || (ct->dtor == (c1_symbol *)0x0)))) {
    *pcVar6 = 'R';
    pcVar6 = local_804 + iVar1 + 1;
    local_811 = '\x01';
    cVar5 = '\0';
    *pcVar6 = '\0';
    local_810 = 0;
  }
  else {
    local_811 = '\0';
    local_810 = type_size(ct->type);
    if ((ct->type->code & 0x200) == 0) {
      cVar5 = '\x01';
    }
    else {
      cVar5 = '\0';
      if (copy_fn != (c1_symbol *)0x0) {
        pcVar2 = decorate_name(copy_fn,ct->cls);
        iVar1 = format_snprintf(pcVar6,"%s",(int)(local_4 + -(int)pcVar6),pcVar2);
        pcVar6 = pcVar6 + iVar1;
      }
    }
    iVar1 = format_snprintf(pcVar6,"%u",(int)(local_4 + -(int)pcVar6),local_810);
    pcVar6 = pcVar6 + iVar1;
    if (cVar5 != '\0') goto LAB_104aa60d;
  }
  if (pmd != (int *)0x0) {
    if (pmd[1] == -1) {
      format_snprintf(pcVar6,"%d",(int)(local_4 + -(int)pcVar6),*pmd);
    }
    else {
      format_snprintf(pcVar6,"%d%d%d",(int)(local_4 + -(int)pcVar6),*pmd,pmd[1],pmd[2]);
    }
  }
LAB_104aa60d:
  name = name_intern(local_804);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar3 != (c1_lookup_entry *)0x0) {
      return pcVar3->sym;
    }
  }
  pcStack_80c = (c1_type *)0x0;
  pcVar4 = eh_new_compiler_data_object(name,&pcStack_80c,"_CatchableType",0);
  item = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x18;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  item[5] = cVar5;
  *(c1_symbol **)item = pcVar4;
  item[4] = local_811;
  if (ct->cls == (c1_symbol *)0x0) {
    item[6] = '\0';
  }
  else {
    item[6] = ((ct->cls->detail).cls)->layout_flags3b >> 4 & 1;
  }
  *(c1_symbol **)(item + 8) = local_808;
  *(int **)(item + 0xc) = pmd;
  *(int *)(item + 0x10) = local_810;
  *(c1_symbol **)(item + 0x14) = copy_fn;
  if (PTR_104d2cac == (c1_vector *)0x0) {
    PTR_104d2cac = vector_new(0,4);
  }
  vector_push(PTR_104d2cac,item);
  return pcVar4;
}

