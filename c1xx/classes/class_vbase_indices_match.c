byte __cdecl class_vbase_indices_match(c1_symbol *cls,c1_symbol *other)

{
  c1_vbase_vector *pcVar1;
  c1_symbol *base;
  c1_symbol *cls_00;
  int iVar2;
  short sVar3;
  c1_vbase_vector *pcVar4;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  c1_vbase_vector *local_18;
  short local_14;
  char local_4;
  
  cls_00 = cls;
  pcVar1 = ((cls->detail).cls)->vbases;
  local_4 = pcVar1 != (c1_vbase_vector *)0x0;
  pcVar4 = local_18;
  sVar3 = local_14;
  if ((bool)local_4) {
    pcVar4 = pcVar1;
    sVar3 = 0;
  }
  while (((local_4 != '\0' && (pcVar4 != (c1_vbase_vector *)0x0)) &&
         (iVar2 = (int)sVar3, iVar2 < (int)(uint)pcVar4->count))) {
    sVar3 = sVar3 + 1;
    base = pcVar4->data[iVar2]->base;
    class_virtual_base_info(base,cls_00,&local_20,&local_24,(c1_type **)&cls);
    class_virtual_base_info(base,other,&local_1c,&local_28,(c1_type **)&cls);
    if (local_28 != local_24) {
      return 0;
    }
  }
  return 1;
}

