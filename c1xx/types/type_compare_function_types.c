char __cdecl type_compare_function_types(c1_function_params *fn1,c1_function_params *fn2,uint mode)

{
  c1_type_list *pcVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  c1_type *pcVar8;
  void *pvVar9;
  void *pvVar10;
  int iVar11;
  c1_type **ppcVar12;
  c1_type *pcVar13;
  c1_type *pcVar14;
  c1_symbol *key;
  
  pcVar1 = fn2->list;
  iVar2 = fn1->list->count;
  if (iVar2 != pcVar1->count) {
    return '\0';
  }
  iVar11 = 0;
  ppcVar12 = fn1->list->types;
  if (0 < iVar2) {
    iVar3 = 8 - (int)ppcVar12;
    do {
      cVar4 = type_compare(*ppcVar12,*(c1_type **)((int)pcVar1 + iVar3 + (int)ppcVar12),mode);
      if (cVar4 == '\0') {
        return '\0';
      }
      iVar11 = iVar11 + 1;
      ppcVar12 = ppcVar12 + 1;
    } while (iVar11 < iVar2);
  }
  if ((fn1->flags & 1) == 0) {
    pcVar13 = fn1->this_type;
  }
  else {
    pcVar13 = (c1_type *)0x0;
  }
  if ((fn2->flags & 1) == 0) {
    pcVar14 = fn2->this_type;
  }
  else {
    pcVar14 = (c1_type *)0x0;
  }
  if (((pcVar13 != pcVar14) && (pcVar13 != (c1_type *)0x0)) && (pcVar14 != (c1_type *)0x0)) {
    pcVar7 = pcVar13;
    if ((pcVar13->code & 0x8f) == 0x83) {
      pcVar7 = type_skip_arrays(pcVar13->base);
    }
    pcVar8 = pcVar14;
    if ((pcVar14->code & 0x8f) == 0x83) {
      pcVar8 = type_skip_arrays(pcVar14->base);
    }
    if ((((byte)pcVar8->flags ^ (byte)pcVar7->flags) & 0x1f) != 0) {
      return '\0';
    }
    pcVar13 = pcVar13->base;
    pcVar14 = pcVar14->base;
    pcVar7 = pcVar13;
    if ((pcVar13->code & 0x8f) == 0x83) {
      pcVar7 = type_skip_arrays(pcVar13->base);
    }
    pcVar8 = pcVar14;
    if ((pcVar14->code & 0x8f) == 0x83) {
      pcVar8 = type_skip_arrays(pcVar14->base);
    }
    if (((pcVar8->flags ^ pcVar7->flags) & 0x3e0) != 0) {
      return '\0';
    }
    if ((pcVar13->code & 0x200) == 0) {
      pcVar6 = (c1_symbol *)0x0;
    }
    else {
      pcVar6 = (pcVar13->extra).cls;
    }
    if ((pcVar14->code & 0x200) == 0) {
      key = (c1_symbol *)0x0;
    }
    else {
      key = (pcVar14->extra).cls;
    }
    if (pcVar6 != key) {
      if ((((mode & 4) != 0) && ((((pcVar6->detail).cls)->flags3e & 1) != 0)) &&
         (((((key->detail).cls)->flags3e & 1) != 0 &&
          (((((pcVar6->detail).cls)->flags3f & 0x80) != 0 ||
           ((((key->detail).cls)->flags3f & 0x80) != 0)))))) {
        pvVar9 = tmpl_template_of_instance(key);
        pvVar10 = tmpl_template_of_instance(pcVar6);
        if (pvVar10 == pvVar9) {
          return '\x01';
        }
      }
      pcVar5 = class_lookup_qualified_member(g_current_scope,pcVar6,key,0);
      if ((pcVar5 == (c1_symbol *)0x0) &&
         (pcVar6 = class_lookup_qualified_member(g_current_scope,key,pcVar6,0),
         pcVar6 == (c1_symbol *)0x0)) {
        return '\0';
      }
    }
  }
  return '\x01';
}

