void __cdecl class_declare_constructor_closures(c1_symbol *cls)

{
  fe_name **ppfVar1;
  char cVar2;
  int iVar3;
  c1_symbol *pcVar4;
  c1_type_extra *pcVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  c1xx_ovl_set_iter local_10;
  
  if (((((cls->detail).cls)->implicit_state41 & 2) == 0) &&
     (pcVar7 = class_find_member_function(cls,g_name_ctor), pcVar7 != (c1_symbol *)0x0)) {
    ppfVar1 = &pcVar7->name;
    if (ppfVar1 != (fe_name **)0x0) {
      iVar3 = sym_is_data_or_function_2(pcVar7);
      pcVar4 = (c1_symbol *)ppfVar1;
      if (((char)iVar3 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
        pcVar4 = (c1_symbol *)pcVar7->type;
      }
      do {
        if ((ppfVar1 == (fe_name **)0x0) || (pcVar4 == (c1_symbol *)0x0)) goto LAB_104374c5;
        iVar3 = sym_is_data_or_function_2(pcVar7);
        if (((char)iVar3 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
          pcVar8 = *(c1_symbol **)&pcVar4->flags4;
        }
        else {
          pcVar8 = (c1_symbol *)0x0;
        }
        pcVar6 = (c1_symbol *)((int)&pcVar4[-1].tail + 4);
        if ((*(byte *)((int)&pcVar4[-1].tail + 4) & 0x1f) == 0x1a) {
          pcVar6 = *(c1_symbol **)pcVar4->next;
        }
        pcVar4 = pcVar8;
      } while (((*(byte *)((int)&pcVar6->tail + 8) & 0x10) == 0) ||
              (*(char *)(*(int *)(((uint)pcVar6->type & -(uint)((pcVar6->type->code & 0x80) != 0)) +
                                 8) + 4) == '\0'));
      class_declare_default_ctor_closure(cls,pcVar6);
    }
LAB_104374c5:
    if ((((((cls->detail).cls)->implicit_state41 & 0x10) == 0) &&
        (pcVar4 = class_find_member_function(cls,g_name_dtor), pcVar4 != (c1_symbol *)0x0)) &&
       (pcVar9 = (c1_type *)&pcVar4->name, pcVar9 != (c1_type *)0x0)) {
      iVar3 = sym_is_data_or_function_2(pcVar4);
      if (((char)iVar3 == '\0') && ((pcVar4->kind & 0x1f) != 0x1a)) {
        pcVar9 = pcVar4->type;
      }
      if (pcVar9 != (c1_type *)0x0) {
        sym_is_data_or_function_2(pcVar4);
        pcVar5 = &pcVar9[-1].extra;
        if ((*(byte *)&pcVar9[-1].extra & 0x1f) == 0x1a) {
          pcVar5 = *(c1_type_extra **)pcVar9->debug_index;
        }
        if (((*(byte *)((int)pcVar5 + 0x21) & 2) != 0) && (ppfVar1 != (fe_name **)0x0)) {
          iVar3 = sym_is_data_or_function_2(pcVar7);
          pcVar4 = (c1_symbol *)ppfVar1;
          if (((char)iVar3 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
            pcVar4 = (c1_symbol *)pcVar7->type;
          }
          do {
            if ((ppfVar1 == (fe_name **)0x0) || (pcVar4 == (c1_symbol *)0x0)) goto LAB_1043740c;
            iVar3 = sym_is_data_or_function_2(pcVar7);
            if (((char)iVar3 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
              pcVar8 = *(c1_symbol **)&pcVar4->flags4;
            }
            else {
              pcVar8 = (c1_symbol *)0x0;
            }
            pcVar6 = (c1_symbol *)((int)&pcVar4[-1].tail + 4);
            if ((*(byte *)((int)&pcVar4[-1].tail + 4) & 0x1f) == 0x1a) {
              pcVar6 = *(c1_symbol **)pcVar4->next;
            }
            pcVar4 = pcVar8;
          } while ((*(byte *)((int)&pcVar6->tail + 8) & 0x10) == 0);
          class_declare_local_vftable_ctor_closure(cls,pcVar6);
        }
      }
    }
  }
LAB_1043740c:
  if ((((cls->detail).cls)->implicit_state41 & 4) == 0) {
    pcVar7 = class_find_member_function(cls,g_name_ctor);
    if (pcVar7 != (c1_symbol *)0x0) {
      ovl_set_iter_init(&local_10,&pcVar7->name);
      cVar2 = ovl_set_iter_next(&local_10);
      if (cVar2 != '\0') {
        while ((pcVar7 = ovl_set_iter_current_symbol(&local_10),
               (*(byte *)((int)&pcVar7->tail + 8) & 0x20) == 0 ||
               (*(char *)(*(int *)(((uint)pcVar7->type & -(uint)((pcVar7->type->code & 0x80) != 0))
                                  + 8) + 4) == '\0'))) {
          cVar2 = ovl_set_iter_next(&local_10);
          if (cVar2 == '\0') {
            return;
          }
        }
        class_declare_copy_ctor_closure_fragment(pcVar7,cls);
        return;
      }
    }
  }
  return;
}

