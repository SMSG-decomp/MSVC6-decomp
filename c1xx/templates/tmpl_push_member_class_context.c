void __cdecl tmpl_push_member_class_context(c1_symbol *cls)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  byte bVar4;
  int iVar5;
  
  if (-1 < g_class_depth) {
    diag_fatal(1,"..\\Cxx\\dymto.c",0x337);
  }
  if (cls->scope_index != 0) {
    scope_enter_symbol_scope(g_scope_vector->entries[(short)cls->scope_index]);
  }
  lookup_overload_member(g_current_scope,cls,0xff);
  iVar5 = g_class_depth + 1;
  pcVar2 = cls->type;
  cVar1 = (char)pcVar2->code;
  pcVar3 = pcVar2;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  if ((pcVar3->code & 0x20f) != 0x201) {
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    if ((pcVar2->code & 0x20f) != 0x202) {
      bVar4 = g_class_def_stack[iVar5].flags & 0xf7;
      goto LAB_104a6219;
    }
  }
  bVar4 = g_class_def_stack[iVar5].flags | 8;
LAB_104a6219:
  g_class_depth = iVar5;
  g_class_def_stack[iVar5].flags = bVar4;
  g_class_def_stack[iVar5].cls = cls;
  g_class_def_stack[iVar5].unk04 = 0;
  g_class_def_stack[iVar5].offset = 0;
  g_class_def_stack[iVar5].bit_offset = '\0';
  g_class_def_stack[iVar5].flags = g_class_def_stack[iVar5].flags & 0xdf;
  g_class_def_stack[iVar5].bitfield_type = 0;
  g_class_def_stack[iVar5].type = cls->type;
  g_class_def_stack[iVar5].alignment = 1;
  return;
}

