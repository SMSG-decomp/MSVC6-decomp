uint __cdecl class_check_zero_sized_array_member(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  char cVar2;
  c1_type *t;
  c1_type *pcVar3;
  byte bVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  
  if ((g_compile_flags_cc & 0x100000) != 0) {
    return 0;
  }
  if (((g_class_def_stack[g_class_depth].flags & 8) != 0) &&
     (pcVar8 = g_class_def_stack[g_class_depth].cls, (pcVar8->flags5 & 1) != 0)) {
    diag_error(0xe5,pcVar8->type,pcVar8);
    pcVar1 = &(g_class_def_stack[g_class_depth].cls)->flags5;
    *pcVar1 = *pcVar1 & 0xfe;
  }
  t = sym->type;
  if ((sym->kind & 0x1f) == 4) {
    pcVar5 = ((sym->detail).segment_class)->text;
LAB_10435566:
    if (pcVar5 != (char *)0x0) goto LAB_1043548e;
  }
  else {
    pcVar5 = (char *)type_size(t);
    if (pcVar5 != (char *)0x0) goto LAB_1043548e;
    if (((t->code & 0x8f) == 0x83) && ((t->extra).cls == (c1_symbol *)0x0)) {
      if ((g_ms_extensions == '\0') && ((g_compile_flags_c8 & 0x20000) == 0)) {
        diag_error(0x85,sym);
        return 0;
      }
      diag_warning(2,200);
      sym->flags5 = sym->flags5 | 1;
      pcVar5 = (char *)type_size(t->base);
      goto LAB_10435566;
    }
  }
  cVar2 = (char)t->code;
  pcVar3 = t;
  while (cVar2 < '\0') {
    pcVar3 = pcVar3->base;
    cVar2 = (char)pcVar3->code;
  }
  if ((pcVar3->code & 0x300) == 0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = (pcVar3->extra).cls;
  }
  if ((pcVar8->flags2 & 4) == 0) {
    diag_error(0x4f,sym,t,pcVar8);
    return 0;
  }
LAB_1043548e:
  if (((g_class_def_stack[g_class_depth].flags & 8) != 0) &&
     (g_class_def_stack[g_class_depth].bitfield_type != 0)) {
    class_close_bit_field_unit();
    iVar7 = g_class_depth;
    g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags & 0xdf;
    g_class_def_stack[iVar7].bit_offset = '\0';
  }
  uVar6 = class_member_natural_alignment(t,g_pack_stack->top->packing);
  class_warn_packing_sensitive_alignment(uVar6);
  if ((g_class_def_stack[g_class_depth].flags & 8) == 0) {
    uVar6 = 0;
    if ((char *)g_class_def_stack[g_class_depth].offset < pcVar5) {
      g_class_def_stack[g_class_depth].offset = (int)pcVar5;
    }
  }
  else {
    uVar6 = g_class_def_stack[g_class_depth].offset;
    if ((sym->flags5 & 1) == 0) {
      if ((pcVar5 != (char *)0x0) &&
         (iVar7 = fold_add_overflows(uVar6,(int)uVar6 >> 0x1f,(uint)(pcVar5 + -1),0,1,
                                     CONCAT22((short)((uint)g_class_depth >> 0x10),4)), iVar7 != 0))
      {
        diag_error(0x59,g_class_def_stack[g_class_depth].cls,
                   (g_class_def_stack[g_class_depth].cls)->type);
        return 0;
      }
      g_class_def_stack[g_class_depth].offset =
           (int)(pcVar5 + g_class_def_stack[g_class_depth].offset);
    }
  }
  if (((t->code & 0x200) != 0) && ((sym->kind & 0x1f) != 4)) {
    if ((t->code & 0x300) == 0) {
      pcVar8 = (c1_symbol *)0x0;
    }
    else {
      pcVar8 = (t->extra).cls;
    }
    sym->flags5 = (sym->flags5 ^ pcVar8->flags5) & 1 ^ sym->flags5;
    pcVar1 = &(g_class_def_stack[g_class_depth].cls)->flags5;
    *pcVar1 = *pcVar1 | pcVar8->flags5 & 2;
    if (((t->code & 0x20f) == 0x203) || ((((pcVar8->detail).cls)->layout_flags3b & 1) != 0)) {
      bVar4 = 1;
    }
    else {
      bVar4 = 0;
    }
    pcVar1 = &(((g_class_def_stack[g_class_depth].cls)->detail).cls)->layout_flags3b;
    *pcVar1 = *pcVar1 | bVar4;
  }
  uVar6 = class_member_offset_add(uVar6,0);
  return uVar6;
}

