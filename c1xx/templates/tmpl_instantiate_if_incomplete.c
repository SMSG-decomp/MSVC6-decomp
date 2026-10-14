void __fastcall tmpl_instantiate_if_incomplete(c1_symbol *cls)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  c1_class_record *pcVar4;
  c1_symbol *tmpl;
  void *pvVar5;
  
  if ((cls->flags2 & 4) != 0) {
    return;
  }
  bVar1 = ((cls->detail).cls)->flags3e;
  if (((bVar1 & 1) != 0) && (bVar2 = ((cls->detail).cls)->flags3f, (bVar2 & 1) == 0)) {
    if ((bVar2 & 0x80) != 0) {
      pvVar5 = tmpl_template_of_instance(cls);
      iVar3 = *(int *)((int)pvVar5 + 0x24);
      pcVar4 = (cls->detail).cls;
      pcVar4->member_count = *(c1_u32 *)(iVar3 + 0x20);
      pcVar4->sorted_members = *(void ***)(iVar3 + 0x24);
      cls->flags2 = cls->flags2 | 4;
      return;
    }
    if ((((bVar1 & 4) == 0) &&
        (((g_class_depth < 0 || ((g_class_def_stack[g_class_depth].cls)->name != cls->name)) &&
         ((cls->flags3 & 4) == 0)))) &&
       (((g_compile_flags_cc & 0x200000) == 0 && ((g_compile_flags_cc & 0x20) == 0)))) {
      tmpl = tmpl_template_of_instance(cls);
      if ((((tmpl->detail).cls)->flags3e & 8) != 0) {
        tmpl_instantiate(tmpl,cls);
      }
    }
  }
  return;
}

