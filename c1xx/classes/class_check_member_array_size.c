uint __cdecl class_check_member_array_size(c1_type *t)

{
  char cVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1_type *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = type_size(t);
  pcVar3 = g_class_def_stack[g_class_depth].cls;
  if ((pcVar3->flags5 & 1) != 0) {
    diag_error(0xe5,pcVar3->type,pcVar3);
    (g_class_def_stack[g_class_depth].cls)->flags5 =
         (g_class_def_stack[g_class_depth].cls)->flags5 & 0xfe;
  }
  if (g_class_def_stack[g_class_depth].bitfield_type != 0) {
    class_close_bit_field_unit();
    iVar5 = g_class_depth;
    g_class_def_stack[g_class_depth].bit_offset = '\0';
    g_class_def_stack[iVar5].flags = g_class_def_stack[iVar5].flags & 0xdf;
  }
  cVar2 = (char)t->code;
  pcVar4 = t;
  cVar1 = cVar2;
  while (cVar1 < '\0') {
    pcVar4 = pcVar4->base;
    cVar1 = (char)pcVar4->code;
  }
  uVar7 = g_pack_stack->top->packing;
  if ((uint)(int)(char)(&g_type_rank_table)[(byte)pcVar4->code & 0xf] <= uVar7) {
    while (cVar2 < '\0') {
      t = t->base;
      cVar2 = (char)t->code;
    }
    uVar7 = (uint)(char)(&g_type_rank_table)[(byte)t->code & 0xf];
  }
  class_warn_packing_sensitive_alignment(uVar7);
  iVar5 = g_class_depth;
  uVar7 = g_class_def_stack[g_class_depth].offset;
  g_class_def_stack[g_class_depth].offset = uVar7 + iVar6;
  if (uVar7 <= uVar7 + iVar6) {
    uVar7 = class_member_offset_add(uVar7,0);
    return uVar7;
  }
  diag_error(0x59,g_class_def_stack[iVar5].cls,(g_class_def_stack[iVar5].cls)->type);
  return 0;
}

