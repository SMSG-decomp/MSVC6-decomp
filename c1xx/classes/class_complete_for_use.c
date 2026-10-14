int __cdecl class_complete_for_use(c1_symbol *cls)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_class_record *pcVar3;
  c1_symbol *cls_00;
  char cVar4;
  int iVar5;
  
  cls_00 = cls;
  if ((cls->kind & 0x1f) != 0x16) {
    if ((cls->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(cls);
    }
    if ((((cls_00->detail).cls)->pm_model & 8) == 0) {
      cVar4 = pragma_pointers_to_members_default((int *)&cls);
      pcVar3 = (cls_00->detail).cls;
      if (cVar4 == '\0') {
        if ((pcVar3->layout_flags3c & 4) == 0) {
          pcVar3->pm_model = pcVar3->pm_model & 0xfc | 4;
          pcVar1 = &((cls_00->detail).cls)->layout_flags3c;
          *pcVar1 = *pcVar1 | 0x20;
        }
        else {
          iVar5 = class_best_inheritance_model(cls_00);
          bVar2 = ((cls_00->detail).cls)->pm_model;
          ((cls_00->detail).cls)->pm_model = (bVar2 ^ (byte)iVar5) & 7 ^ bVar2;
        }
      }
      else {
        pcVar3->pm_model = (pcVar3->pm_model ^ (byte)cls) & 7 ^ pcVar3->pm_model;
      }
      pcVar1 = &((cls_00->detail).cls)->pm_model;
      *pcVar1 = *pcVar1 | 8;
      class_finish_layout_flags(cls_00);
    }
    return ((cls_00->detail).cls)->pm_model & 7;
  }
  return 1;
}

