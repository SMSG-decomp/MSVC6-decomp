void __cdecl class_finish_layout_flags(c1_symbol *cls)

{
  byte bVar1;
  c1_class_record *pcVar2;
  c1_symbol *cls_00;
  char cVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  cls_00 = cls;
  bVar1 = ((cls->detail).cls)->layout_flags3c;
  if ((((bVar1 & 4) != 0) && ((((cls->detail).cls)->pm_model & 8) != 0)) && ((bVar1 & 0x20) == 0)) {
    cVar3 = pragma_pointers_to_members_default((int *)&cls);
    pcVar2 = (cls_00->detail).cls;
    if (cVar3 == '\0') {
      uVar4 = class_best_inheritance_model(cls_00);
      bVar6 = uVar4 != (pcVar2->pm_model & 7);
    }
    else {
      iVar5 = class_best_inheritance_model(cls_00);
      bVar6 = (int)(pcVar2->pm_model & 7) < iVar5;
    }
    if (bVar6) {
      pcVar2->layout_flags3c = pcVar2->layout_flags3c | 0x20;
      iVar5 = class_best_inheritance_model(cls_00);
      diag_error((-(ushort)(cVar3 != '\0') & 0xfffb) + 0x124,cls_00,
                 g_member_pointer_model_names[((cls_00->detail).cls)->pm_model & 7],
                 g_member_pointer_model_names[iVar5]);
    }
  }
  return;
}

